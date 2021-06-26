// #include "Package.h"
// #include <stdio.h>
// using namespace GWDPApi;


// bool Order(CPackage *oPkt)
// {
// 	//清空发送请求包
// 	oPkt->ClearSendPackage();

//    //设置请求功能号(普通买卖委托)
// 	oPkt->SetFunctionCode("00100030");

//    //设置包头flag
// 	oPkt->SetFlags(0);

// 	//设置请求记录数
// 	oPkt->SetValue(0,"recordCnt","1");

//    //设置柜员代码
// 	oPkt->SetValue(1,"optId","99990");

//    //设置柜员密码
// 	oPkt->SetValue(1,"optPwd","666666");

//    //设置委托方式
// 	oPkt->SetValue(1,"optMode","A1");

//    //设置市场代码
//    	oPkt->SetValue(1,"exchId","0");

//    //设置股东代码
//    	oPkt->SetValue(1,"regId","A012345678");

//    // 设置交易密码
//    oPkt->SetValue(1,"tradePwd","214702");

// 	//设置证券代码
// 	oPkt->SetValue(1,"stkId","600030");

// 	//设置买卖方向
// 	oPkt->SetValue(1,"orderType","B");

// 	//设置委托数量
// 	oPkt->SetValue(1,"orderQty","100");

// 	//设置委托价格
// 	oPkt->SetValue(1,"orderPrice","23.21");

// 	//设置登录Mac地址
// 	oPkt->SetValue(1,"permitMac","E3A4D7CBF6AF");

// 	//和网关交互
// 	if(!oPkt->ExchangeMessage())
// 	{
// 		//交互失败，获取错误代码，错误信息
// 		string strErrCode = oPkt->GetValue(0,"errorCode");
// 		string strErrMsg  = oPkt->GetValue(0,"failinfo") + "\n";
// 		printf(strErrMsg.c_str());
// 		return false;
// 	}

// 	//获取成功失败标志
// 	string strSucc = oPkt->GetValue(0,"successflg");
// 	if(strSucc.compare("0")!=0)
// 	{
// 		//后台返回业务处理失败，获取错误代码、错误信息
// 		string strErrCode = oPkt->GetValue(0,"errorCode");
// 		string strErrMsg  = oPkt->GetValue(0,"failinfo") + "\n";
// 		printf(strErrMsg.c_str());
// 		return false;
// 	}

// 	//处理成功，获取返回参数
// 	//获取返回的记录数
// 	int iRecordCnt = atoi(oPkt->GetValue(0,"recordCnt").c_str());

// 	//获取返回的合同号
// 	string strCotractNum = oPkt->GetValue(1,"contractNum");
//     return true;
// }

// bool QueryKnock(CPackage *oPkt)
// {
// 	//查询序号
// 	int iPackNum = 1;
// 	char szTemp[20] = {0};
// 	while(1)
// 	{
// 		//清空发送请求包
// 		oPkt->ClearSendPackage();

// 		//设置请求功能号(普通买卖委托)
// 		oPkt->SetFunctionCode("00800030");

// 		//设置包头flag
// 		oPkt->SetFlags(0);

// 		//设置请求记录数
// 		oPkt->SetValue(0,"recordCnt","1");

// 		//设置柜员代码
// 		oPkt->SetValue(1,"optId","99990");

// 		//设置柜员密码
// 		oPkt->SetValue(1,"optPwd","666666");

// 		//设置委托方式
// 		oPkt->SetValue(1,"optMode","A1");

// 		//设置资金帐号
// 		oPkt->SetValue(1,"acctId","032400000001");

// 		// 设置交易密码
// 		oPkt->SetValue(1,"tradePwd","214702");

// 		//设置查询排序方式(0-升序/1-降序  2-按occurTime升序)
// 		oPkt->SetValue(1,"sortFlag","0");

// 		//设置查询选择（0-明细（分笔）， 1-按股东汇总，2-按资金帐号汇总,3-按合同号汇总）
// 		oPkt->SetValue(1,"queryType","0");

// 		//设置每次返回的最大记录数（1～500）
// 		oPkt->SetValue(1,"maxRowNum","500");

// 		//设置查询序号（首次查询时为1，查下一页时递加1）
// 		sprintf(szTemp,"%d",iPackNum);
// 		oPkt->SetValue(1,"packNum",szTemp);

// 		//和网关交互
// 		if(!oPkt->ExchangeMessage())
// 		{
// 			//交互失败，获取错误代码，错误信息
// 			string strErrCode = oPkt->GetValue(0,"errorCode");
// 			string strErrMsg  = oPkt->GetValue(0,"failinfo") + "\n";
// 			printf(strErrMsg.c_str());
// 			return false;
// 		}

// 		//获取成功失败标志
// 		string strSucc = oPkt->GetValue(0,"successflg");
// 		if(strSucc.compare("0")!=0)
// 		{
// 			//后台返回业务处理失败，获取错误代码、错误信息
// 			string strErrCode = oPkt->GetValue(0,"errorCode");
// 			string strErrMsg  = oPkt->GetValue(0,"failinfo") + "\n";
// 			printf(strErrMsg.c_str());
// 			return false;
// 		}

// 		iPackNum++;

// 		//处理成功，获取返回参数
// 		//获取返回的记录数
// 		int iRecordCnt = atoi(oPkt->GetValue(0,"recordCnt").c_str());
// 		for(int i=1;i<=iRecordCnt;i++)
// 		{
// 			//获取查询返回的成交信息
// 			//合同号
// 			string strCotractNum = oPkt->GetValue(i,"contractNum");

// 			//成交编号
// 			string strKnockCode = oPkt->GetValue(i,"knockCode");

// 			//成交数量
// 			string strKnockqty = oPkt->GetValue(i,"knockQty");

// 			//成交价格
// 			string strknockPrice = oPkt->GetValue(i,"knockPrice");
// 		}

// 		if(iRecordCnt<500)
// 			break;

// 	}
// 	printf("TestGWDPApi QueryKnock success!\n");
//     return true;
// }

// int  main()
// {

// 	//创建CPackage对象
// 	CPackage* pPkt = CPackage::CreateInstance();
// 	//初始化,不需要每次交互调用，一个对象初始化一次就可以
// 	if(!oPkt->Init())
// 	{
// 		printf("CPackage Init failed!\n");
//        oPkt->ReleaseInstance();
// 		return -1;
// 	}

// 	//订单请求示例：
// 	Order(oPkt);

// 	//查询示例
// 	QueryKnock(oPkt);

// 	//================================================================
// 	//清理运行环境，不需要每次交互后都调用，退出时调用即可
// 	oPkt->UnInit();
//     oPkt->ReleaseInstance();
// }
