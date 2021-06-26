#include "util/tc_option.h"
#include "util/tc_timer.h"
#include <iostream>
#include "event/EventManager.h"
#include "event/TimeUtil.h"
#include "util/tc_md5.h"
#include "proto/Assist.h"
#include "proto/HTComm.h"
#include "proto/HTTrade.h"
#include "proto/HTOrder.h"
#include "proto/HTCounterAdaptor.h"
#include "proto/HTCounterConfig.h"
#include "proto/HTTaskData.h"
#include "proto/AlgoOrder.h"
#include "proto/HTBasket.h"
#include "proto/HTQuote.h"
#include "proto/HTEvent.h"


using namespace std;
using namespace taf;
using namespace ht;


DECLARE_EVENT(Depth, Event, EN_DEPTH, EventHTDepth)


class AsyncListener : public IEventListener
{
public:
    AsyncListener(string name) : IEventListener("AsyncListener") {};

    virtual void onEvent(const EventPtr& event)
    {
        if (event->getEventName() == EN_DEPTH)
        {
            Depth& object = event->getObject<Depth>();
            LOG_CONSOLE_DEBUG << "recv Depth|" << object << endl;
        }
        if (event->getEventName() == EN_ORDER_ENTER_RSP)
        {
            EnterOrderRsp &rsp = event->getObject<EnterOrderRsp>();
            LOG_DEBUG << TNOWMS << "|recv EnterOrderRsp|" << rsp << endl;
        }
        if (event->getEventName() == EN_ORDER_CANCEL_RSP)
        {
            CancelOrderRsp &rsp = event->getObject<CancelOrderRsp>();
            LOG_DEBUG << TNOWMS << "|recv CancelOrderRsp|" << rsp << endl;
        }
        if (event->getEventName() == EN_ORDER_DEAL_INFO)
        {
            OrderDealInfo &dealinfo = event->getObject<OrderDealInfo>();
            LOG_DEBUG << TNOWMS << "|recv OrderDealInfo|" << dealinfo <<endl;
        }
    }
};

void dotest1()
{
    string obj = "AT.KDWProxyServer.CounterInnerProxyObj@tcp -h 10.1.82.186 -t 60000 -p 10012";
    AT::CounterInnerProxyPrx prx = Communicator::getInstance()->stringToProxy<AT::CounterInnerProxyPrx>(obj);

    AT::CounterInnerReq req;
    AT::CounterInnerRsp rsp;

    req.uniqueId = TC_Common::now2str();
    req.funcId = "410510"; //当日委托明细查询
    req.userId = "10024";
    req.accountId = "035500000201";
    req.cType = "JZ";

// funcid	INT	外围功能编号, 必须送,不可以为空
// custid	int	登陆后送，登陆客户代码
// custorgid	char(4)	登陆后送，客户所属机构
// trdpwd	char(32)	交易密码
// netaddr	char(270)	网卡地址或电话号码, MAC地址、硬盘信息必须送，不可以为空。
// orgid	char(4)	操作地机构代码, 必须送，不可以为空
// operway	char(1)	必须送，不可以为空,且必须送外围程序对应的操作方式，不允许送0，否则外围程序无法登陆和委托
// ext	CHAR(1)	目前必须为数值0
// custcert	char(128)	客户证书，登陆时送空串,登陆后获得，后续请求传递
// netaddr2	Char(255)	操作站点扩位，接收MAC地址
// ticket		Char(512)	统一认证票据，非必送，如送值，则校验
// operid	int	可选入参，可以不送
// operpwd	char(32)	可选入参，可以不送
//     req.data["market"] = "";
//     req.data["market"] = "";
//     req.data["market"] = "";
//     req.data["market"] = "";
//     req.data["market"] = "";
//     req.data["market"] = "";
//     req.data["market"] = "";

    req.data["market"] = "";
    req.data["fundid"] = "";
    req.data["fortuneid"] = "";
    req.data["secuid"] = "";
    req.data["stkcode"] = "";
    req.data["ordersno"] = "";
    req.data["ordergroup"] = "";
    req.data["bankcode"] = "";
    req.data["qryflag"] = "1";
    req.data["count"] = "10";
    req.data["poststr"] = "";

    // req.reFields.push_back("");


    int ret = prx->directCC(req, rsp);
    cout << "ret=" << ret << endl;
    cout << "req=" << req <<endl;
    cout << "rsp=" << rsp <<endl;


    while (1)
    {
        TC_Common::msleep(1000);
    }
}

