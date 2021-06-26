#pragma once


#include <map>
#include <vector>
#include <string>
using std::string;
using std::map;
using std::vector;


#include "itpdk/itpdk_typedef.h"
#include "itpdk/itpdk_dict.h"
#include "secitpdk/secitpdk_struct.h"


//////////////////////////////////////////////////////////////////////////
//获取时间戳毫秒级（仅linux，win同GetTickCount64）
ITPDK_API int64 SECITPDK_GetTickCount();
//获取时间戳微秒级（仅linux，win同GetTickCount64）
ITPDK_API int64 SECITPDK_GetDoubleTickCount();
//获取服务器交易日期
ITPDK_API int64 SECITPDK_GetTradeDate();
//获取服务器系统日期
ITPDK_API int64 SECITPDK_GetSystemDate();
//获取修正过的时间(按交易服务器时间修正)
ITPDK_API int64 SECITPDK_GetReviseTimeAsLong();
//获取修正过的时间(按交易服务器时间修正)
ITPDK_API void SECITPDK_GetReviseTime(char* buffer);

//////////////////////////////////////////////////////////////////////////
//设置是日志路径，SECITPDK_Init 函数前调用生效
ITPDK_API void SECITPDK_SetLogPath(const char* path);
//设置配置文件所在路径，SECITPDK_Init 函数前调用生效
ITPDK_API void SECITPDK_SetProfilePath(const char* path);
//设置是否记录日志
ITPDK_API void SECITPDK_SetWriteLog(bool bLog);
//设置是否记录Fix日志
ITPDK_API void SECITPDK_SetFixWriteLog(bool bLog);

//初始化
ITPDK_API bool SECITPDK_Init(int commsize);
//退出
ITPDK_API void SECITPDK_Exit();
//获取最近错误信息和错误码
ITPDK_API int64 SECITPDK_GetLastError(char* result_msg);
//设置最新错误信息
ITPDK_API void SECITPDK_SetLastError(int64 result_code, const char* result_msg, const char* result_text = nullptr, ITPDK_CusReqInfo* cusreqinfo = nullptr);

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
			SBJG    int64       申报结果
			JYLB    int64       交易类别
			CXBZ    char        撤销标志
			CXWTH   int64       撤销委托号
			CJBH    char[]      成交编号
			CJSJ    char[]      成交时间
			CJSL    int64       成交数量
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
ITPDK_API void SECITPDK_SetMsgCallback(pMessageCallbackMethod func);

// 异步回调函数
ITPDK_API void SECITPDK_SetFuncCallback(pAsyncCallbackFunc func);

// 连接掉线、恢复事件回调函数
/*
	pConnEventCallback

	pKhh		[in]		客户号
	pConnKey	[in]		连接配置名
	nEvent		[in]		事件:；0：恢复，1：断开
*/
ITPDK_API void SECITPDK_SetConnEventCallback(pConnEventCallback func);

// 设置站点信息
ITPDK_API bool SECITPDK_SetNode(const char* val);

// 设置委托方式
ITPDK_API bool SECITPDK_SetWTFS(const char* val);

/*
	查询客户节点信息

	lpKeyName	[in]		使用的配置Key值
	khh			[in]		客户号
	return				成功返回true，失败返回false
*/
ITPDK_API int SECITPDK_QueryCusNodeinfo(const char* lpKeyName, const char* khh, vector<ITPDK_KHJD>& arKHJD);

/*
	设置用户交易节点

	khh			[in]		客户号
	nodeid		[in]		节点号
*/
ITPDK_API bool SECITPDK_SetCusNodeID(const char* khh, int nodeid);

/*
	交易登录
	lpKeyName	[in]		使用的配置Key值
	khh			[in]		客户号
	pwd			[in]		交易密码
	return				成功返回>0，失败返回<=0
*/
ITPDK_API int64 SECITPDK_TradeLogin(const char* lpKeyName, const char* khh, const char* pwd);

/*
	交易登录
	lpKeyName	[in]		使用的配置Key值
	cusreqinfo	[in/out]	客户信息
	return				成功返回>0，失败返回<=0
*/
ITPDK_API int64 SECITPDK_TradeLoginEx(const char* lpKeyName, ITPDK_CusReqInfo& cusreqinfo);

/*
	登出
	khh			[in]		客户号
*/
ITPDK_API int64 SECITPDK_TradeLogout(const char* khh);

/*
	设置用户token

	khh			[in]		客户号
	token		[in]		令牌
	return				成功返回true，失败返回false
*/
ITPDK_API bool SECITPDK_SetCusToken(const char* khh, int64 token);

/*
	查询字典数据

	tablename	[in]		表名
	khh			[in]		客户号
	nRowcount	[in]		返回记录数（0时返回全部）
	nBrowindex	[in]		分页（0时从头查）
	return				返回查询到的记录数
*/
ITPDK_API int64 SECITPDK_BeginQuery(const char* tablename, const char* khh, int nRowcount = 0, int nBrowindex = 0);

/*
	读取查询数据
		调用查询接口(SECITPDK_BeginQuery等)后，通过该接口获取数据

	tablename	[in]		表名
	khh			[in]		客户号
	buffer		[out]		数据buffer，用于返回数据
	buffsize	[in]		buffer大小
	nRecno		[in]		数据编号
	return				成功返回true，失败false
*/
ITPDK_API bool SECITPDK_GetQuery(const char* tablename, const char* khh, void* buffer, int buffsize, int nRecno);

