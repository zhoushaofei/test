#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "util/tc_common.h"
#include "util/tc_option.h"
#include "util/tc_encoder.h"
#include "event/EventManager.h"
#include "event/TimeUtil.h"

#include "maCliApi.h"

using namespace taf;

TC_Option option;


//金证服务端的返回结果
struct JZMARecordData
{
    int errCode = 0;
    string errMsg;
    vector<string> keys;
    vector<map<string, string>> paramOut;
};

struct TradeAccount
{
    string accountId = "";
    string cuacct_code = "";
    string cust_code = "";
    string orgid = "";
    string session = "";
    string secuid_sza = "";
    string secuid_sha = "";
};

struct GlobalParams
{
    string userId = "10061";
    string entrustId = "123";

    // string serverIp = "192.168.8.41";
    // int serverPort = 41000;
    // string accountId = "161100000005";
    // string password = "123123";
    // string channel = "5";

    string serverIp = "9.75.100.24";
    int serverPort = 41000;
    string accountId = "010100000301";
    string password = "159357";
    string channel = "5";

    // string serverIp = "10.8.8.177";
    // int serverPort = 41000;
    // string accountId = "010100000301";
    // string password = "159357";
    // string channel = "5";

    TradeAccount acc;

    MACLIHANDLE hHandle = nullptr;

    int64_t reqTimeUs = 0;
    int64_t rspTimeUs = 0;
    int64_t confirmTimeUs = 0;
};

GlobalParams g_params;

// ############################################################################
static string maCli_GetVersion_wrapper(MACLIHANDLE handle)
{
    char verbuf[128] = {0};
    maCli_GetVersion(handle, verbuf, sizeof(verbuf) - 1);
    return string(verbuf);
}

static string maCli_GetValueS_wrapper(MACLIHANDLE handle, const char* field)
{
    char buf[1024] = {0x00};
    maCli_GetValueS(handle, buf, sizeof(buf), field);
    return string(buf);
}

static char maCli_GetValueC_wrapper(MACLIHANDLE handle, const char* field)
{
    char value = '\0';
    maCli_GetValueC(handle, &value, field);
    return value;
}

static int64_t maCli_GetValueL_wrapper(MACLIHANDLE handle, const char* field)
{
    long long value = 0;
    maCli_GetValueL(handle, &value, field);
    return value;
}

// static int maCli_GetLastErrorCode_wrapper(MACLIHANDLE handle)
// {
//     int eno = 0;
//     maCli_GetLastErrorCode(handle, &eno);
//     return eno;
// }

static string maCli_GetLastErrorMsg_wrapper(MACLIHANDLE handle)
{
    char buf[512 + 1] = {0};
    maCli_GetLastErrorMsg(handle, buf, sizeof(buf));
    return TC_Encoder::gbk2utf8(buf);
}


// ############################################################################


void initParam()
{
    if (option.hasParam("userId"))
    {
        g_params.userId = option.getValue("userId");
    }
    if (option.hasParam("entrustId"))
    {
        g_params.entrustId = option.getValue("entrustId");
    }
    if (option.hasParam("accountId"))
    {
        g_params.accountId = option.getValue("accountId");
    }
    if (option.hasParam("password"))
    {
        g_params.password = option.getValue("password");
    }
}

void printJZMARecordData(const JZMARecordData& recordData)
{
    cout << "errCode=" << recordData.errCode << endl;
    cout << "errMsg=" << recordData.errMsg << endl;
    cout << "record size=" << recordData.paramOut.size() << endl;
    for (auto & item : recordData.paramOut)
    {
        cout << "-----------------------" << endl;
        for (auto & item2 : item)
        {
            cout << item2.first << "=[" << item2.second << "]" << endl;
        }
    }
}




