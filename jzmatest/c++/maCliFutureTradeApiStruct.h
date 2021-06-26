#if !defined(__MA_CLI_FUTURE_TRADE_API_STRUCT_H__)
#define __MA_CLI_FUTURE_TRADE_API_STRUCT_H__

#include "maCliTradeApi.h"
BGN_NAMESPACE_MACLI

//-------------------------------10330001:�ڻ���½--------------------------
struct MATRADEAPI CReqFutureUserLoginField
{
  char            szCustCode[16 + 1];         // �ͻ����� 
  char            szCuacctCode[16 + 1];       // �ʲ��˻� CTP  �ͻ�ID
  char            szCustPwd[256 + 1];         // �ͻ����� 
  char            szEncryptKey[32 + 1];       // �������� 
  char            szMacAddress[21 + 1];       // Mac��ַ 
  char            szOnetimePassword[41 + 1];  // ��̬���� 
  char            szClientIpAddress[16 + 1];  // �ն�IP��ַ 
};

struct MATRADEAPI CRspFutureUserLoginField
{
  int             iErrorId;                   // ������� 
  char            szErrorMsg[81 + 1];         // ������Ϣ 
  char            szTradingDay[9 + 1];        // ������ 
  char            szLoginTime[9 + 1];         // ��¼�ɹ�ʱ�� 
  char            szCuacctCode[16 + 1];       // �ʲ��˻� CTP  �ͻ�ID
  char            szCustCode[16 + 1];         // �ͻ����� 
  char            szSystemName[41 + 1];       // ����ϵͳ���� 
  int             iFrontId;                   // ǰ�ñ�� 
  LONGLONG        llSessionId;                // �Ự��� 
  char            szMaxOrderRef[13 + 1];      // ��󱨵����� 
  char            szShfeTime[9 + 1];          // ������ʱ�� 
  char            szDceTime[9 + 1];           // ������ʱ�� 
  char            szCzceTime[9 + 1];          // ֣����ʱ�� 
  char            szFfexTime[9 + 1];          // �н���ʱ�� 
};

//-------------------------------10330002:�ڻ��ǳ�--------------------------
struct MATRADEAPI CReqFutureUserLogoutField
{
  char            szCustCode[16 + 1];         // �ͻ����� 
  char            szCuacctCode[16 + 1];       // �ʲ��˻� CTP �ͻ�ID
};

struct MATRADEAPI CRspFutureUserLogoutField
{
  int             iErrorId;                   // ������� 
  char            szErrorMsg[81 + 1];         // ������Ϣ 
  char            szCustCode[16 + 1];         // �ͻ����� 
  char            szCuacctCode[16 + 1];       // �ʲ��˻� CTP �ͻ�ID
};

//����¼��
struct MATRADEAPI CReqFutureOrderField
{
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	char     szInstrumentId[31+1];//��Լ����    INSTRUMENT_ID        VARCHAR(31)Y 48  
	char     chOrderPriceType;     //�����۸�����  ORDER_PRICE_TYPE     VARCHAR(1) Y 8739
	char     chDirection;          //��������    DIRECTION            VARCHAR(1) Y 8740
	char     szCombOffsetFlag[5+1];//��Ͽ�ƽ��־  COMB_OFFSET_FLAG     VARCHAR(5) Y 8741
	char     szCombHedgeFlag[5+1];//���Ͷ���ױ���־COMB_HEDGE_FLAG      VARCHAR(5) X 8742
	char     szLimitPrice[21+1];   //�۸�      LIMIT_PRICE          CMONEY     Y 8958
	LONGLONG llVolumeTotalOriginal;//����      VOLUME_TOTAL_ORIGINALBIGINT     Y 8986
	char     chTimeCondition;      //��Ч������   TIME_CONDITION       VARCHAR(1) X 8710�ֵ䣺TIME_CONDITION
	char     szGtdData[9+1];      //GTD����   GTD_DATA             VARCHAR(9) X 8723
	char     chVolumeCondition;    //�ɽ�������   VOLUME_CONDITION     VARCHAR(1) X 8711
	LONGLONG llMinVolume;          //��С�ɽ���   MIN_VOLUME           BIGINT     X 8712
	char     chContingentCondition;//��������    CONTINGENT_CONDITION VARCHAR(1) X 8713
	char     szStopPrice[21+1];    //ֹ���     STOP_PRICE           CMONEY     X 8714
	char     chForceCloseReason;   //ǿƽԭ��    FORCE_CLOSE_REASON   VARCHAR(1) X 8715
	int      iIsAutoSuspend;       //�Զ������־  IS_AUTO_SUSPEND      SMALLINT   X 8716
	char     szBusinessUnit[21+1];//ҵ��Ԫ    BUSINESS_UNIT        VARCHAR(21)X 8717
	int      iUserForceClose;      //�û�ǿ����־  USER_FORCE_CLOSE     SMALLINT   X 8719
	int      iIsSwapOrder;         //��������־   IS_SWAP_ORDER        SMALLINT   X 8720
};

struct MATRADEAPI CRspFutureOrderField
{
	int      iErrorId;                 //�������    ERROR_ID             SMALLINT   8900
	char     szErrorMsg[81+1];        //������Ϣ    ERROR_MSG            VARCHAR(81)8901
	int      iOrderNo;                 //ί�б��    ORDER_NO             INTEGER    9106
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	char     szInstrumentId[31+1];    //��Լ����    INSTRUMENT_ID        VARCHAR(31)48  
	char     szOrderRef[13+1];        //��������    ORDER_REF            VARCHAR(13)8738
	char     szUserId[16+1];          //�û�����    USER_ID              VARCHAR(16)9080
	char     chOrderPriceType;         //�����۸�����  ORDER_PRICE_TYPE     VARCHAR(1) 8739
	char     chDirection;              //��������    DIRECTION            VARCHAR(1) 8740
	char     szCombOffsetFlag[5+1];   //��Ͽ�ƽ��־  COMB_OFFSET_FLAG     VARCHAR(5) 8741
	char     szCombHedgeFlag[5+1];    //���Ͷ���ױ���־COMB_HEDGE_FLAG      VARCHAR(5) 8742
	char     szLimitPrice[21+1];       //�۸�      LIMIT_PRICE          CMONEY     8958
	LONGLONG llVolumeTotalOriginal;    //����      VOLUME_TOTAL_ORIGINALBIGINT     8986
	char     chTimeCondition;          //��Ч������   TIME_CONDITION       VARCHAR(1) 8710
	char     szGtdData[9+1];          //GTD����   GTD_DATA             VARCHAR(9) 8723
	char     chVolumeCondition;        //�ɽ�������   VOLUME_CONDITION     VARCHAR(1) 8711
	LONGLONG llMinVolume;              //��С�ɽ���   MIN_VOLUME           BIGINT     8712
	char     chContingentCondition;    //��������    CONTINGENT_CONDITION VARCHAR(1) 8713
	char     szStopPrice[21+1];        //ֹ���     STOP_PRICE           CMONEY     8714
	char     chForceCloseReason;       //ǿƽԭ��    FORCE_CLOSE_REASON   VARCHAR(1) 8715
	int      iIsAutoSuspend;           //�Զ������־  IS_AUTO_SUSPEND      SMALLINT   8716
	char     szBusinessUnit[21+1];    //ҵ��Ԫ    BUSINESS_UNIT        VARCHAR(21)8717
	int      iRequestId;               //������    REQUEST_ID           SMALLINT   8718
	int      iUserForceClose;          //�û�ǿ����־  USER_FORCE_CLOSE     SMALLINT   8719
	int      iIsSwapOrder;             //��������־   IS_SWAP_ORDER        SMALLINT   8720
};

