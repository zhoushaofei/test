#pragma once



#include <map>
#include <vector>
#include <string>
using std::string;
using std::map;
using std::vector;

#include "itpdk/itpdk_typedef.h"
#include "itpdk/itpdk_dict.h"
#include "maritpdk/maritpdk_struct.h"
using namespace MarItpdk;


//////////////////////////////////////////////////////////////////////////
//获取时间戳毫秒级（仅linux，win同GetTickCount64）
ITPDK_API int64 MARITPDK_GetTickCount();
//获取时间戳微秒级（仅linux，win同GetTickCount64）
ITPDK_API int64 MARITPDK_GetDoubleTickCount();
//查询系统交易日期
ITPDK_API int64 MARITPDK_GetTradeDate();
////获取服务器系统日期
ITPDK_API int64 MARITPDK_GetSystemDate();
//获取修正过的时间(按交易服务器时间修正)
ITPDK_API int64 MARITPDK_GetReviseTimeAsLong();
//获取修正过的时间(按交易服务器时间修正)
ITPDK_API void MARITPDK_GetReviseTime(char *buffer);
//////////////////////////////////////////////////////////////////////////
//设置配置文件所在路径，ITPDK_Init 函数前调用生效
ITPDK_API void MARITPDK_SetProfilePath(const char *path);
//设置是否记录日志
ITPDK_API void MARITPDK_SetWriteLog(bool bLog);
//设置是否记录Fix日志
ITPDK_API void MARITPDK_SetFixWriteLog(bool bLog);

//设置是日志路径，ITPDK_Init 函数前调用生效
ITPDK_API void MARITPDK_SetLogPath(const char *path);
//初始化
ITPDK_API bool MARITPDK_Init(int commsize);
//退出
ITPDK_API void MARITPDK_Exit();
//获取最近错误信息和错误码
ITPDK_API int64 MARITPDK_GetLastError(char *result_msg);
//设置最新错误信息
ITPDK_API void MARITPDK_SetLastError(int64 result_code, const char *result_msg, const char* result_text = nullptr, ITPDK_CusReqInfo* cusreqinfo = nullptr);



/*
	设置信息回调函数
		消息数据pMsg为json串

		撤单消息 -- NOTIFY_PUSH_WITHDRAW
		废单消息 -- NOTIFY_PUSH_INVALID
		确认消息 -- NOTIFY_PUSH_ORDER
            WTH		int64		委托号
			KHH		char[]		客户号
            YYB     char[]      营业部
            GDH     char[]      股东号
			JYS		char[]		交易所
			ZQDM	char[]		证券代码
            XWH     char[]      席位号
            BZ      char[]      币种
            SBJG    int64        申报结果
            JYLB    int64        交易类别
            CXBZ    char        撤销标志
            CXWTH   int64        撤销委托号
            CJBH    char[]      成交编号
            CJSJ    char[]      成交时间
            CJSL    int64        成交数量
            CJJG    double      成交价格
            CJJE    doube       成交金额
		成交消息 -- NOTIFY_PUSH_MATCH
			KHH		char[]		客户号
			JYS		char[]		交易所
			ZQDM	char[]		证券代码
			WTH		int64		委托号
			CJSL	int64		成交数量
			CJJG	double		成交价格
		资产变动消息 -- NOTIFY_ASSETVARY
			KHH		char[]		客户号
			ZJZH	char[]		资金账号
			ZZC		double		总资产
			KYZJ	double		可用资金
			ZXSZ	double		最新市值

	func		[in]		回调函数
*/
ITPDK_API void MARITPDK_SetMsgCallback(pMessageCallbackMethod func);

// 异步回调函数
ITPDK_API void MARITPDK_SetFuncCallback(pAsyncCallbackFunc func);

// 连接掉线、恢复事件回调函数
/*
pConnEventCallback

pKhh		[in]		客户号
pConnKey	[in]		连接配置名
nEvent		[in]		事件:；0：恢复，1：断开
pData       [in]        保留字段
*/
ITPDK_API void MARITPDK_SetConnEventCallback(pConnEventCallback func);


