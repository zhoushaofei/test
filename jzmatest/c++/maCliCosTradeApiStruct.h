#if !defined(__MA_CLI_COS_TRADE_API_STRUCT_H__)
#define __MA_CLI_COS_TRADE_API_STRUCT_H__
#include "maCliTradeApi.h"
#include "maCliStkTradeApiStruct.h"
#include "maCliFislTradeApiStruct.h"
#include "maCliOptTradeApiStruct.h"
#include "maCliFutureTradeApiStruct.h"
BGN_NAMESPACE_MACLI

//子系统查询
struct MATRADEAPI CReqCosConfField
{
	int      iSubsys;//子系统SUBSYSSMALLINTX 908081:证券现货交易系统
};

struct MATRADEAPI CRspCosConfField
{
	int      iSubsys;            //子系统     SUBSYS        SMALLINT    9080
	int      iSubsysSn;          //子系统编码   SUBSYS_SN     SMALLINT    8988
	char     szSubsysConnstr[128+1];//系统连接串   SUBSYS_CONNSTRVARCHAR(128)9081
	int      iFlowRight;         //流速权(笔/秒)FLOW_RIGHT    INTEGER     9082
};
//子系统设置
struct MATRADEAPI CReqCosChgConfField
{
	char     chOperationType;//操作类型    OPERATION_TYPECHAR(1)     Y 8987 0:新增 1:修改 2:删除
	int      iSubsys;        //子系统     SUBSYS        SMALLINT    Y 9080 
	int      iSubsysSn;      //子系统编码   SUBSYS_SN     SMALLINT    Y 8988 
	char     szSubsysConnstr[128+1];//系统连接串   SUBSYS_CONNSTRVARCHAR(128)X 9081 
	int      iFlowRight;     //流速权(笔/秒)FLOW_RIGHT    INTEGER     X 9082 
};

struct MATRADEAPI CRspCosChgConfField
{
};

//量化委托
struct MATRADEAPI CReqCosOrderField
{
	char     szCuacctCode[16+1];   //资产账户   CUACCT_CODE         BIGINT      Y 8920 
  char     chCuacctType;         //资产账户类型
	char     szCustCode[16+1];           //客户代码   CUST_CODE           BIGINT      X 8902 
	char     szTrdacct[10+1];     //交易账户   TRDACCT             VARCHAR(10) Y 448  
	char     chExchange;           //交易所    EXCHANGE            CHAR(1)     X 207  
	char     szStkbd[2+1];        //交易板块   STKBD               CHAR(2)     Y 625  '00' -- 深圳Ａ股
	int      iStkBiz;              //交易业务   STK_BIZ             SMALLINT    Y 8842 
	int      iStkBizAction;        //业务活动   STK_BIZ_ACTION      SMALLINT    Y 40   
	char     szTrdCode[8+1];      //品种代码   TRD_CODE            VARCHAR(8)  X 48   
	char     szOptNum[16+1];      //合约编码   OPT_NUM             VARCHAR(16) X 9082 
	int      iIntOrg;              //内部机构   INT_ORG             SMALLINT    X 8911 
	int      iOrderBsn;            //委托批号   ORDER_BSN           INTEGER     X 66   
	LONGLONG llOrderQty;           //委托数量   ORDER_QTY           BIGINT      Y 38   
	char     szOrderPrice[21+1];   //委托价格   ORDER_PRICE         CPRICE      X 44   
	char     szStopPrice[21+1];    //触发价格   STOP_PRICE          CPRICE      X 8975 
	int      iValidDate;           //截止日期   VALID_DATE          INTEGER     X 8859 
	int      iTrdCodeCls;          //品种类型   TRD_CODE_CLS        INTEGER     X 8970 
	char     szOrderAttr[256+1];  //高级属性   ORDER_ATTR          VARCHAR(256)X 9100 
	int      iAttrCode;            //属性代码   ATTR_CODE           SMALLINT    Y 91010:普通下单
	int      iBgnExeTime;          //执行开始时间 BGN_EXE_TIME        INTEGER     X 916  
	int      iEndExeTime;          //执行结束时间 END_EXE_TIME        INTEGER     X 917  
	char     szSpreadName[64+1];  //组合名称   SPREAD_NAME         VARCHAR(64) X 8971 
	char     szUndlCode[16+1];    //标的代码   UNDL_CODE           VARCHAR(16) X 8972 
	int      iConExpDate;          //合约到期日  CON_EXP_DATE        INTEGER     X 8976 
	char     szExercisePrice[21+1];//行权价    EXERCISE_PRICE      CPRICE      X 8973 
	LONGLONG llConUnit;            //合约单位   CON_UNIT            BIGINT      X 8974 
	char     szCliOrderNo[32+1];  //客户端委托编号CLI_ORDER_NO        VARCHAR(32) X 9102 
	char     szCliRemark[32+1];   //备用信息   CLI_REMARK          VARCHAR(32) X 8914 
	char     szBusinessUnit[21+1];//业务单元   BUSINESS_UNIT       VARCHAR(21) X 87170
	char     szGtdData[9+1];      //GTD日期  GTD_DATA            VARCHAR(9)  X 87230
	char     chContingentCondition;//触发条件   CONTINGENT_CONDITIONVARCHAR(1)  X 87131:立即
	char     chForceCloseReason;   //强平原因   FORCE_CLOSE_REASON  VARCHAR(1)  X 87150
	int      iIsSwapOrder;         //互换单标志  IS_SWAP_ORDER       SMALLINT    X 87200
	char     szOrderIdEx[64+1];   //外部合同序号 ORDER_ID_EX         VARCHAR(64) X 9093 此序号为外部传入，期权系统不做任何处理
};

struct MATRADEAPI CRspCosOrderField
{
	char     szCliOrderNo[32+1];//客户端委托编号CLI_ORDER_NO   VARCHAR(32) 9102
	int      iOrderBsn;         //委托批号   ORDER_BSN      INTEGER     66  
	int      iOrderNo;          //委托编号   ORDER_NO       INTEGER     9106
	int      iOrderDate;        //委托日期   ORDER_DATE     INTEGER     8834
	char     szOrderTime[32+1];//委托时间   ORDER_TIME     VARCHAR(32) 8845
	char     chExeStatus;       //执行状态   EXE_STATUS     CHAR(1)     9103
	char     szExeInfo[128+1]; //执行信息   EXE_INFO       VARCHAR(128)9104
	LONGLONG llOrderQty;        //委托数量   ORDER_QTY      BIGINT      38  
	int      iTrdBiz;           //交易业务   TRD_BIZ        SMALLINT    8842
	int      iTrdBizAcction;    //业务活动   TRD_BIZ_ACCTIONSMALLINT    40  
	char     szTrdCode[8+1];   //品种代码   TRD_CODE       VARCHAR(8)  48  
	char     szUndlCode[16+1]; //标的代码   UNDL_CODE      VARCHAR(16) 8972
	char     szCuacctCode[16+1];      //资产账户   CUACCT_CODE    BIGINT      8920
};

//委托撤单
struct MATRADEAPI CReqCosCancelOrderField
{
  char     szCuacctCode[16+1];//资产账户CUACCT_CODEBIGINT  Y 8920
  char     chCuacctType;         //资产账户类型
	int      iIntOrg;     //内部机构INT_ORG    SMALLINTX 8911内部机构(期权必填)
	char     szStkbd[2+1];//交易板块STKBD      CHAR(2) X 625 字典[STKBD]
	int      iOrderDate;  //委托日期ORDER_DATE INTEGER Y 8834
	int      iOrderNo;    //委托编号ORDER_NO   INTEGER X 9106
	int      iOrderBsn;   //委托批号ORDER_BSN  INTEGER X 66  
};

struct MATRADEAPI CRspCosCancelOrderField
{
	char     szCuacctCode[16+1];      //资产账户   CUACCT_CODE    BIGINT      8920
	char     szStkbd[2+1];     //交易板块   STKBD          CHAR(2)     625 
	int      iOrderDate;        //委托日期   ORDER_DATE     INTEGER     8834
	int      iOrderNo;          //委托编号   ORDER_NO       INTEGER     9106
	char     szCliOrderNo[32+1];//客户端委托编号CLI_ORDER_NO   VARCHAR(32) 9102
	int      iOrderBsn;         //委托批号   ORDER_BSN      INTEGER     66  
	char     chExeStatus;       //执行状态   EXE_STATUS     CHAR(1)     9103
	char     szExeInfo[128+1]; //执行信息   EXE_INFO       VARCHAR(128)9104
	LONGLONG llOrderQty;        //委托数量   ORDER_QTY      BIGINT      38  
	int      iTrdBiz;           //交易业务   TRD_BIZ        SMALLINT    8842
	int      iTrdBizAcction;    //业务活动   TRD_BIZ_ACCTIONSMALLINT    40  
	char     szTrdCode[8+1];   //品种代码   TRD_CODE       VARCHAR(8)  48  
	char     szUndlCode[16+1]; //标的代码   UNDL_CODE      VARCHAR(16) 8972
	char     chCancelStatus;    //内部撤单标志 CANCEL_STATUS  CHAR(1)     9080
};

//委托改单
struct MATRADEAPI CReqCosChgOrderField
{
  char     szCuacctCode[16+1];//资产账户CUACCT_CODEBIGINT Y 8920
  char     chCuacctType;         //资产账户类型
	int      iOrderDate;  //委托日期ORDER_DATE INTEGERY 8834
	int      iOrderNo;    //委托编号ORDER_NO   INTEGERY 9106
	LONGLONG llOrderQty;  //委托数量ORDER_QTY  BIGINT Y 38  
	char     szOrderPrice[21+1];//委托价格ORDER_PRICECPRICE Y 44  
};

struct MATRADEAPI CRspCosChgOrderField
{
};

//量化组合委托
struct MATRADEAPI CReqCosCombOrderField
{
  char     szCuacctCode[16+1];   //资产账户  CUACCT_CODE    BIGINT        Y 8920
  char     chCuacctType;         //资产账户类型
	char     szCustCode[16+1];     //客户代码  CUST_CODE      BIGINT        Y 8902
	char     szTrdacct[10+1];//交易账户  TRDACCT        VARCHAR(10)   Y 448 
	char     szSpreadName[32+1];//组合名称  SPREAD_NAME    VARCHAR(32)   Y 8971
	int      iValidDate;     //截止日期  VALID_DATE     INTEGER       Y 8859
	int      iOrderDataNum;  //订单数量  ORDER_DATA_NUM INTEGER       Y 8857
	char     szOrderGrpText[32768+1];//委托组合  ORDER_GRP_TEXT VARCHAR(32768)Y 9080
	int      iModuleDataNum; //组合模块数量MODULE_DATA_NUMINTEGER       Y 9081
	char     szModuleGrpText[2048+1];//组合模块  MODULE_GRP_TEXTVARCHAR(2048) Y 9082
	int      iOrderDate;     //委托日期  ORDER_DATE     INTEGER       Y 8834
	char     szOrderTime[32+1];//委托时间  ORDER_TIME     VARCHAR(32)   Y 8845
};

struct MATRADEAPI CRspCosCombOrderField
{
	int      iOrderBsn;       //委托批号  ORDER_BSN  INTEGER     66  
	int      iOrderDate;      //委托日期  ORDER_DATE INTEGER     8834
	char     szOrderTime[32+1];//委托时间  ORDER_TIME VARCHAR(32) 8845
	int      iOrderNo;        //委托编号  ORDER_NO   INTEGER     9106
	char     szClientId[32+1];//客户订单标识CLIENT_ID  VARCHAR(32) 8858
	char     chExeStatus;     //执行状态  EXE_STATUS CHAR(1)     9103
	char     szExeInfo[128+1];//执行信息  EXE_INFO   VARCHAR(128)9104
	char     szCuacctCode[16+1];    //资产账户  CUACCT_CODEBIGINT      8920
};
//普通单买卖委托
struct MATRADEAPI CReqCosNormalOrderField
{
  char     szCustCode[16+1];        //客户代码  CUST_CODE         BIGINT      X 8902 
  char     chCuacctType;         //资产账户类型
	char     szCuacctCode[16+1];      //资产账户  CUACCT_CODE       BIGINT      Y 8920 
	char     szStkbd[2+1];     //交易板块  STKBD             CHAR(2)     Y 625  字典[STKBD]
	char     szStkCode[8+1];   //证券代码  STK_CODE          VARCHAR(8)  Y 48   
	char     szOrderPrice[21+1];//委托价格  ORDER_PRICE       CPRICE      X 44   
	LONGLONG llOrderQty;        //委托数量  ORDER_QTY         BIGINT      Y 38   
	int      iStkBiz;           //证券业务  STK_BIZ           SMALLINT    Y 8842 字典[STK_BIZ]
	int      iStkBizAction;     //业务行为  STK_BIZ_ACTION    SMALLINT    Y 40   字典[STK_BIZ_ACTION]
	char     szStkpbu[8+1];    //交易单元  STKPBU            VARCHAR(8)  X 8843 
	int      iOrderBsn;         //委托批号  ORDER_BSN         INTEGER     X 66   
	char     szOrderText[256+1];//委托扩展  ORDER_TEXT        VARCHAR(256)X 58   格式:关键字1=值1,关键字2=值2
	char     szClientInfo[256+1];//终端信息  CLIENT_INFO       VARCHAR(256)X 9039 包括硬盘号\CPU\机器名等
	char     chSecurityLevel;   //安全手段  SECURITY_LEVEL    CHAR(1)     Y 90801:校验会话凭证
	char     szSecurityInfo[256+1];//安全信息  SECURITY_INFO     VARCHAR(256)X 9081 
	char     szComponetStkCode[8+1];//成份股代码 COMPONET_STK_CODE VARCHAR(8)  X 8911 ETF网下股票认购启用
	char     szComponetStkbd[2+1];//成份股板块 COMPONET_STKBD    VARCHAR(2)  X 8962 ETF网下股票认购、ETF实物申赎启用
	char     szStkbdLink[2+1]; //关联板块  STKBD_LINK        CHAR(2)     X 17   ETF网下股票认购、ETF实物申赎启用
	char     szTrdacct[10+1];  //证券账户  TRDACCT           VARCHAR(10) Y 448  
	int      iCuacctSn;         //账户序号  CUACCT_SN         SMALLINT    X 8928 客户端标识，用于多个客户端共用同一个资产账号下单时，区分不同客户端的委托与成交信息，并提供了相关的接口查询功能。
	char     chPublishCtrlFlag; //股票风控标志PUBLISH_CTRL_FLAG CHAR(1)     X 90830：不控制
	char     szRepayOrderId[10+1];//偿还合同序号REPAY_ORDER_ID    VARCHAR(10) X 11   用于融资融券交易
	int      iRepayOpeningDate; //偿还合约日期REPAY_OPENING_DATEINTEGER     X 9121 用于融资融券交易
	char     szRepayStkCode[8+1];//偿还证券代码REPAY_STK_CODE    VACHAR(8)   X 9218 用于融资融券交易
	char     szRepayContractAmt[21+1];//偿还金额  REPAY_CONTRACT_AMTCMONEY      X 8504 直接还款需要输入
};

struct MATRADEAPI CRspCosNormalOrderField
{
	int      iOrderBsn;        //委托批号ORDER_BSN     INTEGER    66  
	char     szCuacctCode[16+1];     //资产账户CUACCT_CODE   BIGINT     8920
	char     szOrderPrice[21+1];//委托价格ORDER_PRICE   CPRICE     44  
	LONGLONG llOrderQty;       //委托数量ORDER_QTY     BIGINT     38  
	char     szStkpbu[8+1];   //交易单元STKPBU        VARCHAR(8) 8843
	char     szStkbd[2+1];    //交易板块STKBD         CHAR(2)    625 
	char     szStkCode[8+1];  //证券代码STK_CODE      VARCHAR(8) 48  
	char     szStkName[16+1]; //证券名称STK_NAME      VARCHAR(16)55  
	int      iStkBiz;          //证券业务STK_BIZ       SMALLINT   8842
	int      iStkBizAction;    //业务行为STK_BIZ_ACTIONSMALLINT   40  
	char     szTrdacct[10+1]; //证券账户TRDACCT       VARCHAR(10)448 
};