//��������
struct MATRADEAPI CReqFutureChgOrderField
{
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	char     szOrderRef[13+1];//�������� ORDER_REF    VARCHAR(13)X 8738CTP����
	int      iRequestId;    //������ REQUEST_ID   INTEGER    X 8718CTP����
	int      iFrontId;      //ǰ�ñ�� FRONT_ID     SMALLINT   Y 8732CTP����
	char     szExchangeId[9+1];//����������EXCHANGE_ID  VARCHAR(9) X 207 
	char     szOrderSysId[21+1];//������� ORDER_SYS_ID VARCHAR(21)Y 8745
	char     chActionFlag;  //������־ ACTION_FLAG  VARCHAR(1) X 8747CTP����ĵ���������
	char     szLimitPrice[21+1];//�۸�   LIMIT_PRICE  CMONEY     X 8958CTP�ĵ�����
	LONGLONG llVolumeChange;//�����仯 VOLUME_CHANGEBIGINT     X 8721CTP�ĵ�����
	char     szUserId[16+1];//�û����� USER_ID      VARCHAR(16)X 9080
	char     szInstrumentId[31+1];//��Լ���� INSTRUMENT_IDVARCHAR(31)X 48  
};

struct MATRADEAPI CRspFutureChgOrderField
{
	int      iErrorId;          //�������  ERROR_ID     SMALLINT   8900
	char     szErrorMsg[81+1]; //������Ϣ  ERROR_MSG    VARCHAR(81)8901
	char     szBrokerId[11+1]; //���͹�˾����BROKER_ID    VARCHAR(11)8890
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	char     szOrderRef[13+1]; //��������  ORDER_REF    VARCHAR(13)8738
	int      iRequestId;        //������  REQUEST_ID   INTEGER    8718
	int      iFrontId;          //ǰ�ñ��  FRONT_ID     INTEGER    8732
	char     szExchangeId[9+1];//���������� EXCHANGE_ID  VARCHAR(9) 207 
	char     szOrderSysId[21+1];//�������  ORDER_SYS_ID VARCHAR(21)8745
	char     chActionFlag;      //������־  ACTION_FLAG  VARCHAR(1) 8747
	char     szLimitPrice[21+1];//�۸�    LIMIT_PRICE  CMONEY     8958
	LONGLONG llVolumeChange;    //�����仯  VOLUME_CHANGEBIGINT     8721
	char     szUserId[16+1];   //�û�����  USER_ID      VARCHAR(16)9080
	char     szInstrumentId[31+1];//��Լ����  INSTRUMENT_IDVARCHAR(31)48  
};
//������ѯ
struct MATRADEAPI CReqFutureOrderInfoField
{
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	char     szInstrumentId[31+1];//��Լ���� INSTRUMENT_ID    VARCHAR(31)X 48  
	char     szExchangeId[9+1];//����������EXCHANGE_ID      VARCHAR(9) X 207 
	char     szOrderSysId[21+1];//������� ORDER_SYS_ID     VARCHAR(21)X 8745
	char     szInsertTimeStart[9+1];//��ʼʱ�� INSERT_TIME_STARTVARCHAR(9) X 9040
	char     szInsertTimeEnd[9+1];//����ʱ�� INSERT_TIME_END  VARCHAR(9) X 9041
};