// 设置站点信息
ITPDK_API bool MARITPDK_SetNode(const char *val);

// 设置委托方式
ITPDK_API bool MARITPDK_SetWTFS(const char *val);

/*
	交易登录
	lpKeyName	[in]		使用的配置Key值
	khh			[in]		客户号
	pwd			[in]		交易密码
	return				成功返回>0，失败返回<=0
*/
ITPDK_API int64 MARITPDK_TradeLogin(const char *lpKeyName, const char *khh, const char *pwd);
/*
	交易登录
	lpKeyName	[in]		使用的配置Key值
	cusreqinfo	[in/out]	客户信息
	return				成功返回>0，失败返回<=0
*/
ITPDK_API int64 MARITPDK_TradeLoginEx(const char* lpKeyName, ITPDK_CusReqInfo& cusreqinfo);

/*
    登出 
    KhhOrZjzh			[in]		客户号
*/
ITPDK_API int64 MARITPDK_TradeLogout(const char* KhhOrZjzh);


//////////////////////////////////////////////////////////
//交易类接口
//////////////////////////////////////////////////////////

/*
	信用交易

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_BUY、JYLB_SALE、JYLB_RZMR、JYLB_MQHK、JYLB_MQHQ、JYLB_RQMC、JYLB_DBWTJ、JYLB_DBWFH、JYLB_HQHZ、JYLB_ZJHK、JYLB_PHDJMR、JYLB_PHDJMC)
	lWtsl		[in]		委托数量
	lfWtjg		[in]		委托价格(订单类型为市价时，该参数不生效。交易类别为 直接还款时，还款金额填到此字段)
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	nTCLX		[in]		头寸类型  1普通头寸 2专项头寸(开仓: 送0 默认专项 ,偿还: 送0 偿还所有类型)
	lpHYBH		[in]		指定偿还负债流水号
	nChlx		[in]		偿还类型: 0-按了结方式) 1-只还利息
	nFlag		[in]	    撤单允许标志（还券划转业务专用） 0代表实时影响负债 1代表不实时影响负 -1代表没有送入撤单允许标志的委托
	return				成功返回委托号，失败返回<0
*/
ITPDK_API int64 MARITPDK_MarginEntrust(const char *lpKhh,const char *lpJys,const char *lpZqdm,int nJylb,int64 lWtsl,double lfWtjg, int64 lDdlx,const char *lpGdh,int nTCLX,const char * lpHYBH,int nChlx,int nFlag);
ITPDK_API int64 MARITPDK_MarginEntrustEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, int nTCLX, const char* lpHYBH, int nChlx, int nFlag);

/*
	信用交易接口(异步)

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_BUY、JYLB_SALE、JYLB_RZMR、JYLB_MQHK、JYLB_MQHQ、JYLB_RQMC、JYLB_DBWTJ、JYLB_DBWFH、JYLB_HQHZ、JYLB_ZJHK、JYLB_PHDJMR、JYLB_PHDJMC)
	lWtsl		[in]		委托数量
	lfWtjg		[in]		委托价格(订单类型为市价时，该参数不生效)
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	nTCLX		[in]		头寸类型  1普通头寸 2专项头寸(开仓: 送0 默认专项 ,偿还: 送0 偿还所有类型)
	lpHYBH		[in]		指定偿还负债流水号
	nChlx		[in]		偿还类型: 0-按了结方式) 1-只还利息
	nFlag		[in]	    撤单允许标志（还券划转业务专用） 0代表实时影响负债 1代表不实时影响负
	nKFSBDBH    [in]        开发商本地编号，若未送，则由itpdk自动生成(自定义委托号，在确认、成交等推送消息中会包含该值)
	return				成功返回开发商本地编号，失败返回<0
*/
ITPDK_API int64 MARITPDK_MarginEntrust_ASync(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, const char* lpGdh, int nTCLX, const char* lpHYBH, int nChlx,  int nFlag, int64 nKFSBDBH = 0);
ITPDK_API int64 MARITPDK_MarginEntrustEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, int nTCLX, const char* lpHYBH,  int nChlx ,  int nFlag, int64 nKFSBDBH = 0);


