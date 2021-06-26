//----------------------------------------------------------------------------
// ��Ȩ������������ģ�����ڽ�֤΢�ں˼ܹ�ƽ̨(KMAP)��һ����
//           ��֤�Ƽ��ɷ����޹�˾  ��Ȩ����
//
// �ļ����ƣ�maCliTradeApi.h
// ģ�����ƣ�ma΢�ܹ�C++����API�ӿڵ���CTP��װ�ӿ�
// ģ��������
// �������ߣ������
// �������ڣ�2015-06-25
// ģ��汾��001.000.000
//----------------------------------------------------------------------------
// �޸�����      �汾          ����            ��ע
//----------------------------------------------------------------------------
// 2015-06-25    001.000.000   �����          ԭ��
//----------------------------------------------------------------------------
#if !defined(__MA_CLI_TRADE_API_H__)
#define __MA_CLI_TRADE_API_H__

#include "maCliApi.h"

#if defined (_MSC_VER) && (_MSC_VER == 1200)
  #define FORMAT_LONGLONG "%I64d"
  #if defined(WIN32)
  typedef __int64 LONGLONG;
  #endif
#else
  #define FORMAT_LONGLONG "%lld"
  typedef long long LONGLONG;
#endif

#if defined(WIN32) || defined(WIN64) || defined(OS_IS_WINDOWS)
#if defined MA_TRADE_API_EXPORTS
#define MATRADEAPI __declspec(dllexport)
#else
#define MATRADEAPI __declspec(dllimport)
#endif
#elif defined(OS_IS_LINUX)
#define MATRADEAPI
#endif

#define BGN_NAMESPACE_MACLI   namespace macli {
#define END_NAMESPACE_MACLI   }
#define USE_NAMESPACE_MACLI   using namespace macli;  

BGN_NAMESPACE_MACLI

// ����̶�����
struct MATRADEAPI CReqFixField
{
	char          szOpUser[32 + 1];           // �����û�����
	char          chOpRole;                   // �����û���ɫ
	char          szOpSite[256 + 1];          // ����վ��
	char          chChannel;                  // ��������
	char          szSession[128 + 1];         // �Ựƾ֤
	char          szFunction[16 + 1];         // ���ܴ���
	char          szRuntime[32 + 1];          // ����ʱ�� YYYY-MM-DD HH24:MI:SS.nnnnnn
	int           iOpOrg;                     // ��������
};

// ��1���������
struct MATRADEAPI CFirstSetField
{
	int           iMsgCode;                   // ��Ϣ����
	char          chMsgLevel;                 // ��Ϣ����
	char          szMsgText[256 + 1];         // ��Ϣ����
	char          szMsgDebug[1024 + 1];       // ��̨������Ϣ
};

//-------------------------------00102012:��������------------------------------------
struct MATRADEAPI CReqSubTopicField
{
	char          szTopic[12 + 1];            // ����
	char          szFilter[512 + 1];          // ��������
	char          chDataSet;                  // �ɽ����ݼ� '0':���������ӷ���ί�еĳɽ���Ϣ '1':���������ӷ���ί�еĳɽ���Ϣ
};

struct MATRADEAPI CRspSubTopicField
{
	char          szTopic[12 + 1];            // ����
	char          szFilter[512 + 1];          // ��������
	LONGLONG      llAcceptSn;                 // ���������
	char          szChannel[64 + 1];          // ����ͨ��
	char          chDataSet;                  // �ɽ����ݼ� '0':���������ӷ���ί�еĳɽ���Ϣ '1':���������ӷ���ί�еĳɽ���Ϣ
};

//-------------------------------00102013:�˶�����------------------------------------
struct MATRADEAPI CReqUnsubTopicField
{
	char          szTopic[12 + 1];            // ����
	LONGLONG      llAcceptSn;                 // ���������
};

struct MATRADEAPI CRspUnsubTopicField
{
	char          szTopic[12 + 1];            // ����
	LONGLONG      llAcceptSn;                 // ���������
};

//-------------------------------00103003:�������------------------------------------
struct MATRADEAPI CReqHeartBeatField
{
	;
};

struct MATRADEAPI CRspHeartBeatField
{
	char          szServerLocalNodeId[32 + 1];  // ���ڵ���
	char          szServerNodeId[32 + 1];       // �ڵ���
	char          szServerNodeGid[32 + 1];      // �ڵ����
	char          szServerSiteName[32 + 1];     // ����վ����
	char          szServerNodeType[32 + 1];     // �ڵ�����
	char          szServerSiteIP[32 + 1];       // վ��IP
	char          szServerNodePwd[128 + 1];     // �ڵ�·��
	char          szServerNodeUse[4 + 1];       // �ڵ���; ��n��:�����ڵ� ��s��:�����ڵ� ��a��:���ýڵ�
	char          szServerBackIp[32 + 1];       // ����վ��IP
};

//-------------------------------00102020:�����Ϣ��������------------------------------------
struct MATRADEAPI CRtnTradeRiskInfoField
{
	char          chRiskCls;                    // �������
	char          szRiskId[2 + 1];              // ���ձ�ʶ
	char          chRiskIdLevel;                // ���ռ���
	char          szRiskName[256 + 1];          // ��������
	LONGLONG      llCustCode;                   // �ͻ�����
	LONGLONG      llCuacctCode;                 // �ʲ��˻�
	char          szStkbd[2 + 1];               // ���װ��
	char          szContent[2048 + 1];          // ֪ͨ����
};