struct MATRADEAPI CRspFutureOrderInfoField
{
	int      iErrorId;                  //�������        ERROR_ID               SMALLINT   8900
	char     szErrorMsg[81+1];         //������Ϣ        ERROR_MSG              VARCHAR(81)8901
	char     szBrokerId[11+1];         //���͹�˾����      BROKER_ID              VARCHAR(11)8890
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	char     szInstrumentId[31+1];     //��Լ����        INSTRUMENT_ID          VARCHAR(31)48  
	char     szOrderRef[13+1];         //��������        ORDER_REF              VARCHAR(13)8738
	char     szUserId[16+1];           //�û�����        USER_ID                VARCHAR(16)9080
	char     chOrderPriceType;          //�����۸�����      ORDER_PRICE_TYPE       VARCHAR(1) 8739
	char     chDirection;               //��������        DIRECTION              VARCHAR(1) 8740
	char     szCombOffsetFlag[5+1];    //��Ͽ�ƽ��־      COMB_OFFSET_FLAG       VARCHAR(5) 8741
	char     szCombHedgeFlag[5+1];     //���Ͷ���ױ���־    COMB_HEDGE_FLAG        VARCHAR(5) 8742
	char     szLimitPrice[21+1];        //�۸�          LIMIT_PRICE            CMONEY     8958
	LONGLONG llVolumeTotalOriginal;     //����          VOLUME_TOTAL_ORIGINAL  BIGINT     8986
	char     chTimeCondition;           //��Ч������       TIME_CONDITION         VARCHAR(1) 8710
	char     szGtdDate[9+1];           //GTD����       GTD_DATE               VARCHAR(9) 8723
	char     chVolumeCondition;         //�ɽ�������       VOLUME_CONDITION       VARCHAR(1) 8711
	LONGLONG llMinVolume;               //��С�ɽ���       MIN_VOLUME             BIGINT     8712
	char     chContingentCondition;     //��������        CONTINGENT_CONDITION   VARCHAR(1) 8713
	char     szStopPrice[21+1];         //ֹ���         STOP_PRICE             CMONEY     8714
	char     chForceCloseReason;        //ǿƽԭ��        FORCE_CLOSE_REASON     VARCHAR(1) 8715
	int      iIsAutoSuspend;            //�Զ������־      IS_AUTO_SUSPEND        SMALLINT   8716
	char     szBusinessUnit[21+1];     //ҵ��Ԫ        BUSINESS_UNIT          VARCHAR(21)8717
	int      iRequestId;                //������        REQUEST_ID             INTEGER    8718
	char     szOrderLocalId[13+1];     //���ر������      ORDER_LOCAL_ID         VARCHAR(13)8722
	char     szExchangeId[9+1];        //����������       EXCHANGE_ID            VARCHAR(9) 207 
	char     szParticipantId[11+1];    //��Ա����        PARTICIPANT_ID         VARCHAR(11)8724
	char     szClientId[11+1];         //�ͻ�����        CLIENT_ID              VARCHAR(11)8902
	char     szExchangeInstId[31+1];   //��Լ�ڽ������Ĵ���   EXCHANGE_INST_ID       VARCHAR(31)8725
	char     szTraderId[21+1];         //����������Ա����    TRADER_ID              VARCHAR(21)8726
	int      iInstallId;                //��װ���        INSTALL_ID             SMALLINT   8728
	char     chOrderSubmitStatus;       //�����ύ״̬      ORDER_SUBMIT_STATUS    VARCHAR(1) 8729
	int      iNotifySequence;           //������ʾ���      NOTIFY_SEQUENCE        SMALLINT   8743
	char     szTradingDay[9+1];        //������         TRADING_DAY            VARCHAR(9) 8844
	int      iSettlementId;             //������        SETTLEMENT_ID          SMALLINT   8744
	char     szOrderSysId[21+1];       //�������        ORDER_SYS_ID           VARCHAR(21)8745
	char     chOrderSource;             //������Դ        ORDER_SOURCE           VARCHAR(1) 8750
	char     chOrderStatus;             //����״̬        ORDER_STATUS           VARCHAR(1) 8751
	char     chOrderType;               //��������        ORDER_TYPE             VARCHAR(1) 8752
	LONGLONG llVolumeTraded;            //��ɽ�����       VOLUME_TRADED          BIGINT     8753
	LONGLONG llVolumeTotal;             //ʣ������        VOLUME_TOTAL           BIGINT     8754
	char     szInsertDate[9+1];        //��������        INSERT_DATE            VARCHAR(9) 8834
	char     szInsertTime[9+1];        //ί��ʱ��        INSERT_TIME            VARCHAR(9) 8845
	char     szActiveTime[9+1];        //����ʱ��        ACTIVE_TIME            VARCHAR(9) 8755
	char     szSuspendTime[9+1];       //����ʱ��        SUSPEND_TIME           VARCHAR(9) 8756
	char     szUpdateTime[9+1];        //����޸�ʱ��      UPDATE_TIME            VARCHAR(9) 8757
	char     szCancelTime[9+1];        //����ʱ��        CANCEL_TIME            VARCHAR(9) 8758
	char     szActiveTraderId[21+1];   //����޸Ľ���������Ա����ACTIVE_TRADER_ID       VARCHAR(21)8727
	char     szClearingPartId[11+1];   //�����Ա���      CLEARING_PART_ID       VARCHAR(11)8759
	int      iSequenceNo;               //���          SEQUENCE_NO            SMALLINT   8832
	char     szUserProductInfo[11+1];  //�û��˲�Ʒ��Ϣ     USER_PRODUCT_INFO      VARCHAR(11)8730
	char     szStatusMsg[81+1];        //״̬��Ϣ        STATUS_MSG             VARCHAR(81)8760
	int      iUserForceClose;           //�û�ǿ����־      USER_FORCE_CLOSE       SMALLINT   8719
	char     szActiveUserId[16+1];     //�����û�����      ACTIVE_USER_ID         VARCHAR(16)8810
	int      iBrokerOrderSeq;           //���͹�˾�������    BROKER_ORDER_SEQ       SMALLINT   8746
	char     szRealtiveOrderSysId[21+1];//��ر���        REALTIVE_ORDER_SYS_ID  VARCHAR(21)8761
	LONGLONG llZceTotalTradedVolume;    //֣�����ɽ�����     ZCE_TOTAL_TRADED_VOLUMEBIGINT     8762
	int      iIsSwapOrder;              //��������־       IS_SWAP_ORDER          SMALLINT   8720
};
//�ɽ���ѯ
struct MATRADEAPI CReqFutureMatchInfoField
{
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	char     szInstrumentId[31+1];//��Լ���� INSTRUMENT_ID    VARCHAR(31)X 48  
	char     szExchangeId[9+1];//����������EXCHANGE_ID      VARCHAR(9) X 207 
	char     szOrderSysId[21+1];//�ɽ���� ORDER_SYS_ID     VARCHAR(21)X 17  
	char     szInsertTimeStart[9+1];//��ʼʱ�� INSERT_TIME_STARTVARCHAR(9) X 9040
	char     szInsertTimeEnd[9+1];//����ʱ�� INSERT_TIME_END  VARCHAR(9) X 9041
};

struct MATRADEAPI CRspFutureMatchInfoField
{
	int      iErrorId;                 //�������     ERROR_ID            SMALLINT   8900
	char     szErrorMsg[81+1];        //������Ϣ     ERROR_MSG           VARCHAR(81)8901
	char     szBrokerId[11+1];        //���͹�˾����   BROKER_ID           VARCHAR(11)8890
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	char     szInstrumentId[31+1];    //��Լ����     INSTRUMENT_ID       VARCHAR(31)48  
	char     szOrderRef[13+1];        //��������     ORDER_REF           VARCHAR(13)8738
	char     szUserId[16+1];          //�û�����     USER_ID             VARCHAR(16)9080
	char     szExchangeId[9+1];       //����������    EXCHANGE_ID         VARCHAR(9) 207 
	char     szTradeId[21+1];         //�ɽ����     TRADE_ID            VARCHAR(21)17  
	char     chDirection;              //��������     DIRECTION           VARCHAR(1) 8740
	char     szOrderSysId[21+1];      //�������     ORDER_SYS_ID        VARCHAR(21)8745
	char     szParticipantId[11+1];   //��Ա����     PARTICIPANT_ID      VARCHAR(11)8724
	char     szClientId[11+1];        //�ͻ�����     CLIENT_ID           VARCHAR(11)8902
	char     chTradingRole;            //���׽�ɫ     TRADING_ROLE        VARCHAR(1) 8763
	char     szExchangeInstId[31+1];  //��Լ�ڽ������Ĵ���EXCHANGE_INST_ID    VARCHAR(31)8725
	char     szOffsetFlag[5+1];       //��Ͽ�ƽ��־   OFFSET_FLAG         VARCHAR(5) 8741
	char     szHedgeFlag[5+1];        //���Ͷ���ױ���־ HEDGE_FLAG          VARCHAR(5) 8742
	char     szPrice[21+1];            //�۸�       PRICE               CMONEY     44  
	LONGLONG llVolume;                 //����       VOLUME              BIGINT     8986
	char     szTradeDate[9+1];        //�ɽ�ʱ��     TRADE_DATE          VARCHAR(9) 8839
	char     szTradeTime[9+1];        //�ɽ�ʱ��     TRADE_TIME          VARCHAR(9) 8840
	char     chTradeType;              //�ɽ�����     TRADE_TYPE          VARCHAR(1) 8764
	char     chPriceSource;            //�ɽ�����Դ    PRICE_SOURCE        VARCHAR(1) 8765
	char     szTraderId[21+1];        //����������Ա���� TRADER_ID           VARCHAR(21)8726
	char     szOrderLocalId[13+1];    //���ر������   ORDER_LOCAL_ID      VARCHAR(13)8722
	char     szClearingPartId[11+1];  //�����Ա���   CLEARING_PART_ID    VARCHAR(11)8759
	char     chTimeCondition;          //��Ч������    TIME_CONDITION      VARCHAR(1) 8710
	char     szGtdDate[9+1];          //GTD����    GTD_DATE            VARCHAR(9) 8723
	char     chVolumeCondition;        //�ɽ�������    VOLUME_CONDITION    VARCHAR(1) 8711
	LONGLONG llMinVolume;              //��С�ɽ���    MIN_VOLUME          BIGINT     8712
	char     chContingentCondition;    //��������     CONTINGENT_CONDITIONVARCHAR(1) 8713
	char     szStopPrice[21+1];        //ֹ���      STOP_PRICE          CMONEY     8714
	char     chForceCloseReason;       //ǿƽԭ��     FORCE_CLOSE_REASON  VARCHAR(1) 8715
	int      iIsAutoSuspend;           //�Զ������־   IS_AUTO_SUSPEND     SMALLINT   8716
	char     szBusinessUnit[21+1];    //ҵ��Ԫ     BUSINESS_UNIT       VARCHAR(21)8717
	int      iRequestId;               //������     REQUEST_ID          INTEGER    8718
	int      iSequenceNo;              //���       SEQUENCE_NO         SMALLINT   8832
	char     szTradingDay[9+1];       //������      TRADING_DAY         VARCHAR(9) 8844
	int      iSettlementId;            //������     SETTLEMENT_ID       SMALLINT   8744
	int      iBrokerOrderSeq;          //���͹�˾������� BROKER_ORDER_SEQ    SMALLINT   8746
	char     chTradeSource;            //�ɽ���Դ     TRADE_SOURCE        VARCHAR(1) 8766
};
//Ͷ���߲�ѯ
struct MATRADEAPI CReqFutureCustInfoField
{
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
};

