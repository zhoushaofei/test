#if !defined(__MA_CLI_COS_TRADE_API_STRUCT_H__)
#define __MA_CLI_COS_TRADE_API_STRUCT_H__
#include "maCliTradeApi.h"
#include "maCliStkTradeApiStruct.h"
#include "maCliFislTradeApiStruct.h"
#include "maCliOptTradeApiStruct.h"
#include "maCliFutureTradeApiStruct.h"
BGN_NAMESPACE_MACLI

//��ϵͳ��ѯ
struct MATRADEAPI CReqCosConfField
{
	int      iSubsys;//��ϵͳSUBSYSSMALLINTX 908081:֤ȯ�ֻ�����ϵͳ
};

struct MATRADEAPI CRspCosConfField
{
	int      iSubsys;            //��ϵͳ     SUBSYS        SMALLINT    9080
	int      iSubsysSn;          //��ϵͳ����   SUBSYS_SN     SMALLINT    8988
	char     szSubsysConnstr[128+1];//ϵͳ���Ӵ�   SUBSYS_CONNSTRVARCHAR(128)9081
	int      iFlowRight;         //����Ȩ(��/��)FLOW_RIGHT    INTEGER     9082
};
//��ϵͳ����
struct MATRADEAPI CReqCosChgConfField
{
	char     chOperationType;//��������    OPERATION_TYPECHAR(1)     Y 8987 0:���� 1:�޸� 2:ɾ��
	int      iSubsys;        //��ϵͳ     SUBSYS        SMALLINT    Y 9080 
	int      iSubsysSn;      //��ϵͳ����   SUBSYS_SN     SMALLINT    Y 8988 
	char     szSubsysConnstr[128+1];//ϵͳ���Ӵ�   SUBSYS_CONNSTRVARCHAR(128)X 9081 
	int      iFlowRight;     //����Ȩ(��/��)FLOW_RIGHT    INTEGER     X 9082 
};

struct MATRADEAPI CRspCosChgConfField
{
};

//����ί��
struct MATRADEAPI CReqCosOrderField
{
	char     szCuacctCode[16+1];   //�ʲ��˻�   CUACCT_CODE         BIGINT      Y 8920 
  char     chCuacctType;         //�ʲ��˻�����
	char     szCustCode[16+1];           //�ͻ�����   CUST_CODE           BIGINT      X 8902 
	char     szTrdacct[10+1];     //�����˻�   TRDACCT             VARCHAR(10) Y 448  
	char     chExchange;           //������    EXCHANGE            CHAR(1)     X 207  
	char     szStkbd[2+1];        //���װ��   STKBD               CHAR(2)     Y 625  '00' -- ���ڣ���
	int      iStkBiz;              //����ҵ��   STK_BIZ             SMALLINT    Y 8842 
	int      iStkBizAction;        //ҵ��   STK_BIZ_ACTION      SMALLINT    Y 40   
	char     szTrdCode[8+1];      //Ʒ�ִ���   TRD_CODE            VARCHAR(8)  X 48   
	char     szOptNum[16+1];      //��Լ����   OPT_NUM             VARCHAR(16) X 9082 
	int      iIntOrg;              //�ڲ�����   INT_ORG             SMALLINT    X 8911 
	int      iOrderBsn;            //ί������   ORDER_BSN           INTEGER     X 66   
	LONGLONG llOrderQty;           //ί������   ORDER_QTY           BIGINT      Y 38   
	char     szOrderPrice[21+1];   //ί�м۸�   ORDER_PRICE         CPRICE      X 44   
	char     szStopPrice[21+1];    //�����۸�   STOP_PRICE          CPRICE      X 8975 
	int      iValidDate;           //��ֹ����   VALID_DATE          INTEGER     X 8859 
	int      iTrdCodeCls;          //Ʒ������   TRD_CODE_CLS        INTEGER     X 8970 
	char     szOrderAttr[256+1];  //�߼�����   ORDER_ATTR          VARCHAR(256)X 9100 
	int      iAttrCode;            //���Դ���   ATTR_CODE           SMALLINT    Y 91010:��ͨ�µ�
	int      iBgnExeTime;          //ִ�п�ʼʱ�� BGN_EXE_TIME        INTEGER     X 916  
	int      iEndExeTime;          //ִ�н���ʱ�� END_EXE_TIME        INTEGER     X 917  
	char     szSpreadName[64+1];  //�������   SPREAD_NAME         VARCHAR(64) X 8971 
	char     szUndlCode[16+1];    //��Ĵ���   UNDL_CODE           VARCHAR(16) X 8972 
	int      iConExpDate;          //��Լ������  CON_EXP_DATE        INTEGER     X 8976 
	char     szExercisePrice[21+1];//��Ȩ��    EXERCISE_PRICE      CPRICE      X 8973 
	LONGLONG llConUnit;            //��Լ��λ   CON_UNIT            BIGINT      X 8974 
	char     szCliOrderNo[32+1];  //�ͻ���ί�б��CLI_ORDER_NO        VARCHAR(32) X 9102 
	char     szCliRemark[32+1];   //������Ϣ   CLI_REMARK          VARCHAR(32) X 8914 
	char     szBusinessUnit[21+1];//ҵ��Ԫ   BUSINESS_UNIT       VARCHAR(21) X 87170
	char     szGtdData[9+1];      //GTD����  GTD_DATA            VARCHAR(9)  X 87230
	char     chContingentCondition;//��������   CONTINGENT_CONDITIONVARCHAR(1)  X 87131:����
	char     chForceCloseReason;   //ǿƽԭ��   FORCE_CLOSE_REASON  VARCHAR(1)  X 87150
	int      iIsSwapOrder;         //��������־  IS_SWAP_ORDER       SMALLINT    X 87200
	char     szOrderIdEx[64+1];   //�ⲿ��ͬ��� ORDER_ID_EX         VARCHAR(64) X 9093 �����Ϊ�ⲿ���룬��Ȩϵͳ�����κδ���
};

struct MATRADEAPI CRspCosOrderField
{
	char     szCliOrderNo[32+1];//�ͻ���ί�б��CLI_ORDER_NO   VARCHAR(32) 9102
	int      iOrderBsn;         //ί������   ORDER_BSN      INTEGER     66  
	int      iOrderNo;          //ί�б��   ORDER_NO       INTEGER     9106
	int      iOrderDate;        //ί������   ORDER_DATE     INTEGER     8834
	char     szOrderTime[32+1];//ί��ʱ��   ORDER_TIME     VARCHAR(32) 8845
	char     chExeStatus;       //ִ��״̬   EXE_STATUS     CHAR(1)     9103
	char     szExeInfo[128+1]; //ִ����Ϣ   EXE_INFO       VARCHAR(128)9104
	LONGLONG llOrderQty;        //ί������   ORDER_QTY      BIGINT      38  
	int      iTrdBiz;           //����ҵ��   TRD_BIZ        SMALLINT    8842
	int      iTrdBizAcction;    //ҵ��   TRD_BIZ_ACCTIONSMALLINT    40  
	char     szTrdCode[8+1];   //Ʒ�ִ���   TRD_CODE       VARCHAR(8)  48  
	char     szUndlCode[16+1]; //��Ĵ���   UNDL_CODE      VARCHAR(16) 8972
	char     szCuacctCode[16+1];      //�ʲ��˻�   CUACCT_CODE    BIGINT      8920
};

//ί�г���
struct MATRADEAPI CReqCosCancelOrderField
{
  char     szCuacctCode[16+1];//�ʲ��˻�CUACCT_CODEBIGINT  Y 8920
  char     chCuacctType;         //�ʲ��˻�����
	int      iIntOrg;     //�ڲ�����INT_ORG    SMALLINTX 8911�ڲ�����(��Ȩ����)
	char     szStkbd[2+1];//���װ��STKBD      CHAR(2) X 625 �ֵ�[STKBD]
	int      iOrderDate;  //ί������ORDER_DATE INTEGER Y 8834
	int      iOrderNo;    //ί�б��ORDER_NO   INTEGER X 9106
	int      iOrderBsn;   //ί������ORDER_BSN  INTEGER X 66  
};

struct MATRADEAPI CRspCosCancelOrderField
{
	char     szCuacctCode[16+1];      //�ʲ��˻�   CUACCT_CODE    BIGINT      8920
	char     szStkbd[2+1];     //���װ��   STKBD          CHAR(2)     625 
	int      iOrderDate;        //ί������   ORDER_DATE     INTEGER     8834
	int      iOrderNo;          //ί�б��   ORDER_NO       INTEGER     9106
	char     szCliOrderNo[32+1];//�ͻ���ί�б��CLI_ORDER_NO   VARCHAR(32) 9102
	int      iOrderBsn;         //ί������   ORDER_BSN      INTEGER     66  
	char     chExeStatus;       //ִ��״̬   EXE_STATUS     CHAR(1)     9103
	char     szExeInfo[128+1]; //ִ����Ϣ   EXE_INFO       VARCHAR(128)9104
	LONGLONG llOrderQty;        //ί������   ORDER_QTY      BIGINT      38  
	int      iTrdBiz;           //����ҵ��   TRD_BIZ        SMALLINT    8842
	int      iTrdBizAcction;    //ҵ��   TRD_BIZ_ACCTIONSMALLINT    40  
	char     szTrdCode[8+1];   //Ʒ�ִ���   TRD_CODE       VARCHAR(8)  48  
	char     szUndlCode[16+1]; //��Ĵ���   UNDL_CODE      VARCHAR(16) 8972
	char     chCancelStatus;    //�ڲ�������־ CANCEL_STATUS  CHAR(1)     9080
};

//ί�иĵ�
struct MATRADEAPI CReqCosChgOrderField
{
  char     szCuacctCode[16+1];//�ʲ��˻�CUACCT_CODEBIGINT Y 8920
  char     chCuacctType;         //�ʲ��˻�����
	int      iOrderDate;  //ί������ORDER_DATE INTEGERY 8834
	int      iOrderNo;    //ί�б��ORDER_NO   INTEGERY 9106
	LONGLONG llOrderQty;  //ί������ORDER_QTY  BIGINT Y 38  
	char     szOrderPrice[21+1];//ί�м۸�ORDER_PRICECPRICE Y 44  
};

struct MATRADEAPI CRspCosChgOrderField
{
};

//�������ί��
struct MATRADEAPI CReqCosCombOrderField
{
  char     szCuacctCode[16+1];   //�ʲ��˻�  CUACCT_CODE    BIGINT        Y 8920
  char     chCuacctType;         //�ʲ��˻�����
	char     szCustCode[16+1];     //�ͻ�����  CUST_CODE      BIGINT        Y 8902
	char     szTrdacct[10+1];//�����˻�  TRDACCT        VARCHAR(10)   Y 448 
	char     szSpreadName[32+1];//�������  SPREAD_NAME    VARCHAR(32)   Y 8971
	int      iValidDate;     //��ֹ����  VALID_DATE     INTEGER       Y 8859
	int      iOrderDataNum;  //��������  ORDER_DATA_NUM INTEGER       Y 8857
	char     szOrderGrpText[32768+1];//ί�����  ORDER_GRP_TEXT VARCHAR(32768)Y 9080
	int      iModuleDataNum; //���ģ������MODULE_DATA_NUMINTEGER       Y 9081
	char     szModuleGrpText[2048+1];//���ģ��  MODULE_GRP_TEXTVARCHAR(2048) Y 9082
	int      iOrderDate;     //ί������  ORDER_DATE     INTEGER       Y 8834
	char     szOrderTime[32+1];//ί��ʱ��  ORDER_TIME     VARCHAR(32)   Y 8845
};

struct MATRADEAPI CRspCosCombOrderField
{
	int      iOrderBsn;       //ί������  ORDER_BSN  INTEGER     66  
	int      iOrderDate;      //ί������  ORDER_DATE INTEGER     8834
	char     szOrderTime[32+1];//ί��ʱ��  ORDER_TIME VARCHAR(32) 8845
	int      iOrderNo;        //ί�б��  ORDER_NO   INTEGER     9106
	char     szClientId[32+1];//�ͻ�������ʶCLIENT_ID  VARCHAR(32) 8858
	char     chExeStatus;     //ִ��״̬  EXE_STATUS CHAR(1)     9103
	char     szExeInfo[128+1];//ִ����Ϣ  EXE_INFO   VARCHAR(128)9104
	char     szCuacctCode[16+1];    //�ʲ��˻�  CUACCT_CODEBIGINT      8920
};
//��ͨ������ί��
struct MATRADEAPI CReqCosNormalOrderField
{
  char     szCustCode[16+1];        //�ͻ�����  CUST_CODE         BIGINT      X 8902 
  char     chCuacctType;         //�ʲ��˻�����
	char     szCuacctCode[16+1];      //�ʲ��˻�  CUACCT_CODE       BIGINT      Y 8920 
	char     szStkbd[2+1];     //���װ��  STKBD             CHAR(2)     Y 625  �ֵ�[STKBD]
	char     szStkCode[8+1];   //֤ȯ����  STK_CODE          VARCHAR(8)  Y 48   
	char     szOrderPrice[21+1];//ί�м۸�  ORDER_PRICE       CPRICE      X 44   
	LONGLONG llOrderQty;        //ί������  ORDER_QTY         BIGINT      Y 38   
	int      iStkBiz;           //֤ȯҵ��  STK_BIZ           SMALLINT    Y 8842 �ֵ�[STK_BIZ]
	int      iStkBizAction;     //ҵ����Ϊ  STK_BIZ_ACTION    SMALLINT    Y 40   �ֵ�[STK_BIZ_ACTION]
	char     szStkpbu[8+1];    //���׵�Ԫ  STKPBU            VARCHAR(8)  X 8843 
	int      iOrderBsn;         //ί������  ORDER_BSN         INTEGER     X 66   
	char     szOrderText[256+1];//ί����չ  ORDER_TEXT        VARCHAR(256)X 58   ��ʽ:�ؼ���1=ֵ1,�ؼ���2=ֵ2
	char     szClientInfo[256+1];//�ն���Ϣ  CLIENT_INFO       VARCHAR(256)X 9039 ����Ӳ�̺�\CPU\��������
	char     chSecurityLevel;   //��ȫ�ֶ�  SECURITY_LEVEL    CHAR(1)     Y 90801:У��Ựƾ֤
	char     szSecurityInfo[256+1];//��ȫ��Ϣ  SECURITY_INFO     VARCHAR(256)X 9081 
	char     szComponetStkCode[8+1];//�ɷݹɴ��� COMPONET_STK_CODE VARCHAR(8)  X 8911 ETF���¹�Ʊ�Ϲ�����
	char     szComponetStkbd[2+1];//�ɷݹɰ�� COMPONET_STKBD    VARCHAR(2)  X 8962 ETF���¹�Ʊ�Ϲ���ETFʵ����������
	char     szStkbdLink[2+1]; //�������  STKBD_LINK        CHAR(2)     X 17   ETF���¹�Ʊ�Ϲ���ETFʵ����������
	char     szTrdacct[10+1];  //֤ȯ�˻�  TRDACCT           VARCHAR(10) Y 448  
	int      iCuacctSn;         //�˻����  CUACCT_SN         SMALLINT    X 8928 �ͻ��˱�ʶ�����ڶ���ͻ��˹���ͬһ���ʲ��˺��µ�ʱ�����ֲ�ͬ�ͻ��˵�ί����ɽ���Ϣ�����ṩ����صĽӿڲ�ѯ���ܡ�
	char     chPublishCtrlFlag; //��Ʊ��ر�־PUBLISH_CTRL_FLAG CHAR(1)     X 90830��������
	char     szRepayOrderId[10+1];//������ͬ���REPAY_ORDER_ID    VARCHAR(10) X 11   ����������ȯ����
	int      iRepayOpeningDate; //������Լ����REPAY_OPENING_DATEINTEGER     X 9121 ����������ȯ����
	char     szRepayStkCode[8+1];//����֤ȯ����REPAY_STK_CODE    VACHAR(8)   X 9218 ����������ȯ����
	char     szRepayContractAmt[21+1];//�������  REPAY_CONTRACT_AMTCMONEY      X 8504 ֱ�ӻ�����Ҫ����
};

struct MATRADEAPI CRspCosNormalOrderField
{
	int      iOrderBsn;        //ί������ORDER_BSN     INTEGER    66  
	char     szCuacctCode[16+1];     //�ʲ��˻�CUACCT_CODE   BIGINT     8920
	char     szOrderPrice[21+1];//ί�м۸�ORDER_PRICE   CPRICE     44  
	LONGLONG llOrderQty;       //ί������ORDER_QTY     BIGINT     38  
	char     szStkpbu[8+1];   //���׵�ԪSTKPBU        VARCHAR(8) 8843
	char     szStkbd[2+1];    //���װ��STKBD         CHAR(2)    625 
	char     szStkCode[8+1];  //֤ȯ����STK_CODE      VARCHAR(8) 48  
	char     szStkName[16+1]; //֤ȯ����STK_NAME      VARCHAR(16)55  
	int      iStkBiz;          //֤ȯҵ��STK_BIZ       SMALLINT   8842
	int      iStkBizAction;    //ҵ����ΪSTK_BIZ_ACTIONSMALLINT   40  
	char     szTrdacct[10+1]; //֤ȯ�˻�TRDACCT       VARCHAR(10)448 
};

