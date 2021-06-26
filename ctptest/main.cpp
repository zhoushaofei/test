#include <unistd.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include "util/tc_encoder.h"
#include <util/tc_thread_pool.h>
#include <util/tc_common.h>
#include <util/tc_thread_queue.h>
#include "util/tc_logger.h"
#include "util/tc_file.h"
#include "util/tc_config.h"
#include "servant/RemoteLogger.h"
#include "event/TimeUtil.h"
#include "ThostFtdcTraderApi.h"
#include "traderSpi.h"
#include "DataCollect.h"
#include "util/tc_base64.h"
#include <sys/syscall.h>

using namespace std;
using namespace taf;

#define LOG printf
#define gettid() syscall(__NR_gettid)


atomic_bool tmp_bIsLast = {false};


class MyTraderSpi : public CTraderSpi
{
public:
    ///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
    virtual void OnFrontConnected()
    {
        CTraderSpi::OnFrontConnected();
        cout << "thread:" << this_thread::get_id() << "|" << gettid() << endl;
    }

    ///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
    ///@param nReason 错误原因
    ///        0x1001 网络读失败
    ///        0x1002 网络写失败
    ///        0x2001 接收心跳超时
    ///        0x2002 发送心跳失败
    ///        0x2003 收到错误报文
    virtual void OnFrontDisconnected(int nReason)
    {
        CTraderSpi::OnFrontDisconnected(nReason);
        cout << "thread:" << this_thread::get_id() << "|" << gettid() << endl;
    }

    ///客户端认证响应
    virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
    {
        CTraderSpi::OnRspAuthenticate(pRspAuthenticateField, pRspInfo, nRequestID, bIsLast);
        cout << "thread:" << this_thread::get_id() << "|" << gettid() << endl;
    }

	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
    {
        CTraderSpi::OnRspUserLogin(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
        cout << "thread:" << this_thread::get_id() << "|" << gettid() << endl;
    }
	///用户口令更新请求响应
	virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
    {
        CTraderSpi::OnRspUserPasswordUpdate(pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast);
        cout << "thread:" << this_thread::get_id() << "|" << gettid() << endl;
    }

	///资金账户口令更新请求响应
	virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
    {
        CTraderSpi::OnRspTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, pRspInfo, nRequestID, bIsLast);
        cout << "thread:" << this_thread::get_id() << "|" << gettid() << endl;
    }


	virtual void OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
    {
        CTraderSpi::OnRspQryExchange(pExchange, pRspInfo, nRequestID, bIsLast);
        if (bIsLast)
        {
            tmp_bIsLast = true;
        cout << &tmp_bIsLast << endl;
            cout << "tmp_bIsLast=" << tmp_bIsLast << endl;
        }
    }

};

