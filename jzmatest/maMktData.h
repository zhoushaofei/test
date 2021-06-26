//----------------------------------------------------------------------------
// ��Ȩ������������ģ�����ڽ�֤΢�ں˼ܹ�ƽ̨(KMAP)��һ����
//           ��֤�Ƽ��ɷ����޹�˾  ��Ȩ����
//
// �ļ����ƣ�maMktData.h
// ģ�����ƣ�΢�ܹ��ͻ���(Client)������ṹ����
// ģ��������
// �������ߣ������
// �������ڣ�2015-07-17
// ģ��汾��1.0
//----------------------------------------------------------------------------
// �޸�����      �汾          ����            ��ע
//----------------------------------------------------------------------------
// 2015-07-17    1.0          �����          ����
// 2016-03-18    1.0          �߽�            ����ST_MKT_DATA2��ST_MKT_DATA3�ɽ������ɽ�����ֶΣ�
//                                            ���ֿ��ַ���ʱ���޷������л�����д�����л�ʵ��
// 2016-08-16    1.0          �߽�            ST_MKT_DATA2�����������̼ۣ��Լ�4��Ԥ���ֶ�
// 2016-12-16    1.1          �߽�            ����ST_MKT_DATA�ֶε�����
// 2018-03-08    1.2          �߽�            ����ST_MKT_MATCH��ʡ�ST_MKT_ORDERί�нṹ��,ST_MKT_INDEXָ��ṹ��
//                                            ���鶩������DATA_SET���,2(ԭ�����鶩��),8(�ɽ�����),16(ί�ж���),32(ָ�궩��),���Ϊ����ǰ����,���Ķ���ȡֵ�û�
//----------------------------------------------------------------------------
#if !defined(__MA_MKT_DATA_H__)
#define __MA_MKT_DATA_H__

#include <stdio.h>

#if defined(WIN32) || defined(WIN64) || defined(OS_IS_WINDOWS)
  #if defined(MA_CLIAPI_EXPORTS)
    #define MACLIAPI __declspec(dllexport)
  #else
    #define MACLIAPI __declspec(dllimport)
  #endif
  #define MACLI_STDCALL __stdcall
  #define MACLI_EXPORTS __declspec(dllexport)
#else
  #define MACLIAPI
  #define MACLI_STDCALL
  #define MACLI_EXPORTS
#endif

#if defined (_MSC_VER) && (_MSC_VER == 1200)
  #define FORMAT_LONGLONG "%I64d"
  #if defined(WIN32) || defined(WIN64)
  typedef __int64 LONGLONG;
  #endif
#else
  #define FORMAT_LONGLONG "%lld"
  typedef long long LONGLONG;
#endif

#pragma pack(1)
//////////////////////////////////////////////////////////////////////////
// llMktDataTime:����������Ľ���ʱ��,��ʽYYYYMMDDHHMMSSsss
// chExchange   :��������0�Ͻ�����1�����A��������B��������C֣������G�н���
// iTrdDate     :�������ݱ��������,��ʽYYYYMMDD
// iDataTime    :�������ݱ����ʱ��,��ʽHHMMSSsss
// uiMatchedCnt :����,��С������
// szStatus     :Ʒ��״̬
//               '0' δ����
//               'Y' �²�Ʒ
//               'R' ���׼䣬��ֹ�κν��׻
//               'P' ���У����磬������С��޴���г��ڲ���Ϣ��¶��
//               'B' ͣ��
//               'C' ����
//               'D' ͣ��
//               'Z' ��Ʒ��ɾ��
//               'V' ��������
//               'T' �̶��۸񼯺Ͼ���
//               'W' ��ͣ���������ж����ͽ��׵Ĳ�ѯ֮�⣬�κν��׻������ֹ��
//               'X' ͣ��,( 'X'��'W'����������'X'ʱ���Գ���)
//               'I' ���м��Ͼ��ۡ�
//               'N' ���м��Ͼ��۶�����ƽ��
//               'L' ���м��Ͼ���PreOBB
//               'I' ���м��Ͼ���
//               'M' ���м��Ͽ�����OBB
//               'K' ���м��Ͼ��۶�����ƽ��(OBB)ǰ��ʱ��
//               'S' �ǽ��׷���֧��
//               'U' �̺���
//               'F' ��ǰ����
//               'E' ����
//               'O' �������
//               'Q' �������׺ͼ��Ͼ��۵Ĳ������ж�
//
// �۸�         :Ԫ,4λС��,ʵ�ʼ۸�10000��
// �����ɽ���   :��ƱΪ����,��Ȩ�ڻ�Ϊ����,����С������
// ���         :Ԫ,��С������
// ��ӯ�ʵ������ֶ�,��ʽ����
//////////////////////////////////////////////////////////////////////////
//��������(����)
struct MACLIAPI ST_MKT_DATA
{
  bool      bInitialized;
  LONGLONG  llMktDataTime;                    // ����ʱ��(YYYYMMDDHHMMSSmmm)
  char      chExchange;                       // ������
  char      szTrdCode[16 + 1];                // Ʒ�ִ���
  int       iTrdDate;                         // ��������
  int       iDataTime;                        // ����ʱ��(HHMMSSmmm)
  char      szStatus[1+1];                    // Ʒ��״̬