struct MATRADEAPI CRspFutureCustInfoField
{
	int      iErrorId;                //�������    ERROR_ID            SMALLINT    8900
	char     szErrorMsg[81+1];       //������Ϣ    ERROR_MSG           VARCHAR(81) 8901
	char     szInvestorId[13+1];     //Ͷ���ߴ���   INVESTOR_ID         VARCHAR(13) 8903
	char     szBrokerId[11+1];       //���͹�˾����  BROKER_ID           VARCHAR(11) 8890
	char     szInvestorGroupId[13+1];//Ͷ���߷������ INVESTOR_GROUP_ID   VARCHAR(13) 8749
	char     szInvestorName[81+1];   //Ͷ��������   INVESTOR_NAME       VARCHAR(81) 8938
	char     chIdentifiedCardType;    //֤������    IDENTIFIED_CARD_TYPEVARCHAR(1)  8893
	char     szIdentifiedCardNo[51+1];//֤������    IDENTIFIED_CARD_NO  VARCHAR(51) 8894
	int      iIsActive;               //�Ƿ��Ծ    IS_ACTIVE           SMALLINT    8767
	char     szTelephone[41+1];      //��ϵ�绰    TELEPHONE           VARCHAR(41) 8768
	char     szAddress[101+1];       //ͨѶ��ַ    ADDRESS             VARCHAR(101)8769
	char     szOpendate[9+1];        //��������    OPENDATE            VARCHAR(9)  8895
	char     szMobile[41+1];         //�ֻ�      MOBILE              VARCHAR(41) 8770
	char     szCommmodelId[13+1];    //��������ģ�����COMMMODEL_ID        VARCHAR(13) 8771
	char     szMarginmodelId[13+1];  //��֤����ģ�����MARGINMODEL_ID      VARCHAR(13) 8772
};
//Ͷ���ֲֲ߳�ѯ
struct MATRADEAPI CReqFuturePosInfoField
{
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
  char     szCustCode[16+1];     //�ͻ�����CUST_CODE      VARCHAR(16)
	char     szInstrumentId[31+1];//��Լ����INSTRUMENT_IDVARCHAR(31)X 48  
};

struct MATRADEAPI CRspFuturePosInfoField
{
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	char     szExchangeId[9+1];  //���������� EXCHANGE_ID     VARCHAR(9) 207 
	char     szExchangeName[31+1];//���������� EXCHANGE_NAME   VARCHAR(31)9441
	char     szInstrumentId[31+1];//��Լ����  INSTRUMENT_ID   VARCHAR(31)48  
	char     szInstrumentName[21+1];//��Լ����  INSTRUMENT_NAME VARCHAR(21)55  
	char     szHedgeFlag[5+1];   //Ͷ�����  HEDGE_FLAG      VARCHAR(5) 8939
	char     chPosiDirection;     //�ֲֶ�շ���POSI_DIRECTION  VARCHAR(1) 8740
	LONGLONG llPositionVolume;    //�ֲ���   POSITION_VOLUME BIGINT     9351
	LONGLONG llExeAvl;            //��ִ����  EXE_AVL         BIGINT     8869
	int      iCloseFrzVolume;     //ƽ�ֶ�������CLOSE_FRZ_VOLUMESMALLINT   8870
	char     szPositionCost[21+1];//�ֲ־���  POSITION_COST   CMONEY     8785
	char     szOpenCost[21+1];    //���־���  OPEN_COST       CMONEY     8700
	char     szLatestPrice[21+1]; //���¼�   LATEST_PRICE    CMONEY     9094
	char     szHedgeName[31+1];  //Ͷ������  HEDGE_NAME      VARCHAR(31)9414
	char     szFloatProfit[21+1]; //����ӯ��  FLOAT_PROFIT    CMONEY     8796
	char     szExchangeCode[31+1];//���ױ���  EXCHANGE_CODE   VARCHAR(31)9080
	char     szProductCode[31+1];//Ʒ�ִ���  PRODUCT_CODE    VARCHAR(31)8705
	char     szProductName[31+1];//Ʒ������  PRODUCT_NAME    VARCHAR(31)8706
	char     szUseMargin[21+1];   //�ֱֲ�֤�� USE_MARGIN      CMONEY     8787
	char     szDelivDate[31+1];  //������   DELIV_DATE      VARCHAR(31)9151
};
//��Լ��ѯ
struct MATRADEAPI CReqFutureContractInfoField
{
	char     szInstrumentId[31+1];//��Լ����    INSTRUMENT_ID   VARCHAR(31)X 48  
	char     szExchangeId[9+1];//����������   EXCHANGE_ID     VARCHAR(9) X 207 
	char     szExchangeInstId[31+1];//��Լ�ڽ���������EXCHANGE_INST_IDVARCHAR(31)X 8725
	char     szProductId[31+1];//��Ʒ����    PRODUCT_ID      VARCHAR(31)X 8705
};