//节点变更
struct MATRADEAPI CReqCosChgNodeField
{
	char     chNodeChgFlag;//结点切换标志NODE_CHG_FLAGCHAR(1)Y 9080‘0’: 正切 ‘1’:回切
	int      iNodeIdOrg;   //原节点编号 NODE_ID_ORG  INTEGERY 9081切换前结点
	int      iNodeIdNow;   //现节点编号 NODE_ID_NOW  INTEGERY 9082切换到结点
	char     chNodeStatus; //原结点状态 NODE_STATUS  CHAR(1)Y 9083这个参数后台自动送
};

struct MATRADEAPI CRspCosChgNodeField
{
	char     chNodeChgFlag;    //结点切换标志NODE_CHG_FLAGCHAR(1)9080
	int      iNodeIdOrg;       //原节点编号 NODE_ID_ORG  INTEGER9081
	int      iNodeIdNow;       //现节点编号 NODE_ID_NOW  INTEGER9082
};
//节点变更上线
struct MATRADEAPI CReqCosChgNodeOnlineField
{
	char     chNodeChgFlag;//结点切换标志NODE_CHG_FLAGCHAR(1)Y 9080
	int      iNodeIdOrg;   //原节点编号 NODE_ID_ORG  INTEGERY 9081切换前结点
	int      iNodeIdNow;   //现节点编号 NODE_ID_NOW  INTEGERY 9082切换到结点
};

struct MATRADEAPI CRspCosChgNodeOnlineField
{
};
//自动登录
struct MATRADEAPI CReqCosAutoLoginField
{
  char     szAcctType[2+1];//账户类型ACCT_TYPE  VARCHAR(2)  Y 8987‘U’:客户代码
  char     szAcctId[32+1];//账户标识ACCT_ID    VARCHAR(32) Y 9081
  char     chCuacctType;//资产账户类型CUACCT_TYPE    CHAR(1) Y 8826
  char     chUseScope;  //使用范围USE_SCOPE  CHAR(1)     X 9082‘0’:交易密码
  char     szEncryptKey[32+1];//加密因子ENCRYPT_KEYVARCHAR(32) Y 9086如：使用功能号(10301105)加密因子
  char     chAuthType;  //认证类型AUTH_TYPE  CHAR(1)     X 9083‘0’--密码
  char     szAuthData[256+1];//认证数据AUTH_DATA  VARCHAR(256)Y 9084此字段使用maCli_ComEncrypt函数，对客户交易密码，用ENCRYPT_KEY字段中的值作为Key进行加密后得到的密
};

struct MATRADEAPI CRspCosAutoLoginField
{
};
//-------------------------------10388750:登录后台量化系统--------------------------
struct MATRADEAPI CReqCosLoginField
{
  char            szUserCode[16 + 1];         // 用户代码 也可以是手机号登录
  char            szAuthData[256 + 1];        // 认证数据 
  char            szEncryptKey[32 + 1];       // 加密因子 
  char            szThirdParty[1024 + 1];     // 第三方 使用第三方客户端的用户代码必输,字段内容由密钥dll指定接口获取;
};

struct MATRADEAPI CRspCosLoginField
{
  char            szUserCode[16 + 1];         // 用户代码 
  char            szPhoneNum[16 + 1];         // 手机号 
  char            szUserGroupRight[8 + 1];    // 用户组权限 
  char            szSessionId[128 + 1];       // 会话凭证 客户端需保存，后续请求填写到固定入参会话凭证(8814)中，否则后续请求将被拒绝。
};

//量化委托查询
struct MATRADEAPI CReqCosOrderInfoField
{
  char     szCuacctCode[16+1];//资产账户  CUACCT_CODE BIGINT     Y 8920 
  char     chCuacctType;         //资产账户类型
	char     szStkbd[2+1];//交易板块  STKBD       CHAR(2)    X 625  
	int      iTrdCodeCls; //品种类型  TRD_CODE_CLSINTEGER    X 8970 
	char     szTrdCode[8+1];//品种代码  TRD_CODE    VARCHAR(8) X 48   
	char     szOptNum[16+1];//合约编码  OPT_NUM     VARCHAR(16)X 9082 
	int      iOrderNo;    //委托编号  ORDER_NO    INTEGER    X 9106 
	int      iOrderBsn;   //委托批号  ORDER_BSN   INTEGER    X 66   
	char     szTrdacct[10+1];//交易账户  TRDACCT     VARCHAR(10)X 448  
	int      iAttrCode;   //属性代码  ATTR_CODE   SMALLINT   X 9101 
	int      iBgnExeTime; //执行开始时间BGN_EXE_TIMEINTEGER    X 916  
	char     chQueryFlag; //查询方向  QUERY_FLAG  CHAR(1)    Y 90800:向后取数据
	char     szQueryPos[32+1];//定位串   QUERY_POS   VARCHAR(32)X 8991 与查询方向和资产账户配合使用
	int      iQueryNum;   //查询行数  QUERY_NUM   INTEGER    Y 8992 最大值为1000
	char     chFlag;      //查询标志  FLAG        CHAR(1)    X 9081 ‘1’ :  可撤单
};

struct MATRADEAPI CRspCosOrderInfoField
{
	char     szQryPos[32+1];    //定位串    QRY_POS       VARCHAR(32) 8991
	char     szCuacctCode[16+1];       //资产账户   CUACCT_CODE   BIGINT      8920
	char     szCustCode[16+1];         //客户代码   CUST_CODE     BIGINT      8902
	char     szTrdacct[10+1];   //交易账户   TRDACCT       VARCHAR(10) 448 
	char     chExchange;         //交易所    EXCHANGE      CHAR(1)     207 
	char     szStkbd[2+1];      //交易板块   STKBD         CHAR(2)     625 
	int      iTrdCodeCls;        //品种类型   TRD_CODE_CLS  INTEGER     8970
	int      iStkBiz;            //交易业务   STK_BIZ       SMALLINT    8842
	int      iStkBizAction;      //业务活动   STK_BIZ_ACTIONSMALLINT    40  
	char     szTrdCode[8+1];    //品种代码   TRD_CODE      VARCHAR(8)  48  
	char     szOptNum[16+1];    //合约编码   OPT_NUM       VARCHAR(16) 9082
	int      iIntOrg;            //内部机构   INT_ORG       SMALLINT    8911
	int      iOrderDate;         //委托日期   ORDER_DATE    INTEGER     8834
	char     szOrderTime[32+1]; //委托时间   ORDER_TIME    VARCHAR(32) 8845
	int      iOrderBsn;          //委托批号   ORDER_BSN     INTEGER     66  
	int      iOrderNo;           //委托编号   ORDER_NO      INTEGER     9106
	LONGLONG llOrderQty;         //委托数量   ORDER_QTY     BIGINT      38  
	char     szOrderPrice[21+1]; //委托价格   ORDER_PRICE   CPRICE      44  
	char     szStopPrice[21+1];  //触发价格   STOP_PRICE    CPRICE      8975
	int      iValidDate;         //截止日期   VALID_DATE    INTEGER     8859
	char     szOrderAttr[256+1];//高级属性   ORDER_ATTR    VARCHAR(256)9100
	int      iAttrCode;          //属性代码   ATTR_CODE     SMALLINT    9101
	int      iBgnExeTime;        //执行开始时间 BGN_EXE_TIME  INTEGER     916 
	int      iEndExeTime;        //执行结束时间 END_EXE_TIME  INTEGER     917 
	char     szSpreadName[64+1];//组合名称   SPREAD_NAME   VARCHAR(64) 8971
	char     szUndlCode[16+1];  //标的代码   UNDL_CODE     VARCHAR(16) 8972
	int      iConExpDate;        //合约到期日  CON_EXP_DATE  INTEGER     8976
	char     szExercisePrice[21+1];//行权价    EXERCISE_PRICECPRICE      8973
	LONGLONG llConUnit;          //合约单位   CON_UNIT      BIGINT      8974
	char     szCliOrderNo[32+1];//客户端委托编号CLI_ORDER_NO  VARCHAR(32) 9102
	char     szCliRemark[32+1]; //备用信息   CLI_REMARK    VARCHAR(32) 8914
	char     chExeStatus;        //执行状态   EXE_STATUS    CHAR(1)     9103
	char     szExeInfo[128+1];  //执行信息   EXE_INFO      VARCHAR(128)9104
	LONGLONG llExeQty;           //执行数量   EXE_QTY       BIGINT      9105
	LONGLONG llMatchedQty;       //已成交数量  MATCHED_QTY   BIGINT      387 
	LONGLONG llWithdrawnQty;     //已撤单数量  WITHDRAWN_QTY BIGINT      8837
	char     szMatchedAmt[21+1]; //已成交金额  MATCHED_AMT   CMONEY      8504
	char     szUpdateTime[32+1];//最后修改时间 UPDATE_TIME   VARCHAR(32) 8757
};
//客户所在节点编号查询
struct MATRADEAPI CReqCosNodeInfoField
{
  char     szCuacctCode[16+1];//资产账户CUACCT_CODEBIGINTY 8920
	char     szCustCode[16+1];  //客户代码CUST_CODE  BIGINTX 8902
};

struct MATRADEAPI CRspCosNodeInfoField
{
  char     szCuacctCode[16+1];    //资产账户 CUACCT_CODEBIGINT  8920
  char     chCuacctType;         //资产账户类型
	char     szCustCode[16+1];      //客户代码 CUST_CODE  BIGINT  8902
	int      iSubsys;         //子系统  SUBSYS     SMALLINT9080
	int      iSubsysSn;       //子系统编码SUBSYS_SN  SMALLINT8988
	int      iNodeIdOrg;      //原节点编号NODE_ID_ORGINTEGER 9081
	int      iNodeIdNow;      //现节点编号NODE_ID_NOWINTEGER 9082
};
//节点的客户查询
struct MATRADEAPI CReqCosNodeCustInfoField
{
	int      iNodeIdOrg;//原节点编号NODE_ID_ORGINTEGER    X 9081不能同时为空
	int      iNodeIdNow;//现节点编号NODE_ID_NOWINTEGER    X 9082不能同时为空
	char     szQueryPos[32+1];//定位串  QUERY_POS  VARCHAR(32)X 8991
	int      iQueryNum; //查询行数 QUERY_NUM  INTEGER    X 8992最大值为1000
};

struct MATRADEAPI CRspCosNodeCustInfoField
{
	char     szQryPos[32+1]; //定位串  QRY_POS    VARCHAR(32)8991
  char     szCuacctCode[16+1];    //资产账户 CUACCT_CODEBIGINT     8920
  char     chCuacctType;         //资产账户类型
	char     szCustCode[16+1];      //客户代码 CUST_CODE  BIGINT     8902
	int      iSubsys;         //子系统  SUBSYS     SMALLINT   9080
	int      iSubsysSn;       //子系统编码SUBSYS_SN  SMALLINT   8988
	int      iNodeIdOrg;      //原节点编号NODE_ID_ORGINTEGER    9081
	int      iNodeIdNow;      //现节点编号NODE_ID_NOWINTEGER    9082
};
//接口配置查询
struct MATRADEAPI CReqCosItfInfoField
{
	char     szItfDataTypes[32+1];//接口数据类型ITF_DATA_TYPESCHAR(32)X 9028
	char     szItfDataFlows[32+1];//接口数据流向ITF_DATA_FLOWSCHAR(32)X 9029
};

struct MATRADEAPI CRspCosItfInfoField
{
	int      iItfCfgSn;        //接口配置序号ITF_CFG_SN   INTEGER     9023
	char     szItfId[32+1];   //接口标识  ITF_ID       VARCHAR(32) 9027
	char     szItfString[256+1];//接口字串  ITF_STRING   VARCHAR(256)9032
	char     szItfName[32+1]; //接口名称  ITF_NAME     VARCHAR(32) 9033
	char     chItfType;        //接口类型  ITF_TYPE     CHAR(1)     9034字典[ITF_TYPE]
	char     chItfDataType;    //接口数据类型ITF_DATA_TYPECHAR(1)     9028字典[ITF_DATA_TYPE]
	char     chItfDataFlow;    //接口数据流向ITF_DATA_FLOWCHAR(1)     9029字典[ITF_DATA_FLOW]
};
//接口配置设置
struct MATRADEAPI CReqCosChgItfField
{
	char     chOperationType;//操作类型  OPERATION_TYPECHAR(1)     Y 89870:新增
	int      iItfCfgSn;      //接口配置序号ITF_CFG_SN    INTEGER     Y 9023 接口配置序号
	char     szItfId[32+1]; //接口标识  ITF_ID        VARCHAR(32) Y 9027 接口标识
	char     szItfString[256+1];//接口字串  ITF_STRING    VARCHAR(256)Y 9032 接口字串
	char     szItfName[32+1];//接口名称  ITF_NAME      VARCHAR(32) Y 9033 接口名称
	char     chItfType;      //接口类型  ITF_TYPE      CHAR(1)     Y 9034 接口类型
	char     chItfDataType;  //接口数据类型ITF_DATA_TYPE CHAR(1)     Y 9028 接口数据类型
	char     chItfDataFlow;  //接口数据流向ITF_DATA_FLOW CHAR(1)     Y 9029 接口数据流向
	char     szItfFilePath[256+1];//接口文件路径ITF_FILE_PATH VARCHAR(256)Y 9026 
	char     szItfSyncXa[64+1];//接口同步XAITF_SYNC_XA   VARCHAR(64) Y 9082 
	char     szItfProcClsid[64+1];//接口处理组件ITF_PROC_CLSIDVARCHAR(64) Y 9083 
};

struct MATRADEAPI CRspCosChgItfField
{
};
//量化可撤单委托查询
struct MATRADEAPI CReqCosCanWithdrawOrderField
{
  char     szCuacctCode[16+1];//资产账户  CUACCT_CODE BIGINT     Y 8920 
  char     chCuacctType;         //资产账户类型
	char     szStkbd[2+1];//交易板块  STKBD       CHAR(2)    X 625  
	int      iTrdCodeCls; //品种类型  TRD_CODE_CLSINTEGER    X 8970 
	char     szTrdCode[8+1];//品种代码  TRD_CODE    VARCHAR(8) X 48   
	int      iOrderNo;    //委托编号  ORDER_NO    INTEGER    X 9106 
	int      iOrderBsn;   //委托批号  ORDER_BSN   INTEGER    X 66   
	char     szTrdacct[10+1];//交易账户  TRDACCT     VARCHAR(10)X 448  
	int      iAttrCode;   //属性代码  ATTR_CODE   SMALLINT   X 9101 
	char     chExeStatus; //执行状态  EXE_STATUS  CHAR(1)    X 9103 
	int      iBgnExeTime; //执行开始时间BGN_EXE_TIMEINTEGER    X 916  
	char     chQueryFlag; //查询方向  QUERY_FLAG  CHAR(1)    Y 90800:向后取数据1:向前取数据其他全部返回
	char     szQueryPos[32+1];//定位串   QUERY_POS   VARCHAR(32)X 8991 与查询方向和资产账户配合使用
	int      iQueryNum;   //查询行数  QUERY_NUM   INTEGER    Y 8992 最大值为1000
};