//�ڵ���
struct MATRADEAPI CReqCosChgNodeField
{
	char     chNodeChgFlag;//����л���־NODE_CHG_FLAGCHAR(1)Y 9080��0��: ���� ��1��:����
	int      iNodeIdOrg;   //ԭ�ڵ��� NODE_ID_ORG  INTEGERY 9081�л�ǰ���
	int      iNodeIdNow;   //�ֽڵ��� NODE_ID_NOW  INTEGERY 9082�л������
	char     chNodeStatus; //ԭ���״̬ NODE_STATUS  CHAR(1)Y 9083���������̨�Զ���
};

struct MATRADEAPI CRspCosChgNodeField
{
	char     chNodeChgFlag;    //����л���־NODE_CHG_FLAGCHAR(1)9080
	int      iNodeIdOrg;       //ԭ�ڵ��� NODE_ID_ORG  INTEGER9081
	int      iNodeIdNow;       //�ֽڵ��� NODE_ID_NOW  INTEGER9082
};
//�ڵ�������
struct MATRADEAPI CReqCosChgNodeOnlineField
{
	char     chNodeChgFlag;//����л���־NODE_CHG_FLAGCHAR(1)Y 9080
	int      iNodeIdOrg;   //ԭ�ڵ��� NODE_ID_ORG  INTEGERY 9081�л�ǰ���
	int      iNodeIdNow;   //�ֽڵ��� NODE_ID_NOW  INTEGERY 9082�л������
};

struct MATRADEAPI CRspCosChgNodeOnlineField
{
};
//�Զ���¼
struct MATRADEAPI CReqCosAutoLoginField
{
  char     szAcctType[2+1];//�˻�����ACCT_TYPE  VARCHAR(2)  Y 8987��U��:�ͻ�����
  char     szAcctId[32+1];//�˻���ʶACCT_ID    VARCHAR(32) Y 9081
  char     chCuacctType;//�ʲ��˻�����CUACCT_TYPE    CHAR(1) Y 8826
  char     chUseScope;  //ʹ�÷�ΧUSE_SCOPE  CHAR(1)     X 9082��0��:��������
  char     szEncryptKey[32+1];//��������ENCRYPT_KEYVARCHAR(32) Y 9086�磺ʹ�ù��ܺ�(10301105)��������
  char     chAuthType;  //��֤����AUTH_TYPE  CHAR(1)     X 9083��0��--����
  char     szAuthData[256+1];//��֤����AUTH_DATA  VARCHAR(256)Y 9084���ֶ�ʹ��maCli_ComEncrypt�������Կͻ��������룬��ENCRYPT_KEY�ֶ��е�ֵ��ΪKey���м��ܺ�õ�����
};

struct MATRADEAPI CRspCosAutoLoginField
{
};
//-------------------------------10388750:��¼��̨����ϵͳ--------------------------
struct MATRADEAPI CReqCosLoginField
{
  char            szUserCode[16 + 1];         // �û����� Ҳ�������ֻ��ŵ�¼
  char            szAuthData[256 + 1];        // ��֤���� 
  char            szEncryptKey[32 + 1];       // �������� 
  char            szThirdParty[1024 + 1];     // ������ ʹ�õ������ͻ��˵��û��������,�ֶ���������Կdllָ���ӿڻ�ȡ;
};

struct MATRADEAPI CRspCosLoginField
{
  char            szUserCode[16 + 1];         // �û����� 
  char            szPhoneNum[16 + 1];         // �ֻ��� 
  char            szUserGroupRight[8 + 1];    // �û���Ȩ�� 
  char            szSessionId[128 + 1];       // �Ựƾ֤ �ͻ����豣�棬����������д���̶���λỰƾ֤(8814)�У�����������󽫱��ܾ���
};

//����ί�в�ѯ
struct MATRADEAPI CReqCosOrderInfoField
{
  char     szCuacctCode[16+1];//�ʲ��˻�  CUACCT_CODE BIGINT     Y 8920 
  char     chCuacctType;         //�ʲ��˻�����
	char     szStkbd[2+1];//���װ��  STKBD       CHAR(2)    X 625  
	int      iTrdCodeCls; //Ʒ������  TRD_CODE_CLSINTEGER    X 8970 
	char     szTrdCode[8+1];//Ʒ�ִ���  TRD_CODE    VARCHAR(8) X 48   
	char     szOptNum[16+1];//��Լ����  OPT_NUM     VARCHAR(16)X 9082 
	int      iOrderNo;    //ί�б��  ORDER_NO    INTEGER    X 9106 
	int      iOrderBsn;   //ί������  ORDER_BSN   INTEGER    X 66   
	char     szTrdacct[10+1];//�����˻�  TRDACCT     VARCHAR(10)X 448  
	int      iAttrCode;   //���Դ���  ATTR_CODE   SMALLINT   X 9101 
	int      iBgnExeTime; //ִ�п�ʼʱ��BGN_EXE_TIMEINTEGER    X 916  
	char     chQueryFlag; //��ѯ����  QUERY_FLAG  CHAR(1)    Y 90800:���ȡ����
	char     szQueryPos[32+1];//��λ��   QUERY_POS   VARCHAR(32)X 8991 ���ѯ������ʲ��˻����ʹ��
	int      iQueryNum;   //��ѯ����  QUERY_NUM   INTEGER    Y 8992 ���ֵΪ1000
	char     chFlag;      //��ѯ��־  FLAG        CHAR(1)    X 9081 ��1�� :  �ɳ���
};

struct MATRADEAPI CRspCosOrderInfoField
{
	char     szQryPos[32+1];    //��λ��    QRY_POS       VARCHAR(32) 8991
	char     szCuacctCode[16+1];       //�ʲ��˻�   CUACCT_CODE   BIGINT      8920
	char     szCustCode[16+1];         //�ͻ�����   CUST_CODE     BIGINT      8902
	char     szTrdacct[10+1];   //�����˻�   TRDACCT       VARCHAR(10) 448 
	char     chExchange;         //������    EXCHANGE      CHAR(1)     207 
	char     szStkbd[2+1];      //���װ��   STKBD         CHAR(2)     625 
	int      iTrdCodeCls;        //Ʒ������   TRD_CODE_CLS  INTEGER     8970
	int      iStkBiz;            //����ҵ��   STK_BIZ       SMALLINT    8842
	int      iStkBizAction;      //ҵ��   STK_BIZ_ACTIONSMALLINT    40  
	char     szTrdCode[8+1];    //Ʒ�ִ���   TRD_CODE      VARCHAR(8)  48  
	char     szOptNum[16+1];    //��Լ����   OPT_NUM       VARCHAR(16) 9082
	int      iIntOrg;            //�ڲ�����   INT_ORG       SMALLINT    8911
	int      iOrderDate;         //ί������   ORDER_DATE    INTEGER     8834
	char     szOrderTime[32+1]; //ί��ʱ��   ORDER_TIME    VARCHAR(32) 8845
	int      iOrderBsn;          //ί������   ORDER_BSN     INTEGER     66  
	int      iOrderNo;           //ί�б��   ORDER_NO      INTEGER     9106
	LONGLONG llOrderQty;         //ί������   ORDER_QTY     BIGINT      38  
	char     szOrderPrice[21+1]; //ί�м۸�   ORDER_PRICE   CPRICE      44  
	char     szStopPrice[21+1];  //�����۸�   STOP_PRICE    CPRICE      8975
	int      iValidDate;         //��ֹ����   VALID_DATE    INTEGER     8859
	char     szOrderAttr[256+1];//�߼�����   ORDER_ATTR    VARCHAR(256)9100
	int      iAttrCode;          //���Դ���   ATTR_CODE     SMALLINT    9101
	int      iBgnExeTime;        //ִ�п�ʼʱ�� BGN_EXE_TIME  INTEGER     916 
	int      iEndExeTime;        //ִ�н���ʱ�� END_EXE_TIME  INTEGER     917 
	char     szSpreadName[64+1];//�������   SPREAD_NAME   VARCHAR(64) 8971
	char     szUndlCode[16+1];  //��Ĵ���   UNDL_CODE     VARCHAR(16) 8972
	int      iConExpDate;        //��Լ������  CON_EXP_DATE  INTEGER     8976
	char     szExercisePrice[21+1];//��Ȩ��    EXERCISE_PRICECPRICE      8973
	LONGLONG llConUnit;          //��Լ��λ   CON_UNIT      BIGINT      8974
	char     szCliOrderNo[32+1];//�ͻ���ί�б��CLI_ORDER_NO  VARCHAR(32) 9102
	char     szCliRemark[32+1]; //������Ϣ   CLI_REMARK    VARCHAR(32) 8914
	char     chExeStatus;        //ִ��״̬   EXE_STATUS    CHAR(1)     9103
	char     szExeInfo[128+1];  //ִ����Ϣ   EXE_INFO      VARCHAR(128)9104
	LONGLONG llExeQty;           //ִ������   EXE_QTY       BIGINT      9105
	LONGLONG llMatchedQty;       //�ѳɽ�����  MATCHED_QTY   BIGINT      387 
	LONGLONG llWithdrawnQty;     //�ѳ�������  WITHDRAWN_QTY BIGINT      8837
	char     szMatchedAmt[21+1]; //�ѳɽ����  MATCHED_AMT   CMONEY      8504
	char     szUpdateTime[32+1];//����޸�ʱ�� UPDATE_TIME   VARCHAR(32) 8757
};
//�ͻ����ڽڵ��Ų�ѯ
struct MATRADEAPI CReqCosNodeInfoField
{
  char     szCuacctCode[16+1];//�ʲ��˻�CUACCT_CODEBIGINTY 8920
	char     szCustCode[16+1];  //�ͻ�����CUST_CODE  BIGINTX 8902
};

struct MATRADEAPI CRspCosNodeInfoField
{
  char     szCuacctCode[16+1];    //�ʲ��˻� CUACCT_CODEBIGINT  8920
  char     chCuacctType;         //�ʲ��˻�����
	char     szCustCode[16+1];      //�ͻ����� CUST_CODE  BIGINT  8902
	int      iSubsys;         //��ϵͳ  SUBSYS     SMALLINT9080
	int      iSubsysSn;       //��ϵͳ����SUBSYS_SN  SMALLINT8988
	int      iNodeIdOrg;      //ԭ�ڵ���NODE_ID_ORGINTEGER 9081
	int      iNodeIdNow;      //�ֽڵ���NODE_ID_NOWINTEGER 9082
};
//�ڵ�Ŀͻ���ѯ
struct MATRADEAPI CReqCosNodeCustInfoField
{
	int      iNodeIdOrg;//ԭ�ڵ���NODE_ID_ORGINTEGER    X 9081����ͬʱΪ��
	int      iNodeIdNow;//�ֽڵ���NODE_ID_NOWINTEGER    X 9082����ͬʱΪ��
	char     szQueryPos[32+1];//��λ��  QUERY_POS  VARCHAR(32)X 8991
	int      iQueryNum; //��ѯ���� QUERY_NUM  INTEGER    X 8992���ֵΪ1000
};

struct MATRADEAPI CRspCosNodeCustInfoField
{
	char     szQryPos[32+1]; //��λ��  QRY_POS    VARCHAR(32)8991
  char     szCuacctCode[16+1];    //�ʲ��˻� CUACCT_CODEBIGINT     8920
  char     chCuacctType;         //�ʲ��˻�����
	char     szCustCode[16+1];      //�ͻ����� CUST_CODE  BIGINT     8902
	int      iSubsys;         //��ϵͳ  SUBSYS     SMALLINT   9080
	int      iSubsysSn;       //��ϵͳ����SUBSYS_SN  SMALLINT   8988
	int      iNodeIdOrg;      //ԭ�ڵ���NODE_ID_ORGINTEGER    9081
	int      iNodeIdNow;      //�ֽڵ���NODE_ID_NOWINTEGER    9082
};
//�ӿ����ò�ѯ
struct MATRADEAPI CReqCosItfInfoField
{
	char     szItfDataTypes[32+1];//�ӿ���������ITF_DATA_TYPESCHAR(32)X 9028
	char     szItfDataFlows[32+1];//�ӿ���������ITF_DATA_FLOWSCHAR(32)X 9029
};

struct MATRADEAPI CRspCosItfInfoField
{
	int      iItfCfgSn;        //�ӿ��������ITF_CFG_SN   INTEGER     9023
	char     szItfId[32+1];   //�ӿڱ�ʶ  ITF_ID       VARCHAR(32) 9027
	char     szItfString[256+1];//�ӿ��ִ�  ITF_STRING   VARCHAR(256)9032
	char     szItfName[32+1]; //�ӿ�����  ITF_NAME     VARCHAR(32) 9033
	char     chItfType;        //�ӿ�����  ITF_TYPE     CHAR(1)     9034�ֵ�[ITF_TYPE]
	char     chItfDataType;    //�ӿ���������ITF_DATA_TYPECHAR(1)     9028�ֵ�[ITF_DATA_TYPE]
	char     chItfDataFlow;    //�ӿ���������ITF_DATA_FLOWCHAR(1)     9029�ֵ�[ITF_DATA_FLOW]
};
//�ӿ���������
struct MATRADEAPI CReqCosChgItfField
{
	char     chOperationType;//��������  OPERATION_TYPECHAR(1)     Y 89870:����
	int      iItfCfgSn;      //�ӿ��������ITF_CFG_SN    INTEGER     Y 9023 �ӿ��������
	char     szItfId[32+1]; //�ӿڱ�ʶ  ITF_ID        VARCHAR(32) Y 9027 �ӿڱ�ʶ
	char     szItfString[256+1];//�ӿ��ִ�  ITF_STRING    VARCHAR(256)Y 9032 �ӿ��ִ�
	char     szItfName[32+1];//�ӿ�����  ITF_NAME      VARCHAR(32) Y 9033 �ӿ�����
	char     chItfType;      //�ӿ�����  ITF_TYPE      CHAR(1)     Y 9034 �ӿ�����
	char     chItfDataType;  //�ӿ���������ITF_DATA_TYPE CHAR(1)     Y 9028 �ӿ���������
	char     chItfDataFlow;  //�ӿ���������ITF_DATA_FLOW CHAR(1)     Y 9029 �ӿ���������
	char     szItfFilePath[256+1];//�ӿ��ļ�·��ITF_FILE_PATH VARCHAR(256)Y 9026 
	char     szItfSyncXa[64+1];//�ӿ�ͬ��XAITF_SYNC_XA   VARCHAR(64) Y 9082 
	char     szItfProcClsid[64+1];//�ӿڴ������ITF_PROC_CLSIDVARCHAR(64) Y 9083 
};

struct MATRADEAPI CRspCosChgItfField
{
};
//�����ɳ���ί�в�ѯ
struct MATRADEAPI CReqCosCanWithdrawOrderField
{
  char     szCuacctCode[16+1];//�ʲ��˻�  CUACCT_CODE BIGINT     Y 8920 
  char     chCuacctType;         //�ʲ��˻�����
	char     szStkbd[2+1];//���װ��  STKBD       CHAR(2)    X 625  
	int      iTrdCodeCls; //Ʒ������  TRD_CODE_CLSINTEGER    X 8970 
	char     szTrdCode[8+1];//Ʒ�ִ���  TRD_CODE    VARCHAR(8) X 48   
	int      iOrderNo;    //ί�б��  ORDER_NO    INTEGER    X 9106 
	int      iOrderBsn;   //ί������  ORDER_BSN   INTEGER    X 66   
	char     szTrdacct[10+1];//�����˻�  TRDACCT     VARCHAR(10)X 448  
	int      iAttrCode;   //���Դ���  ATTR_CODE   SMALLINT   X 9101 
	char     chExeStatus; //ִ��״̬  EXE_STATUS  CHAR(1)    X 9103 
	int      iBgnExeTime; //ִ�п�ʼʱ��BGN_EXE_TIMEINTEGER    X 916  
	char     chQueryFlag; //��ѯ����  QUERY_FLAG  CHAR(1)    Y 90800:���ȡ����1:��ǰȡ��������ȫ������
	char     szQueryPos[32+1];//��λ��   QUERY_POS   VARCHAR(32)X 8991 ���ѯ������ʲ��˻����ʹ��
	int      iQueryNum;   //��ѯ����  QUERY_NUM   INTEGER    Y 8992 ���ֵΪ1000
};

