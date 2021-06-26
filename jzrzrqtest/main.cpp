#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "util/tc_common.h"
#include "util/tc_option.h"
#include "util/tc_encoder.h"
#include "event/EventManager.h"
#include "event/TimeUtil.h"
#include "KCBPCli.h"
#include "kdencode.h"

using namespace taf;

TC_Option option;


//金证服务端的返回结果
struct JZRecordData
{
    int errCode = 0;
    string errMsg;
    vector<map<string, string>> paramOut;
};

struct TradeAccount
{
    string accountId = "";
    string custid = "";
    string custorgid = "";
    string trdpwd = "";
    string netaddr = "";
    string orgid = "";
    string custcert = "";
    string secuid_sza = "";
    string secuid_sha = "";
};

struct GlobalParams
{
    string userId = "10010";
    string entrustId = "123";

    // string accountId = "010188882128";
    // string password = "123123";

    // string accountId = "200189990005";
    // string password = "123123";

    // string accountId = "080909002012";
    // string password = "123123";

    string accountId = "010188879280";
    string password = "123123";
    TradeAccount acc;

    KCBPCLIHANDLE hHandle = nullptr;
};

GlobalParams g_params;

// ############################################################################

// 金证柜台API封装
static int KCBPCLI_ConnectServer_wrapper(KCBPCLIHANDLE hHandle, const string& ServerName, const string& UserName, const string& Password)
{
    return KCBPCLI_ConnectServer(hHandle, (char*)ServerName.c_str(), (char*)UserName.c_str(), (char*)Password.c_str());
}

static int KCBPCLI_SetValue_wrapper(KCBPCLIHANDLE hHandle, const string& KeyName, const string& Vlu)
{
    return KCBPCLI_SetValue(hHandle, (char*)KeyName.c_str(), (char*)Vlu.c_str());
}

static int KCBPCLI_CallProgramAndCommit_wrapper(KCBPCLIHANDLE hHandle, const string& ProgramName)
{
    return KCBPCLI_CallProgramAndCommit(hHandle, (char*)ProgramName.c_str());
}

static string KCBPCLI_GetErrorMsg_wrapper(KCBPCLIHANDLE hHandle)
{
    char msg[256] = {0};
    KCBPCLI_GetErrorMsg(hHandle, msg);
    return string(msg);
}

