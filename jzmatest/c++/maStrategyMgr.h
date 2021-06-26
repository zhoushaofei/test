//----------------------------------------------------------------------------
// ��Ȩ������������ģ�����ڽ�֤΢�ں˼ܹ�ƽ̨(KMAP)��һ����
//           ��֤�Ƽ��ɷ����޹�˾  ��Ȩ����
//
// �ļ����ƣ�maStrategyMgr.h
// ģ�����ƣ�΢�ܹ�C++���Բ������еĹ���ӿ�
// ģ��������
// �������ߣ������
// �������ڣ�2017-04-13
// ģ��汾��001.000.000
//----------------------------------------------------------------------------
// �޸�����      �汾          ����            ��ע
//----------------------------------------------------------------------------
// 2017-04-13    001.000.000   �����          ԭ��
//----------------------------------------------------------------------------
#if !defined(__MA_STRATEGY_MGR_H__)
#define __MA_STRATEGY_MGR_H__
#include "maStrategyApi.h"

// ����dll/so��������ԭ��
//int MATRADEAPI CreateStrategyMgr(void **p_ppclMgr, void *p_pclSpi);
//int MATRADEAPI ReleaseStrategyMgr(void *p_pclMgr);

BGN_NAMESPACE_MACLI

class IStrategyMgrSpi
{
public:
  virtual int OnRequest(unsigned char *p_pszData, int p_nDataLen, LONGLONG p_llRequestID, const char *p_pszFuncId) = 0;
  virtual int OnMessage(int p_iDate, int p_iTime, unsigned int p_iPid, unsigned int p_iTid, int p_iMsgCode, int p_iMsgLevel, const char *p_pszMsgText) = 0;
};

class IStrategyMgrApi
{
public:
  // ����Formatʵ��
  virtual IStrategyFmt* CreateFormat(void) = 0;

  // ����Formatʵ��
  virtual void ReleaseFormat(IStrategyFmt *p_pclFmt) = 0;

public:
  // ��ʼ���뷴��ʼ��
  virtual int Initialize(void) = 0;
  virtual int Uninitialize(void) = 0;

  // ����ģ��
  virtual const char* GetStgyModule(void) = 0;
  virtual int SetStgModule(const char* p_pszModule) = 0;
  virtual bool CheckModlue(void) = 0;

  // ��������
  virtual unsigned int GetQueMaxSize(void) = 0;
  virtual int SetQueMaxSize(unsigned int p_uiQueMaxSize) = 0;
  virtual unsigned int GetReqQueDepth(void) = 0;
  virtual unsigned int GetRepQueDepth(void) = 0;
  virtual unsigned int GetNtfQueDepth(void) = 0;

  // ��������
  virtual bool IsStgyRunning(void) = 0;
  virtual unsigned int GetStgyPid(void) = 0;
  virtual int StgyStartup(bool p_bDebug = false) = 0;
  virtual int StgyShutdown(void) = 0;

  // Ӧ��֪ͨ
  virtual int Response(unsigned char *p_pszRspData, int p_iDataLen, LONGLONG  p_llRequestId, const char *p_pszFuncId) = 0;
  virtual int Notify(unsigned char *p_pszNtfData, int p_iDataLen, const char *p_pszTopic) = 0;

  // ������Ϣ
  virtual const char* GetLastErrorText(void) = 0;
};

END_NAMESPACE_MACLI

#endif  // __MA_STRATEGY_MGR_H__
