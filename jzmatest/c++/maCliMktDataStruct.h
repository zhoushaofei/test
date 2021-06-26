#if !defined(__MA_CLI_MKT_DATA_STRUCT_H__)
#define __MA_CLI_MKT_DATA_STRUCT_H__
#include "maMktData.h"
#include "maCliTradeApi.h"
#include "maCliStkTradeApiStruct.h"
#include "maCliOptTradeApiStruct.h"
#include "maCliFutureTradeApiStruct.h"
BGN_NAMESPACE_MACLI


struct MACLIAPI CReqSubMktDataField:public  CReqSubTopicField
{
  //char          szMktCode[24+1];  //��Ĵ���  MKT_CODE  CHAR(24)  X ��������ı�Ĵ��룬��SH.600446
};

struct MACLIAPI CRspSubMktDataField:public  CRspSubTopicField
{
  //char          szMktCode[24+1];
};
struct MACLIAPI CReqUnsubMktDataField:public CReqUnsubTopicField
{
  //LONGLONG llCuacctCode;
};
struct MACLIAPI CRspUnsubMktDataField:public CRspUnsubTopicField
{

};
 struct MACLIAPI CReqPlayBackField
 {
  char chPlayCtrl;      //���ſ���  PLAY_CTRL CHAR(1) ��  9080  ��0����ֹͣ���� ��1������ʼ����
  char szTrdDate[8+1];    //TRD_DATE              8844
  int  iBgnTime;        //BGN_TIME              916
  int  iEndTime;        //END_TIME              917
  char chPlayBackType;    //PLAY_BACK_TYPE        8996
  int  iPlayInterval;     //�ط�ʱ����  PLAY_INTERVAL INTEGER X 9081  ���ŵ�λ����ʱ���ļ��ʱ��(PLAY_INTERVAL�Ժ���Ϊ��λ)
  char szStkCode[128+1];    //��Ʊ����  STK_CODE  VARCHAR(128)  X 48  ������������ö��ţ������ָ��000001,000002,000003��.
 };
 struct MACLIAPI CRspPlayBackField
 {
  //none
 };
 //��ѡ�ɱ༭
 struct MACLIAPI CReqMktDataPortfolioField
 {
   char     szUserCode[16+1]; //�û����� USER_CODE VARCHAR(16) Y 8902 cos�û�����
   char     chStkex;          //������   STKEX     CHAR(1)     Y 207
   char     szStkbd[2+1];     //���     STKBD     CHAR(2)     Y 625
   char     szTrdCodes[512+1];//Ʒ�ִ��� TRD_CODES VARCHAR(512)X 48  ���߷ָ�(������ӻ�ɾ��ʱ�ش�)
   char     chOperType;       //�������� OPER_TYPE CHAR(1)     Y 8844;0:��ӣ�1:����ɾ����2:��Χɾ��������Ϊ��������
   char     szBegCode[8+1];   //��ʼ���� BEG_CODE  VARCHAR(8)  X 9000��Χɾ��ʱ�ش�(�˷�Χ������ʼ����ͽ������뱾��)
   char     szEndCode[8+1];   //�������� END_CODE  VARCHAR(8)  X 9001��Χɾ��ʱ�ش�
 };

 struct MACLIAPI CRspMktDataPortfolioField
 {
   int      iAmount;          //����AMOUNTINTEGER8900���ز����ɾ��������
 };
 //��ѡ�ɲ�ѯ
 struct MACLIAPI CReqMktDataPortfolioInfoField
 {
   char     szUserCode[16+1]; //�û����� USER_CODE  VARCHAR(16) Y 8902 cos�û�����
   char     chStkex;         //������    STKEX      CHAR(1)     Y 207
   char     szStkbd[2+1];    //���      STKBD      CHAR(2)     Y 625
   char     chQueryFlag;     //��ѯ��ʽ  QUERY_FLAG CHAR(1)     Y 9080;0����λ������ѯ1����λ����ǰ��ѯ2������Χ��ѯ������������
   char     szStkCode[8+1];  //��ѯλ��  STK_CODE   VARCHAR(8)  X 8991��λ�ò�ѯʱ�ش�
   int      iQueryNum;       //��ѯ����  QUERY_NUM  INTEGER     X 8992��λ�ò�ѯʱ�ش������1000��
   char     szBegCode[8+1];  //��ʼ����  BEG_CODE   VARCHAR(8)  X 9000��Χ��ѯʱ�ش�(�˷�Χ������ʼ����ͽ������뱾��)
   char     szEndCode[8+1];  //��������  END_CODE   VARCHAR(8)  X 9001��Χ��ѯʱ�ش�
 };

 struct MACLIAPI CRspMktDataPortfolioInfoField
 {
   char     szUserCode[16+1]; //�û����� USER_CODE   VARCHAR(16)   8902 cos�û�����
   char     chStkex;           //������   STKEX      CHAR(1)       207
   char     szStkbd[2+1];      //���    STKBD       CHAR(2)       625
   int      iAmount;           //����    AMOUNT      INTEGER       8900
   char     szStkCodes[1536+1];//����(����)STK_CODES VARCHAR(512)  48  |�ָ�������
 };
