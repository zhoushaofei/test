#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "util/tc_common.h"
#include "util/tc_option.h"
#include "util/tc_encoder.h"
#include "event/EventManager.h"
#include "event/TimeUtil.h"

#include "json/json.h"

#include "KCBPCli.h"
#include "kdencode.h"

using namespace taf;

//金证服务端的返回结果
struct JZRecordData
{
    int errCode = 0;
    string errMsg;
    vector<map<string, string>> paramOut;
};

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

static string KCBPCLI_GetValue_wrapper(KCBPCLIHANDLE hHandle, const string& KeyName)
{
    char value[1024] = {0};
    KCBPCLI_GetValue(hHandle, (char*)KeyName.c_str(), value, sizeof(value)-1);
    return string(value);
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
            cout << item2.first << "=[" << item2.second << "]" << endl;
        }
    }
    LOG_CONSOLE_DEBUG << "-----------------------" << endl;
    LOG_CONSOLE_DEBUG << "errCode=" << recordData.errCode << endl;
    LOG_CONSOLE_DEBUG << "errMsg=" << recordData.errMsg << endl;
    LOG_CONSOLE_DEBUG << "record size=" << recordData.paramOut.size() << endl;
}

KCBPCLIHANDLE initKCBPCLI(const string& ip, int port, const string& sendQName, const string& recvQName)
{
    KCBPCLIHANDLE handle = nullptr;

    int ret = KCBPCLI_Init(&handle);
    if (ret != 0 || !handle)
    {
        cout << "KCBPCLI_Init failed! ret=" << ret << endl;
        return nullptr;
    }

    tagKCBPConnectOption stKCBPConnection;
    memset(&stKCBPConnection, 0, sizeof(stKCBPConnection));

    strcpy(stKCBPConnection.szServerName, "KCXP00");
    stKCBPConnection.nProtocal = 0;
    strcpy(stKCBPConnection.szAddress, ip.c_str());
    stKCBPConnection.nPort = port;
    strcpy(stKCBPConnection.szSendQName, sendQName.c_str());
    strcpy(stKCBPConnection.szReceiveQName, recvQName.c_str());

    cout << "-------------------------------------" << endl;
    cout << stKCBPConnection.szAddress << ":" << stKCBPConnection.nPort << endl;
    cout << "-------------------------------------" << endl;

    // 设置连接选项
    ret = KCBPCLI_SetOptions(handle, KCBP_OPTION_CONNECT ,&stKCBPConnection, sizeof(stKCBPConnection));
    if (ret != 0)
    {
        cout << "KCBPCLI_SetOptions failed! ret=" << ret << endl;
        return nullptr;
    }

    // 设置超时选项
    int timeout = 60;
    ret = KCBPCLI_SetOptions(handle, KCBP_OPTION_TIMEOUT, &timeout, sizeof(timeout));
    if (ret != 0)
    {
        cout << "KCBPCLI_SetOptions failed! ret=" << ret << endl;
        return nullptr;
    }

    // 设置报文跟踪日志目录
    string logpath = "./kcbplog";
    ret = KCBPCLI_SetOptions(handle, KCBP_OPTION_TRACE_DIR, (void*)logpath.c_str(), logpath.length()+1);
    if (ret != 0)
    {
        cout << "KCBPCLI_SetOptions failed! ret=" << ret << endl;
        return nullptr;
    }

    // 设置通讯数据包跟踪日志设置
    int nValue = 1;
    ret = KCBPCLI_SetOptions(handle, KCBP_OPTION_TRACE, &nValue, sizeof(nValue));
    if (ret != 0)
    {
        cout << "KCBPCLI_SetOptions failed! ret=" << ret << endl;
        return nullptr;
    }

    // 连接服务器
    ret = KCBPCLI_ConnectServer_wrapper(handle, "KCXP00", "KCXP00", "888888");
    if (ret != 0)
    {
        string msg = KCBPCLI_GetErrorMsg_wrapper(handle);
        cout << "KCBPCLI_ConnectServer failed! ret=" << ret << "|msg=" << msg << endl;
        return nullptr;
    }

    cout << "KCBPCLI_ConnectServer OK!" << endl;
    return handle;
}

