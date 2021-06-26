#if !defined(__MA_CLI_STK_MKT_DATA_H__)
#define __MA_CLI_STK_MKT_DATA_H__


#include "maCliApi.h"
#include "maCliMktDataStruct.h"
#include <map>
#include "maCliTradeApi.h"
#include "maMktData.h"
BGN_NAMESPACE_MACLI

class MACLIAPI CCliMktDataSpi
{
public:
  // �ͻ�����������ɹ�����ͨ�����Ӻ󣬸÷���������
  virtual int OnConnected(void) {return 0;}

  // �ͻ�����������ɹ���ͨ�����ӶϿ�ʱ���÷���������
  virtual int OnDisconnected(int p_nReason, const char *p_pszErrInfo) {return 0;}
  // �ֻ��û���¼������Ӧ
  virtual int OnRspStkUserLogin(CFirstSetField *p_pFirstSetField, CRspStkUserLoginField *p_pRsqField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  // ��Ȩ�û���¼������Ӧ
  virtual int OnRspOptUserLogin(CFirstSetField *p_pFirstSetField, CRspOptUserLoginField *p_pRspUserLoginField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �ڻ��û���¼������Ӧ
   virtual int OnRspFutureUserLogin(CFirstSetField *p_pFirstSetField, CRspFutureUserLoginField *p_pRspUserLoginField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  // �������������Ӧ
  virtual int OnRspHeartBeat(CFirstSetField *p_pFirstSetField, CRspHeartBeatField *p_pRsqField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //����ط�������Ӧ
  virtual int OnRspPlayBack(CFirstSetField *p_pFirstSetField, CRspPlayBackField *p_pRsqField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  //��Ȩ���ֻ����ڻ�������Ӧ
  virtual int OnRtnMktData(ST_MKT_DATA2* p_pMktData){return 0;}

  //������Ӧ
  virtual int OnRtnSubMktData(CRspSubMktDataField* p_pRspSubField){return 0;}

  //ȡ��������Ӧ
  virtual int OnRtnUnsubMktData(CRspUnsubMktDataField* p_pRspUnsubField){return 0;}

  //��ѡ�ɱ༭
  virtual int OnRspPortfolio(CFirstSetField *p_pFirstSet, CRspMktDataPortfolioField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  //��ѡ�ɲ�ѯ
  virtual int OnRspQryPortfolioInfo(CFirstSetField *p_pFirstSet, CRspMktDataPortfolioInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

//   //������ѯ
//   virtual int OnRspQryCodeTable(CFirstSetField *p_pFirstSet, CRspMktDataCodeTableField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
//   //������Ϣ��ѯ
//   virtual int OnRspQryCodeInfo(CFirstSetField *p_pFirstSet, CRspMktDataCodeInfoField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
//
  //k������
  virtual int OnRspQryKData(CFirstSetField *p_pFirstSet, CRspMktDataKDataField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}

  //tick����
  virtual int OnRspQryTickSnapshot(CFirstSetField *p_pFirstSet, CRspMktDataTickSnapshotField *p_pRspField, LONGLONG  p_llRequestId, int p_iFieldNum, int p_iFieldIndex) {return 0;}
  //�ɽ�����������Ӧ
  virtual int OnRtnMktMatch(ST_MKT_MATCH* p_pMktMatch){return 0;}
  //ί������������Ӧ
  virtual int OnRtnMktOrder(ST_MKT_ORDER* p_pMktOrder){return 0;}
  //ָ������������Ӧ
  virtual int OnRtnMktIndex(ST_MKT_INDEX* p_pMktIndex){return 0;}
};

class MACLIAPI CCliMktDataApi
{
public:
  // Ĭ�Ϲ��캯��
  CCliMktDataApi(void);

  // ��������
  virtual ~CCliMktDataApi(void);

  // ��ʼ��
  virtual int Init(void);

  // �˳�
  virtual int Exit(void);

  // ע��������ӵ�ַ
  virtual int RegisterServer(const char *p_pszIp, int p_iPort);

  //ע��ص��ӿ�
  virtual int RegisterSpi(CCliMktDataSpi *p_pSpi);

  // ע���˺���Ϣ
  virtual int RegisterAcct(char p_chChannel, const char *p_pszSession);



  // �û��ֻ���¼����
  virtual int ReqStkUserLogin(CReqStkUserLoginField *p_pReqField, LONGLONG p_llRequestId);

  // �û���Ȩ��¼����
  virtual int ReqOptUserLogin(CReqOptUserLoginField *p_pReqField, LONGLONG p_llRequestId);

  // �û��ڻ���¼����
  virtual int ReqFutureUserLogin(CReqFutureUserLoginField *p_pReqField, LONGLONG p_llRequestId);

  // �����������
  virtual int ReqHeartBeat(CReqHeartBeatField *p_pReqField, LONGLONG p_llRequestId);


  //����ط�����
  virtual int ReqPlayBack(CReqPlayBackField * p_pPlayBack,LONGLONG p_llRequestID);

  //���鴦���������
  //virtual int ReqSnapshot(CReqSnapshot * p_pSnapshot,LONGLONG p_llRequestId);

  //��ѡ�ɱ༭
  virtual int ReqPortfolio(CReqMktDataPortfolioField *p_pReqField, LONGLONG p_llRequestId);

  //��ѡ�ɲ�ѯ
  virtual int ReqQryPortfolioInfo(CReqMktDataPortfolioInfoField *p_pReqField, LONGLONG p_llRequestId);

//   //������ѯ
//   virtual int ReqQryCodeTable(CReqMktDataCodeTableField *p_pReqField, LONGLONG p_llRequestId);
//
//   //������Ϣ��ѯ
//   virtual int ReqQryCodeInfo(CReqMktDataCodeInfoField *p_pReqField, LONGLONG p_llRequestId);
//

  //k������
  virtual int ReqQryKData(CReqMktDataKDataField *p_pReqField, LONGLONG p_llRequestId);


  //tick����
  virtual int ReqQryTickSnapshot(CReqMktDataTickSnapshotField *p_pReqField, LONGLONG p_llRequestId);

  // ��ȡ��������Ϣ
  virtual const char* GetLastErrorText(void);




public:
  // �첽�ص�����
  void OnArCallback(const char *p_pszMsgId, const unsigned char *p_pszDataBuff, int p_iDataLen);

  // �����ص�����
  void OnPsCallback(const char *p_pszAcceptSn, const unsigned char *p_pszDataBuff, int p_iDataLen);

  // ��������
  int SubMktData(CReqSubMktDataField* p_pReqSubField);

  // �˶�����
  int UnsubMktData(CReqUnsubMktDataField* p_pReqUnsubField);


private:
  // ����ҵ���ͷ��Ϣ
  int SetBizPackHead(const char *p_pszFuncId, LONGLONG p_llRequestId, char *p_pszMsgId, char p_chPkgType);

  // ����������Ӧ
  void OnRspSubMktData(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);

  // �˶�������Ӧ
  void OnRspUnsubMktData(CFirstSetField *p_pFirstSetField, LONGLONG p_llRequestId, int p_iFieldNum);


  // �û��ֻ���¼������Ӧ
  void OnRspStkUserLogin(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);

  // �û���Ȩ��¼������Ӧ
  void OnRspOptUserLogin(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);

  // �û��ڻ���¼������Ӧ
  void OnRspFutureUserLogin(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);


  // �������������Ӧ
  void OnRspHeartBeat(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);

  //����ط�������Ӧ
  void OnRspPlayBack(CFirstSetField *p_pFirstSetField, LONGLONG  p_llRequestId, int p_iFieldNum);

  //��ѡ�ɱ༭
  void OnRspPortfolio(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);

  //��ѡ�ɲ�ѯ
  void OnRspQryPortfolioInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);


//   ������ѯ
//     void OnRspQryCodeTable(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
//
//     //������Ϣ��ѯ
//     void OnRspQryCodeInfo(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);
//
  //k������
  void OnRspQryKData(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);

  //tick����
  void OnRspQryTickSnapshot(CFirstSetField *p_pFirstSet, LONGLONG p_llRequestId, int p_iFieldNum);

private:
  MACLIHANDLE               m_hAsynCall;        // ϵͳ���þ��
  MACLIHANDLE               m_hAnsParse;        // Ӧ�������
  MACLIHANDLE               m_hPubParse;        // ���ͽ�����
  ST_MACLI_CONNECT_OPTION   m_stConnectOption;  // �������Ӳ���

  CReqFixField        m_stReqFixField;    // ����̶�����
  CCliMktDataSpi       *m_pMktDataSpi;      // �ص�ʵ��ָ��

private:
  bool            m_bIsLogin;
  char            m_szLastErrorText[1024+1]; // ��������Ϣ
};

END_NAMESPACE_MACLI

#endif  //__MA_CLI_STK_MKT_DATA_H__