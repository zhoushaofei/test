#pragma once
#pragma pack(push,1)
//֤ȯ����
typedef struct
{
    char     Market[4];           //������
    char     StockCode[12];       //֤ȯ����
    char     StockName[16];       //֤ȯ����
    char     PhoneticCode[8];     //ƴ������
    char     StockType[4];        //֤ȯ���
    double   PriceTick;           //���׼�λ
    double   TradeUnit;           //���׵�λ
    int      MaxTradeAmt;         //ί������
    int      MinTradeAmt;         //ί������
    char     MoneyType[4];        //����
    double   LastPrice;           //���¼�
    double   HighLimitPrice;      //��߱���--��ͣ��
    double   LowLimitPrice;       //��ͱ���--��ͣ��
    int      NetPriceFlag;        //��ծ���۱�־
    int      QtyTick;             //������--�۹�
    double   LastClosePrice;      //������
    double   OpenPrice;           //����
    int      SuspendFlag;         //ͣ�Ʊ�־
    double   MatchQty;            //�ɽ�����
    double   MatchAmt;            //�ɽ����
    double   HighPrice;           //��߼�
    double   LowPrice;            //��ͼ�
    double   BidPrice1;           //����۸�1
    double   BidPrice2;           //����۸�2
    double   BidPrice3;           //����۸�3
    double   BidPrice4;           //����۸�4
    double   BidPrice5;           //����۸�5
    double   AskPrice1;           //�����۸�1
    double   AskPrice2;           //�����۸�2
    double   AskPrice3;           //�����۸�3
    double   AskPrice4;           //�����۸�4
    double   AskPrice5;           //�����۸�5
    int      BidQty1;             //��������1
    int      BidQty2;             //��������2
    int      BidQty3;             //��������3
    int      BidQty4;             //��������4
    int      BidQty5;             //��������5
    int      AskQty1;             //��������1
    int      AskQty2;             //��������2
    int      AskQty3;             //��������3
    int      AskQty4;             //��������4
    int      AskQty5;             //��������5
    double   InterestPrice;       //��Ϣ����
    double   FloatShareQty;       //��ͨ������
    int      ListDate;            //��������
    int      PaymentDate;         //�Ҹ�����
    double   StrikePrice;         //��Ȩ�۸�--��Ȩ
    char     StrikeCode[16];      //��Ȩ����--��Ȩ
    char     OrderTypeAvl[64];    //���ö�������
    double   UpdateTime;          //����ʱ��
} ITPDK_ZQHQ;
//�ͻ���Ϣ
typedef struct
{
    char     AccountId[16];          //�ͻ���
    char     AccountName[32];        //�ͻ�����
    char     CertificateNo[32];      //֤�����
    int      CertificateType;        //֤�����
    char     OrgCode[8];             //��������
    int      OrgAccFlag;             //�����˻���־
    int      EntrustWayAvl;          //����ί�з�ʽ
    int      ServiceAvl;             //��ͨ��Ʒ����
} ITPDK_KHH;
//�����ֵ�-�г�
typedef struct
{
    char     Market[4];           //������
    char     MarketName[16];      //���������
    char     MarketFullName[32];  //������ȫ��
} ITPDK_JYS;
//�����ֵ�-���ʲ���
typedef struct
{
    char     MoneyType1[4];       //����1
    char     MoneyType2[4];       //����2
    double   CashBuyRate;         //�ֳ������
    double   CashAskRate;         //�ֳ�������
    double   RemitBuyRate;        //�ֻ������
    double   RemitAskRate;        //�ֻ�������
    double   GSBL;                //�������
    double   JSPJJ;               //������
    int      UpdateTime;          //��������
} ITPDK_HLCS;
//�����ֵ�-ϵͳ����
typedef struct
{
    char     GroupId[32];   //�������
    char     Code[8];       //����
    char     CodeName[64];  //����˵��
} ITPDK_XTDM;
//�����ֵ�-�������
typedef struct
{
    char     EntrustType[4];         //�������
    char     EntrustTypeName[16];    //�������
} ITPDK_JYLB;
//�����ֵ�-֤ȯ��������
typedef struct
{
    char     Market[4];        //������
    char     StockType[4];     //֤ȯ���
    int      EntrustType;      //�������
    int      QtyTick;          //���׻���
    int      EntrustWay;       //ί�з�ʽ
} ITPDK_ZQJYSX;
//����
typedef struct
{
    char     MoneyType[4];        //����
    char     MoneyTypeName[16];   //��������
} ITPDK_BZ;
//�����ֵ�-��������
typedef struct
{
    char     OrgCode[8];    //��������
    char     OrgName[32];   //��������
} ITPDK_JGDM;
//�����ֵ�-���в���
typedef struct
{
    char     BankCode[8];         //���д���
    char     MoneyType[4];        //����
    char     BusinessAvl[64];     //����֤ȯ�����ҵ�����
    char     CheckFundPwd[64];    //��ҪУ���ʽ������ҵ�����
    char     CheckBankPwd[64];    //��ҪУ�����������ҵ�����
} ITPDK_YHCS;
//�����¹��깺
typedef struct
{
    int      Flag;             //��� 1.�����¹ɷ��� 2.���տ�תծ���ɽ���ծ���� ��A5�޸��ֶΣ�
    char     Market[4];        //������
    char     StockCode[12];    //֤ȯ����
    char     StockName[16];    //֤ȯ����
    char     RGCode[12];       //�Ϲ�����
    int      RGRQ;             //�Ϲ�����
    double   IssuePrice;       //���м۸�
    int64      MaxTradeAmt;    //ί������
    int      MinTradeAmt;      //ί�����ޣ�A5�޸��ֶΣ�
    char     MoneyType[4];     //���֣�A5�޸��ֶΣ�
    int      UpdateTime;       //����ʱ��
} ITPDK_XGSG;
//�����ֵ�-�۹ɽ��׼�λ
typedef struct
{
    char     Market[4];        //������
    char     StockType[4];     //֤ȯ���
    double   BeginPrice;       //��ʼ�۸�
    double   EndPrice;         //�����۸�
    double   PriceTick;        //���ü�λ
    int      UpdateTime;       //��������
} ITPDK_JYJW;
//�����ֵ�-ETF������Ϣ
typedef struct
{
    char     Market[4];              //������
    char     FundCode[8];            //�������
    char     FundName[16];           //��������
    char     SubsAndRedeCode[8];     //�깺��ش���
    int64    SubsAndRedeUnit;        //�깺��ص�λ
    double   CashComponent;          //T��ÿ�������ֽ���
    double   CashDiff;               //Ԥ���ֽ���
    double   MaxCashRatio;           //�ֽ������������
    double   NetAssetValue;          //T-1����λ��ֵ
    double   NAVperCU;               //�깺��ص�λ��ֵ
    char     TradingDate[12];        //��������
} ITPDK_ETFXX;
//�����ֵ�-ETF�ɷֹ���Ϣ
typedef struct
{
    char     FundCode[8];         //�������
    char     Market[4];           //������
    char     StockCode[12];       //֤ȯ����
    char     StockName[16];       //֤ȯ����
    int64    ComponentQty;        //�ɷݹ�����
    double   PremiumRatio;        //��۱���
    double   CashSubstitute;      //������
    int      SubstituteFlag;      //�����־
    char     StockType[4];        //֤ȯ���
} ITPDK_ETFMX;
//�����ֵ�-�������
typedef struct
{
    char     Market[4];                 //������
    char     StockCode[12];             //֤ȯ����
    char     FundCode[12];              //�������
    char     FundName[44];              //��������
    int      DivideAndMergeStatus;      //������״̬
    double   NetValue;                  //����ֵ
    double   TotalNAV;                  //�ۼƾ�ֵ
    int      DivideRate;                //��ֱ���
    double   MinMergeQty;               //��ͺϲ�����
    double   MinDivideQty;              //��Ͳ������
} ITPDK_JJHQ;
//�ּ�������Ϣ
typedef struct
{
    char     Market[4];                 //������
    char     FundCode_M[12];            //ĸ������
    char     FundName_M[20];            //ĸ������
    double   FundNetValue_M;            //ĸ����ֵ
    double   FundPrice_M;               //ĸ���۸�
    char     IndexCode[12];             //ָ������
    char     IndexName[12];             //ָ������
    double   IndexRate;                 //ָ���ǵ���
    char     FundManager[36];           //���������
    double   SubscribeFeeRate;          //�깺����
    double   RedeemFeeRate;             //��ط���
    char     DivideRate[20];            //AB����
    int      DivideRate_A;              //A����
    int      DivideRate_B;              //B����
    int      RegularConvertFlag;        //���۱�־
    double   UpConvertLimit;            //���۷�ֵ
    double   DownConvertLimit;          //���۷�ֵ
    char     NextConvertDate[12];       //�´ζ���
    int      ExpiryDate;                //��ֹ����
    char     FundCode_A[12];            //A������
    char     FundName_A[20];            //A������
    double   FundPrice_A;               //A���ּ�
    double   FundNetValue_A;            //A����ֵ
    char     InterestRateRule[20];      //���ʹ���
    double   CurrentInterestRate;       //��������
    double   NextInterestRate;          //��������
    double   ForwardInterestRate;       //��������
    int      TradableFlag;              //�ɽ��ױ�־
    char     TradePrompt[260];          //�����ر���ʾ
    int      NetValueDate;              //��ֵ����
    int      MinMergeQty;               //����������
    int      MinDivideQty;              //��Ͳ������
    char     FundCode_B[8];             //B������
    char     FundName_B[20];            //A������
    double   FundNetValue_B;            //A����ֵ
    double   FundProce_B;               //A���ּ�
    int      UpdateTime;                //����ʱ��
    int      PreTradeVolume_M;          //T-1ĸ��������
    int      PreTradeVolume_A;          //T-1A��������
    int      PreTradeVolume_B;          //T-1B��������
    double   FundShares;                //�ݶ�
    double   DateIncFundShares;         //�������ӷݶ�
    double   WholePremiumRate;          //T-1���������
    double   PreWholePremiumRate;       //T-2���������
    char     SubscribeStatus[68];       //�����깺״̬
    char     RedeemStatus[68];          //�������״̬
    int      Status;                    //����״̬
    double   PreNetValue;               //T-1����ֵ
} ITPDK_FJJJ;
//�ɶ���
typedef struct
{
    char     AccountId[16];    //�ͻ���
    char     Market[4];        //������
    char     SecuAccount[12];  //�ɶ���
    char     HolderName[16];   //�ɶ�����
    char     FundAccount[16];  //�ʽ��ʺ�
    char     OrgCode[8];       //��������--��������
    char     MoneyType[4];     //����
    char     TradeAccess[16];  //����Ȩ��
    int      HolderType;       //�ɶ����
    int      EquityQty;        //Ȩ������(�¹��깺)
} ITPDK_GDH;
//����Ȩ��
typedef struct
{
    char     AccountId[16];    //�ͻ���
    char     Market[4];        //������
    char     SecuAccount[12];  //�ɶ���
    int64    StarQty;          //�ƴ�������
    int64    EquityQty;        //֤ȯȨ������
    int      SettleMentDate;   //��������
} ITPDK_PSQY;
//�ʽ���Ϣ
typedef struct
{
    char     AccountId[16];             //�ͻ���
    char     FundAccount[16];           //�ʽ��˺�
    char     MoneyType[4];              //����
    char     OrgCode[8];                //��������
    int      MasterFlag;                //���ʻ���־
    int      AccountType;               //�ʻ����
    double   LastBalance;               //�������
    double   CurrentBalance;            //�˻����
    double   FrozenBalance;             //�����ʽ�
    double   T2_FrozenBalance;          //T+2������
    double   FundAvl;                   //�����ʽ�
    double   T2_FundAvl;                //T+2�����ʽ�
    double   TotalAsset;                //���ʲ�
    double   MarketValue;               //������ֵ
    double   DebtAmt;                   //��ծ���
    double   CreditQuota;               //���ö��
    double   CreditQuotaAvl;            //�������ö��
    double   UncomeBalance;             //δ�����ʽ�
    double   CashBalance;               //�ֽ����
    double   CashAsset;                 //�ֽ��ʲ�
    double   OtherAsset;                //�����ʲ�
    double   FetchBalance;              //��ȡ�ʽ�
    double   DateProfit;                //����ӯ��
    double   UnclearProfit;             //����ӯ��
    double   DiluteUnclearProfit;       //̯������ӯ��
    double   UpdateTime;                //����ʱ��
    double 	 SettleBalance;				// ʵʱ�����ʽ�
    double   ContractPosiValue;				//��Լ�ֲ���ֵ(��Ȩ��չ��ѯ)
    double   LastPositionValue;			//���ճֲ���ֵ(��Ȩ��չ��ѯ)
} ITPDK_ZJZH;
//�ʲ�����
typedef struct
{
    char     AccountId[16];          //�ͻ���
    char     MoneyType[4];           //����
    char     CollectItem[16];        //��Ʒ��Ŀ
    char     AccountCode[16];        //�ʻ�����
    double   AssetAmt;               //�ʲ����
    double   DebtAmt;                //��ծ���
    double   NetAsset;               //���ʲ�
    double   NoNegotiableValue;      //����ͨ��ֵ
    double   UpdateTime;             //����ʱ��
} ITPDK_ZCXX;
//�����˺�
typedef struct
{
    char     AccountId[16];    //�ͻ���
    char     BankAccount[32];  //�����˺�
    char     FundAccount[16];  //�ʽ��˺�
    char     BankCode[8];      //���д���
    char     BankName[32];     //��������
    char     MoneyType[4];     //����
} ITPDK_YHZH;
//֤ȯ�ֲ�
typedef struct
{
    char     AccountId[16];             //�ͻ���
    char     Market[4];                 //������
    char     StockCode[12];             //֤ȯ����
    char     SecuAccount[12];           //�ɶ���
    char     FundAccount[16];           //�ʽ��˺�
    int      AccountType;               //�˻����
    char     MoneyType[4];              //����
    char     StockName[16];             //֤ȯ����
    int64    CurrentQty;                //��ֲ���
    int64    QtyAvl;                    //����������
    double   LastPrice;                 //���¼�
    double   MarketValue;               //������ֵ
    double   DateProfit;                //����ӯ��
    double   CostPrice;                 //�ֲ־���
    double   UnclearProfit;             //����ӯ��
    double   DividendAmt;               //�������
    double   RealizeProfit;             //ʵ��ӯ��
    int64     PreQty;                    //��ֲ���
    int64     FrozenQty;                 //��������
    int64     UncomeQty;                 //δ��������
    double   CostBalance;               //�ֲֳɱ�
    double   DiluteCostPrice;           //̯���ɱ���
    double   KeepCostPrice;             //������
    double   AvgBuyPrice;               //�������
    int64     AllotmentQty;              //�������
    int64     SubscribeQty;              //�깺����
    char     OpenDate[12];              //��������
    double   InterestPrice;             //��Ϣ����
    double   Dilutekeep_CostPrice;      //̯��������
    double   DiluteUnclearProfit;       //̯������ӯ��
    int64     TradeUnit;                 //���׵�λ
    int64     SubscribableQty;           //���깺����
    int64     RedeemableQty;             //���������
    int64     RealSubsQty;               //�깺�ɽ�����
    int64     RealRedeQty;               //��سɽ�����
    int64    TotalSellQty;              //�ۼ���������
    int64    TotalBuyQty;               //�ۼ���������
    double   TotalSellAmt;              //�������
    double   TotalBuyAmt;               //������
    double   AllotmentAmt;              //��ɽ��
    int64     RealBuyQty;                //��������ɽ�����
    int64     RealSellQty;               //���������ɽ�����
    double   RealBuyBalance;            //��������ɽ����
    double   RealSellBalance;           //���������ɽ����
    int64     BrowIndex;                 //��ҳ��ѯ��λ��
} ITPDK_ZQGL;
//����ί��
typedef struct
{
    char     AccountId[16];       //�ͻ���
    int64    OrderId;             //ί�к�
    int64    CXOrderId;           //����ί�к�
    char     SBWTH[17];           //�걨ί�к�
    int64    KFSBDBH;             //�����̱��ر��
    char     Market[4];           //������
    char     StockCode[12];       //֤ȯ����
    char     StockName[16];       //֤ȯ����
    int      EntrustType;         //�������
    double   OrderPrice;          //ί�м۸�
    int64    OrderQty;            //ί������
    double   MatchPrice;          //�ɽ��۸�
    int64    MatchQty;            //�ɽ�����
    int64    WithdrawQty;         //��������
    char     SecuAccount[12];     //�ɶ���
    int64    BatchNo;             //ί�����κ�
    int      EntrustDate;         //ί������
    int64    SerialNo;            //��ˮ��
    int      OrderType;           //��������
    int      OrderType_HK;        //�۹ɶ�������
    double   StopPrice;           //ֹ���޼�
    int      OrderStatus;         //�걨���
    char     EntrustNode[48];     //����վ��
    char     EntrustTime[13];     //ί��ʱ��
    char     ReportTime[13];      //�걨ʱ��
    char     MatchTime[13];       //�ɽ�ʱ��
    char     WithdrawFlag[4];     //������־
    char     ResultInfo[128];     //���˵��
    double   MatchAmt;            //�ɽ����
    double   FrozenBalance;       //�����ʽ�
    double   BailBalance;         //���ᱣ֤��
    double   HandingFee;          //�����̷ּ�
    int64    BrowIndex;           //��ҳ��ѯ��λ��
} ITPDK_DRWT;
//�ֱʳɽ�
typedef struct
{
    char     AccountId[16];       //�ͻ���
    char     Market[4];           //������
    char     SecuAccount[12];     //�ɶ���
    char     MatchSerialNo[32];   //�ɽ����
    int64    OrderId;             //ί�к�
    int      EntrustType;         //�������
    char     MatchTime[13];       //�ɽ�ʱ��
    char     StockCode[12];       //֤ȯ����
    char     StockName[16];       //֤ȯ����
    int64    MatchQty;            //�ɽ�����
    double   MatchPrice;          //�ɽ��۸�
    double   MatchAmt;            //�ɽ����
    char     MoneyType[4];        //����
    double   ClearBalance;        //������
    int64    BatchNo;             //ί�����κ�
    int      EntrustDate;         //ί������
    int64    BrowIndex;           //��ʼ��¼����ֵ
    char     WithdrawFlag[4];     //������־
    int64    KFSBDBH;             //�����̱��ر��
} ITPDK_SSCJ;
//ת������
typedef struct
{
    char     AccountId[16];    //�ͻ���
    char     OrgCode[8];       //���д���
    char     BankAccount[32];  //�����ʺ�
    char     MoneyType[4];     //����
    char     ReportNo[16];     //������
    char     TransType[8];     //ҵ�����
    int      ResultCode;       //������
    double   OccurAmt;         //�������
    double   FundBalance;      //�����ʽ����
    char     ResultInfo[64];   //���˵��
    char     ResultTime[13];   //����ʱ��
    char     ApplyTime[13];    //����ʱ��
} ITPDK_ZZSQ;
//������ˮ
typedef struct
{
    char     AccountId[16];       //�ͻ���
    int      OccurDate;           //�ɽ�����
    char     browindex[64];       //��ҳ��ѯ��λ��
    char     MatchTime[13];       //�ɽ�ʱ��
    char     Market[4];           //������
    char     StockName[16];       //֤ȯ����
    char     StockCode[12];       //֤ȯ����
    int      EntrustType;         //�������
    int64    MatchQty;            //�ɽ�����
    double   MatchPrice;          //�ɽ��۸�
    double   MatchAmt;            //�ɽ����
    double   HolderQty;           //�ɷ����
    double   FundBalance;         //�ʽ����
    double   clearBalance;        //�����ʽ�
    double   HandingFee;          //Ӷ��
    double   StampTax;            //ӡ��˰
    double   TransferFee;         //������
    double   FinalValueFee;       //�ɽ���
    double   ClearingFee;         //�����
    double   RegulatoryFee;       //��ܹ��
    char     MatchSerialNo[20];   //�ɽ����
    char     SecuAccount[12];     //�ɶ���
    int64      OrderId;             //ί�к�
    char     MoneyType[4];        //����
} ITPDK_JGMX;
//��ʷί��
typedef struct
{
    char     AccountId[16];       //�ͻ���
    int      OccurDate;           //ί������
    char     browindex[64];       //��ҳ��ѯ��λ��
    char     EntrustTime[13];     //ί��ʱ��
    int      OrderId;             //ί�к�
    char     ResultInfo[64];      //���˵��
    char     Market[4];           //������
    char     StockCode[12];       //֤ȯ����
    char     StockName[16];       //֤ȯ����
    int      EntrustType;         //�������
    double   OrderPrice;          //ί�м۸�
    int      OrderQty;            //ί������
    double   MatchPrice;          //�ɽ��۸�
    int      MatchQty;            //�ɽ�����
    int      WithdrawQty;         //��������
    char     SecuAccount[12];     //�ɶ���
    char     EntrustNode[48];     //ί�е�ַ
    int      OrderType;           //��������
    int      OrderType_HK;        //�۹ɶ�������
    double   StopPrice;           //ֹ���޼�
    int      OrderStatus;         //�걨���
    char     WithdrawFlag[4];     //������־
} ITPDK_WTLS;
//�ʽ���ˮ
typedef struct
{
    char     AccountId[16];    //�ͻ���
    int      OccurDate;        //��������
    char     browindex[64];    //��ҳ��ѯ��λ��
    char     SerialNo[24];     //��ˮ��
    double   InBalance;        //������
    double   OutBalance;       //�������
    double   FundBalance;      //�������
    char     Summary[128];     //ժҪ
    char     FundAccount[16];  //�ʽ��˺�
    char     SubjectCode[8];   //ҵ���Ŀ
    char     MoneyType[4];     //����
} ITPDK_ZJLS;
//��ǩ�ɿ�
typedef struct
{
    char     AccountId[16];       //�ͻ���
    char     Market[4];           //������
    char     StockCode[12];       //֤ȯ����
    char     SecuAccount[12];     //�ɶ���
    char     StockName[16];       //֤ȯ����
    int      LuckyQty;            //��ǩ����
    double   IssuePrice;          //���м۸�
    int      PaymentQty;          //��Ԥ�ɿ�����
    int      PaymentQtyAvl;       //�ɲ��ɿ�����
    int      T3_PaymentQty;       //T+3��Ч��������
    int      T3_CancelQty;        //T+3ȷ�Ϸ�������
} ITPDK_ZQJK;

