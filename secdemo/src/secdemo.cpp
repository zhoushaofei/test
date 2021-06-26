// secdemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "stdafx.h"


const char sKey[] = "A5_RS_156";        //对应配置文件内的段名
const char sKhh[] = "011303292066";     //客户号
const char sPwd[] = "000783";           //交易密码
const char sWtfs[] = "32";              //委托方式
const char sNode[] = "127.0.0.1";       //操作站点


string SECITPDK_GetLastError();
void time_example();
void callback_example();
void login_example();
void trade_example();
void trade_async_example();
void batchorder_example();
void fxyw_async_example();
void query_dictdata_example();
void query_tradedata_example();
void yhld_example();


char sShGdh[13] = { 0 };                //上海股东号
char sSzGdh[13] = { 0 };                //深圳股东号
char sShZjzh[13] = { 0 };               //上海资金账号
char sSzZjzh[13] = { 0 };               //深圳资金账号


class Test
{
public:
    Test()
    {
        bool ret = SECITPDK_Init(0);
        cout << "SECITPDK_Init ret=" << ret << endl;
        cout << "Test" << endl;
    }

    virtual ~Test()
    {
        cout << "before SECITPDK_Exit" << endl;
        SECITPDK_Exit();
        cout << "after SECITPDK_Exit" << endl;
    }

    void init()
    {
        // bool ret = SECITPDK_Init(0);
        // cout << "SECITPDK_Init ret=" << ret << endl;
    }
};

int main()
{
    static Test tt;
    tt.init();
    cout << "byebye" << endl;
    return 0;

    // SECITPDK_SetLogPath("log");            //日志目录
    // SECITPDK_SetProfilePath("");           //配置文件目录

    // SECITPDK_Init(0);                      //初始化，在所有接口使用前调用，除路径设置接口外
    // ScopeGuard OnExit(
    //     []() {SECITPDK_Exit(); }           //退出，不再使用ITPDK接口时调用
    // );

    // SECITPDK_SetWTFS(sWtfs);               //设置委托方式
    // SECITPDK_SetNode(sNode);               //设置站点信息

    // {
    //     login_example();
    //     time_example();
    //     callback_example();
    //     query_dictdata_example();
    //     query_tradedata_example();
    //     //trade_example();
    //     fxyw_async_example();
    //     //batchorder_example();
    //     //trade_async_example();
    //     //yhld_example();
    // }

    // getchar();
    // return 0;
}


string SECITPDK_GetLastError()
{
    char msg[256];
    SECITPDK_GetLastError(msg);            //获取错误信息
    return msg;
}


void time_example()
{
    cout << "=========== time_example ============" << endl;
    cout << "SECITPDK_GetTickCount=" << SECITPDK_GetTickCount() << endl;
    cout << "SECITPDK_GetDoubleTickCount=" << SECITPDK_GetDoubleTickCount() << endl;
    cout << "SECITPDK_GetSystemDate=" << SECITPDK_GetSystemDate() << endl;
    cout << "SECITPDK_GetTradeDate=" << SECITPDK_GetTradeDate() << endl;
    cout << "SECITPDK_GetReviseTimeAsLong=" << SECITPDK_GetReviseTimeAsLong() << endl;

    char time[128];
    SECITPDK_GetReviseTime(time);
    cout << "SECITPDK_GetReviseTime=" << time << endl;
}