//解协议包
static int unpackPackage(MACLIHANDLE handle, const unsigned char* data, int size, JZMARecordData& recordData)
{
    char szMsgText[256 + 1] = {0};

    int ret = maCli_Parse(handle, data, size);
    if (ret != 0)
    {
        cout << "maCli_Parse failed, ret=" << ret << endl;
        return ret;
    }

    ret = maCli_OpenTable(handle, 1);
    if (ret != 0)
    {
        cout << "maCli_OpenTable(1) failed, ret=" << ret << endl;
        return ret;
    }

    ret = maCli_ReadRow(handle, 1);
    if (ret != 0)
    {
        cout << "maCli_ReadRow failed, ret=" << ret << endl;
        return ret;
    }

    ret = maCli_GetValueN(handle, &recordData.errCode, "8817");
    if (ret != 0)
    {
        cout << "maCli_GetValueN(8817) failed, ret=" << ret << endl;
        return ret;
    }

    // MSG_CODE: 0:成功，100:无查询结果，其他:错误代码
    if (recordData.errCode == 100)
    {
        return 0;
    }
    if (recordData.errCode != 0)
    {
        memset(szMsgText, 0, sizeof(szMsgText));
        maCli_GetValueS(handle, szMsgText, sizeof(szMsgText), "8819");
        recordData.errMsg = TC_Encoder::gbk2utf8(szMsgText);
        return -1;
    }

    if (!recordData.keys.empty())
    {
        int rowCount = 0;

        ret = maCli_OpenTable(handle, 2);
        if (ret != 0)
        {
            cout << "maCli_OpenTable(2) failed, ret=" << ret << endl;
            return ret;
        }

        ret = maCli_GetRowCount(handle, &rowCount);
        if (ret != 0)
        {
            cout << "maCli_GetRowCount failed, ret=" << ret << endl;
            return ret;
        }

        for (int i = 0; i < rowCount; i++)
        {
            ret = maCli_ReadRow(handle, i + 1);
            if (ret != 0)
            {
                break;
            }

            map<string, string> mapRecord;
            for (const auto & item : recordData.keys)
            {
                memset(szMsgText, 0, sizeof(szMsgText));
                maCli_GetValueS(handle, szMsgText, sizeof(szMsgText), item.c_str());
                mapRecord[item] = szMsgText;
            }
            recordData.paramOut.push_back(mapRecord);
        }
    }

    return 0;
}

//解协议包
static int unpackPackage(const unsigned char* data, int size, JZMARecordData& recordData)
{
    MACLIHANDLE handle = nullptr;
    int ret = maCli_Init(&handle);
    if (ret != 0 || !handle)
    {
        cout << "maCli_Init, ret=" << ret << endl;
        return ret;
    }

    ret = unpackPackage(handle, data, size, recordData);
    maCli_Exit(handle);
    return ret;
}

//填协议包头
static void fillFixedHeader(MACLIHANDLE handle, const char* funcId, const char* msgId, char funcType, char pktType)
{
    /* MACLI_HEAD_FID_MSG_TYPE-------消息类型：R-请求消息，A-应答消息 */
    /* MACLI_HEAD_FID_PKT_TYPE-------S系统报文，B业务报文 */
    /* MACLI_HEAD_FID_FUNC_TYPE------指令类型:空格(不明确), T(事务), Q(查询) */

    maCli_SetHdrValueC(handle, 'R', MACLI_HEAD_FID_MSG_TYPE); //消息类型
    maCli_SetHdrValueC(handle, pktType, MACLI_HEAD_FID_PKT_TYPE); //消息类型
    // maCli_SetHdrValueS(handle, "01", MACLI_HEAD_FID_PKT_VER); //协议版本
    maCli_SetHdrValueS(handle, funcId, MACLI_HEAD_FID_FUNC_ID); //功能号
    maCli_SetHdrValueS(handle, msgId, MACLI_HEAD_FID_MSG_ID); //消息号
    maCli_SetHdrValueC(handle, funcType, MACLI_HEAD_FID_FUNC_TYPE); //指令类型

    // std::string tmStr = TC_Common::now2str("%Y-%m-%d %H:%M:%S.000");
    // maCli_SetHdrValueS(handle, tmStr.c_str(), MACLI_HEAD_FID_TIMESTAMP);
    // maCli_SetHdrValueS(handle, "", MACLI_HEAD_FID_DEST_NODE);
    // maCli_SetHdrValueS(handle, "", MACLI_HEAD_FID_USER_SESSION);
}