  unsigned int    uiPreClosePrice;            // �����̼�
  unsigned int    uiOpenPrice;                // ���̼�
  unsigned int    uiHighPrice;                // ��߼�
  unsigned int    uiLowPrice;                 // ��ͼ�
  unsigned int    uiCurPrice;                 // ���¼�
  unsigned int    uiAnsPrice[10];             // ������
  LONGLONG        llAnsVol[10];               // ������
  unsigned int    uiBidPrice[10];             // �����
  LONGLONG        llBidVol[10];               // ������
  unsigned int    uiMatchedCnt;               // �ɽ�����
  LONGLONG        llMatchedVol;               // �ɽ�����
  LONGLONG        llMatchedAmtTot;            // �ɽ��ܽ��
  LONGLONG        llBidVolTot;                // ��������
  LONGLONG        llAnsVolTot;                // ��������
  unsigned int    uiBidPriceAvg;              // ƽ��ί��۸�
  unsigned int    uiAnsPriceAvg;              // ƽ��ί���۸�
  int             iIopv;                      // IOPV
  int             iYield;                     // ����������
  unsigned int    uiHighLmtPrice;             // ��ͣ��
  unsigned int    uiLowLmtPrice;              // ��ͣ��
  char            szStkPrefix[16 + 1];        // ֤ȯǰ׺
  LONGLONG        llPreOpenVol;               // ��ֲ���
  unsigned int    uiSettPrice;                // ������
  int             iPreDelta;                  // ����ʵ��
  int             iCurrDelta;                 // ����ʵ��
  int             iNsyl1;                     // ��ӯ��1
  int             iNsyl2;                     // ��ӯ��2
  int             iNsd2;                      // ����2
  LONGLONG        llOpenVol;                  // �ֲ�����
  unsigned int    uiPreSettPrice;             // ������
  unsigned int    uiClosePrice;               // ������
  char            szContractID[32 +1];        // ��Ȩ��Լ����
  char            szUnderlyingSecurityID[32]; // ���֤ȯ����
  char            szCallOrPut[1+1];           // �Ϲ��Ϲ�C1
  int             iExerciseDate;              // ��Ȩ��Ȩ�գ�YYYYMMDD
  char            szCallOrPutStatus[1+1];     //

  int Serialize(char *p_szFmtMktDataStr, int p_iFmtMktDataStrLen);
  int DeSerialize(char * p_szFmtMktDataStr);
};

//��������(����)
struct MACLIAPI ST_MKT_DATA2
{
  bool            bInitialized;
  LONGLONG        llMktDataTime;              // ����ʱ��(YYYYMMDDHHMMSSmmm)
  char            chExchange;                 // ������
  char            szTrdCode[16 + 1];          // Ʒ�ִ���
  int             iTrdDate;                   // ��������
  int             iDataTime;                  // ����ʱ��(HHMMSSmmm)
  char            szStatus[1+1];              // Ʒ��״̬

  unsigned int    uiCurPrice;                 // ���¼ۣ��۸�*10000)
  unsigned int    uiAnsPrice[10];             // �����ۣ��۸�*10000)
  LONGLONG        llAnsVol[10];               // ������
  unsigned int    uiBidPrice[10];             // ����ۣ��۸�*10000)
  LONGLONG        llBidVol[10];               // ������
  unsigned int    uiMatchedCnt;               // �ɽ�����
  LONGLONG        llMatchedVol;               // �ɽ���
  LONGLONG        llMatchedValue;             // �ɽ����

  unsigned int    uiPreClosePrice;            // �����̼� 2016/8/16����
  unsigned int    uiReserved1;                // Ԥ��1    2016/8/16����
  unsigned int    uiReserved2;                // Ԥ��2    2016/8/16����
  unsigned int    uiReserved3;                // Ԥ��3    2016/8/16����
  unsigned int    uiReserved4;                // Ԥ��4    2016/8/16����

  int Serialize(char *p_szFmtMktDataStr, int p_iFmtMktDataStrLen);
  int DeSerialize(char * p_szFmtMktDataStr);
};

//��������(Ԥ��)
struct MACLIAPI ST_MKT_DATA3
{
  bool            bInitialized;
  LONGLONG        llMktDataTime;              // ����ʱ��(YYYYMMDDHHMMSSmmm)
  char            chExchange;                 // ������
  char            szTrdCode[16 + 1];          // Ʒ�ִ���
  int             iTrdDate;                   // ��������
  int             iDataTime;                  // ����ʱ��(HHMMSSmmm)
  char            szStatus[1+1];              // Ʒ��״̬