static string KDEncode_wrapper(const string& str, const string& key)
{
	unsigned char pDestData[256] = {0};
	KDEncode(KDCOMPLEX_ENCODE, (unsigned char*)str.c_str(), str.length(),
            pDestData, sizeof(pDestData), (void*)key.c_str(), key.length());
    return string((char*)pDestData);
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

void printJZRecordData(const JZRecordData& recordData)
{
    cout << "errCode=" << recordData.errCode << endl;
    cout << "errMsg=" << recordData.errMsg << endl;
    cout << "record size=" << recordData.paramOut.size() << endl;
    for (auto & item : recordData.paramOut)
    {
        cout << "-----------------------" << endl;
        for (auto & item2 : item)
        {
            cout << item2.first << "=" << item2.second << endl;
        }
    }
}

int initKCBPCLI()
{
    int ret = KCBPCLI_Init(&g_params.hHandle);
    if (ret != 0)
    {
        cout << "KCBPCLI_Init failed! ret=" << ret << endl;
        return ret;
    }

    tagKCBPConnectOption stKCBPConnection;
    memset(&stKCBPConnection, 0, sizeof(stKCBPConnection));

    // strcpy(stKCBPConnection.szServerName, "KCXP00");
    // stKCBPConnection.nProtocal = 0;
    // strcpy(stKCBPConnection.szAddress, "172.16.8.34");
    // stKCBPConnection.nPort = 21000;
    // strcpy(stKCBPConnection.szSendQName, "req_rzrq");
    // strcpy(stKCBPConnection.szReceiveQName, "ans_rzrq");

    // strcpy(stKCBPConnection.szServerName, "KCXP00");
    // stKCBPConnection.nProtocal = 0;
    // strcpy(stKCBPConnection.szAddress, "10.1.93.26");
    // stKCBPConnection.nPort = 21000;
    // strcpy(stKCBPConnection.szSendQName, "req_rzrq_gt6");
    // strcpy(stKCBPConnection.szReceiveQName, "ans_rzrq_gt6");

    strcpy(stKCBPConnection.szServerName, "KCXP00");
    stKCBPConnection.nProtocal = 0;
    strcpy(stKCBPConnection.szAddress, "10.4.101.79");
    stKCBPConnection.nPort = 21000;
    strcpy(stKCBPConnection.szSendQName, "req_rzrq");
    strcpy(stKCBPConnection.szReceiveQName, "ans_rzrq");

    // strcpy(stKCBPConnection.szServerName, "KCXP00");
    // stKCBPConnection.nProtocal = 0;
    // strcpy(stKCBPConnection.szAddress, "10.1.93.78");
    // stKCBPConnection.nPort = 21000;
    // strcpy(stKCBPConnection.szSendQName, "req_rzrq_gt61");
    // strcpy(stKCBPConnection.szReceiveQName, "ans_rzrq_gt61");

    // strcpy(stKCBPConnection.szServerName, "KCXP00");
    // stKCBPConnection.nProtocal = 0;
    // strcpy(stKCBPConnection.szAddress, "192.168.8.173");
    // stKCBPConnection.nPort = 21000;
    // strcpy(stKCBPConnection.szSendQName, "req1");
    // strcpy(stKCBPConnection.szReceiveQName, "ans1");


    // 设置连接选项
    ret = KCBPCLI_SetOptions(g_params.hHandle, KCBP_OPTION_CONNECT ,&stKCBPConnection, sizeof(stKCBPConnection));
    if (ret != 0)
    {
        cout << "KCBPCLI_SetOptions failed! ret=" << ret << endl;
        return ret;
    }

    // 设置超时选项
    int timeout = 60;
    ret = KCBPCLI_SetOptions(g_params.hHandle, KCBP_OPTION_TIMEOUT, &timeout, sizeof(timeout));
    if (ret != 0)
    {
        cout << "KCBPCLI_SetOptions failed! ret=" << ret << endl;
        return ret;
    }

    int nValue;
    int nBytes = sizeof(int);
    KCBPCLI_GetOptions(g_params.hHandle, KCBP_OPTION_TIMEOUT, & nValue, &nBytes);
    if (ret != 0)
    {
        cout << "KCBPCLI_GetOptions failed! ret=" << ret << endl;
        return ret;
    }
    else
    {
        cout << "nBytes=" << nBytes << "|nValue=" << nValue << endl;
    }

    if (ret != 0)
    {
        cout << "KCBPCLI_GetOptions failed! ret=" << ret << endl;
        return ret;
    }
    else
    {
        cout << "nBytes=" << nBytes << "|nValue=" << nValue << endl;
    }

    // 连接服务器
    ret = KCBPCLI_ConnectServer_wrapper(g_params.hHandle, "KCXP00", "KCXP00", "888888");
    if (ret != 0)
    {
        string msg = KCBPCLI_GetErrorMsg_wrapper(g_params.hHandle);
        cout << "KCBPCLI_ConnectServer failed! ret=" << ret << "|msg=" << msg << endl;
        return ret;
    }

    cout << "KCBPCLI_ConnectServer OK!" << endl;
    return 0;
}

int setCommonArgs(const TradeAccount& tradeAccount, const string& funcId)
{
    // 清除通信公共数据区
    int ret = KCBPCLI_BeginWrite(g_params.hHandle);
    if (ret != 0)
    {
        cout << "KCBPCLI_BeginWrite failed! ret=" << ret << endl;
        return ret;
    }

    // 功能号	funcid	INT	外围功能编号, 必须送,不可以为空
    // 客户代码	custid	int	登陆后送，登陆客户代码
    // 客户机构	custorgid 	char(4)	登陆后送，客户所属机构
    // 交易密码	trdpwd	char(32)	交易密码
    // 操作站点	netaddr	char(270)	网卡地址或电话号码, 必须送，不可以为空
    // 操作机构	orgid 	char(4)	操作地机构代码, 必须送，不可以为空
    // 操作方式	operway	char(1)	必须送，不可以为空,且必须送外围程序对应的操作方式，不允许送0，否则外围程序无法登陆和委托
    // 扩展	ext	CHAR(1)	目前必须为数值0
    // 客户证书	custcert	char(128)	客户证书，登陆时送空串,登陆后获得，后续请求传递
    // 站点扩位	netaddr2	Char(255)	操作站点扩位，接收MAC地址
    // 统一认证票据	ticket	Char(512)	统一认证票据，非必送，如送值，则校验

    // 设置系统固定入参
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "funcid", funcId); //功能号
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "custid", tradeAccount.custid); //客户代码
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "custorgid", tradeAccount.custorgid); //客户机构
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "trdpwd", tradeAccount.trdpwd); //交易密码
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "netaddr", tradeAccount.netaddr); //操作站点
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "orgid", ""); //操作机构
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "operway", "8"); //操作方式
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "ext", "0"); //扩展
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "custcert", ""); //客户证书
    // KCBPCLI_SetValue_wrapper(g_params.hHandle, "custcert", tradeAccount.custcert); //客户证书
    // KCBPCLI_SetValue_wrapper(g_params.hHandle, "netaddr2", ""); //站点扩位
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "ticket", ""); //统一认证票据

    return 0;
}

