#include <unistd.h>
#include <iostream>
#include <atomic>
#include <unordered_set>
#include <unordered_map>
#include <util/tc_thread_pool.h>
#include <util/tc_common.h>
#include <util/tc_thread_queue.h>
#include <util/tc_base64.h>
#include <util/tc_encoder.h>
#include "util/tc_logger.h"
#include "util/tc_file.h"
#include "util/tc_config.h"
#include "util/tc_option.h"
#include "util/tc_timer.h"
#include "servant/RemoteLogger.h"
#include "event/TimeUtil.h"
#include "jmem/jmem_hashmap.h"

#include "Package.h"

using namespace std;
using namespace taf;
using namespace GWDPApi;


bool Order(CPackage *oPkt)
{
	LOG_CONSOLE_DEBUG << "2222222" << endl;
	//清空发送请求包
	oPkt->ClearSendPackage();
	LOG_CONSOLE_DEBUG << "2222222" << endl;

   //设置请求功能号(普通买卖委托)
	oPkt->SetFunctionCode("00100030");
	LOG_CONSOLE_DEBUG << "2222222" << endl;

   //设置包头flag
	oPkt->SetFlags(0);
	LOG_CONSOLE_DEBUG << "2222222" << endl;

	//设置请求记录数
	oPkt->SetValue(0,"recordCnt","1");
	LOG_CONSOLE_DEBUG << "2222222" << endl;

   //设置柜员代码
	oPkt->SetValue(1,"optId","99990");

   //设置柜员密码
	oPkt->SetValue(1,"optPwd","666666");

   //设置委托方式
	oPkt->SetValue(1,"optMode","A1");

   //设置市场代码
   	oPkt->SetValue(1,"exchId","0");
	LOG_CONSOLE_DEBUG << "2222222" << endl;

   //设置股东代码
   	oPkt->SetValue(1,"regId","A012345678");

   // 设置交易密码
   oPkt->SetValue(1,"tradePwd","214702");

	//设置证券代码
	oPkt->SetValue(1,"stkId","600030");

	//设置买卖方向
	oPkt->SetValue(1,"orderType","B");

	//设置委托数量
	oPkt->SetValue(1,"orderQty","100");

	//设置委托价格
	oPkt->SetValue(1,"orderPrice","23.21");

	//设置登录Mac地址
	bool ree = oPkt->SetValue(1,"permitMac","E3A4D7CBF6AF");
	LOG_CONSOLE_DEBUG << "ree=" << ree << endl;
	LOG_CONSOLE_DEBUG << "2222222111111111" << endl;

	//和网关交互
	if(!oPkt->ExchangeMessage())
	{
	LOG_CONSOLE_DEBUG << "2222222111111111" << endl;
		//交互失败，获取错误代码，错误信息
		const char* pp = oPkt->GetValue(0,"errorCode");
		cout << "p=" << (void*)pp << endl;
	LOG_CONSOLE_DEBUG << "2222222111111111333333333" << endl;
		// string strErrMsg  = oPkt->GetValue(0,"failinfo") + string("\n");
		// printf(strErrMsg.c_str());
		const char* p = oPkt->GetValue(0,"failinfo");
		cout << "p=" << (void*)p << endl;
		return false;
	}

	LOG_CONSOLE_DEBUG << "2222222111111111" << endl;
	//获取成功失败标志
	string strSucc = oPkt->GetValue(0,"successflg");
	LOG_CONSOLE_DEBUG << "2222222111111111" << endl;
	if(strSucc.compare("0")!=0)
	{
		// //后台返回业务处理失败，获取错误代码、错误信息
		// string strErrCode = oPkt->GetValue(0,"errorCode");
		// string strErrMsg  = oPkt->GetValue(0,"failinfo") + "\n";
		// printf(strErrMsg.c_str());
		return false;
	}

	//处理成功，获取返回参数
	//获取返回的记录数
	// int iRecordCnt = atoi(oPkt->GetValue(0,"recordCnt").c_str());

	//获取返回的合同号
	string strCotractNum = oPkt->GetValue(1,"contractNum");
    return true;
}

void test()
{

	//创建CPackage对象
	CPackage* pkg = CPackage::CreateInstance();

	cout << pkg->GetVersion() << endl;

	//初始化,不需要每次交互调用，一个对象初始化一次就可以
	if(!pkg->Init())
	{
		cout << "CPackage Init failed!" << endl;
       	// pkg->ReleaseInstance();
		// return;
	}

	cout << "pkg init done!" << endl;

	Order(pkg);

	cout << "2222222" << endl;

	while (1)
	{
		TC_Common::msleep(1000);
	}


	pkg->UnInit();
    pkg->ReleaseInstance();
}


int main(int argc, char **argv)
{
	try
	{
		test();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    cout << "byebye" << endl;
    return 0;
}