/*
	信用委托普通撤单

	lpKhh		[in]		客户号
	lpGdh		[in]		股东号
	lWth		[in]		委托号
    nJylb       [in]       交易类别
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 MARITPDK_MarginOrderWithdraw(const char *lpKhh,const char *lpGdh, int64 lWth,int nJylb);
ITPDK_API int64 MARITPDK_MarginOrderWithdrawEx(ITPDK_CusReqInfo& cusreqinfo, int64 lWth, int nJylb);
/*
	信用委托普通撤单(异步)

	lpKhh		[in]		客户号
	lpGdh		[in]		股东号
	lWth		[in]		委托号
	nJylb       [in]       交易类别
	nKFSBDBH	[in]        流水号：透传字段，在回调函数中通过该值匹配调用；
								若未送该字段，由接口内部生成。
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 MARITPDK_MarginOrderWithdraw_ASync(const char* lpKhh, const char* lpGdh, int64 lWth, int nJylb, int64 nKFSBDBH = 0);
ITPDK_API int64 MARITPDK_MarginOrderWithdrawEx_ASync(ITPDK_CusReqInfo& cusreqinfo, int64 lWth, int nJylb, int64 nKFSBDBH = 0);
/*
	信用委托开发商代码撤单

	lpKhh		[in]		客户号
	lpGdh		[in]		股东号
	nCxkfsbdh	[in]		撤销委托号
	nJylb       [in]       交易类别
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 MARITPDK_MarginOrderKFSDMWithdraw(const char* lpKhh, const char* lpGdh, int64 nCxkfsbdh, int nJylb);
ITPDK_API int64 MARITPDK_MarginOrderKFSDMWithdrawEx(ITPDK_CusReqInfo& cusreqinfo, int64 nCxkfsbdh, int nJylb);

/*
	信用委托开发商代码撤单(异步)

	lpKhh		[in]		客户号
	lpGdh		[in]		股东号
	nCxkfsbdh	[in]		撤销委托号
	nJylb       [in]       交易类别
	nKFSBDBH	[in]        流水号：透传字段，在回调函数中通过该值匹配调用；
								若未送该字段，由接口内部生成。
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 MARITPDK_MarginOrderKFSDMWithdraw_ASync(const char* lpKhh, const char* lpGdh, int64 nCxkfsbdh, int nJylb, int64 nKFSBDBH = 0);
ITPDK_API int64 MARITPDK_MarginOrderKFSDMWithdrawEx_ASync(ITPDK_CusReqInfo& cusreqinfo, int64 nCxkfsbdh, int nJylb, int64 nKFSBDBH = 0);



/*
	信用可委托数量计算
	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_BUY、JYLB_SALE)
	lfWtjg		[in]		委托价格(订单类型为市价时，该参数不生效)
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	lpDfGdh		[in]		对方股东号
	nTCLX		[in]		头寸类型  1普通头寸 2专项头寸
	nCHBZ       [in]        偿还标志：0-所有 1-普通 2-专项
	lpHYBH      [in]        合约编号（还券划转可指定合约编号）

*/
ITPDK_API int64 MARITPDK_MarginTradableQty(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, double lfWtjg, int64 lDdlx, const char* lpGdh, const char* lpDfGdh, int nTCLX, int nCHBZ, const char* lpHYBH);
ITPDK_API int64 MARITPDK_MarginTradableQtyEx(ITPDK_CusReqInfo& cusreqinfo,const char *lpJys,const char *lpZqdm,int nJylb,double lfWtjg, int64 lDdlx ,int nTCLX, int nCHBZ, const char* lpHYBH);


//////////////////////////////////////////////////////////
//查询类接口
//////////////////////////////////////////////////////////


/*
	查询资金信息

	khh			[in]		客户号
	arInfo		[out]		结果数据
	return				返回查询到的记录数
*/
ITPDK_API int64 MARITPDK_QueryFundInfo(const char* khh, vector<ITPDK_XYZJZH>& arInfo);
ITPDK_API int64 MARITPDK_QueryFundInfoEx(ITPDK_CusReqInfo& cusreqinfo, vector<ITPDK_XYZJZH>& arInfo);