int fetchRowData(JZRecordData& recordData)
{
    char sColName[1024] = {0};
    char sColValue[1024] = {0};

    int ret = KCBPCLI_RsOpen(g_params.hHandle);
    if (ret != 0)
    {
        cout << "KCBPCLI_RsOpen failed! ret=" <<  ret << endl;
        return ret;
    }

    ret = KCBPCLI_RsFetchRow(g_params.hHandle);
    if (ret != 0)
    {
        cout << "KCBPCLI_RsFetchRow failed! ret=" <<  ret << endl;
        KCBPCLI_RsClose(g_params.hHandle);
        return ret;
    }

    memset(sColValue, sizeof(sColValue), 0);
    ret = KCBPCLI_RsGetColByName(g_params.hHandle, (char*)"CODE", sColValue);
    if (ret != 0)
    {
        cout << "KCBPCLI_RsGetColByName failed! ret=" <<  ret << "|col=" << "CODE" << endl;
        KCBPCLI_RsClose(g_params.hHandle);
        return ret;
    }
    recordData.errCode = TC_Common::strto<int>(sColValue);

    memset(sColValue, sizeof(sColValue), 0);
    ret = KCBPCLI_RsGetColByName(g_params.hHandle, (char*)"MSG", sColValue);
    if (ret != 0)
    {
        cout << "KCBPCLI_RsGetColByName failed! ret=" <<  ret << "|col=" << "MSG" << endl;
        KCBPCLI_RsClose(g_params.hHandle);
        return ret;
    }
    recordData.errMsg = TC_Encoder::gbk2utf8(sColValue);

    if (KCBPCLI_RsMore(g_params.hHandle) == 0)
    {
        while (KCBPCLI_RsFetchRow(g_params.hHandle) == 0)
        {
            int nCol = 0;
            KCBPCLI_RsGetColNum(g_params.hHandle, &nCol);
            map<string, string> mapRecord;
            for (int i = 1; i <= nCol; i++)
            {
                KCBPCLI_RsGetColName(g_params.hHandle, i, sColName, sizeof(sColName));
                KCBPCLI_RsGetColByName(g_params.hHandle, sColName, sColValue);
                mapRecord[sColName] = TC_Encoder::gbk2utf8(sColValue);
            }
            recordData.paramOut.push_back(mapRecord);
        }
    }

    KCBPCLI_RsClose(g_params.hHandle);
    return ret;
}

