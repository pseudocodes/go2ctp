#include "ThostFtdcTraderApi.h"
#include <cstring>
#include <thread>

// The test writes these neutral implementations from the SDK's pure virtual
// declarations so the compiler checks every override and assigns the slots.
class TraderDefaults : public CThostFtdcTraderApi {
public:
#include "trader_defaults.inc"
};

class Trader final : public TraderDefaults {
    CThostFtdcTraderSpi* spi = nullptr;
    std::thread worker;
    int seq = 0;
public:
    void RegisterSpi(CThostFtdcTraderSpi* receiver) override { spi = receiver; }
    void SubscribePrivateTopic(THOST_TE_RESUME_TYPE, int value) override { seq = value; }
    void GetFrontInfo(CThostFtdcFrontInfoField* info) override { info->QryFreq = seq; }
    int ReqUserLogin(CThostFtdcReqUserLoginField* f, int id) override { return f && f->BrokerID[0]=='B' ? id : 0; }
    void Init() override {
        auto* s = spi;
        int value = seq;
        worker = std::thread([s,value] {
            if (!s) return;
            CThostFtdcOrderField order{};
            order.VolumeTotalOriginal = 17;
            CThostFtdcRspInfoField info{};
            info.ErrorID = -12;
            s->OnRtnPrivateSeqNo(value);
            s->OnRspAuthenticate(nullptr, &info, -77, true);
            s->OnRtnOrder(&order);
            s->OnErrRtnOrderInsert(nullptr, &info);
            s->OnRspError(&info, 42, false);
            s->OnRspQryHedgeCfm(nullptr, nullptr, -8, false);
            s->OnErrRtnHedgeCfmAction(nullptr,&info);
        });
    }
    int Join() override { if (worker.joinable()) worker.join(); return -27; }
    void Release() override { Join(); delete this; }
};

CThostFtdcTraderApi* CThostFtdcTraderApi::CreateFtdcTraderApi(const char* path, bool production) {
    // Each fixture instance selects its mode explicitly in the flow prefix.
    bool evaluation = std::strstr(path,"evaluation") != nullptr;
    return evaluation == !production ? new Trader : nullptr;
}
const char* CThostFtdcTraderApi::GetApiVersion() { return "6.7.13_trader_fixture"; }