/*
	释放查询数据
		调用查询接口后，不再使用查询数据时，调用该接口释放查询数据

	tablename	[in]		表名
	khh			[in]		客户号
	return				成功返回true，失败false
*/
ITPDK_API bool SECITPDK_EndQuery(const char* tablename, const char* khh);

/*
	查询资金信息

	khh			[in]		客户号
	arZjzh		[out]		结果数据
	return				返回查询到的记录数
*/
ITPDK_API int64 SECITPDK_QueryFundInfo(const char* khh, vector<ITPDK_ZJZH>& arZjzh);
ITPDK_API int64 SECITPDK_QueryFundInfoEx(ITPDK_CusReqInfo& cusreqinfo, vector<ITPDK_ZJZH>& arZjzh);

/*
	查询股东信息

	khh			[in]		客户号
	arZjzh		[out]		结果数据
	return				返回查询到的记录数
*/
ITPDK_API int64 SECITPDK_QueryAccInfo(const char* khh, vector<ITPDK_GDH>& arGdh);
ITPDK_API int64 SECITPDK_QueryAccInfoEx(ITPDK_CusReqInfo& cusreqinfo, vector<ITPDK_GDH>& arGdh);

/*
	查询当日委托

	khh			[in]		客户号
	nType		[in]		是否仅查询可撤委托（0查询全部，1查询可撤）
	nSortType	[in]		排序方式，0逆序，1正序
	nRowcount	[in]		返回条数
	nBrowindex	[in]		分页（按委托号）
	jys			[in]		交易所（为空时查询所有交易所）
	zqdm		[in]		证券代码（为空时查询所有代码）
	lWth		[in]		委托号（为空时查询所有委托号）
	arDrwt		[out]		结果数据
	return				返回查询到的记录数
*/
ITPDK_API int64 SECITPDK_QueryOrders(const char* khh, int nType, int nSortType, int nRowcount, int64 nBrowindex, const char* jys, const char* zqdm, int64 lWth, vector<ITPDK_DRWT>& arDrwt);
ITPDK_API int64 SECITPDK_QueryOrdersEx(ITPDK_CusReqInfo& cusreqinfo, int nType, int nSortType, int nRowcount, int64 nBrowindex, const char* jys, const char* zqdm, int64 lWth, vector<ITPDK_DRWT>& arDrwt);

/*
	查询成交

	khh			[in]		客户号
	nType		[in]		是否仅查询CJSL>0部分（0查询全部，1查询CJSL>0部分）
	nSortType	[in]		排序方式，0逆序，1正序
	nRowcount	[in]		返回条数
	nBrowindex	[in]		分页（按成交编号）
	jys			[in]		交易所（为空时查询所有交易所）
	zqdm		[in]		证券代码（为空时查询所有代码）
	lWth		[in]		委托号（为空时查询所有委托号）
	arSscj		[out]		结果数据
	return				返回查询到的记录数
*/
ITPDK_API int64 SECITPDK_QueryMatchs(const char* khh, int nType, int nSortType, int nRowcount, int64 nBrowindex, const char* jys, const char* zqdm, int64 lWth, vector<ITPDK_SSCJ>& arSscj);
ITPDK_API int64 SECITPDK_QueryMatchsEx(ITPDK_CusReqInfo& cusreqinfo, int nType, int nSortType, int nRowcount, int64 nBrowindex, const char* jys, const char* zqdm, int64 lWth, vector<ITPDK_SSCJ>& arSscj);

/*
	查询持仓

	tablename	[in]		表名table_zqgl
	khh			[in]		客户号
	nSortType	[in]		排序方式，0逆序，1正序
	nRowcount	[in]		返回条数
	nBrowindex	[in]		分页（按持仓编号）
	gdh			[in]		股东号（为空时查询所有股东号）
	jys			[in]		交易所（为空时查询所有交易所）
	zqdm		[in]		证券代码（为空时查询所有代码）
	exeflag		[in]		>0包括实现收益的浮动盈亏
	arZqgl		[out]		结果数据
	return				返回查询到的记录数
*/
ITPDK_API int64 SECITPDK_QueryPositions(const char* khh, int nSortType, int nRowcount, int64 nBrowindex, const char* gdh, const char* jys, const char* zqdm, int32 exeflag, vector<ITPDK_ZQGL>& arZqgl);
ITPDK_API int64 SECITPDK_QueryPositionsEx(ITPDK_CusReqInfo& cusreqinfo, int nSortType, int nRowcount, int64 nBrowindex, const char* gdh, const char* jys, const char* zqdm, int32 exeflag, vector<ITPDK_ZQGL>& arZqgl);

/*
	查询配售权益

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpGdh		[in]		股东号
	return				成功返回结果数，失败返回<0
*/
ITPDK_API int64 SECITPDK_QueryPSQY(const char* lpKhh, const char* lpJys, const char* lpGdh, vector<ITPDK_PSQYInfo>& arPsqy);
ITPDK_API int64 SECITPDK_QueryPSQYEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpGdh, vector<ITPDK_PSQYInfo>& arPsqy);