struct MATRADEAPI CRspCosCanWithdrawOrderField
{
	char     szQryPos[32+1];    //��λ��    QRY_POS       VARCHAR(32) 8991
  char     szCuacctCode[16+1];       //�ʲ��˻�   CUACCT_CODE   BIGINT      8920
  char     chCuacctType;         //�ʲ��˻�����
	char     szCustCode[16+1];         //�ͻ�����   CUST_CODE     BIGINT      8902
	char     szTrdacct[10+1];   //�����˻�   TRDACCT       VARCHAR(10) 448 
	char     chExchange;         //������    EXCHANGE      CHAR(1)     207 
	char     szStkbd[2+1];      //���װ��   STKBD         CHAR(2)     625 
	int      iTrdCodeCls;        //Ʒ������   TRD_CODE_CLS  INTEGER     8970
	int      iStkBiz;            //����ҵ��   STK_BIZ       SMALLINT    8842
	int      iStkBizAction;      //ҵ��   STK_BIZ_ACTIONSMALLINT    40  
	char     szTrdCode[8+1];    //Ʒ�ִ���   TRD_CODE      VARCHAR(8)  48  
	int      iOrderDate;         //ί������   ORDER_DATE    INTEGER     8834
	char     szOrderTime[32+1]; //ί��ʱ��   ORDER_TIME    VARCHAR(32) 8845
	int      iOrderBsn;          //ί������   ORDER_BSN     INTEGER     66  
	int      iOrderNo;           //ί�б��   ORDER_NO      INTEGER     9106
	LONGLONG llOrderQty;         //ί������   ORDER_QTY     BIGINT      38  
	char     szOrderPrice[21+1]; //ί�м۸�   ORDER_PRICE   CPRICE      44  
	char     szStopPrice[21+1];  //�����۸�   STOP_PRICE    CPRICE      8975
	int      iValidDate;         //��ֹ����   VALID_DATE    INTEGER     8859
	char     szOrderAttr[256+1];//�߼�����   ORDER_ATTR    VARCHAR(256)9100
	int      iAttrCode;          //���Դ���   ATTR_CODE     SMALLINT    9101
	int      iBgnExeTime;        //ִ�п�ʼʱ�� BGN_EXE_TIME  INTEGER     916 
	int      iEndExeTime;        //ִ�н���ʱ�� END_EXE_TIME  INTEGER     917 
	char     szSpreadName[64+1];//�������   SPREAD_NAME   VARCHAR(64) 8971
	char     szUndlCode[16+1];  //��Ĵ���   UNDL_CODE     VARCHAR(16) 8972
	int      iConExpDate;        //��Լ������  CON_EXP_DATE  INTEGER     8976
	char     szExercisePrice[21+1];//��Ȩ��    EXERCISE_PRICECPRICE      8973
	LONGLONG llConUnit;          //��Լ��λ   CON_UNIT      BIGINT      8974
	char     szCliOrderNo[32+1];//�ͻ���ί�б��CLI_ORDER_NO  VARCHAR(32) 9102
	char     szCliRemark[32+1]; //������Ϣ   CLI_REMARK    VARCHAR(32) 8914
	char     chExeStatus;        //ִ��״̬   EXE_STATUS    CHAR(1)     9103
	char     szExeInfo[128+1];  //ִ����Ϣ   EXE_INFO      VARCHAR(128)9104
	LONGLONG llExeQty;           //ִ������   EXE_QTY       BIGINT      9105
	LONGLONG llMatchedQty;       //�ѳɽ�����  MATCHED_QTY   BIGINT      387 
	LONGLONG llWithdrawnQty;     //�ѳ�������  WITHDRAWN_QTY BIGINT      8837
	char     szMatchedAmt[21+1]; //�ѳɽ����  MATCHED_AMT   CMONEY      8504
};
//�����ɽ���ѯ
struct MATRADEAPI CReqCosMatchField
{
  char     szCuacctCode[16+1];//�ʲ��˻�CUACCT_CODEBIGINT     Y 8920 
  char     chCuacctType;         //�ʲ��˻�����
	char     szStkbd[2+1];//���װ��STKBD      CHAR(2)    X 625  
	char     szTrdCode[8+1];//Ʒ�ִ���TRD_CODE   VARCHAR(8) X 48   
	int      iOrderNo;    //ί�б��ORDER_NO   INTEGER    X 9106 
	int      iOrderBsn;   //ί������ORDER_BSN  INTEGER    X 66   
	char     szTrdacct[10+1];//�����˻�TRDACCT    VARCHAR(10)X 448  
	char     szOptNum[16+1];//��Լ����OPT_NUM    VARCHAR(16)X 9082 
	char     chQueryFlag; //��ѯ����QUERY_FLAG CHAR(1)    Y 90800:���ȡ����
	char     szQueryPos[32+1];//��λ�� QUERY_POS  VARCHAR(32)X 8991 ���ѯ������ʲ��˻����ʹ��
	int      iQueryNum;   //��ѯ����QUERY_NUM  INTEGER    Y 8992 ���ֵΪ1000
};

struct MATRADEAPI CRspCosMatchField
{
	char     szQryPos[32+1];      //��λ��     QRY_POS           VARCHAR(32)8991
	int      iOrderDate;           //ί������    ORDER_DATE        INTEGER    8834
	char     chMatchedType;        //�ɽ�����    MATCHED_TYPE      CHAR(1)    8992
	char     szMatchedSn[16+1];   //�ɽ����    MATCHED_SN        VARCHAR(16)17  
	int      iOrderBsn;            //ί������    ORDER_BSN         INTEGER    66  
	LONGLONG llCliOrderGroupNo;    //��ϱ��    CLI_ORDER_GROUP_NOBIGINT     9301
	char     szClientId[32+1];    //�ͻ�������ʶ  CLIENT_ID         VARCHAR(32)8858
	int      iOrderNo;             //ί�б��    ORDER_NO          INTEGER    9106
	char     szOrderId[10+1];     //��ͬ���    ORDER_ID          VARCHAR(10)11  
  char     szCuacctCode[16+1];         //�ʲ��˻�    CUACCT_CODE       BIGINT     8920
  char     chCuacctType;         //�ʲ��˻�����
	char     szCustCode[16+1];           //�ͻ�����    CUST_CODE         BIGINT     8902
	char     szTrdacct[10+1];     //�����˻�    TRDACCT           VARCHAR(10)448 
	char     chExchange;           //������     EXCHANGE          CHAR(1)    207 
	char     szStkbd[2+1];        //���װ��    STKBD             CHAR(2)    625 
	int      iStkBiz;              //����ҵ��    STK_BIZ           SMALLINT   8842
	int      iStkBizAction;        //ҵ��    STK_BIZ_ACTION    SMALLINT   40  
	char     szTrdCode[8+1];      //Ʒ�ִ���    TRD_CODE          VARCHAR(8) 48  
	LONGLONG llMatchedQty;         //�ѳɽ�����   MATCHED_QTY       BIGINT     387 
	char     szMatchedPrice[21+1]; //�ɽ��۸�    MATCHED_PRICE     CPRICE     8841
	int      iMatchedDate;         //�ɽ�����    MATCHED_DATE      INTEGER    8839
	char     szMatchedTime[8+1];  //�ɽ�ʱ��    MATCHED_TIME      VARCHAR(8) 8840
	int      iSubsys;              //����ϵͳ����  SUBSYS            SMALLINT   9080
	int      iSubsysSn;            //����ϵͳ����  SUBSYS_SN         SMALLINT   8988
	int      iErrorId;             //�������    ERROR_ID          SMALLINT   8900
	char     szErrorMsg[81+1];    //������Ϣ    ERROR_MSG         VARCHAR(81)8901
	char     szBrokerId[11+1];    //���͹�˾����  BROKER_ID         VARCHAR(11)8890
	char     szParticipantId[11+1];//��Ա����    PARTICIPANT_ID    VARCHAR(11)8724
	char     chTradingRole;        //���׽�ɫ    TRADING_ROLE      VARCHAR(1) 8763
	char     szCombOffsetFlag[5+1];//��Ͽ�ƽ��־  COMB_OFFSET_FLAG  VARCHAR(5) 8741
	char     szCombHedgeFlag[5+1];//���Ͷ���ױ���־COMB_HEDGE_FLAG   VARCHAR(5) 8742
	char     chPriceSource;        //�ɽ�����Դ   PRICE_SOURCE      VARCHAR(1) 8765
	char     szTraderId[21+1];    //����������Ա����TRADER_ID         VARCHAR(21)8726
	char     szClearingPartId[11+1];//�����Ա���  CLEARING_PART_ID  VARCHAR(11)8759
	int      iBrokerOrderSeq;      //���͹�˾�������BROKER_ORDER_SEQ  SMALLINT   8746
};
//������ί�в�ѯ
struct MATRADEAPI CReqCosSubOrderField
{
  char     szCuacctCode[16+1];   //�ʲ��˻�CUACCT_CODE   BIGINT     Y 8920 
  char     chCuacctType;         //�ʲ��˻�����
	char     szStkbd[2+1];  //���װ��STKBD         CHAR(2)    X 625  
	char     szTrdCode[8+1];//Ʒ�ִ���TRD_CODE      VARCHAR(8) X 48   
	char     szOptNum[16+1];//��Լ����OPT_NUM       VARCHAR(16)X 9082 
	int      iOrderNo;       //ί�б��ORDER_NO      INTEGER    X 9106 
	int      iOrderBsn;      //ί������ORDER_BSN     INTEGER    X 66   
	char     szTrdacct[10+1];//�����˻�TRDACCT       VARCHAR(10)X 448  
	char     szOrderStatuses[32+1];//ί��״̬ORDER_STATUSESVARCHAR(32)X 39   ����
	char     chQueryFlag;    //��ѯ����QUERY_FLAG    CHAR(1)    Y 90800:���ȡ����
	char     szQueryPos[32+1];//��λ�� QUERY_POS     VARCHAR(32)X 8991 ���ѯ������ʲ��˻����ʹ��
	int      iQueryNum;      //��ѯ����QUERY_NUM     INTEGER    Y 8992 ���ֵΪ1000
};

struct MATRADEAPI CRspCosSubOrderField
{
	char     szQryPos[32+1];     //��λ��     QRY_POS         VARCHAR(32) 8991
	int      iOrderDate;          //ί������    ORDER_DATE      INTEGER     8834
	int      iOrderBsn;           //ί������    ORDER_BSN       INTEGER     66  
	LONGLONG llOrderGroupNo;      //��ϱ��    ORDER_GROUP_NO  BIGINT      9300
	char     szOrderClientId[32+1];//�ͻ�������ʶ  ORDER_CLIENT_ID VARCHAR(32) 9102
	int      iOrderNo;            //ί�б��    ORDER_NO        INTEGER     9106
	int      iSuborderSn;         //�ӵ����    SUBORDER_SN     INTEGER     9107
	char     szOrderId[32+1];    //��ͬ���    ORDER_ID        VARCHAR(32) 11  
	char     chIsWithdraw;        //������־    IS_WITHDRAW     CHAR(1)     8836�ֵ�[IS_WITHDRAW]
	char     chIsWithdrawn;       //�ѳ�����־   IS_WITHDRAWN    CHAR(1)     8838�ֵ�[IS_WITHDRAWN]
	char     szOrderTime[32+1];  //ί��ʱ��    ORDER_TIME      VARCHAR(32) 8845
	int      iExeDate;            //ִ������    EXE_DATE        INTEGER     916 
	char     szExeTime[32+1];    //ִ��ʱ��    EXE_TIME        VARCHAR(32) 917 
	char     szCuacctCode[16+1];        //�ʲ��˻�    CUACCT_CODE     BIGINT      8920
	char     szCustCode[16+1];          //�ͻ�����    CUST_CODE       BIGINT      8902
	char     szTrdacct[10+1];    //�����˻�    TRDACCT         VARCHAR(10) 448 
	char     chExchange;          //������     EXCHANGE        CHAR(1)     207 
	char     szStkbd[2+1];       //���װ��    STKBD           CHAR(2)     625 
	int      iStkBiz;             //����ҵ��    STK_BIZ         SMALLINT    8842
	int      iStkBizAction;       //ҵ��    STK_BIZ_ACTION  SMALLINT    40  
	char     szTrdCode[8+1];     //Ʒ�ִ���    TRD_CODE        VARCHAR(8)  48  
	char     szOptNum[16+1];     //��Լ����    OPT_NUM         VARCHAR(16) 9082
	int      iIntOrg;             //�ڲ�����    INT_ORG         SMALLINT    8911
	LONGLONG llOrderQty;          //ί������    ORDER_QTY       BIGINT      38  
	char     szOrderPrice[21+1];  //ί�м۸�    ORDER_PRICE     CPRICE      44  
	LONGLONG llMatchedQty;        //�ѳɽ�����   MATCHED_QTY     BIGINT      387 
	LONGLONG llWithdrawnQty;      //�ѳ�������   WITHDRAWN_QTY   BIGINT      8837
	char     chOrderStatus;       //ί��״̬    ORDER_STATUS    CHAR(1)     39  
	int      iSubsys;             //����ϵͳ����  SUBSYS          SMALLINT    9080
	int      iSubsysSn;           //����ϵͳ����  SUBSYS_SN       SMALLINT    8988
	char     szExeInfo[128+1];   //ִ����Ϣ    EXE_INFO        VARCHAR(128)9104
	char     chOrderPriceType;    //�����۸�����  ORDER_PRICE_TYPEVARCHAR(1)  8739
	char     szCombOffsetFlag[5+1];//��Ͽ�ƽ��־  COMB_OFFSET_FLAGVARCHAR(5)  8741
	char     szCombHedgeFlag[5+1];//���Ͷ���ױ���־COMB_HEDGE_FLAG VARCHAR(5)  8742
	char     szStopPrice[21+1];   //�����۸�    STOP_PRICE      CPRICE      8975
	int      iFrontId;            //ǰ�ñ��    FRONT_ID        INTEGER     8732
	LONGLONG llSessionId;         //�Ự���    SESSION_ID      BIGINT      8814
	char     szOrderIdEx[64+1];  //�ⲿ��ͬ���  ORDER_ID_EX     VARCHAR(64) 9093
};

//��ʷί�в�ѯ
struct MATRADEAPI CReqCosHisOrderInfoField
{
  char     szCuacctCode[16+1];   //�ʲ��˻�  CUACCT_CODE   BIGINT     Y 8920 
  char     chCuacctType;         //�ʲ��˻�����
	char     szCustCode[16+1];     //�ͻ�����  CUST_CODE     BIGINT     X 8902 
	char     szTrdCode[8+1];//Ʒ�ִ���  TRD_CODE      VARCHAR(8) X 48   
	int      iBgnDate;       //��ʼ����  BGN_DATE      INTEGER    Y 916  
	int      iEndDate;       //��������  END_DATE      INTEGER    Y 917  
	char     szExeStatuses[32+1];//ִ��״̬  EXE_STATUSES  VARCHAR(32)X 9103 ����
	int      iOrderNo;       //ί�б��  ORDER_NO      INTEGER    X 9106 
	char     chQueryFlag;    //��ѯ����  QUERY_FLAG    CHAR(1)    Y 90800:���ȡ����
	char     szQueryPos[32+1];//��λ��   QUERY_POS     VARCHAR(32)X 8991 ���ѯ������ʲ��˻����ʹ��
	int      iQueryNum;      //��ѯ����  QUERY_NUM     INTEGER    Y 8992 ���ֵΪ1000
	char     chModifiedState;//״̬�޸ı�ʶMODIFIED_STATECHAR(1)    X 8899 ���м�״̬�޸�Ϊ����״̬��
};

struct MATRADEAPI CRspCosHisOrderInfoField
{
	char     szQryPos[32+1];    //��λ��    QRY_POS       VARCHAR(32) 8991
  char     szCuacctCode[16+1];       //�ʲ��˻�   CUACCT_CODE   BIGINT      8920
  char     chCuacctType;         //�ʲ��˻�����
	char     szCustCode[16+1];         //�ͻ�����   CUST_CODE     BIGINT      8902
	char     szTrdacct[10+1];   //�����˻�   TRDACCT       VARCHAR(10) 448 
	char     chExchange;         //������    EXCHANGE      CHAR(1)     207 
	char     szStkbd[2+1];      //���װ��   STKBD         CHAR(2)     625 
	int      iTrdCodeCls;        //Ʒ������   TRD_CODE_CLS  INTEGER     8970
	int      iStkBiz;            //����ҵ��   STK_BIZ       SMALLINT    8842
	int      iStkBizAction;      //ҵ��   STK_BIZ_ACTIONSMALLINT    40  
	char     szTrdCode[8+1];    //Ʒ�ִ���   TRD_CODE      VARCHAR(8)  48  
	char     szOptNum[16+1];    //��Լ����   OPT_NUM       VARCHAR(16) 9082
	int      iIntOrg;            //�ڲ�����   INT_ORG       SMALLINT    8911
	int      iOrderDate;         //ί������   ORDER_DATE    INTEGER     8834
	char     szOrderTime[32+1]; //ί��ʱ��   ORDER_TIME    VARCHAR(32) 8845
	int      iOrderBsn;          //ί������   ORDER_BSN     INTEGER     66  
	int      iOrderNo;           //ί�б��   ORDER_NO      INTEGER     9106
	LONGLONG llOrderQty;         //ί������   ORDER_QTY     BIGINT      38  
	char     szOrderPrice[21+1]; //ί�м۸�   ORDER_PRICE   CPRICE      44  
	char     szStopPrice[21+1];  //�����۸�   STOP_PRICE    CPRICE      8975
	int      iValidDate;         //��ֹ����   VALID_DATE    INTEGER     8859
	char     szOrderAttr[256+1];//�߼�����   ORDER_ATTR    VARCHAR(256)9100
	int      iAttrCode;          //���Դ���   ATTR_CODE     SMALLINT    9101
	int      iBgnExeTime;        //ִ�п�ʼʱ�� BGN_EXE_TIME  INTEGER     916 
	int      iEndExeTime;        //ִ�н���ʱ�� END_EXE_TIME  INTEGER     917 
	char     szSpreadName[64+1];//�������   SPREAD_NAME   VARCHAR(64) 8971
	char     szUndlCode[16+1];  //��Ĵ���   UNDL_CODE     VARCHAR(16) 8972
	int      iConExpDate;        //��Լ������  CON_EXP_DATE  INTEGER     8976
	char     szExercisePrice[21+1];//��Ȩ��    EXERCISE_PRICECPRICE      8973
	LONGLONG llConUnit;          //��Լ��λ   CON_UNIT      BIGINT      8974
	char     szCliOrderNo[32+1];//�ͻ���ί�б��CLI_ORDER_NO  VARCHAR(32) 9102
	char     szCliRemark[32+1]; //������Ϣ   CLI_REMARK    VARCHAR(32) 8914
	char     chExeStatus;        //ִ��״̬   EXE_STATUS    CHAR(1)     9103
	char     szExeInfo[128+1];  //ִ����Ϣ   EXE_INFO      VARCHAR(128)9104
	LONGLONG llExeQty;           //ִ������   EXE_QTY       BIGINT      9105
	LONGLONG llMatchedQty;       //�ѳɽ�����  MATCHED_QTY   BIGINT      387 
	LONGLONG llWithdrawnQty;     //�ѳ�������  WITHDRAWN_QTY BIGINT      8837
	char     szMatchedAmt[21+1]; //�ѳɽ����  MATCHED_AMT   CMONEY      8504
};