struct MATRADEAPI CRspCosCanWithdrawOrderField
{
	char     szQryPos[32+1];    //定位串    QRY_POS       VARCHAR(32) 8991
  char     szCuacctCode[16+1];       //资产账户   CUACCT_CODE   BIGINT      8920
  char     chCuacctType;         //资产账户类型
	char     szCustCode[16+1];         //客户代码   CUST_CODE     BIGINT      8902
	char     szTrdacct[10+1];   //交易账户   TRDACCT       VARCHAR(10) 448 
	char     chExchange;         //交易所    EXCHANGE      CHAR(1)     207 
	char     szStkbd[2+1];      //交易板块   STKBD         CHAR(2)     625 
	int      iTrdCodeCls;        //品种类型   TRD_CODE_CLS  INTEGER     8970
	int      iStkBiz;            //交易业务   STK_BIZ       SMALLINT    8842
	int      iStkBizAction;      //业务活动   STK_BIZ_ACTIONSMALLINT    40  
	char     szTrdCode[8+1];    //品种代码   TRD_CODE      VARCHAR(8)  48  
	int      iOrderDate;         //委托日期   ORDER_DATE    INTEGER     8834
	char     szOrderTime[32+1]; //委托时间   ORDER_TIME    VARCHAR(32) 8845
	int      iOrderBsn;          //委托批号   ORDER_BSN     INTEGER     66  
	int      iOrderNo;           //委托编号   ORDER_NO      INTEGER     9106
	LONGLONG llOrderQty;         //委托数量   ORDER_QTY     BIGINT      38  
	char     szOrderPrice[21+1]; //委托价格   ORDER_PRICE   CPRICE      44  
	char     szStopPrice[21+1];  //触发价格   STOP_PRICE    CPRICE      8975
	int      iValidDate;         //截止日期   VALID_DATE    INTEGER     8859
	char     szOrderAttr[256+1];//高级属性   ORDER_ATTR    VARCHAR(256)9100
	int      iAttrCode;          //属性代码   ATTR_CODE     SMALLINT    9101
	int      iBgnExeTime;        //执行开始时间 BGN_EXE_TIME  INTEGER     916 
	int      iEndExeTime;        //执行结束时间 END_EXE_TIME  INTEGER     917 
	char     szSpreadName[64+1];//组合名称   SPREAD_NAME   VARCHAR(64) 8971
	char     szUndlCode[16+1];  //标的代码   UNDL_CODE     VARCHAR(16) 8972
	int      iConExpDate;        //合约到期日  CON_EXP_DATE  INTEGER     8976
	char     szExercisePrice[21+1];//行权价    EXERCISE_PRICECPRICE      8973
	LONGLONG llConUnit;          //合约单位   CON_UNIT      BIGINT      8974
	char     szCliOrderNo[32+1];//客户端委托编号CLI_ORDER_NO  VARCHAR(32) 9102
	char     szCliRemark[32+1]; //备用信息   CLI_REMARK    VARCHAR(32) 8914
	char     chExeStatus;        //执行状态   EXE_STATUS    CHAR(1)     9103
	char     szExeInfo[128+1];  //执行信息   EXE_INFO      VARCHAR(128)9104
	LONGLONG llExeQty;           //执行数量   EXE_QTY       BIGINT      9105
	LONGLONG llMatchedQty;       //已成交数量  MATCHED_QTY   BIGINT      387 
	LONGLONG llWithdrawnQty;     //已撤单数量  WITHDRAWN_QTY BIGINT      8837
	char     szMatchedAmt[21+1]; //已成交金额  MATCHED_AMT   CMONEY      8504
};
//量化成交查询
struct MATRADEAPI CReqCosMatchField
{
  char     szCuacctCode[16+1];//资产账户CUACCT_CODEBIGINT     Y 8920 
  char     chCuacctType;         //资产账户类型
	char     szStkbd[2+1];//交易板块STKBD      CHAR(2)    X 625  
	char     szTrdCode[8+1];//品种代码TRD_CODE   VARCHAR(8) X 48   
	int      iOrderNo;    //委托编号ORDER_NO   INTEGER    X 9106 
	int      iOrderBsn;   //委托批号ORDER_BSN  INTEGER    X 66   
	char     szTrdacct[10+1];//交易账户TRDACCT    VARCHAR(10)X 448  
	char     szOptNum[16+1];//合约代码OPT_NUM    VARCHAR(16)X 9082 
	char     chQueryFlag; //查询方向QUERY_FLAG CHAR(1)    Y 90800:向后取数据
	char     szQueryPos[32+1];//定位串 QUERY_POS  VARCHAR(32)X 8991 与查询方向和资产账户配合使用
	int      iQueryNum;   //查询行数QUERY_NUM  INTEGER    Y 8992 最大值为1000
};

struct MATRADEAPI CRspCosMatchField
{
	char     szQryPos[32+1];      //定位串     QRY_POS           VARCHAR(32)8991
	int      iOrderDate;           //委托日期    ORDER_DATE        INTEGER    8834
	char     chMatchedType;        //成交类型    MATCHED_TYPE      CHAR(1)    8992
	char     szMatchedSn[16+1];   //成交编号    MATCHED_SN        VARCHAR(16)17  
	int      iOrderBsn;            //委托批号    ORDER_BSN         INTEGER    66  
	LONGLONG llCliOrderGroupNo;    //组合编号    CLI_ORDER_GROUP_NOBIGINT     9301
	char     szClientId[32+1];    //客户订单标识  CLIENT_ID         VARCHAR(32)8858
	int      iOrderNo;             //委托编号    ORDER_NO          INTEGER    9106
	char     szOrderId[10+1];     //合同序号    ORDER_ID          VARCHAR(10)11  
  char     szCuacctCode[16+1];         //资产账户    CUACCT_CODE       BIGINT     8920
  char     chCuacctType;         //资产账户类型
	char     szCustCode[16+1];           //客户代码    CUST_CODE         BIGINT     8902
	char     szTrdacct[10+1];     //交易账户    TRDACCT           VARCHAR(10)448 
	char     chExchange;           //交易所     EXCHANGE          CHAR(1)    207 
	char     szStkbd[2+1];        //交易板块    STKBD             CHAR(2)    625 
	int      iStkBiz;              //交易业务    STK_BIZ           SMALLINT   8842
	int      iStkBizAction;        //业务活动    STK_BIZ_ACTION    SMALLINT   40  
	char     szTrdCode[8+1];      //品种代码    TRD_CODE          VARCHAR(8) 48  
	LONGLONG llMatchedQty;         //已成交数量   MATCHED_QTY       BIGINT     387 
	char     szMatchedPrice[21+1]; //成交价格    MATCHED_PRICE     CPRICE     8841
	int      iMatchedDate;         //成交日期    MATCHED_DATE      INTEGER    8839
	char     szMatchedTime[8+1];  //成交时间    MATCHED_TIME      VARCHAR(8) 8840
	int      iSubsys;              //交易系统类型  SUBSYS            SMALLINT   9080
	int      iSubsysSn;            //交易系统编码  SUBSYS_SN         SMALLINT   8988
	int      iErrorId;             //错误代码    ERROR_ID          SMALLINT   8900
	char     szErrorMsg[81+1];    //错误信息    ERROR_MSG         VARCHAR(81)8901
	char     szBrokerId[11+1];    //经纪公司代码  BROKER_ID         VARCHAR(11)8890
	char     szParticipantId[11+1];//会员代码    PARTICIPANT_ID    VARCHAR(11)8724
	char     chTradingRole;        //交易角色    TRADING_ROLE      VARCHAR(1) 8763
	char     szCombOffsetFlag[5+1];//组合开平标志  COMB_OFFSET_FLAG  VARCHAR(5) 8741
	char     szCombHedgeFlag[5+1];//组合投机套保标志COMB_HEDGE_FLAG   VARCHAR(5) 8742
	char     chPriceSource;        //成交价来源   PRICE_SOURCE      VARCHAR(1) 8765
	char     szTraderId[21+1];    //交易所交易员代码TRADER_ID         VARCHAR(21)8726
	char     szClearingPartId[11+1];//结算会员编号  CLEARING_PART_ID  VARCHAR(11)8759
	int      iBrokerOrderSeq;      //经纪公司报单编号BROKER_ORDER_SEQ  SMALLINT   8746
};
//量化子委托查询
struct MATRADEAPI CReqCosSubOrderField
{
  char     szCuacctCode[16+1];   //资产账户CUACCT_CODE   BIGINT     Y 8920 
  char     chCuacctType;         //资产账户类型
	char     szStkbd[2+1];  //交易板块STKBD         CHAR(2)    X 625  
	char     szTrdCode[8+1];//品种代码TRD_CODE      VARCHAR(8) X 48   
	char     szOptNum[16+1];//合约编码OPT_NUM       VARCHAR(16)X 9082 
	int      iOrderNo;       //委托编号ORDER_NO      INTEGER    X 9106 
	int      iOrderBsn;      //委托批号ORDER_BSN     INTEGER    X 66   
	char     szTrdacct[10+1];//交易账户TRDACCT       VARCHAR(10)X 448  
	char     szOrderStatuses[32+1];//委托状态ORDER_STATUSESVARCHAR(32)X 39   复数
	char     chQueryFlag;    //查询方向QUERY_FLAG    CHAR(1)    Y 90800:向后取数据
	char     szQueryPos[32+1];//定位串 QUERY_POS     VARCHAR(32)X 8991 与查询方向和资产账户配合使用
	int      iQueryNum;      //查询行数QUERY_NUM     INTEGER    Y 8992 最大值为1000
};

struct MATRADEAPI CRspCosSubOrderField
{
	char     szQryPos[32+1];     //定位串     QRY_POS         VARCHAR(32) 8991
	int      iOrderDate;          //委托日期    ORDER_DATE      INTEGER     8834
	int      iOrderBsn;           //委托批号    ORDER_BSN       INTEGER     66  
	LONGLONG llOrderGroupNo;      //组合编号    ORDER_GROUP_NO  BIGINT      9300
	char     szOrderClientId[32+1];//客户订单标识  ORDER_CLIENT_ID VARCHAR(32) 9102
	int      iOrderNo;            //委托编号    ORDER_NO        INTEGER     9106
	int      iSuborderSn;         //子单序号    SUBORDER_SN     INTEGER     9107
	char     szOrderId[32+1];    //合同序号    ORDER_ID        VARCHAR(32) 11  
	char     chIsWithdraw;        //撤单标志    IS_WITHDRAW     CHAR(1)     8836字典[IS_WITHDRAW]
	char     chIsWithdrawn;       //已撤单标志   IS_WITHDRAWN    CHAR(1)     8838字典[IS_WITHDRAWN]
	char     szOrderTime[32+1];  //委托时间    ORDER_TIME      VARCHAR(32) 8845
	int      iExeDate;            //执行日期    EXE_DATE        INTEGER     916 
	char     szExeTime[32+1];    //执行时间    EXE_TIME        VARCHAR(32) 917 
	char     szCuacctCode[16+1];        //资产账户    CUACCT_CODE     BIGINT      8920
	char     szCustCode[16+1];          //客户代码    CUST_CODE       BIGINT      8902
	char     szTrdacct[10+1];    //交易账户    TRDACCT         VARCHAR(10) 448 
	char     chExchange;          //交易所     EXCHANGE        CHAR(1)     207 
	char     szStkbd[2+1];       //交易板块    STKBD           CHAR(2)     625 
	int      iStkBiz;             //交易业务    STK_BIZ         SMALLINT    8842
	int      iStkBizAction;       //业务活动    STK_BIZ_ACTION  SMALLINT    40  
	char     szTrdCode[8+1];     //品种代码    TRD_CODE        VARCHAR(8)  48  
	char     szOptNum[16+1];     //合约编码    OPT_NUM         VARCHAR(16) 9082
	int      iIntOrg;             //内部机构    INT_ORG         SMALLINT    8911
	LONGLONG llOrderQty;          //委托数量    ORDER_QTY       BIGINT      38  
	char     szOrderPrice[21+1];  //委托价格    ORDER_PRICE     CPRICE      44  
	LONGLONG llMatchedQty;        //已成交数量   MATCHED_QTY     BIGINT      387 
	LONGLONG llWithdrawnQty;      //已撤单数量   WITHDRAWN_QTY   BIGINT      8837
	char     chOrderStatus;       //委托状态    ORDER_STATUS    CHAR(1)     39  
	int      iSubsys;             //交易系统类型  SUBSYS          SMALLINT    9080
	int      iSubsysSn;           //交易系统编码  SUBSYS_SN       SMALLINT    8988
	char     szExeInfo[128+1];   //执行信息    EXE_INFO        VARCHAR(128)9104
	char     chOrderPriceType;    //报单价格条件  ORDER_PRICE_TYPEVARCHAR(1)  8739
	char     szCombOffsetFlag[5+1];//组合开平标志  COMB_OFFSET_FLAGVARCHAR(5)  8741
	char     szCombHedgeFlag[5+1];//组合投机套保标志COMB_HEDGE_FLAG VARCHAR(5)  8742
	char     szStopPrice[21+1];   //触发价格    STOP_PRICE      CPRICE      8975
	int      iFrontId;            //前置编号    FRONT_ID        INTEGER     8732
	LONGLONG llSessionId;         //会话编号    SESSION_ID      BIGINT      8814
	char     szOrderIdEx[64+1];  //外部合同序号  ORDER_ID_EX     VARCHAR(64) 9093
};

//历史委托查询
struct MATRADEAPI CReqCosHisOrderInfoField
{
  char     szCuacctCode[16+1];   //资产账户  CUACCT_CODE   BIGINT     Y 8920 
  char     chCuacctType;         //资产账户类型
	char     szCustCode[16+1];     //客户代码  CUST_CODE     BIGINT     X 8902 
	char     szTrdCode[8+1];//品种代码  TRD_CODE      VARCHAR(8) X 48   
	int      iBgnDate;       //开始日期  BGN_DATE      INTEGER    Y 916  
	int      iEndDate;       //结束日期  END_DATE      INTEGER    Y 917  
	char     szExeStatuses[32+1];//执行状态  EXE_STATUSES  VARCHAR(32)X 9103 复数
	int      iOrderNo;       //委托编号  ORDER_NO      INTEGER    X 9106 
	char     chQueryFlag;    //查询方向  QUERY_FLAG    CHAR(1)    Y 90800:向后取数据
	char     szQueryPos[32+1];//定位串   QUERY_POS     VARCHAR(32)X 8991 与查询方向和资产账户配合使用
	int      iQueryNum;      //查询行数  QUERY_NUM     INTEGER    Y 8992 最大值为1000
	char     chModifiedState;//状态修改标识MODIFIED_STATECHAR(1)    X 8899 将中间状态修改为最终状态；
};

struct MATRADEAPI CRspCosHisOrderInfoField
{
	char     szQryPos[32+1];    //定位串    QRY_POS       VARCHAR(32) 8991
  char     szCuacctCode[16+1];       //资产账户   CUACCT_CODE   BIGINT      8920
  char     chCuacctType;         //资产账户类型
	char     szCustCode[16+1];         //客户代码   CUST_CODE     BIGINT      8902
	char     szTrdacct[10+1];   //交易账户   TRDACCT       VARCHAR(10) 448 
	char     chExchange;         //交易所    EXCHANGE      CHAR(1)     207 
	char     szStkbd[2+1];      //交易板块   STKBD         CHAR(2)     625 
	int      iTrdCodeCls;        //品种类型   TRD_CODE_CLS  INTEGER     8970
	int      iStkBiz;            //交易业务   STK_BIZ       SMALLINT    8842
	int      iStkBizAction;      //业务活动   STK_BIZ_ACTIONSMALLINT    40  
	char     szTrdCode[8+1];    //品种代码   TRD_CODE      VARCHAR(8)  48  
	char     szOptNum[16+1];    //合约编码   OPT_NUM       VARCHAR(16) 9082
	int      iIntOrg;            //内部机构   INT_ORG       SMALLINT    8911
	int      iOrderDate;         //委托日期   ORDER_DATE    INTEGER     8834
	char     szOrderTime[32+1]; //委托时间   ORDER_TIME    VARCHAR(32) 8845
	int      iOrderBsn;          //委托批号   ORDER_BSN     INTEGER     66  
	int      iOrderNo;           //委托编号   ORDER_NO      INTEGER     9106
	LONGLONG llOrderQty;         //委托数量   ORDER_QTY     BIGINT      38  
	char     szOrderPrice[21+1]; //委托价格   ORDER_PRICE   CPRICE      44  
	char     szStopPrice[21+1];  //触发价格   STOP_PRICE    CPRICE      8975
	int      iValidDate;         //截止日期   VALID_DATE    INTEGER     8859
	char     szOrderAttr[256+1];//高级属性   ORDER_ATTR    VARCHAR(256)9100
	int      iAttrCode;          //属性代码   ATTR_CODE     SMALLINT    9101
	int      iBgnExeTime;        //执行开始时间 BGN_EXE_TIME  INTEGER     916 
	int      iEndExeTime;        //执行结束时间 END_EXE_TIME  INTEGER     917 
	char     szSpreadName[64+1];//组合名称   SPREAD_NAME   VARCHAR(64) 8971
	char     szUndlCode[16+1];  //标的代码   UNDL_CODE     VARCHAR(16) 8972
	int      iConExpDate;        //合约到期日  CON_EXP_DATE  INTEGER     8976
	char     szExercisePrice[21+1];//行权价    EXERCISE_PRICECPRICE      8973
	LONGLONG llConUnit;          //合约单位   CON_UNIT      BIGINT      8974
	char     szCliOrderNo[32+1];//客户端委托编号CLI_ORDER_NO  VARCHAR(32) 9102
	char     szCliRemark[32+1]; //备用信息   CLI_REMARK    VARCHAR(32) 8914
	char     chExeStatus;        //执行状态   EXE_STATUS    CHAR(1)     9103
	char     szExeInfo[128+1];  //执行信息   EXE_INFO      VARCHAR(128)9104
	LONGLONG llExeQty;           //执行数量   EXE_QTY       BIGINT      9105
	LONGLONG llMatchedQty;       //已成交数量  MATCHED_QTY   BIGINT      387 
	LONGLONG llWithdrawnQty;     //已撤单数量  WITHDRAWN_QTY BIGINT      8837
	char     szMatchedAmt[21+1]; //已成交金额  MATCHED_AMT   CMONEY      8504
};

