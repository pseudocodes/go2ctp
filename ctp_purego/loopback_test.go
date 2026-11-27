//go:build (amd64 && (windows || linux || darwin)) || (arm64 && darwin)

package ctp_purego

import (
	"io"
	"net"
	"os"
	"testing"
	"time"
)

type loopbackSPI struct {
	BaseMdSpi
	event chan string
}

func (s *loopbackSPI) signal(e string) {
	select {
	case s.event <- e:
	default:
	}
}
func (s *loopbackSPI) OnFrontConnected()              { s.signal("connected") }
func (s *loopbackSPI) OnFrontDisconnected(reason int) { s.signal("disconnected") }

func TestSDKLoopback(t *testing.T) {
	lib := os.Getenv("CTP_MD_LIBRARY")
	if lib == "" {
		t.Skip("set CTP_MD_LIBRARY to run the SDK callback probe")
	}
	addr := loopbackFront(t)
	api := CreateMdApi(MdDynamicLibPath(lib), MdFlowPath(t.TempDir()+string(os.PathSeparator)))
	defer api.Release()
	spi := &loopbackSPI{event: make(chan string, 1)}
	api.RegisterSpi(spi)
	api.RegisterFront(addr)
	api.Init()
	awaitFront(t, spi.event)
}

type traderLoopbackSPI struct {
	BaseTraderSpi
	front *loopbackSPI
}

func (s *traderLoopbackSPI) OnFrontConnected()              { s.front.signal("connected") }
func (s *traderLoopbackSPI) OnFrontDisconnected(reason int) { s.front.signal("disconnected") }

func TestTraderSDKLoopback(t *testing.T) {
	lib := os.Getenv("CTP_TRADER_LIBRARY")
	if lib == "" {
		t.Skip("set CTP_TRADER_LIBRARY to run the official trader SDK probe")
	}
	addr := loopbackFront(t)
	api := CreateTraderApi(TraderDynamicLibPath(lib), TraderFlowPath(t.TempDir()+string(os.PathSeparator)))
	defer api.Release()
	t.Logf("trader SDK version %q", api.GetApiVersion())
	front := &loopbackSPI{event: make(chan string, 1)}
	api.RegisterSpi(&traderLoopbackSPI{front: front})
	api.RegisterFront(addr)
	api.Init()
	awaitFront(t, front.event)
}

func loopbackFront(t *testing.T) string {
	t.Helper()
	listener, err := net.Listen("tcp4", "127.0.0.1:0")
	if err != nil {
		t.Fatal(err)
	}
	t.Cleanup(func() { listener.Close() })
	go func() {
		for {
			c, err := listener.Accept()
			if err != nil {
				return
			}
			// Drain the handshake before sending an EOF. Keeping the read
			// half open lets the SDK finish pending writes during disconnection.
			tcp := c.(*net.TCPConn)
			tcp.SetDeadline(time.Now().Add(5 * time.Second))
			var handshake [1]byte
			tcp.Read(handshake[:])
			tcp.CloseWrite()
			io.Copy(io.Discard, tcp)
			tcp.Close()
		}
	}()
	return "tcp://" + listener.Addr().String()
}

func awaitFront(t *testing.T, events <-chan string) {
	t.Helper()
	select {
	case event := <-events:
		t.Logf("official SDK callback: %s", event)
	case <-time.After(12 * time.Second):
		t.Fatal("no SDK front callback")
	}
}