/////////////////////////////�ӿڳ���νṹ/////////////////////////////
//�ӿ����� - �ͻ���Ϣ
struct ITPDK_CusReqInfo
{
    char     AccountId[16];       //�ͻ���
    char     SecuAccount[12];     //�ɶ���
    char     Password[40];        //��������
    int      TradeNodeID;         //���׽ڵ�
    char     EntrustWay[5];       //ί�з�ʽ
    char     NodeInfo[256];       //����վ��
    int64    Token;               //��¼����

    int64    RetCode;             //����ֵ
    char     ErrMsg[256];         //������Ϣ

    ITPDK_CusReqInfo()
        :AccountId{ 0 }
        , SecuAccount{ 0 }
        , Password{ 0 }
        , TradeNodeID(-1)
        , EntrustWay{ 0 }
        , NodeInfo{ 0 }
        , Token(-1)
        , RetCode(0)
        , ErrMsg{ 0 }
    {
    }
};
//�ͻ��ڵ���Ϣ
struct ITPDK_KHJD
{
    char     AccountId[16];       //�ͻ���
    int      SystemType;          //ϵͳ����
    char     Market[4];           //������
    int      NodeID;              //�ڵ���
};
//��ͨ��������ί��
struct BatchOrderInfo
{
    char    Jys[3];     //������
    char    Zqdm[7];    //֤ȯ����
    int     Jylb;       //�������(JYLB_BUY��JYLB_SALE)
    double  Wtjg;       //ί�м۸�
    int64   Wtsl;       //ί������
    int     Ddlx;       //��������(DDLX_XJWT,DDLX_SJWT)
    char    Gdh[11];