//-------------------------------10388357:历史成交查询--------------------------
struct MATRADEAPI CReqCosHisFillInfoField
{
  char            szCuacctCode[16 + 1];       // 资产账户 
  char            szStkbd[2 + 1];             // 交易板块 
  char            chCuacctType;               // 账户类型 
  char            szTrdCode[30 + 1];          // 品种代码 
  int             iBgnDate;                   // 开始日期 
  int             iEndDate;                   // 结束日期 
  int             iOrderNo;                   // 委托编号 
  int             iOrderBsn;                  // 委托批号 
  char            szTrdacct[32 + 1];          // 交易账户 
  char            szOptNum[16 + 1];           // 合约代码 
  char            chQueryFlag;                // 查询方向 0:向后取数据 1:向前取数据
  char            szQueryPos[32 + 1];         // 定位串 
  int             iQueryNum;                  // 查询行数 最大值为1000
};

struct MATRADEAPI CRspCosHisFillInfoField
{
  char            szQryPos[32 + 1];           // 定位串 
  int             iOrderDate;                 // 委托日期 
  char            chMatchedType;              // 成交类型 
  char            szMatchedSn[16 + 1];        // 成交编号 
  int             iOrderBsn;                  // 委托批号 
  LONGLONG        llCliOrderGroupNo;          // 组合编号 
  char            szClientId[32 + 1];         // 客户订单标识 
  int             iOrderNo;                   // 委托编号 
  char            szOrderId[21 + 1];          // 合同序号 
  char            szCuacctCode[16 + 1];       // 资产账户 
  char            chCuacctType;               // 账户类型 
  char            szCustCode[16 + 1];         // 客户代码 
  char            szTrdacct[32 + 1];          // 交易账户 
  char            chExchange;                 // 交易所 
  char            szStkbd[2 + 1];             // 交易板块 
  int             iStkBiz;                    // 交易业务 
  int             iStkBizAction;              // 业务活动 
  char            szTrdCode[30 + 1];          // 品种代码 
  LONGLONG        llMatchedQty;               // 已成交数量 
  char            szMatchedPrice[21 + 1];     // 成交价格 
  int             iMatchedDate;               // 成交日期 
  char            szMatchedTime[8 + 1];       // 成交时间 
  int             iSubsys;                    // 交易系统类型 
  int             iSubsysSn;                  // 交易系统编码 
  int             iErrorId;                   // 错误代码 
  char            szErrorMsg[81 + 1];         // 错误信息 
  char            szBrokerId[11 + 1];         // 经纪公司代码 
  char            szParticipantId[11 + 1];    // 会员代码 
  char            chTradingRole;              // 交易角色 
  char            szCombOffsetFlag[5 + 1];    // 组合开平标志 
  char            szCombHedgeFlag[5 + 1];     // 组合投机套保标志 
  char            chPriceSource;              // 成交价来源 
  char            szTraderId[21 + 1];         // 交易所交易员代码 
  char            szClearingPartId[11 + 1];   // 结算会员编号 
  int             iBrokerOrderSeq;            // 经纪公司报单编号 
};

//组合委托查询
struct MATRADEAPI CReqCosCombOrderInfoField
{
  char     szCuacctCode[16+1];  //资产账户CUACCT_CODE   BIGINT     Y 8920 
  char     chCuacctType;         //资产账户类型
	int      iOrderBsn;     //委托批号ORDER_BSN     INTEGER    X 66   
	LONGLONG llOrderGroupNo;//组合编号ORDER_GROUP_NOBIGINT     X 9300 
	char     szExeStatuses[32+1];//执行状态EXE_STATUSES  VARCHAR(32)X 9103 复数 
	char     chQueryFlag;   //查询方向QUERY_FLAG    CHAR(1)    Y 90800:向后取数据1:向前取数据其他全部返回
	char     szQueryPos[32+1];//定位串 QUERY_POS     VARCHAR(32)X 8991 与查询方向和资产账户配合使用
	int      iQueryNum;     //查询行数QUERY_NUM     INTEGER    Y 8992 最大值为1000
};

struct MATRADEAPI CRspCosCombOrderInfoField
{
	int      iOrderBsn;               //委托批号    ORDER_BSN            INTEGER     66  
	LONGLONG llOrderGroupNo;          //组合编号    ORDER_GROUP_NO       BIGINT      9300
	char     szCliOrderGroupNo[32+1];//组合编号(客户)CLI_ORDER_GROUP_NO   VARCHAR(32) 9301
	char     szOrderGroupType[32+1]; //组合类型    ORDER_GROUP_TYPE     VARCHAR(32) 9306
	LONGLONG llOrderGroupParentNo;    //父组合编号   ORDER_GROUP_PARENT_NOBIGINT      9302
	LONGLONG llOrderParentNo;         //父委托编号   ORDER_PARENT_NO      BIGINT      9304
	char     chExeStatus;             //执行状态    EXE_STATUS           CHAR(1)     9103
	int      iOrderDate;              //委托日期    ORDER_DATE           INTEGER     8834
	char     szOrderTime[32+1];      //委托时间    ORDER_TIME           VARCHAR(32) 8845
	int      iOrderValidDate;         //有效日期    ORDER_VALID_DATE     INTEGER     8859
	char     szCustCode[16+1];              //客户代码    CUST_CODE            BIGINT      8902
  char     szCuacctCode[16+1];            //资产账户    CUACCT_CODE          BIGINT      8920
	int      iTrdDate;                //交易日期    TRD_DATE             INTEGER     8844
	char     szRemark[128+1];        //备注信息    REMARK               VARCHAR(128)8914
	char     szQueryPos[32+1];       //查询定位串   QUERY_POS            VARCHAR(32) 8991
};
//资产用户查询
struct MATRADEAPI CReqCosCuacctCodeInfoField
{
  char     szCuacctCode[16+1];//资产账户CUACCT_CODEBIGINT  X 8920  
  char     chCuacctType;         //资产账户类型
	char     szCustCode[16+1];  //客户代码CUST_CODE  BIGINT  X 8902  
	int      iSubsys;     //子系统 SUBSYS     SMALLINTX 908081:证券现货交易系统 82:个股期权交易系统 83:股指期货交易系统
	LONGLONG llQueryPos;  //定位串 QUERY_POS  BIGINT  Y 8991  以资产账户作为定位串
	int      iQueryNum;   //查询行数QUERY_NUM  INTEGER Y 8992  最大行数10000
};

struct MATRADEAPI CRspCosCuacctCodeInfoField
{
	int      iSubsys;            //子系统   SUBSYS         SMALLINT   9080
	LONGLONG llSubsysSn;         //组合编号  SUBSYS_SN      BIGINT     9300
	char     szLastLoginTime[32+1];//最后登录时间LAST_LOGIN_TIMEVARCHAR(32)9901
	char     szCustCode[16+1];         //客户代码  CUST_CODE      BIGINT     8902
	char     szCuacctCode[16+1];       //资产账户  CUACCT_CODE    BIGINT     8920
	int      iNodeIdNow;         //现节点编号 NODE_ID_NOW    INTEGER    9082
	int      iNodeIdOrg;         //原节点编号 NODE_ID_ORG    INTEGER    9081
};

//节点账户查询
struct MATRADEAPI CReqCosNodeUsersField
{
	LONGLONG llQueryPos;//定位串 QUERY_POSBIGINT Y 8991以资产账户作为定位串
	int      iQueryNum; //查询行数QUERY_NUMINTEGERY 8992最大行数10000
};

struct MATRADEAPI CRspCosNodeUsersField
{
	char     szCuacctCode[16+1];    //资产账户 CUACCT_CODEBIGINT  8920
	char     szCustCode[16+1];      //客户代码 CUST_CODE  BIGINT  8902
	int      iSubsys;         //子系统  SUBSYS     SMALLINT9080
	int      iSubsysSn;       //子系统编码SUBSYS_SN  SMALLINT8988
	int      iNodeIdOrg;      //原节点编号NODE_ID_ORGINTEGER 9081
	int      iNodeIdNow;      //现节点编号NODE_ID_NOWINTEGER 9082
};

//-------------------------------10388352:根据组合委托编号查询组合委托--------------------------
struct MATRADEAPI CReqCosCombOrderInfoExField
{
  int             iOrderDate;                 // 委托日期 
  int             iOrderBsn;                  // 委托批号 
  LONGLONG        llOrderGroupNo;             // 组合编号 
  char            szCuacctCode[16 + 1];       // 资产账户 
  char            chCuacctType;               // 账户类型 
};

struct MATRADEAPI CRspCosCombOrderInfoExField
{
  LONGLONG        llOrderGroupNo;             // 组合编号 
  char            szCuacctCode[16 + 1];       // 资产账户 
  char            szCustCode[16 + 1];         // 客户代码 
  char            szTrdacct[32 + 1];          // 交易账户 
  char            chExchange;                 // 交易所 
  char            szStkbd[2 + 1];             // 交易板块 
  char            chCuacctType;               // 账户类型 
  int             iStkBiz;                    // 交易业务 
  int             iStkBizAction;              // 业务活动 
  char            szTrdCode[30 + 1];          // 品种代码 
  char            szOptNum[16 + 1];           // 合约编码 
  int             iIntOrg;                    // 内部机构 
  int             iOrderDate;                 // 委托日期 
  char            szOrderTime[32 + 1];        // 委托时间 
  int             iOrderBsn;                  // 委托批号 
  int             iOrderNo;                   // 委托编号 
  LONGLONG        llOrderQty;                 // 委托数量 
  char            szOrderPrice[21 + 1];       // 委托价格 
  char            szStopPrice[21 + 1];        // 触发价格 
  int             iValidDate;                 // 截止日期 
  char            szOrderAttr[256 + 1];       // 高级属性 
  int             iAttrCode;                  // 属性代码 
  int             iBgnExeTime;                // 执行开始时间 
  int             iEndExeTime;                // 执行结束时间 
  char            szUndlCode[16 + 1];         // 标的代码 
  int             iConExpDate;                // 合约到期日 
  char            szExercisePrice[21 + 1];    // 行权价 
  LONGLONG        llConUnit;                  // 合约单位 
  char            szCliOrderNo[32 + 1];       // 客户端委托编号 
  char            szCliRemark[256 + 1];       // 留痕信息 
  char            chExeStatus;                // 执行状态 
  char            szExeInfo[128 + 1];         // 执行信息 
  LONGLONG        llExeQty;                   // 执行数量 
  LONGLONG        llMatchedQty;               // 已成交数量 
  LONGLONG        llWithdrawnQty;             // 已撤单数量 
  char            szMatchedAmt[21 + 1];       // 已成交金额 
  char            szUpdateTime[32 + 1];       // 最后修改时间 
};

