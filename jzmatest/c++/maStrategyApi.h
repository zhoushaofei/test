//----------------------------------------------------------------------------
// ��Ȩ������������ģ�����ڽ�֤΢�ں˼ܹ�ƽ̨(KMAP)��һ����
//           ��֤�Ƽ��ɷ����޹�˾  ��Ȩ����
//
// �ļ����ƣ�maStrategyApi.h
// ģ�����ƣ�΢�ܹ�C++���Բ������еĽӿ�
// ģ��������
// �������ߣ������
// �������ڣ�2017-04-13
// ģ��汾��001.000.000
//----------------------------------------------------------------------------
// �޸�����      �汾          ����            ��ע
//----------------------------------------------------------------------------
// 2017-04-13    001.000.000   �����          ԭ��
//----------------------------------------------------------------------------
#if !defined(__MA_STRATEGY_API_H__)
#define __MA_STRATEGY_API_H__

#if defined (_MSC_VER) && (_MSC_VER == 1200)
  #define FORMAT_LONGLONG "%I64d"
  #if defined(WIN32)
  typedef __int64 LONGLONG;
  typedef unsigned __int64 ULONGLONG;
  #endif
#else
  #define FORMAT_LONGLONG "%lld"
  typedef long long LONGLONG;
  typedef unsigned long long ULONGLONG;
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

// ����dll/so��������ԭ��
//int MATRADEAPI CreateStrategySpi(void **p_ppclSpi, void *p_pclApi);
//int MATRADEAPI ReleaseStrategySpi(void *p_pclSpi);

BGN_NAMESPACE_MACLI

// �����ӿ���
class MATRADEAPI IStrategyFmt
{
public:
  // ���
  virtual int BeginWrite(void) = 0;
  virtual int SetValue(const char *p_pszValue, int p_iValueLen, const char *p_pszField) = 0;
  virtual int EndWrite(void) = 0;
  virtual int Make(unsigned char **ppszData, int &p_refiDataLen) = 0;
  virtual int CreateTable(void) = 0;
  virtual int AddRow(void) = 0;
  virtual int SaveRow(void) = 0;

  // ���
  virtual int Parse(unsigned char *p_pszData, int p_iDataLen) = 0;
  virtual int GetTableCount(int &p_refiTableCount) = 0;
  virtual int OpenTable(int p_iTableIdx) = 0;
  virtual int GetRowCount(int &p_refiRowCount) = 0;
  virtual int ReadRow(int p_iRowIdx) = 0;
  virtual int GetValue(char *p_pszValue, int p_iValueSize, int &p_refiValueLen, const char *p_pszField) = 0;

  // ����
  virtual int GetValue(char *p_pszValue, int p_iValueSize, const char *p_pszField) = 0;
  virtual int SetValue(const char *p_pszValue, const char *p_pszField) = 0;

  virtual int GetValue(char &p_refchValue,  const char *p_pszField) = 0;
  virtual int SetValue(char p_chValue, const char *p_pszField) = 0;

  virtual int GetValue(short &p_refsValue,  const char *p_pszField) = 0;
  virtual int SetValue(short p_sValue, const char *p_pszField) = 0;

  virtual int GetValue(unsigned short &p_refusValue, const char *p_pszField) = 0;
  virtual int SetValue(unsigned short p_usValue, const char *p_pszField) = 0;

  virtual int GetValue(int &p_refiValue, const char *p_pszField) = 0;
  virtual int SetValue(int p_iValue, const char *p_pszField) = 0;

  virtual int GetValue(unsigned int &p_refuiValue, const char *p_pszField) = 0;
  virtual int SetValue(unsigned int p_uiValue, const char *p_pszField) = 0;

  virtual int GetValue(__int64 &p_refllValue, const char *p_pszField) = 0;
  virtual int SetValue(__int64 p_llValue, const char *p_pszField) = 0;

  virtual int GetValue(ULONGLONG &p_refullValue, const char *p_pszField) = 0;
  virtual int SetValue(ULONGLONG p_ullValue, const char *p_pszField) = 0;

  virtual int GetValue(double &p_refdValue, const char *p_pszField) = 0;
  virtual int SetValue(double p_dValue, const char *p_pszField) = 0;

  // ������Ϣ
  virtual const char* GetLastErrorText(void) = 0;
};

// ������Ӧ�ӿ���
class MATRADEAPI IStrategySpi
{
public:
  // ������Ӧ
  virtual int OnStartup(void) {return 0;}

  // �˳���Ӧ
  virtual int OnShutdown(void) {return 0;}

  // �Ͽ���Ӧ(��������������״ζϿ�ʱ����)
  virtual int OnDisconnect(void) {return 0;}

  // ������Ӧ(��������������ؽ��ɹ�ʱ����)
  virtual int OnReconnect(void) {return 0;}

  // Ӧ����Ӧ
  virtual int OnResponse(unsigned char *p_pszRspData, int p_iDataLen, LONGLONG  p_llRequestId, const char *p_pszFuncId) {return 0;}

  // ֪ͨ��Ӧ
  virtual int OnNotify(unsigned char *p_pszNtfData, int p_iDataLen, const char *p_pszTopic) {return 0;}
};

// �������ӿ���
class MATRADEAPI IStrategyApi
{
public:
  // ����Formatʵ��
  virtual IStrategyFmt* CreateFormat(void) = 0;

  // ����Formatʵ��
  virtual void ReleaseFormat(IStrategyFmt *p_pclFmt) = 0;

  // ����������Ϣ(p_llRequestIDΨһ����)
  virtual int Request(unsigned char *p_pszReqData, int p_nDataLen, LONGLONG p_llRequestID, const char *p_pszFuncId) = 0;

  // ����������Ϣ
  virtual int Message(int p_iMsgCode, int p_iMsgLevel, const char *p_pszMsgText) = 0; 

  // ��ȡ��������Ϣ
  virtual const char* GetLastErrorText(void) = 0;
};

END_NAMESPACE_MACLI

#endif  // __MA_STRATEGY_API_H__