/*
	查询ETF明细，成分股信息

	khh			[in]		客户号
	jjdm		[in]		ETF代码
	arEtfmx		[out]		结果数据
	return				返回查询到的记录数
*/
ITPDK_API int64 SECITPDK_QueryETFShare(const char* khh, const char* jjdm, vector<ITPDK_ETFMX>& arEtfmx);
ITPDK_API int64 SECITPDK_QueryETFShareEx(ITPDK_CusReqInfo& cusreqinfo, const char* jjdm, vector<ITPDK_ETFMX>& arEtfmx);

//证券发起银行业务 Bank business initiated by Securities
//ITPDK_API int64 SECITPDK_BankBusiness(const char *lpKhh,int nYwlb,double lfZzje,const char *lpZjmm,const char *lpYhmm,const char *lpZjzh,const char *lpBz,const char *lpYhdm,const char *lpYhzh);

/*
	普通交易
		注：后缀Ex接口通过cusreqinfo参数送入客户号、股东号、节点号、token
	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_BUY、JYLB_SALE)
	lWtsl		[in]		委托数量
	lfWtjg		[in]		委托价格(订单类型为市价时，该参数不生效)
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	return				成功返回委托号，失败返回<0
*/
ITPDK_API int64 SECITPDK_OrderEntrust(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, const char* lpGdh);
ITPDK_API int64 SECITPDK_OrderEntrustEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx);

/*
	异步普通交易
		注：后缀Ex接口通过cusreqinfo参数送入客户号、股东号、节点号、token
	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_BUY、JYLB_SALE)
	lWtsl		[in]		委托数量
	lfWtjg		[in]		委托价格(订单类型为市价时，该参数不生效)
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	nKFSBDBH    [in]        开发商本地编号，若未送，则由itpdk自动生成(自定义委托号，在确认、成交等推送消息中会包含该值)
	return				成功返回开发商本地编号，失败返回<0
*/
ITPDK_API int64 SECITPDK_OrderEntrust_ASync(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, const char* lpGdh, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_OrderEntrustEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, int64 nKFSBDBH = 0);

/*
	普通交易批量委托

	lpKhh		    [in]		客户号
	arBatOrder		[in/out]	批量委托信息
	nWTPCH		    [in]	    委托批次号：可用于批量撤单，在每笔委托的消息推送中也会包含
	return				小于0：表示非交易错误或其他导致无法进行委托的错误，可通过SECITPDK_GetLastError获取错误信息
						其他：表示买卖失败的数量，可通过参数获取失败信息
*/
ITPDK_API int64 SECITPDK_BatchOrderEntrust(const char* lpKhh, vector<BatchOrderInfo>& arBatOrder, int64 nWTPCH);
ITPDK_API int64 SECITPDK_BatchOrderEntrustEx(ITPDK_CusReqInfo& cusreqinfo, vector<BatchOrderInfo>& arBatOrder, int64 nWTPCH);

/*
	异步普通交易批量委托

	lpKhh		    [in]		客户号
	arBatOrder		[in/out]	批量委托信息
	nWTPCH		    [in]	    委托批次号：可用于批量撤单，在每笔委托的消息推送中也会包含
	return				小于0：表示非交易错误或其他导致无法进行委托的错误，可通过SECITPDK_GetLastError获取错误信息
						其他：表示买卖失败的数量，可通过参数获取失败信息
*/
ITPDK_API int64 SECITPDK_BatchOrderEntrust_ASync(const char* lpKhh, vector<BatchOrderInfo>& arBatOrder, int64 nWTPCH);
ITPDK_API int64 SECITPDK_BatchOrderEntrustEx_ASync(ITPDK_CusReqInfo& cusreqinfo, vector<BatchOrderInfo>& arBatOrder, int64 nWTPCH);

/*
	ETF交易

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		ETF代码
	nJylb		[in]		交易类别(JYLB_ETFSG申购、JYLB_ETFSH赎回)
	lWtsl		[in]		委托数量
	lpGdh		[in]		股东号
	lpStep		[in]		扩展字段(默认空)
	return				成功返回委托号，失败返回<0
*/
ITPDK_API int64 SECITPDK_ETFEntrust(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int32 lWtsl, const char* lpGdh, const char* lpStep = "");
ITPDK_API int64 SECITPDK_ETFEntrustEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int32 lWtsl, const char* lpStep = "");

/*
	异步ETF交易

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		ETF代码
	nJylb		[in]		交易类别(JYLB_ETFSG申购、JYLB_ETFSH赎回)
	lWtsl		[in]		委托数量
	lpGdh		[in]		股东号
	lpStep		[in]		扩展字段(默认空)
	nKFSBDBH    [in]        开发商本地编号，若未送，则由itpdk自动生成(自定义委托号，在确认、成交等推送消息中会包含该值)
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_ETFEntrust_ASync(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int32 lWtsl, const char* lpGdh, const char* lpStep = "", int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_ETFEntrustEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int32 lWtsl, const char* lpStep = "", int64 nKFSBDBH = 0);

/*
	ETF篮子股买卖

	lpKhh		    [in]		客户号
	lpJjdm		    [in]		ETF代码
	nJylb		    [in]		交易类别(JYLB_BUY、JYLB_SALE)
	lWtsl		    [in]		委托数量
	mpJysGdh		[in]		交易所股东号
	pSuccRecords    [out]       买卖成功记录
	pFailRecords    [out]       买卖失败记录
	nLSH			[in]		流水号：可用于批量撤单，在每笔委托的消息推送中也会包含
	return				小于0：表示非交易错误或其他导致无法进行委托的错误，可通过SECITPDK_GetLastError获取错误信息
						其他：表示买卖篮子股失败的数量，可通过参数获取失败记录
*/
ITPDK_API int64 SECITPDK_ETFBasketEntrust(const char* lpKhh, const char* lpJjdm, int nJylb, int64 lWtsl, map<string, string>& mpJysGdh, vector<ETFBasket>* pSuccRecords = nullptr, vector<ETFBasket>* pFailRecords = nullptr, int64 nLSH = 0);
ITPDK_API int64 SECITPDK_ETFBasketEntrustEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJjdm, int nJylb, int64 lWtsl, map<string, string>& mpJysGdh, vector<ETFBasket>* pSuccRecords = nullptr, vector<ETFBasket>* pFailRecords = nullptr, int64 nLSH = 0);