void test()
{
    cout << "version: " << CThostFtdcTraderApi::GetApiVersion() << endl;

    CThostFtdcTraderApi *m_pApi = CThostFtdcTraderApi::CreateFtdcTraderApi("./flow/");

    MyTraderSpi spi;
    m_pApi->RegisterSpi(&spi);

    int nRequestID = 23;

    // // string frontAddr = "tcp://180.168.146.187:10101"; //电信
    // // string frontAddr = "tcp://218.202.237.33:10102"; //移动
    // string frontAddr = "tcp://180.168.146.187:10130"; //7x24
    // string userId = "169702";
    // string password = "1234ABCD";
    // string brokerId = "9999";
    // string authCode = "0000000000000000";
    // string appId = "simnow_client_test";
    // string relayAppId = "simnow_client_test";

    // string frontAddr = "tcp://114.255.82.175:11205";
    string frontAddr = "tcp://106.39.36.72:11205";
    string userId = "10031";
    string password = "1234ABCD";
    string brokerId = "1010";
    string authCode = "YHQHYHQHYHQHYHQH";
    string appId = "gmatrix_quant_test";
    string relayAppId = "gmatrix_relay_test";
    // string appId = "cgs_gmatrix_2.0.0";
    // string relayAppId = "cgs_gmxapama_2.0.0";


    // // string frontAddr = "tcp://114.255.82.175:11205";
    // string frontAddr = "tcp://106.39.36.72:11205";
    // string userId = "06710";
    // string password = "123123";
    // string brokerId = "1010";
    // string authCode = "YHQHYHQHYHQHYHQH";
    // string appId = "gmatrix_quant_test";
    // string relayAppId = "gmatrix_relay_test";
    // // string appId = "cgs_gmatrix_2.0.0";
    // // string relayAppId = "cgs_gmxapama_2.0.0";


    // string frontAddr = "tcp://180.166.103.22:42206";
    // string userId = "8118019222";
    // string password = "yhqh123456";
    // string brokerId = "4040";
    // string authCode = "9GC44VLJNLV2SUDB";
    // string appId = "cgs_gmatrix_2.0.0";
    // string relayAppId = "cgs_gmatrix_2.0.0";
    // // string appId = "cgs_gmatrix_2.0.0";
    // // string relayAppId = "cgs_gmxapama_2.0.0";

    // string frontAddr = "tcp://106.39.36.72:31205";
    // string userId = "10000010";
    // string password = "abc@123456";
    // string brokerId = "1010";
    // string authCode = "YHQHYHQHYHQHYHQH";
    // string appId = "cgs_gmatrix_2.0.0";
    // string relayAppId = "cgs_gmxapama_2.0.0";

    // // string frontAddr = "tcp://114.255.82.175:11205";
    // string frontAddr = "tcp://106.39.36.72:11205";
    // string userId = "10026";
    // string password = "w123456";
    // string brokerId = "1010";
    // string authCode = "YHQHYHQHYHQHYHQH";
    // string appId = "gmatrix_quant_test";
    // string relayAppId = "gmatrix_relay_test";

    // // string frontAddr = "tcp://114.255.82.175:11205";
    // string frontAddr = "tcp://106.39.36.72:11205";
    // string userId = "10031";
    // string password = "1234ABCD";
    // string brokerId = "1010";
    // string authCode = "YHQHYHQHYHQHYHQH";
    // string appId = "rootnet_gateway_1.0.0.0";
    // string relayAppId = "rootnet_gateway_1.0.0.0";

    // // string frontAddr = "tcp://114.255.82.175:11205";
    // string frontAddr = "tcp://106.39.36.72:11205";
    // string userId = "02704";
    // string password = "1234ABCD";
    // string brokerId = "1010";
    // string authCode = "YHQHYHQHYHQHYHQH";
    // string appId = "rootnet_gateway_1.0.0.0";

    // string frontAddr = "tcp://106.39.36.72:31205";
    // string userId = "10004667";
    // string password = "123456";
    // string brokerId = "1010";
    // string authCode = "YHQHYHQHYHQHYHQH";
    // string appId = "AppID=apama_cgs_v1.0.0";

    if (1)
    {
        m_pApi->SubscribePrivateTopic(THOST_TERT_QUICK);
        m_pApi->SubscribePublicTopic(THOST_TERT_QUICK);
        m_pApi->RegisterFront((char*)(frontAddr.c_str()));
        m_pApi->Init();
        TC_Common::msleep(1000);
        cout << "after init ----------------------- " << endl;
    }

    if (1)
    {
        CThostFtdcReqAuthenticateField reqAuth = { 0 };
        strcpy(reqAuth.BrokerID, brokerId.c_str());
        strcpy(reqAuth.UserID, userId.c_str());
        // strcpy(reqAuth.UserProductInfo, "");
        strcpy(reqAuth.AuthCode, authCode.c_str());
        strcpy(reqAuth.AppID, relayAppId.c_str());
        int ret = m_pApi->ReqAuthenticate(&reqAuth, nRequestID++);
        printf("\t客户端认证 = [%d]\n", ret);
        TC_Common::msleep(1000);
        cout << "after ReqAuthenticate ----------------------- " << endl;
    }

    if (0)
    {
        char pSystemInfo[344]={0};
        int len = 0;
        CTP_GetSystemInfo(pSystemInfo, len);

		CThostFtdcUserSystemInfoField a = { 0 };
		strcpy(a.BrokerID, brokerId.c_str());
		strcpy(a.UserID, userId.c_str());
		memcpy(a.ClientSystemInfo, pSystemInfo, len);
		a.ClientSystemInfoLen = len;

		strcpy(a.ClientPublicIP, "172.16.8.24");//ip地址
		a.ClientIPPort = 35904;//端口号

		strcpy(a.ClientLoginTime, "10:01:01");
		strcpy(a.ClientAppID, appId.c_str());
		int b = m_pApi->RegisterUserSystemInfo(&a);
		LOG((b == 0) ? "注册用户终端信息......发送成功\n" : "注册用户终端信息......发送失败，错误序号=[%d]\n", b);
        TC_Common::msleep(1000);
        cout << "after RegisterUserSystemInfo ----------------------- " << endl;
    }

    if (1)
    {
		CThostFtdcReqUserLoginField reqUserLogin = { 0 };
		strcpy(reqUserLogin.BrokerID, brokerId.c_str());
		strcpy(reqUserLogin.UserID, userId.c_str());
		strcpy(reqUserLogin.Password, password.c_str());
		//strcpy_s(reqUserLogin.ClientIPAddress, "::c0a8:0101");
		//strcpy_s(reqUserLogin.UserProductInfo, "123");
		// 发出登陆请求
		int ret = m_pApi->ReqUserLogin(&reqUserLogin, nRequestID++);
        printf("\t请求用户登录 = [%d]\n", ret);
        TC_Common::msleep(1000);
        cout << "after ReqUserLogin ----------------------- " << endl;
        cout << "tradedate: " << m_pApi->GetTradingDay() << endl;
    }
    if (0)
    {
		CThostFtdcQryInvestorPositionField a = { 0 };
		strcpy(a.BrokerID, brokerId.c_str());
		strcpy(a.InvestorID, userId.c_str());
		strcpy(a.InstrumentID, "IC2109");
		int b = m_pApi->ReqQryInvestorPosition(&a, nRequestID++);
		LOG((b == 0) ? "请求查询投资者持仓......发送成功\n" : "请求查询投资者持仓......发送失败，错误序号=[%d]\n", b);
        getchar();
    }

    if (0)
    {
		CThostFtdcQryInstrumentCommissionRateField a = { 0 };
		strcpy(a.BrokerID, brokerId.c_str());
		strcpy(a.InvestorID, userId.c_str());
		strcpy(a.InstrumentID, "IC2106");
		int b = m_pApi->ReqQryInstrumentCommissionRate(&a, nRequestID++);
		LOG((b == 0) ? "请求查询合约手续费率......发送成功\n" : "请求查询合约手续费率......发送失败，错误序号=[%d]\n", b);
        getchar();
    }

    if (0)
    {
		CThostFtdcQueryMaxOrderVolumeField a = { 0 };
		strcpy(a.BrokerID, brokerId.c_str());
		strcpy(a.InvestorID, userId.c_str());
		strcpy(a.InstrumentID, "IC2106");
		a.Direction = THOST_FTDC_D_Buy;
		a.OffsetFlag = THOST_FTDC_OF_Open;
		a.HedgeFlag = THOST_FTDC_HF_Speculation;
		int b = m_pApi->ReqQueryMaxOrderVolume(&a, nRequestID++);
		LOG((b == 0) ? "查询最大报单数量请求......发送成功\n" : "查询最大报单数量请求......发送失败，错误序号=[%d]\n", b);
        getchar();
    }

    if (0)
    {
		CThostFtdcQryExchangeField a = { 0 };
		strcpy(a.ExchangeID, "CFFEX11");
		int b = m_pApi->ReqQryExchange(&a, nRequestID++);
		LOG((b == 0) ? "请求查询交易所......发送成功\n" : "请求查询交易所......发送失败，错误序号=[%d]\n", b);
        getchar();
    }

    if (1)
    {
		CThostFtdcQryInstrumentField a = { 0 };
		strcpy(a.ExchangeID, "CFFEX");
		strcpy(a.InstrumentID, "");
		//strcpy_s(a.ExchangeInstID,"");
		//strcpy_s(a.ProductID, "m");
		int b = m_pApi->ReqQryInstrument(&a, nRequestID++);
		LOG((b == 0) ? "请求查询合约......发送成功\n" : "请求查询合约......发送失败，错误序号=[%d]\n", b);

        getchar();
    }

    if (0)
    {
        for(int i = 0; i < 30; i++)
        {
        tmp_bIsLast = false;
        cout << "xxxxxxx=" << tmp_bIsLast << "|" << &tmp_bIsLast << endl;
		CThostFtdcQryExchangeField  a = { 0 };
		strcpy(a.ExchangeID, "CFFEX");
		int b = m_pApi->ReqQryExchange(&a, nRequestID++);
		LOG((b == 0) ? "请求查询交易所......发送成功\n" : "请求查询交易所......发送失败，错误序号=[%d]\n", b);
        while(!tmp_bIsLast){
            // TC_Common::msleep(10);
                        // TC_Common::msleep(1000);cout << tmp_bIsLast<<endl;
            }
        cout << "i=" << i << "|tmp_bIsLast=" << tmp_bIsLast << endl;
        }

        getchar();
    }

    // if (1)
    // {
	// 	CThostFtdcQryInstrumentMarginRateField a = { 0 };
	// 	strcpy(a.BrokerID, brokerId.c_str());
	// 	strcpy(a.InvestorID, userId.c_str());
	// 	strcpy(a.InstrumentID, "IC2103");
	// 	a.HedgeFlag = THOST_FTDC_HF_Speculation;//投机
	// 	int b = m_pApi->ReqQryInstrumentMarginRate(&a, nRequestID++);
	// 	LOG((b == 0) ? "请求查询合约保证金率......发送成功\n" : "请求查询合约保证金率......发送失败，错误序号=[%d]\n", b);
    // }

    // getchar();

    // if (1)
    // {
	// 	CThostFtdcQryOrderField a = { 0 };
	// 	strcpy(a.BrokerID, brokerId.c_str());
	// 	strcpy(a.InvestorID, userId.c_str());
	// 	// strcpy(a.ExchangeID, g_chExchangeID);
	// 	int ab = m_pApi->ReqQryOrder(&a, nRequestID++);
	// 	LOG((ab == 0) ? "请求查询报单......发送成功\n" : "请求查询报单......发送失败，序号=[%d]\n", ab);
    // }

    // getchar();

    // if (1)
    // {
    //     cout << "======================== " << i << endl;
	// 	CThostFtdcInputOrderField a = { 0 };
	// 	strcpy(a.BrokerID, brokerId.c_str()); ///经纪公司代码
	// 	strcpy(a.InvestorID, userId.c_str()); ///投资者代码
	// 	strcpy(a.InstrumentID, "IC2104"); ///合约代码
	// 	strcpy(a.UserID, userId.c_str()); ///用户代码
    //     // strcpy(a.OrderRef, "orderid"); ///报单引用，OrderRef是本地会话全局唯一编号，必须保持递增；可由用户维护，也可由系统自动填写。一定为数字。
    //     // strcpy(a.OrderRef, "0"); ///报单引用，OrderRef是本地会话全局唯一编号，必须保持递增；可由用户维护，也可由系统自动填写。一定为数字。
    //     strcpy(a.OrderRef, TC_Common::tostr(i+110).c_str()); ///报单引用，OrderRef是本地会话全局唯一编号，必须保持递增；可由用户维护，也可由系统自动填写。一定为数字。
	// 	a.OrderPriceType = THOST_FTDC_OPT_LimitPrice; ///报单价格条件，限价
	// 	// a.OrderPriceType = THOST_FTDC_OPT_AnyPrice; ///报单价格条件，任意价
	// 	// a.OrderPriceType = THOST_FTDC_OPT_BestPrice; ///报单价格条件，最优价
	// 	// a.OrderPriceType = THOST_FTDC_OPT_LastPrice; ///报单价格条件，最新价
    //     // a.OrderPriceType = THOST_FTDC_OPT_FiveLevelPrice; ///报单价格条件，五档价
	// 	a.Direction = THOST_FTDC_D_Buy; ///买卖方向，买
	// 	// a.Direction = THOST_FTDC_D_Sell; ///买卖方向，买
	// 	a.CombOffsetFlag[0] = THOST_FTDC_OF_Open; ///组合开平标志//开仓，THOST_FTDC_OF_Open
	// 	// a.CombOffsetFlag[0] = THOST_FTDC_OF_Close; ///组合开平标志//平仓，THOST_FTDC_OF_Close
	// 	a.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation; ///组合投机套保标志//投机，THOST_FTDC_HF_Speculation
	// 	// strcpy(a.CombOffsetFlag, "0"); ///组合开平标志//开仓，THOST_FTDC_OF_Open
	// 	// strcpy(a.CombHedgeFlag, "1"); ///组合投机套保标志//投机，THOST_FTDC_HF_Speculation
	// 	a.LimitPrice = 6100.0; ///价格
	// 	a.VolumeTotalOriginal = 1; ///数量
	// 	a.TimeCondition = THOST_FTDC_TC_GFD; ///有效期类型，当日有效
    //     // a.TimeCondition = THOST_FTDC_TC_IOC; ///立即完成，否则撤销
    //     // a.GTDDate; ///GTD日期
	// 	a.VolumeCondition = THOST_FTDC_VC_AV; ///成交量类型，任何数量
	// 	// a.VolumeCondition = THOST_FTDC_VC_MV; ///成交量类型，最小数量
	// 	a.MinVolume = 0; ///最小成交量
    //     a.ContingentCondition = THOST_FTDC_CC_Immediately; ///触发条件
	// 	a.StopPrice = 0.0; ///止损价
	// 	a.ForceCloseReason = THOST_FTDC_FCC_NotForceClose; ///强平原因///非强平
	// 	a.IsAutoSuspend = 0; ///自动挂起标志
    //     a.UserForceClose = 0; ///用户强评标志
    //     a.IsSwapOrder = 0; ///互换单标志
	// 	// strcpy(a.ExchangeID, "J"); ///交易所代码，///中国金融期货交易所，THOST_FTDC_EIDT_CFFEX，'J'
    //     a.RequestID = 1123;///请求编号
    // // TThostFtdcInvestUnitIDType InvestUnitID; ///投资单元代码
    // // TThostFtdcAccountIDType AccountID; ///资金账号
    // // TThostFtdcCurrencyIDType CurrencyID; ///币种代码，不填写默认为CNY
    // // TThostFtdcClientIDType ClientID; ///交易编码
    // // TThostFtdcBusinessUnitType BusinessUnit; ///业务单元
    // // TThostFtdcRequestIDType RequestID; ///请求编号
    // // TThostFtdcIPAddressType IPAddress; ///IP地址，手工填写本机IP地址，不自动获取。
    // // TThostFtdcMacAddressType MacAddress; ///Mac地址，手工填写本机Mac地址，不自动获取。

	// 	int ab = m_pApi->ReqOrderInsert(&a, nRequestID++);
	// 	LOG((ab == 0) ? "请求报入......发送成功\n" : "请求报入......发送失败，序号=[%d]\n", ab);
    //     // TC_Common::msleep(1000);
    //     cout << "after ReqOrderInsert ----------------------- " << endl;
    //     cout << "======================== " << i << endl;
    // }

    if (0)
    {
		CThostFtdcInputOrderActionField a = { 0 };
		strcpy(a.BrokerID, brokerId.c_str()); ///经纪公司代码
		strcpy(a.InvestorID, userId.c_str()); ///投资者代码
		a.OrderActionRef = 1;
		// strcpy_s(a.OrderRef, g_chOrderRef);
		//a.FrontID = g_chFrontID;
		//a.SessionID = g_chSessionID;
		strcpy(a.ExchangeID, "CFFEX");
		// strcpy_s(a.InstrumentID, g_chInstrumentID);
		// strcpy(a.OrderSysID, "      893944");
        strcpy(a.OrderSysID, "      269696");
		a.ActionFlag = THOST_FTDC_AF_Delete;
		// strcpy_s(a.UserID, g_chUserID);
        a.RequestID = 1234;
		int ab = m_pApi->ReqOrderAction(&a, a.RequestID);
		LOG((ab == 0) ? "撤单......发送成功\n" : "撤单......发送失败，序号=[%d]\n", ab);
        TC_Common::msleep(1000);
        cout << "after ReqOrderAction ----------------------- " << endl;
    }

    if (0)
    {
		CThostFtdcQryOrderField a = { 0 };
		strcpy(a.BrokerID, brokerId.c_str());
		strcpy(a.InvestorID, userId.c_str());
		//strcpy_s(a.InstrumentID, g_chInstrumentID);
		// strcpy_s(a.ExchangeID, g_chExchangeID);
		strcpy(a.OrderSysID, "       77830");
		int ab = m_pApi->ReqQryOrder(&a, nRequestID++);
		LOG((ab == 0) ? "请求查询报单......发送成功\n" : "请求查询报单......发送失败，序号=[%d]\n", ab);
    }

    if (0)
	{
		CThostFtdcUserLogoutField a = { 0 };
		strcpy(a.BrokerID, brokerId.c_str());
		strcpy(a.UserID, userId.c_str());
		int ret = m_pApi->ReqUserLogout(&a, nRequestID++);
        printf("\t请求用户登出 = [%d]\n", ret);
        TC_Common::msleep(1000);
        cout << "after ReqUserLogout ----------------------- " << endl;
	}


    while (1)
    {
        TC_Common::msleep(1000);
    }

}

int main()
{
    cout << "welcome" << endl;

    ProgressTimer t;
    test();
    cout << "elapsed: " << t.elapse() << endl;

    cout << "byebye" << endl;
    return 0;
}