#pragma once
#pragma pack(push,1)
namespace MarItpdk
{


//股东号
typedef struct
{
   char     AccountId[16];    //客户号
   char     Market[4];        //交易所
   char     SecuAccount[12];  //股东号
   char     HolderName[16];   //股东姓名
   char     FundAccount[16];  //资金帐号
   char     OrgCode[8];       //机构代码--结算银行
   char     MoneyType[4];     //币种
   char     TradeAccess[16];  //交易权限
   int64      HolderType;       //股东类别
   int64      EquityQty;        //权益数量(新股申购)
} ITPDK_XYGDH;


//配售权益
typedef struct
{
   char     AccountId[16];    //客户号
   char     Market[4];        //交易所
   char     SecuAccount[12];  //股东号
   int      StarQty;          //科创版数量
   int      EquityQty;        //证券权益数量
   int      SettleMentDate;   //清算日期
} ITPDK_XYPSQY;



//两融证券代码查询
typedef struct
{
    char     Market[4];           //交易所
    char     MoneyType[4];        //币种
    char     StockCode[12];       //证券代码
    char     StockName[16];       //证券名称
    char     StockType[4];        //证券类别
    double   PriceTick;           //交易价位
    double   TradeUnit;           //交易单位
    int64      MaxTradeAmt;         //委托上限
    int64      MinTradeAmt;         //委托下限
    double   LastClosePrice;      //昨收盘
    double   HighLimitPrice;      //最高报价--涨停价
    double   LowLimitPrice;       //最低报价--跌停价
    int64      NetPriceFlag;        //国债净价标志
    double   InterestPrice;       //利息报价
    int64     BrowIndex;           //分页查询定位串
   
}ITPDK_XYZQDM;


//资金信息
typedef struct
{
   char     AccountId[16];             //客户号
   char     FundAccount[16];           //资金账号
   char     MoneyType[4];              //币种
   char     OrgCode[8];                //机构代码
   int      MasterFlag;                //主帐户标志
   int      AccountType;               //帐户类别
   double   LastBalance;               //上日余额
   double   CurrentBalance;            //账户余额
   double   FrozenBalance;             //冻结资金
   double   T2_FrozenBalance;          //T+2冻结金额
   double   FundAvl;                   //可用资金
   double   T2_FundAvl;                //T+2可用资金
   double   TotalAsset;                //总资产
   double   MarketValue;               //最新市值
   double   DebtAmt;                   //负债金额
   double   CreditQuota;               //信用额度
   double   CreditQuotaAvl;            //可用信用额度
   double   UncomeBalance;             //未交收资金
   double   CashBalance;               //现金余额
   double   CashAsset;                 //现金资产
   double   OtherAsset;                //其他资产
   double   FetchBalance;              //可取资金
   double   DateProfit;                //本日盈亏
   double   UnclearProfit;             //浮动盈亏
   double   DiluteUnclearProfit;       //摊薄浮动盈亏
   double   UpdateTime;                //更新时间
   double 	SettleBalance;				// 实时清算资金(期权)
   double   ContractPosiValue;				//合约持仓市值(期权扩展查询)
   double   LastPositionValue;			//昨日持仓市值(期权扩展查询)
} ITPDK_XYZJZH;


//证券持仓
typedef struct
{
   char     AccountId[16];             //客户号
   char     Market[4];                 //交易所
   char     StockCode[12];             //证券代码
   char     SecuAccount[12];           //股东号
   char     FundAccount[16];           //资金账号
   int64      AccountType;               //账户类别
   char     MoneyType[4];              //币种
   char     StockName[16];             //证券名称
   int64      CurrentQty;                //今持仓量
   int64      QtyAvl;                    //可卖出数量
   double   LastPrice;                 //最新价
   double   MarketValue;               //最新市值
   double   DateProfit;                //本日盈亏
   double   CostPrice;                 //持仓均价
   double   UnclearProfit;             //浮动盈亏
   double   DividendAmt;               //红利金额
   double   RealizeProfit;             //实现盈亏
   int64   PreQty;                    //昨持仓量
   int64   FrozenQty;                 //冻结数量
   int64   UncomeQty;                 //未交收数量
   double   CostBalance;               //持仓成本
   double   DiluteCostPrice;           //摊薄成本价
   double   KeepCostPrice;             //保本价
   double   AvgBuyPrice;               //买入均价
   int64   AllotmentQty;              //配股数量
   int64   SubscribeQty;              //申购数量
   char     OpenDate[12];              //开仓日期
   double   InterestPrice;             //利息报价
   double   Dilutekeep_CostPrice;      //摊薄保本价
   double   DiluteUnclearProfit;       //摊薄浮动盈亏
   int64      TradeUnit;                 //交易单位
   int64      SubscribableQty;           //可申购数量
   int64      RedeemableQty;             //可赎回数量
   int64      RealSubsQty;               //申购成交数量
   int64      RealRedeQty;               //赎回成交数量
   int64   TotalSellQty;              //累计卖出数量
   int64   TotalBuyQty;               //累计买入数量
   double   TotalSellAmt;              //卖出金额
   double   TotalBuyAmt;               //买入金额
   double   AllotmentAmt;              //配股金额
   int64      RealBuyQty;                //当日买入成交数量
   int64      RealSellQty;               //当日卖出成交数量
   double   RealBuyBalance;            //当日买入成交金额
   double   RealSellBalance;           //当日卖出成交金额
   int64      BrowIndex;                 //分页查询定位串
} ITPDK_XYZQGL;
//当日委托
typedef struct
{
   char     AccountId[16];       //客户号
   int      OrderId;             //委托号
   int      CancelOrderId;       //撤销委托号
   char     SBWTH[17];           //申报委托号
   char     Market[4];           //交易所
   char     StockCode[12];       //证券代码
   char     StockName[16];       //证券名称
   int      EntrustType;         //交易类别
   double   OrderPrice;          //委托价格
   int      OrderQty;            //委托数量
   double   MatchPrice;          //成交价格
   int   MatchQty;            //成交数量
   int      WithdrawQty;         //撤单数量
   char     SecuAccount[12];     //股东号
   int      BatchNo;             //委托批次号
   int      EntrustDate;         //委托日期
   int      SerialNo;            //流水号
   int      OrderType;           //订单类型
   int      OrderType_HK;        //港股订单类型
   double   StopPrice;           //止损限价
   int      OrderStatus;         //申报结果
   char     EntrustNode[48];     //交易站点
   char     EntrustTime[12];     //委托时间
   char     ReportTime[12];      //申报时间
   char     MatchTime[12];       //成交时间
   char     KfsOrderNum[24];       //开发商报单编号
   char     WithdrawFlag[4];     //撤销标志
   char     ResultInfo[128];     //结果说明
   double   MatchAmt;            //成交金额
   double   FrozenBalance;       //冻结资金
   double   BailBalance;         //冻结保证金
   double   HandingFee;          //冻结手继费
   int      BrowIndex;           //分页查询定位串
} ITPDK_XYDRWT;

//分笔成交
typedef struct
{
   char     AccountId[16];       //客户号
   int64      ReportSerialNo;      //回报序号
   char     Market[4];           //交易所
   char     SecuAccount[12];     //股东号
   char     MatchSerialNo[32];   //成交编号
   int64      OrderId;             //委托号
   int64      EntrustType;         //交易类别
   char     MatchTime[12];       //成交时间
   char     StockCode[12];       //证券代码
   char     StockName[16];       //证券名称
   char     KfsOrderNum[24];       //开发商报单编号
   int64   MatchQty;            //成交数量
   double   MatchPrice;          //成交价格
   double   MatchAmt;            //成交金额
   char     MoneyType[4];        //币种
   double   clearBalance;        //清算金额
   int64      BatchNo;             //委托批次号
   int64      EntrustDate;         //委托日期
   int64      BrowIndex;           //起始记录索引值
   char     WithdrawFlag[4];     //撤销标志
} ITPDK_XYSSCJ;


//资格证券
typedef struct
{
    char     Market[4];           //交易所
    char     StockCode[12];       //证券代码
    char     StockName[16];       //证券名称
    double   ConversionRate;      //折算率
    double   MarginBailRate;      //融资保证金比例
    double   ShortBailRate;       //融券保证金比例
    int      StockProperty;       //证券属性 1	融资标的, 2	融券标的, 4	担保物, 7 融资融券担保标的
    int      TradeStatus;         //交易状态  0-正常，1 禁止融资 2 禁止融券 3 禁止融资融券
    int      Type;                //类型，0-公司，1 个人
    int64     BrowIndex;           //分页查询定位串
} ITPDK_ZGZQ;

//客户可融券信息
typedef struct
{
    char        AccountId[16];       //客户号
    int32       nTCXZ;      //头寸性质（1普通头寸 2专项头寸）
    char        szTCBH[21];  //头寸编号
    char        sJYS[3];    //交易所
    char        sZQDM[11];  //证券代码
    char        sZQMC[21];  //证券名称
    int64       nZQSL;      //证券数量
    int64       nDJSL;      //冻结数量
    int64       nMCWTSL;    //卖出委托数量
    int64       nDRCHSL;    //当日偿还数量
    int64       nRCSL;      //已融出数量
    int64       nYYSL;      //预约数量
    int64       nDRCJSL;    //当日成交数量
    int64       nKYSL;      //可用数量
    int64       nHCCHSL;    //划出偿还数量
    float64     dRQBL;      //融券比例
    float64     dZSL;       //折算率
    int32       nJYZT;      //交易状态
    int64       BrowIndex;           //分页查询定位串

} ITPDK_RQZQ;

//客户可融资金信息
typedef struct
{
    char        AccountId[16];       //客户号
    int32       nTCXZ;      //头寸性质（1普通头寸 2专项头寸）
    char        szTCBH[21];  //头寸编号
    double      dTCGM;      //头寸规模
    double      dYRCJE;     //已融出金额
    double      dYYJE;      //预约金额
    double      dRCDJJE;    //当日融出冻结金额
    double      dDRCHJE;    //当日偿还金额
    double      dDJJE;      //临时冻结金额
    double      dKYED;      //可用金额

} ITPDK_KRZJXX;

//信用资产
typedef struct
{
    char   AccountId[16];                //客户号
    double dKYBZJ;       //可用保证金
    double dDBBL;       //担保比例
    double dYJBL1;       //预计维持担保比例1，考虑担保物划入划出
    double dYJBL2;         //预计维持担保比例2，考虑担保物划出，不考虑划入
    double dZHYE;       //账户余额
    double dKYZJ;       //可用资金
    double dQSZJ;       //清算资金
    double dKMDBPZJ;	//可买担保品资金

    double dZQSZ_BD;    //标的证券市值
    double dZQSZ;		    //证券市值_计算担保比例使用
    double dZQSZ_DB;    //担保证券市值
    double dZQSZ_DBZS;	//担保证券折算市值_计算可用保证金使用(已扣融资)
    double dZQSZ_DB_BD;//担保证券变动折算市值_计算可用保证金使用
    double dZQSZ_DBZS_BD;//担保证券变动折算市值_计算可用保证金使用
    double dZQSZ_YJZC;          //担保物返回未成交_预估资产

    double dRZFZ;       //融资负债
    double dRQFZ;       //融券负债
    double dRZFZ2;      //融资负债2
    double dRQFZ2;      //融券负债2
    double dHQWT2;      //还券委托未成
    double dXJCE;       //应该追补到比例线的资金差额
    double dPCJE;       //强制平仓资金 = (总负债*平仓到位比例 - 总资产)/(平仓到位比例 -1)
    double dZDPCJE;     //主动平仓资金 = (总负债*追保到位比例 - 总资产)/(追保到位比例 -1)
    double dKQBZ;       //可提资产标准
    double dKQZJ;       //可取资金

    double dRZLX;       //尚欠利息_融资
    double dRQLX;       //尚欠利息_融券
    double dYJLX;       //预计利息/费用
    double dZFZ;        //总负债
    double dZZC;        //总资产
    double dJZC;        //净资产
    //double dZYBZJ;    //占用保证金
    double dZYBZJ_RZ;   //占用保证金_融资
    double dZYBZJ_RQ;   //占用保证金_融券
    double dRZYK;       //融资盈亏
    double dRQYK;       //融券盈亏
    double dRQSYZJ;     //融券剩余资金
    double dRZSXF;      //融资费用
    double dRQSXF;      //融券费用
    double dDBSZ_SH;    //上海担保证券市值
    double dDBSZ_SZ;    //深圳担保证券市值
    double dRZFYZS;     //融资浮盈折算
    double dRZFK;       //融资浮亏
    double dRQFYZS;     //融券浮盈折算
    double dRQFK;       //融券浮亏
    double dRQMCJE;     //融券金额_负债

    double dRZDQSZ;     //融资当前市值
    double dRQDQSZ;     //融券当前市值

    double dSYZQSZ;     //所有证券市值
						
						
						// FALG 送1  扩展字段
    int    nJSRQ;		//合同到期日
    double dRZED;		//融资授信额度
    double dRQED;       //融券授信额度
    double dRZZY;       //融资已用额度
    double dRQZY;       //融券已用额度
    double dHTED;       //合同额度
    double dQTZY;		//其它占用
    double dKYDBZJ;		//可买担保品资金
    double dQTFY;       //其他费用
    double dZZCJZD;     //持仓占总资产集中度
    double dJZCJZD;     //净资产集中度
    double dZZCJZD_BK;  //科创板+创业板板块持仓占总资产集中度
    double dJZCJZD_BK;  //科创板+创业板板块净持仓集中度
    double dZZCJZD_BKCDR;//科创板+创业板+科创板CDR+创业板CDR板块持仓占总资产集中度

    double dRZFZ_PT;       //融资负债(普通头寸)
    double dRZSXF_PT;      //融资费用(普通头寸)
    double dRZLX_PT;       //尚欠利息_融资(普通头寸)
   
} ITPDK_XYZC;
//信用合约
typedef struct
{
    char    AccountId[16];             //客户号
    char    m_szHYBH[25];  // HYBH 合约编号
    char    m_szHTBH[17];  // HTBH 合同编号
    int   	m_nWTH;        // WTH	订单编号
    int   	m_nFSRQ;       // FSRQ	发生日期
    char    m_szFSSJ[13];  // FSSJ 发生时间
    int     m_nJYRQ;       // JYRQ  交易日期
    int     m_nDQRQ;		// 到期日期
    int     m_nHYQX;        // 合约期限
    int     m_nQXRQ;        // 起息日期
    int     m_nHYLB;        // 合约类别
    int     m_nHYLX;        // 合约类型
    char    m_szJYS[3];    // JYS 交易所
    char    m_szGDH[11];      //股东号
    char    m_szZQDM[11];  // ZQDM 证券代码
    char    m_szZQMC[21];  // ZQMC 证券名称
    int     m_nWTSL;       // WTSL 委托数量
    double  m_dWTJG;     // WTJG	数托价格
    int     m_nCJSL;       // CJSL	成交数量
    double  m_dCJJE;     // CJJE	成交金额
    double  m_dCJJG;     // CJJG 	成交价格
    double  m_dSXF;      // SXF	成交手续费
    double  m_dYCHJE;    // YCHJE	 已偿还合约金额
    double  m_dYCHSXF;   // YCHSXF 已偿还交易费用
    int     m_nYCHSL;      // YCHSL 已偿还数量
    double  m_dYCHLX;    // YCHLX	已偿还利息
    double  m_dYCHFX;    // YCHFX	已偿还罚息
    double  m_dQCHYJE;   // QCHYJE	期初合约金额
    double  m_dQCSXF;    // QCSXF	期初合约交易费用
    double  m_dQCLX;     // QCLX	期初合约利息
    double  m_dQCFX;     // QCFX	期初罚息金额
    int     m_nQCSL;       // QCSL	期初合约数量
    double  m_dSSHYJE;   // SSHYJE	实时合约金额
    double  m_dSSSXF;    // SSSXF	实时合约交易费用
    double  m_dSSLX;     // SSLX	实时合约利息
    double  m_dSSFX;     // SSFX	实时罚息金额
    int     m_nSSSL;       // SSSL	实时合约数量
    double  m_dHYLL;     // HYLL	利率/费率
    double  m_dFXFL;     // FXFL	罚息利率
    double  m_dLXJS;     // LXJS	利息基数
    double  m_dFDLX;     // FDLX	分段利息
    double  m_dYJLX;     // YJLX	预计利息
    double  m_dFXLXJS;   // FXLXJS	罚息利息积数
    double  m_dFXYJLX;   // FXYJLX	罚息预计利息
    double  m_dFXFDLX;   // FXFDLX	罚息分段利息
    double  m_dBZJBL;    // BZJBL	保证金比例
    int     m_nZQCS;       // ZQCS	展期次数
    int     m_nEDDJBS;     // EDDJBS额度冻结标识
    char    m_szYHYBH[25];           // YHYBH	原合约编号
    char    m_szTCBH[21];             // TCBH	头寸编号
    int     m_nBCSL;       // BCSL	补偿数量
    double  m_dBCJE;     // BCJE	补偿金额
    int     m_nLXLJFS;     // LXLJFS	利息了结方式
    int     m_nFLBH;       // FLBH	费率编号
    char    m_szDQRQHYBH[29];        // DQRQHYBH
    int     m_nQKBZ;       // QKBZ 欠款标志
    int     m_nQQBZ;       // QQBZ	欠券标志
    int     m_nZT;			//检查负债了结状态：0-未了结  1-已了结
    char    m_szBrowIndex[25];//分页索引值
} ITPDK_XYFZ;
//当日信用合约变动
typedef struct
{
    char    AccountId[16];       //客户号
    int     m_nLSH;        // LSH 流水号
    char    m_szHYBH[25];  // HYBH 合约编号
    int     m_nWTH;        // WTH	订单编号
    int     m_nHBXH;       // HBXH  回报序号
    char    m_szJYS[3];    // JYS	交易所
    char    m_szZQDM[11];  // ZQDM	证券代码
    int     m_nJYRQ;       // JYRQ	交易日期
    int     m_nFSRQ;       // FSRQ	发生日期
    char    m_szFSSJ[13];  // FSSJ	发生时间
    int     m_nHYBDLB;     // HYBDLB 合约变动类别
    int     m_nJYLB;       // JYLB	交易类别
    int     m_nHYLB;       // HYLB	合约类别
    char    m_szHYZQDM[11];// HYZQDM	合约证券代码
    char    m_szHYJYS[3];  // HYJYS		合约交易所
    int     m_nFSHYSL;     // FSHYSL	发生合约数量
    int     m_nHYSL;       // HYSL		后余数量
    double  m_dFSHYJE;     // FSHYJE	发生合约金额
    double  m_dHYJE;       // HYJE		后余金额
    double  m_dFSFY;       // FSFY		发生费用
    double  m_dHYFY;       // HYFY		后余费用
    double  m_dFSLX;       // FSLX		发生利息
    double  m_dHYLX;       // HYLX		后余利息
    double  m_dFSFX;       // FSFX		发生罚息
    double  m_dHYFX;       // HYFX		后余罚息
    int     m_nZDBZ;       // ZDBZ		指定还款标志
    int     m_nQPBZ;       // QPBZ		强平标志
    char    m_szYHYBH[25];    // YHYBH	原合约编号
    char    m_szTCBH[21];      // TCBH	头寸编号
    char    m_szZY[129];      // ZY		摘要
    int     m_nCXBZ;         // CXBZ	撤销标志
    int     m_nQSBZ;         // QSBZ	清算标志
} ITPDK_XYDRBD;
//当日信用融券负债汇总
typedef struct
{
    char    AccountId[16];       //客户号
    char    m_szJYS[3];         //交易所
    char    m_szZQDM[11];       //证券代码
    int     m_nFZSL;            //负债数量
    int     m_nDRRQCJSL;        //当日融券成交数量
    int     m_nHQWTSL;          //还券委托数量
    int     m_nHQCJSL;          //还券成交数量
    int     m_nYQWTSL;          //余券委托数量
    int     m_nYQSL;            //余券数量

} ITPDK_XYRQFZHZ;


/////////////////////////////接口出入参结构/////////////////////////////
//接口请求 - 客户信息
struct ITPDK_CusReqInfo
{
    char     AccountId[16];       //客户号
    char     FundAccount[16];      //资金号
    char     SecuAccount[12];     //股东号
    char     Password[40];        //交易密码
    char     OrgCode[8];          //机构代码
    int      TradeNodeID;         //交易节点
    char     EntrustWay[5];       //委托方式
    char     NodeInfo[256];       //操作站点
    char     OppSecuAccount[12];      //对方股东号
    char     OppSeat[12];           //对方席位
    int64    Token;               //登录令牌

    int64    RetCode;             //返回值
    char     ErrMsg[256];         //错误信息

    ITPDK_CusReqInfo()
        :AccountId{ 0 }
        , FundAccount{ 0 }
        , SecuAccount{ 0 }
        , Password{ 0 }
        , OrgCode{ 0}
        , TradeNodeID(-1)
        , EntrustWay{ 0 }
        , NodeInfo{ 0 }
        , OppSecuAccount{ 0 }
        , OppSeat{ 0 }
        , Token(-1)
        , RetCode(0)
        , ErrMsg{ 0 }
    {
    }
};

};  //MarItpdk
#pragma pack(pop)