struct MATRADEAPI CRspFutureContractInfoField
{
	int      iErrorId;                    //�������         ERROR_ID                 SMALLINT   8900
	char     szErrorMsg[81+1];           //������Ϣ         ERROR_MSG                VARCHAR(81)8901
	char     szInstrumentId[31+1];       //��Լ����         INSTRUMENT_ID            VARCHAR(31)48  
	char     szExchangeId[9+1];          //����������        EXCHANGE_ID              VARCHAR(9) 207 
	char     szInstrumentName[21+1];     //��Լ����         INSTRUMENT_NAME          VARCHAR(21)55  
	char     szExchangeInstId[31+1];     //��Լ�ڽ������Ĵ���    EXCHANGE_INST_ID         VARCHAR(31)8725
	char     szProductId[31+1];          //��Ʒ����         PRODUCT_ID               VARCHAR(31)8705
	char     chProductClass;              //��Ʒ����         PRODUCT_CLASS            VARCHAR(1) 8706
	int      iDeliveryYear;               //�������         DELIVERY_YEAR            SMALLINT   8707
	int      iDeliveryMonth;              //������          DELIVERY_MONTH           SMALLINT   8708
	LONGLONG llMaxMarketOrderVolume;      //�м۵�����µ���     MAX_MARKET_ORDER_VOLUME  BIGINT     8670
	LONGLONG llMinMarketOrderVolume;      //�м۵���С�µ���     MIN_MARKET_ORDER_VOLUME  BIGINT     8671
	LONGLONG llMaxLimitOrderVolume;       //�޼۵�����µ���     MAX_LIMIT_ORDER_VOLUME   BIGINT     8672
	LONGLONG llMinLimitOrderVolume;       //�޼۵���С�µ���     MIN_LIMIT_ORDER_VOLUME   BIGINT     8673
	LONGLONG llVolumeMultiple;            //��Լ��������       VOLUME_MULTIPLE          BIGINT     8674
	char     szPriceTick[21+1];           //��С�䶯��λ       PRICE_TICK               CMONEY     8675
	char     szCreateDate[9+1];          //������          CREATE_DATE              VARCHAR(9) 8676
	char     szOpenDate[9+1];            //������          OPEN_DATE                VARCHAR(9) 8677
	char     szExpireDate[9+1];          //������          EXPIRE_DATE              VARCHAR(9) 8678
	char     szStartDelivDate[9+1];      //��ʼ������        START_DELIV_DATE         VARCHAR(9) 8679
	char     szEndDelivDate[9+1];        //����������        END_DELIV_DATE           VARCHAR(9) 8680
	char     chInstLifePhase;             //��Լ��������״̬     INST_LIFE_PHASE          VARCHAR(1) 8681
	int      iIsTrading;                  //��ǰ�Ƿ���       IS_TRADING               SMALLINT   8682
	char     chPositionType;              //�ֲ�����         POSITION_TYPE            VARCHAR(1) 8683
	char     chPositionDateType;          //�ֲ���������       POSITION_DATE_TYPE       VARCHAR(1) 8773
	char     szLongMarginRatio[8+1];      //��ͷ��֤����       LONG_MARGIN_RATIO        CRATE      8684
	char     szShortMarginRatio[8+1];     //��ͷ��֤����       SHORT_MARGIN_RATIO       CRATE      8685
	char     chMaxMarginSideAlgorithm;    //�Ƿ�ʹ�ô��߱�֤���㷨MAX_MARGIN_SIDE_ALGORITHMVARCHAR(1) 8686
};
//Ͷ�����ʽ��ѯ
struct MATRADEAPI CReqFutureFundInfoField
{
	char     szCuacctCode[16+1]; //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
  char     chCuacctType; //�˻�����	CUACCT_TYPE	CHAR(1)	��	8826
  char     szCustCode[16+1]; //�ͻ�����	CUST_CODE	VARCHAR(16)	X	8902
};

struct MATRADEAPI CRspFutureFundInfoField
{
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	char     szCurrencyType[5+1];    //����     CURRENCY_TYPE      VARCHAR(5) 15  
	char     szClentName[31+1];      //�ͻ����   CLENT_NAME         VARCHAR(31)8910
	int      iTrdDate;                //��������   TRD_DATE           INTEGER    8844
	char     szPrebalanceAmout[21+1]; //���ս��   PREBALANCE_AMOUT   CMONEY     8604
	char     szAvailableAmout[21+1];  //�����ʽ�   AVAILABLE_AMOUT    CMONEY     8611
	char     szLongFrozen[21+1];      //�򶳽�    LONG_FROZEN        CMONEY     8776
	char     szShortFrozen[21+1];     //������    SHORT_FROZEN       CMONEY     8778
	char     szFrozenCommission[21+1];//����������  FROZEN_COMMISSION  CMONEY     8790
	char     szCommission[21+1];      //������    COMMISSION         CMONEY     8792
	char     szBuyMargin[21+1];       //��֤��   BUY_MARGIN         CMONEY     9403
	char     szSellMargin[21+1];      //����֤��   SELL_MARGIN        CMONEY     9405
	char     szCloseProfit[21+1];     //ƽ��ӯ��   CLOSE_PROFIT       CMONEY     8793
	char     szFloatProfit[21+1];     //����ӯ��   FLOAT_PROFIT       CMONEY     9089
	char     szFundTrdOtd[21+1];      //��;�ʽ�   FUND_TRD_OTD       CMONEY     8866
	char     szNoDeliveryProfit[21+1];//δ����ӯ��  NO_DELIVERY_PROFIT CMONEY     9406
	char     szDepositAmout[21+1];    //�������   DEPOSIT_AMOUT      CMONEY     8607
	char     szWithdrawAmout[21+1];   //���ճ���   WITHDRAW_AMOUT     CMONEY     8608
	char     szDynamicRight[21+1];    //��̬Ȩ��   DYNAMIC_RIGHT      CMONEY     9350
	char     szFrozenCash[21+1];      //�����ʽ�   FROZEN_CASH        CMONEY     8789
	char     szCurrmargin[21+1];      //�ܱ�֤��   CURRMARGIN         CMONEY     8609
	char     szExchangeMargin[21+1];  //��������֤�� EXCHANGE_MARGIN    CMONEY     8701
	char     szMortgageAmout[21+1];   //��Ѻ���   MORTGAGE_AMOUT     CMONEY     8615
	char     szCreditAmout[21+1];     //���ý��   CREDIT_AMOUT       CMONEY     8614
	char     szRiskLevel[21+1];       //���ռ���   RISK_LEVEL         CMONEY     9407
	char     szRiskLevel1[21+1];      //���ն�1   RISK_LEVEL_1       CMONEY     9408
	char     szRiskLevel2[21+1];      //���ն�2   RISK_LEVEL_2       CMONEY     9409
	char     szDynamicmarketRight[21+1];//��ֵ��̬Ȩ�� DYNAMICMARKET_RIGHTCMONEY     9083
	char     szExeDynamicMargin[21+1];//ִ�ж��ᱣ֤��EXE_DYNAMIC_MARGIN CMONEY     9410
	char     szCurrentMargin[21+1];   //ʵʱ��֤��  CURRENT_MARGIN     CMONEY     9411
	char     szPreferentialMargin[21+1];//�Żݱ�֤��  PREFERENTIAL_MARGINCMONEY     9412
	char     szAddMargin[21+1];       //׷�ӱ�֤��  ADD_MARGIN         CMONEY     9413
};
//���ɿ�������
struct MATRADEAPI CReqFutureAvlQtyField
{
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	char     szInstrumentId[31+1];//��Լ���� INSTRUMENT_IDVARCHAR(31)Y 48  
	char     szExchangeId[9+1];//����������EXCHANGE_ID  VARCHAR(9) Y 207 
	int      iStkBiz;       //֤ȯҵ�� STK_BIZ      SMALLINT   Y 8842
	char     szOrderPrice[21+1];//�۸�   ORDER_PRICE  CMONEY     X 44  
};