//行情处理快照
struct MATRADEAPI CReqCosSnapshotField
{
	char     chExchange;     //交易所   EXCHANGE       CHAR(1)    Y 207 
	char     szTrdCode[16+1];//交易代码  TRD_CODE       VARCHAR(16)Y 48  
	LONGLONG llTrdDate;      //行情日期  TRD_DATE       BIGINT     Y 8844
	LONGLONG llDataTime;     //行情时间  DATA_TIME      BIGINT     Y 8816
	char     chStatus;       //品种状态  STATUS         CHAR(1)    Y 326 
	LONGLONG llPreClosePrice;//昨收盘价  PRE_CLOSE_PRICEBIGINT     Y 140 
	LONGLONG llOpenPrice;    //开盘价   OPEN_PRICE     BIGINT     Y 8957
	LONGLONG llHighPrice;    //最高价   HIGH_PRICE     BIGINT     Y 8983
	LONGLONG llLowPrice;     //最低价   LOW_PRICE      BIGINT     Y 8984
	LONGLONG llCurPrice;     //最新价   CUR_PRICE      BIGINT     Y 8958
	LONGLONG llAns1Price;     //申卖价1  ANS1_PRICE     BIGINT     Y 9080
	LONGLONG llAns2Price;     //申卖价2  ANS2_PRICE     BIGINT     Y 9081
	LONGLONG llAns3Price;     //申卖价3  ANS3_PRICE     BIGINT     Y 9082
	LONGLONG llAns4Price;     //申卖价4  ANS4_PRICE     BIGINT     Y 9083
	LONGLONG llAns5Price;     //申卖价5  ANS5_PRICE     BIGINT     Y 9084
	LONGLONG llAns6Price;     //申卖价6  ANS6_PRICE     BIGINT     X 9085
	LONGLONG llAns7Price;     //申卖价7  ANS7_PRICE     BIGINT     X 9086
	LONGLONG llAns8Price;     //申卖价8  ANS8_PRICE     BIGINT     X 9087
	LONGLONG llAns9Price;     //申卖价9  ANS9_PRICE     BIGINT     X 9088
	LONGLONG llAns10Price;     //申卖价10 ANS10_PRICE    BIGINT     X 9089
	LONGLONG llAns1Vol;       //申卖量1  ANS1_VOL       BIGINT     Y 9090
	LONGLONG llAns2Vol;       //申卖量2  ANS2_VOL       BIGINT     Y 9091
	LONGLONG llAns3Vol;       //申卖量3  ANS3_VOL       BIGINT     Y 9092
	LONGLONG llAns4Vol;       //申卖量4  ANS4_VOL       BIGINT     Y 9093
	LONGLONG llAns5Vol;       //申卖量5  ANS5_VOL       BIGINT     Y 9094
	LONGLONG llAns6Vol;       //申卖量6  ANS6_VOL       BIGINT     X 9095
	LONGLONG llAns7Vol;       //申卖量7  ANS7_VOL       BIGINT     X 9096
	LONGLONG llAns8Vol;       //申卖量8  ANS8_VOL       BIGINT     X 9097
	LONGLONG llAns9Vol;       //申卖量9  ANS9_VOL       BIGINT     X 9098
	LONGLONG llAns10Vol;       //申卖量10 ANS10_VOL      BIGINT     X 9099
	LONGLONG llBid1Price;     //申买价1  BID1_PRICE     BIGINT     Y 9180
	LONGLONG llBid2Price;     //申买价2  BID2_PRICE     BIGINT     Y 9181
	LONGLONG llBid3Price;     //申买价3  BID3_PRICE     BIGINT     Y 9182
	LONGLONG llBid4Price;     //申买价4  BID4_PRICE     BIGINT     Y 9183
	LONGLONG llBid5Price;     //申买价5  BID5_PRICE     BIGINT     Y 9184
	LONGLONG llBid6Price;     //申买价6  BID6_PRICE     BIGINT     X 9185
	LONGLONG llBid7Price;     //申买价7  BID7_PRICE     BIGINT     X 9186
	LONGLONG llBid8Price;     //申买价8  BID8_PRICE     BIGINT     X 9187
	LONGLONG llBid9Price;     //申买价9  BID9_PRICE     BIGINT     X 9188
	LONGLONG llBid10Price;     //申买价10 BID10_PRICE    BIGINT     X 9189
	LONGLONG llBid1Vol;       //申买量1  BID1_VOL       BIGINT     Y 9190
	LONGLONG llBid2Vol;       //申买量2  BID2_VOL       BIGINT     Y 9191
	LONGLONG llBid3Vol;       //申买量3  BID3_VOL       BIGINT     Y 9192
	LONGLONG llBid4Vol;       //申买量4  BID4_VOL       BIGINT     Y 9193
	LONGLONG llBid5Vol;       //申买量5  BID5_VOL       BIGINT     Y 9194
	LONGLONG llBid6Vol;       //申买量6  BID6_VOL       BIGINT     X 9195
	LONGLONG llBid7Vol;       //申买量7  BID7_VOL       BIGINT     X 9196
	LONGLONG llBid8Vol;       //申买量8  BID8_VOL       BIGINT     X 9197
	LONGLONG llBid9Vol;       //申买量9  BID9_VOL       BIGINT     X 9198
	LONGLONG llBid10Vol;       //申买量10 BID10_VOL      BIGINT     X 9199
	int      iMatchedCnt;    //成交笔数  MATCHED_CNT    SMALLINT   Y 561 
	LONGLONG llMatchedVol;   //成交总量  MATCHED_VOL    BIGINT     Y 387 
	LONGLONG llMatchedAmtTot;//成交总金额 MATCHED_AMT_TOTBIGINT     Y 8504
	LONGLONG llBidVolTot;    //买入总量  BID_VOL_TOT    BIGINT     Y 38  
	LONGLONG llAnsVolTot;    //卖出总量  ANS_VOL_TOT    BIGINT     Y 8980
	LONGLONG llBidPriceAvg;  //平均委买价格BID_PRICE_AVG  BIGINT     Y 8981
	LONGLONG llAnsPriceAvg;  //平均委卖价格ANS_PRICE_AVG  BIGINT     Y 8982
	LONGLONG llIopv;         //IOPV  IOPV           BIGINT     Y 8967
	LONGLONG llYield;        //到期收益率 YIELD          BIGINT     Y 8985
	LONGLONG llHighLmtPrice; //涨停价   HIGH_LMT_PRICE BIGINT     Y 8519
	LONGLONG llLowLmtPrice;  //跌停价   LOW_LMT_PRICE  BIGINT     Y 8520
	char     szStkPrefix[32+1];//证券前缀  STK_PREFIX     VARCHAR(32)Y 8988
	LONGLONG llPreOpenVol;   //昨持仓量  PRE_OPEN_VOL   BIGINT     Y 8989
	LONGLONG llSettPrice;    //今结算价  SETT_PRICE     BIGINT     Y 8841
	LONGLONG llPreDelta;     //昨虚实度  PRE_DELTA      BIGINT     Y 8990
	LONGLONG llCurrDelta;    //今虚实度  CURR_DELTA     BIGINT     Y 8991
	int      iNsyl1;          //市盈率1  NSYL1          SMALLINT   Y 9200
	int      iNsyl2;          //市盈率2  NSYL2          SMALLINT   Y 9201
	int      iNsd;           //升跌2   NSD2           SMALLINT   Y 9203
	LONGLONG llOpenVol;      //持仓总量  OPEN_VOL       BIGINT     Y 9204
	LONGLONG llPreSettPrice; //昨结算价  PRE_SETT_PRICE BIGINT     Y 9205
	LONGLONG llClosePrice;   //今收盘   CLOSE_PRICE    BIGINT     Y 9206
};

struct MATRADEAPI CRspCosSnapshotField
{
};

//行情回放功能
struct MATRADEAPI CReqCosReplayField
{
	char     chPlayCtrl;    //播放控制  PLAY_CTRL     CHAR(1)     Y 9080‘0’—停止播放 ‘1’—开始播放
	int      iTrdDate;      //行情日期  TRD_DATE      INTEGER     X 8844默认当前日期
	int      iBgnTime;      //开始时间  BGN_TIME      INTEGER     X 916 不设置默认从文件开头开始
	int      iEndTime;      //结束时间  END_TIME      INTEGER     X 917 不设置默认读到文件结束
	char     chPlayBackType;//回放类型  PLAY_BACK_TYPECHAR(1)     X 8996‘0’- 按时间间隔回放（其他值保留）
	int      iPlayInterval; //回放时间间隔PLAY_INTERVAL INTEGER     X 9081播放单位行情时间后的间隔时间(PLAY_INTERVAL以毫秒为单位)
	char     szStkCode[128+1];//股票代码  STK_CODE      VARCHAR(128)X 48  播放行情代码用逗号（，）分割，如000001,000002,000003….
};

struct MATRADEAPI CRspCosReplayField
{
};
//深度行情查询委托
struct MATRADEAPI CReqCosMktDataInfoField
{
	char     chExchange; //交易所 EXCHANGE  CHAR(1)    X 207  
	char     szTrdCode[8+1];//品种代码TRD_CODE  VARCHAR(8) X 48   
	char     chQueryFlag;//查询方向QUERY_FLAGCHAR(1)    X 90800:向后取数据1:向前取数据其他全部返回
	char     szQueryPos[32+1];//定位串 QUERY_POS VARCHAR(32)X 8991 与查询方向和资产账户配合使用
	int      iQueryNum;  //查询行数QUERY_NUM INTEGER    X 8992 最大值为100
};

struct MATRADEAPI CRspCosMktDataInfoField
{
	char     chExchange;         //交易所   EXCHANGE       CHAR(1)    207 
	char     szTrdCode[16+1];   //品种代码  TRD_CODE       VARCHAR(16)48  
	int      iTrdDate;           //行情日期  TRD_DATE       INTEGER    8844
	LONGLONG llDataTime;         //行情时间  DATA_TIME      BIGINT     8816
	char     chStatus;           //品种状态  STATUS         CHAR(1)    326 
	LONGLONG llPreClosePrice;    //昨收盘价  PRE_CLOSE_PRICEBIGINT     140 
	LONGLONG llOpenPrice;        //开盘价   OPEN_PRICE     BIGINT     8957
	LONGLONG llHighPrice;        //最高价   HIGH_PRICE     BIGINT     8983
	LONGLONG llLowPrice;         //最低价   LOW_PRICE      BIGINT     8984
	LONGLONG llCurPrice;         //最新价   CUR_PRICE      BIGINT     8958
	LONGLONG llAns1Price;        //申卖价1  ANS1_PRICE     BIGINT     9080
	LONGLONG llAns2Price;        //申卖价2  ANS2_PRICE     BIGINT     9081
	LONGLONG llAns3Price;        //申卖价3  ANS3_PRICE     BIGINT     9082
	LONGLONG llAns4Price;        //申卖价4  ANS4_PRICE     BIGINT     9083
	LONGLONG llAns5Price;        //申卖价5  ANS5_PRICE     BIGINT     9084
	LONGLONG llAns6Price;        //申卖价6  ANS6_PRICE     BIGINT     9085
	LONGLONG llAns7Price;        //申卖价7  ANS7_PRICE     BIGINT     9086
	LONGLONG llAns8Price;        //申卖价8  ANS8_PRICE     BIGINT     9087
	LONGLONG llAns9Price;        //申卖价9  ANS9_PRICE     BIGINT     9088
	LONGLONG llAns10Price;       //申卖价10 ANS10_PRICE    BIGINT     9089
	LONGLONG llAns1Vol;          //申卖量1  ANS1_VOL       BIGINT     9090
	LONGLONG llAns2Vol;          //申卖量2  ANS2_VOL       BIGINT     9091
	LONGLONG llAns3Vol;          //申卖量3  ANS3_VOL       BIGINT     9092
	LONGLONG llAns4Vol;          //申卖量4  ANS4_VOL       BIGINT     9093
	LONGLONG llAns5Vol;          //申卖量5  ANS5_VOL       BIGINT     9094
	LONGLONG llAns6Vol;          //申卖量6  ANS6_VOL       BIGINT     9095
	LONGLONG llAns7Vol;          //申卖量7  ANS7_VOL       BIGINT     9096
	LONGLONG llAns8Vol;          //申卖量8  ANS8_VOL       BIGINT     9097
	LONGLONG llAns9Vol;          //申卖量9  ANS9_VOL       BIGINT     9098
	LONGLONG llAns10Vol;         //申卖量10 ANS10_VOL      BIGINT     9099
	LONGLONG llBid1Price;        //申买价1  BID1_PRICE     BIGINT     9180
	LONGLONG llBid2Price;        //申买价2  BID2_PRICE     BIGINT     9181
	LONGLONG llBid3Price;        //申买价3  BID3_PRICE     BIGINT     9182
	LONGLONG llBid4Price;        //申买价4  BID4_PRICE     BIGINT     9183
	LONGLONG llBid5Price;        //申买价5  BID5_PRICE     BIGINT     9184
	LONGLONG llBid6Price;        //申买价6  BID6_PRICE     BIGINT     9185
	LONGLONG llBid7Price;        //申买价7  BID7_PRICE     BIGINT     9186
	LONGLONG llBid8Price;        //申买价8  BID8_PRICE     BIGINT     9187
	LONGLONG llBid9Price;        //申买价9  BID9_PRICE     BIGINT     9188
	LONGLONG llBid10Price;       //申买价10 BID10_PRICE    BIGINT     9189
	LONGLONG llBid1Vol;          //申买量1  BID1_VOL       BIGINT     9190
	LONGLONG llBid2Vol;          //申买量2  BID2_VOL       BIGINT     9191
	LONGLONG llBid3Vol;          //申买量3  BID3_VOL       BIGINT     9192
	LONGLONG llBid4Vol;          //申买量4  BID4_VOL       BIGINT     9193
	LONGLONG llBid5Vol;          //申买量5  BID5_VOL       BIGINT     9194
	LONGLONG llBid6Vol;          //申买量6  BID6_VOL       BIGINT     9195
	LONGLONG llBid7Vol;          //申买量7  BID7_VOL       BIGINT     9196
	LONGLONG llBid8Vol;          //申买量8  BID8_VOL       BIGINT     9197
	LONGLONG llBid9Vol;          //申买量9  BID9_VOL       BIGINT     9198
	LONGLONG llBid10Vol;         //申买量10 BID10_VOL      BIGINT     9199
	int      iMatchedCnt;        //成交笔数  MATCHED_CNT    SMALLINT   561 
	LONGLONG llMatchedVol;       //成交总量  MATCHED_VOL    BIGINT     387 
	LONGLONG llMatchedAmtTot;    //成交总金额 MATCHED_AMT_TOTBIGINT     8504
	LONGLONG llBidVolTot;        //买入总量  BID_VOL_TOT    BIGINT     38  
	LONGLONG llAnsVolTot;        //卖出总量  ANS_VOL_TOT    BIGINT     8980
	LONGLONG llBidPriceAvg;      //平均委买价格BID_PRICE_AVG  BIGINT     8981
	LONGLONG llAnsPriceAvg;      //平均委卖价格ANS_PRICE_AVG  BIGINT     8982
	LONGLONG llIopv;             //IOPV  IOPV           BIGINT     8967
	LONGLONG llYield;            //到期收益率 YIELD          BIGINT     8985
	LONGLONG llHighLmtPrice;     //涨停价   HIGH_LMT_PRICE BIGINT     8519
	LONGLONG llLowLmtPrice;      //跌停价   LOW_LMT_PRICE  BIGINT     8520
	char     szStkPrefix[32+1]; //证券前缀  STK_PREFIX     VARCHAR(32)8988
	LONGLONG llPreOpenVol;       //昨持仓量  PRE_OPEN_VOL   BIGINT     8989
	LONGLONG llSettPrice;        //今结算价  SETT_PRICE     BIGINT     8841
	LONGLONG llPreDelta;         //昨虚实度  PRE_DELTA      BIGINT     8990
	LONGLONG llCurrDelta;        //今虚实度  CURR_DELTA     BIGINT     8991
	int      iNsyl1;              //市盈率1  NSYL1          SMALLINT   9200
	int      iNsyl2;              //市盈率2  NSYL2          SMALLINT   9201
	int      iNsd;               //升跌2   NSD2           SMALLINT   9203
	LONGLONG llOpenVol;          //持仓总量  OPEN_VOL       BIGINT     9204
	LONGLONG llPreSettPrice;     //昨结算价  PRE_SETT_PRICE BIGINT     9205
	LONGLONG llClosePrice;       //今收盘   CLOSE_PRICE    BIGINT     9206
};
//行情记录功能
struct MATRADEAPI CReqCosRecordMktDataField
{
	char     chRecCtrl;//记录控制REC_CTRLCHAR(1)     Y 9080‘0’-停止记录， ‘1’- 开始记录
	int      iTrdDate; //行情日期TRD_DATEINTEGER     X 8844默认当前交易日
	int      iBgnTime; //开始时间BGN_TIMEINTEGER     X 916 默认当前时间
	int      iEndTime; //结束时间END_TIMEINTEGER     X 917 默认交易日结束
	char     szStkCode[128+1];//股票代码STK_CODEVARCHAR(128)X 48  记录行情代码用逗号（，）分割，如000001,000002,000003….
};

struct MATRADEAPI CRspCosRecordMktDataField
{
};
struct MATRADEAPI CReqCosReplayInfoField
{
	LONGLONG llTrdDate;//行情日期TRD_DATEBIGINTX 8844默认当前交易日
};

struct MATRADEAPI CRspCosReplayInfoField
{
	char     chPlayStatus;     //回放状态  PLAY_STATUS  CHAR(1)9080‘0’未开始 ‘1’进行中‘2’已完成‘3’已取消
	LONGLONG llMktTotalNum;    //行情总数  MKT_TOTAL_NUMBIGINT 9081
	LONGLONG llMktCurNum;      //已播数   MKT_CUR_NUM  BIGINT 9082
	int      iMktCurTime;      //当前行情时间MKT_CUR_TIME INTEGER9083
};
//历史行情查询委托
struct MATRADEAPI CReqCosHisMktDataField
{
	char     chExchange;   //交易所   EXCHANGE     CHAR(1)   Y 207 
	char     szTrdCode[8+1];//品种代码  TRD_CODE     VARCHAR(8)Y 48  
	int      iTrdDate;     //行情日期  TRD_DATE     INTEGER   X 8844默认为当天
	LONGLONG llDataBegTime;//行情开始时间DATA_BEG_TIMEBIGINT    X 8816
	LONGLONG llDataEndTime;//行情结束时间DATA_END_TIMEBIGINT    X 8817
};

struct MATRADEAPI CRspCosHisMktDataField
{
	char     chExchange;    //交易所 EXCHANGE CHAR(1)    207 
	char     szTrdCode[16+1];//品种代码TRD_CODE VARCHAR(16)48  
	int      iTrdDate;      //行情日期TRD_DATE INTEGER    8844
	LONGLONG llDataTime;    //行情时间DATA_TIMEBIGINT     8816
	LONGLONG llCurPrice;    //最新价 CUR_PRICEBIGINT     8958
};

//数据同步
struct MATRADEAPI CReqCosSyncField
{
	int      iItfCfgSn;    //接口配置序号ITF_CFG_SN   INTEGERY 9023接口配置序号
	char     chItfDataType;//接口数据类型ITF_DATA_TYPECHAR(1)Y 9028接口数据类型
	char     chItfDataFlow;//接口数据流向ITF_DATA_FLOWCHAR(1)Y 9029接口数据流向
};