int callProgramAndCommit(const string& funcId, JZRecordData& recordData)
{
    ev::ProgressTimer timer;

    // 调用服务端程序
    int ret = KCBPCLI_CallProgramAndCommit_wrapper(g_params.hHandle, funcId);
    if (ret != 0)
    {
        // 当使用服务调用类函数（参见第二章CLIENT API 函数分类）如KCBP
        // CLI_CallProgramAndCommit、KCBPCLI_GetReply 等，返回码如果是2
        // 054、2055、2003 时，表示连接已断，这时需要调用KCBPCLI_DisCon
        // nectForce 关闭连接，然后再调用KCBPCLI_ConnectServer 重现建立连
        // 接。
        //
        // 关于重建连接：函数调用返回码 2054、2055、2003、2004 等说明连接已经断
        // 开，2011 说明接收应答超时，2082 说明数据通讯错误，这时需要调用
        // DisconnectForce 断开连接，然后调用ConnectServer 重新连接。
        // if (ret == 2054 || ret == 2055 || ret == 2003 || ret == 2004 || ret == 2011 || ret == 2082) {
        //     disConnect();
        // }

        string msg = KCBPCLI_GetErrorMsg_wrapper(g_params.hHandle);
        cout << "KCBPCLI_CallProgramAndCommit failed! ret=" << ret << "|msg=" << msg << endl;
        cout << "KCBPCLI_CallProgramAndCommit failed! elapsed=" << timer.elapse() << "|funcId=" << funcId << endl;
        return ret;
    }
    cout << "KCBPCLI_CallProgramAndCommit elapsed=" << timer.elapse() << "|funcId=" << funcId << endl;

    // 获取服务端返回的结果集
    ret = fetchRowData(recordData);
    if (ret != 0)
    {
        cout << "getRecordData failed! ret=" << ret << endl;
        return ret;
    }

    cout << "fetchRowData elapsed=" << timer.elapse() << endl;
    return 0;
}

void testConnect()
{
    initKCBPCLI();
}

void testHeartBeat()
{
    if (initKCBPCLI() != 0)
    {
        return;
    }

    int ret = setCommonArgs(g_params.acc, "410232");
    if (ret != 0)
    {
        cout << "setCommonArgs failed! ret=" << ret << endl;
        return;
    }

    // 调用服务端程序
    JZRecordData recordData;
    ret = callProgramAndCommit("410232", recordData);
    if (ret != 0)
    {
        cout << "callProgramAndCommit failed! ret=" << ret << endl;
        return;
    }

    printJZRecordData(recordData);
}

void testLogin()
{
    if (initKCBPCLI() != 0)
    {
        return;
    }

    g_params.acc.accountId = g_params.accountId;

	unsigned char pDestData[30] = {0x00};
	KDEncode(KDCOMPLEX_ENCODE, (unsigned char*)g_params.password.c_str(), g_params.password.length(),
                pDestData, sizeof(pDestData), (void*)"410301", 6);
	cout << "encode after(login):" << pDestData << endl;
    g_params.acc.trdpwd = (char*)pDestData;

    cout << "accountId=" << g_params.acc.accountId << "|pwd=" << g_params.acc.trdpwd << endl;

    int ret = setCommonArgs(g_params.acc, "410301");
    if (ret != 0)
    {
        cout << "setCommonArgs failed! ret=" << ret << endl;
        return;
    }

    // 设置具体业务参数
	KCBPCLI_SetValue_wrapper(g_params.hHandle, "inputtype", "Z");
	KCBPCLI_SetValue_wrapper(g_params.hHandle, "inputid", g_params.accountId);

    //调用服务端程序
    JZRecordData recordData;
    ret = callProgramAndCommit("410301", recordData);
    if (ret != 0)
    {
        cout << "callProgramAndCommit failed! ret=" << ret << endl;
        return;
    }

    if (!recordData.paramOut.empty())
    {
        g_params.acc.accountId = g_params.accountId;
        g_params.acc.custid = recordData.paramOut[0]["custid"];
        g_params.acc.custorgid = recordData.paramOut[0]["orgid"];
        g_params.acc.trdpwd = KDEncode_wrapper(g_params.password, recordData.paramOut[0]["custid"]);
        g_params.acc.netaddr = "127.0.0.1";
        g_params.acc.orgid = recordData.paramOut[0]["orgid"];
        g_params.acc.custcert = recordData.paramOut[0]["custcert"];
        for (auto & item : recordData.paramOut)
        {
            if (item["market"] == "0")
            {
                g_params.acc.secuid_sza = item["secuid"];
            }
            else if (item["market"] == "1")
            {
                g_params.acc.secuid_sha = item["secuid"];
            }
        }
    }

    printJZRecordData(recordData);
}