class MATRADEAPI CCliTradeSpi
{
public:
  // �ͻ�����������ɹ�����ͨ�����Ӻ󣬸÷���������
  virtual int OnConnected(void) {return 0;}

  // �ͻ�����������ɹ���ͨ�����ӶϿ�ʱ���÷���������
  virtual int OnDisconnected(int p_nReason, const char *p_pszErrInfo) {return 0;}

  // �������������Ӧ
  virtual int OnRspHeartBeat(CFirstSetField *p_pFirstSetField, CRspHeartBeatField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  //������Ӧ
  virtual int OnRtnSubTopic(CRspSubTopicField* p_pRspField) {return 0;}

  //ȡ��������Ӧ
  virtual int OnRtnUnsubTopic(CRspUnsubTopicField* p_pRspField) {return 0;}

  // �����Ϣ
  virtual int OnRtnTradeRisk(CRtnTradeRiskInfoField* p_pRspField) {return 0;}

};

class MATRADEAPI CCliTradeApi
{
public:
  // Ĭ�Ϲ��캯��
  CCliTradeApi(void);

  // ��������
  virtual ~CCliTradeApi(void);

  // ��ʼ��
  virtual int Init(void);

  // �˳�
  virtual int Exit(void);

  // ע��������Ϣ
  virtual int RegisterServer(const char *p_pszIp, int p_iPort, unsigned int uiTimeout = 1, const char* p_pszPktVer = "01");

  ///ע��ص��ӿ�
  virtual int RegisterSpi(CCliTradeSpi *p_pSpi);

  // ע���˺���Ϣ
  virtual int RegisterAcct(char p_chChannel, const char* p_pszOpSite = 0, int p_iSiteLen = 0);

  // �����������
  virtual int ReqHeartBeat(CReqHeartBeatField *p_pReqField, LONGLONG p_llRequestId);

  // ����ҵ���ͷ��Ϣ
  int SetBizPackHead(const char *p_pszFuncId, LONGLONG p_llRequestId, char *p_pszMsgId, char p_chPkgType, char p_chPkgVer = '2');

  // ��������
  int SubTopic(const char *p_pszTopic, const char *p_pszFilter, char p_chDataSet = '0');

  // �˶�����
  int UnsubTopic(const char *p_pszTopic, LONGLONG llAcceptSn = 0);

  // ����������Ӧ
  void OnRspSubTopic(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �˶�������Ӧ
  void OnRspUnsubTopic(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �������������Ӧ
  void OnRspHeartBeat(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);

  // ��ȡ��������Ϣ
  const char* GetLastErrorText(void);
  
public:
  // �첽�ص�����
  virtual void OnArCallback(const char *p_pszMsgId, const unsigned char *p_pszDataBuff, int p_iDataLen);

  // �����ص�����
  virtual void OnPsCallback(const char *p_pszAcceptSn, const unsigned char *p_pszDataBuff, int p_iDataLen);

  // ���ӻص�����
  virtual void OnNetCallback(const char *p_pszNetState, const unsigned char *p_pszDataBuff, int p_iDataLen);

protected:
  int OnBeginCall(void);
  int OnEndCall(void);
  int OnDoCall(ST_MACLI_ASYNCALL& p_stAsynCall);
  int OnCheckPointer(void* p_pVar, const char* p_pszVar);
  int OnCheckCuacctCode(LONGLONG llCuacctCode);
  int OnCheckCustCode(LONGLONG llCustCode);

  void SetCustCode(LONGLONG llCustCode);
  LONGLONG GetCustCode(void);
  void AddCuacctCode(LONGLONG llCuacctCode);
  void ClearAcct(void);
  bool IsLogin(void);
  void SetLogin(bool p_bIsLogin = true);

protected:
  MACLIHANDLE               m_hAsynCall;                // ϵͳ���þ��
  MACLIHANDLE               m_hAnsParse;                // Ӧ�������
  MACLIHANDLE               m_hPubParse;                // ���ͽ�����
  ST_MACLI_CONNECT_OPTION   m_stConnectOption;          // �������Ӳ���
  unsigned int              m_uiTimeout;                // ��ʱʱ��(��)
  CReqFixField              m_stReqFixField;            // ����̶�����
  CCliTradeSpi             *m_pTradeSpi;                // �ص�ʵ��ָ��
  char                      m_szLastErrorText[1024+1];  // ��������Ϣ
  void                     *m_pMutexCall;               // ���������
  bool                      m_bSetOpSite;               // �Ƿ����ò���վ��
  void                     *m_pAcctInfo;                // ��¼�˻���Ϣ
  char                      m_szFuncId[8 + 1];          // ��ǰӦ����ID
  CFirstSetField            m_stFirstSetField;          // ��ǰӦ���һ�����
  LONGLONG                  m_llRequestId;              // ��ǰӦ������ID
  int                       m_iRsRowCnt;                // ��ǰӦ����������
  int                       m_iAnsState;                // ��ǰӦ����״̬
  char                      m_szBuffer[256 + 1];
  char                      m_szTemp[256 + 1];
  char                      m_szAuthData[256 + 1];
  int                       m_iSubsystem;
  char                      m_szPktVer[2 + 1];
};

END_NAMESPACE_MACLI

#endif  // __MA_CLI_TRADE_API_H__



	     