//-------------------------------10388357:��ʷ�ɽ���ѯ--------------------------
struct MATRADEAPI CReqCosHisFillInfoField
{
  char            szCuacctCode[16 + 1];       // �ʲ��˻� 
  char            szStkbd[2 + 1];             // ���װ�� 
  char            chCuacctType;               // �˻����� 
  char            szTrdCode[30 + 1];          // Ʒ�ִ��� 
  int             iBgnDate;                   // ��ʼ���� 
  int             iEndDate;                   // �������� 
  int             iOrderNo;                   // ί�б�� 
  int             iOrderBsn;                  // ί������ 
  char            szTrdacct[32 + 1];          // �����˻� 
  char            szOptNum[16 + 1];           // ��Լ���� 
  char            chQueryFlag;                // ��ѯ���� 0:���ȡ���� 1:��ǰȡ����
  char            szQueryPos[32 + 1];         // ��λ�� 
  int             iQueryNum;                  // ��ѯ���� ���ֵΪ1000
};

struct MATRADEAPI CRspCosHisFillInfoField
{
  char            szQryPos[32 + 1];           // ��λ�� 
  int             iOrderDate;                 // ί������ 
  char            chMatchedType;              // �ɽ����� 
  char            szMatchedSn[16 + 1];        // �ɽ���� 
  int             iOrderBsn;                  // ί������ 
  LONGLONG        llCliOrderGroupNo;          // ��ϱ�� 
  char            szClientId[32 + 1];         // �ͻ�������ʶ 
  int             iOrderNo;                   // ί�б�� 
  char            szOrderId[21 + 1];          // ��ͬ��� 
  char            szCuacctCode[16 + 1];       // �ʲ��˻� 
  char            chCuacctType;               // �˻����� 
  char            szCustCode[16 + 1];         // �ͻ����� 
  char            szTrdacct[32 + 1];          // �����˻� 
  char            chExchange;                 // ������ 
  char            szStkbd[2 + 1];             // ���װ�� 
  int             iStkBiz;                    // ����ҵ�� 
  int             iStkBizAction;              // ҵ�� 
  char            szTrdCode[30 + 1];          // Ʒ�ִ��� 
  LONGLONG        llMatchedQty;               // �ѳɽ����� 
  char            szMatchedPrice[21 + 1];     // �ɽ��۸� 
  int             iMatchedDate;               // �ɽ����� 
  char            szMatchedTime[8 + 1];       // �ɽ�ʱ�� 
  int             iSubsys;                    // ����ϵͳ���� 
  int             iSubsysSn;                  // ����ϵͳ���� 
  int             iErrorId;                   // ������� 
  char            szErrorMsg[81 + 1];         // ������Ϣ 
  char            szBrokerId[11 + 1];         // ���͹�˾���� 
  char            szParticipantId[11 + 1];    // ��Ա���� 
  char            chTradingRole;              // ���׽�ɫ 
  char            szCombOffsetFlag[5 + 1];    // ��Ͽ�ƽ��־ 
  char            szCombHedgeFlag[5 + 1];     // ���Ͷ���ױ���־ 
  char            chPriceSource;              // �ɽ�����Դ 
  char            szTraderId[21 + 1];         // ����������Ա���� 
  char            szClearingPartId[11 + 1];   // �����Ա��� 
  int             iBrokerOrderSeq;            // ���͹�˾������� 
};

//���ί�в�ѯ
struct MATRADEAPI CReqCosCombOrderInfoField
{
  char     szCuacctCode[16+1];  //�ʲ��˻�CUACCT_CODE   BIGINT     Y 8920 
  char     chCuacctType;         //�ʲ��˻�����
	int      iOrderBsn;     //ί������ORDER_BSN     INTEGER    X 66   
	LONGLONG llOrderGroupNo;//��ϱ��ORDER_GROUP_NOBIGINT     X 9300 
	char     szExeStatuses[32+1];//ִ��״̬EXE_STATUSES  VARCHAR(32)X 9103 ���� 
	char     chQueryFlag;   //��ѯ����QUERY_FLAG    CHAR(1)    Y 90800:���ȡ����1:��ǰȡ��������ȫ������
	char     szQueryPos[32+1];//��λ�� QUERY_POS     VARCHAR(32)X 8991 ���ѯ������ʲ��˻����ʹ��
	int      iQueryNum;     //��ѯ����QUERY_NUM     INTEGER    Y 8992 ���ֵΪ1000
};

struct MATRADEAPI CRspCosCombOrderInfoField
{
	int      iOrderBsn;               //ί������    ORDER_BSN            INTEGER     66  
	LONGLONG llOrderGroupNo;          //��ϱ��    ORDER_GROUP_NO       BIGINT      9300
	char     szCliOrderGroupNo[32+1];//��ϱ��(�ͻ�)CLI_ORDER_GROUP_NO   VARCHAR(32) 9301
	char     szOrderGroupType[32+1]; //�������    ORDER_GROUP_TYPE     VARCHAR(32) 9306
	LONGLONG llOrderGroupParentNo;    //����ϱ��   ORDER_GROUP_PARENT_NOBIGINT      9302
	LONGLONG llOrderParentNo;         //��ί�б��   ORDER_PARENT_NO      BIGINT      9304
	char     chExeStatus;             //ִ��״̬    EXE_STATUS           CHAR(1)     9103
	int      iOrderDate;              //ί������    ORDER_DATE           INTEGER     8834
	char     szOrderTime[32+1];      //ί��ʱ��    ORDER_TIME           VARCHAR(32) 8845
	int      iOrderValidDate;         //��Ч����    ORDER_VALID_DATE     INTEGER     8859
	char     szCustCode[16+1];              //�ͻ�����    CUST_CODE            BIGINT      8902
  char     szCuacctCode[16+1];            //�ʲ��˻�    CUACCT_CODE          BIGINT      8920
	int      iTrdDate;                //��������    TRD_DATE             INTEGER     8844
	char     szRemark[128+1];        //��ע��Ϣ    REMARK               VARCHAR(128)8914
	char     szQueryPos[32+1];       //��ѯ��λ��   QUERY_POS            VARCHAR(32) 8991
};
//�ʲ��û���ѯ
struct MATRADEAPI CReqCosCuacctCodeInfoField
{
  char     szCuacctCode[16+1];//�ʲ��˻�CUACCT_CODEBIGINT  X 8920  
  char     chCuacctType;         //�ʲ��˻�����
	char     szCustCode[16+1];  //�ͻ�����CUST_CODE  BIGINT  X 8902  
	int      iSubsys;     //��ϵͳ SUBSYS     SMALLINTX 908081:֤ȯ�ֻ�����ϵͳ 82:������Ȩ����ϵͳ 83:��ָ�ڻ�����ϵͳ
	LONGLONG llQueryPos;  //��λ�� QUERY_POS  BIGINT  Y 8991  ���ʲ��˻���Ϊ��λ��
	int      iQueryNum;   //��ѯ����QUERY_NUM  INTEGER Y 8992  �������10000
};

struct MATRADEAPI CRspCosCuacctCodeInfoField
{
	int      iSubsys;            //��ϵͳ   SUBSYS         SMALLINT   9080
	LONGLONG llSubsysSn;         //��ϱ��  SUBSYS_SN      BIGINT     9300
	char     szLastLoginTime[32+1];//����¼ʱ��LAST_LOGIN_TIMEVARCHAR(32)9901
	char     szCustCode[16+1];         //�ͻ�����  CUST_CODE      BIGINT     8902
	char     szCuacctCode[16+1];       //�ʲ��˻�  CUACCT_CODE    BIGINT     8920
	int      iNodeIdNow;         //�ֽڵ��� NODE_ID_NOW    INTEGER    9082
	int      iNodeIdOrg;         //ԭ�ڵ��� NODE_ID_ORG    INTEGER    9081
};

//�ڵ��˻���ѯ
struct MATRADEAPI CReqCosNodeUsersField
{
	LONGLONG llQueryPos;//��λ�� QUERY_POSBIGINT Y 8991���ʲ��˻���Ϊ��λ��
	int      iQueryNum; //��ѯ����QUERY_NUMINTEGERY 8992�������10000
};

struct MATRADEAPI CRspCosNodeUsersField
{
	char     szCuacctCode[16+1];    //�ʲ��˻� CUACCT_CODEBIGINT  8920
	char     szCustCode[16+1];      //�ͻ����� CUST_CODE  BIGINT  8902
	int      iSubsys;         //��ϵͳ  SUBSYS     SMALLINT9080
	int      iSubsysSn;       //��ϵͳ����SUBSYS_SN  SMALLINT8988
	int      iNodeIdOrg;      //ԭ�ڵ���NODE_ID_ORGINTEGER 9081
	int      iNodeIdNow;      //�ֽڵ���NODE_ID_NOWINTEGER 9082
};

//-------------------------------10388352:�������ί�б�Ų�ѯ���ί��--------------------------
struct MATRADEAPI CReqCosCombOrderInfoExField
{
  int             iOrderDate;                 // ί������ 
  int             iOrderBsn;                  // ί������ 
  LONGLONG        llOrderGroupNo;             // ��ϱ�� 
  char            szCuacctCode[16 + 1];       // �ʲ��˻� 
  char            chCuacctType;               // �˻����� 
};

struct MATRADEAPI CRspCosCombOrderInfoExField
{
  LONGLONG        llOrderGroupNo;             // ��ϱ�� 
  char            szCuacctCode[16 + 1];       // �ʲ��˻� 
  char            szCustCode[16 + 1];         // �ͻ����� 
  char            szTrdacct[32 + 1];          // �����˻� 
  char            chExchange;                 // ������ 
  char            szStkbd[2 + 1];             // ���װ�� 
  char            chCuacctType;               // �˻����� 
  int             iStkBiz;                    // ����ҵ�� 
  int             iStkBizAction;              // ҵ�� 
  char            szTrdCode[30 + 1];          // Ʒ�ִ��� 
  char            szOptNum[16 + 1];           // ��Լ���� 
  int             iIntOrg;                    // �ڲ����� 
  int             iOrderDate;                 // ί������ 
  char            szOrderTime[32 + 1];        // ί��ʱ�� 
  int             iOrderBsn;                  // ί������ 
  int             iOrderNo;                   // ί�б�� 
  LONGLONG        llOrderQty;                 // ί������ 
  char            szOrderPrice[21 + 1];       // ί�м۸� 
  char            szStopPrice[21 + 1];        // �����۸� 
  int             iValidDate;                 // ��ֹ���� 
  char            szOrderAttr[256 + 1];       // �߼����� 
  int             iAttrCode;                  // ���Դ��� 
  int             iBgnExeTime;                // ִ�п�ʼʱ�� 
  int             iEndExeTime;                // ִ�н���ʱ�� 
  char            szUndlCode[16 + 1];         // ��Ĵ��� 
  int             iConExpDate;                // ��Լ������ 
  char            szExercisePrice[21 + 1];    // ��Ȩ�� 
  LONGLONG        llConUnit;                  // ��Լ��λ 
  char            szCliOrderNo[32 + 1];       // �ͻ���ί�б�� 
  char            szCliRemark[256 + 1];       // ������Ϣ 
  char            chExeStatus;                // ִ��״̬ 
  char            szExeInfo[128 + 1];         // ִ����Ϣ 
  LONGLONG        llExeQty;                   // ִ������ 
  LONGLONG        llMatchedQty;               // �ѳɽ����� 
  LONGLONG        llWithdrawnQty;             // �ѳ������� 
  char            szMatchedAmt[21 + 1];       // �ѳɽ���� 
  char            szUpdateTime[32 + 1];       // ����޸�ʱ�� 
};

//���鴦�����
struct MATRADEAPI CReqCosSnapshotField
{
	char     chExchange;     //������   EXCHANGE       CHAR(1)    Y 207 
	char     szTrdCode[16+1];//���״���  TRD_CODE       VARCHAR(16)Y 48  
	LONGLONG llTrdDate;      //��������  TRD_DATE       BIGINT     Y 8844
	LONGLONG llDataTime;     //����ʱ��  DATA_TIME      BIGINT     Y 8816
	char     chStatus;       //Ʒ��״̬  STATUS         CHAR(1)    Y 326 
	LONGLONG llPreClosePrice;//�����̼�  PRE_CLOSE_PRICEBIGINT     Y 140 
	LONGLONG llOpenPrice;    //���̼�   OPEN_PRICE     BIGINT     Y 8957
	LONGLONG llHighPrice;    //��߼�   HIGH_PRICE     BIGINT     Y 8983
	LONGLONG llLowPrice;     //��ͼ�   LOW_PRICE      BIGINT     Y 8984
	LONGLONG llCurPrice;     //���¼�   CUR_PRICE      BIGINT     Y 8958
	LONGLONG llAns1Price;     //������1  ANS1_PRICE     BIGINT     Y 9080
	LONGLONG llAns2Price;     //������2  ANS2_PRICE     BIGINT     Y 9081
	LONGLONG llAns3Price;     //������3  ANS3_PRICE     BIGINT     Y 9082
	LONGLONG llAns4Price;     //������4  ANS4_PRICE     BIGINT     Y 9083
	LONGLONG llAns5Price;     //������5  ANS5_PRICE     BIGINT     Y 9084
	LONGLONG llAns6Price;     //������6  ANS6_PRICE     BIGINT     X 9085
	LONGLONG llAns7Price;     //������7  ANS7_PRICE     BIGINT     X 9086
	LONGLONG llAns8Price;     //������8  ANS8_PRICE     BIGINT     X 9087
	LONGLONG llAns9Price;     //������9  ANS9_PRICE     BIGINT     X 9088
	LONGLONG llAns10Price;     //������10 ANS10_PRICE    BIGINT     X 9089
	LONGLONG llAns1Vol;       //������1  ANS1_VOL       BIGINT     Y 9090
	LONGLONG llAns2Vol;       //������2  ANS2_VOL       BIGINT     Y 9091
	LONGLONG llAns3Vol;       //������3  ANS3_VOL       BIGINT     Y 9092
	LONGLONG llAns4Vol;       //������4  ANS4_VOL       BIGINT     Y 9093
	LONGLONG llAns5Vol;       //������5  ANS5_VOL       BIGINT     Y 9094
	LONGLONG llAns6Vol;       //������6  ANS6_VOL       BIGINT     X 9095
	LONGLONG llAns7Vol;       //������7  ANS7_VOL       BIGINT     X 9096
	LONGLONG llAns8Vol;       //������8  ANS8_VOL       BIGINT     X 9097
	LONGLONG llAns9Vol;       //������9  ANS9_VOL       BIGINT     X 9098
	LONGLONG llAns10Vol;       //������10 ANS10_VOL      BIGINT     X 9099
	LONGLONG llBid1Price;     //�����1  BID1_PRICE     BIGINT     Y 9180
	LONGLONG llBid2Price;     //�����2  BID2_PRICE     BIGINT     Y 9181
	LONGLONG llBid3Price;     //�����3  BID3_PRICE     BIGINT     Y 9182
	LONGLONG llBid4Price;     //�����4  BID4_PRICE     BIGINT     Y 9183
	LONGLONG llBid5Price;     //�����5  BID5_PRICE     BIGINT     Y 9184
	LONGLONG llBid6Price;     //�����6  BID6_PRICE     BIGINT     X 9185
	LONGLONG llBid7Price;     //�����7  BID7_PRICE     BIGINT     X 9186
	LONGLONG llBid8Price;     //�����8  BID8_PRICE     BIGINT     X 9187
	LONGLONG llBid9Price;     //�����9  BID9_PRICE     BIGINT     X 9188
	LONGLONG llBid10Price;     //�����10 BID10_PRICE    BIGINT     X 9189
	LONGLONG llBid1Vol;       //������1  BID1_VOL       BIGINT     Y 9190
	LONGLONG llBid2Vol;       //������2  BID2_VOL       BIGINT     Y 9191
	LONGLONG llBid3Vol;       //������3  BID3_VOL       BIGINT     Y 9192
	LONGLONG llBid4Vol;       //������4  BID4_VOL       BIGINT     Y 9193
	LONGLONG llBid5Vol;       //������5  BID5_VOL       BIGINT     Y 9194
	LONGLONG llBid6Vol;       //������6  BID6_VOL       BIGINT     X 9195
	LONGLONG llBid7Vol;       //������7  BID7_VOL       BIGINT     X 9196
	LONGLONG llBid8Vol;       //������8  BID8_VOL       BIGINT     X 9197
	LONGLONG llBid9Vol;       //������9  BID9_VOL       BIGINT     X 9198
	LONGLONG llBid10Vol;       //������10 BID10_VOL      BIGINT     X 9199
	int      iMatchedCnt;    //�ɽ�����  MATCHED_CNT    SMALLINT   Y 561 
	LONGLONG llMatchedVol;   //�ɽ�����  MATCHED_VOL    BIGINT     Y 387 
	LONGLONG llMatchedAmtTot;//�ɽ��ܽ�� MATCHED_AMT_TOTBIGINT     Y 8504
	LONGLONG llBidVolTot;    //��������  BID_VOL_TOT    BIGINT     Y 38  
	LONGLONG llAnsVolTot;    //��������  ANS_VOL_TOT    BIGINT     Y 8980
	LONGLONG llBidPriceAvg;  //ƽ��ί��۸�BID_PRICE_AVG  BIGINT     Y 8981
	LONGLONG llAnsPriceAvg;  //ƽ��ί���۸�ANS_PRICE_AVG  BIGINT     Y 8982
	LONGLONG llIopv;         //IOPV  IOPV           BIGINT     Y 8967
	LONGLONG llYield;        //���������� YIELD          BIGINT     Y 8985
	LONGLONG llHighLmtPrice; //��ͣ��   HIGH_LMT_PRICE BIGINT     Y 8519
	LONGLONG llLowLmtPrice;  //��ͣ��   LOW_LMT_PRICE  BIGINT     Y 8520
	char     szStkPrefix[32+1];//֤ȯǰ׺  STK_PREFIX     VARCHAR(32)Y 8988
	LONGLONG llPreOpenVol;   //��ֲ���  PRE_OPEN_VOL   BIGINT     Y 8989
	LONGLONG llSettPrice;    //������  SETT_PRICE     BIGINT     Y 8841
	LONGLONG llPreDelta;     //����ʵ��  PRE_DELTA      BIGINT     Y 8990
	LONGLONG llCurrDelta;    //����ʵ��  CURR_DELTA     BIGINT     Y 8991
	int      iNsyl1;          //��ӯ��1  NSYL1          SMALLINT   Y 9200
	int      iNsyl2;          //��ӯ��2  NSYL2          SMALLINT   Y 9201
	int      iNsd;           //����2   NSD2           SMALLINT   Y 9203
	LONGLONG llOpenVol;      //�ֲ�����  OPEN_VOL       BIGINT     Y 9204
	LONGLONG llPreSettPrice; //������  PRE_SETT_PRICE BIGINT     Y 9205
	LONGLONG llClosePrice;   //������   CLOSE_PRICE    BIGINT     Y 9206
};