int fetchRowData(KCBPCLIHANDLE handle, JZRecordData& recordData)
{
    char sColName[128] = {0};
    char sColValue[128] = {0};

    int ret = KCBPCLI_RsOpen(handle);
    if (ret != 0)
    {
        cout << "KCBPCLI_RsOpen failed! ret=" <<  ret << endl;
        return ret;
    }

    ret = KCBPCLI_RsFetchRow(handle);
    if (ret != 0)
    {
        cout << "KCBPCLI_RsFetchRow failed! ret=" <<  ret << endl;
        KCBPCLI_RsClose(handle);
        return ret;
    }

    memset(sColValue, 0, sizeof(sColValue));
    ret = KCBPCLI_RsGetColByName(handle, (char*)"CODE", sColValue);
    if (ret != 0)
    {
        cout << "KCBPCLI_RsGetColByName failed! ret=" <<  ret << "|col=" << "CODE" << endl;
        KCBPCLI_RsClose(handle);
        return ret;
    }
    recordData.errCode = TC_Common::strto<int>(sColValue);

    memset(sColValue, 0, sizeof(sColValue));
    ret = KCBPCLI_RsGetColByName(handle, (char*)"MSG", sColValue);
    if (ret != 0)
    {
        cout << "KCBPCLI_RsGetColByName failed! ret=" <<  ret << "|col=" << "MSG" << endl;
        KCBPCLI_RsClose(handle);
        return ret;
    }
    recordData.errMsg = TC_Encoder::gbk2utf8(sColValue);

    if (KCBPCLI_RsMore(handle) == 0)
    {
        while (KCBPCLI_RsFetchRow(handle) == 0)
        {
            int nCol = 0;
            KCBPCLI_RsGetColNum(handle, &nCol);
            map<string, string> mapRecord;
            for (int i = 1; i <= nCol; i++)
            {
                ret = KCBPCLI_RsGetColName(handle, i, sColName, sizeof(sColName));
                if (ret != 0)
                {
                    cout << "KCBPCLI_RsGetColName failed! ret=" <<  ret << "|col=" << i << endl;
                }

                ret = KCBPCLI_RsGetColByName(handle, sColName, sColValue);
                if (ret != 0)
                {
                    cout << "KCBPCLI_RsGetVal failed! ret=" <<  ret << "|col=" << i << endl;
                }

                mapRecord[sColName] = TC_Encoder::gbk2utf8(sColValue);
            }
            recordData.paramOut.push_back(mapRecord);
        }
    }

    KCBPCLI_RsClose(handle);
    return ret;
}