/*
	债券正逆回购

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_HGRQ、JYLB_HGRZ)
	lWtsl		[in]		委托数量
	lfWtjg		[in]		委托价格(订单类型为市价时，该参数不生效)
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	return				成功返回委托号，失败返回<0
*/
ITPDK_API int64 SECITPDK_ZQHGEntrust(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int32 lWtsl, double lfWtjg, int64 lDdlx, const char* lpGdh);
ITPDK_API int64 SECITPDK_ZQHGEntrustEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int32 lWtsl, double lfWtjg, int64 lDdlx);

/*
	异步债券正逆回购

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_HGRQ、JYLB_HGRZ)
	lWtsl		[in]		委托数量
	lfWtjg		[in]		委托价格(订单类型为市价时，该参数不生效)
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	nKFSBDBH    [in]        开发商本地编号，若未送，则由itpdk自动生成(自定义委托号，在确认、成交等推送消息中会包含该值)
	return				成功返回委托号，失败返回<0
*/
ITPDK_API int64 SECITPDK_ZQHGEntrust_ASync(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int32 lWtsl, double lfWtjg, int64 lDdlx, const char* lpGdh, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_ZQHGEntrustEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int32 lWtsl, double lfWtjg, int64 lDdlx, int64 nKFSBDBH = 0);

/*
	债券出入库

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		质押代码
	nJylb		[in]		交易类别(JYLB_ZYQRK、JYLB_ZYQCK)
	lWtsl		[in]		委托数量
	lpGdh		[in]		股东号
	return				成功返回委托号，失败返回<0
*/
ITPDK_API int64 SECITPDK_ZQHGCrk(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int32 lWtsl, const char* lpGdh);
ITPDK_API int64 SECITPDK_ZQHGCrkEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int32 lWtsl);

/*
	异步债券出入库

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		质押代码
	nJylb		[in]		交易类别(JYLB_ZYQRK、JYLB_ZYQCK)
	lWtsl		[in]		委托数量
	lpGdh		[in]		股东号
	nKFSBDBH    [in]        开发商本地编号，若未送，则由itpdk自动生成(自定义委托号，在确认、成交等推送消息中会包含该值)
	return				成功返回委托号，失败返回<0
*/
ITPDK_API int64 SECITPDK_ZQHGCrk_ASync(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int32 lWtsl, const char* lpGdh, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_ZQHGCrkEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int32 lWtsl, int64 nKFSBDBH = 0);

/*
	发行业务

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_PGJK配股配债缴款、JYLB_PSSG配售申购|债券配发、JYLB_BUY首发增发买入、JYLB_PSFQ配售债券放弃)
	lWtsl		[in]		委托数量
	lfWtjg		[in]		委托价格
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	return				成功返回委托号，失败返回<0
*/
ITPDK_API int64 SECITPDK_FXYW(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, const char* lpGdh);
ITPDK_API int64 SECITPDK_FXYWEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx);

/*
	异步发行业务

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_PGJK配股配债缴款、JYLB_PSSG配售申购|债券配发、JYLB_BUY首发增发买入、JYLB_PSFQ配售债券放弃)
	lWtsl		[in]		委托数量
	lfWtjg		[in]		委托价格
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	return				成功返回委托号，失败返回<0
*/
ITPDK_API int64 SECITPDK_FXYW_ASync(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, const char* lpGdh, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_FXYWEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, int64 nKFSBDBH = 0);

/*
	LOF基金业务

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_JJRG基金认购,JYLB_JJSG基金申购,JYLB_JJSH基金赎回,JYLB_JJFC基金分拆,JYLB_JJHB基金合并)
	lWtsl		[in]		委托数量
	lfWtjg		[in]		委托价格
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	return				成功返回委托号，失败返回<0
*/
ITPDK_API int64 SECITPDK_Lof(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int32 lWtsl, double lfWtjg, int8 lDdlx, const char* lpGdh);
ITPDK_API int64 SECITPDK_LofEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int32 lWtsl, double lfWtjg, int8 lDdlx);

/*
	异步LOF基金业务

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_JJRG基金认购,JYLB_JJSG基金申购,JYLB_JJSH基金赎回,JYLB_JJFC基金分拆,JYLB_JJHB基金合并)
	lWtsl		[in]		委托数量
	lfWtjg		[in]		委托价格
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	return				成功返回委托号，失败返回<0
*/
ITPDK_API int64 SECITPDK_Lof_ASync(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int32 lWtsl, double lfWtjg, int8 lDdlx, const char* lpGdh, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_LofEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int32 lWtsl, double lfWtjg, int8 lDdlx, int64 nKFSBDBH = 0);

