#include "util/tc_common.h"
#include "servant/Communicator.h"
#include "../test_taf_server/Hello.h"

using namespace std;
using namespace taf;
using namespace Test;

int64_t tmstart = 0;
int64_t tm111 = 0;
int count111 = 100;
atomic_int cnt = {0};

class MyHelloPrxCallback : public HelloPrxCallback
{
public:
    MyHelloPrxCallback(int idx)
    {
        _idx = idx;
    }

 	virtual void callback_test1(taf::Int32 ret)
    {
		// LOG_CONSOLE_DEBUG << "callback_test1|ret=" << ret << "|idx=" << _idx << endl;
		cnt++;
		if (cnt == 1)
		{
			tm111 = TC_Common::now2us() - tmstart;
		}
		else if (cnt == count111)
		{
			int tm1 = TC_Common::now2us() - tmstart;
			LOG_CONSOLE_DEBUG << "callback_test1|cnt=" << count111 << "|tm=" << tm1 << "|" << tm1*1.0/count111 << "|tm111=" << tm111 << endl;
		}
	}
    virtual void callback_test1_exception(taf::Int32 ret)
    {
		LOG_CONSOLE_DEBUG << "callback_test1_exception|ret=" << ret << "|idx=" << _idx << endl;
	}

 	virtual void callback_test2(taf::Int32 ret)
    {
		LOG_CONSOLE_DEBUG << "callback_test2|ret=" << ret << "|idx=" << _idx << endl;
	}
    virtual void callback_test2_exception(taf::Int32 ret)
    {
		LOG_CONSOLE_DEBUG << "callback_test2_exception|ret=" << ret << "|idx=" << _idx << endl;
	}

private:
    int _idx;
};


void test()
{
	Communicator::getInstance()->setProperty("async-invoke-timeout", "5000");

    string obj = "Test.TestServer.TestObj@tcp -h 127.0.0.1 -t 60000 -p 20002";
    // string obj = "Test.TestServer.TestObj@tcp -h 10.1.84.130 -t 60000 -p 20002";
	HelloPrx prx = Communicator::getInstance()->stringToProxy<HelloPrx>(obj);

	prx->taf_ping();
	TC_Common::msleep(1000);


	// TC_Common::msleep(1000);
	// int64_t t1 = TC_Common::now2us();
	// prx->test1();
 	// LOG_CONSOLE_DEBUG << "test1|tm=" << TC_Common::now2us()-t1 << endl;

	// TC_Common::msleep(1000);
	// t1 = TC_Common::now2us();
	// prx->test1();
 	// LOG_CONSOLE_DEBUG << "test1|tm=" << TC_Common::now2us()-t1 << endl;

	// TC_Common::msleep(1000);
	// t1 = TC_Common::now2us();
	// prx->async_test1(new MyHelloPrxCallback(0));
 	// LOG_CONSOLE_DEBUG << "async_test1|tm=" << TC_Common::now2us()-t1 << endl;

	// TC_Common::msleep(1000);
	// t1 = TC_Common::now2us();
	// prx->async_test1(new MyHelloPrxCallback(0));
 	// LOG_CONSOLE_DEBUG << "async_test1|tm=" << TC_Common::now2us()-t1 << endl;

	// LOG_CONSOLE_DEBUG << "test2" << endl;
	// for (int i = 0; i < 10; i++)
	// {
	// 	getchar();
	// 	prx->async_test2(new MyHelloPrxCallback(i));
	// }
	// LOG_CONSOLE_DEBUG << "done" << endl;

	// {
	// 	count111 = 10000;
	// 	tmstart = TC_Common::now2us();
	// 	for (int i = 0; i < count111; i++)
	// 	{
	// 		prx->test1();
	// 	}
	// 	int tm1 = TC_Common::now2us() - tmstart;
	// 	LOG_CONSOLE_DEBUG << "done|cnt=" << count111 << "|tm=" << tm1 << "|" << tm1*1.0/count111 << endl;
	// }

	{
		tmstart = TC_Common::now2us();
		for (int i = 0; i < count111; i++)
		{
			// prx->async_test1(new MyHelloPrxCallback(i));
			prx->async_test1(nullptr);
			// prx->test1();
		}
		int tm1 = TC_Common::now2us() - tmstart;
		LOG_CONSOLE_DEBUG << "done|cnt=" << count111 << "|tm=" << tm1 << "|" << tm1*1.0/count111 << endl;
	}

	while (1)
	{
		TC_Common::msleep(1000);
	}
}

int main()
{
	try
	{
		test();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