struct MATRADEAPI CRspFutureAvlQtyField
{
	LONGLONG llOrderQty;          //�ɿ�������ORDER_QTY      BIGINT 38  ��ί���������
	char     szAvailableAmout[21+1];//�����ʽ� AVAILABLE_AMOUTCMONEY 8611
	LONGLONG llBuyOrderQty;       //��������BUY_ORDER_QTY  BIGINT 9080
	int      iSellOrderQty;       //����������SELL_ORDER_QTY INTEGER9081
	LONGLONG llMarketValue;       //��̬Ȩ�� MARKET_VALUE   BIGINT 9082
};
//����ƽ������
struct MATRADEAPI CReqFutureAvlPosField
{
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	char     szInstrumentId[31+1];//��Լ���� INSTRUMENT_IDVARCHAR(31)Y 48  
	char     szExchangeId[9+1];//����������EXCHANGE_ID  VARCHAR(9) Y 207 
	int      iStkBiz;       //֤ȯҵ�� STK_BIZ      SMALLINT   Y 8842
	char     szStkpbu[8+1];//ϯλ��  STKPBU       VARCHAR(8) Y 8843
};

struct MATRADEAPI CRspFutureAvlPosField
{
	char     szMktTrdCode[31+1]; //���ױ��� MKT_TRD_CODE   VARCHAR(31)9080
	char     szInstrumentId[31+1];//��Լ���� INSTRUMENT_ID  VARCHAR(31)48  
	char     szAvailableAmout[21+1];//�����ʽ� AVAILABLE_AMOUTCMONEY     8611
	LONGLONG llOrderQty;          //��ƽ������ORDER_QTY      BIGINT     38  ��ί���������
	LONGLONG llTodayOrderQty;     //��ƽ������TODAY_ORDER_QTYBIGINT     9081��ί���������
	char     szStkpbu[8+1];      //ϯλ��  STKPBU         VARCHAR(8) 8843
	LONGLONG llMarketValue;       //��̬Ȩ�� MARKET_VALUE   BIGINT     9082
};
//�ͻ�����ѯ
struct MATRADEAPI CReqFutureUsersOnlineField
{
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
};

struct MATRADEAPI CRspFutureUsersOnlineField
{
	int      iUerNum;    //�ͻ���UER_NUMSMALLINT8600
};

//�������ʲ�ѯ
struct MATRADEAPI CReqFutureFeeField
{
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	int      iTrdDate;      //�������� TRD_DATE     SMALLINT   X 8844
	char     szExchangeId[9+1];//����������EXCHANGE_ID  VARCHAR(9) X 207 ����������
	char     szInstrumentId[31+1];//��Լ���� INSTRUMENT_IDVARCHAR(31)X 48  
};

struct MATRADEAPI CRspFutureFeeField
{
	int      iTrdDate;                           //��������      TRD_DATE                        SMALLINT   8844
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	char     szExchangeId[9+1];                 //����������     EXCHANGE_ID                     VARCHAR(9) 207 
	char     szSeatId[12+1];                    //ϯλ��       SEAT_ID                         VARCHAR(12)8724
	char     szProductId[31+1];                 //Ʒ�ִ���      PRODUCT_ID                      VARCHAR(31)8705
	char     szDeliveryDate[31+1];              //������       DELIVERY_DATE                   VARCHAR(31)9151
	char     szBuketOpenCommissionByqty[21+1];   //Ͷ����ƽ�����Ѱ�����BUKET_OPEN_COMMISSION_BYQTY     CMONEY     9415
	char     szBuketOpenCommissionByamt[21+1];   //Ͷ����ƽ�����Ѱ����BUKET_OPEN_COMMISSION_BYAMT     CMONEY     9416
	char     szBuketCloseCommissionByqty[21+1];  //Ͷ��ƽ�������Ѱ�����BUKET_CLOSE_COMMISSION_BYQTY    CMONEY     9417
	char     szBuketCloseCommissionByamt[21+1];  //Ͷ��ƽ�������Ѱ����BUKET_CLOSE_COMMISSION_BYAMT    CMONEY     9418
	char     szHedgeOpenCommissionByqty[21+1];   //��ֵ��ƽ�����Ѱ�����HEDGE_OPEN_COMMISSION_BYQTY     CMONEY     9419
	char     szHedgeOpenCommissionByamt[21+1];   //��ֵ��ƽ�����Ѱ����HEDGE_OPEN_COMMISSION_BYAMT     CMONEY     9420
	char     szHedgeCloseCommissionByqty[21+1];  //��ֵƽ�������Ѱ�����HEDGE_CLOSE_COMMISSION_BYQTY    CMONEY     9421
	char     szHedgeCloseCommissionByamt[21+1];  //��ֵƽ�������Ѱ����HEDGE_CLOSE_COMMISSION_BYAMT    CMONEY     9422
	char     szArbitrageOpenCommissionByqty[21+1];//������ƽ�����Ѱ�����ARBITRAGE_OPEN_COMMISSION_BYQTY CMONEY     9423
	char     szArbitrageOpenCommissionByamt[21+1];//������ƽ�����Ѱ����ARBITRAGE_OPEN_COMMISSION_BYAMT CMONEY     9424
	char     szArbitrageCloseCommissionByqty[21+1];//����ƽ�������Ѱ�����ARBITRAGE_CLOSE_COMMISSION_BYQTYCMONEY     9425
	char     szArbitrageCloseCommissionByamt[21+1];//����ƽ�������Ѱ����ARBITRAGE_CLOSE_COMMISSION_BYAMTCMONEY     9426
	char     szExeCommissionByqty[21+1];         //ִ���������ʣ�������EXE_COMMISSION_BYQTY            CMONEY     9427
	char     szExeCommissionByamt[21+1];         //ִ���������ʣ���EXE_COMMISSION_BYAMT            CMONEY     9428
	char     szInstrumentId[31+1];              //��Լ����      INSTRUMENT_ID                   VARCHAR(31)48  
};
//��֤���ʲ�ѯ
struct MATRADEAPI CReqFutureMarginField
{
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	int      iTrdDate;      //�������� TRD_DATE     SMALLINT   X 8844
	char     szExchangeId[9+1];//����������EXCHANGE_ID  VARCHAR(9) X 207 ����������
	char     szInstrumentId[31+1];//��Լ���� INSTRUMENT_IDVARCHAR(31)X 48  
};