//填协议包体固定字段
static void fillFixedValue(MACLIHANDLE handle, const TradeAccount& account, const char* funcId)
{
    /* 操作用户代码 填写本次登陆的客户代码 */
    maCli_SetValueS(handle, account.cust_code.c_str(), "8810");
    /* 操作用户角色 1:客户 2:柜员 */
    maCli_SetValueS(handle, "1", "8811");
    /* 操作站点 0:网卡物理地址 ro 1:TCP/IP地址 or 2:电话号码 or 3:其它终端标识 */
    maCli_SetValueS(handle, "", "8812");
    /* 操作渠道 字典字典[CHANNEL] 0:柜台 */
    maCli_SetValueS(handle, g_params.channel.c_str(), "8813");
    /* 会话凭证 */
    maCli_SetValueS(handle, account.session.c_str(), "8814");
    /* 功能代码  功能代码填写登陆功能号,即 10301104 或 10301105 或 10314001。*/
    maCli_SetValueS(handle, funcId, "8815");
    // /* 调用时间 */
    // maCli_SetValueS(handle, tmStr.c_str(), "8816");
    /* 操作机构 被操作者的分支机构(营业部代码) 操作机构填写 0 */
    maCli_SetValueS(handle, account.orgid.c_str(), "8821");
}

//异步调用接口
static int asynCall(MACLIHANDLE handle, const char* msgId, const char* funcId)
{
    ST_MACLI_ASYNCALL stMacliAsyncall = {0};
    int ret = maCli_AsynCall(handle, &stMacliAsyncall);
    if (ret != 0)
    {
        cout << "maCli_AsynCall, ret=" << ret << endl;
        return ret;
    }

    return ret;
}

//订阅消息
static int subscribeTopic(MACLIHANDLE handle, const char* topic, const char* filter, const char* dataset)
{
    static const char* funcId = "00102012";
    char msgId[32 + 1] = {0};

    maCli_GetUuid(handle, msgId, sizeof(msgId));
    maCli_BeginWrite(handle);

    fillFixedHeader(handle, funcId, msgId, 'Q', 'S');

    maCli_SetValueS(handle, topic, "TOPIC"); //订阅主题
    maCli_SetValueS(handle, filter, "FILTER"); //过滤条件
    maCli_SetValueS(handle, dataset, "DATA_SET"); //数据集

    maCli_EndWrite(handle);

    return asynCall(handle, msgId, funcId);
}


static void onNetChanged_static(const char* netStat, const unsigned char* data, int size)
{
    if (strcmp(netStat, "0") == 0)
    {
        LOG_CONSOLE_DEBUG << "connection ok|netStat=" << netStat << endl;
    }
    else if (data)
    {
        LOG_CONSOLE_DEBUG << "connection broken|netStat=" << netStat << "|reason=" << data << endl;
    }
    else
    {
        LOG_CONSOLE_DEBUG << "connection broken|netStat=" << netStat << "|size=" << size << endl;
    }
}

static void onCallback_static(const char* msgId, const unsigned char* data, int size)
{
    LOG_CONSOLE_DEBUG << "onCallback_static|" << msgId << "|" << size << endl;

    JZMARecordData recordData;
    unpackPackage(g_params.hHandle, data, size, recordData);
    printJZMARecordData(recordData);
}