/*
	查询股东信息

	khh			[in]		客户号
	arInfo		[out]		结果数据
	return				返回查询到的记录数
*/
ITPDK_API int64 MARITPDK_QueryAccInfo(const char* khh, vector<ITPDK_XYGDH>& arInfo);
ITPDK_API int64 MARITPDK_QueryAccInfoEx(ITPDK_CusReqInfo& cusreqinfo, vector<ITPDK_XYGDH>& arInfo);

/*
	查询信用负债

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpGdh		[in]		股东号
	lpZqdm		[in]		证券代码
	lpHybh		[in]		合约编号
	nJylb		[in]		交易类别
	nRowcount	[in]		返回条数
	nBrowindex	[in]		分页索引号
	nKsrq		[in]		开始日期
	nJsrq		[in]		结束日期
	lWth		[in]		委托号
	nType		[in]		是否了结(0 所有合约,1 已了结 2未了结)
	nTclx		[in]		头寸类型(0 所有类型 1 普通 2 专项)
	arInfo		[out]		结果数据
	return  返回条数

*/
ITPDK_API int64 MARITPDK_QueryDebts(const char* lpKhh, const char* lpJys, const char* lpGdh, const char* lpZqdm, const char* lpHybh, int64 nJylb, int64 nRowcount, const char* nBrowindex, int64 nKsrq, int64 nJsrq, int64 lWth, int64 nType, int64 nTclx, vector<ITPDK_XYFZ>& arInfo);
ITPDK_API int64 MARITPDK_QueryDebtsEx(ITPDK_CusReqInfo& cusreqinfo, const char * lpJys,const char * lpZqdm ,const char * lpHybh, int64 nJylb, int64 nRowcount, const char * nBrowindex, int64 nKsrq, int64 nJsrq, int64 lWth, int64 nType, int64 nTclx, vector<ITPDK_XYFZ>& arInfo);


/*
	两融查询当日委托

	khh			[in]		客户号
	nType		[in]		是否仅查询可撤委托（0查询全部，1查询可撤）
	nSortType	[in]		排序方式，当前仅支持逆序
	nRowcount	[in]		返回条数
	nBrowindex	[in]		分页（按委托号）
	jys			[in]		交易所（为空时查询所有交易所）
	zqdm		[in]		证券代码（为空时查询所有代码）
	nJylb		[in]		交易类别
	sCxbz		[in]		撤销标志
	lWth		[in]		委托号（为空时查询所有委托号）
	arInfo		[out]		结果数据
	return				返回查询到的记录数
*/
ITPDK_API int64 MARITPDK_QueryOrders_MR_DRWT(const char* khh, int nType, int nSortType, int nRowcount, int64 nBrowindex, const char* jys, const char* zqdm, int nJylb, const char* sCxbz, int64 lWth, vector<ITPDK_XYDRWT>& arInfo);
ITPDK_API int64 MARITPDK_QueryOrders_MR_DRWTEx(ITPDK_CusReqInfo& cusreqinfo, int nType, int nSortType, int nRowcount, int64 nBrowindex, const char *jys, const char *zqdm, int nJylb, const char *sCxbz, int64 lWth, vector<ITPDK_XYDRWT>& arInfo);

/*
	两融查询实时成交


	khh			[in]		客户号
	nType		[in]		是否查询可撤单委托部分（0查询全部，1 过滤 撤单数量CDSL>0部分）  
	nSortType	[in]		排序方式，0正序，1逆序
	nRowcount	[in]		返回条数
	nBrowindex	[in]		分页（按成交编号）
	jys			[in]		交易所（为空时查询所有交易所）
	zqdm		[in]		证券代码（为空时查询所有代码）
	nJylb		[in]		交易类别	
	lWth		[in]		委托号（为空时查询所有委托号）
	arInfo		[out]		结果数据
	return				返回查询到的记录数
*/
ITPDK_API int64 MARITPDK_QueryMatchs_MR_SSCJ(const char *khh, int nType, int nSortType, int nRowcount, int64 nBrowindex, const char *jys, const char *zqdm,int nJylb, int64 lWth, vector<ITPDK_XYSSCJ>& arInfo);
ITPDK_API int64 MARITPDK_QueryMatchs_MR_SSCJEx(ITPDK_CusReqInfo& cusreqinfo, int nType, int nSortType, int nRowcount, int64 nBrowindex, const char* jys, const char* zqdm, int nJylb, int64 lWth, vector<ITPDK_XYSSCJ>& arInfo);