struct MATRADEAPI CRspFutureMarginField
{
	int      iTrdDate;                      //��������     TRD_DATE                   SMALLINT   8844
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	char     szExchangeId[9+1];            //����������    EXCHANGE_ID                VARCHAR(9) 207 
	char     szSeatId[12+1];               //ϯλ��      SEAT_ID                    VARCHAR(12)8724
	char     szProductId[31+1];            //Ʒ�ִ���     PRODUCT_ID                 VARCHAR(31)8705
	char     szDeliveryDate[31+1];         //������      DELIVERY_DATE              VARCHAR(31)9151
	char     szBuketBuyMarginByqty[21+1];   //Ͷ����֤������BUKET_BUY_MARGIN_BYQTY     CMONEY     9429
	char     szBuketBuyMarginByamt[21+1];   //Ͷ����֤�𰴽��BUKET_BUY_MARGIN_BYAMT     CMONEY     9430
	char     szBuketSellMarginByqty[21+1];  //Ͷ������֤������BUKET_SELL_MARGIN_BYQTY    CMONEY     9431
	char     szBuketSellMarginByamt[21+1];  //Ͷ������֤�𰴽��BUKET_SELL_MARGIN_BYAMT    CMONEY     9432
	char     szHedgeBuyMarginByqty[21+1];   //��ֵ��֤������HEDGE_BUY_MARGIN_BYQTY     CMONEY     9433
	char     szHedgeBuyMarginByamt[21+1];   //��ֵ��֤�𰴽��HEDGE_BUY_MARGIN_BYAMT     CMONEY     9434
	char     szHedgeSellMarginByqty[21+1];  //��ֵ����֤������HEDGE_SELL_MARGIN_BYQTY    CMONEY     9435
	char     szHedgeSellMarginByamt[21+1];  //��ֵ����֤�𰴽��HEDGE_SELL_MARGIN_BYAMT    CMONEY     9436
	char     szArbitrageBuyMarginByqty[21+1];//������֤������ARBITRAGE_BUY_MARGIN_BYQTY CMONEY     9437
	char     szArbitrageBuyMarginByamt[21+1];//������֤�𰴽��ARBITRAGE_BUY_MARGIN_BYAMT CMONEY     9438
	char     szArbitrageSellMarginByqty[21+1];//��������֤������ARBITRAGE_SELL_MARGIN_BYQTYCMONEY     9439
	char     szArbitrageSellMarginByamt[21+1];//��������֤�𰴽��ARBITRAGE_SELL_MARGIN_BYAMTCMONEY     9440
	char     szInstrumentId[31+1];         //��Լ����     INSTRUMENT_ID              VARCHAR(31)48  
};
//�������ڲ�ѯ
struct MATRADEAPI CReqFutureDateInfoField
{
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
};

