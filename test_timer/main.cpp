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

using namespace std;
using namespace taf;


struct AAA
{
	AAA(){cout << "AAA" << endl;};
	~AAA(){cout << "~AAA" << endl;};
	int xxx = 100;
};

void fff(const std::shared_ptr<AAA>& ppp)
{
	cout << "ppp=" << &ppp << endl;
	cout << "ppp.get=" << ppp.get() << endl;
	cout << ppp->xxx << "|" << &ppp->xxx << endl;
}

int main(int argc, char **argv)
{
	try
	{
		// {
		// 	TC_ThreadPool _threadPool;
		// 	_threadPool.init(1);
		// 	_threadPool.start();
		// 	std::shared_ptr<AAA> pa = std::make_shared<AAA>();
		// 	_threadPool.exec(std::bind(fff, pa));
		// 	getchar();
		// }
		{
			TC_Timer timer;
			timer.startTimer(1);
			// {
				std::shared_ptr<AAA>  pa = std::make_shared<AAA>();
				cout << "ppp=" << &pa << endl;
				cout << pa->xxx << "|" << &pa->xxx << endl;
				auto func = [pa](){
					fff(pa);
				};
				// timer.postDelayed(100, fff, pa);
				// std::thread(std::bind(fff, pa)).detach();

				// NOTE: 以下两种调用方式传递的pa.get()是nullptr，不正常
				timer.postDelayed(100, [pa](){
					cout << &pa << endl;
					cout << pa << endl;
					cout << pa.get() << endl;
					// fff(pa);
				});
				// timer.postDelayed(100, std::bind(fff, pa));
			// }
			getchar();
		}

		cout << "dddddd" << endl;
		while(1)
		{
			TC_Common::msleep(1000);
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    cout << "byebye" << endl;
    return 0;
}