/*
	大宗交易

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_YXMR意向买入,JYLB_YXMC意向卖出,JYLB_DJMR定价买入,JYLB_DJMC定价卖出,JYLB_MRQR买入确认,JYLB_MCQR卖出确认,JYLB_PHMR盘后买入,JYLB_PHMC盘后卖出)
	lWtsl		[in]		委托数量
	lfWtjg		[in]		委托价格
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	lpDfxw		[in]		对方席位
	lpDfgdh		[in]		对方股东号
	lpLxr		[in]		联系人
	lpLxdh		[in]		联系电话
	lpHyh		[in]		合约号
	nPddm		[in]		配对成交标志（>0 表示配对成交）
	nTdbz		[in]		特定股份大宗交易标志（>0 表示特定股份交易）
	return				成功返回委托号，失败返回<0
*/
ITPDK_API int64 SECITPDK_DZJY(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, const char* lpGdh, const char* lpDfxw, const char* lpDfgdh, const char* lpLxr, const char* lpLxdh, const char* lpHyh, int nPddm, int nTdbz);
ITPDK_API int64 SECITPDK_DZJYEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, const char* lpDfxw, const char* lpDfgdh, const char* lpLxr, const char* lpLxdh, const char* lpHyh, int nPddm, int nTdbz);

/*
	盘后定价交易
		注：后缀Ex接口通过cusreqinfo参数送入客户号、股东号、节点号、token
	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_PHDJMR、JYLB_PHDJMC)
	lWtsl		[in]		委托数量
	lfWtjg		[in]		委托价格(订单类型为市价时，该参数不生效)
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	return				成功返回委托号，失败返回<0
*/
ITPDK_API int64 SECITPDK_PHDJEntrust(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, const char* lpGdh);
ITPDK_API int64 SECITPDK_PHDJEntrustEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx);

/*
	异步盘后定价交易
		注：后缀Ex接口通过cusreqinfo参数送入客户号、股东号、节点号、token
	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_PHDJMR、JYLB_PHDJMC)
	lWtsl		[in]		委托数量
	lfWtjg		[in]		委托价格(订单类型为市价时，该参数不生效)
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	nKFSBDBH    [in]        开发商本地编号，若未送，则由itpdk自动生成(自定义委托号，在确认、成交等推送消息中会包含该值)
	return				成功返回开发商本地编号，失败返回<0
*/
ITPDK_API int64 SECITPDK_PHDJEntrust_ASync(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, const char* lpGdh, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_PHDJEntrustEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, int64 nKFSBDBH = 0);

/*
	非交易业务

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_HSCX回售冲销、JYLB_ZZZG转债转股、JYLB_ZZHS转债回售、JYLB_YSYY预受要约、JYLB_JCYS解除预受要约)
	lWtsl		[in]		委托数量
	lfWtjg		[in]		委托价格
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	return				成功返回委托号，失败返回<0
*/
ITPDK_API int64 SECITPDK_FJY(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, const char* lpGdh);
ITPDK_API int64 SECITPDK_FJYEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx);

/*
	异步非交易业务

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_HSCX回售冲销、JYLB_ZZZG转债转股、JYLB_ZZHS转债回售、JYLB_YSYY预受要约、JYLB_JCYS解除预受要约)
	lWtsl		[in]		委托数量
	lfWtjg		[in]		委托价格
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	return				成功返回委托号，失败返回<0
*/
ITPDK_API int64 SECITPDK_FJY_ASync(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, const char* lpGdh, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_FJYEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, int64 lWtsl, double lfWtjg, int64 lDdlx, int64 nKFSBDBH = 0);

/*
	普通委托撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxwth		[in]		撤销委托号
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_OrderWithdraw(const char* lpKhh, const char* lpJys, int64 nCxwth);
ITPDK_API int64 SECITPDK_OrderWithdrawEx(ITPDK_CusReqInfo &cusreqinfo, const char* lpJys, int64 nCxwth);

/*
	异步普通委托撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxwth		[in]		撤销委托号
	nKFSBDBH	[in]        流水号：透传字段，在回调函数中通过该值匹配调用；
								若未送该字段，由接口内部生成。
	return				失败返回<0，成功返回KFSBDBH
*/
ITPDK_API int64 SECITPDK_OrderWithdraw_ASync(const char* lpKhh, const char* lpJys, int64 lCXWth, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_OrderWithdrawEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 lCXWth, int64 nKFSBDBH);

