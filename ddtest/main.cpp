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
#include "util/tc_base64.h"

#include "secitpdk/secitpdk.h"


using namespace std;
using namespace taf;

string SECITPDK_GetLastError()
{
    char msg[256];
    SECITPDK_GetLastError(msg);            //获取错误信息
    return TC_Encoder::gbk2utf8(msg);
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
            LOG_CONSOLE_DEBUG << "SECITPDK_SetFuncCallback|" << TC_Encoder::gbk2utf8(pMsg) << endl;
        }
    );

    SECITPDK_SetMsgCallback(               //设置消息推送回调函数
        [](const char* pTime, const char* pMsg, int nType)
        {
            LOG_CONSOLE_DEBUG << "SECITPDK_SetMsgCallback|" << TC_Encoder::gbk2utf8(pMsg) << endl;
        }
    );

    SECITPDK_SetConnEventCallback(
        [](const char* pKhh, const char* pConnKey, int nEvent, void* pData)
        {
            cout << "SetConnEventCallback|pKhh=" << pKhh << "|pConnKey=" << pConnKey << "|nEvent=" << nEvent << "|pData=" << pData << endl;
        }
    );
}

void test()
{
    SECITPDK_SetLogPath("log");            //日志目录
    SECITPDK_SetProfilePath("");           //配置文件目录

    if (!SECITPDK_Init(0))                      //初始化，在所有接口使用前调用，除路径设置接口外
    {
        cout << "SECITPDK_Init failed" << endl;
        return;
    }
    SECITPDK_SetWriteLog(true);
    SECITPDK_SetFixWriteLog(false);

    SECITPDK_SetWTFS("32");               //设置委托方式
    SECITPDK_SetNode("127.0.0.1");               //设置站点信息

    callback_example();

    // const char* sKhh = "250418851205";
    // const char* sShGdh = "B880643886";
    // const char* sSzGdh = "8512212211";
    // const char* sPwd = "159357";
    // const char* section = "A5_RS_2";

    // const char* sKhh = "250418875796";
    // const char* sShGdh = "A179230381";
    // const char* sSzGdh = "0176347210";
    // const char* sPwd = "123321";
    // const char* section = "A5_RS_2";

    const char* sKhh = "10300761010";
    const char* sShGdh = "A466634405";
    const char* sSzGdh = "0000342006";
    const char* sPwd = "123321";
    const char* section = "A5_RS";

    // const char* sKhh = "010100106235";
    // const char* sShGdh = "A466634405";
    // const char* sSzGdh = "0000342006";
    // const char* sPwd = "123321";
    // const char* section = "A5_RS_2";

    // const char* sKhh = "10100003964";
    // const char* sShGdh = "A466634405";
    // const char* sSzGdh = "0000342006";
    // const char* sPwd = "123456";
    // const char* section = "A5_RS_2";


    int64 nRet = 0;
    ProgressTimer t;

    nRet = SECITPDK_TradeLogin(section, sKhh, sPwd);     //登录
    if (nRet <= 0)
    {
        string msg = SECITPDK_GetLastError();              //登录失败，获取错误信息
        printf("Login failed. Msg:%s\n", msg.c_str());
    }
    else
    {
        printf("Login success. Token:%ld\n", nRet);
    }
    cout << "111111=" << t.elapse() << endl;

    getchar();

    nRet = SECITPDK_TradeLogout(sKhh);
    cout << "logout, ret=" << nRet << endl;

    getchar();

    // int64_t token1, token2;

    // {
    //     ITPDK_CusReqInfo cusreqinfo;
    //     strcpy(cusreqinfo.AccountId, sKhh); //客户号
    //     strcpy(cusreqinfo.Password, sPwd); //交易密码
    //     strcpy(cusreqinfo.NodeInfo, "site16"); //操作站点
    //     strcpy(cusreqinfo.EntrustWay, "128"); //委托方式

    //     nRet = SECITPDK_TradeLoginEx("A5_RS", cusreqinfo);     //登录
    //     if (nRet <= 0)
    //     {
    //         string msg = SECITPDK_GetLastError();              //登录失败，获取错误信息
    //         printf("Login failed. Ret:%lld, Msg:%s\n", nRet, msg.c_str());
    //     }
    //     else
    //     {
    //         printf("Login success. Token:%ld\n", nRet);
    //     }
    //     cout << cusreqinfo.Token << endl;
    //     cout << cusreqinfo.TradeNodeID << endl;
    //     token1 = cusreqinfo.Token;
    //     getchar();
    // }

    // {
    //     ITPDK_CusReqInfo cusreqinfo;
    //     strcpy(cusreqinfo.AccountId, sKhh); //客户号
    //     strcpy(cusreqinfo.Password, "sPwd"); //交易密码
    //     strcpy(cusreqinfo.NodeInfo, "site16"); //操作站点
    //     strcpy(cusreqinfo.EntrustWay, "128"); //委托方式

    //     nRet = SECITPDK_TradeLoginEx("A5_RS", cusreqinfo);     //登录
    //     if (nRet <= 0)
    //     {
    //         string msg = SECITPDK_GetLastError();              //登录失败，获取错误信息
    //         printf("Login failed. Ret:%d, Msg:%s\n", nRet, msg.c_str());
    //     }
    //     else
    //     {
    //         printf("Login success. Token:%ld\n", nRet);
    //     }
    //     cout << cusreqinfo.Token << endl;
    //     cout << cusreqinfo.TradeNodeID << endl;
    //     // token1 = cusreqinfo.Token;
    //     getchar();
    // }

    // std::thread([&](){
    //     LOG_CONSOLE_DEBUG << "sssssssssssssssssssss11111111" << endl;
    //     std::lock_guard<std::mutex> lock(mtx);

    //     ITPDK_CusReqInfo cusreqinfo;
    //     strcpy(cusreqinfo.AccountId, sKhh); //客户号
    //     strcpy(cusreqinfo.Password, sPwd); //交易密码
    //     strcpy(cusreqinfo.NodeInfo, "site32"); //操作站点
    //     strcpy(cusreqinfo.EntrustWay, "32"); //委托方式

    //     nRet = SECITPDK_TradeLoginEx("A5_RS", cusreqinfo);     //登录
    //     if (nRet <= 0)
    //     {
    //         string msg = SECITPDK_GetLastError();              //登录失败，获取错误信息
    //         printf("Login failed. Msg:%s\n", msg.c_str());
    //     }
    //     else
    //     {
    //         printf("Login success. Token:%ld\n", nRet);
    //     }
    //     cout << cusreqinfo.Token << endl;
    //     cout << cusreqinfo.TradeNodeID << endl;
    //     token2 = cusreqinfo.Token;
    //     // getchar();
    // }).detach();

    // {
    // // std::thread([&](){
    //     LOG_CONSOLE_DEBUG << "yyyyyyyyyyyyyyyyy" << endl;
    //     std::lock_guard<std::mutex> lock(mtx);
    //     for (int i = 0; i < 1; i++)
    //     {
    //         printf("=========== trade_async_example ============\n");
    //         int64 nWtsl = 100;                  //委托数量
    //         double dWtjg = 18.1;                //委托价格
    //         const char* sJys = "SZ";
    //         const char* sZQDM = "000001";
    //         const char* sGdh = sSzGdh;

    //         ITPDK_CusReqInfo cusreqinfo;
    //         strcpy(cusreqinfo.AccountId, sKhh);
    //         strcpy(cusreqinfo.SecuAccount, sSzGdh);
    //         // strcpy(cusreqinfo.Password, "123123");
    //         // cusreqinfo.TradeNodeID = 2;
    //         // strcpy(cusreqinfo.EntrustWay, "32");
    //         strcpy(cusreqinfo.NodeInfo, "aaaaaaaa");
    //         cusreqinfo.Token = token1;

    //         // //异步接口下单
    //         // // nRet = SECITPDK_OrderEntrust_ASync(sKhh, sJys, sZQDM, JYLB_BUY, nWtsl, dWtjg, DDLX_XJWT, sGdh, 0);
    //         nRet = SECITPDK_OrderEntrustEx_ASync(cusreqinfo, sJys, sZQDM, JYLB_BUY, nWtsl, dWtjg, DDLX_XJWT, 0);
    //         cout << "SECITPDK_OrderEntrustEx_ASync, ret=" << nRet << endl;
    //     }
    // // }).detach();
    // }


    // {
    //     printf("=========== trade_async_example ============\n");
    //     int64 nWtsl = 1100;                  //委托数量
    //     double dWtjg = 21.1;                //委托价格
    //     const char* sJys = "SH";
    //     const char* sZQDM = "689009";
    //     const char* sGdh = sShGdh;
    //     // const char* sJys = "SZ";
    //     // const char* sZQDM = "000001";
    //     // const char* sGdh = sSzGdh;

    //     ITPDK_CusReqInfo cusreqinfo;
    //     strcpy(cusreqinfo.AccountId, sKhh);
    //     strcpy(cusreqinfo.SecuAccount, sGdh);
    //     // strcpy(cusreqinfo.Password, "123123");
    //     // cusreqinfo.TradeNodeID = 2;
    //     // strcpy(cusreqinfo.EntrustWay, "32");
    //     strcpy(cusreqinfo.NodeInfo, "aaaaaaaa");
    //     cusreqinfo.Token = token1;

    //     // //异步接口下单
    //     // // nRet = SECITPDK_OrderEntrust_ASync(sKhh, sJys, sZQDM, JYLB_BUY, nWtsl, dWtjg, DDLX_XJWT, sGdh, 0);
    //     nRet = SECITPDK_OrderEntrustEx_ASync(cusreqinfo, sJys, sZQDM, JYLB_BUY, nWtsl, dWtjg, DDLX_XJWT, 0);
    //     cout << "SECITPDK_OrderEntrustEx_ASync, ret=" << nRet << "|" << SECITPDK_GetLastError() << endl;
    // }

    getchar();

    // std::thread([&](){
    //     for (int i = 0; i < 1; i++)
    //     {
    //         printf("=========== trade_async_example ============\n");
    //         int64 nWtsl = 100;                  //委托数量
    //         double dWtjg = 18.2;                //委托价格
    //         const char* sJys = "SZ";
    //         const char* sZQDM = "000001";
    //         const char* sGdh = sSzGdh;

    //         ITPDK_CusReqInfo cusreqinfo;
    //         strcpy(cusreqinfo.AccountId, sKhh);
    //         strcpy(cusreqinfo.SecuAccount, sSzGdh);
    //         // strcpy(cusreqinfo.Password, "123123");
    //         // cusreqinfo.TradeNodeID = 2;
    //         // strcpy(cusreqinfo.EntrustWay, "32");
    //         strcpy(cusreqinfo.NodeInfo, "aaaaaaaa");
    //         cusreqinfo.Token = token2;

    //         // //异步接口下单
    //         // // nRet = SECITPDK_OrderEntrust_ASync(sKhh, sJys, sZQDM, JYLB_BUY, nWtsl, dWtjg, DDLX_XJWT, sGdh, 0);
    //         nRet = SECITPDK_OrderEntrustEx_ASync(cusreqinfo, sJys, sZQDM, JYLB_BUY, nWtsl, dWtjg, DDLX_XJWT, 0);
    //         cout << "SECITPDK_OrderEntrustEx_ASync, ret=" << nRet << endl;
    //     }
    // }).detach();

    // {
    //     printf("=========== trade_async_example ============\n");
    //     int64 nWtsl = 1100;                  //委托数量
    //     double dWtjg = 18.1;                //委托价格
    //     const char* sJys = "SZ";
    //     const char* sZQDM = "000001";
    //     const char* sGdh = sSzGdh;

    //     ITPDK_CusReqInfo cusreqinfo;
    //     strcpy(cusreqinfo.AccountId, sKhh);
    //     strcpy(cusreqinfo.SecuAccount, sSzGdh);
    //     // strcpy(cusreqinfo.Password, "123123");
    //     // cusreqinfo.TradeNodeID = 2;
    //     // strcpy(cusreqinfo.EntrustWay, "32");
    //     strcpy(cusreqinfo.NodeInfo, "aaaaaaaa");
    //     cusreqinfo.Token = token1;

    //     // //异步接口下单
    //     // // nRet = SECITPDK_OrderEntrust_ASync(sKhh, sJys, sZQDM, JYLB_BUY, nWtsl, dWtjg, DDLX_XJWT, sGdh, 0);
    //     nRet = SECITPDK_OrderEntrustEx_ASync(cusreqinfo, sJys, sZQDM, JYLB_BUY, nWtsl, dWtjg, DDLX_XJWT, 0);
    //     cout << "SECITPDK_OrderEntrustEx_ASync, ret=" << nRet << endl;
    // }

    // {
    //     printf("=========== trade_async_example ============\n");
    //     int64 nWtsl = 1200;                  //委托数量
    //     double dWtjg = 18.2;                //委托价格
    //     const char* sJys = "SZ";
    //     const char* sZQDM = "000001";
    //     const char* sGdh = sSzGdh;

    //     ITPDK_CusReqInfo cusreqinfo;
    //     strcpy(cusreqinfo.AccountId, sKhh);
    //     strcpy(cusreqinfo.SecuAccount, sSzGdh);
    //     // strcpy(cusreqinfo.Password, "123123");
    //     // cusreqinfo.TradeNodeID = 2;
    //     // strcpy(cusreqinfo.EntrustWay, "32");
    //     strcpy(cusreqinfo.NodeInfo, "bbbbbbbbbb");
    //     cusreqinfo.Token = token2;

    //     // //异步接口下单
    //     // // nRet = SECITPDK_OrderEntrust_ASync(sKhh, sJys, sZQDM, JYLB_BUY, nWtsl, dWtjg, DDLX_XJWT, sGdh, 0);
    //     nRet = SECITPDK_OrderEntrustEx_ASync(cusreqinfo, sJys, sZQDM, JYLB_BUY, nWtsl, dWtjg, DDLX_XJWT, 0);
    //     cout << "SECITPDK_OrderEntrustEx_ASync, ret=" << nRet << endl;
    // }

    getchar();

    // {
    //     nRet = SECITPDK_TradeLogout(sKhh);
    //     if (nRet <= 0)
    //     {
    //         string msg = SECITPDK_GetLastError();              //登录失败，获取错误信息
    //         printf("Logout failed. Msg:%s\n", msg.c_str());
    //     }
    //     else
    //     {
    //         printf("Logout success. Token:%ld\n", nRet);
    //     }
    //     getchar();
    // }


    // {
    //     nRet = SECITPDK_TradeLogout(sKhh);
    //     if (nRet <= 0)
    //     {
    //         string msg = SECITPDK_GetLastError();              //登录失败，获取错误信息
    //         printf("Logout failed. Msg:%s\n", msg.c_str());
    //     }
    //     else
    //     {
    //         printf("Logout success. Token:%ld\n", nRet);
    //     }
    //     getchar();
    // }

    // //查询客户股东信息
    // vector<ITPDK_GDH> arGDH;
    // arGDH.reserve(5);
    // nRet = (long)SECITPDK_QueryAccInfo(sKhh, arGDH);
    // if (nRet < 0)
    // {
    //     string msg = SECITPDK_GetLastError();              //查询失败，获取错误信息
    //     printf("SECITPDK_QueryAccInfo failed. Msg:%s\n", msg.c_str());
    //     return;
    // }
    // printf("SECITPDK_QueryAccInfo success. Num of results %ld.\n", nRet);
    // for (auto& itr : arGDH)
    // {
    //     printf("AccountId:%s -- Market:%s;SecuAccount:%s;FundAccount:%s;\n",
    //         itr.AccountId, itr.Market, itr.SecuAccount, itr.FundAccount);
    // }

    //实时成交查询
    vector<ITPDK_SSCJ> arSscj;
    arSscj.reserve(1200);                        //需要预分配足够空间，查询结果最大返回200条
    nRet = (long)SECITPDK_QueryMatchs(sKhh, 0, SORT_TYPE_AES, 1000, 0, "", "", 0, arSscj);
    if (nRet < 0)
    {
        string msg = SECITPDK_GetLastError();
        printf("SECITPDK_QueryMatchs failed. Msg:%d:%s\n", nRet, msg.c_str());
    }
    else
    {
        printf("SECITPDK_QueryMatchs success. Num of results %ld.\n", nRet);
        for (auto& itr : arSscj)
        {
            cout << "-------------------" << endl;
            cout << "AccountId=" << itr.AccountId << endl;
            cout << "Market=" << itr.Market << endl;
            cout << "SecuAccount=" << itr.SecuAccount << endl;
            cout << "MatchSerialNo=" << itr.MatchSerialNo << endl;
            cout << "OrderId=" << itr.OrderId << endl;
            cout << "EntrustType=" << itr.EntrustType << endl;
            cout << "MatchTime=" << itr.MatchTime << endl;
            cout << "StockCode=" << itr.StockCode << endl;
            cout << "StockName=" << TC_Encoder::gbk2utf8(itr.StockName) << endl;
            cout << "MatchQty=" << itr.MatchQty << endl;
            cout << "MatchPrice=" << itr.MatchPrice << endl;
            cout << "MatchAmt=" << itr.MatchAmt << endl;
            cout << "MoneyType=" << itr.MoneyType << endl;
            cout << "ClearBalance=" << itr.ClearBalance << endl;
            cout << "BatchNo=" << itr.BatchNo << endl;
            cout << "EntrustDate=" << itr.EntrustDate << endl;
            cout << "BrowIndex=" << itr.BrowIndex << endl;
            cout << "WithdrawFlag=" << itr.WithdrawFlag << endl;
            cout << "KFSBDBH=" << itr.KFSBDBH << endl;
            cout << "-------------------" << endl;
        }
    }

    // printf("=========== trade_async_example ============\n");
    // int64 nWtsl = 100;                  //委托数量
    // double dWtjg = 16.1;                //委托价格
    // const char* sJys = "SZ";
    // const char* sZQDM = "000001";
    // const char* sGdh = sSzGdh;

    // ITPDK_CusReqInfo cusreqinfo;
    // strcpy(cusreqinfo.AccountId, sKhh);
    // strcpy(cusreqinfo.SecuAccount, sSzGdh);
    // // strcpy(cusreqinfo.Password, "123123");
    // // cusreqinfo.TradeNodeID = 2;
    // // strcpy(cusreqinfo.EntrustWay, "32");
    // // strcpy(cusreqinfo.NodeInfo, "123.145.214.122");
    // // cusreqinfo.Token = 0;

    // //异步接口下单
    // // nRet = SECITPDK_OrderEntrust_ASync(sKhh, sJys, sZQDM, JYLB_BUY, nWtsl, dWtjg, DDLX_XJWT, sGdh, 0);
    // nRet = SECITPDK_OrderEntrustEx_ASync(cusreqinfo, sJys, sZQDM, JYLB_BUY, nWtsl, dWtjg, DDLX_XJWT, 0);
    // mymap[0] = TC_Common::now2us();
    // // int64_t ret64 = SECITPDK_OrderWithdraw_ASync("10300761010", "SH", 25, 1);
    // if (nRet > 0)
    // {
    //     // printf("SECITPDK_OrderEntrust_ASync success:%ld\n", nRet);
    // }
    // else
    // {
    //     string msg = SECITPDK_GetLastError();              //下单失败，获取错误信息
    //     printf("SECITPDK_OrderEntrust_ASync failed. Msg:%d:%s\n", nRet, msg.c_str());
    // }
    // TC_Common::msleep(100);



    // nRet = SECITPDK_ZQHGEntrust_ASync(sKhh, "SH", "204001", JYLB_HGRQ, 100, 1.0, DDLX_XJWT, sShGdh, 0);
    // if (nRet > 0)
    // {
    //     printf("SECITPDK_ZQHGEntrustEx_ASync success:%ld\n", nRet);
    // }
    // else
    // {
    //     string msg = SECITPDK_GetLastError();              //下单失败，获取错误信息
    //     printf("SECITPDK_ZQHGEntrustEx_ASync failed. Msg:%d:%s\n", nRet, msg.c_str());
    // }

    // nRet = SECITPDK_OrderEntrust(sKhh, sJys, sZQDM, JYLB_BUY, nWtsl, dWtjg, DDLX_XJWT, sSzGdh);
    // if (nRet > 0)
    //     printf("SECITPDK_OrderEntrustEx success:%ld\n", nRet);
    // else
    // {
    //     string msg = SECITPDK_GetLastError();              //下单失败，获取错误信息
    //     printf("SECITPDK_OrderEntrustEx failed. ret = %d, Msg:%s\n", nRet, msg.c_str());
    // }

    // nRet = SECITPDK_ETFEntrustEx_ASync(cusreqinfo, "SZ", "159970", JYLB_ETFSH, 1000, "", 0);
    // if (nRet > 0)
    //     printf("SECITPDK_ETFEntrustEx_ASync success:%ld\n", nRet);
    // else
    // {
    //     string msg = SECITPDK_GetLastError();              //下单失败，获取错误信息
    //     printf("SECITPDK_ETFEntrustEx_ASync failed. ret = %d, Msg:%s\n", nRet, msg.c_str());
    // }

    // nRet = SECITPDK_ETFEntrust(sKhh, "SZ", "159901", JYLB_ETFSH, 1000000,  sSzGdh, "");
    // // nRet = SECITPDK_ETFEntrust(sKhh, "SZ", "159970", JYLB_ETFSH, 100,  sSzGdh, "");
    // if (nRet > 0)
    //     printf("SECITPDK_ETFEntrust success:%ld\n", nRet);
    // else
    // {
    //     string msg = SECITPDK_GetLastError();              //下单失败，获取错误信息
    //     printf("SECITPDK_ETFEntrust failed. ret = %d, Msg:%s\n", nRet, msg.c_str());
    // }

    // cout << "cusreqinfo.AccountId=" << cusreqinfo.AccountId << endl;
    // cout << "cusreqinfo.SecuAccount=" << cusreqinfo.SecuAccount << endl;
    // cout << "cusreqinfo.Password=" << cusreqinfo.Password << endl;
    // cout << "cusreqinfo.TradeNodeID=" << cusreqinfo.TradeNodeID << endl;
    // cout << "cusreqinfo.EntrustWay=" << cusreqinfo.EntrustWay << endl;
    // cout << "cusreqinfo.NodeInfo=" << cusreqinfo.NodeInfo << endl;
    // cout << "cusreqinfo.Token=" << cusreqinfo.Token << endl;
    // cout << "cusreqinfo.RetCode=" << cusreqinfo.RetCode << endl;
    // cout << "cusreqinfo.ErrMsg=" << TC_Encoder::gbk2utf8(cusreqinfo.ErrMsg) << endl;

    while (1)
    {
        TC_Common::msleep(1000);
    }

    SECITPDK_Exit();
}

int main()
{
    cout << "welcome" << endl;

    // ProgressTimer t;
    test();
    // cout << "elapsed: " << t.elapse() << endl;

    cout << "byebye" << endl;
    return 0;
}