struct MATRADEAPI CRspCosSnapshotField
{
};

//����طŹ���
struct MATRADEAPI CReqCosReplayField
{
	char     chPlayCtrl;    //���ſ���  PLAY_CTRL     CHAR(1)     Y 9080��0����ֹͣ���� ��1������ʼ����
	int      iTrdDate;      //��������  TRD_DATE      INTEGER     X 8844Ĭ�ϵ�ǰ����
	int      iBgnTime;      //��ʼʱ��  BGN_TIME      INTEGER     X 916 ������Ĭ�ϴ��ļ���ͷ��ʼ
	int      iEndTime;      //����ʱ��  END_TIME      INTEGER     X 917 ������Ĭ�϶����ļ�����
	char     chPlayBackType;//�ط�����  PLAY_BACK_TYPECHAR(1)     X 8996��0��- ��ʱ�����طţ�����ֵ������
	int      iPlayInterval; //�ط�ʱ����PLAY_INTERVAL INTEGER     X 9081���ŵ�λ����ʱ���ļ��ʱ��(PLAY_INTERVAL�Ժ���Ϊ��λ)
	char     szStkCode[128+1];//��Ʊ����  STK_CODE      VARCHAR(128)X 48  ������������ö��ţ������ָ��000001,000002,000003��.
};

struct MATRADEAPI CRspCosReplayField
{
};
//��������ѯί��
struct MATRADEAPI CReqCosMktDataInfoField
{
	char     chExchange; //������ EXCHANGE  CHAR(1)    X 207  
	char     szTrdCode[8+1];//Ʒ�ִ���TRD_CODE  VARCHAR(8) X 48   
	char     chQueryFlag;//��ѯ����QUERY_FLAGCHAR(1)    X 90800:���ȡ����1:��ǰȡ��������ȫ������
	char     szQueryPos[32+1];//��λ�� QUERY_POS VARCHAR(32)X 8991 ���ѯ������ʲ��˻����ʹ��
	int      iQueryNum;  //��ѯ����QUERY_NUM INTEGER    X 8992 ���ֵΪ100
};

struct MATRADEAPI CRspCosMktDataInfoField
{
	char     chExchange;         //������   EXCHANGE       CHAR(1)    207 
	char     szTrdCode[16+1];   //Ʒ�ִ���  TRD_CODE       VARCHAR(16)48  
	int      iTrdDate;           //��������  TRD_DATE       INTEGER    8844
	LONGLONG llDataTime;         //����ʱ��  DATA_TIME      BIGINT     8816
	char     chStatus;           //Ʒ��״̬  STATUS         CHAR(1)    326 
	LONGLONG llPreClosePrice;    //�����̼�  PRE_CLOSE_PRICEBIGINT     140 
	LONGLONG llOpenPrice;        //���̼�   OPEN_PRICE     BIGINT     8957
	LONGLONG llHighPrice;        //��߼�   HIGH_PRICE     BIGINT     8983
	LONGLONG llLowPrice;         //��ͼ�   LOW_PRICE      BIGINT     8984
	LONGLONG llCurPrice;         //���¼�   CUR_PRICE      BIGINT     8958
	LONGLONG llAns1Price;        //������1  ANS1_PRICE     BIGINT     9080
	LONGLONG llAns2Price;        //������2  ANS2_PRICE     BIGINT     9081
	LONGLONG llAns3Price;        //������3  ANS3_PRICE     BIGINT     9082
	LONGLONG llAns4Price;        //������4  ANS4_PRICE     BIGINT     9083
	LONGLONG llAns5Price;        //������5  ANS5_PRICE     BIGINT     9084
	LONGLONG llAns6Price;        //������6  ANS6_PRICE     BIGINT     9085
	LONGLONG llAns7Price;        //������7  ANS7_PRICE     BIGINT     9086
	LONGLONG llAns8Price;        //������8  ANS8_PRICE     BIGINT     9087
	LONGLONG llAns9Price;        //������9  ANS9_PRICE     BIGINT     9088
	LONGLONG llAns10Price;       //������10 ANS10_PRICE    BIGINT     9089
	LONGLONG llAns1Vol;          //������1  ANS1_VOL       BIGINT     9090
	LONGLONG llAns2Vol;          //������2  ANS2_VOL       BIGINT     9091
	LONGLONG llAns3Vol;          //������3  ANS3_VOL       BIGINT     9092
	LONGLONG llAns4Vol;          //������4  ANS4_VOL       BIGINT     9093
	LONGLONG llAns5Vol;          //������5  ANS5_VOL       BIGINT     9094
	LONGLONG llAns6Vol;          //������6  ANS6_VOL       BIGINT     9095
	LONGLONG llAns7Vol;          //������7  ANS7_VOL       BIGINT     9096
	LONGLONG llAns8Vol;          //������8  ANS8_VOL       BIGINT     9097
	LONGLONG llAns9Vol;          //������9  ANS9_VOL       BIGINT     9098
	LONGLONG llAns10Vol;         //������10 ANS10_VOL      BIGINT     9099
	LONGLONG llBid1Price;        //�����1  BID1_PRICE     BIGINT     9180
	LONGLONG llBid2Price;        //�����2  BID2_PRICE     BIGINT     9181
	LONGLONG llBid3Price;        //�����3  BID3_PRICE     BIGINT     9182
	LONGLONG llBid4Price;        //�����4  BID4_PRICE     BIGINT     9183
	LONGLONG llBid5Price;        //�����5  BID5_PRICE     BIGINT     9184
	LONGLONG llBid6Price;        //�����6  BID6_PRICE     BIGINT     9185
	LONGLONG llBid7Price;        //�����7  BID7_PRICE     BIGINT     9186
	LONGLONG llBid8Price;        //�����8  BID8_PRICE     BIGINT     9187
	LONGLONG llBid9Price;        //�����9  BID9_PRICE     BIGINT     9188
	LONGLONG llBid10Price;       //�����10 BID10_PRICE    BIGINT     9189
	LONGLONG llBid1Vol;          //������1  BID1_VOL       BIGINT     9190
	LONGLONG llBid2Vol;          //������2  BID2_VOL       BIGINT     9191
	LONGLONG llBid3Vol;          //������3  BID3_VOL       BIGINT     9192
	LONGLONG llBid4Vol;          //������4  BID4_VOL       BIGINT     9193
	LONGLONG llBid5Vol;          //������5  BID5_VOL       BIGINT     9194
	LONGLONG llBid6Vol;          //������6  BID6_VOL       BIGINT     9195
	LONGLONG llBid7Vol;          //������7  BID7_VOL       BIGINT     9196
	LONGLONG llBid8Vol;          //������8  BID8_VOL       BIGINT     9197
	LONGLONG llBid9Vol;          //������9  BID9_VOL       BIGINT     9198
	LONGLONG llBid10Vol;         //������10 BID10_VOL      BIGINT     9199
	int      iMatchedCnt;        //�ɽ�����  MATCHED_CNT    SMALLINT   561 
	LONGLONG llMatchedVol;       //�ɽ�����  MATCHED_VOL    BIGINT     387 
	LONGLONG llMatchedAmtTot;    //�ɽ��ܽ�� MATCHED_AMT_TOTBIGINT     8504
	LONGLONG llBidVolTot;        //��������  BID_VOL_TOT    BIGINT     38  
	LONGLONG llAnsVolTot;        //��������  ANS_VOL_TOT    BIGINT     8980
	LONGLONG llBidPriceAvg;      //ƽ��ί��۸�BID_PRICE_AVG  BIGINT     8981
	LONGLONG llAnsPriceAvg;      //ƽ��ί���۸�ANS_PRICE_AVG  BIGINT     8982
	LONGLONG llIopv;             //IOPV  IOPV           BIGINT     8967
	LONGLONG llYield;            //���������� YIELD          BIGINT     8985
	LONGLONG llHighLmtPrice;     //��ͣ��   HIGH_LMT_PRICE BIGINT     8519
	LONGLONG llLowLmtPrice;      //��ͣ��   LOW_LMT_PRICE  BIGINT     8520
	char     szStkPrefix[32+1]; //֤ȯǰ׺  STK_PREFIX     VARCHAR(32)8988
	LONGLONG llPreOpenVol;       //��ֲ���  PRE_OPEN_VOL   BIGINT     8989
	LONGLONG llSettPrice;        //������  SETT_PRICE     BIGINT     8841
	LONGLONG llPreDelta;         //����ʵ��  PRE_DELTA      BIGINT     8990
	LONGLONG llCurrDelta;        //����ʵ��  CURR_DELTA     BIGINT     8991
	int      iNsyl1;              //��ӯ��1  NSYL1          SMALLINT   9200
	int      iNsyl2;              //��ӯ��2  NSYL2          SMALLINT   9201
	int      iNsd;               //����2   NSD2           SMALLINT   9203
	LONGLONG llOpenVol;          //�ֲ�����  OPEN_VOL       BIGINT     9204
	LONGLONG llPreSettPrice;     //������  PRE_SETT_PRICE BIGINT     9205
	LONGLONG llClosePrice;       //������   CLOSE_PRICE    BIGINT     9206
};
//�����¼����
struct MATRADEAPI CReqCosRecordMktDataField
{
	char     chRecCtrl;//��¼����REC_CTRLCHAR(1)     Y 9080��0��-ֹͣ��¼�� ��1��- ��ʼ��¼
	int      iTrdDate; //��������TRD_DATEINTEGER     X 8844Ĭ�ϵ�ǰ������
	int      iBgnTime; //��ʼʱ��BGN_TIMEINTEGER     X 916 Ĭ�ϵ�ǰʱ��
	int      iEndTime; //����ʱ��END_TIMEINTEGER     X 917 Ĭ�Ͻ����ս���
	char     szStkCode[128+1];//��Ʊ����STK_CODEVARCHAR(128)X 48  ��¼��������ö��ţ������ָ��000001,000002,000003��.
};

struct MATRADEAPI CRspCosRecordMktDataField
{
};
struct MATRADEAPI CReqCosReplayInfoField
{
	LONGLONG llTrdDate;//��������TRD_DATEBIGINTX 8844Ĭ�ϵ�ǰ������
};

struct MATRADEAPI CRspCosReplayInfoField
{
	char     chPlayStatus;     //�ط�״̬  PLAY_STATUS  CHAR(1)9080��0��δ��ʼ ��1�������С�2������ɡ�3����ȡ��
	LONGLONG llMktTotalNum;    //��������  MKT_TOTAL_NUMBIGINT 9081
	LONGLONG llMktCurNum;      //�Ѳ���   MKT_CUR_NUM  BIGINT 9082
	int      iMktCurTime;      //��ǰ����ʱ��MKT_CUR_TIME INTEGER9083
};
//��ʷ�����ѯί��
struct MATRADEAPI CReqCosHisMktDataField
{
	char     chExchange;   //������   EXCHANGE     CHAR(1)   Y 207 
	char     szTrdCode[8+1];//Ʒ�ִ���  TRD_CODE     VARCHAR(8)Y 48  
	int      iTrdDate;     //��������  TRD_DATE     INTEGER   X 8844Ĭ��Ϊ����
	LONGLONG llDataBegTime;//���鿪ʼʱ��DATA_BEG_TIMEBIGINT    X 8816
	LONGLONG llDataEndTime;//�������ʱ��DATA_END_TIMEBIGINT    X 8817
};

struct MATRADEAPI CRspCosHisMktDataField
{
	char     chExchange;    //������ EXCHANGE CHAR(1)    207 
	char     szTrdCode[16+1];//Ʒ�ִ���TRD_CODE VARCHAR(16)48  
	int      iTrdDate;      //��������TRD_DATE INTEGER    8844
	LONGLONG llDataTime;    //����ʱ��DATA_TIMEBIGINT     8816
	LONGLONG llCurPrice;    //���¼� CUR_PRICEBIGINT     8958
};

//����ͬ��
struct MATRADEAPI CReqCosSyncField
{
	int      iItfCfgSn;    //�ӿ��������ITF_CFG_SN   INTEGERY 9023�ӿ��������
	char     chItfDataType;//�ӿ���������ITF_DATA_TYPECHAR(1)Y 9028�ӿ���������
	char     chItfDataFlow;//�ӿ���������ITF_DATA_FLOWCHAR(1)Y 9029�ӿ���������
};

struct MATRADEAPI CRspCosSyncField
{
};
//�ʲ��˻�����
struct MATRADEAPI CReqCosOpenAccountField
{
	char     szCustCode[16+1];  //�ͻ����� CUST_CODE  BIGINT  Y 8902
  char     szCuacctCode[16+1];//�ʲ��˻� CUACCT_CODEBIGINT  Y 8920
	int      iSubsys;     //��ϵͳ  SUBSYS     SMALLINTY 9080
	int      iSubsysSn;   //��ϵͳ���SUBSYS_SN  SMALLINTY 8988
};

struct MATRADEAPI CRspCosOpenAccountField
{
	char     szCuacctCode[16+1];    //�ʲ��˻� CUACCT_CODEBIGINT  8920
	int      iNodeIdNow;      //���������NODE_ID_NOWINTEGER 9082
	int      iSubsysSn;       //��ϵͳ���SUBSYS_SN  SMALLINT8988
};

//�ʲ��˻�����
struct MATRADEAPI CReqCosCloseAccountField
{
  char     szCuacctCode[16+1];//�ʲ��˻�CUACCT_CODEBIGINTY 8920
};

struct MATRADEAPI CRspCosCloseAccountField
{
	char     szCuacctCode[16+1];    //�ʲ��˻� CUACCT_CODEBIGINT 8920
	int      iNodeIdNow;      //�ֽڵ���NODE_ID_NOWINTEGER9082
};

//�ʽ�ͬ��
struct MATRADEAPI CReqCosFundSyncField
{
};

struct MATRADEAPI CRspCosFundSyncField
{
	char     chTaskStatus;     //ִ��״̬TASK_STATUS  CHAR(1)     9000
	int      iTaskSchedule;    //ִ�н���TASK_SCHEDULEINTEGER     9001
	int      iErrorId;         //�������ERROR_ID     SMALLINT    8900
	char     szErrorMsg[256+1];//������ϢERROR_MSG    VARCHAR(256)8901
};
//�ɷ�ͬ��
struct MATRADEAPI CReqCosStkSyncField
{
};

