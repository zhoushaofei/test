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
#include "servant/RemoteLogger.h"
#include "event/TimeUtil.h"
#include "jmem/jmem_hashmap.h"
#include "json/json.h"


#include "rapidjson/document.h"
// #include "rapidjson/writer.h"
// #include "rapidjson/stringbuffer.h"

using namespace std;
using namespace taf;

void test()
{
	string txt = TC_File::load2str("json.txt");

	{
		Json::Value root;
		Json::Reader reader;
		if (!reader.parse(txt, root, false))
		{
			LOG_CONSOLE_DEBUG << "parse msg failed|" << txt << endl;
			return;
		}
		cout << root.toStyledString() << endl;
	}

	ProgressTimer t;
	int cnt = 100000;
	for (int i = 0; i < cnt; i++)
	{
		Json::Value root;
		Json::Reader reader;
		reader.parse(txt, root, false);
	}
	cout << "elapsed: " << t.elapse() << "|" << t.elapse()*1000/cnt << endl;

	// // NOTE: 资金账号需要补0
	// string accountId = root["KHH"].asString(); //客户号
	// string entrustId = root["WTH"].asString(); //委托号
	// int64_t requestId = root["KFSBDBH"].asInt64(); //开发商本地编号
	// int nRetCode = root["RETCODE"].asInt(); //处理结果
	// string sRetNote = TC_Encoder::gbk2utf8(root["RETNOTE"].asString()); //处理结果

}

void test_rapidjson()
{
	string txt = TC_File::load2str("json.txt");
	cout << txt << endl;

            // rapidjson::Document document;
            // if (document.Parse(pMsg).HasParseError())   //解析失败
            // {
            //     cout << "Parse confirm message failed." << endl;
            //     return;
            // }

            // long nWTH = (long)document["WTH"].GetInt64();
            // int64 nLSH = document["KFSBDBH"].GetInt64();
            // const char* sKHH = document["KHH"].GetString();
            // const char* sGDH = document["GDH"].GetString();
            // const char* sZQDM = document["ZQDM"].GetString();

	{
		rapidjson::Document document;
		if (document.Parse(txt.c_str()).HasParseError())   //解析失败
		{
			cout << "Parse confirm message failed." << endl;
			return;
		}

		// cout << document.GetString() << endl;
	}

	ProgressTimer t;
	int cnt = 1000000;
	long wth , bh;
	string khh, gdh, zqdm,acc;
	bool hasm;
	for (int i = 0; i < cnt; i++)
	{
		rapidjson::Document document;
		document.Parse(txt.c_str());
		if (i == 0)
		{
			cout << document["WTH"].IsInt() << endl;
			cout << document["WTH"].IsInt64() << endl;
			cout << document["WTH"].IsDouble() << endl;
			cout << document["WTH"].IsString() << endl;
			cout << document["KHH"].IsInt64() << endl;
			cout << document["KHH"].IsString() << endl;

            cout << document["WTH"].GetInt64() << endl;
            cout << document["KFSBDBH"].GetInt64() << endl;
            cout << document["KHH"].GetString() << endl;
            cout << document["GDH"].GetString() << endl;
            cout << document["ZQDM"].GetString() << endl;
            // cout << "RETNOTE=" << document["RETNOTE"].GetString() << endl;
		}
		if (document.HasMember("WTH") && document["WTH"].IsInt64())
		{
            wth= (long)document["WTH"].GetInt64() ;
		}
		if (document.HasMember("KFSBDBH") && document["KFSBDBH"].IsInt64())
            bh = document["KFSBDBH"].GetInt64() ;
		if (document.HasMember("KHH") && document["KHH"].IsString())
            khh = document["KHH"].GetString() ;
		if (document.HasMember("GDH") && document["GDH"].IsString())
            gdh = document["GDH"].GetString() ;
		if (document.HasMember("ZQDM") && document["ZQDM"].IsString())
            zqdm = document["ZQDM"].GetString();
			acc = TC_Common::tostr(wth);
			hasm = document.HasMember("RETNOTE");
	}
	cout << "elapsed: " << t.elapse() << "|" << t.elapse()*1000/cnt << endl;
	cout << acc << "|" << hasm << endl;

	// // NOTE: 资金账号需要补0
	// string accountId = root["KHH"].asString(); //客户号
	// string entrustId = root["WTH"].asString(); //委托号
	// int64_t requestId = root["KFSBDBH"].asInt64(); //开发商本地编号
	// int nRetCode = root["RETCODE"].asInt(); //处理结果
	// string sRetNote = TC_Encoder::gbk2utf8(root["RETNOTE"].asString()); //处理结果

}

int main(int argc, char **argv)
{
	try
	{
		// TC_Option option;
		// option.decode(argc, argv);

		// for(int i = 0; i < argc; i++)
		// {
		// 	cout << "dddddddd|" << argv[i] << endl;
		// }

		// auto map = option.getMulti();
		// for(auto item : map)
		// {
		// 	cout << item.first << "|" << item.second << endl;
		// }
		// auto v = option.getSingle();
		// for(auto item : v)
		// {
		// 	cout << item << endl;
		// }

		ProgressTimer t;
		// test();
		test_rapidjson();
		cout << "elapsed: " << t.elapse() << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    cout << "byebye" << endl;
    return 0;
}