void testEnterOrder()
{
    // if (initKCBPCLI() != 0)
    // {
    //     return;
    // }
    testLogin();

    cout << "testEnterOrder ---------------------------------" << endl;

    int ret = setCommonArgs(g_params.acc, "410411");
    if (ret != 0)
    {
        cout << "setCommonArgs failed! ret=" << ret << endl;
        return;
    }

    // 设置具体业务参数
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "market", "0"); //交易市场
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "secuid", g_params.acc.secuid_sza); //股东代码
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "fundid", g_params.acc.accountId); //资金账户
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "stkcode", "000001"); //证券代码
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "bsflag", "0b"); //买卖类别
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "price", "10"); //价格
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "qty", "1000"); //数量
    // KCBPCLI_SetValue_wrapper(g_params.hHandle, "ordergroup", ""); //委托批号
    // KCBPCLI_SetValue_wrapper(g_params.hHandle, "bankcode", ""); //外部银行
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "creditid", "0"); //信用产品标识
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "creditflag", "6"); //特殊委托类型
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "remark", ""); //备注信息
    // KCBPCLI_SetValue_wrapper(g_params.hHandle, "targetseat", ""); //对方席位
    // KCBPCLI_SetValue_wrapper(g_params.hHandle, "promiseno", ""); //约定号

    // 调用服务端程序
    JZRecordData recordData;
    ret = callProgramAndCommit("410411", recordData);
    if (ret != 0)
    {
        cout << "callProgramAndCommit failed! ret=" << ret << endl;
        return;
    }

    printJZRecordData(recordData);
}

void testCancelOrder()
{
    // if (initKCBPCLI() != 0)
    // {
    //     return;
    // }
    testLogin();

    int ret = setCommonArgs(g_params.acc, "410413");
    if (ret != 0)
    {
        cout << "setCommonArgs failed! ret=" << ret << endl;
        return;
    }

    // 设置具体业务参数
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "orderdate", ""); //委托日期
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "fundid", g_params.acc.accountId); //资金帐户
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "ordersno", g_params.entrustId); //委托序号
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "bsflag", ""); //买卖类别

    //调用服务端程序
    JZRecordData recordData;
    ret = callProgramAndCommit("410413", recordData);
    if (ret != 0)
    {
        cout << "callProgramAndCommit failed! ret=" << ret << endl;
        return;
    }

    printJZRecordData(recordData);
}

void testQueryDealInfo()
{
    // if (initKCBPCLI() != 0)
    // {
    //     return;
    // }
    testLogin();

    int ret = setCommonArgs(g_params.acc, "410512");
    if (ret != 0)
    {
        cout << "setCommonArgs failed! ret=" << ret << endl;
        return;
    }

    // 设置具体业务参数
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "fundid", g_params.acc.accountId); //资金帐户
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "market", ""); //交易市场
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "secuid", ""); //股东代码
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "stkcode", ""); //证券代码
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "ordersno", ""); //委托序号
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "bankcode", ""); //外部银行
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "qryflag", "1"); //查询方向
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "count", "100"); //请求行数
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "poststr", ""); //定位串
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "qryoperway", ""); //委托渠道

    //调用服务端程序
    JZRecordData recordData;
    ret = callProgramAndCommit("410512", recordData);
    if (ret != 0)
    {
        cout << "callProgramAndCommit failed! ret=" << ret << endl;
        return;
    }

    printJZRecordData(recordData);
}