struct MATRADEAPI CRspCosStkSyncField
{
	char     chTaskStatus;     //ִ��״̬TASK_STATUS  CHAR(1)     9000
	int      iTaskSchedule;    //ִ�н���TASK_SCHEDULEINTEGER     9001
	int      iErrorId;         //�������ERROR_ID     SMALLINT    8900
	char     szErrorMsg[256+1];//������ϢERROR_MSG    VARCHAR(256)8901
};
//��������
struct MATRADEAPI CReqCosCutoffField
{
	int      iTrdDate;//��������TRD_DATEINTEGERY 8844
};

struct MATRADEAPI CRspCosCutoffField
{
	char     chTaskStatus;     //ִ��״̬TASK_STATUS  CHAR(1)     9000
	int      iTaskSchedule;    //ִ�н���TASK_SCHEDULEINTEGER     9001
	int      iErrorId;         //�������ERROR_ID     SMALLINT    8900
	char     szErrorMsg[256+1];//������ϢERROR_MSG    VARCHAR(256)8901
};

//�ɽ��ر�
//�ɽ���Ϣ��������: 
//  1.����ί�еĳɽ���Ϣ
// 	2.�����������ĳɽ���Ϣ��ί�����걨����������
// 	3.�ڲ������ĳɽ���Ϣ��ί��δ�걨����������
// 	4.�Ƿ�ί�еĳ����ɽ���Ϣ��ί�б��������ܾ���
struct MATRADEAPI CRtnOrderField
{
  char            szMatchedSn[16 + 1];        // �ɽ���� 
  char            chStkex;                    // �����г� �ֵ�[STKEX]
  char            szStkCode[8 + 1];           // ֤ȯ���� 
  char            szOrderId[10 + 1];          // ��ͬ��� 
  char            szTrdacct[16 + 1];          // �����˻� 
  LONGLONG        llMatchedQty;               // ���γɽ����� �����ɽ�ʱ��Ϊ����
  char            szMatchedPrice[21 + 1];     // ���γɽ��۸� �۹�ί�з��ظ۱�
  char            szOrderFrzAmt[21 + 1];      // ί�ж����� �۹�ί�з��ظ۱�
  char            szRltSettAmt[21 + 1];       // ʵʱ������ �۹�ί�з��ظ۱�
  char            szFundAvl[21 + 1];          // �ʽ���ý�� һ��̨�˿���
  LONGLONG        llStkAvl;                   // ֤ȯ�������� 
  char            szOpptStkpbu[8 + 1];        // �Է�ϯλ 
  char            szOpptTrdacct[10 + 1];      // �Է������˺� 
  int             iMatchedDate;               // �ɽ����� 
  char            szMatchedTime[8 + 1];       // �ɽ�ʱ�� 
  char            chIsWithdraw;               // ������־ �ֵ�[IS_WITHDRAW]
  char            szCustCode[16 + 1];         // �ͻ����� 
  char            szCuacctCode[16 + 1];       // �ʲ��˻� 
  int             iOrderBsn;                  // ί������ 
  int             iCuacctSn;                  // �˻���� 
  char            szStkbd[2 + 1];             // ���װ�� �ֵ�[STKBD]
  char            chMatchedType;              // �ɽ����� ��0��:�ڲ������ɽ� ��1��:�Ƿ�ί�г����ɽ� ��2��:�������ɽ��������������ɽ�����ί�гɽ���
  char            chOrderStatus;              // ί��״̬ �ֵ�[ORDER_STATUS] ���γɽ���ί�е�״̬
  int             iStkBiz;                    // ֤ȯҵ�� 
  int             iStkBizAction;              // ֤ȯҵ����Ϊ 
  char            szOfferRetMsg[64 + 1];      // �걨��Ϣ �������ϵ�ʱ���طϵ�ԭ��
  LONGLONG        llOrderQty;                 // ί������ 
  LONGLONG        llWithdrawnQty;             // �ѳ������� Ϊ����
  LONGLONG        llTotalMatchedQty;          // �ۼƳɽ����� 
  char            chCuacctAttr;               // �˻����� �ֻ�ר���ֶ�
  char            szTotalMatchedAmt[21 + 1];  // �ۼƳɽ���� �ֻ�ר���ֶ� �۹�ί�з��ظ۱�
  LONGLONG        llStkQty;                   // ӵ���� �ֻ�ר���ֶ�
  char            szMatchedAmt[21 + 1];       // �ѳɽ���� �۹�ί�з��ظ۱�
  char            szHFundAvl[21 + 1];         // �۹��ʽ���� ����̨�˿���(KFOS1.2.3.5�����ϰ汾֧��)
  int             iOrderDate;                 // ί������ ��Ȩר���ֶ�
  int             iOrderSn;                   // ί����� ��Ȩר���ֶ�
  int             iIntOrg;                    // �ڲ����� ��Ȩר���ֶ�
  char            szStkpbu[8 + 1];            // ���׵�Ԫ ��Ȩר���ֶ�
  char            szSubacctCode[8 + 1];       // ֤ȯ�˻��ӱ��� ��Ȩר���ֶ�
  char            szOptTrdacct[18 + 1];       // ��Ȩ��Լ�˻� ��Ȩר���ֶ�
  char            szOwnerType[3 + 1];         // ������������ ��Ȩר���ֶ�
  char            szOptCode[32 + 1];          // ��Լ���� ��Ȩר���ֶ�
  char            szOptName[32 + 1];          // ��Լ��� ��Ȩר���ֶ�
  char            chCurrency;                 // ���Ҵ��� ��Ȩר���ֶ�
  char            chOptUndlCls;               // ���֤ȯ��� ��Ȩר���ֶ�
  char            szOptUndlCode[8 + 1];       // ���֤ȯ���� ��Ȩר���ֶ�
  char            szOptUndlName[16 + 1];      // ���֤ȯ���� ��Ȩר���ֶ�
  char            szOrderPrice[21 + 1];       // ί�м۸� ��Ȩר���ֶ�
  char            szOrderAmt[21 + 1];         // ί�н�� ��Ȩר���ֶ�
  char            szMarginPreFrz[21 + 1];     // Ԥռ�ñ�֤�� ��Ȩר���ֶΣ�����ί��ʱ��дԤ����ı�֤�����������0����
  char            szMarginFrz[21 + 1];        // ռ�ñ�֤�� ��Ȩר���ֶΣ������ɽ�ʱ��дʵ�ʶ���ı�֤�����������0����
  char            szMarginPreUfz[21 + 1];     // Ԥ�ͷű�֤�� ��Ȩר���ֶΣ���ƽί��ʱ��дԤ�ⶳ�ı�֤�����������0����
  char            szMarginUfz[21 + 1];        // �ͷű�֤�� ��Ȩר���ֶΣ���ƽ�ɽ�ʱ��дʵ�ʽⶳ�ı�֤�����������0����
  char            szCombNum[16 + 1];          // ��ϱ��� ��Ȩר���ֶΣ�������ϡ�������ʱ��д�����������գ�
  char            szCombStraCode[16 + 1];     // ��ϲ��Դ��� ��Ȩר���ֶΣ�������ϡ�������ʱ��д�����������գ�
  char            szLeg1Num[16 + 1];          // �ɷ�һ��Լ���� ��Ȩר���ֶΣ�������ϡ������ϡ���Ȩָ��ϲ��걨ʱ��д�����������գ�
  char            szLeg2Num[16 + 1];          // �ɷֶ���Լ���� ��Ȩר���ֶΣ�������ϡ������ϡ���Ȩָ��ϲ��걨ʱ��д�����������գ�
  char            szLeg3Num[16 + 1];          // �ɷ�����Լ���� ��Ȩר���ֶΣ�������ϡ�������ʱ��д�����������գ�
  char            szLeg4Num[16 + 1];          // �ɷ��ĺ�Լ���� ��Ȩר���ֶΣ�������ϡ�������ʱ��д�����������գ�
  char            szOptBcostRltPrice[21 + 1]; // ʵʱ�ɱ��� ��Ȩר���ֶ�
  int             iTrdCodeCls;                // Ʒ������ ���Ӷ���ר���ֶ�
  int             iOrderNo;                   // ί�б�� ���Ӷ���ר���ֶ�
  int             iErrorId;                   // ������� ���Ӷ���ר���ֶ�
  char            szErrorMsg[81 + 1];         // ������Ϣ ���Ӷ���ר���ֶ�
  char            szBrokerId[11 + 1];         // ���͹�˾���� ���Ӷ���ר���ֶ�
  char            szInstrumentId[31 + 1];     // ��Լ���� ���Ӷ���ר���ֶ�
  char            szOrderRef[13 + 1];         // �������� ���Ӷ���ר���ֶ�
  char            szUserId[16 + 1];           // �û����� ���Ӷ���ר���ֶ�
  char            szExchangeId[9 + 1];        // ���������� ���Ӷ���ר���ֶ�
  char            szOrderSysId[21 + 1];       // ������� ���Ӷ���ר���ֶ�
  char            szCombOffsetFlag[5 + 1];    // ��Ͽ�ƽ��־ ���Ӷ���ר���ֶ�
  char            szCombHedgeFlag[5 + 1];     // ���Ͷ���ױ���־ ���Ӷ���ר���ֶ�
  char            szOrderLocalId[13 + 1];     // ���ر������ ���Ӷ���ר���ֶ�
  int             iSequenceNo;                // ��� ���Ӷ���ר���ֶ�
  char            szCliOrderNo[32 + 1];       // �ͻ���ί�б�� ���Ӷ���ר���ֶ�
  int             iAttrCode;                  // ���Դ��� ���Ӷ���ר���ֶ�
  char            chCuacctType;               // �˻����� ���Ӷ���ר���ֶ�
  char            szStkName[16 + 1];          // ֤ȯ���� ���Ӷ���ר���ֶ�
  char            chStrategyType;             // �������� ���Ӷ���ר���ֶ�
  char            szStrategyName[32 + 1];     // �������� ���Ӷ���ר���ֶ�
  int             iOrderGroupNo;              // ��ϵ���� ���Ӷ���ר���ֶ�
  int             iSubOrderSn;                // �ӵ���� ���Ӷ���ר���ֶ�
  int             iMainTrdDate;               // ĸ���������� ���Ӷ���ר���ֶ�
  int             iTrdDate;                   // �������� ���Ӷ���ר���ֶ�
  char            szOrderTime[32 + 1];        // ί��ʱ�� ���Ӷ���ר���ֶ�
  char            szOrderAttr[256 + 1];       // �߼����� ���Ӷ���ר���ֶ�
  char            szTrdExInfo[512 + 1];       // ������չ��Ϣ ���Ӷ���ר���ֶ�
  char            chUpdownCtrl;               // ��ͣ������ͣ�����־ ���Ӷ���ר���ֶ�
  char            szStopPrice[21 + 1];        // ֹ��� ���Ӷ���ר���ֶ�
  char            szTrackMatchPrice[21 + 1];  // ��̬������ ���Ӷ���ר���ֶ�
  LONGLONG        llExeBuyQty;                // ��ִ���걨���� ���Ӷ���ר���ֶ�
  LONGLONG        llExeSellQty;               // ��ִ���걨���� ���Ӷ���ר���ֶ�
  LONGLONG        llMatchBuyQty;              // ��ɽ����� ���Ӷ���ר���ֶ�
  LONGLONG        llMatchSellQty;             // ���ɽ����� ���Ӷ���ר���ֶ�
  char            szMatchBuyAmt[21 + 1];      // ��ɽ���� ���Ӷ���ר���ֶ�
  char            szMatchSellAmt[21 + 1];     // ���ɽ���� ���Ӷ���ר���ֶ�
  char            szMatchBuyAvgPrice[21 + 1]; // ��ɽ����� ���Ӷ���ר���ֶ�
  char            szMatchSellAvgPrice[21 + 1];// ���ɽ����� ���Ӷ���ר���ֶ�
  LONGLONG        llWithdrawnBuyQty;          // �򳷵����� ���Ӷ���ר���ֶ�
  LONGLONG        llWithdrawnSellQty;         // ���������� ���Ӷ���ר���ֶ�
  int             iExeBuyCnt;                 // ��ִ�д��� ���Ӷ���ר���ֶ�
  int             iExeSellCnt;                // ��ִ�д��� ���Ӷ���ר���ֶ�
  char            szExeInfo[256 + 1];         // ִ����Ϣ ���Ӷ���ר���ֶ�
  char            chChannel;                  // �������� ���Ӷ���ר���ֶ�
  char            szCliRemark[256 + 1];       // ������Ϣ ���Ӷ���ר���ֶ�
  char            szCliDefine1[32 + 1];       // �ͻ��Զ���1 ���Ӷ���ר���ֶ�
  char            szCliDefine2[32 + 1];       // �ͻ��Զ���2 ���Ӷ���ר���ֶ�
  char            szCliDefine3[32 + 1];       // �ͻ��Զ���3 ���Ӷ���ר���ֶ�
  char            szRemark1[32 + 1];          // Ԥ���ֶ�1 ��Ȩר���ֶ�
  char            szRemark2[32 + 1];          // Ԥ���ֶ�2 
  char            szRemark3[32 + 1];          // Ԥ���ֶ�3 
  char            szRemark4[32 + 1];          // Ԥ���ֶ�4 
  char            szRemark5[32 + 1];          // Ԥ���ֶ�5 
  char            szRemark6[32 + 1];          // Ԥ���ֶ�6 ���Ӷ���ר���ֶ�
  char            szRemark7[32 + 1];          // Ԥ���ֶ�7 ���Ӷ���ר���ֶ�
  char            szRemark8[32 + 1];          // Ԥ���ֶ�8 ���Ӷ���ר���ֶ�
  char            szRemark9[32 + 1];          // Ԥ���ֶ�9 ���Ӷ���ר���ֶ�
  char            szRemarka[32 + 1];          // Ԥ���ֶ�A ���Ӷ���ר���ֶ�
};

//����ί��ȷ�ϻر�
struct MATRADEAPI CRtnTsuOrderField
{
  int             iOrderBsn;                  // ί������ 
  char            szOrderId[10 + 1];          // ��ͬ��� 
  char            szCuacctCode[16 + 1];       // �ʲ��˻� 
  char            szOrderPrice[21 + 1];       // ί�м۸� 
  LONGLONG        llOrderQty;                 // ί������ 
  char            szOrderAmt[21 + 1];         // ί�н�� 
  char            szOrderFrzAmt[21 + 1];      // ������ 
  char            szStkpbu[8 + 1];            // ���׵�Ԫ 
  char            szStkbd[2 + 1];             // ���װ�� 
  char            szStkCode[8 + 1];           // ֤ȯ���� 
  char            szStkName[16 + 1];          // ֤ȯ���� 
  int             iStkBiz;                    // ֤ȯҵ�� 
  int             iStkBizAction;              // ҵ����Ϊ 
  int             iCuacctSn;                  // �˻���� 
  int             iOrderNo;                   // ί�б�� 
  int             iOrderDate;                 // ί������ 
  char            szOrderTime[32 + 1];        // ί��ʱ�� 
  char            szTrdacct[16 + 1];          // �����˻� 
  char            szOptNum[16 + 1];           // ��Լ���� 
  char            szOptCode[32 + 1];          // ��Լ���� 
  char            szOptName[32 + 1];          // ��Լ��� 
  char            szOptUndlCode[8 + 1];       // ���֤ȯ���� 
  char            chExeStatus;                // ִ��״̬ 
  int             iFrontId;                   // ǰ�ñ�� 
  LONGLONG        llSessionId;                // �Ự��� 
  int             iErrorId;                   // ������� 
  char            szErrorMsg[256 + 1];        // ������Ϣ 
  int             iOrderChange;               // �ĵ���ʶ 
  char            szCliOrderNo[32 + 1];       // �ͻ���ί�б�� 
  char            chCuacctType;               // �˻����� 
  int             iAttrCode;                  // ���Դ��� 
  char            szTriggerPrice[21 + 1];     // �����۸� 
  char            szCustCode[16 + 1];         // �ͻ����� 
  int             iOrderGroupNo;              // ��ϵ���� 
  int             iSubOrderSn;                // �ӵ���� 
  int             iTrdDate;                   // �������� 
  int             iMainTrdDate;               // ĸ�������� 
  char            szOrderAttr[256 + 1];       // �߼����� 
  char            szTrdExInfo[512 + 1];       // ����ִ����Ϣ 
  char            chUpdownCtrl;               // ��ͣ������ͣ�����־ 
  char            chStkex;                    // �����г� 
  char            chTrdCodeCls;               // ֤ȯ�������� 
  char            szStopPrice[21 + 1];        // ֹ��� 
  char            szTrackMatchPrice[21 + 1];  // ��̬������ 
  int             iIntOrg;                    // �ڲ����� 
  char            szExeInfo[256 + 1];         // ִ����Ϣ 
  char            chOnoffFlag;                // ��ͣ��־ 
  char            chChannel;                  // �������� 
  char            chStrategyType;             // �������� 
  char            szStrategyName[32 + 1];     // �������� 
  char            szCliRemark[256 + 1];       // ������Ϣ 
  char            szCliDefine1[32 + 1];       // �ͻ��Զ���1 
  char            szCliDefine2[32 + 1];       // �ͻ��Զ���2 
  char            szCliDefine3[32 + 1];       // �ͻ��Զ���3 
  char            szRemark1[32 + 1];          // Ԥ���ֶ�1 ��Ȩר���ֶ�
  char            szRemark2[32 + 1];          // Ԥ���ֶ�2 
  char            szRemark3[32 + 1];          // Ԥ���ֶ�3 
  char            szRemark4[32 + 1];          // Ԥ���ֶ�4 
  char            szRemark5[32 + 1];          // Ԥ���ֶ�5 
  char            szRemark6[32 + 1];          // Ԥ���ֶ�6 ���Ӷ���ר���ֶ�
  char            szRemark7[32 + 1];          // Ԥ���ֶ�7 ���Ӷ���ר���ֶ�
  char            szRemark8[32 + 1];          // Ԥ���ֶ�8 ���Ӷ���ר���ֶ�
  char            szRemark9[32 + 1];          // Ԥ���ֶ�9 ���Ӷ���ר���ֶ�
  char            szRemarka[32 + 1];          // Ԥ���ֶ�A ���Ӷ���ר���ֶ�
};