struct MATRADEAPI CRspCosSyncField
{
};
//资产账户开户
struct MATRADEAPI CReqCosOpenAccountField
{
	char     szCustCode[16+1];  //客户代码 CUST_CODE  BIGINT  Y 8902
  char     szCuacctCode[16+1];//资产账户 CUACCT_CODEBIGINT  Y 8920
	int      iSubsys;     //子系统  SUBSYS     SMALLINTY 9080
	int      iSubsysSn;   //子系统编号SUBSYS_SN  SMALLINTY 8988
};

struct MATRADEAPI CRspCosOpenAccountField
{
	char     szCuacctCode[16+1];    //资产账户 CUACCT_CODEBIGINT  8920
	int      iNodeIdNow;      //服务器编号NODE_ID_NOWINTEGER 9082
	int      iSubsysSn;       //子系统编号SUBSYS_SN  SMALLINT8988
};

//资产账户销户
struct MATRADEAPI CReqCosCloseAccountField
{
  char     szCuacctCode[16+1];//资产账户CUACCT_CODEBIGINTY 8920
};

struct MATRADEAPI CRspCosCloseAccountField
{
	char     szCuacctCode[16+1];    //资产账户 CUACCT_CODEBIGINT 8920
	int      iNodeIdNow;      //现节点编号NODE_ID_NOWINTEGER9082
};

//资金同步
struct MATRADEAPI CReqCosFundSyncField
{
};

struct MATRADEAPI CRspCosFundSyncField
{
	char     chTaskStatus;     //执行状态TASK_STATUS  CHAR(1)     9000
	int      iTaskSchedule;    //执行进度TASK_SCHEDULEINTEGER     9001
	int      iErrorId;         //错误代码ERROR_ID     SMALLINT    8900
	char     szErrorMsg[256+1];//错误信息ERROR_MSG    VARCHAR(256)8901
};
//股份同步
struct MATRADEAPI CReqCosStkSyncField
{
};

struct MATRADEAPI CRspCosStkSyncField
{
	char     chTaskStatus;     //执行状态TASK_STATUS  CHAR(1)     9000
	int      iTaskSchedule;    //执行进度TASK_SCHEDULEINTEGER     9001
	int      iErrorId;         //错误代码ERROR_ID     SMALLINT    8900
	char     szErrorMsg[256+1];//错误信息ERROR_MSG    VARCHAR(256)8901
};
//交易日切
struct MATRADEAPI CReqCosCutoffField
{
	int      iTrdDate;//交易日期TRD_DATEINTEGERY 8844
};

struct MATRADEAPI CRspCosCutoffField
{
	char     chTaskStatus;     //执行状态TASK_STATUS  CHAR(1)     9000
	int      iTaskSchedule;    //执行进度TASK_SCHEDULEINTEGER     9001
	int      iErrorId;         //错误代码ERROR_ID     SMALLINT    8900
	char     szErrorMsg[256+1];//错误信息ERROR_MSG    VARCHAR(256)8901
};

//成交回报
//成交信息包括四类: 
//  1.正常委托的成交信息
// 	2.撤单所产生的成交信息（委托已申报至交易所）
// 	3.内部撤单的成交信息（委托未申报至交易所）
// 	4.非法委托的撤单成交信息（委托被交易所拒绝）
struct MATRADEAPI CRtnOrderField
{
  char            szMatchedSn[16 + 1];        // 成交编号 
  char            chStkex;                    // 交易市场 字典[STKEX]
  char            szStkCode[8 + 1];           // 证券代码 
  char            szOrderId[10 + 1];          // 合同序号 
  char            szTrdacct[16 + 1];          // 交易账户 
  LONGLONG        llMatchedQty;               // 本次成交数量 撤单成交时数为负数
  char            szMatchedPrice[21 + 1];     // 本次成交价格 港股委托返回港币
  char            szOrderFrzAmt[21 + 1];      // 委托冻结金额 港股委托返回港币
  char            szRltSettAmt[21 + 1];       // 实时清算金额 港股委托返回港币
  char            szFundAvl[21 + 1];          // 资金可用金额 一级台账可用
  LONGLONG        llStkAvl;                   // 证券可用数量 
  char            szOpptStkpbu[8 + 1];        // 对方席位 
  char            szOpptTrdacct[10 + 1];      // 对方交易账号 
  int             iMatchedDate;               // 成交日期 
  char            szMatchedTime[8 + 1];       // 成交时间 
  char            chIsWithdraw;               // 撤单标志 字典[IS_WITHDRAW]
  char            szCustCode[16 + 1];         // 客户代码 
  char            szCuacctCode[16 + 1];       // 资产账户 
  int             iOrderBsn;                  // 委托批号 
  int             iCuacctSn;                  // 账户序号 
  char            szStkbd[2 + 1];             // 交易板块 字典[STKBD]
  char            chMatchedType;              // 成交类型 ‘0’:内部撤单成交 ‘1’:非法委托撤单成交 ‘2’:交易所成交（含主动撤单成交与撮合委托成交）
  char            chOrderStatus;              // 委托状态 字典[ORDER_STATUS] 本次成交后委托的状态
  int             iStkBiz;                    // 证券业务 
  int             iStkBizAction;              // 证券业务行为 
  char            szOfferRetMsg[64 + 1];      // 申报信息 交易所废单时返回废单原因
  LONGLONG        llOrderQty;                 // 委托数量 
  LONGLONG        llWithdrawnQty;             // 已撤单数量 为正数
  LONGLONG        llTotalMatchedQty;          // 累计成交数量 
  char            chCuacctAttr;               // 账户属性 现货专有字段
  char            szTotalMatchedAmt[21 + 1];  // 累计成交金额 现货专有字段 港股委托返回港币
  LONGLONG        llStkQty;                   // 拥股数 现货专有字段
  char            szMatchedAmt[21 + 1];       // 已成交金额 港股委托返回港币
  char            szHFundAvl[21 + 1];         // 港股资金可用 二级台账可用(KFOS1.2.3.5及以上版本支持)
  int             iOrderDate;                 // 委托日期 期权专有字段
  int             iOrderSn;                   // 委托序号 期权专有字段
  int             iIntOrg;                    // 内部机构 期权专有字段
  char            szStkpbu[8 + 1];            // 交易单元 期权专有字段
  char            szSubacctCode[8 + 1];       // 证券账户子编码 期权专有字段
  char            szOptTrdacct[18 + 1];       // 期权合约账户 期权专有字段
  char            szOwnerType[3 + 1];         // 订单所有类型 期权专有字段
  char            szOptCode[32 + 1];          // 合约代码 期权专有字段
  char            szOptName[32 + 1];          // 合约简称 期权专有字段
  char            chCurrency;                 // 货币代码 期权专有字段
  char            chOptUndlCls;               // 标的证券类别 期权专有字段
  char            szOptUndlCode[8 + 1];       // 标的证券代码 期权专有字段
  char            szOptUndlName[16 + 1];      // 标的证券名称 期权专有字段
  char            szOrderPrice[21 + 1];       // 委托价格 期权专有字段
  char            szOrderAmt[21 + 1];         // 委托金额 期权专有字段
  char            szMarginPreFrz[21 + 1];     // 预占用保证金 期权专有字段（卖开委托时填写预冻结的保证金金额，其他情况填“0”）
  char            szMarginFrz[21 + 1];        // 占用保证金 期权专有字段（卖开成交时填写实际冻结的保证金金额，其他情况填“0”）
  char            szMarginPreUfz[21 + 1];     // 预释放保证金 期权专有字段（买平委托时填写预解冻的保证金金额，其他情况填“0”）
  char            szMarginUfz[21 + 1];        // 释放保证金 期权专有字段（买平成交时填写实际解冻的保证金金额，其他情况填“0”）
  char            szCombNum[16 + 1];          // 组合编码 期权专有字段（构建组合、解除组合时填写，其他情况填空）
  char            szCombStraCode[16 + 1];     // 组合策略代码 期权专有字段（构建组合、解除组合时填写，其他情况填空）
  char            szLeg1Num[16 + 1];          // 成分一合约编码 期权专有字段（构建组合、解除组合、行权指令合并申报时填写，其他情况填空）
  char            szLeg2Num[16 + 1];          // 成分二合约编码 期权专有字段（构建组合、解除组合、行权指令合并申报时填写，其他情况填空）
  char            szLeg3Num[16 + 1];          // 成分三合约编码 期权专有字段（构建组合、解除组合时填写，其他情况填空）
  char            szLeg4Num[16 + 1];          // 成分四合约编码 期权专有字段（构建组合、解除组合时填写，其他情况填空）
  char            szOptBcostRltPrice[21 + 1]; // 实时成本价 期权专有字段
  int             iTrdCodeCls;                // 品种类型 复杂订单专有字段
  int             iOrderNo;                   // 委托编号 复杂订单专有字段
  int             iErrorId;                   // 错误代码 复杂订单专有字段
  char            szErrorMsg[81 + 1];         // 错误信息 复杂订单专有字段
  char            szBrokerId[11 + 1];         // 经纪公司代码 复杂订单专有字段
  char            szInstrumentId[31 + 1];     // 合约代码 复杂订单专有字段
  char            szOrderRef[13 + 1];         // 报单引用 复杂订单专有字段
  char            szUserId[16 + 1];           // 用户代码 复杂订单专有字段
  char            szExchangeId[9 + 1];        // 交易所代码 复杂订单专有字段
  char            szOrderSysId[21 + 1];       // 报单编号 复杂订单专有字段
  char            szCombOffsetFlag[5 + 1];    // 组合开平标志 复杂订单专有字段
  char            szCombHedgeFlag[5 + 1];     // 组合投机套保标志 复杂订单专有字段
  char            szOrderLocalId[13 + 1];     // 本地报单编号 复杂订单专有字段
  int             iSequenceNo;                // 序号 复杂订单专有字段
  char            szCliOrderNo[32 + 1];       // 客户端委托编号 复杂订单专有字段
  int             iAttrCode;                  // 属性代码 复杂订单专有字段
  char            chCuacctType;               // 账户类型 复杂订单专有字段
  char            szStkName[16 + 1];          // 证券名称 复杂订单专有字段
  char            chStrategyType;             // 策略类型 复杂订单专有字段
  char            szStrategyName[32 + 1];     // 策略名称 复杂订单专有字段
  int             iOrderGroupNo;              // 组合单编号 复杂订单专有字段
  int             iSubOrderSn;                // 子单编号 复杂订单专有字段
  int             iMainTrdDate;               // 母单交易日期 复杂订单专有字段
  int             iTrdDate;                   // 交易日期 复杂订单专有字段
  char            szOrderTime[32 + 1];        // 委托时间 复杂订单专有字段
  char            szOrderAttr[256 + 1];       // 高级属性 复杂订单专有字段
  char            szTrdExInfo[512 + 1];       // 交易扩展信息 复杂订单专有字段
  char            chUpdownCtrl;               // 涨停不卖跌停不买标志 复杂订单专有字段
  char            szStopPrice[21 + 1];        // 止损价 复杂订单专有字段
  char            szTrackMatchPrice[21 + 1];  // 动态触发价 复杂订单专有字段
  LONGLONG        llExeBuyQty;                // 买执行申报数量 复杂订单专有字段
  LONGLONG        llExeSellQty;               // 卖执行申报数量 复杂订单专有字段
  LONGLONG        llMatchBuyQty;              // 买成交数量 复杂订单专有字段
  LONGLONG        llMatchSellQty;             // 卖成交数量 复杂订单专有字段
  char            szMatchBuyAmt[21 + 1];      // 买成交金额 复杂订单专有字段
  char            szMatchSellAmt[21 + 1];     // 卖成交金额 复杂订单专有字段
  char            szMatchBuyAvgPrice[21 + 1]; // 买成交均价 复杂订单专有字段
  char            szMatchSellAvgPrice[21 + 1];// 卖成交均价 复杂订单专有字段
  LONGLONG        llWithdrawnBuyQty;          // 买撤单数量 复杂订单专有字段
  LONGLONG        llWithdrawnSellQty;         // 卖撤单数量 复杂订单专有字段
  int             iExeBuyCnt;                 // 买执行次数 复杂订单专有字段
  int             iExeSellCnt;                // 卖执行次数 复杂订单专有字段
  char            szExeInfo[256 + 1];         // 执行信息 复杂订单专有字段
  char            chChannel;                  // 操作渠道 复杂订单专有字段
  char            szCliRemark[256 + 1];       // 留痕信息 复杂订单专有字段
  char            szCliDefine1[32 + 1];       // 客户自定义1 复杂订单专有字段
  char            szCliDefine2[32 + 1];       // 客户自定义2 复杂订单专有字段
  char            szCliDefine3[32 + 1];       // 客户自定义3 复杂订单专有字段
  char            szRemark1[32 + 1];          // 预留字段1 期权专有字段
  char            szRemark2[32 + 1];          // 预留字段2 
  char            szRemark3[32 + 1];          // 预留字段3 
  char            szRemark4[32 + 1];          // 预留字段4 
  char            szRemark5[32 + 1];          // 预留字段5 
  char            szRemark6[32 + 1];          // 预留字段6 复杂订单专有字段
  char            szRemark7[32 + 1];          // 预留字段7 复杂订单专有字段
  char            szRemark8[32 + 1];          // 预留字段8 复杂订单专有字段
  char            szRemark9[32 + 1];          // 预留字段9 复杂订单专有字段
  char            szRemarka[32 + 1];          // 预留字段A 复杂订单专有字段
};

//量化委托确认回报
struct MATRADEAPI CRtnTsuOrderField
{
  int             iOrderBsn;                  // 委托批号 
  char            szOrderId[10 + 1];          // 合同序号 
  char            szCuacctCode[16 + 1];       // 资产账户 
  char            szOrderPrice[21 + 1];       // 委托价格 
  LONGLONG        llOrderQty;                 // 委托数量 
  char            szOrderAmt[21 + 1];         // 委托金额 
  char            szOrderFrzAmt[21 + 1];      // 冻结金额 
  char            szStkpbu[8 + 1];            // 交易单元 
  char            szStkbd[2 + 1];             // 交易板块 
  char            szStkCode[8 + 1];           // 证券代码 
  char            szStkName[16 + 1];          // 证券名称 
  int             iStkBiz;                    // 证券业务 
  int             iStkBizAction;              // 业务行为 
  int             iCuacctSn;                  // 账户序号 
  int             iOrderNo;                   // 委托编号 
  int             iOrderDate;                 // 委托日期 
  char            szOrderTime[32 + 1];        // 委托时间 
  char            szTrdacct[16 + 1];          // 交易账户 
  char            szOptNum[16 + 1];           // 合约编码 
  char            szOptCode[32 + 1];          // 合约代码 
  char            szOptName[32 + 1];          // 合约简称 
  char            szOptUndlCode[8 + 1];       // 标的证券代码 
  char            chExeStatus;                // 执行状态 
  int             iFrontId;                   // 前置编号 
  LONGLONG        llSessionId;                // 会话编号 
  int             iErrorId;                   // 错误代码 
  char            szErrorMsg[256 + 1];        // 错误信息 
  int             iOrderChange;               // 改单标识 
  char            szCliOrderNo[32 + 1];       // 客户端委托编号 
  char            chCuacctType;               // 账户类型 
  int             iAttrCode;                  // 属性代码 
  char            szTriggerPrice[21 + 1];     // 触发价格 
  char            szCustCode[16 + 1];         // 客户代码 
  int             iOrderGroupNo;              // 组合单编号 
  int             iSubOrderSn;                // 子单编号 
  int             iTrdDate;                   // 交易日期 
  int             iMainTrdDate;               // 母单交易日 
  char            szOrderAttr[256 + 1];       // 高级属性 
  char            szTrdExInfo[512 + 1];       // 交易执行信息 
  char            chUpdownCtrl;               // 涨停不卖跌停不买标志 
  char            chStkex;                    // 交易市场 
  char            chTrdCodeCls;               // 证券代码类型 
  char            szStopPrice[21 + 1];        // 止损价 
  char            szTrackMatchPrice[21 + 1];  // 动态触发价 
  int             iIntOrg;                    // 内部机构 
  char            szExeInfo[256 + 1];         // 执行信息 
  char            chOnoffFlag;                // 启停标志 
  char            chChannel;                  // 操作渠道 
  char            chStrategyType;             // 策略类型 
  char            szStrategyName[32 + 1];     // 策略名称 
  char            szCliRemark[256 + 1];       // 留痕信息 
  char            szCliDefine1[32 + 1];       // 客户自定义1 
  char            szCliDefine2[32 + 1];       // 客户自定义2 
  char            szCliDefine3[32 + 1];       // 客户自定义3 
  char            szRemark1[32 + 1];          // 预留字段1 期权专有字段
  char            szRemark2[32 + 1];          // 预留字段2 
  char            szRemark3[32 + 1];          // 预留字段3 
  char            szRemark4[32 + 1];          // 预留字段4 
  char            szRemark5[32 + 1];          // 预留字段5 
  char            szRemark6[32 + 1];          // 预留字段6 复杂订单专有字段
  char            szRemark7[32 + 1];          // 预留字段7 复杂订单专有字段
  char            szRemark8[32 + 1];          // 预留字段8 复杂订单专有字段
  char            szRemark9[32 + 1];          // 预留字段9 复杂订单专有字段
  char            szRemarka[32 + 1];          // 预留字段A 复杂订单专有字段
};

