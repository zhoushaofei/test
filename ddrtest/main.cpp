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

#include "maritpdk/maritpdk.h"


using namespace std;
using namespace taf;

string MARITPDK_GetLastError()
{
    char msg[256];
    MARITPDK_GetLastError(msg);            //获取错误信息
    return TC_Encoder::gbk2utf8(msg);
}

void callback_example()
{
    /*
        回调消息以json格式推送，下例使用rapidjson库解析。
        消息中的LSH字段，为下单时送入的值，可用于匹配委托单。
    */
    MARITPDK_SetFuncCallback(              //设置异步接口回调函数
        [](const char* pTime, const char* pMsg, int nType)
        {
            LOG_CONSOLE_DEBUG << "MARITPDK_SetFuncCallback|" << TC_Encoder::gbk2utf8(pMsg) << endl;
        }
    );

    MARITPDK_SetMsgCallback(               //设置消息推送回调函数
        [](const char* pTime, const char* pMsg, int nType)
        {
            LOG_CONSOLE_DEBUG << "MARITPDK_SetMsgCallback|" << TC_Encoder::gbk2utf8(pMsg) << endl;
        }
    );

    MARITPDK_SetConnEventCallback(
        [](const char* pKhh, const char* pConnKey, int nEvent, void* pData)
        {
            cout << "SetConnEventCallback|pKhh=" << (pKhh?pKhh:"null") << "|pConnKey=" << (pConnKey?pConnKey:"null") << "|nEvent=" << nEvent << "|pData=" << (pData?pData:"null") << endl;
        }
    );
}


void test()
{
    MARITPDK_SetLogPath("log");            //日志目录
    MARITPDK_SetProfilePath("./");           //配置文件目录

    if (!MARITPDK_Init(0))                      //初始化，在所有接口使用前调用，除路径设置接口外
    {
        cout << "SECITPDK_Init failed" << endl;
        return;
    }
    MARITPDK_SetWriteLog(true);
    MARITPDK_SetFixWriteLog(false);

    MARITPDK_SetWTFS("128");               //设置委托方式
    MARITPDK_SetNode("127.0.0.1");               //设置站点信息

    callback_example();

    // const char* sKhh = "221188943401";
    // const char* sShGdh = "B888377972";
    // const char* sSzGdh = "0899069080";
    // const char* sPwd = "123123";
    // const char* section = "A5_RS_MR3";

    // const char* sKhh = "221188943404";
    // const char* sShGdh = "B888377975";
    // const char* sSzGdh = "0899069083";
    // const char* sPwd = "123123";
    // const char* section = "A5_RS_MR";

    // const char* sKhh = "10100042406";
    // const char* sShGdh = "E021410969";
    // const char* sSzGdh = "0602152870";
    // const char* sPwd = "123123";
    // const char* section = "A5_RS_MR";

    // const char* sKhh = "10100000009";
    // const char* sShGdh = "E026147260";
    // const char* sSzGdh = "0602629132";
    // const char* sPwd = "123321";
    // const char* section = "A5_RS_MR";

    const char* sKhh = "10100000009";
    const char* sShGdh = "E026147260";
    const char* sSzGdh = "0602629132";
    const char* sPwd = "123321";
    const char* section = "A5_RS_MR2";



    int64 nRet = 0;
    ProgressTimer t;

    nRet = MARITPDK_TradeLogin(section, sKhh, sPwd);     //登录
    if (nRet <= 0)
    {
        string msg = MARITPDK_GetLastError();              //登录失败，获取错误信息
        printf("Login failed. Msg:%s\n", msg.c_str());
    }
    else
    {
        printf("Login success. Token:%ld\n", nRet);
    }
    cout << "111111=" << t.elapse() << endl;

    getchar();

    nRet = MARITPDK_TradeLogout(sKhh);
    cout << "logout, ret=" << nRet << endl;

    getchar();

    vector<ITPDK_XYGDH> arInfo;
    nRet = MARITPDK_QueryAccInfo(sKhh, arInfo);
    if (nRet < 0)
    {
        string msg = MARITPDK_GetLastError();
        printf("MARITPDK_QueryAccInfo failed. Msg:%s\n", msg.c_str());
    }
    else
    {
        printf("MARITPDK_QueryAccInfo success. Token:%ld\n", nRet);
    }
    for (auto & item : arInfo)
    {
        cout << item.AccountId << "|" << item.Market << "|" << item.SecuAccount << "|" << item.HolderType << endl;
    }
    cout << arInfo.size() << endl;


    cout << "=========== 两融信用买入===========" << endl;
    nRet = MARITPDK_MarginEntrust_ASync(sKhh, "SH", "600000", JYLB_BUY, 200, 10, DDLX_XJWT, sShGdh, 0, "", 0, 0);
    // nRet = MARITPDK_MarginEntrust_ASync(sKhh, "SZ", "000001", JYLB_BUY, 200, 10, DDLX_XJWT, sSzGdh, 0, "", 0, 0);
    // nRet = MARITPDK_MarginEntrust_ASync(sKhh, "SH", "010303", JYLB_BUY, 100, 10, DDLX_XJWT, sShGdh, 0, "", 0, 0);
    // nRet = MARITPDK_MarginEntrust_ASync(sKhh, "SZ", "100303", JYLB_BUY, 100, 10, DDLX_XJWT, sSzGdh, 0, "", 0, 0);

    if (nRet > 0)
        cout << "order success. wth:" << nRet << endl;
    else {
        string msg = MARITPDK_GetLastError();
        cout << "order failed. msg:" << msg   << " err code:"<< nRet  << endl;
    }

    while (1)
    {
        TC_Common::msleep(1000);
    }

    MARITPDK_Exit();
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