void callback_example()
{
    /*
        回调消息以json格式推送，下例使用rapidjson库解析。
        消息中的LSH字段，为下单时送入的值，可用于匹配委托单。
    */
    SECITPDK_SetFuncCallback(              //设置异步接口回调函数
        [](const char* pTime, const char* pMsg, int nType)
        {
            rapidjson::Document document;
            if (document.Parse(pMsg).HasParseError())       //解析失败
            {
                cout << "Parse async func message failed." << endl;
                return;
            }
            int64 nLSH = document["KFSBDBH"].GetInt64();            //开发商本地编号
            int nRetCode = document["RETCODE"].GetInt();            //处理结果
            const char *sRetNote = document["RETNOTE"].GetString();            //处理结果
            printf("Accept async func message: LSH=%ld,RetCode=%d,RetNote=%s\n", nLSH, nRetCode, sRetNote);
        }
    );

    SECITPDK_SetMsgCallback(               //设置消息推送回调函数
        [](const char* pTime, const char* pMsg, int nType)
        {
            rapidjson::Document document;
            if (document.Parse(pMsg).HasParseError())   //解析失败
            {
                cout << "Parse confirm message failed." << endl;
                return;
            }

            long nWTH = (long)document["WTH"].GetInt64();
            int64 nLSH = document["KFSBDBH"].GetInt64();
            const char* sKHH = document["KHH"].GetString();
            const char* sGDH = document["GDH"].GetString();
            const char* sZQDM = document["ZQDM"].GetString();

            if (NOTIFY_PUSH_ORDER == nType)
            {
                //确认推送
                printf("Accept confirm message: WTH=%ld,LSH=%ld,KHH=%s,GDH=%s,ZQDM=%s\n", nWTH, nLSH, sKHH, sGDH, sZQDM);
            }
            else if (NOTIFY_PUSH_MATCH == nType)
            {
                //成交推送
                printf("Accept report message: WTH=%ld,LSH=%ld,KHH=%s,GDH=%s,ZQDM=%s\n", nWTH, nLSH, sKHH, sGDH, sZQDM);
            }
            else if (NOTIFY_PUSH_WITHDRAW == nType)
            {
                //撤单推送
            }
            else if (NOTIFY_PUSH_INVALID == nType)
            {
                //废单推送
            }
        }
    );
}


void login_example()
{
    /*
        登录时需指定配置段，接口根据配置段内信息进行连接登录
    */
    printf("=========== login_example ============\n");
    int64 nRet = SECITPDK_TradeLogin(sKey, sKhh, sPwd);     //登录
    if (nRet <= 0)
    {
        string msg = SECITPDK_GetLastError();              //登录失败，获取错误信息
        printf("Login failed. Msg:%s\n", msg.c_str());
    }
    else
        printf("Login success. Token:%ld\n", nRet);
}


void trade_example()
{
    printf("=========== trade_example ============\n");
    int64 nWtsl = 100;                  //委托数量
    double dWtjg = 10.1;                //委托价格
    const char sJys[] = "SH";
    const char sZQDM[] = "600000";

    //查询可委托数量
    int64 nRet = SECITPDK_TradableQty(sKhh, sJys, sZQDM, JYLB_BUY, dWtjg, DDLX_XJWT, sShGdh);
    if (nRet > 0)
        printf("SECITPDK_TradableQty number=%ld\n", nRet);
    else
    {
        string msg = SECITPDK_GetLastError();              //查询失败，获取错误信息
        printf("SECITPDK_TradableQty failed. Msg:%s\n", msg.c_str());
    }
    //同步接口下单
    nRet = SECITPDK_OrderEntrust(sKhh, sJys, sZQDM, JYLB_BUY, nWtsl, dWtjg, DDLX_XJWT, sShGdh);
    if (nRet > 0)
        printf("SECITPDK_OrderEntrust success. Wth=%ld\n", nRet);
    else
    {
        string msg = SECITPDK_GetLastError();              //下单失败，获取错误信息
        printf("SECITPDK_OrderEntrust failed. Msg:%s\n", msg.c_str());
    }
    //同步接口撤单
    if (nRet > 0)       //若下单成功，返回值为委托号，用委托号进行撤单
    {
        nRet = SECITPDK_OrderWithdraw(sKhh, sJys, nRet);
        if (nRet > 0)
            printf("SECITPDK_OrderWithdraw success. Wth=%ld\n", nRet);
        else
        {
            string msg = SECITPDK_GetLastError();          //下单失败，获取错误信息
            printf("SECITPDK_OrderWithdraw failed. Msg:%s\n", msg.c_str());
        }
    }
}