void testZJHK()
{
    // if (initKCBPCLI() != 0)
    // {
    //     return;
    // }
    testLogin();

    int ret = setCommonArgs(g_params.acc, "471013");
    if (ret != 0)
    {
        cout << "setCommonArgs failed! ret=" << ret << endl;
        return;
    }

    // 设置具体业务参数
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "fundid", g_params.acc.accountId); //资金帐户
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "moneytype", "2"); //货币代码
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "fundeffect", "1000"); //还款金额
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "remark", ""); //备注信息

    //调用服务端程序
    JZRecordData recordData;
    ret = callProgramAndCommit("471013", recordData);
    if (ret != 0)
    {
        cout << "callProgramAndCommit failed! ret=" << ret << endl;
        return;
    }

    printJZRecordData(recordData);
}

void test1()
{
    if (initKCBPCLI() != 0)
    {
        return;
    }
    testLogin();

    cout << "---------------------------------------" << endl;
    cout << "---------------------------------------" << endl;
    int ret = setCommonArgs(g_params.acc, "471143");
    if (ret != 0)
    {
        cout << "setCommonArgs failed! ret=" << ret << endl;
        return;
    }

    // 设置具体业务参数
    KCBPCLI_SetValue_wrapper(g_params.hHandle, "fundid", g_params.acc.accountId); //资金帐户

    // 调用服务端程序
    JZRecordData recordData;
    ret = callProgramAndCommit("471143", recordData);
    if (ret != 0)
    {
        cout << "callProgramAndCommit failed! ret=" << ret << endl;
        return;
    }

    printJZRecordData(recordData);
}


void testEncode()
{
    cout << "accountid=" << g_params.accountId << "|password=" << g_params.password << endl;

	unsigned char pDestData[30] = {0x00};
	KDEncode(KDCOMPLEX_ENCODE, (unsigned char*)g_params.password.c_str(), g_params.password.length(),
                pDestData, sizeof(pDestData), (void*)"410301", 6);
	cout << "encode after(login):" << pDestData << endl;

	KDEncode(KDCOMPLEX_ENCODE, (unsigned char*)g_params.password.c_str(), g_params.password.length(),
                pDestData, sizeof(pDestData),
			    (void*)(g_params.accountId.c_str()), g_params.accountId.length());
	cout << "encode after(custid):" << pDestData << endl;
}

void testLoopHeartBeat()
{
    if (initKCBPCLI() != 0)
    {
        return;
    }

    int cnt = 100;
    ProgressTimer timer;
    for (int i = 0; i < 100; i++)
    {
        int ret = setCommonArgs(g_params.acc, "410232");
        if (ret != 0)
        {
            cout << "setCommonArgs failed! ret=" << ret << endl;
            return;
        }

        // 调用服务端程序
        JZRecordData recordData;
        ret = callProgramAndCommit("410232", recordData);
        if (ret != 0)
        {
            cout << "callProgramAndCommit failed! ret=" << ret << endl;
            return;
        }
        if (recordData.errCode != 0)
        {
            cout << "errcode=" << recordData.errCode << "|errmsg=" << recordData.errMsg << endl;
        }
    }
    cout << "loop done! elapse=" << timer.elapse() << "|ave=" << timer.elapse()/cnt << endl;
}

void testLoopEnterOrder()
{
    // if (initKCBPCLI() != 0)
    // {
    //     return;
    // }
    testLogin();

    int cnt = 100;
    ProgressTimer timer;
    for (int i = 0; i < 100; i++)
    {
        int ret = setCommonArgs(g_params.acc, "410411");
        if (ret != 0)
        {
            cout << "setCommonArgs failed! ret=" << ret << endl;
            return;
        }

        // 设置具体业务参数
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "market", "0"); //交易市场
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "secuid", g_params.acc.secuid_sza); //股东代码
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "fundid", g_params.acc.accountId); //资金账户
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "stkcode", "000001"); //证券代码
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "bsflag", "B"); //买卖类别
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "price", "14"); //价格
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "qty", "100"); //数量
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "ordergroup", ""); //委托批号
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "bankcode", ""); //外部银行
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "creditid", ""); //信用产品标识
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "creditflag", ""); //特殊委托类型
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "remark", ""); //备注信息
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "targetseat", ""); //对方席位
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "promiseno", ""); //约定号

        // 调用服务端程序
        JZRecordData recordData;
        ret = callProgramAndCommit("410411", recordData);
        if (ret != 0)
        {
            cout << "callProgramAndCommit failed! ret=" << ret << endl;
            return;
        }
        if (recordData.errCode != 0)
        {
            cout << "errcode=" << recordData.errCode << "|errmsg=" << recordData.errMsg << endl;
        }
    }
    cout << "loop done! elapse=" << timer.elapse() << "|ave=" << timer.elapse()/cnt << endl;
}