static void onHeartBeat_static(const char* msgId, const unsigned char* data, int size)
{
    LOG_CONSOLE_DEBUG << "onHeartBeat_static|" << msgId << "|" << size << endl;

    JZMARecordData recordData;

    recordData.keys.push_back("SERVER_LOCAL_NODE_ID"); //本节点编号[SERVER_LOCAL_NODE_ID]
    recordData.keys.push_back("SERVER_NODE_ID"); //节点编号[SERVER_NODE_ID]
    recordData.keys.push_back("SERVER_NODE_GID"); //节点组号[SERVER_NODE_GID]
    recordData.keys.push_back("SERVER_SITE_NAME"); //接入站点名[SERVER_SITE_NAME]
    recordData.keys.push_back("SERVER_NODE_TYPE"); //节点类型[SERVER_NODE_TYPE]
    recordData.keys.push_back("SERVER_SITE_IP"); //站点IP[SERVER_SITE_IP]
    recordData.keys.push_back("SERVER_NODE_PWD"); //节点路径[SERVER_NODE_PWD]
    recordData.keys.push_back("SERVER_NODE_USE"); //节点用途[SERVER_NODE_USE]
    recordData.keys.push_back("SERVER_BACK_IP"); //备份站点IP[SERVER_BACK_IP]


    char szMsgText[256 + 1] = {0};
    maCli_Parse(g_params.hHandle, data, size);
    maCli_OpenTable(g_params.hHandle, 1);
    maCli_ReadRow(g_params.hHandle, 1);

    memset(szMsgText, 0, sizeof(szMsgText));
    maCli_GetValueN(g_params.hHandle, &recordData.errCode, "MSG_CODE");

    memset(szMsgText, 0, sizeof(szMsgText));
    maCli_GetValueS(g_params.hHandle, szMsgText, sizeof(szMsgText), "MSG_TEXT");
    recordData.errMsg = TC_Encoder::gbk2utf8(szMsgText);

    int rowCount = 0;
    maCli_OpenTable(g_params.hHandle, 2);
    maCli_GetRowCount(g_params.hHandle, &rowCount);

    for (int i = 0; i < rowCount; i++)
    {
        maCli_ReadRow(g_params.hHandle, i+1);

        map<string, string> mapRecord;
        for (const auto & item : recordData.keys)
        {
            memset(szMsgText, 0, sizeof(szMsgText));
            maCli_GetValueS(g_params.hHandle, szMsgText, sizeof(szMsgText), item.c_str());
            mapRecord[item] = szMsgText;
        }
        recordData.paramOut.push_back(mapRecord);
    }

    // unpackPackage(g_params.hHandle, data, size, recordData);
    printJZMARecordData(recordData);
}

static void onSubscribe_static(const char* msgId, const unsigned char* data, int size)
{
    LOG_CONSOLE_DEBUG << "onSubscribe_static|" << msgId << "|" << size << endl;
}

static void onUnsubscribe_static(const char* msgId, const unsigned char* data, int size)
{
    LOG_CONSOLE_DEBUG << "onUnsubscribe_static|" << msgId << "|" << size << endl;
}

static void onUserLogin_static(const char* msgId, const unsigned char* data, int size)
{
    LOG_CONSOLE_DEBUG << "onUserLogin_static|" << msgId << "|" << size << endl;

    JZMARecordData recordData;

    recordData.keys.push_back("8902"); //客户代码[CUST_CODE,8902]
    recordData.keys.push_back("8920"); //资产账户[CUACCT_CODE,8920]
    recordData.keys.push_back("207"); //交易市场[STKEX,207]
    recordData.keys.push_back("625"); //交易板块[STKBD,625]
    recordData.keys.push_back("448"); //证券账户[STK_TRDACCT,448]
    recordData.keys.push_back("8843"); //交易单元[STKPBU,8843]
    recordData.keys.push_back("8987"); //账户类型[ACCT_TYPE,8987]
    recordData.keys.push_back("9081"); //账户标识[ACCT_ID,9081]
    recordData.keys.push_back("8814"); //会话凭证[SESSION_ID,8814]
    recordData.keys.push_back("8911"); //内部机构[INT_ORG,8911]

    unpackPackage(g_params.hHandle, data, size, recordData);
    printJZMARecordData(recordData);

    for (auto & item : recordData.paramOut)
    {
        g_params.acc.accountId = g_params.accountId;
        g_params.acc.cuacct_code = item["8920"];
        g_params.acc.cust_code = item["8902"];
        g_params.acc.orgid = item["8911"];
        g_params.acc.session = item["8814"];
        if (item["625"] == "00") g_params.acc.secuid_sza = item["448"];
        if (item["625"] == "10") g_params.acc.secuid_sha = item["448"];
    }
}

static void onEnterOrderRsp_static(const char* msgId, const unsigned char* data, int size)
{
    LOG_CONSOLE_DEBUG << "onEnterOrderRsp_static|" << msgId << "|" << size << endl;

    JZMARecordData recordData;

    recordData.keys.push_back("11"); //合同序号[ORDER_ID,11]
    recordData.keys.push_back("625"); //合同序号[STKBD,625]

    unpackPackage(g_params.hHandle, data, size, recordData);
    printJZMARecordData(recordData);
}

static void onCancelOrderRsp_static(const char* msgId, const unsigned char* data, int size)
{
    LOG_CONSOLE_DEBUG << "onCancelOrderRsp_static|" << msgId << "|" << size << endl;
}

