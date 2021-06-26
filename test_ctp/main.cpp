#include <unistd.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "DataCollect.h"
#include "ThostFtdcTraderApi.h"


using namespace std;


class MyTraderSpi : public CThostFtdcTraderSpi
{
public:
    ///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
    virtual void OnFrontConnected()
    {
        printf("<OnFrontConnected>\n");
        printf("</OnFrontConnected>\n");
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
        printf("<OnFrontDisconnected>\n");
        printf("\tnReason [%d]\n",nReason);
        printf("</OnFrontDisconnected>\n");
    }

    virtual void OnHeartBeatWarning(int nTimeLapse)
    {
        printf("<OnHeartBeatWarning>\n");
        printf("\tnTimeLapse [%d]\n",nTimeLapse);
        printf("</OnHeartBeatWarning>\n");
    }

    ///客户端认证响应
    virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
    {
        printf("<OnRspAuthenticate>\n");
        if (pRspAuthenticateField)
        {
            printf("\tBrokerID [%s]\n",pRspAuthenticateField->BrokerID);
            printf("\tUserID [%s]\n",pRspAuthenticateField->UserID);
            printf("\tUserProductInfo [%s]\n",pRspAuthenticateField->UserProductInfo);
            printf("\tAppID [%s]\n",pRspAuthenticateField->AppID);
            printf("\tAppType [%c]\n",pRspAuthenticateField->AppType);
        }
        if (pRspInfo)
        {
            printf("\tErrorMsg [%s]\n",pRspInfo->ErrorMsg);
            printf("\tErrorID [%d]\n",pRspInfo->ErrorID);
        }
        printf("\tnRequestID [%d]\n",nRequestID);
        printf("\tbIsLast [%d]\n",bIsLast);
        printf("</OnRspAuthenticate>\n");
    }

    virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
    {
        printf("<OnRspUserLogin>\n");
        if (pRspUserLogin)
        {
            printf("\tTradingDay [%s]\n",pRspUserLogin->TradingDay);
            printf("\tLoginTime [%s]\n",pRspUserLogin->LoginTime);
            printf("\tBrokerID [%s]\n",pRspUserLogin->BrokerID);
            printf("\tUserID [%s]\n",pRspUserLogin->UserID);
            printf("\tSystemName [%s]\n",pRspUserLogin->SystemName);
            printf("\tMaxOrderRef [%s]\n",pRspUserLogin->MaxOrderRef);
            printf("\tSHFETime [%s]\n",pRspUserLogin->SHFETime);
            printf("\tDCETime [%s]\n",pRspUserLogin->DCETime);
            printf("\tCZCETime [%s]\n",pRspUserLogin->CZCETime);
            printf("\tFFEXTime [%s]\n",pRspUserLogin->FFEXTime);
            printf("\tINETime [%s]\n",pRspUserLogin->INETime);
            printf("\tFrontID [%d]\n",pRspUserLogin->FrontID);
            printf("\tSessionID [%d]\n",pRspUserLogin->SessionID);
        }
        if (pRspInfo)
        {
            printf("\tErrorMsg [%s]\n",pRspInfo->ErrorMsg);
            printf("\tErrorID [%d]\n",pRspInfo->ErrorID);
        }
        printf("\tnRequestID [%d]\n",nRequestID);
        printf("\tbIsLast [%d]\n",bIsLast);
        printf("</OnRspUserLogin>\n");
    };

    virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
    {
        printf("<OnRspUserLogout>\n");
        if (pUserLogout)
        {
            printf("\tBrokerID [%s]\n",pUserLogout->BrokerID);
            printf("\tUserID [%s]\n",pUserLogout->UserID);
        }
        if (pRspInfo)
        {
            printf("\tErrorMsg [%s]\n",pRspInfo->ErrorMsg);
            printf("\tErrorID [%d]\n",pRspInfo->ErrorID);
        }
        printf("\tnRequestID [%d]\n",nRequestID);
        printf("\tbIsLast [%d]\n",bIsLast);
        printf("</OnRspUserLogout>\n");
    }
};

int main()
{
    cout << "version: " << CThostFtdcTraderApi::GetApiVersion() << endl;

    CThostFtdcTraderApi *m_pApi = CThostFtdcTraderApi::CreateFtdcTraderApi("./");

    MyTraderSpi spi;
    m_pApi->RegisterSpi(&spi);

    int nRequestID = 23;

    if (1)
    {
        m_pApi->SubscribePrivateTopic(THOST_TERT_QUICK);
        m_pApi->SubscribePublicTopic(THOST_TERT_QUICK);
        m_pApi->RegisterFront((char*)("tcp://106.39.36.72:31205"));
        m_pApi->Init();
        sleep(1);
        cout << "after init ----------------------- " << endl;
    }

    if (1)
    {
        CThostFtdcReqAuthenticateField reqAuth = { 0 };
        strcpy(reqAuth.BrokerID, "1010");
        strcpy(reqAuth.UserID, "10000010");
        // strcpy(reqAuth.UserProductInfo, "");
        strcpy(reqAuth.AuthCode, "YHQHYHQHYHQHYHQH");
        strcpy(reqAuth.AppID, "cgs_gmatrix_2.0.0");
		// strcpy(reqAuth.AppID, "cgs_gmxapama_2.0.0");
        int ret = m_pApi->ReqAuthenticate(&reqAuth, nRequestID++);
        printf("\t客户端认证 = [%d]\n", ret);
        sleep(1);
        cout << "after ReqAuthenticate ----------------------- " << endl;
    }

    if (0)
    {
        char pSystemInfo[344]={0};
        int len = 0;
        CTP_GetSystemInfo(pSystemInfo, len);

        cout << "pSystemInfo len=" << len << endl;

		CThostFtdcUserSystemInfoField a = { 0 };
		strcpy(a.BrokerID, "1010");
		strcpy(a.UserID, "10000010");
		memcpy(a.ClientSystemInfo, pSystemInfo, len);
		a.ClientSystemInfoLen = len;

		strcpy(a.ClientPublicIP, "127.0.0.1");//ip地址
		a.ClientIPPort = 12345;//端口号

		strcpy(a.ClientLoginTime, "10:12:23");
		strcpy(a.ClientAppID, "cgs_gmatrix_2.0.0");
		int b = m_pApi->RegisterUserSystemInfo(&a);
		printf((b == 0) ? "注册用户终端信息......发送成功\n" : "注册用户终端信息......发送失败，错误序号=[%d]\n", b);
        sleep(1);
        cout << "after RegisterUserSystemInfo ----------------------- " << endl;
    }

    if (1)
    {
		CThostFtdcReqUserLoginField reqUserLogin = { 0 };
		strcpy(reqUserLogin.BrokerID, "1010");
		strcpy(reqUserLogin.UserID, "10000010");
		strcpy(reqUserLogin.Password, "abc@123456");
		//strcpy_s(reqUserLogin.ClientIPAddress, "::c0a8:0101");
		//strcpy_s(reqUserLogin.UserProductInfo, "123");
		// 发出登陆请求
		int ret = m_pApi->ReqUserLogin(&reqUserLogin, nRequestID++);
        sleep(1);
        cout << "after ReqUserLogin ----------------------- " << endl;
        cout << "tradedate: " << m_pApi->GetTradingDay() << endl;
    }

    getchar();

    return 0;
}