//  ������ѯ
//   struct MACLIAPI CReqMktDataCodeTableField
//   {
//     char     chStkex;           //������STKEXCHAR(1)Y 207������
//     char     szStkbd[2+1];      //��� STKBDCHAR(2)Y 625���
//   };
//
//   struct MACLIAPI CRspMktDataCodeTableField
//   {
//     char     chStkex;           //������  STKEX CHAR(1)       207
//     char     szStkbd[2+1];      //���   STKBD CHAR(2)        625
//     int      iAmount;           //����   AMOUNTINTEGER        8901
//     char     szCodes[512000+1]; //���뼰����CODES VARCHAR(512000)8902{code|CNNname|ENName|type}{ code|CNNname|ENName|type }....
//   };
//   //������Ϣ��ѯ
//   struct MACLIAPI CReqMktDataCodeInfoField
//   {
//     char     chStkex;           //������ STKEX   CHAR(1)    Y 207
//     char     szStkbd[2+1];      //���  STKBD   CHAR(2)    Y 625
//     char     szStkCode[12+1];   //֤ȯ����STK_CODEVARCHAR(12)Y 48
//   };
//
//   struct MACLIAPI CRspMktDataCodeInfoField
//   {
//     char     chStkex;          //������  STKEX CHAR(1)    207
//     char     szCode[8+1];      //����������CODE  VARCHAR(8) 8901
//     char     szCnname[32+1];   //�������� CNNAMEVARCHAR(32)8902
//     char     szEnname[32+1];   //Ӣ������ ENNAMEVARCHAR(32)8903
//     int      iType;            //�������� TYPE  INTEGER    8904
//   };

 //k������
 struct MACLIAPI CReqMktDataKDataField
 {
   char     chMarket;        //�г�  MARKET       CHAR(1)     Y 8899
   char     szCode[8+1];     //����  CODE         VARCHAR(8)  Y 8900
   char     chCqFlag;        //��Ȩ��־CQ_FLAG      CHAR(1)   Y 89010������Ȩ����֧�֣�1����ǰ��Ȩ�����������ȥ��2�����Ȩ���ӹ�ȥ�����ڣ�
   int      iCqDate;         //��Ȩ����CQ_DATE      INTEGER   Y 8902
   char     chQjFlag;        //ȫ�۱�־QJ_FLAG      CHAR(1)   Y 89030:���ۣ�1��ȫ��
   char     szCycType[2+1];  //��������CYC_TYPE     VARCHAR(2)Y 89040���루��֧�֣�1����2����3����4����5����6������7����8��tickbar����֧�֣�9��5��10��15��11��30��12��60��
   int      iCycDef;         //��������CYC_DEF      INTEGER   X 8905
   char     chAutoComplete;  //�Զ�����AUTO_COMPLETECHAR(1)   Y 89060����������������
   int      iBegDate;        //��ʼ����BEG_DATE     INTEGER   Y 8907 <0:�������ڿ�ʼ0�����쿪ʼ
   int      iEndDate;        //��������END_DATE     INTEGER   X 8908
   int      iBegTime;        //��ʼʱ��BEG_TIME     INTEGER   Y 8909
   int      iEndTime;        //����ʱ��END_TIME     INTEGER   Y 8910
 };

 struct MACLIAPI CRspMktDataKDataField
 {
   char     chMarket;         //�г�  MARKET  CHAR(1)          8899
   char     szCode[8+1];      //����  CODE    VARCHAR(8)       8900
   int      iAmount;          //����  AMOUNT  INTEGER          8902��������
   int      iBegDate;         //��ʼ����      BEG_DATEINTEGER  8907
   int      iEndDate;         //��������      END_DATEINTEGER  8908
   int      iBegTime;         //��ʼʱ��      BEG_TIMEINTEGER  8909
   int      iEndTime;         //����ʱ��      END_TIMEINTEGER  8910
   char     szData[256000+1]; //����  DATA    VARCHAR(256000)  8901{����|ʱ��|���̼�|���|���|���̼�|�ɽ���}{}...���У�����YYYYMMDDʱ��HHMMSSmmm�۸���Ϊʵ�ʼ۸�10000��
 };
 //tick����
 struct MACLIAPI CReqMktDataTickSnapshotField
 {
   char     chStkex;          //������    STKEX     CHAR(1)     Y 8899
   char     szStkCodes[512+1];//����(����)STK_CODES VARCHAR(512)Y 8900 |�ָ��ֻ����,���֧�ֵ���40ֻ���룬����40ֻ�����ಿ�ֲ��ٴ���

 };

 struct MACLIAPI CRspMktDataTickSnapshotField
 {
   char     chStkex;       //������STKEX CHAR(1)         8899
   int      iAmount;       //����  AMOUNTINTEGER         8901���ص���������
   char     szData[40960+1];//���� DATA  VARCHAR(40960)  8902{..|..|..}{..|..|..}...���У�����YYYYMMDDʱ��HHMMSSmmm�۸���Ϊʵ�ʼ۸�10000��,�����������ʽΪST_MKT_DATA�ṹ���ֶ�
 };
END_NAMESPACE_MACLI

#endif  //__MA_CLI_MKT_DATA_STRUCT_H__