void batchorder_example()
{
    printf("=========== batchorder_example ============\n");
    int64 nWtsl = 100;                   //委托数量
    double dWtjg = 100.01;                   //委托价格
    const char sJys[] = "SZ";
    const char sZQDM[] = "000001";

    BatchOrderInfo order;
    strncpy(order.Jys, sJys, sizeof(order.Jys));
    strncpy(order.Zqdm, sZQDM, sizeof(order.Zqdm));
    order.Jylb = JYLB_BUY;
    order.Wtjg = dWtjg;
    order.Wtsl = nWtsl;
    order.Ddlx = DDLX_XJWT;
    strncpy(order.Gdh, sSzGdh, sizeof(order.Gdh));

    //委托10笔
    vector<BatchOrderInfo> arBatchOrder;
    for (int i = 0; i < 10; ++i)
        arBatchOrder.push_back(order);

    int64 nRet = SECITPDK_BatchOrderEntrust_ASync(sKhh, arBatchOrder, 1);
    //if (0 == nRet)
    //{
    //    //全部成功
    //    printf("SECITPDK_BatchOrderEntrust success.\n");
    //}
    //else
    if (nRet > 0)
    {
        //部分成功，取失败委托信息
        printf("SECITPDK_BatchOrderEntrust partial success, failed num:%ld.\n", nRet);
        //for (auto& itr : arBatchOrder)
        //{
        //    if (itr.Wth <= 0)
        //        printf("RetCode=%ld, RetNode=%s\n", itr.Wth, itr.Msg);
        //}
    }
    else
    {
        //异常情况
        string msg = SECITPDK_GetLastError();
        printf("SECITPDK_BatchOrderEntrust failed. Msg:%s\n", msg.c_str());
    }
}


void trade_async_example()
{
    printf("=========== trade_async_example ============\n");
    int64 nWtsl = 100;                  //委托数量
    double dWtjg = 10.1;                //委托价格
    const char sJys[] = "SZ";
    const char sZQDM[] = "000001";

    //异步接口下单
    int64 nRet = SECITPDK_OrderEntrust_ASync(sKhh, sJys, sZQDM, JYLB_BUY, nWtsl, dWtjg, DDLX_XJWT, sSzGdh);
    if (nRet > 0)
        printf("SECITPDK_OrderEntrust_ASync success:%ld\n", nRet);
    else
    {
        string msg = SECITPDK_GetLastError();              //下单失败，获取错误信息
        printf("SECITPDK_OrderEntrust_ASync failed. Msg:%s\n", msg.c_str());
    }
    //利用本地编号进行撤单
    nRet = SECITPDK_OrderWithdrawByKFSBDBH_ASync(sKhh, " ", nRet);
    if (nRet > 0)
        printf("SECITPDK_OrderWithdrawByKFSBDBH_ASync success:%ld.\n", nRet);
    else
    {
        string msg = SECITPDK_GetLastError();              //下单失败，获取错误信息
        printf("SECITPDK_OrderWithdrawByKFSBDBH_ASync failed. Msg:%s\n", msg.c_str());
    }
}


void fxyw_async_example()
{
    printf("=========== fxyw_async_example ============\n");
    int64 nWtsl = 100;                  //委托数量
    double dWtjg = 10.1;                //委托价格
    const char sJys[] = "SZ";
    const char sZQDM[] = "000001";

    //异步接口下单
    int64 nRet = SECITPDK_FXYW_ASync(sKhh, sJys, sZQDM, JYLB_BUY, nWtsl, dWtjg, DDLX_XJWT, sSzGdh);
    if (nRet > 0)
        printf("SECITPDK_FXYW_ASync success:%ld\n", nRet);
    else
    {
        string msg = SECITPDK_GetLastError();              //下单失败，获取错误信息
        printf("SECITPDK_FXYW_ASync failed. Msg:%s\n", msg.c_str());
    }

    //异步撤单
    nRet = SECITPDK_FXYWWithdraw_ASync(sKhh, sJys, 10001);
    if (nRet > 0)
        printf("SECITPDK_FXYWWithdraw_ASync success:%ld\n", nRet);
    else
    {
        string msg = SECITPDK_GetLastError();              //下单失败，获取错误信息
        printf("SECITPDK_FXYWWithdraw_ASync failed. Msg:%s\n", msg.c_str());
    }
}


void query_dictdata_example()
{

    /*
        SECITPDK_BeginQuery需要配合SECITPDK_GetQuery、SECITPDK_EndQuery使用
    */
    printf("=========== query_dict_example ============\n");
    //查询交易所信息
    long nRet = (long)SECITPDK_BeginQuery(table_jys, sKhh);
    if (nRet < 0)
    {
        string msg = SECITPDK_GetLastError();              //查询失败，获取错误信息
        printf("SECITPDK_BeginQuery table_jys failed. Msg:%s\n", msg.c_str());
        return;
    }

    printf("SECITPDK_BeginQuery table_jys success. Num of results %ld.\n", nRet);
    for (int index = 0; index < nRet; ++index)         //读取结果
    {
        ITPDK_JYS jysRecord;
        if (SECITPDK_GetQuery(table_jys, sKhh, (void*)&jysRecord, sizeof(ITPDK_JYS), index))
        {
            printf("Market:%s -- MarketName:%s;MarketFullName:%s;\n",
                jysRecord.Market, jysRecord.MarketName, jysRecord.MarketFullName);
        }
    }
    SECITPDK_EndQuery(table_jys, sKhh);                   //释放
}