void dotest2()
{
    // string obj = "AT.KDWProxyServer.CounterProxyObj@tcp -h 10.1.82.186 -t 60000 -p 10013";
    string obj = "AT.KDWRRProxyServer.CounterProxyObj@tcp -h 10.1.82.186 -t 60000 -p 10015";
    AT::CounterProxyPrx prx = Communicator::getInstance()->stringToProxy<AT::CounterProxyPrx>(obj);

    AT::CounterReq req;
    AT::CounterRsp rsp;

    req.funcID = "430016"; //当日委托明细查询
    req.bid = "JZR";
    req.nodeId = "JZR_111002";

    // req.data["funcid"] = "410510";
    req.data["funcid"] = "430016";
    req.data["custid"] = "10100058638";
    req.data["custorgid"] = "0101";
    req.data["trdpwd"] = "";
    req.data["netaddr"] = "";
    req.data["orgid"] = "";
    req.data["operway"] = "";
    req.data["ext"] = "";
    req.data["custcert"] = "";
    req.data["ticket"] = "";

    req.data["strdate"] = "20200519";
    req.data["enddate"] = "20210519";
    req.data["fundid"] = "";
    req.data["printflag"] = "0";
    req.data["qryflag"] = "1";
    req.data["count"] = "1000";
    req.data["poststr"] = "";

    // int ret = prx->cc(req, rsp);
    int ret = prx->cc(req, rsp);
    cout << "ret=" << ret << endl;
    cout << "req=" << req <<endl;
    cout << "rsp=" << rsp <<endl;


    while (1)
    {
        TC_Common::msleep(1000);
    }
}