////////////////////////////////////////////////////////////////////////////////////////////////
//内部接口功能
//成交回报数据
struct MATRADEAPI CReqCosMatchReportField
{
	int      iTrdCodeCls;     //品种类型    TRD_CODE_CLS    INTEGER    X 8970
	char     szMatchedSn[16+1];//成交编号    MATCHED_SN      VARCHAR(16)X 17  
	char     chStkex;         //交易市场    STKEX           CHAR(1)    X 207 字典[STKEX]
	char     szStkCode[8+1]; //证券代码    STK_CODE        VARCHAR(8) X 48  
	int      iOrderNo;        //委托编号    ORDER_NO        INTEGER    X 9106
	char     szOrderId[10+1];//合同序号    ORDER_ID        VARCHAR(10)X 11  
	char     szTrdacct[16+1];//交易账户    TRDACCT         VARCHAR(16)X 448 
	LONGLONG llMatchedQty;    //成交数量    MATCHED_QTY     BIGINT     X 387 撤单成交时数为负数
	char     szMatchedPrice[21+1];//成交价格    MATCHED_PRICE   CPRICE     X 8841
	char     szOrderFrzAmt[21+1];//委托冻结金额  ORDER_FRZ_AMT   CMONEY     X 8831
	char     szRltSettAmt[21+1];//实时清算金额  RLT_SETT_AMT    CMONEY     X 8853
	char     szFundAvl[21+1]; //资金可用金额  FUND_AVL        CMONEY     X 8861
	LONGLONG llStkAvl;        //证券可用数量  STK_AVL         BIGINT     X 8869
	char     szOpptStkpbu[8+1];//对方席位    OPPT_STKPBU     VARCHAR(8) X 9107
	char     szOpptTrdacct[10+1];//对方交易账号  OPPT_TRDACCT    VARCHAR(10)X 9108
	int      iMatchedDate;    //成交日期    MATCHED_DATE    INTEGER    X 8839
	char     szMatchedTime[8+1];//成交时间    MATCHED_TIME    VARCHAR(8) X 8840
	char     chIsWithdraw;    //撤单标志    IS_WITHDRAW     CHAR(1)    X 8836字典[IS_WITHDRAW]
	char     szCustCode[16+1]; //客户代码    CUST_CODE       BIGINT     X 8902
  char     szCuacctCode[16+1];    //资产账户    CUACCT_CODE     BIGINT     X 8920
	int      iOrderBsn;       //委托批号    ORDER_BSN       INTEGER    X 66  
	int      iCuacctSn;       //账户序号    CUACCT_SN       SMALLINT   X 8928
	char     szStkbd[2+1];   //交易板块    STKBD           CHAR(2)    X 625 字典[STKBD]
	char     chMatchedType;   //成交类型    MATCHED_TYPE    CHAR(1)    X 9080‘0’:内部撤单成交‘1’:非法委托撤单成交‘2’:交易所成交（含主动撤单成交与撮合委托成交）
	char     chOrderStatus;   //委托状态    ORDER_STATUS    CHAR(1)    X 39  字典[ORDER_STATUS]
	int      iStkBiz;         //证券业务    STK_BIZ         SMALLINT   X 8842
	int      iStkBizAction;   //证券业务行为  STK_BIZ_ACTION  SMALLINT   X 40  
	int      iOrderDate;      //委托日期    ORDER_DATE      INTEGER    X 8834期权专有字段—>共用
	int      iOrderSn;        //委托序号    ORDER_SN        INTEGER    X 8832期权专有字段
	int      iIntOrg;         //内部机构    INT_ORG         SMALLINT   X 8911期权专有字段
	char     szStkpbu[8+1];  //交易单元    STKPBU          VARCHAR(8) X 8843期权专有字段
	char     szSubacctCode[8+1];//证券账户子编码 SUBACCT_CODE    VARCHAR(8) X 9099期权专有字段
	char     szOptTrdacct[18+1];//期权合约账户  OPT_TRDACCT     VARCHAR(18)X 9098期权专有字段
	char     szOwnerType[3+1];//订单所有类型  OWNER_TYPE      CHAR(3)    X 9091期权专有字段
	char     szOptCode[32+1];//合约代码    OPT_CODE        VARCHAR(32)X 9083期权专有字段
	char     szOptName[32+1];//合约简称    OPT_NAME        VARCHAR(32)X 9084期权专有字段
	char     chCurrency;      //货币代码    CURRENCY        CHAR(1)    X 15  期权专有字段
	char     chOptUndlCls;    //标的证券类别  OPT_UNDL_CLS    CHAR(1)    X 9085期权专有字段
	char     szOptUndlCode[8+1];//标的证券代码  OPT_UNDL_CODE   VARCHAR(8) X 9086期权专有字段
	char     szOptUndlName[16+1];//标的证券名称  OPT_UNDL_NAME   VARCHAR(16)X 9087期权专有字段
	char     szOrderPrice[21+1];//委托价格    ORDER_PRICE     CPRICE4    X 44  期权专有字段
	LONGLONG llOrderQty;      //委托数量    ORDER_QTY       BIGINT     X 38  期权专有字段
	char     szOrderAmt[21+1];//委托金额    ORDER_AMT       CMONEY     X 8830期权专有字段
	char     szMatchedAmt[21+1];//已成交金额   MATCHED_AMT     CMONEY     X 8504期权专有字段
	char     szMarginPreFrz[21+1];//预占用保证金  MARGIN_PRE_FRZ  CMONEY     X 9094期权专有字段（卖开委托时填写预冻结的保证金金额，其他情况填“0”）
	char     szMarginFrz[21+1];//占用保证金   MARGIN_FRZ      CMONEY     X 9095期权专有字段（卖开成交时填写实际冻结的保证金金额，其他情况填“0”）
	char     szMarginPreUfz[21+1];//预释放保证金  MARGIN_PRE_UFZ  CMONEY     X 9096期权专有字段（买平委托时填写预解冻的保证金金额，其他情况填“0”）
	char     szMarginUfz[21+1];//释放保证金   MARGIN_UFZ      CMONEY     X 9097期权专有字段（买平成交时填写实际解冻的保证金金额，其他情况填“0”）
	int      iErrorId;        //错误代码    ERROR_ID        SMALLINT   X 8900期货专有字段
	char     szErrorMsg[81+1];//错误信息    ERROR_MSG       VARCHAR(81)X 8901期货专有字段
	char     szBrokerId[11+1];//经纪公司代码  BROKER_ID       VARCHAR(11)X 8890期货专有字段
	char     szInstrumentId[31+1];//合约代码    INSTRUMENT_ID   VARCHAR(31)X 48  期货专有字段
	char     szOrderRef[13+1];//报单引用    ORDER_REF       VARCHAR(13)X 8738期货专有字段
	char     szUserId[16+1]; //用户代码    USER_ID         VARCHAR(16)X 9080期货专有字段
	char     szExchangeId[9+1];//交易所代码   EXCHANGE_ID     VARCHAR(9) X 207 期货专有字段
	char     szOrderSysId[21+1];//报单编号    ORDER_SYS_ID    VARCHAR(21)X 8745期货专有字段
	char     szCombOffsetFlag[5+1];//组合开平标志  COMB_OFFSET_FLAGVARCHAR(5) X 8741期货专有字段
	char     szCombHedgeFlag[5+1];//组合投机套保标志COMB_HEDGE_FLAG VARCHAR(5) X 8742期货专有字段
	char     szOrderLocalId[13+1];//本地报单编号  ORDER_LOCAL_ID  VARCHAR(13)X 8722期货专有字段
	int      iSequenceNo;     //序号      SEQUENCE_NO     SMALLINT   X 8832期货专有字段
	char     szCliOrderNo[32+1];//客户端委托编号 CLI_ORDER_NO    VARCHAR(32)X 9102客户端委托编号
};

struct MATRADEAPI CRspCosMatchReportField
{
	int      iTrdCodeCls;         //品种类型    TRD_CODE_CLS    INTEGER    8970
	char     szMatchedSn[16+1];  //成交编号    MATCHED_SN      VARCHAR(16)17  
	char     chStkex;             //交易市场    STKEX           CHAR(1)    207 字典[STKEX]
	char     szStkCode[8+1];     //证券代码    STK_CODE        VARCHAR(8) 48  
	int      iOrderNo;            //委托编号    ORDER_NO        INTEGER    9106
	char     szOrderId[10+1];    //合同序号    ORDER_ID        VARCHAR(10)11  
	char     szTrdacct[16+1];    //交易账户    TRDACCT         VARCHAR(16)448 
	LONGLONG llMatchedQty;        //成交数量    MATCHED_QTY     BIGINT     387 撤单成交时数为负数
	char     szMatchedPrice[21+1];//成交价格    MATCHED_PRICE   CPRICE     8841
	char     szOrderFrzAmt[21+1]; //委托冻结金额  ORDER_FRZ_AMT   CMONEY     8831
	char     szRltSettAmt[21+1];  //实时清算金额  RLT_SETT_AMT    CMONEY     8853
	char     szFundAvl[21+1];     //资金可用金额  FUND_AVL        CMONEY     8861
	LONGLONG llStkAvl;            //证券可用数量  STK_AVL         BIGINT     8869
	char     szOpptStkpbu[8+1];  //对方席位    OPPT_STKPBU     VARCHAR(8) 9107
	char     szOpptTrdacct[10+1];//对方交易账号  OPPT_TRDACCT    VARCHAR(10)9108
	int      iMatchedDate;        //成交日期    MATCHED_DATE    INTEGER    8839
	char     szMatchedTime[8+1]; //成交时间    MATCHED_TIME    VARCHAR(8) 8840
	char     chIsWithdraw;        //撤单标志    IS_WITHDRAW     CHAR(1)    8836字典[IS_WITHDRAW]
	char     szCustCode[16+1];          //客户代码    CUST_CODE       BIGINT     8902
	char     szCuacctCode[16+1];        //资产账户    CUACCT_CODE     BIGINT     8920
	int      iOrderBsn;           //委托批号    ORDER_BSN       INTEGER    66  
	int      iCuacctSn;           //账户序号    CUACCT_SN       SMALLINT   8928
	char     szStkbd[2+1];       //交易板块    STKBD           CHAR(2)    625 字典[STKBD]
	char     chMatchedType;       //成交类型    MATCHED_TYPE    CHAR(1)    9080‘0’:内部撤单成交
	char     chOrderStatus;       //委托状态    ORDER_STATUS    CHAR(1)    39  字典[ORDER_STATUS]
	int      iStkBiz;             //证券业务    STK_BIZ         SMALLINT   8842
	int      iStkBizAction;       //证券业务行为  STK_BIZ_ACTION  SMALLINT   40  
	int      iOrderDate;          //委托日期    ORDER_DATE      INTEGER    8834期权专有字段
	int      iOrderSn;            //委托序号    ORDER_SN        INTEGER    8832期权专有字段
	int      iIntOrg;             //内部机构    INT_ORG         SMALLINT   8911期权专有字段
	char     szStkpbu[8+1];      //交易单元    STKPBU          VARCHAR(8) 8843期权专有字段
	char     szSubacctCode[8+1]; //证券账户子编码 SUBACCT_CODE    VARCHAR(8) 9099期权专有字段
	char     szOptTrdacct[18+1]; //期权合约账户  OPT_TRDACCT     VARCHAR(18)9098期权专有字段
	char     szOwnerType[3+1];   //订单所有类型  OWNER_TYPE      CHAR(3)    9091期权专有字段
	char     szOptCode[32+1];    //合约代码    OPT_CODE        VARCHAR(32)9083期权专有字段
	char     szOptName[32+1];    //合约简称    OPT_NAME        VARCHAR(32)9084期权专有字段
	char     chCurrency;          //货币代码    CURRENCY        CHAR(1)    15  期权专有字段
	char     chOptUndlCls;        //标的证券类别  OPT_UNDL_CLS    CHAR(1)    9085期权专有字段
	char     szOptUndlCode[8+1]; //标的证券代码  OPT_UNDL_CODE   VARCHAR(8) 9086期权专有字段
	char     szOptUndlName[16+1];//标的证券名称  OPT_UNDL_NAME   VARCHAR(16)9087期权专有字段
	char     szOrderPrice[21+1];  //委托价格    ORDER_PRICE     CPRICE4    44  期权专有字段
	LONGLONG llOrderQty;          //委托数量    ORDER_QTY       BIGINT     38  期权专有字段
	char     szOrderAmt[21+1];    //委托金额    ORDER_AMT       CMONEY     8830期权专有字段
	char     szMatchedAmt[21+1];  //已成交金额   MATCHED_AMT     CMONEY     8504期权专有字段
	char     szMarginPreFrz[21+1];//预占用保证金  MARGIN_PRE_FRZ  CMONEY     9094期权专有字段（卖开委托时填写预冻结的保证金金额，其他情况填“0”）
	char     szMarginFrz[21+1];   //占用保证金   MARGIN_FRZ      CMONEY     9095期权专有字段（卖开成交时填写实际冻结的保证金金额，其他情况填“0”）
	char     szMarginPreUfz[21+1];//预释放保证金  MARGIN_PRE_UFZ  CMONEY     9096期权专有字段（买平委托时填写预解冻的保证金金额，其他情况填“0”）
	char     szMarginUfz[21+1];   //释放保证金   MARGIN_UFZ      CMONEY     9097期权专有字段（买平成交时填写实际解冻的保证金金额，其他情况填“0”）
	int      iErrorId;            //错误代码    ERROR_ID        SMALLINT   8900错误代码
	char     szErrorMsg[81+1];   //错误信息    ERROR_MSG       VARCHAR(81)8901错误信息
	char     szBrokerId[11+1];   //经纪公司代码  BROKER_ID       VARCHAR(11)8890经纪公司代码
	char     szInstrumentId[31+1];//合约代码    INSTRUMENT_ID   VARCHAR(31)48  合约代码
	char     szOrderRef[13+1];   //报单引用    ORDER_REF       VARCHAR(13)8738报单引用
	char     szUserId[16+1];     //用户代码    USER_ID         VARCHAR(16)9080用户代码
	char     szExchangeId[9+1];  //交易所代码   EXCHANGE_ID     VARCHAR(9) 207 交易所代码
	char     szOrderSysId[21+1]; //报单编号    ORDER_SYS_ID    VARCHAR(21)8745报单编号
	char     szCombOffsetFlag[5+1];//组合开平标志  COMB_OFFSET_FLAGVARCHAR(5) 8741组合开平标志
	char     szCombHedgeFlag[5+1];//组合投机套保标志COMB_HEDGE_FLAG VARCHAR(5) 8742组合投机套保标志
	char     szOrderLocalId[13+1];//本地报单编号  ORDER_LOCAL_ID  VARCHAR(13)8722本地报单编号
	int      iSequenceNo;         //序号      SEQUENCE_NO     SMALLINT   8832序号
	char     szCliOrderNo[32+1]; //客户端委托编号 CLI_ORDER_NO    VARCHAR(32)9102
	LONGLONG llVolumeTraded;      //已成交总量   VOLUME_TRADED   BIGINT     8753已成交总量
	LONGLONG llWithdrawnQty;      //已撤单数量   WITHDRAWN_QTY   BIGINT     8837已撤单数量
};
//委托应答数据
struct MATRADEAPI CReqCosOrderAnswerField
{
	int      iOrderBsn;    //委托批号   ORDER_BSN     INTEGER     X 66   
	char     szOrderId[10+1];//合同序号   ORDER_ID      VARCHAR(10) X 11   
	int      iOrderNo;     //委托编号   ORDER_NO      INTEGER     X 9106 
	int      iOrderDate;   //委托日期   ORDER_DATE    INTEGER     X 8834 
	char     szOrderTime[32+1];//委托时间   ORDER_TIME    VARCHAR(32) X 8845 
  char     szCuacctCode[16+1]; //资产账户   CUACCT_CODE   BIGINT      X 8920 
	char     szOrderPrice[21+1];//委托价格   ORDER_PRICE   CPRICE      X 44   
	LONGLONG llOrderQty;   //委托数量   ORDER_QTY     BIGINT      X 38   
	char     szOrderAmt[21+1];//委托金额   ORDER_AMT     CMONEY      X 8830 
	char     szOrderFrzAmt[21+1];//冻结金额   ORDER_FRZ_AMT CMONEY      X 8831 
	char     szStkpbu[8+1];//交易单元   STKPBU        VARCHAR(8)  X 8843 
	char     szStkbd[2+1];//交易板块   STKBD         CHAR(2)     X 625  
	char     szStkCode[8+1];//证券代码   STK_CODE      VARCHAR(8)  X 48   
	char     szStkName[16+1];//证券名称   STK_NAME      VARCHAR(16) X 55   
	int      iStkBiz;      //证券业务   STK_BIZ       SMALLINT    X 8842 
	int      iStkBizAction;//业务行为   STK_BIZ_ACTIONSMALLINT    X 40   
	char     szTrdacct[16+1];//证券账户   TRDACCT       VARCHAR(16) X 448  
	int      iCuacctSn;    //账户序号   CUACCT_SN     SMALLINT    X 8928 
	char     szOptNum[16+1];//合约编码   OPT_NUM       VARCHAR(16) X 9082 期权
	char     szOptCode[32+1];//合约代码   OPT_CODE      VARCHAR(32) X 9084 期权
	char     szOptName[32+1];//合约简称   OPT_NAME      VARCHAR(32) X 9085 期权
	char     szOptUndlCode[8+1];//标的证券代码 OPT_UNDL_CODE VARCHAR(8)  X 48   期权
	char     chExeStatus;  //执行状态   EXE_STATUS    CHAR(1)     X 9103 
	char     szFrontId[32+1];//前置编号   FRONT_ID      VARCHAR(32) X 8732 
	char     szSessionId[32+1];//会话编号   SESSION_ID    VARCHAR(32) X 8814 
	int      iErrorId;     //错误代码   ERROR_ID      SMALLINT    X 8900 
	char     szErrorMsg[256+1];//错误信息   ERROR_MSG     VARCHAR(256)X 8901 
	int      iOrderChange; //改单标识   ORDER_CHANGE  SMALLINT    X 90860：普通委托1：改单2：撤单
	char     szCliOrderNo[32+1];//客户端委托编号CLI_ORDER_NO  VARCHAR(32) X 9102 客户端委托编号
};