// enterOrder|_CA=2.3&_ENDIAN=0&funcid=410512&custid=20500000001&custorgid=0205&trdpwd=SkA6wznCZB+6cXSZXLs2RA@3D@3D&netaddr=PC;IIP@3D106.120.201.106;IPORT@3D43040;LIP@3D192.168.217.1;MAC@3D98EECBAA91D0;HD@3D0025_3889_91BB_1B42.;PCN@3DWindows 10.0.18362.476;CPU@3DBFEBFBFF000906EA;PI@3DC^238.251G,D^466G,E^465.508G;VOL@3DC,C5DBAB98@40gmatrixtc_0.0.4_37DD&orgid=0205&operway=9&ext=0&custcert=&ticket=&fundid=020500000001&market=&secuid=&stkcode=&ordersno=&bankcode=&qryflag=1&count=1000&poststr=&qryoperway=9
// enterOrder|_CA=2.4&_SYSID=9001&_ENDIAN=0&_RS_1=MESSAGE;3;LEVEL,CODE,MSG;1&_1=0,0,▒▒▒ճɽ▒▒▒ѯ▒ɹ▒&_EORS_1=1&_RS_2=DATA;26;poststr,trddate,matchcode,fundid,fortuneid,orgid,secuid,bsflag,orderid,ordersno,market,stkcode,stkname,matchtime,matchprice,matchqty,matchamt,matchtype,orderqty,orderprice,bondintr,matchsno,serverid,prodcode,stktype,prodname;2&_2=20210219|2,20210219,,20500000001,0,0205,0158209985,B,B4000001,3,0,000001,ƽ▒▒▒▒▒▒,105844,.000,200,.00,2,200,10.000,.00000000,2,1,,0,&_3=20210219|3,20210219,,20500000001,0,0205,0158209985,B,B4000002,4,0,000001,ƽ▒▒▒▒▒▒,110100,.000,200,.00,2,200,10.000,.00000000,3,1,,0,&_EORS_2=3&_RC=3&_CC=26&_TL=3:1;26:2;
//  [bondintr]=[.00000000]  [bsflag]=[B]  [fortuneid]=[0]  [fundid]=[20500000001]  [market]=[0]  [matchamt]=[.00]  [matchcode]=[20210219]  [matchprice]=[.000]  [matchqty]=[200]  [matchsno]=[2]  [matchtime]=[105844]  [matchtype]=[2]  [orderid]=[B4000001]  [orderprice]=[10.000]  [orderqty]=[200]  [ordersno]=[3]  [orgid]=[0205]  [poststr]=[20210219|2]  [prodcode]=[1]  [prodname]=[0]  [secuid]=[0158209985]  [serverid]=[1]  [stkcode]=[000001]  [stkname]=[ƽ▒▒▒▒▒▒]  [stktype]=[0]  [trddate]=[20210219]
//  [bondintr]=[.00000000]  [bsflag]=[B]  [fortuneid]=[0]  [fundid]=[20500000001]  [market]=[0]  [matchamt]=[.00]  [matchcode]=[20210219]  [matchprice]=[.000]  [matchqty]=[200]  [matchsno]=[3]  [matchtime]=[110100]  [matchtype]=[2]  [orderid]=[B4000002]  [orderprice]=[10.000]  [orderqty]=[200]  [ordersno]=[4]  [orgid]=[0205]  [poststr]=[20210219|3]  [prodcode]=[1]  [prodname]=[0]  [secuid]=[0158209985]  [serverid]=[1]  [stkcode]=[000001]  [stkname]=[ƽ▒▒▒▒▒▒]  [stktype]=[0]  [trddate]=[20210219]

// enterOrder|_CA=2.3&_ENDIAN=0&custid=20500000001&custorgid=0205&trdpwd=SkA6wznCZB+6cXSZXLs2RA@3D@3D&netaddr=127.0.0.1&orgid=0205&operway=9&ext=0&custcert=&ticket=&bankcode=&count=10&funcid=410512&fundid=&market=&ordersno=&poststr=&qryflag=1&qryoperway=&secuid=&stkcode=
// KCBPCLI_CallProgramAndCommit elapsed=15|funcId=410512
// enterOrder|_CA=2.4&_SYSID=9001&_ENDIAN=0&_RS_1=MESSAGE;3;LEVEL,CODE,MSG;1&_1=0,0,▒▒▒ճɽ▒▒▒ѯ▒ɹ▒&_EORS_1=1&_RS_2=DATA;26;poststr,trddate,matchcode,fundid,fortuneid,orgid,secuid,bsflag,orderid,ordersno,market,stkcode,stkname,matchtime,matchprice,matchqty,matchamt,matchtype,orderqty,orderprice,bondintr,matchsno,serverid,prodcode,stktype,prodname;2&_2=20210219|2,20210219,,20500000001,0,0205,0158209985,B,B4000001,3,0,000001,ƽ▒▒▒▒▒▒,105844,.000,200,.00,2,200,10.000,.00000000,2,1,,0,&_3=20210219|3,20210219,,20500000001,0,0205,0158209985,B,B4000002,4,0,000001,ƽ▒▒▒▒▒▒,110100,.000,200,.00,2,200,10.000,.00000000,3,1,,0,&_EORS_2=3&_RC=3&_CC=26&_TL=3:1;26:2;