void query_tradedata_example()
{
    printf("=========== query_tradedata_example ============\n");
    long nRet = 0;
    //资金信息
    vector<ITPDK_ZJZH> arZjzh;
    arZjzh.reserve(5);
    nRet = (long)SECITPDK_QueryFundInfo(sKhh, arZjzh);
    if (nRet < 0)                               //查询失败
    {
        string msg = SECITPDK_GetLastError();
        printf("SECITPDK_QueryFundInfo failed. Msg:%s\n", msg.c_str());
    }
    else
    {                                           //查询结果
        printf("SECITPDK_QueryFundInfo success. Num of results %ld.\n", nRet);
        for (auto& itr : arZjzh)
        {
            printf("FundAccount:%s;AccountId:%s -- MoneyType:%s;FundAvl:%f;FrozenBalance:%f;TotalAsset:%f;MarketValue:%f;\n",
                itr.FundAccount, itr.AccountId, itr.MoneyType, itr.FundAvl, itr.FrozenBalance, itr.TotalAsset, itr.MarketValue);
        }
    }
    //查询客户股东信息
    vector<ITPDK_GDH> arGDH;
    arGDH.reserve(5);
    nRet = (long)SECITPDK_QueryAccInfo(sKhh, arGDH);
    if (nRet < 0)
    {
        string msg = SECITPDK_GetLastError();              //查询失败，获取错误信息
        printf("SECITPDK_QueryAccInfo failed. Msg:%s\n", msg.c_str());
        return;
    }
    printf("SECITPDK_QueryAccInfo success. Num of results %ld.\n", nRet);
    for (auto& itr : arGDH)
    {
        printf("AccountId:%s -- Market:%s;SecuAccount:%s;FundAccount:%s;\n",
            itr.AccountId, itr.Market, itr.SecuAccount, itr.FundAccount);

        if (0 == strcmp(itr.Market, "SH"))
        {
            strncpy(sShGdh, itr.SecuAccount, sizeof(sShGdh));
            strncpy(sShZjzh, itr.FundAccount, sizeof(sShZjzh));
        }
        if (0 == strcmp(itr.Market, "SZ"))
        {
            strncpy(sSzGdh, itr.SecuAccount, sizeof(sSzGdh));
            strncpy(sSzZjzh, itr.FundAccount, sizeof(sSzZjzh));
        }
    }
    //当日委托查询
    vector<ITPDK_DRWT> arDrwt;
    arDrwt.reserve(200);                        //需要预分配足够空间，查询结果最大返回200条
    nRet = (long)SECITPDK_QueryOrders(sKhh, 0, SORT_TYPE_AES, 2, 0, "", "", 0, arDrwt);
    if (nRet < 0)                               //查询失败
    {
        string msg = SECITPDK_GetLastError();
        printf("SECITPDK_QueryOrders failed. Msg:%s\n", msg.c_str());
    }
    else
    {                                           //查询结果
        printf("SECITPDK_QueryOrders success. Num of results %ld.\n", nRet);
        for (auto& itr : arDrwt)
        {
            printf("WTH:%ld -- SBWTH:%s;StockCode:%s;JYS:%s;WTJG:%.2f;CurrentQty:%ld;BrowIndex:%ld;\n",
                (long)itr.OrderId, itr.SBWTH, itr.StockCode, itr.Market, itr.OrderPrice, (long)itr.OrderQty, (long)itr.BrowIndex);
        }
    }
    //实时成交查询
    vector<ITPDK_SSCJ> arSscj;
    arSscj.reserve(200);                        //需要预分配足够空间，查询结果最大返回200条
    nRet = (long)SECITPDK_QueryMatchs(sKhh, 0, SORT_TYPE_AES, 2, 0, "", "", 0, arSscj);
    if (nRet < 0)
    {
        string msg = SECITPDK_GetLastError();
        printf("SECITPDK_QueryMatchs failed. Msg:%s\n", msg.c_str());
    }
    else
    {
        printf("SECITPDK_QueryMatchs success. Num of results %ld.\n", nRet);
        for (auto& itr : arSscj)
        {
            printf("StockName:%s -- WTH:%ld;StockCode:%s;JYS:%s;CJSL:%ld;WithdrawFlag:%s;BatchNo:%ld;KFSBDBH:%ld;BrowIndex:%ld;\n",
                itr.StockName, (long)itr.OrderId, itr.StockCode, itr.Market, (long)itr.MatchQty, itr.WithdrawFlag, itr.BatchNo, itr.KFSBDBH, (long)itr.BrowIndex);
        }
    }
    //持仓查询
    vector<ITPDK_ZQGL> arZqgl;
    arZqgl.reserve(200);                        //需要预分配足够空间，查询结果最大返回200条
    nRet = (long)SECITPDK_QueryPositions(sKhh, SORT_TYPE_AES, 2, 0, "", "", "", 0, arZqgl);
    if (nRet < 0)
    {
        string msg = SECITPDK_GetLastError();
        printf("SECITPDK_QueryPositions failed. Msg:%s\n", msg.c_str());
    }
    else
    {
        printf("SECITPDK_QueryPositions success. Num of results %ld.\n", nRet);
        for (auto& itr : arZqgl)
        {
            printf("StockName:%s -- AccountId:%s;StockCode:%s;CurrentQty:%ld;BrowIndex:%ld;\n",
                itr.StockName, itr.AccountId, itr.StockCode, (long)itr.CurrentQty, (long)itr.BrowIndex);
        }
    }
}