struct MATRADEAPI CRspCosOrderAnswerField
{
	int      iOrderBsn;        //委托批号   ORDER_BSN     INTEGER     66  
	char     szOrderId[10+1]; //合同序号   ORDER_ID      VARCHAR(10) 11  
	int      iOrderNo;         //委托编号   ORDER_NO      INTEGER     9106
	int      iOrderDate;       //委托日期   ORDER_DATE    INTEGER     8834
	char     szOrderTime[32+1];//委托时间   ORDER_TIME    VARCHAR(32) 8845
	char     szCuacctCode[16+1];     //资产账户   CUACCT_CODE   BIGINT      8920
	char     szOrderPrice[21+1];//委托价格   ORDER_PRICE   CPRICE      44  
	LONGLONG llOrderQty;       //委托数量   ORDER_QTY     BIGINT      38  
	char     szOrderAmt[21+1]; //委托金额   ORDER_AMT     CMONEY      8830
	char     szOrderFrzAmt[21+1];//冻结金额   ORDER_FRZ_AMT CMONEY      8831
	char     szStkpbu[8+1];   //交易单元   STKPBU        VARCHAR(8)  8843
	char     szStkbd[2+1];    //交易板块   STKBD         CHAR(2)     625 
	char     szStkCode[8+1];  //证券代码   STK_CODE      VARCHAR(8)  48  
	char     szStkName[16+1]; //证券名称   STK_NAME      VARCHAR(16) 55  
	int      iStkBiz;          //证券业务   STK_BIZ       SMALLINT    8842
	int      iStkBizAction;    //业务行为   STK_BIZ_ACTIONSMALLINT    40  
	char     szTrdacct[16+1]; //证券账户   TRDACCT       VARCHAR(16) 448 
	int      iCuacctSn;        //账户序号   CUACCT_SN     SMALLINT    8928
	char     szOptNum[16+1];  //合约编码   OPT_NUM       VARCHAR(16) 9082期权
	char     szOptCode[32+1]; //合约代码   OPT_CODE      VARCHAR(32) 9084期权
	char     szOptName[32+1]; //合约简称   OPT_NAME      VARCHAR(32) 9085期权
	char     szOptUndlCode[8+1];//标的证券代码 OPT_UNDL_CODE VARCHAR(8)  48  期权
	char     chExeStatus;      //执行状态   EXE_STATUS    CHAR(1)     9103
	char     szFrontId[32+1]; //前置编号   FRONT_ID      VARCHAR(32) 8732
	char     szSessionId[32+1];//会话编号   SESSION_ID    VARCHAR(32) 8814
	int      iErrorId;         //错误代码   ERROR_ID      SMALLINT    8900
	char     szErrorMsg[256+1];//错误信息   ERROR_MSG     VARCHAR(256)8901
	int      iOrderChange;     //改单标识   ORDER_CHANGE  SMALLINT    9086
	char     szCliOrderNo[32+1];//客户端委托编号CLI_ORDER_NO  VARCHAR(32) 9102
};
//CON ORDER (单委托)条件单处理
struct MATRADEAPI CReqCosCondOrderField
{
	int      iTrdCodeCls;          //品种类型  TRD_CODE_CLS        INTEGER     Y 8970 
	char     szCustCode[16+1];           //客户代码  CUST_CODE           BIGINT      X 8902 
  char     szCuacctCode[16+1];         //资产账户  CUACCT_CODE         BIGINT      Y 8920 
	char     szTrdacct[32+1];     //交易账户  TRDACCT             VARCHAR(32) Y 448  
	char     chExchange;           //交易所   EXCHANGE            CHAR(1)     X 207  
	char     szBoard[2+1];        //交易板块  BOARD               CHAR(2)     Y 625  
	char     szTrdCode[16+1];     //交易代码  TRD_CODE            VARCHAR(16) X 48   现货/信用/期货时 必输
	int      iTrdBiz;              //交易业务  TRD_BIZ             SMALLINT    Y 8842 
	int      iTrdBizAcction;       //业务活动  TRD_BIZ_ACCTION     SMALLINT    Y 40   
	LONGLONG llOrderQty;           //委托数量  ORDER_QTY           BIGINT      Y 38   
	LONGLONG llOrderPrice;         //委托价格  ORDER_PRICE         BIGINT      X 44   期货时必输
	char     chSecurityLevel;      //安全手段  SECURITY_LEVEL      CHAR(1)     X 90801: 校验会话凭证
	char     szSecurityInfo[256+1];//安全信息  SECURITY_INFO       VARCHAR(256)X 9081 
	int      iIntOrg;              //内部机构  INT_ORG             SMALLINT    X 8911 期权时必输
	char     szOptNum[16+1];      //合约编码  OPT_NUM             VARCHAR(16) X 9082 期权时必输
	char     szStkpbu[8+1];       //交易单元  STKPBU              VARCHAR(8)  X 8843 
	int      iOrderBsn;            //委托批号  ORDER_BSN           INTEGER     X 66   
	char     szOrderIdEx[64+1];   //外部合同序号ORDER_ID_EX         VARCHAR(64) X 9093 此序号为外部传入，期权系统不做任何处理
	char     szUndlCode[16+1];    //标的代码  UNDL_CODE           VARCHAR(16) X 8972 
	int      iConExpDate;          //合约到期日 CON_EXP_DATE        INTEGER     X 8976 
	char     szExercisePrice[21+1];//行权价   EXERCISE_PRICE      CPRICE      X 8973 
	LONGLONG llConUnit;            //合约单位  CON_UNIT            BIGINT      X 8974 
	char     szCliOrderNo[32+1];  //客户端委托编CLI_ORDER_NO        VARCHAR(32) X 9102 
	char     szCliRemark[32+1];   //备用信息  CLI_REMARK          VARCHAR(32) X 8914 
	char     szBusinessUnit[21+1];//业务单元  BUSINESS_UNIT       VARCHAR(21) X 87170
	char     szGtdData[9+1];      //GTD日期 GTD_DATA            VARCHAR(9)  X 87230
	char     chContingentCondition;//触发条件  CONTINGENT_CONDITIONVARCHAR(1)  X 87131:立即
	char     chForceCloseReason;   //强平原因  FORCE_CLOSE_REASON  VARCHAR(1)  X 87150
	int      iIsSwapOrder;         //互换单标志 IS_SWAP_ORDER       SMALLINT    X 87200
};

struct MATRADEAPI CRspCosCondOrderField
{
};
//GROP ORDER(Group Order )组合条件单处理
struct MATRADEAPI CReqCosCombCondOrderField
{
	int      iTrdCodeCls;          //品种类型   TRD_CODE_CLS        INTEGER     Y 8970 
	char     szCustCode[16+1];           //客户代码   CUST_CODE           BIGINT      X 8902 
  char     szCuacctCode[16+1];         //资产账户   CUACCT_CODE         BIGINT      Y 8920 
  char     chCuacctType;         //资产账户类型
	char     szTrdacct[32+1];     //交易账户   TRDACCT             VARCHAR(32) Y 448  
	char     chExchange;           //交易所    EXCHANGE            CHAR(1)     X 207  
	char     szBoard[2+1];        //交易板块   BOARD               CHAR(2)     Y 625  
	char     szTrdCode[16+1];     //交易代码   TRD_CODE            VARCHAR(16) X 48   现货/信用/期货时 必输
	int      iTrdBiz;              //交易业务   TRD_BIZ             SMALLINT    Y 8842 
	int      iTrdBizAcction;       //业务活动   TRD_BIZ_ACCTION     SMALLINT    Y 40   
	LONGLONG llOrderQty;           //委托数量   ORDER_QTY           BIGINT      Y 38   
	LONGLONG llOrderPrice;         //委托价格   ORDER_PRICE         BIGINT      X 44   期货时必输
	char     chSecurityLevel;      //安全手段   SECURITY_LEVEL      CHAR(1)     X 90801: 校验会话凭证
	char     szSecurityInfo[256+1];//安全信息   SECURITY_INFO       VARCHAR(256)X 9081 
	int      iIntOrg;              //内部机构   INT_ORG             SMALLINT    X 8911 期权时必输
	char     szOptNum[16+1];      //合约编码   OPT_NUM             VARCHAR(16) X 9082 期权时必输
	char     szStkpbu[8+1];       //交易单元   STKPBU              VARCHAR(8)  X 8843 
	int      iOrderBsn;            //委托批号   ORDER_BSN           INTEGER     X 66   
	char     szOrderIdEx[64+1];   //外部合同序号 ORDER_ID_EX         VARCHAR(64) X 9093 此序号为外部传入，期权系统不做任何处理
	char     szUndlCode[16+1];    //标的代码   UNDL_CODE           VARCHAR(16) X 8972 
	int      iConExpDate;          //合约到期日  CON_EXP_DATE        INTEGER     X 8976 
	char     szExercisePrice[21+1];//行权价    EXERCISE_PRICE      CPRICE      X 8973 
	LONGLONG llConUnit;            //合约单位   CON_UNIT            BIGINT      X 8974 
	char     szCliOrderNo[32+1];  //客户端委托编号CLI_ORDER_NO        VARCHAR(32) X 9102 
	char     szCliRemark[32+1];   //备用信息   CLI_REMARK          VARCHAR(32) X 8914 
	char     szBusinessUnit[21+1];//业务单元   BUSINESS_UNIT       VARCHAR(21) X 87170
	char     szGtdData[9+1];      //GTD日期  GTD_DATA            VARCHAR(9)  X 87230
	char     chContingentCondition;//触发条件   CONTINGENT_CONDITIONVARCHAR(1)  X 87131:立即
	char     chForceCloseReason;   //强平原因   FORCE_CLOSE_REASON  VARCHAR(1)  X 87150
	int      iIsSwapOrder;         //互换单标志  IS_SWAP_ORDER       SMALLINT    X 87200
};

struct MATRADEAPI CRspCosCombCondOrderField
{
};


//自选股编辑
struct MATRADEAPI CReqCosPortfolioField
{
  char     szCuacctCode[16+1];//资产账号CUACCT_CODEBIGINT      Y 8920 
  char     chCuacctType;         //资产账户类型
	char     chStkex;     //交易所 STKEX      CHAR(1)     Y 207  
	char     szStkbd[2+1];//板块  STKBD      CHAR(2)     Y 625  
	char     szTrdCodes[512+1];//品种代码TRD_CODES  VARCHAR(512)Y 48   竖线分割
	char     chOperType;  //操作类型OPER_TYPE  CHAR(1)     Y 88441:添加;0:删除，其它不处理
};

struct MATRADEAPI CRspCosPortfolioField
{
};

//自选股查询
struct MATRADEAPI CReqCosPortfolioInfoField
{
  char     szCuacctCode[16+1];//资产账号CUACCT_CODEBIGINT    Y 8920 
  char     chCuacctType;         //资产账户类型
	char     chStkex;     //交易所 STKEX      CHAR(1)   Y 207  
	char     szStkbd[2+1];//板块  STKBD      CHAR(2)   Y 625  
	char     chQueryFlag; //查询方式QUERY_FLAG CHAR(1)   Y 90800：按位置向后查询 1：按位置向前查询 2：按范围查询 其它参数错误
	char     szStkCode[8+1];//查询位置STK_CODE   VARCHAR(8)X 8991 按位置查询时必传
	int      iQueryNum;   //查询行数QUERY_NUM  INTEGER   X 8992 按位置查询时必传，最多1000条
	char     szBegCode[8+1];//开始代码BEG_CODE   VARCHAR(8)X 9000 范围查询时必传(此范围包含开始代码和结束代码本身)
	char     szEndCode[8+1];//结束代码END_CODE   VARCHAR(8)X 9001 范围查询时必传
};

struct MATRADEAPI CRspCosPortfolioInfoField
{
	char     szCuacctCode[16+1];    //资产账号  CUACCT_CODEBIGINT      8920
	char     chStkex;         //交易所   STKEX      CHAR(1)     207 
	char     szStkbd[2+1];   //板块    STKBD      CHAR(2)     625 
	int      iAmount;         //数量    AMOUNT     INTEGER     8900
	char     szStkCodes[512+1];//代码(复数)STK_CODES  VARCHAR(512)48  |分割多个代码
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
END_NAMESPACE_MACLI
#endif//__MA_CLI_COS_TRADE_API_STRUCT_H__