static void onQueryDealInfo_static(const char* msgId, const unsigned char* data, int size)
{
    LOG_CONSOLE_DEBUG << "onQueryDealInfo_static|" << msgId << "|" << size << endl;
}

static void onOrderMatch_static(const char* acceptSn, const unsigned char* data, int size)
{
    LOG_CONSOLE_DEBUG << "onOrderMatch_static|" << acceptSn << "|" << size << endl;
}

static void onOrderConfirm_static(const char* acceptSn, const unsigned char* data, int size)
{
    LOG_CONSOLE_DEBUG << "onOrderConfirm_static|" << acceptSn << "|" << size << endl;
}


int initMACLI()
{
    int ret = maCli_Init(&g_params.hHandle);
    if (ret != 0)
    {
        cout << "maCli_Init failed! ret=" << ret << endl;
        return ret;
    }

    //连接参数
    ST_MACLI_CONNECT_OPTION stConnectOption;
    memset(&stConnectOption, 0, sizeof(stConnectOption));

    strcpy(stConnectOption.szServerName, "ServerName");
    stConnectOption.nCommType = 3;
    stConnectOption.nProtocal = 1;

    strcpy(stConnectOption.szSvrAddress, g_params.serverIp.c_str());
    stConnectOption.nSvrPort = g_params.serverPort;

    //设置连接选项
    maCli_SetOptions(g_params.hHandle, MACLI_OPTION_CONNECT_PARAM, &stConnectOption, sizeof(stConnectOption));


    vector<ST_MACLI_ARCALLBACK> pstArCallbackList;
    vector<ST_MACLI_PSCALLBACK> pstPsCallbackList;
    ST_MACLI_NETCALLBACK pstNetCallback;

    //设置连接信息回调函数
    pstNetCallback.pfnCallback = &onNetChanged_static;

    //设置发布内容回调函数
    pstPsCallbackList.push_back((ST_MACLI_PSCALLBACK){"MATCH*", &onOrderMatch_static}); //成交回报推送
    pstPsCallbackList.push_back((ST_MACLI_PSCALLBACK){"CONFIRM*", &onOrderConfirm_static}); //交易确认推送
    pstPsCallbackList.push_back((ST_MACLI_PSCALLBACK){"*", &onCallback_static}); //交易确认推送

    //设置异步应答回调函数
    pstArCallbackList.push_back((ST_MACLI_ARCALLBACK){"00103003", &onHeartBeat_static}); //心跳
    pstArCallbackList.push_back((ST_MACLI_ARCALLBACK){"00102012", &onSubscribe_static}); //订阅
    pstArCallbackList.push_back((ST_MACLI_ARCALLBACK){"00102013", &onUnsubscribe_static}); //退订

    pstArCallbackList.push_back((ST_MACLI_ARCALLBACK){"10301105", &onUserLogin_static}); //客户登录
    pstArCallbackList.push_back((ST_MACLI_ARCALLBACK){"10302001", &onEnterOrderRsp_static}); //买卖委托
    pstArCallbackList.push_back((ST_MACLI_ARCALLBACK){"10302004", &onCancelOrderRsp_static}); //委托撤单

    pstArCallbackList.push_back((ST_MACLI_ARCALLBACK){"10303004", &onQueryDealInfo_static}); //查询成交回报
    pstArCallbackList.push_back((ST_MACLI_ARCALLBACK){"********", &onCallback_static}); //查询成交回报


    //设置连接信息回调函数
    maCli_SetNetCallback(g_params.hHandle, (ST_MACLI_NETCALLBACK*)(&pstNetCallback));

    //用户信息
    ST_MACLI_USERINFO stMacliUserInfo;
    memset(&stMacliUserInfo, 0, sizeof(stMacliUserInfo));

    strcpy(stMacliUserInfo.szServerName, "ServerName");
    strcpy(stMacliUserInfo.szUserId, "KMAP00");
    strcpy(stMacliUserInfo.szPassword, "888888");
    strcpy(stMacliUserInfo.szAppId, "KD_FORTUNE_2");
    strcpy(stMacliUserInfo.szAuthCode, "");

    //连接服务器
    ret = maCli_Open(g_params.hHandle, &stMacliUserInfo);
    if (ret != 0)
    {
        string msg = maCli_GetLastErrorMsg_wrapper(g_params.hHandle);
        cout << "maCli_Open failed! ret=" << ret << "|msg=" << msg << endl;
        return ret;
    }

    //设置异步应答回调函数
    for (const auto & item : pstArCallbackList)
    {
        maCli_SetArCallback(g_params.hHandle, (ST_MACLI_ARCALLBACK*)(&item));
    }

    //设置发布内容回调函数
    for (const auto & item : pstPsCallbackList)
    {
        maCli_SetPsCallback(g_params.hHandle, (ST_MACLI_PSCALLBACK*)(&item));
    }

    //订阅成交回报
    ret = subscribeTopic(g_params.hHandle, "MATCH*", "*", "0");
    if (ret != 0)
    {
        LOG_CONSOLE_DEBUG << "subscribeTopic(MATCH*) failed, ret=" << ret << endl;
        return ret;
    }

    //订阅交易确认
    ret = subscribeTopic(g_params.hHandle, "CONFIRM*", "*", "0");
    if (ret != 0)
    {
        LOG_CONSOLE_DEBUG << "subscribeTopic(CONFIRM*) failed, ret=" << ret << endl;
        return ret;
    }

    cout << "maCli_Open OK!" << endl;
    return 0;
}