/*
	两融查询持仓


	khh			[in]		客户号
	nFlag		[in]		扩展标志（0不扩展，1扩展）
	nSortType	[in]		排序方式，当前仅支持逆序
	nRowcount	[in]		返回条数
	nBrowindex	[in]		分页（按委托号）
	gdh			[in]		股东号
	jys			[in]		交易所（为空时查询所有交易所）
	zqdm		[in]		证券代码（为空时查询所有代码）
	arInfo		[out]		结果数据
	
	return				返回查询到的记录数
*/
ITPDK_API int64 MARITPDK_QueryPosition_MR_ZQGL(const char *khh, int nFlag, int nSortType, int nRowcount, int64 nBrowindex,const char * gdh, const char *jys, const char *zqdm, vector<ITPDK_XYZQGL>& arInfo);
ITPDK_API int64 MARITPDK_QueryPosition_MR_ZQGLEx(ITPDK_CusReqInfo& cusreqinfo, int nFlag, int nSortType, int nRowcount, int64 nBrowindex, const char* jys, const char* zqdm, vector<ITPDK_XYZQGL>& arInfo);

/*
	两融查询信用资产


	khh			[in]		客户号
	jys			[in]		交易所
	zqdm		[in]		证券代码
	nFlag		[in]		扩展标志（0不扩展，1扩展）
	
	arInfo		[out]		结果数据
	return				返回查询到的记录数
*/
ITPDK_API int64 MARITPDK_QueryTradeData_MR_XYZC(const char *khh, const char* jys, const char* zqdm, int nFlag , vector<ITPDK_XYZC>& arInfo);
ITPDK_API int64 MARITPDK_QueryTradeData_MR_XYZCEx(ITPDK_CusReqInfo& cusreqinfo, const char* jys, const char* zqdm, int nFlag, vector<ITPDK_XYZC>& arInfo);


/*
	两融查询客户可融券信息


    khh			[in]		客户号
	jys			[in]		交易所
	zqdm		[in]		证券代码
	tcxz		[in]		头寸来源(1 普通头寸 2 专项头寸 0所有)
	nRowcount	[in]		返回条数
	nBrowindex	[in]		分页索引号
	arInfo		[out]		结果数据
		
	return				返回查询到的记录数
*/
ITPDK_API int64 MARITPDK_QueryTradeData_MR_KRQXX(const char *khh,const char * jys,const char * zqdm ,int32 tcxz, int nRowcount, int64 nBrowindex, vector<ITPDK_RQZQ>& arInfo);
ITPDK_API int64 MARITPDK_QueryTradeData_MR_KRQXXEx(ITPDK_CusReqInfo& cusreqinfo, const char* jys, const char* zqdm, int32 tcxz, int nRowcount, int64 nBrowindex, vector<ITPDK_RQZQ>& arInfo);

/*
	两融查询客户可融资金信息


	khh			[in]		客户号
	tcxz		[in]		头寸来源(1 普通头寸 2 专项头寸 0所有)
	arInfo		[out]		结果数据

	return				返回查询到的记录数
*/
ITPDK_API int64 MARITPDK_QueryTradeData_MR_KRZJXX(const char* khh, int32 tcxz, vector<ITPDK_KRZJXX>& arInfo);
ITPDK_API int64 MARITPDK_QueryTradeData_MR_KRZJXXEx(ITPDK_CusReqInfo& cusreqinfo, int32 tcxz, vector<ITPDK_KRZJXX>& arInfo);