void dotest()
{
    ProgressTimer t;



    // {
    //     EventManager::getInstance()->setLogLevel("DEBUG");

    //     auto func = [](bool isConnected, const TC_Endpoint& ep){
    //         LOG_CONSOLE_DEBUG << "isConnected=" << isConnected << "|ep=" << ep.toString() << endl;
    //     };

    //     // auto client = RemoteEventClient::createClient("Test.TestServer.TestEventObj@tcp -h 127.0.0.1 -p 23502", func);
    //     // auto client = RemoteEventClient::createClient("ht.JZApamaMatchServer.JZApamaMatchObj@tcp -h 172.16.8.24 -t 60000 -p 10030", func);
    //     // auto client = RemoteEventClient::createClient("ht.JZApamaMatchServer.JZApamaMatchObj@tcp -h 10.1.82.188 -t 60000 -p 10016", func);
    //     auto client = RemoteEventClient::createClient("GTP.SDKQuoteServer.SdkQuoteEventObj@	tcp -h 10.1.82.188 -t 60000 -p 10033", func);

    //     IEventListenerPtr listener = new AsyncListener("AsyncListener");

    //     client->subscribeAsync("threadName", listener, EN_DEPTH, "600000");

    //     getchar();
    // }

    // {
    //     string obj = "AT.KDWProxyServer.CounterProxyObj@tcp -h 10.1.82.186 -t 60000 -p 10013";
    //     // string obj = "AT.KDWRRProxyServer.CounterProxyObj@tcp -h 10.1.82.186 -t 60000 -p 10015";
    //     // string obj = "AT.APEXFastProxyServer.CounterProxyObj@tcp -h 10.1.82.186 -t 60000 -p 10004";
    //     AT::CounterProxyPrx prx = Communicator::getInstance()->stringToProxy<AT::CounterProxyPrx>(obj);

    //     AT::CounterReq req;
    //     AT::CounterRsp rsp;

    //     req.funcID = "430016"; //当日委托明细查询
    //     req.bid = "JZ";
    //     req.nodeId = "JZ_112000";

    //     req.data["funcid"] = "430016";
    //     req.data["custid"] = "10100058638";
    //     req.data["custorgid"] = "0101";
    //     req.data["trdpwd"] = "";
    //     req.data["netaddr"] = "";
    //     req.data["orgid"] = "";
    //     req.data["operway"] = "";
    //     req.data["ext"] = "";
    //     req.data["custcert"] = "";
    //     req.data["ticket"] = "";

    //     req.data["strdate"] = "20200519";
    //     req.data["enddate"] = "20210519";
    //     req.data["fundid"] = "";
    //     req.data["printflag"] = "0";
    //     req.data["qryflag"] = "1";
    //     req.data["count"] = "1000";
    //     req.data["poststr"] = "";

    //     int ret = prx->cc(req, rsp);
    //     cout << "ret=" << ret << endl;
    //     cout << "req=" << req <<endl;
    //     cout << "rsp=" << rsp <<endl;
    // }

    // {
    //     // string obj = "AT.KDWProxyServer.CounterProxyObj@tcp -h 10.1.82.186 -t 60000 -p 10013";
    //     // string obj = "AT.KDWRRProxyServer.CounterProxyObj@tcp -h 10.1.82.186 -t 60000 -p 10015";
    //     string obj = "AT.APEXFastProxyServer.CounterInnerProxyObj@tcp -h 10.1.82.186 -t 60000 -p 10003";
    //     AT::CounterInnerProxyPrx prx = Communicator::getInstance()->stringToProxy<AT::CounterInnerProxyPrx>(obj);

    //     AT::CounterInnerReq req;
    //     AT::CounterInnerRsp rsp;

    //     req.uniqueId = TC_Common::now2str();
    //     req.funcId = "630004";
    //     req.userId = "10033";
    //     req.accountId = "010300761010";
    //     req.cType = "DD";

    //     req.data["FID_KHH"] = "10300761010";
    //     req.data["FID_JYS"] = "SZ";
    //     req.data["FID_ZQDM"] = "000001";
    //     req.data["FID_EXFLG"] = "1";


    //     req.reFields.push_back("FID_ZQDM");
    //     req.reFields.push_back("FID_BBJ");
    //     req.reFields.push_back("FID_JCCL");
    //     req.reFields.push_back("FID_CCJJ");
    //     req.reFields.push_back("FID_MRJJ");
    //     req.reFields.push_back("FID_ZXJ");
    //     req.reFields.push_back("FID_ZSP");
    //     req.reFields.push_back("FID_TBFDYK");
    //     req.reFields.push_back("FID_TBBBJ");
    //     req.reFields.push_back("FID_TBCBJ");

    //     int ret = prx->directCC(req, rsp);
    //     cout << "ret=" << ret << endl;
    //     cout << "req=" << req <<endl;
    //     cout << "rsp=" << rsp <<endl;
    // }

    {
        string obj = "hta.JZMAQQTradeAlgoServer.TradeAlgoTafObj@tcp -h 9.21.200.151 -t 60000 -p 10030";
        AT::CounterInnerProxyPrx prx = Communicator::getInstance()->stringToProxy<AT::CounterInnerProxyPrx>(obj);

        AT::CounterInnerReq req;
        AT::CounterInnerRsp rsp;

        req.uniqueId = TC_Common::now2str();
        req.funcId = "10311001";
        req.userId = "10033";
        req.accountId = "011100044401";
        req.cType = "JZJSQQ";

        req.data["625"] = "05";
        req.data["48"] = "91002045";

        req.reFields.push_back("55");
        req.reFields.push_back("9084");

        int ret = prx->directCC(req, rsp);
        cout << "ret=" << ret << endl;
        cout << "req=" << req <<endl;
        cout << "rsp=" << rsp <<endl;
    }

    // {
    //     // string obj = "httds.TaskDataReadServer.TaskDataTafInnerReadObj@tcp -h 10.1.84.116 -t 60000 -p 10003";
    //     string obj = "ht.TaskDataServer.TaskDataTafObj@tcp -h 10.1.84.115 -t 60000 -p 10002";
    //     HTTaskDataPrx prx = Communicator::getInstance()->stringToProxy<HTTaskDataPrx>(obj);

    //     ht::QueryTaskReq req;
    //     ht::QueryTaskRsp rsp;

    //     // req.accountIds.push_back("010300000497");
    //     req.accountIds.push_back("020500000625");
    //     // req.accountIds.push_back("035500000201");
    //     // req.accountIds.push_back("010100000004");

    //     // req.taskIds.push_back("5844555");
    //     // req.taskTypes.push_back("0");

    //     req.pagination.pageSize = 100;

    //     int ret = prx->queryTask(req, rsp);
    //     cout << ret << endl;
    //     // cout << rsp << endl;

    //     for (const auto & item : rsp.tasks)
    //     {
    //         // if (item.taskBasic.instruments.size() > 0 && item.taskBasic.instruments[0].symbol=="600000")
    //         if (item.taskBasic.instruments.size() > 0)
    //         {
    //             cout << item << endl;
    //         }
    //     }
    //     cout  << "rsp.size=" << rsp.tasks.size() << "|elapse = " << t.elapse() << endl;
    // }

    // {
    //     // string obj = "ht.CounterAdaptorServer.CounterAdaptorObj@tcp -h 127.0.0.1 -p 23403 -t 60000";
    //     string obj = "ht.CounterAdaptorServer.CounterAdaptorObj@tcp -h 10.1.82.186 -t 60000 -p 10025";
    //     CounterAdaptorPrx prx = Communicator::getInstance()->stringToProxy<CounterAdaptorPrx>(obj);

    //     GetAlgoDayOrderReq req;
    //     GetAlgoDayOrderRsp rsp;

    //     // req.tradeAccount.push_back("010300000497");
    //     req.tradeAccount.push_back("020500000625");
    //     // req.tradeAccount.push_back("010100000301");
    //     // req.tradeAccount.push_back("35500000201");
    //     // req.tradeAccount.push_back("10100000004");

    //     int ret = prx->getAlgoDayOrder(req, rsp);
    //     cout << "ret=" << ret << "|errCode=" << rsp.errCode << "|errMsg=" << rsp.errMsg << endl;
    //     cout << "req=" << req <<endl;

    //     for (const auto & item : rsp.algoOrderDetailList)
    //     {
    //         cout << item << endl;
    //     }
    //     cout << "rsp.size=" << rsp.algoOrderDetailList.size() << "|elapse=" << t.elapse() <<endl;
    // }


    // {
    //     // string obj = "ht.CounterAdaptorServer.CounterAdaptorObj@tcp -h 127.0.0.1 -p 23403 -t 60000";
    //     string obj = "ht.CounterAdaptorServer.CounterAdaptorObj@tcp -h 10.1.82.186 -t 60000 -p 10025";
    //     CounterAdaptorPrx prx = Communicator::getInstance()->stringToProxy<CounterAdaptorPrx>(obj);

    //     GetDayOrderReq req;
    //     GetDayOrderRsp rsp;

    //     // req.custNo.push_back("10300000497");
    //     req.custNo.push_back("35500000201");
    //     // req.custNo.push_back("10100000004");

    //     int ret = prx->getDayOrder(req, rsp);
    //     cout << "ret=" << ret << "|errCode=" << rsp.errCode << "|errMsg=" << rsp.errMsg << endl;
    //     cout << "req=" << req <<endl;

    //     for (const auto & item : rsp.dayOrderDetailList)
    //     {
    //         cout << item << endl;
    //     }
    //     cout << "rsp.size=" << rsp.dayOrderDetailList.size() << "|elapse=" << t.elapse() <<endl;
    // }

    // {
    //     algo::MarketSessionReq req;
    //     algo::MarketSessionRsp rsp;
    //     // 请求所有市场的交易日历
    //     req.marketName = "CS"; //请求A股的所有交易日历信息

    //     string obj = "algo.FactorTsbReadServer.AssistObj@tcp -h 10.1.82.187 -t 60000 -p 20010";
    //     auto prx = Communicator::getInstance()->stringToProxy<algo::AssistObjPrx>(obj);
    //     int ret = prx->getMarketSessions(req, rsp);
    //     cout << "ret=" << ret << endl;
    //     cout << "req=" << req <<endl;
    //     cout << "rsp=" << rsp <<endl;
    // }

    // {
    //     ht::QueryNodeByBranchReq req;
    //     ht::QueryNodeByBranchRsp rsp;

    //     req.branch.id = "0101";
    //     req.branch.cType = "JZ";
    //     req.branch.env = "5";

    //     string obj = "ht.CounterConfigServer.CounterConfigObj@tcp -h 10.1.82.186 -t 60000 -p 10000";
    //     auto prx = Communicator::getInstance()->stringToProxy<ht::CounterConfigPrx>(obj);
    //     int ret = prx->getNodeByBranch(req, rsp);
    //     cout << "ret=" << ret << endl;
    //     cout << "req=" << req <<endl;
    //     cout << "rsp=" << rsp <<endl;
    // }

    // {
    //     QueryOrderReq req;
    //     QueryOrderRsp rsp;

    //     req.client.userId = "upchina";
    //     req.client.guid = "upchina";
    //     req.client.xua = "upchina";
    //     req.client.channel = "web";
    //     req.token = "84360A977C722D6AC7B3C8BE5E07219C";

    //     req.page.pageSize = 10;

    //     // string obj = "ht.AlgoOrderServer.AlgoOrderTafObj@tcp -h 10.1.84.117 -t 60000 -p 10000";
    //     // auto prx = Communicator::getInstance()->stringToProxy<ht::AlgoOrderPrx>(obj);
    //     // int ret = prx->queryOrderToday(req, rsp);
    //     // cout << "ret=" << ret << endl;
    //     // cout << "req=" << req << endl;
    //     // cout << "rsp=" << rsp << endl;

    //     string obj = "ht_algo_order@tcp -h 10.1.84.117 -t 60000 -p 4509";
    //     map<string, string> context;
    //     context[":path"] = "/wup";
    //     context["X-GUID"] = "0.0.1";
    //     auto prx = Communicator::getInstance()->stringToProxy<ht::AlgoOrderPrx>(obj);
    //     prx->taf_set_protocol(ServantProxy::PROTOCOL_HTTP_JCE, 5);
    //     int ret = prx->queryOrderToday(req, rsp, context);
    //     cout << "ret=" << ret << endl;
    //     cout << "req=" << req << endl;
    //     cout << "rsp=" << rsp << endl;
    // }


    while (1)
    {
        TC_Common::msleep(1000);
    }
}

int main(int argc, char *argv[])
{
    try
    {
        dotest();
    }
    catch (std::exception& e)
    {
        LOG_ERROR << "exception:" << e.what() << endl;
    }
    catch (...)
    {
        LOG_ERROR << "unknown exception." << endl;
    }

    return 0;
}