  unsigned int    uiCurPrice;                 // ���¼ۣ��۸�*10000)
  unsigned int    uiAnsPrice[5];              // �����ۣ��۸�*10000)
  LONGLONG        llAnsVol[5];                // ������
  unsigned int    uiBidPrice[5];              // ����ۣ��۸�*10000)
  LONGLONG        llBidVol[5];                // ������
  unsigned int    uiMatchedCnt;               // �ɽ�����
  LONGLONG        llMatchedVol;               // �ɽ���
  LONGLONG        llMatchedValue;             // �ɽ����
  int Serialize(char *p_szFmtMktDataStr, int p_iFmtMktDataStrLen);
  int DeSerialize(char * p_szFmtMktDataStr);
};

//�ɽ�����
struct MACLIAPI ST_MKT_MATCH
{
  bool           bInitialized;
  char           chExchange;             // ������
  char           szTrdCode[16 + 1];      // Ʒ�ִ���
  int            iTrdDate;               // ��������
  char           chType;                 // ����:0�໻1�ջ�2˫��;3�࿪4�տ�5˫��;6��ƽ7��ƽ8˫ƽ
  char           chBSSide;               // ��������:0:�� 1:�� ����:
  int            iDataDate;              // ��������
  int            iDataTime;              // ����ʱ��  
  int            iIopv;                  // (Indicative Optimized Portfolio Value)ETF�Ļ���ݶ�ο���ֵ,�ɽ�����ÿ15����㲢����һ��,ʵ�ʼ۸�10000��
  unsigned int   uiPrice;                // �ɽ���	
  int            iOpenVol;               // �ֲ�����
  unsigned int   uiMatchedCnt;           // �ɽ�����
  unsigned int	 uiMatchedVol;           // �ɽ���
  LONGLONG       llMatchedAmtTot;        // �ɽ����
  int            iTimediff;              // ����˱ʳɽ������ʿ���ʱ��� ԽСԽ׼ȷ
  int Serialize(char *p_szFmtMktDataStr, int p_iFmtMktDataStrLen);
  int DeSerialize(char * p_szFmtMktDataStr);
};

//ί������
struct MACLIAPI ST_MKT_ORDER
{
  bool           bInitialized;
  char           chExchange;             // ������
  char           szTrdCode[16 + 1];      // Ʒ�ִ���
  int            iTrdDate;               // ��������
  char           chOrderType;            // ί����� 1=��  2=��    G=����    F=����
  int            iDataDate;              // ί������
  int            iDataTime;	             // ί��ʱ��
  int 	         iOrderNo;               // ί�к�
  unsigned int	 uiOrderPrice;           // ί�м۸�
  int 	         iOrderVol;              // ί������
  int Serialize(char *p_szFmtMktDataStr, int p_iFmtMktDataStrLen);
  int DeSerialize(char * p_szFmtMktDataStr);  
};

// ָ������
struct MACLIAPI ST_MKT_INDEX
{
  bool                bInitialized;
  char                chExchange;         // ������
  char                szTrdCode[16 + 1];  // Ʒ�ִ���
  int                 iTrdDate;           // ��������
  unsigned short      uiIndexType;        // ָ����� ָ�������ָ�����ݵľ��庬��,�������ͺ�����չ
  int                 iDataDate;          // ָ������
  int                 iDataTime;          // ָ��ʱ��
  unsigned long long  ullIndexMask;       // �������� iλbit����uiIndexData[i]����
  unsigned int	      uiIndexData[64];    // ����    
  int Serialize(char *p_szFmtMktDataStr, int p_iFmtMktDataStrLen);
  int DeSerialize(char * p_szFmtMktDataStr);  
};

struct ST_EXCHANGE_CVT
{
  char chExchange;
  char szHongHuiType[3+1];
  char szTsType[2+1];
};

#pragma pack()

const ST_EXCHANGE_CVT g_stExchangeCvt[] =
{
  {'0', "SZ",  "SZ"},   // ����֤ȯ������
  {'1', "SH",  "SH"},   // �Ϻ�֤ȯ������
  {'A', "SHF", "SQ"},   // �Ϻ��ڻ�������
  {'B', "DCE", "DL"},   // �����ڻ�������
  {'C', "CZC", "ZZ"},   // ֣���ڻ�������
  {'G', "CF",  "ZJ"},   // �й������ڻ�������
  {'7', "HK",  "HK"},   // ��۽�����
  {'2', "BJ",  "BJ"}    // ����֤ȯ������
};

#endif  // __MA_MKT_DATA_H__