////////////////////////////////////////////////////////////////////////////////////////////////
//�ڲ��ӿڹ���
//�ɽ��ر�����
struct MATRADEAPI CReqCosMatchReportField
{
	int      iTrdCodeCls;     //Ʒ������    TRD_CODE_CLS    INTEGER    X 8970
	char     szMatchedSn[16+1];//�ɽ����    MATCHED_SN      VARCHAR(16)X 17  
	char     chStkex;         //�����г�    STKEX           CHAR(1)    X 207 �ֵ�[STKEX]
	char     szStkCode[8+1]; //֤ȯ����    STK_CODE        VARCHAR(8) X 48  
	int      iOrderNo;        //ί�б��    ORDER_NO        INTEGER    X 9106
	char     szOrderId[10+1];//��ͬ���    ORDER_ID        VARCHAR(10)X 11  
	char     szTrdacct[16+1];//�����˻�    TRDACCT         VARCHAR(16)X 448 
	LONGLONG llMatchedQty;    //�ɽ�����    MATCHED_QTY     BIGINT     X 387 �����ɽ�ʱ��Ϊ����
	char     szMatchedPrice[21+1];//�ɽ��۸�    MATCHED_PRICE   CPRICE     X 8841
	char     szOrderFrzAmt[21+1];//ί�ж�����  ORDER_FRZ_AMT   CMONEY     X 8831
	char     szRltSettAmt[21+1];//ʵʱ������  RLT_SETT_AMT    CMONEY     X 8853
	char     szFundAvl[21+1]; //�ʽ���ý��  FUND_AVL        CMONEY     X 8861
	LONGLONG llStkAvl;        //֤ȯ��������  STK_AVL         BIGINT     X 8869
	char     szOpptStkpbu[8+1];//�Է�ϯλ    OPPT_STKPBU     VARCHAR(8) X 9107
	char     szOpptTrdacct[10+1];//�Է������˺�  OPPT_TRDACCT    VARCHAR(10)X 9108
	int      iMatchedDate;    //�ɽ�����    MATCHED_DATE    INTEGER    X 8839
	char     szMatchedTime[8+1];//�ɽ�ʱ��    MATCHED_TIME    VARCHAR(8) X 8840
	char     chIsWithdraw;    //������־    IS_WITHDRAW     CHAR(1)    X 8836�ֵ�[IS_WITHDRAW]
	char     szCustCode[16+1]; //�ͻ�����    CUST_CODE       BIGINT     X 8902
  char     szCuacctCode[16+1];    //�ʲ��˻�    CUACCT_CODE     BIGINT     X 8920
	int      iOrderBsn;       //ί������    ORDER_BSN       INTEGER    X 66  
	int      iCuacctSn;       //�˻����    CUACCT_SN       SMALLINT   X 8928
	char     szStkbd[2+1];   //���װ��    STKBD           CHAR(2)    X 625 �ֵ�[STKBD]
	char     chMatchedType;   //�ɽ�����    MATCHED_TYPE    CHAR(1)    X 9080��0��:�ڲ������ɽ���1��:�Ƿ�ί�г����ɽ���2��:�������ɽ��������������ɽ�����ί�гɽ���
	char     chOrderStatus;   //ί��״̬    ORDER_STATUS    CHAR(1)    X 39  �ֵ�[ORDER_STATUS]
	int      iStkBiz;         //֤ȯҵ��    STK_BIZ         SMALLINT   X 8842
	int      iStkBizAction;   //֤ȯҵ����Ϊ  STK_BIZ_ACTION  SMALLINT   X 40  
	int      iOrderDate;      //ί������    ORDER_DATE      INTEGER    X 8834��Ȩר���ֶΡ�>����
	int      iOrderSn;        //ί�����    ORDER_SN        INTEGER    X 8832��Ȩר���ֶ�
	int      iIntOrg;         //�ڲ�����    INT_ORG         SMALLINT   X 8911��Ȩר���ֶ�
	char     szStkpbu[8+1];  //���׵�Ԫ    STKPBU          VARCHAR(8) X 8843��Ȩר���ֶ�
	char     szSubacctCode[8+1];//֤ȯ�˻��ӱ��� SUBACCT_CODE    VARCHAR(8) X 9099��Ȩר���ֶ�
	char     szOptTrdacct[18+1];//��Ȩ��Լ�˻�  OPT_TRDACCT     VARCHAR(18)X 9098��Ȩר���ֶ�
	char     szOwnerType[3+1];//������������  OWNER_TYPE      CHAR(3)    X 9091��Ȩר���ֶ�
	char     szOptCode[32+1];//��Լ����    OPT_CODE        VARCHAR(32)X 9083��Ȩר���ֶ�
	char     szOptName[32+1];//��Լ���    OPT_NAME        VARCHAR(32)X 9084��Ȩר���ֶ�
	char     chCurrency;      //���Ҵ���    CURRENCY        CHAR(1)    X 15  ��Ȩר���ֶ�
	char     chOptUndlCls;    //���֤ȯ���  OPT_UNDL_CLS    CHAR(1)    X 9085��Ȩר���ֶ�
	char     szOptUndlCode[8+1];//���֤ȯ����  OPT_UNDL_CODE   VARCHAR(8) X 9086��Ȩר���ֶ�
	char     szOptUndlName[16+1];//���֤ȯ����  OPT_UNDL_NAME   VARCHAR(16)X 9087��Ȩר���ֶ�
	char     szOrderPrice[21+1];//ί�м۸�    ORDER_PRICE     CPRICE4    X 44  ��Ȩר���ֶ�
	LONGLONG llOrderQty;      //ί������    ORDER_QTY       BIGINT     X 38  ��Ȩר���ֶ�
	char     szOrderAmt[21+1];//ί�н��    ORDER_AMT       CMONEY     X 8830��Ȩר���ֶ�
	char     szMatchedAmt[21+1];//�ѳɽ����   MATCHED_AMT     CMONEY     X 8504��Ȩר���ֶ�
	char     szMarginPreFrz[21+1];//Ԥռ�ñ�֤��  MARGIN_PRE_FRZ  CMONEY     X 9094��Ȩר���ֶΣ�����ί��ʱ��дԤ����ı�֤�����������0����
	char     szMarginFrz[21+1];//ռ�ñ�֤��   MARGIN_FRZ      CMONEY     X 9095��Ȩר���ֶΣ������ɽ�ʱ��дʵ�ʶ���ı�֤�����������0����
	char     szMarginPreUfz[21+1];//Ԥ�ͷű�֤��  MARGIN_PRE_UFZ  CMONEY     X 9096��Ȩר���ֶΣ���ƽί��ʱ��дԤ�ⶳ�ı�֤�����������0����
	char     szMarginUfz[21+1];//�ͷű�֤��   MARGIN_UFZ      CMONEY     X 9097��Ȩר���ֶΣ���ƽ�ɽ�ʱ��дʵ�ʽⶳ�ı�֤�����������0����
	int      iErrorId;        //�������    ERROR_ID        SMALLINT   X 8900�ڻ�ר���ֶ�
	char     szErrorMsg[81+1];//������Ϣ    ERROR_MSG       VARCHAR(81)X 8901�ڻ�ר���ֶ�
	char     szBrokerId[11+1];//���͹�˾����  BROKER_ID       VARCHAR(11)X 8890�ڻ�ר���ֶ�
	char     szInstrumentId[31+1];//��Լ����    INSTRUMENT_ID   VARCHAR(31)X 48  �ڻ�ר���ֶ�
	char     szOrderRef[13+1];//��������    ORDER_REF       VARCHAR(13)X 8738�ڻ�ר���ֶ�
	char     szUserId[16+1]; //�û�����    USER_ID         VARCHAR(16)X 9080�ڻ�ר���ֶ�
	char     szExchangeId[9+1];//����������   EXCHANGE_ID     VARCHAR(9) X 207 �ڻ�ר���ֶ�
	char     szOrderSysId[21+1];//�������    ORDER_SYS_ID    VARCHAR(21)X 8745�ڻ�ר���ֶ�
	char     szCombOffsetFlag[5+1];//��Ͽ�ƽ��־  COMB_OFFSET_FLAGVARCHAR(5) X 8741�ڻ�ר���ֶ�
	char     szCombHedgeFlag[5+1];//���Ͷ���ױ���־COMB_HEDGE_FLAG VARCHAR(5) X 8742�ڻ�ר���ֶ�
	char     szOrderLocalId[13+1];//���ر������  ORDER_LOCAL_ID  VARCHAR(13)X 8722�ڻ�ר���ֶ�
	int      iSequenceNo;     //���      SEQUENCE_NO     SMALLINT   X 8832�ڻ�ר���ֶ�
	char     szCliOrderNo[32+1];//�ͻ���ί�б�� CLI_ORDER_NO    VARCHAR(32)X 9102�ͻ���ί�б��
};

struct MATRADEAPI CRspCosMatchReportField
{
	int      iTrdCodeCls;         //Ʒ������    TRD_CODE_CLS    INTEGER    8970
	char     szMatchedSn[16+1];  //�ɽ����    MATCHED_SN      VARCHAR(16)17  
	char     chStkex;             //�����г�    STKEX           CHAR(1)    207 �ֵ�[STKEX]
	char     szStkCode[8+1];     //֤ȯ����    STK_CODE        VARCHAR(8) 48  
	int      iOrderNo;            //ί�б��    ORDER_NO        INTEGER    9106
	char     szOrderId[10+1];    //��ͬ���    ORDER_ID        VARCHAR(10)11  
	char     szTrdacct[16+1];    //�����˻�    TRDACCT         VARCHAR(16)448 
	LONGLONG llMatchedQty;        //�ɽ�����    MATCHED_QTY     BIGINT     387 �����ɽ�ʱ��Ϊ����
	char     szMatchedPrice[21+1];//�ɽ��۸�    MATCHED_PRICE   CPRICE     8841
	char     szOrderFrzAmt[21+1]; //ί�ж�����  ORDER_FRZ_AMT   CMONEY     8831
	char     szRltSettAmt[21+1];  //ʵʱ������  RLT_SETT_AMT    CMONEY     8853
	char     szFundAvl[21+1];     //�ʽ���ý��  FUND_AVL        CMONEY     8861
	LONGLONG llStkAvl;            //֤ȯ��������  STK_AVL         BIGINT     8869
	char     szOpptStkpbu[8+1];  //�Է�ϯλ    OPPT_STKPBU     VARCHAR(8) 9107
	char     szOpptTrdacct[10+1];//�Է������˺�  OPPT_TRDACCT    VARCHAR(10)9108
	int      iMatchedDate;        //�ɽ�����    MATCHED_DATE    INTEGER    8839
	char     szMatchedTime[8+1]; //�ɽ�ʱ��    MATCHED_TIME    VARCHAR(8) 8840
	char     chIsWithdraw;        //������־    IS_WITHDRAW     CHAR(1)    8836�ֵ�[IS_WITHDRAW]
	char     szCustCode[16+1];          //�ͻ�����    CUST_CODE       BIGINT     8902
	char     szCuacctCode[16+1];        //�ʲ��˻�    CUACCT_CODE     BIGINT     8920
	int      iOrderBsn;           //ί������    ORDER_BSN       INTEGER    66  
	int      iCuacctSn;           //�˻����    CUACCT_SN       SMALLINT   8928
	char     szStkbd[2+1];       //���װ��    STKBD           CHAR(2)    625 �ֵ�[STKBD]
	char     chMatchedType;       //�ɽ�����    MATCHED_TYPE    CHAR(1)    9080��0��:�ڲ������ɽ�
	char     chOrderStatus;       //ί��״̬    ORDER_STATUS    CHAR(1)    39  �ֵ�[ORDER_STATUS]
	int      iStkBiz;             //֤ȯҵ��    STK_BIZ         SMALLINT   8842
	int      iStkBizAction;       //֤ȯҵ����Ϊ  STK_BIZ_ACTION  SMALLINT   40  
	int      iOrderDate;          //ί������    ORDER_DATE      INTEGER    8834��Ȩר���ֶ�
	int      iOrderSn;            //ί�����    ORDER_SN        INTEGER    8832��Ȩר���ֶ�
	int      iIntOrg;             //�ڲ�����    INT_ORG         SMALLINT   8911��Ȩר���ֶ�
	char     szStkpbu[8+1];      //���׵�Ԫ    STKPBU          VARCHAR(8) 8843��Ȩר���ֶ�
	char     szSubacctCode[8+1]; //֤ȯ�˻��ӱ��� SUBACCT_CODE    VARCHAR(8) 9099��Ȩר���ֶ�
	char     szOptTrdacct[18+1]; //��Ȩ��Լ�˻�  OPT_TRDACCT     VARCHAR(18)9098��Ȩר���ֶ�
	char     szOwnerType[3+1];   //������������  OWNER_TYPE      CHAR(3)    9091��Ȩר���ֶ�
	char     szOptCode[32+1];    //��Լ����    OPT_CODE        VARCHAR(32)9083��Ȩר���ֶ�
	char     szOptName[32+1];    //��Լ���    OPT_NAME        VARCHAR(32)9084��Ȩר���ֶ�
	char     chCurrency;          //���Ҵ���    CURRENCY        CHAR(1)    15  ��Ȩר���ֶ�
	char     chOptUndlCls;        //���֤ȯ���  OPT_UNDL_CLS    CHAR(1)    9085��Ȩר���ֶ�
	char     szOptUndlCode[8+1]; //���֤ȯ����  OPT_UNDL_CODE   VARCHAR(8) 9086��Ȩר���ֶ�
	char     szOptUndlName[16+1];//���֤ȯ����  OPT_UNDL_NAME   VARCHAR(16)9087��Ȩר���ֶ�
	char     szOrderPrice[21+1];  //ί�м۸�    ORDER_PRICE     CPRICE4    44  ��Ȩר���ֶ�
	LONGLONG llOrderQty;          //ί������    ORDER_QTY       BIGINT     38  ��Ȩר���ֶ�
	char     szOrderAmt[21+1];    //ί�н��    ORDER_AMT       CMONEY     8830��Ȩר���ֶ�
	char     szMatchedAmt[21+1];  //�ѳɽ����   MATCHED_AMT     CMONEY     8504��Ȩר���ֶ�
	char     szMarginPreFrz[21+1];//Ԥռ�ñ�֤��  MARGIN_PRE_FRZ  CMONEY     9094��Ȩר���ֶΣ�����ί��ʱ��дԤ����ı�֤�����������0����
	char     szMarginFrz[21+1];   //ռ�ñ�֤��   MARGIN_FRZ      CMONEY     9095��Ȩר���ֶΣ������ɽ�ʱ��дʵ�ʶ���ı�֤�����������0����
	char     szMarginPreUfz[21+1];//Ԥ�ͷű�֤��  MARGIN_PRE_UFZ  CMONEY     9096��Ȩר���ֶΣ���ƽί��ʱ��дԤ�ⶳ�ı�֤�����������0����
	char     szMarginUfz[21+1];   //�ͷű�֤��   MARGIN_UFZ      CMONEY     9097��Ȩר���ֶΣ���ƽ�ɽ�ʱ��дʵ�ʽⶳ�ı�֤�����������0����
	int      iErrorId;            //�������    ERROR_ID        SMALLINT   8900�������
	char     szErrorMsg[81+1];   //������Ϣ    ERROR_MSG       VARCHAR(81)8901������Ϣ
	char     szBrokerId[11+1];   //���͹�˾����  BROKER_ID       VARCHAR(11)8890���͹�˾����
	char     szInstrumentId[31+1];//��Լ����    INSTRUMENT_ID   VARCHAR(31)48  ��Լ����
	char     szOrderRef[13+1];   //��������    ORDER_REF       VARCHAR(13)8738��������
	char     szUserId[16+1];     //�û�����    USER_ID         VARCHAR(16)9080�û�����
	char     szExchangeId[9+1];  //����������   EXCHANGE_ID     VARCHAR(9) 207 ����������
	char     szOrderSysId[21+1]; //�������    ORDER_SYS_ID    VARCHAR(21)8745�������
	char     szCombOffsetFlag[5+1];//��Ͽ�ƽ��־  COMB_OFFSET_FLAGVARCHAR(5) 8741��Ͽ�ƽ��־
	char     szCombHedgeFlag[5+1];//���Ͷ���ױ���־COMB_HEDGE_FLAG VARCHAR(5) 8742���Ͷ���ױ���־
	char     szOrderLocalId[13+1];//���ر������  ORDER_LOCAL_ID  VARCHAR(13)8722���ر������
	int      iSequenceNo;         //���      SEQUENCE_NO     SMALLINT   8832���
	char     szCliOrderNo[32+1]; //�ͻ���ί�б�� CLI_ORDER_NO    VARCHAR(32)9102
	LONGLONG llVolumeTraded;      //�ѳɽ�����   VOLUME_TRADED   BIGINT     8753�ѳɽ�����
	LONGLONG llWithdrawnQty;      //�ѳ�������   WITHDRAWN_QTY   BIGINT     8837�ѳ�������
};
//ί��Ӧ������
struct MATRADEAPI CReqCosOrderAnswerField
{
	int      iOrderBsn;    //ί������   ORDER_BSN     INTEGER     X 66   
	char     szOrderId[10+1];//��ͬ���   ORDER_ID      VARCHAR(10) X 11   
	int      iOrderNo;     //ί�б��   ORDER_NO      INTEGER     X 9106 
	int      iOrderDate;   //ί������   ORDER_DATE    INTEGER     X 8834 
	char     szOrderTime[32+1];//ί��ʱ��   ORDER_TIME    VARCHAR(32) X 8845 
  char     szCuacctCode[16+1]; //�ʲ��˻�   CUACCT_CODE   BIGINT      X 8920 
	char     szOrderPrice[21+1];//ί�м۸�   ORDER_PRICE   CPRICE      X 44   
	LONGLONG llOrderQty;   //ί������   ORDER_QTY     BIGINT      X 38   
	char     szOrderAmt[21+1];//ί�н��   ORDER_AMT     CMONEY      X 8830 
	char     szOrderFrzAmt[21+1];//������   ORDER_FRZ_AMT CMONEY      X 8831 
	char     szStkpbu[8+1];//���׵�Ԫ   STKPBU        VARCHAR(8)  X 8843 
	char     szStkbd[2+1];//���װ��   STKBD         CHAR(2)     X 625  
	char     szStkCode[8+1];//֤ȯ����   STK_CODE      VARCHAR(8)  X 48   
	char     szStkName[16+1];//֤ȯ����   STK_NAME      VARCHAR(16) X 55   
	int      iStkBiz;      //֤ȯҵ��   STK_BIZ       SMALLINT    X 8842 
	int      iStkBizAction;//ҵ����Ϊ   STK_BIZ_ACTIONSMALLINT    X 40   
	char     szTrdacct[16+1];//֤ȯ�˻�   TRDACCT       VARCHAR(16) X 448  
	int      iCuacctSn;    //�˻����   CUACCT_SN     SMALLINT    X 8928 
	char     szOptNum[16+1];//��Լ����   OPT_NUM       VARCHAR(16) X 9082 ��Ȩ
	char     szOptCode[32+1];//��Լ����   OPT_CODE      VARCHAR(32) X 9084 ��Ȩ
	char     szOptName[32+1];//��Լ���   OPT_NAME      VARCHAR(32) X 9085 ��Ȩ
	char     szOptUndlCode[8+1];//���֤ȯ���� OPT_UNDL_CODE VARCHAR(8)  X 48   ��Ȩ
	char     chExeStatus;  //ִ��״̬   EXE_STATUS    CHAR(1)     X 9103 
	char     szFrontId[32+1];//ǰ�ñ��   FRONT_ID      VARCHAR(32) X 8732 
	char     szSessionId[32+1];//�Ự���   SESSION_ID    VARCHAR(32) X 8814 
	int      iErrorId;     //�������   ERROR_ID      SMALLINT    X 8900 
	char     szErrorMsg[256+1];//������Ϣ   ERROR_MSG     VARCHAR(256)X 8901 
	int      iOrderChange; //�ĵ���ʶ   ORDER_CHANGE  SMALLINT    X 90860����ͨί��1���ĵ�2������
	char     szCliOrderNo[32+1];//�ͻ���ί�б��CLI_ORDER_NO  VARCHAR(32) X 9102 �ͻ���ί�б��
};

