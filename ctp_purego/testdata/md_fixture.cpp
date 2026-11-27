// Test-only SDK substitute. Compile against the actual CTP header so the C++
// compiler, independently of the Go bindings, chooses the virtual table slots.
#include "ThostFtdcMdApi.h"
#include <atomic>
#include <cstring>
#include <string>
#include <thread>

class Market final : public CThostFtdcMdApi {
    std::atomic<CThostFtdcMdSpi*> spi{nullptr};
    std::thread worker;
    std::string front, nameServer;
    int requestID = 0;
    char loginMode = 0;

    static bool valid(char** ids, int n) {
        return n == 2 && std::strcmp(ids[0], "IF01") == 0 && std::strcmp(ids[1], "IF02") == 0;
    }
public:
    void RegisterSpi(CThostFtdcMdSpi* s) override { spi.store(s); }
    void RegisterFront(char* f) override { front = f; }
    void RegisterNameServer(char* n) override { nameServer = n; }
    void RegisterFensUserInfo(CThostFtdcFensUserInfoField* f) override { loginMode = f->LoginMode; }
    const char* GetTradingDay() override { return "20261127"; }

    void Init() override {
        worker = std::thread([this]() {
            auto* s = spi.load();
            if (!s) return;
            CThostFtdcRspInfoField info{};
            info.ErrorID = -9;
            CThostFtdcDepthMarketDataField tick{};
            tick.LastPrice = 42.25;
            std::strcpy(tick.InstrumentID, "IF01");
            s->OnFrontConnected();
            s->OnFrontDisconnected(-1);
            s->OnHeartBeatWarning(23);
            s->OnRspUserLogin(nullptr, &info, requestID, true);
            s->OnRspUserLogout(nullptr, nullptr, -2, false);
            s->OnRspQryMulticastInstrument(nullptr, nullptr, 3, true);
            s->OnRspError(&info, 4, false);
            s->OnRspSubMarketData(nullptr, nullptr, 5, true);
            s->OnRspUnSubMarketData(nullptr, nullptr, 6, false);
            s->OnRspSubForQuoteRsp(nullptr, nullptr, 7, true);
            s->OnRspUnSubForQuoteRsp(nullptr, nullptr, 8, false);
            s->OnRtnDepthMarketData(&tick);
            s->OnRtnForQuoteRsp(nullptr);
        });
    }
    int Join() override {
        if (worker.joinable()) worker.join();
        return -17;
    }
    void Release() override { Join(); delete this; }
    int SubscribeMarketData(char** ids, int n) override { return valid(ids,n) ? 8 : -1; }
    int UnSubscribeMarketData(char** ids, int n) override { return valid(ids,n) ? 9 : -1; }
    int SubscribeForQuoteRsp(char** ids, int n) override { return valid(ids,n) ? 10 : -1; }
    int UnSubscribeForQuoteRsp(char** ids, int n) override { return n == 0 && ids == nullptr ? 11 : -1; }
    int ReqUserLogin(CThostFtdcReqUserLoginField* req, int id) override {
        requestID = id;
        return req && req->BrokerID[0] == 'B' && loginMode == 'A' &&
               front == "front" && nameServer == "ns" ? -12 : 0;
    }
    int ReqUserLogout(CThostFtdcUserLogoutField* req, int id) override { return req ? id : 0; }
    int ReqQryMulticastInstrument(CThostFtdcQryMulticastInstrumentField* req, int id) override { return req ? -id : 0; }
};

CThostFtdcMdApi* CThostFtdcMdApi::CreateFtdcMdApi(const char*, bool udp, bool multicast, bool production) {
    return udp && multicast && !production ? new Market : nullptr;
}
const char* CThostFtdcMdApi::GetApiVersion() { return "6.7.13_fixture"; }