struct MATRADEAPI CRspFutureDateInfoField
{
	int      iTrdDate;        //��������TRD_DATE   SMALLINT   8844
	char     szSystemDate[32+1];//ϵͳ����SYSTEM_DATEVARCHAR(32)9093
	char     szSystemTime[32+1];//ϵͳʱ��SYSTEM_TIMEVARCHAR(32)9092
};
//ί������
struct MATRADEAPI CRtnFutureOrderField
{
	char     szBrokerId[11+1];         //���͹�˾����      BROKER_ID              VARCHAR(11)8890
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	char     szInstrumentId[31+1];     //��Լ����        INSTRUMENT_ID          VARCHAR(31)48  
	char     szOrderRef[13+1];         //��������        ORDER_REF              VARCHAR(13)8738
	char     szUserId[16+1];           //�û�����        USER_ID                VARCHAR(16)9080
	char     chOrderPriceType;          //�����۸�����      ORDER_PRICE_TYPE       VARCHAR(1) 8739
	char     chDirection;               //��������        DIRECTION              VARCHAR(1) 8740
	char     szCombOffsetFlag[5+1];    //��Ͽ�ƽ��־      COMB_OFFSET_FLAG       VARCHAR(5) 8741
	char     szCombHedgeFlag[5+1];     //���Ͷ���ױ���־    COMB_HEDGE_FLAG        VARCHAR(5) 8742
	char     szLimitPrice[21+1];        //�۸�          LIMIT_PRICE            CMONEY     8958
	LONGLONG llVolumeTotalOriginal;     //����          VOLUME_TOTAL_ORIGINAL  BIGINT     8986
	char     chTimeCondition;           //��Ч������       TIME_CONDITION         VARCHAR(1) 8710
	char     szGtdDate[9+1];           //GTD����       GTD_DATE               VARCHAR(9) 8723
	char     chVolumeCondition;         //�ɽ�������       VOLUME_CONDITION       VARCHAR(1) 8711
	LONGLONG llMinVolume;               //��С�ɽ���       MIN_VOLUME             BIGINT     8712
	char     chContingentCondition;     //��������        CONTINGENT_CONDITION   VARCHAR(1) 8713
	char     szStopPrice[21+1];         //ֹ���         STOP_PRICE             CMONEY     8714
	char     chForceCloseReason;        //ǿƽԭ��        FORCE_CLOSE_REASON     VARCHAR(1) 8715
	int      iIsAutoSuspend;            //�Զ������־      IS_AUTO_SUSPEND        SMALLINT   8716
	char     szBusinessUnit[21+1];     //ҵ��Ԫ        BUSINESS_UNIT          VARCHAR(21)8717
	int      iRequestId;                //������        REQUEST_ID             INTEGER    8718
	char     szOrderLocalId[13+1];     //���ر������      ORDER_LOCAL_ID         VARCHAR(13)8722
	char     szExchangeId[9+1];        //����������       EXCHANGE_ID            VARCHAR(9) 207 
	char     szParticipantId[11+1];    //��Ա����        PARTICIPANT_ID         VARCHAR(11)8724
	char     szClientId[11+1];         //�ͻ�����        CLIENT_ID              VARCHAR(11)8902
	char     szExchangeInstId[31+1];   //��Լ�ڽ������Ĵ���   EXCHANGE_INST_ID       VARCHAR(31)8725
	char     szTraderId[21+1];         //����������Ա����    TRADER_ID              VARCHAR(21)8726
	int      iInstallId;                //��װ���        INSTALL_ID             SMALLINT   8728
	char     chOrderSubmitStatus;       //�����ύ״̬      ORDER_SUBMIT_STATUS    VARCHAR(1) 8729
	int      iNotifySequence;           //������ʾ���      NOTIFY_SEQUENCE        SMALLINT   8743
	char     szTradingDay[9+1];        //������         TRADING_DAY            VARCHAR(9) 8844
	int      iSettlementId;             //������        SETTLEMENT_ID          SMALLINT   8744
	char     szOrderSysId[21+1];       //�������        ORDER_SYS_ID           VARCHAR(21)8745
	char     chOrderSource;             //������Դ        ORDER_SOURCE           VARCHAR(1) 8750
	char     chOrderStatus;             //����״̬        ORDER_STATUS           VARCHAR(1) 8751
	char     chOrderType;               //��������        ORDER_TYPE             VARCHAR(1) 8752
	LONGLONG llVolumeTraded;            //��ɽ�����       VOLUME_TRADED          BIGINT     8753
	LONGLONG llVolumeTotal;             //ʣ������        VOLUME_TOTAL           BIGINT     8754
	char     szInsertDate[9+1];        //��������        INSERT_DATE            VARCHAR(9) 8834
	char     szInsertTime[9+1];        //ί��ʱ��        INSERT_TIME            VARCHAR(9) 8845
	char     szActiveTime[9+1];        //����ʱ��        ACTIVE_TIME            VARCHAR(9) 8755
	char     szSuspendTime[9+1];       //����ʱ��        SUSPEND_TIME           VARCHAR(9) 8756
	char     szUpdateTime[9+1];        //����޸�ʱ��      UPDATE_TIME            VARCHAR(9) 8757
	char     szCancelTime[9+1];        //����ʱ��        CANCEL_TIME            VARCHAR(9) 8758
	char     szActiveTraderId[21+1];   //����޸Ľ���������Ա����ACTIVE_TRADER_ID       VARCHAR(21)8727
	char     szClearingPartId[11+1];   //�����Ա���      CLEARING_PART_ID       VARCHAR(11)8759
	int      iSequenceNo;               //���          SEQUENCE_NO            SMALLINT   8832
	char     szUserProductInfo[11+1];  //�û��˲�Ʒ��Ϣ     USER_PRODUCT_INFO      VARCHAR(11)8730
	char     szStatusMsg[81+1];        //״̬��Ϣ        STATUS_MSG             VARCHAR(81)8760
	int      iUserForceClose;           //�û�ǿ����־      USER_FORCE_CLOSE       SMALLINT   8719
	char     szActiveUserId[16+1];     //�����û�����      ACTIVE_USER_ID         VARCHAR(16)8810
	int      iBrokerOrderSeq;           //���͹�˾�������    BROKER_ORDER_SEQ       SMALLINT   8746
	char     szRealtiveOrderSysId[21+1];//��ر���        REALTIVE_ORDER_SYS_ID  VARCHAR(21)8761
	LONGLONG llZceTotalTradedVolume;    //֣�����ɽ�����     ZCE_TOTAL_TRADED_VOLUMEBIGINT     8762
	int      iIsSwapOrder;              //��������־       IS_SWAP_ORDER          SMALLINT   8720
	int      iFrontId;                  //ǰ�ñ��        FRONT_ID               INTEGER    8732
	LONGLONG llSessionId;               //�Ự���        SESSION_ID             BIGINT     8814
};
//�ɽ�����
struct MATRADEAPI CRtnFutureMatchField
{
	int      iErrorId;                //�������     ERROR_ID             SMALLINT   8900
	char     szErrorMsg[81+1];       //������Ϣ     ERROR_MSG            VARCHAR(81)8901
	char     szBrokerId[11+1];       //���͹�˾����   BROKER_ID            VARCHAR(11)8890
	char     szCuacctCode[16+1];     //�ʲ��˻� CUACCT_CODE      VARCHAR(16)     Y 8920CTP  �ͻ�ID
	char     szInstrumentId[31+1];   //��Լ����     INSTRUMENT_ID        VARCHAR(31)48  
	char     szOrderRef[13+1];       //��������     ORDER_REF            VARCHAR(13)8738
	char     szUserId[16+1];         //�û�����     USER_ID              VARCHAR(16)9080
	char     szExchangeId[9+1];      //����������    EXCHANGE_ID          VARCHAR(9) 207 
	char     szMatchedSn[16+1];      //�ɽ����     MATCHED_SN           VARCHAR(16)17  
	char     chDirection;             //��������     DIRECTION            VARCHAR(1) 8740
	char     szOrderSysId[21+1];     //�������     ORDER_SYS_ID         VARCHAR(21)8745
	char     szParticipantId[11+1];  //��Ա����     PARTICIPANT_ID       VARCHAR(11)8724
	char     szClientId[11+1];       //�ͻ�����     CLIENT_ID            VARCHAR(11)8902
	char     chTradingRole;           //���׽�ɫ     TRADING_ROLE         VARCHAR(1) 8763
	char     szExchangeInstId[31+1]; //��Լ�ڽ������Ĵ���EXCHANGE_INST_ID     VARCHAR(31)8725
	char     szCombOffsetFlag[5+1];  //��Ͽ�ƽ��־   COMB_OFFSET_FLAG     VARCHAR(5) 8741
	char     szCombHedgeFlag[5+1];   //���Ͷ���ױ���־ COMB_HEDGE_FLAG      VARCHAR(5) 8742
	LONGLONG llLimitPrice;            //�۸�       LIMIT_PRICE          BIGINT     8958
	int      iVolumeTotalOriginal;    //����       VOLUME_TOTAL_ORIGINALSMALLINT   8986
	char     szTradeDate[9+1];       //�ɽ�ʱ��     TRADE_DATE           VARCHAR(9) 8839
	char     szTradeTime[9+1];       //�ɽ�ʱ��     TRADE_TIME           VARCHAR(9) 8840
	char     chTradeType;             //�ɽ�����     TRADE_TYPE           VARCHAR(1) 8764
	char     chPriceSource;           //�ɽ�����Դ    PRICE_SOURCE         VARCHAR(1) 8765
	char     szTraderId[21+1];       //����������Ա���� TRADER_ID            VARCHAR(21)8726
	char     szOrderLocalId[13+1];   //���ر������   ORDER_LOCAL_ID       VARCHAR(13)8722
	char     szClearingPartId[11+1]; //�����Ա���   CLEARING_PART_ID     VARCHAR(11)8759
	char     szBusinessUnit[21+1];   //ҵ��Ԫ     BUSINESS_UNIT        VARCHAR(21)8717
	int      iSequenceNo;             //���       SEQUENCE_NO          SMALLINT   8832
	char     szTradingDay[9+1];      //������      TRADING_DAY          VARCHAR(9) 8844
	int      iSettlementId;           //������     SETTLEMENT_ID        SMALLINT   8744
	int      iBrokerOrderSeq;         //���͹�˾������� BROKER_ORDER_SEQ     SMALLINT   8746
	char     chTradeSource;           //�ɽ���Դ     TRADE_SOURCE         VARCHAR(1) 8766
};
END_NAMESPACE_MACLI
#endif//__MA_CLI_FUTURE_TRADE_API_STRUCT_H__