int callProgramAndCommit(KCBPCLIHANDLE handle, const string& funcId, JZRecordData& recordData)
{
    ev::ProgressTimer timer;

    //打印关键接口日志
    cout << "callProgramAndCommit|" << KCBPCLI_GetValue_wrapper(handle, "") << endl;

    // 调用服务端程序
    int ret = KCBPCLI_CallProgramAndCommit_wrapper(handle, funcId);
    if (ret != 0)
    {
        string msg = KCBPCLI_GetErrorMsg_wrapper(handle);
        cout << "KCBPCLI_CallProgramAndCommit failed! ret=" << ret << "|msg=" << msg << endl;
        cout << "KCBPCLI_CallProgramAndCommit failed! elapsed=" << timer.elapse() << "|funcId=" << funcId << endl;
        return ret;
    }
    cout << "KCBPCLI_CallProgramAndCommit elapsed=" << timer.elapse() << "|funcId=" << funcId << endl;

    // //打印关键接口日志
    // cout << "callProgramAndCommit-rsp|" << KCBPCLI_GetValue_wrapper(handle, "") << endl;

    // 获取服务端返回的结果集
    ret = fetchRowData(handle, recordData);
    if (ret != 0)
    {
        cout << "getRecordData failed! ret=" << ret << endl;
        return ret;
    }

    cout << "fetchRowData elapsed=" << timer.elapse() << endl;
    return 0;
}

void login(KCBPCLIHANDLE handle, Json::Value& root, std::map<string, string>& logininfo)
{
    string fundid = root["fundid"].asString();
    string password = root["password"].asString();
    string operway = root["operway"].asString();

    string trdpwd = KDEncode_wrapper(password, "410301");

    KCBPCLI_BeginWrite(handle);

    // 设置系统固定入参
    KCBPCLI_SetValue_wrapper(handle, "funcid", "410301"); //功能号
    KCBPCLI_SetValue_wrapper(handle, "custid", ""); //客户代码
    KCBPCLI_SetValue_wrapper(handle, "custorgid", ""); //客户机构
    KCBPCLI_SetValue_wrapper(handle, "trdpwd", trdpwd); //交易密码
    KCBPCLI_SetValue_wrapper(handle, "netaddr", "127.0.0.1"); //操作站点
    KCBPCLI_SetValue_wrapper(handle, "orgid", ""); //操作机构
    KCBPCLI_SetValue_wrapper(handle, "operway", operway); //操作方式
    KCBPCLI_SetValue_wrapper(handle, "ext", "0"); //扩展
    KCBPCLI_SetValue_wrapper(handle, "custcert", ""); //客户证书
    // KCBPCLI_SetValue_wrapper(handle, "custcert", tradeAccount.custcert); //客户证书
    // KCBPCLI_SetValue_wrapper(handle, "netaddr2", ""); //站点扩位
    KCBPCLI_SetValue_wrapper(handle, "ticket", ""); //统一认证票据

    // 设置具体业务参数
    KCBPCLI_SetValue_wrapper(handle, "inputtype", "Z");
    KCBPCLI_SetValue_wrapper(handle, "inputid", fundid);

    //调用服务端程序
    JZRecordData recordData;
    int ret = callProgramAndCommit(handle, "410301", recordData);
    if (ret != 0)
    {
        cout << "callProgramAndCommit failed! ret=" << ret << endl;
        return;
    }

    if (!recordData.paramOut.empty())
    {
        logininfo["fundid"] = recordData.paramOut[0]["fundid"];
        logininfo["custid"] = recordData.paramOut[0]["custid"];
        logininfo["orgid"] = recordData.paramOut[0]["orgid"];
        logininfo["custcert"] = recordData.paramOut[0]["custcert"];
        for (auto & item : recordData.paramOut)
        {
            logininfo["secuid-" + item["market"]] = item["secuid"];
        }
    }

    printJZRecordData(recordData);

    cout << "=========================================" << endl;
}