void yhld_example()
{
    /*
        一户两地相关接口
    */
    printf("=========== yhld_example ============\n");
    //节点可划拨资金额度查询
    {
        int64 nNode = 3;            //查询节点
        double dKYZJ = 1000.0;      //可用
        double dED = SECITPDK_QueryJDKYZJ(sKhh, sSzGdh, nNode, dKYZJ);
        if (dED < 0)
        {
            string msg = SECITPDK_GetLastError();
            printf("SECITPDK_FundTransBetweenNodes failed. Msg:%s\n", msg.c_str());
        }
        else
            printf("SECITPDK_FundTransBetweenNodes success. ED:%lf\n", dED);
    }
    //节点间资金划拨
    {
        double dFSJE = 1000.0;      //划拨金额
        int64 nNode1 = 3;           //划出节点
        int64 nNode2 = 4;           //划入节点
        const char sZy[] = "SECITPDK_FundTransBetweenNodes";   //摘要信息
        int64 nRet = SECITPDK_FundTransBetweenNodes(sKhh, sSzZjzh, dFSJE, nNode1, nNode2, sZy);
        if (nRet < 0)
        {
            string msg = SECITPDK_GetLastError();
            printf("SECITPDK_FundTransBetweenNodes failed. Msg:%s\n", msg.c_str());
        }
        else
            printf("SECITPDK_FundTransBetweenNodes success.\n");
    }
    //资金划拨策略查询
    {
        vector<ZJHBCL> arZJHBCL;
        int64 nRet = SECITPDK_QueryZJHBCL(sKhh, sSzZjzh, arZJHBCL);
        if (nRet < 0)
        {
            string msg = SECITPDK_GetLastError();
            printf("SECITPDK_QueryZJHBCL failed. Msg:%s\n", msg.c_str());
        }
        else
        {
            printf("SECITPDK_QueryZJHBCL success. Num of results %ld.\n", (long)nRet);
            for (auto& itr : arZJHBCL)
            {
                printf("AccountId:%s -- FundAccount:%s;MoneyType:%s;NodeId:%ld;Market:%s;Rate:%lf;\n",
                    itr.AccountId, itr.FundAccount, itr.MoneyType, (long)itr.NodeId, itr.Market, itr.Rate);
            }
        }
    }
    //修改资金策略
    {
        int64 nNode1 = 3;           //节点1
        int64 nNode2 = 4;           //节点2
        double dBL1 = 0.3;          //节点1资金比例
        double dBL2 = 0.7;          //节点2资金比例
        const char sZy[] = "SECITPDK_ModifyZJHBCL";   //摘要信息
        int64 nRet = SECITPDK_ModifyZJHBCL(sKhh, sSzZjzh, nNode1, nNode2, dBL1, dBL2, sZy);
        if (nRet < 0)
        {
            string msg = SECITPDK_GetLastError();
            printf("SECITPDK_ModifyZJHBCL failed. Msg:%s\n", msg.c_str());
        }
        else
            printf("SECITPDK_ModifyZJHBCL success.\n");
    }
}