struct MATRADEAPI CRspCosOrderAnswerField
{
	int      iOrderBsn;        //ί������   ORDER_BSN     INTEGER     66  
	char     szOrderId[10+1]; //��ͬ���   ORDER_ID      VARCHAR(10) 11  
	int      iOrderNo;         //ί�б��   ORDER_NO      INTEGER     9106
	int      iOrderDate;       //ί������   ORDER_DATE    INTEGER     8834
	char     szOrderTime[32+1];//ί��ʱ��   ORDER_TIME    VARCHAR(32) 8845
	char     szCuacctCode[16+1];     //�ʲ��˻�   CUACCT_CODE   BIGINT      8920
	char     szOrderPrice[21+1];//ί�м۸�   ORDER_PRICE   CPRICE      44  
	LONGLONG llOrderQty;       //ί������   ORDER_QTY     BIGINT      38  
	char     szOrderAmt[21+1]; //ί�н��   ORDER_AMT     CMONEY      8830
	char     szOrderFrzAmt[21+1];//������   ORDER_FRZ_AMT CMONEY      8831
	char     szStkpbu[8+1];   //���׵�Ԫ   STKPBU        VARCHAR(8)  8843
	char     szStkbd[2+1];    //���װ��   STKBD         CHAR(2)     625 
	char     szStkCode[8+1];  //֤ȯ����   STK_CODE      VARCHAR(8)  48  
	char     szStkName[16+1]; //֤ȯ����   STK_NAME      VARCHAR(16) 55  
	int      iStkBiz;          //֤ȯҵ��   STK_BIZ       SMALLINT    8842
	int      iStkBizAction;    //ҵ����Ϊ   STK_BIZ_ACTIONSMALLINT    40  
	char     szTrdacct[16+1]; //֤ȯ�˻�   TRDACCT       VARCHAR(16) 448 
	int      iCuacctSn;        //�˻����   CUACCT_SN     SMALLINT    8928
	char     szOptNum[16+1];  //��Լ����   OPT_NUM       VARCHAR(16) 9082��Ȩ
	char     szOptCode[32+1]; //��Լ����   OPT_CODE      VARCHAR(32) 9084��Ȩ
	char     szOptName[32+1]; //��Լ���   OPT_NAME      VARCHAR(32) 9085��Ȩ
	char     szOptUndlCode[8+1];//���֤ȯ���� OPT_UNDL_CODE VARCHAR(8)  48  ��Ȩ
	char     chExeStatus;      //ִ��״̬   EXE_STATUS    CHAR(1)     9103
	char     szFrontId[32+1]; //ǰ�ñ��   FRONT_ID      VARCHAR(32) 8732
	char     szSessionId[32+1];//�Ự���   SESSION_ID    VARCHAR(32) 8814
	int      iErrorId;         //�������   ERROR_ID      SMALLINT    8900
	char     szErrorMsg[256+1];//������Ϣ   ERROR_MSG     VARCHAR(256)8901
	int      iOrderChange;     //�ĵ���ʶ   ORDER_CHANGE  SMALLINT    9086
	char     szCliOrderNo[32+1];//�ͻ���ί�б��CLI_ORDER_NO  VARCHAR(32) 9102
};
//CON ORDER (��ί��)����������
struct MATRADEAPI CReqCosCondOrderField
{
	int      iTrdCodeCls;          //Ʒ������  TRD_CODE_CLS        INTEGER     Y 8970 
	char     szCustCode[16+1];           //�ͻ�����  CUST_CODE           BIGINT      X 8902 
  char     szCuacctCode[16+1];         //�ʲ��˻�  CUACCT_CODE         BIGINT      Y 8920 
	char     szTrdacct[32+1];     //�����˻�  TRDACCT             VARCHAR(32) Y 448  
	char     chExchange;           //������   EXCHANGE            CHAR(1)     X 207  
	char     szBoard[2+1];        //���װ��  BOARD               CHAR(2)     Y 625  
	char     szTrdCode[16+1];     //���״���  TRD_CODE            VARCHAR(16) X 48   �ֻ�/����/�ڻ�ʱ ����
	int      iTrdBiz;              //����ҵ��  TRD_BIZ             SMALLINT    Y 8842 
	int      iTrdBizAcction;       //ҵ��  TRD_BIZ_ACCTION     SMALLINT    Y 40   
	LONGLONG llOrderQty;           //ί������  ORDER_QTY           BIGINT      Y 38   
	LONGLONG llOrderPrice;         //ί�м۸�  ORDER_PRICE         BIGINT      X 44   �ڻ�ʱ����
	char     chSecurityLevel;      //��ȫ�ֶ�  SECURITY_LEVEL      CHAR(1)     X 90801: У��Ựƾ֤
	char     szSecurityInfo[256+1];//��ȫ��Ϣ  SECURITY_INFO       VARCHAR(256)X 9081 
	int      iIntOrg;              //�ڲ�����  INT_ORG             SMALLINT    X 8911 ��Ȩʱ����
	char     szOptNum[16+1];      //��Լ����  OPT_NUM             VARCHAR(16) X 9082 ��Ȩʱ����
	char     szStkpbu[8+1];       //���׵�Ԫ  STKPBU              VARCHAR(8)  X 8843 
	int      iOrderBsn;            //ί������  ORDER_BSN           INTEGER     X 66   
	char     szOrderIdEx[64+1];   //�ⲿ��ͬ���ORDER_ID_EX         VARCHAR(64) X 9093 �����Ϊ�ⲿ���룬��Ȩϵͳ�����κδ���
	char     szUndlCode[16+1];    //��Ĵ���  UNDL_CODE           VARCHAR(16) X 8972 
	int      iConExpDate;          //��Լ������ CON_EXP_DATE        INTEGER     X 8976 
	char     szExercisePrice[21+1];//��Ȩ��   EXERCISE_PRICE      CPRICE      X 8973 
	LONGLONG llConUnit;            //��Լ��λ  CON_UNIT            BIGINT      X 8974 
	char     szCliOrderNo[32+1];  //�ͻ���ί�б�CLI_ORDER_NO        VARCHAR(32) X 9102 
	char     szCliRemark[32+1];   //������Ϣ  CLI_REMARK          VARCHAR(32) X 8914 
	char     szBusinessUnit[21+1];//ҵ��Ԫ  BUSINESS_UNIT       VARCHAR(21) X 87170
	char     szGtdData[9+1];      //GTD���� GTD_DATA            VARCHAR(9)  X 87230
	char     chContingentCondition;//��������  CONTINGENT_CONDITIONVARCHAR(1)  X 87131:����
	char     chForceCloseReason;   //ǿƽԭ��  FORCE_CLOSE_REASON  VARCHAR(1)  X 87150
	int      iIsSwapOrder;         //��������־ IS_SWAP_ORDER       SMALLINT    X 87200
};

struct MATRADEAPI CRspCosCondOrderField
{
};
//GROP ORDER(Group Order )�������������
struct MATRADEAPI CReqCosCombCondOrderField
{
	int      iTrdCodeCls;          //Ʒ������   TRD_CODE_CLS        INTEGER     Y 8970 
	char     szCustCode[16+1];           //�ͻ�����   CUST_CODE           BIGINT      X 8902 
  char     szCuacctCode[16+1];         //�ʲ��˻�   CUACCT_CODE         BIGINT      Y 8920 
  char     chCuacctType;         //�ʲ��˻�����
	char     szTrdacct[32+1];     //�����˻�   TRDACCT             VARCHAR(32) Y 448  
	char     chExchange;           //������    EXCHANGE            CHAR(1)     X 207  
	char     szBoard[2+1];        //���װ��   BOARD               CHAR(2)     Y 625  
	char     szTrdCode[16+1];     //���״���   TRD_CODE            VARCHAR(16) X 48   �ֻ�/����/�ڻ�ʱ ����
	int      iTrdBiz;              //����ҵ��   TRD_BIZ             SMALLINT    Y 8842 
	int      iTrdBizAcction;       //ҵ��   TRD_BIZ_ACCTION     SMALLINT    Y 40   
	LONGLONG llOrderQty;           //ί������   ORDER_QTY           BIGINT      Y 38   
	LONGLONG llOrderPrice;         //ί�м۸�   ORDER_PRICE         BIGINT      X 44   �ڻ�ʱ����
	char     chSecurityLevel;      //��ȫ�ֶ�   SECURITY_LEVEL      CHAR(1)     X 90801: У��Ựƾ֤
	char     szSecurityInfo[256+1];//��ȫ��Ϣ   SECURITY_INFO       VARCHAR(256)X 9081 
	int      iIntOrg;              //�ڲ�����   INT_ORG             SMALLINT    X 8911 ��Ȩʱ����
	char     szOptNum[16+1];      //��Լ����   OPT_NUM             VARCHAR(16) X 9082 ��Ȩʱ����
	char     szStkpbu[8+1];       //���׵�Ԫ   STKPBU              VARCHAR(8)  X 8843 
	int      iOrderBsn;            //ί������   ORDER_BSN           INTEGER     X 66   
	char     szOrderIdEx[64+1];   //�ⲿ��ͬ��� ORDER_ID_EX         VARCHAR(64) X 9093 �����Ϊ�ⲿ���룬��Ȩϵͳ�����κδ���
	char     szUndlCode[16+1];    //��Ĵ���   UNDL_CODE           VARCHAR(16) X 8972 
	int      iConExpDate;          //��Լ������  CON_EXP_DATE        INTEGER     X 8976 
	char     szExercisePrice[21+1];//��Ȩ��    EXERCISE_PRICE      CPRICE      X 8973 
	LONGLONG llConUnit;            //��Լ��λ   CON_UNIT            BIGINT      X 8974 
	char     szCliOrderNo[32+1];  //�ͻ���ί�б��CLI_ORDER_NO        VARCHAR(32) X 9102 
	char     szCliRemark[32+1];   //������Ϣ   CLI_REMARK          VARCHAR(32) X 8914 
	char     szBusinessUnit[21+1];//ҵ��Ԫ   BUSINESS_UNIT       VARCHAR(21) X 87170
	char     szGtdData[9+1];      //GTD����  GTD_DATA            VARCHAR(9)  X 87230
	char     chContingentCondition;//��������   CONTINGENT_CONDITIONVARCHAR(1)  X 87131:����
	char     chForceCloseReason;   //ǿƽԭ��   FORCE_CLOSE_REASON  VARCHAR(1)  X 87150
	int      iIsSwapOrder;         //��������־  IS_SWAP_ORDER       SMALLINT    X 87200
};

struct MATRADEAPI CRspCosCombCondOrderField
{
};


//��ѡ�ɱ༭
struct MATRADEAPI CReqCosPortfolioField
{
  char     szCuacctCode[16+1];//�ʲ��˺�CUACCT_CODEBIGINT      Y 8920 
  char     chCuacctType;         //�ʲ��˻�����
	char     chStkex;     //������ STKEX      CHAR(1)     Y 207  
	char     szStkbd[2+1];//���  STKBD      CHAR(2)     Y 625  
	char     szTrdCodes[512+1];//Ʒ�ִ���TRD_CODES  VARCHAR(512)Y 48   ���߷ָ�
	char     chOperType;  //��������OPER_TYPE  CHAR(1)     Y 88441:���;0:ɾ��������������
};

struct MATRADEAPI CRspCosPortfolioField
{
};

//��ѡ�ɲ�ѯ
struct MATRADEAPI CReqCosPortfolioInfoField
{
  char     szCuacctCode[16+1];//�ʲ��˺�CUACCT_CODEBIGINT    Y 8920 
  char     chCuacctType;         //�ʲ��˻�����
	char     chStkex;     //������ STKEX      CHAR(1)   Y 207  
	char     szStkbd[2+1];//���  STKBD      CHAR(2)   Y 625  
	char     chQueryFlag; //��ѯ��ʽQUERY_FLAG CHAR(1)   Y 90800����λ������ѯ 1����λ����ǰ��ѯ 2������Χ��ѯ ������������
	char     szStkCode[8+1];//��ѯλ��STK_CODE   VARCHAR(8)X 8991 ��λ�ò�ѯʱ�ش�
	int      iQueryNum;   //��ѯ����QUERY_NUM  INTEGER   X 8992 ��λ�ò�ѯʱ�ش������1000��
	char     szBegCode[8+1];//��ʼ����BEG_CODE   VARCHAR(8)X 9000 ��Χ��ѯʱ�ش�(�˷�Χ������ʼ����ͽ������뱾��)
	char     szEndCode[8+1];//��������END_CODE   VARCHAR(8)X 9001 ��Χ��ѯʱ�ش�
};

struct MATRADEAPI CRspCosPortfolioInfoField
{
	char     szCuacctCode[16+1];    //�ʲ��˺�  CUACCT_CODEBIGINT      8920
	char     chStkex;         //������   STKEX      CHAR(1)     207 
	char     szStkbd[2+1];   //���    STKBD      CHAR(2)     625 
	int      iAmount;         //����    AMOUNT     INTEGER     8900
	char     szStkCodes[512+1];//����(����)STK_CODES  VARCHAR(512)48  |�ָ�������
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
END_NAMESPACE_MACLI
#endif//__MA_CLI_COS_TRADE_API_STRUCT_H__