void testLoopCancelOrder()
{
    // if (initKCBPCLI() != 0)
    // {
    //     return;
    // }
    testLogin();

    int cnt = 100;
    ProgressTimer timer;
    for (int i = 0; i < 100; i++)
    {
        int ret = setCommonArgs(g_params.acc, "410413");
        if (ret != 0)
        {
            cout << "setCommonArgs failed! ret=" << ret << endl;
            return;
        }

        // 设置具体业务参数
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "orderdate", ""); //委托日期
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "fundid", g_params.acc.accountId); //资金帐户
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "ordersno", TC_Common::tostr(TC_Common::strto<int>(g_params.entrustId)+i)); //委托序号
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "bsflag", ""); //买卖类别

        // 调用服务端程序
        JZRecordData recordData;
        ret = callProgramAndCommit("410413", recordData);
        if (ret != 0)
        {
            cout << "callProgramAndCommit failed! ret=" << ret << endl;
            return;
        }
        if (recordData.errCode != 0)
        {
            cout << "errcode=" << recordData.errCode << "|errmsg=" << recordData.errMsg << endl;
        }
    }
    cout << "loop done! elapse=" << timer.elapse() << "|ave=" << timer.elapse()/cnt << endl;
}

void testLoopDealInfo()
{
    // if (initKCBPCLI() != 0)
    // {
    //     return;
    // }
    testLogin();

    int cnt = 100;
    ProgressTimer timer;
    for (int i = 0; i < 100; i++)
    {
        int ret = setCommonArgs(g_params.acc, "410512");
        if (ret != 0)
        {
            cout << "setCommonArgs failed! ret=" << ret << endl;
            return;
        }

        // 设置具体业务参数
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "fundid", g_params.acc.accountId); //资金帐户
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "market", ""); //交易市场
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "secuid", ""); //股东代码
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "stkcode", ""); //证券代码
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "ordersno", ""); //委托序号
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "bankcode", ""); //外部银行
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "qryflag", "1"); //查询方向
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "count", "100"); //请求行数
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "poststr", ""); //定位串
        KCBPCLI_SetValue_wrapper(g_params.hHandle, "qryoperway", ""); //委托渠道

        // 调用服务端程序
        JZRecordData recordData;
        ret = callProgramAndCommit("410512", recordData);
        if (ret != 0)
        {
            cout << "callProgramAndCommit failed! ret=" << ret << endl;
            return;
        }
        if (recordData.errCode != 0)
        {
            cout << "errcode=" << recordData.errCode << "|errmsg=" << recordData.errMsg << endl;
        }
    }
    cout << "loop done! elapse=" << timer.elapse() << "|ave=" << timer.elapse()/cnt << endl;
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
            cout << "./test --cmd=encode" << endl;
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
        else if (cmd == "encode")
        {
            testEncode();
        }
        else if (cmd == "zjhk")
        {
            testZJHK();
        }
        else if (cmd == "loop_heartbeat")
        {
            testLoopHeartBeat();
        }
        else if (cmd == "loop_enter_order")
        {
            testLoopEnterOrder();
        }
        else if (cmd == "loop_cancel_order")
        {
            testLoopCancelOrder();
        }
        else if (cmd == "loop_dealinfo")
        {
            testLoopDealInfo();
        }
        else
        {
            test1();
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