    //����Ϊ�����������ֶ�
    int64   Wth;        //�ɹ�ʱΪί�к�>0��ʧ��ʱΪ������<=0
    char    Msg[128];   //ʧ����Ϣ
};

//ETF���ӹ�����
struct ETFBasket
{
    int64   Wth;           //�ɹ�ʱΪί�к�>0��ʧ��ʱΪ������<=0
    char    Cfgdm[10];     //�ɷֹɴ���
    char    Jys[3];        //������
    int64   Wtsl;          //ί������
    char    Msg[128];      //ʧ����Ϣ
};

//����Ȩ����Ϣ
struct ITPDK_PSQYInfo
{
    char    AccountId[16];      //�ͻ���
    char    Market[4];          //������
    char    SecuAccount[12];    //�ɶ���
    int64   BallotQty;          //�¹ɶ��
    int64   StartQty;           //�ƴ�����
};

//һ������-�����ڵ���Ϣ
struct KHJD
{
    char    AccountId[16]; //�ͻ���
    int64   NodeId;        //�ڵ���
    char    Market[4];     //������
};

//һ������-����������Ϣ
struct ZJHBCL
{
    char    AccountId[16];     //�ͻ���
    char    FundAccount[16];   //�ʽ��˺�
    char    MoneyType[4];      //����
    int64   NodeId;            //�ڵ���
    char    Market[4];         //������
    double  Rate;            //����
};


#pragma pack(pop)