/*
	普通委托根据开发商本地编号撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxkfsbdh	[in]		撤销委托号
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_OrderWithdrawByKFSBDBH(const char* lpKhh, const char* lpJys, int64 nCXKFSBDBH);
ITPDK_API int64 SECITPDK_OrderWithdrawByKFSBDBHEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCXKFSBDBH);

/*
	异步普通委托根据开发商本地编号撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxkfsbdh	[in]		撤销开发商本地编号
	nKFSBDBH    [in]        流水号：透传字段，在回调函数中通过该值匹配调用；
								若未送该字段，由接口内部生成。
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_OrderWithdrawByKFSBDBH_ASync(const char* lpKhh, const char* lpJys, int64 nCXKFSBDBH, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_OrderWithdrawByKFSBDBHEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCXKFSBDBH, int64 nKFSBDBH = 0);

/*
	普通委托批量撤单

	lpKhh		[in]		客户号
	nLSH		[in]		流水号：批量委托时送入的流水号，为0撤全部委托
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_BatchOrderWithdraw(const char* lpKhh, int64 nLSH);
ITPDK_API int64 SECITPDK_BatchOrderWithdrawEx(ITPDK_CusReqInfo& cusreqinfo, int64 nLSH);

/*
	异步普通委托批量撤单

	lpKhh		[in]		客户号
	nLSH		[in]		流水号：批量委托时送入的流水号，为0撤全部委托；在回调函数中送回。
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_BatchOrderWithdraw_ASync(const char* lpKhh, int64 nLSH);
ITPDK_API int64 SECITPDK_BatchOrderWithdrawEx_ASync(ITPDK_CusReqInfo& cusreqinfo, int64 nLSH);

/*
	ETF委托撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lCxwth		[in]		委托号
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_ETFWithdraw(const char* lpKhh, const char* lpJys, int64 lCxwth);
ITPDK_API int64 SECITPDK_ETFWithdrawEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 lCxwth);

/*
	异步ETF委托撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lWth		[in]		委托号
	nKFSBDBH	[in]        流水号：透传字段，在回调函数中通过该值匹配调用；
								若未送该字段，由接口内部生成。
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_ETFWithdraw_ASync(const char* lpKhh, const char* lpJys, int64 lCxwth, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_ETFWithdrawEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 lCxwth, int64 nKFSBDBH = 0);

/*
	ETF委托根据开发商本地编号撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCXKFSBDBH	[in]		开发商本地编码（由异步委托接口返回）
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_ETFWithdrawByKFSBDBH(const char* lpKhh, const char* lpJys, int64 nCXKFSBDBH);
ITPDK_API int64 SECITPDK_ETFWithdrawByKFSBDBHEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCXKFSBDBH);

/*
	异步ETF委托根据开发商本地编号撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCXKFSBDBH	[in]		开发商本地编码（由异步委托接口返回）
	nKFSBDBH	[in]        流水号：透传字段，在回调函数中通过该值匹配调用；
								若未送该字段，由接口内部生成。
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_ETFWithdrawByKFSBDBH_ASync(const char* lpKhh, const char* lpJys, int64 nCXKFSBDBH, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_ETFWithdrawByKFSBDBHEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCXKFSBDBH, int64 nKFSBDBH = 0);

/*
	债券回购委托撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxwth		[in]		撤销委托号
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_ZQHGWithdraw(const char* lpKhh, const char* lpJys, int64 nCxwth);
ITPDK_API int64 SECITPDK_ZQHGWithdrawEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCxwth);

/*
	异步债券回购委托撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxwth		[in]		撤销委托号
	nKFSBDBH	[in]        流水号：透传字段，在回调函数中通过该值匹配调用；
							若未送该字段，由接口内部生成。
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_ZQHGWithdraw_ASync(const char* lpKhh, const char* lpJys, int64 nCxwth, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_ZQHGWithdrawEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCxwth, int64 nKFSBDBH = 0);

/*
	债券回购委托根据开发商本地编号撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxkfsbdh	[in]		撤销开发商本地编号
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_ZQHGWithdrawByKFSBDBH(const char* lpKhh, const char* lpJys, int64 nCxkfsbdh);
ITPDK_API int64 SECITPDK_ZQHGWithdrawByKFSBDBHEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCxkfsbdh);

/*
	异步债券回购委托根据开发商本地编号撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxkfsbdh	[in]		撤销开发商本地编号
	nKFSBDBH	[in]        流水号：透传字段，在回调函数中通过该值匹配调用；
							若未送该字段，由接口内部生成。
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_ZQHGWithdrawByKFSBDBH_ASync(const char* lpKhh, const char* lpJys, int64 nCxkfsbdh, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_ZQHGWithdrawByKFSBDBHEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCxkfsbdh, int64 nKFSBDBH = 0);

/*
	发行业务委托撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxwth		[in]		撤销委托号
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_FXYWWithdraw(const char* lpKhh, const char* lpJys, int64 nCxwth);
ITPDK_API int64 SECITPDK_FXYWWithdrawEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCxwth);

/*
	异步发行业务委托撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxwth		[in]		撤销委托号
	nKFSBDBH	[in]        流水号：透传字段，在回调函数中通过该值匹配调用；
							若未送该字段，由接口内部生成。
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_FXYWWithdraw_ASync(const char* lpKhh, const char* lpJys, int64 nCxwth, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_FXYWWithdrawEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCxwth, int64 nKFSBDBH = 0);

/*
	LOF业务撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxwth		[in]		撤销委托号
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_LOFWithdraw(const char* lpKhh, const char* lpJys, int64 nCxwth);
ITPDK_API int64 SECITPDK_LOFWithdrawEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCxwth);

/*
	异步LOF业务撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxwth		[in]		撤销委托号
	nKFSBDBH	[in]        流水号：透传字段，在回调函数中通过该值匹配调用；
							若未送该字段，由接口内部生成。
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_LOFWithdraw_ASync(const char* lpKhh, const char* lpJys, int64 nCxwth, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_LOFWithdrawEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCxwth, int64 nKFSBDBH = 0);

/*
	LOF业务委托根据开发商本地编号撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxkfsbdh	[in]		撤销开发商本地编号
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_LOFWithdrawByKFSBDBH(const char* lpKhh, const char* lpJys, int64 nCxkfsbdh);
ITPDK_API int64 SECITPDK_LOFWithdrawByKFSBDBHEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCxkfsbdh);

/*
	异步LOF业务委托根据开发商本地编号撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxkfsbdh	[in]		撤销开发商本地编号
	nKFSBDBH	[in]        流水号：透传字段，在回调函数中通过该值匹配调用；
							若未送该字段，由接口内部生成。
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_LOFWithdrawByKFSBDBH_ASync(const char* lpKhh, const char* lpJys, int64 nCxkfsbdh, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_LOFWithdrawByKFSBDBHEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCxkfsbdh, int64 nKFSBDBH = 0);

/*
	盘后定价委托撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxwth		[in]		撤销委托号
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_PHDJWithdraw(const char* lpKhh, const char* lpJys, int64 nCxwth);
ITPDK_API int64 SECITPDK_PHDJWithdrawEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCxwth);

/*
	异步盘后定价委托撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxwth		[in]		撤销委托号
	nKFSBDBH	[in]        流水号：透传字段，在回调函数中通过该值匹配调用；
								若未送该字段，由接口内部生成。
	return				失败返回<0，成功返回KFSBDBH
*/
ITPDK_API int64 SECITPDK_PHDJWithdraw_ASync(const char* lpKhh, const char* lpJys, int64 lCXWth, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_PHDJWithdrawEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 lCXWth, int64 nKFSBDBH);