void run(KCBPCLIHANDLE handle, Json::Value& root, const string& section, std::map<string, string>& logininfo)
{
    string funcid = root[section]["funcid"].asString();
    string fundid = root["fundid"].asString();
    string password = root["password"].asString();
    string operway = root["operway"].asString();

    string trdpwd = KDEncode_wrapper(password, logininfo["custid"]);

    KCBPCLI_BeginWrite(handle);

    // 设置系统固定入参
    KCBPCLI_SetValue_wrapper(handle, "funcid", funcid); //功能号
    KCBPCLI_SetValue_wrapper(handle, "custid", logininfo["custid"]); //客户代码
    KCBPCLI_SetValue_wrapper(handle, "custorgid", logininfo["orgid"]); //客户机构
    KCBPCLI_SetValue_wrapper(handle, "orgid", logininfo["orgid"]); //操作机构
    // KCBPCLI_SetValue_wrapper(handle, "custid", "35500000201"); //客户代码
    // KCBPCLI_SetValue_wrapper(handle, "custorgid", "0355"); //客户机构
    // KCBPCLI_SetValue_wrapper(handle, "orgid", ""); //操作机构
    KCBPCLI_SetValue_wrapper(handle, "trdpwd", trdpwd); //交易密码
    KCBPCLI_SetValue_wrapper(handle, "netaddr", "127.0.0.1"); //操作站点
    KCBPCLI_SetValue_wrapper(handle, "operway", operway); //操作方式
    KCBPCLI_SetValue_wrapper(handle, "ext", "0"); //扩展
    KCBPCLI_SetValue_wrapper(handle, "custcert", ""); //客户证书
    // KCBPCLI_SetValue_wrapper(handle, "custcert", tradeAccount.custcert); //客户证书
    // KCBPCLI_SetValue_wrapper(handle, "netaddr2", ""); //站点扩位
    KCBPCLI_SetValue_wrapper(handle, "ticket", ""); //统一认证票据

    // 设置具体业务参数
    Json::Value::Members mem = root[section].getMemberNames();
	for (auto item : mem)
	{
        if (item == "secuid" && root[section][item].asString() == "logininfo")
        {
            string secuid_key = "secuid-" + root[section]["market"].asString();
            KCBPCLI_SetValue_wrapper(handle, item, logininfo[secuid_key]);
        }
        else if (item == "fundid" && root[section][item].asString() == "fundid")
        {
            KCBPCLI_SetValue_wrapper(handle, item, logininfo["fundid"]);
        }
        else
        {
            KCBPCLI_SetValue_wrapper(handle, item, root[section][item].asString());
        }
    }

    //调用服务端程序
    JZRecordData recordData;
    int ret = callProgramAndCommit(handle, funcid, recordData);
    if (ret != 0)
    {
        cout << "callProgramAndCommit failed! ret=" << ret << endl;
        return;
    }

    printJZRecordData(recordData);

    cout << "=========================================" << endl;
}

void test()
{
    ifstream ifs("json.json");
    if(!ifs.is_open())
	{
		cout << "open failed!" << endl;
		return;
	}

    Json::Value root;
    Json::Reader reader;
    if (!reader.parse(ifs, root, false))
    {
		cout << "parse failed!" << endl;
        return;
    }


    string ip = root["ip"].asString();
    int port = TC_Common::strto<int>(root["port"].asString());
    string sendQName = root["sendQName"].asString();
    string recvQName = root["recvQName"].asString();


    KCBPCLIHANDLE handle = initKCBPCLI(ip, port, sendQName, recvQName);
    if (!handle)
    {
        cout << "initKCBPCLI failed" << endl;
        return;
    }

    //登录
    std::map<string, string> logininfo;

    //登录
    if (root["login"].asString() != "0")
    {
        login(handle, root, logininfo);
    }

    //具体业务功能
	for (auto item : root["run"])
    {
        cout << "============= run: " << item << " =================" << endl;
        run(handle, root, item.asString(), logininfo);
    }
}

int main(int argc, char *argv[])
{
    try
    {
        test();
    }
    catch (std::exception& e)
    {
        LOG_CONSOLE_DEBUG << "exception:" << e.what() << endl;
    }
    catch (...)
    {
        LOG_CONSOLE_DEBUG << "unknown exception." << endl;
    }

    return 0;
}