void testConnect()
{
    initMACLI();
}

void testHeartBeat()
{
    if (initMACLI() != 0)
    {
        return;
    }
{
    static const char* funcId = "00103003";
    char msgId[32 + 1] = {0};

    maCli_GetUuid(g_params.hHandle, msgId, sizeof(msgId));
    maCli_BeginWrite(g_params.hHandle);

    fillFixedHeader(g_params.hHandle, funcId, msgId, 'Q', 'S');

    maCli_EndWrite(g_params.hHandle);

    int ret = asynCall(g_params.hHandle, msgId, funcId);
    cout << "asynCall, ret=" << ret << endl;

    string msg = maCli_GetLastErrorMsg_wrapper(g_params.hHandle);
    cout << "asynCall, msg=" << msg << endl;
}
getchar();
{
    static const char* funcId = "00103003";
    char msgId[32 + 1] = {0};

    maCli_GetUuid(g_params.hHandle, msgId, sizeof(msgId));
    maCli_BeginWrite(g_params.hHandle);

    fillFixedHeader(g_params.hHandle, funcId, msgId, 'Q', 'S');

    maCli_EndWrite(g_params.hHandle);

    int ret = asynCall(g_params.hHandle, msgId, funcId);
    cout << "asynCall, ret=" << ret << endl;

    string msg = maCli_GetLastErrorMsg_wrapper(g_params.hHandle);
    cout << "asynCall, msg=" << msg << endl;
}
}

void testLogin()
{
    if (initMACLI() != 0)
    {
        return;
    }

    static const char* funcId = "10301105";
    char msgId[32 + 1] = {0};

    maCli_GetUuid(g_params.hHandle, msgId, sizeof(msgId));
    maCli_BeginWrite(g_params.hHandle);

    fillFixedHeader(g_params.hHandle, funcId, msgId, 'Q', 'B');
    fillFixedValue(g_params.hHandle, g_params.acc, funcId);

    maCli_SetValueS(g_params.hHandle, "Z", "8987"); //账户类型[ACCT_TYPE,8987]
    maCli_SetValueS(g_params.hHandle, g_params.accountId.c_str(), "9081"); //账户标识[ACCT_ID,9081]
    maCli_SetValueS(g_params.hHandle, "0", "9082"); //使用范围[USE_SCOPE,9082]
    maCli_SetValueS(g_params.hHandle, g_params.accountId.c_str(), "9086"); //加密因子[ENCRYPT_KEY,9086]
    maCli_SetValueS(g_params.hHandle, "0", "9083"); //认证类型[AUTH_TYPE,9083]

    char szBufAuthData[128] = {0};
    maCli_ComEncrypt(g_params.hHandle, szBufAuthData, sizeof(szBufAuthData), g_params.password.c_str(), g_params.accountId.c_str());
    maCli_SetValueS(g_params.hHandle, szBufAuthData, "9084"); //认证数据[AUTH_DATA,9084]

    maCli_EndWrite(g_params.hHandle);

    asynCall(g_params.hHandle, msgId, funcId);
}