/*
	非交易业务委托撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxwth		[in]		撤销委托号
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_FJYWithdraw(const char* lpKhh, const char* lpJys, int64 nCxwth);
ITPDK_API int64 SECITPDK_FJYWithdrawEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCxwth);

/*
	异步非交易业务委托撤单

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	nCxwth		[in]		撤销委托号
	nKFSBDBH	[in]        流水号：透传字段，在回调函数中通过该值匹配调用；
							若未送该字段，由接口内部生成。
	return				成功返回>0，失败返回<0
*/
ITPDK_API int64 SECITPDK_FJYWithdraw_ASync(const char* lpKhh, const char* lpJys, int64 nCxwth, int64 nKFSBDBH = 0);
ITPDK_API int64 SECITPDK_FJYWithdrawEx_ASync(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, int64 nCxwth, int64 nKFSBDBH = 0);

/*
	普通买卖可委托数量计算

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(仅JYLB_BUY申购)
	lfWtjg		[in]		委托价格(订单类型为市价时，该参数不生效)
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	return				成功返回可申购数量，失败返回<0
*/
ITPDK_API int64 SECITPDK_TradableQty(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, double lfWtjg, int32 lDdlx, const char* lpGdh);
ITPDK_API int64 SECITPDK_TradableQtyEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, double lfWtjg, int32 lDdlx);

/*
	ETF可认购数量

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		ETF代码
	nJylb		[in]		交易类别(仅JYLB_ETFSG申购)
	lpGdh		[in]		股东号
	return				成功返回可申购数量，失败返回<0
*/
ITPDK_API int64 SECITPDK_ETFTradableQty(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, const char* lpGdh);
ITPDK_API int64 SECITPDK_ETFTradableQtyEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb);

/*
	债券可委托数量

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		代码
	nJylb		[in]		交易类别
	lpGdh		[in]		股东号
	return				成功返回可申购数量，失败返回<0
*/
ITPDK_API int64 SECITPDK_ZQHGTradableQty(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, const char* lpGdh);
ITPDK_API int64 SECITPDK_ZQHGTradableQtyEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb);

/*
	发行业务可认购数量

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		ETF代码
	nJylb		[in]		交易类别(JYLB_PGJK配股缴款,JYLB_PSSG配售申购,JYLB_BUY增发买入)
	lfWtjg		[in]		委托价格(订单类型为市价时，该参数不生效)
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	return				成功返回可申购数量，失败返回<0
*/
ITPDK_API int64 SECITPDK_FXYWTradableQty(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, double lfWtjg, int32 lDdlx, const char* lpGdh);
ITPDK_API int64 SECITPDK_FXYWTradableQtyEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, double lfWtjg, int32 lDdlx);

/*
	LOF业务可委托数量

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		ETF代码
	nJylb		[in]		交易类别(JYLB_JJRG基金认购,JYLB_JJSG基金申购,JYLB_JJSH基金赎回,JYLB_JJFC基金分拆,JYLB_JJHB基金合并)
	lfWtjg		[in]		委托价格(订单类型为市价时，该参数不生效)
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	return				成功返回可申购数量，失败返回<0
*/
ITPDK_API int64 SECITPDK_LOFTradableQty(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, double lfWtjg, int32 lDdlx, const char* lpGdh);
ITPDK_API int64 SECITPDK_LOFTradableQtyEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, double lfWtjg, int32 lDdlx);

/*
	盘后定价可委托数量计算

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		证券代码
	nJylb		[in]		交易类别(JYLB_PHDJMR、JYLB_PHDJMC)
	lfWtjg		[in]		委托价格(订单类型为市价时，该参数不生效)
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	return				成功返回可申购数量，失败返回<0
*/
ITPDK_API int64 SECITPDK_PHDJTradableQty(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, double lfWtjg, int32 lDdlx, const char* lpGdh);
ITPDK_API int64 SECITPDK_PHDJTradableQtyEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, double lfWtjg, int32 lDdlx);

/*
	非交易业务可买卖数量

	lpKhh		[in]		客户号
	lpJys		[in]		交易所
	lpZqdm		[in]		ETF代码
	nJylb		[in]		交易类别(JYLB_ZZZG转债转股、JYLB_ZZHS转债回售、JYLB_YSYY预受要约)
	lfWtjg		[in]		委托价格(订单类型为市价时，该参数不生效)
	lDdlx		[in]		订单类型(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		股东号
	return				成功返回可申购数量，失败返回<0
*/
ITPDK_API int64 SECITPDK_FJYTradableQty(const char* lpKhh, const char* lpJys, const char* lpZqdm, int nJylb, double lfWtjg, int32 lDdlx, const char* lpGdh);
ITPDK_API int64 SECITPDK_FJYTradableQtyEx(ITPDK_CusReqInfo& cusreqinfo, const char* lpJys, const char* lpZqdm, int nJylb, double lfWtjg, int32 lDdlx);

/*
	密码修改

	lpKhh		[in]		客户号
	oldpwd		[in]		旧密码
	newpwd		[in]		新密码
	nType		[in]		修改类型（0 修改交易密码 1 修改资金密码）
	return				成功返回true，失败返回false
*/
ITPDK_API bool SECITPDK_ModifyPwd(const char* lpKhh, const char* oldpwd, const char* newpwd, int nType);

/*
	资金调入

	lpKhh		[in]		客户号
	sJymm		[in]		交易密码
	dFsje		[in]		发生金额
	sZjzh		[in]		资金账号
	sGyh        [in]		柜员号
	sGymm        [in]		柜员密码
	sZy		    [in]		摘要
	return				成功返回>=0，失败返回<0
*/
ITPDK_API int64 SECITPDK_FundTransIn(const char* sKhh, const char* sJymm, double dFsje, const char* sZjzh = nullptr, const char* sGyh = nullptr, const char* sGymm = nullptr, const char* sZy = nullptr);

/*
	资金调出

	lpKhh		[in]		客户号
	sJymm		[in]		交易密码
	dFsje		[in]		发生金额
	sZjzh		[in]		资金账号
	sGyh        [in]		柜员号
	sGymm        [in]		柜员密码
	sZy		    [in]		摘要
	return				成功返回>=0，失败返回<0
*/
ITPDK_API int64 SECITPDK_FundTransOut(const char* sKhh, const char* sJymm, double dFsje, const char* sZjzh = nullptr, const char* sGyh = nullptr, const char* sGymm = nullptr, const char* sZy = nullptr);

/*
	一户两地 - 节点间资金划拨

	lpKhh		[in]		客户号
	sZjzh		[in]		资金账号
	dFsje		[in]		发生金额
	nNode1      [in]        划出节点
	nNode2      [in]        划入节点
	sZy		    [in]		摘要
	return				成功返回>=0，失败返回<0
*/
ITPDK_API int64 SECITPDK_FundTransBetweenNodes(const char* lpKhh, const char* sZjzh, double dFsje, int64 nNode1, int64 nNode2, const char* sZy);

/*
	一户两地 - 划拨策略查询

	lpKhh		[in]		客户号
	sZjzh		[in]		资金账号
	arZJHBCL	[out]		资金划拨策略信息
	return				成功返回>=0，失败返回<0
*/
ITPDK_API int64 SECITPDK_QueryZJHBCL(const char* lpKhh, const char* sZjzh, vector<ZJHBCL>& arZJHBCL);

/*
	一户两地 - 修改资金策略

	lpKhh		[in]		客户号
	lpZjzh		[in]		资金账号
	nNode1      [in]        节点1编号
	nNode2      [in]        节点2编号
	dBL1        [in]        节点1资金比例
	dBL2        [in]        节点2资金比例
	sZy		    [in]		摘要
	return				成功返回>=0，失败返回<0
*/
ITPDK_API int64 SECITPDK_ModifyZJHBCL(const char* lpKhh, const char* lpZjzh, int64 nNode1, int64 nNode2, double dBL1, double dBL2, const char* sZy);

/*
	一户两地 - 节点可划拨资金额度查询

	lpKhh		[in]		客户号
	lpZjzh		[in]		资金账号
	nNode       [in]        节点编号
	dKYZJ       [in]        可用资金
	return				成功返回>=0，失败返回<0
*/
ITPDK_API double SECITPDK_QueryJDKYZJ(const char* lpKhh, const char* lpZjzh, int64 nNode, double dKYZJ);

/*
	连接行情服务器
	lpKeyName	[in]		使用的配置Key值
	return				成功返回true，失败返回false
*/
ITPDK_API bool SECITPDK_OpenQuoteLink(const char* lpKeyName);

/*
	查询行情数据
	jys			[in]		交易所
	zqdm		[in]		证券代码
	buffer		[out]		行情保存buffer
	buffsize	[in]		buffer大小
	return				成功返回true，失败返回false
*/
ITPDK_API bool SECITPDK_GetQuote(const char* jys, const char* zqdm, char* buffer, int buffsize);