void testEnterOrder()
{
    if (initMACLI() != 0)
    {
        return;
    }
    testLogin();

    cout << "---------------------------------" << endl;
    TC_Common::msleep(2000);
    cout << "---------------------------------" << endl;

    static const char* funcId = "10302001";
    char msgId[32 + 1] = {0};

    int64_t t1 = TC_Common::now2us();

    maCli_GetUuid(g_params.hHandle, msgId, sizeof(msgId));
    maCli_BeginWrite(g_params.hHandle);

    fillFixedHeader(g_params.hHandle, funcId, msgId, 'T', 'B');
    fillFixedValue(g_params.hHandle, g_params.acc, funcId);

    maCli_SetValueS(g_params.hHandle, g_params.acc.cuacct_code.c_str(), "8920"); //资产账户[CUACCT_CODE]
    maCli_SetValueL(g_params.hHandle, 1000, "38"); //委托数量[ORDER_QTY]
    maCli_SetValueN(g_params.hHandle, 100, "8842"); //证券业务[STK_BIZ]
    maCli_SetValueN(g_params.hHandle, 100, "40"); //业务行为[STK_BIZ_ACTION]
    maCli_SetValueS(g_params.hHandle, "CLIENT_INFO", "9039"); //终端信息[CLIENT_INFO]
    maCli_SetValueC(g_params.hHandle, '1', "9080"); //安全手段[SECURITY_LEVEL]

    maCli_SetValueS(g_params.hHandle, g_params.acc.secuid_sha.c_str(), "448"); //证券账户[TRDACCT]
    maCli_SetValueS(g_params.hHandle, "10", "625"); //交易板块[STKBD]
    maCli_SetValueS(g_params.hHandle, "600000", "48"); //证券代码[STK_CODE]
    maCli_SetValueD(g_params.hHandle, 10, "44"); //委托价格[ORDER_PRICE]

    // maCli_SetValueS(g_params.hHandle, g_params.acc.secuid_sza.c_str(), "448"); //证券账户[TRDACCT]
    // maCli_SetValueS(g_params.hHandle, "00", "625"); //交易板块[STKBD]
    // maCli_SetValueS(g_params.hHandle, "000001", "48"); //证券代码[STK_CODE]
    // maCli_SetValueD(g_params.hHandle, 10, "44"); //委托价格[ORDER_PRICE]

    maCli_EndWrite(g_params.hHandle);

    int64_t t2 = TC_Common::now2us();

    asynCall(g_params.hHandle, msgId, funcId);

    g_params.reqTimeUs = TC_Common::now2us();
    cout << "t2-t1=" << t2-t1 << "|t3-t2=" << g_params.reqTimeUs-t2 << endl;
}

void testCancelOrder()
{
    // if (initMACLI() != 0)
    // {
    //     return;
    // }
    // testLogin();
}

void testQueryDealInfo()
{
    // if (initMACLI() != 0)
    // {
    //     return;
    // }
    // testLogin();
}


int main(int argc, char *argv[])
{
    int iRet = -1;
    option.decode(argc, argv);

    try
    {
        string cmd = option.getValue("cmd");
        if (argc < 2)
        {
            cout << "./test --cmd=heartbeat" << endl;
            cout << "./test --cmd=enter" << endl;
            cout << "./test --cmd=cancel" << endl;
            cout << "./test --cmd=dealinfo" << endl;
            cout << "./test --cmd=login" << endl;
            exit(1);
        }
        initParam();

        if (cmd == "heartbeat")
        {
            testHeartBeat();
        }
        else if (cmd == "enter")
        {
            testEnterOrder();
        }
        else if (cmd == "cancel")
        {
            testCancelOrder();
        }
        else if (cmd == "dealinfo")
        {
            testQueryDealInfo();
        }
        else if (cmd == "login")
        {
            testLogin();
        }

        while (1)
        {
            TC_Common::msleep(1000);
        }
    }
    catch (std::exception& e)
    {
        LOG_ERROR << "exception:" << e.what() << endl;
    }
    catch (...)
    {
        LOG_ERROR << "unknown exception." << endl;
    }

    return iRet;
}
