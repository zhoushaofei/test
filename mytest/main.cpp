#include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <iostream>
#include <atomic>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <util/tc_thread_pool.h>
#include <util/tc_common.h>
#include <util/tc_thread_queue.h>
#include <util/tc_base64.h>
#include <util/tc_encoder.h>
#include "util/tc_logger.h"
#include "util/tc_file.h"
#include "util/tc_timer.h"
#include "util/tc_config.h"
#include "util/tc_option.h"
#include "servant/RemoteLogger.h"
#include "event/TimeUtil.h"
#include "event/IdGen.h"
#include "jmem/jmem_hashmap.h"
#include "jmem/jmem_hashmap_compact.h"
#include "json/json.h"

using namespace std;
using namespace taf;

void test()
{
    unordered_map<int, int> m;
    m[1] = 11;
    m[3] = 33;
    m[2] = 22;
    m[5] = 55;
    m[4] = 44;

    for (auto & item : m)
    {
        cout << item.first << "=" << item.second << endl;
        m.erase(item.first);
    }
    for (auto & item : m)
    {
        cout << item.first << "=" << item.second << endl;
    }
}

void test2()
{
    {
        TC_Config c;
        for(int i = 0; i < 10000; i++)
        {
            string account_id = TC_Common::tostr(123412341000+i);
            c.set("/main/"+account_id+"/<account_id>", account_id);
            c.set("/main/"+account_id+"/<user_id>", "10086");
            c.set("/main/"+account_id+"/<counter_type>", "JZRD");
            c.set("/main/"+account_id+"/<poststr>", "20201002|123456");
        }
        // // c.insertDomain
        // c.set("/a/<hello>", "1212");
        // c.set("/main/domain/<hello222>", "1212");
        // cout << c.tostr() << endl;

        TC_File::save2file("a.conf", c.tostr());
    }
    // {
    // 	TC_Config c;
    // 	c.parseFile("a.conf");
    // 	cout << c.tostr() << endl;
    // }
}

void testshm()
{
    JceHashMap<string, string, ThreadLockPolicy, ShmStorePolicy> shm;

    shm.initDataBlockSize(100, 1000, 1.2);
    shm.initStore(0x123458, 10*1024*1024);
    shm.setAutoErase(true);

    cout << shm.size() << endl;
    {
        string key(10, 'a');
        string value(10000, 'b');
        int ret = shm.set(key, value);
        cout << "ret=" << ret << endl;
        cout << "key=" << key.size() << "|" << key << endl;
        cout << "value=" << value.size() << "|" << "value" << endl;
    }
    {
        string key(10, 'c');
        string value(10000, 'b');
        int ret = shm.set(key, value);
        cout << "ret=" << ret << endl;
        cout << "key=" << key.size() << "|" << key << endl;
        cout << "value=" << value.size() << "|" << "value" << endl;
    }
    {
        string key(10, 'a');
        string value;
        int ret = shm.get(key, value);
        cout << "ret=" << ret << endl;
        cout << "key=" << key.size() << "|" << key << endl;
        cout << "value=" << value.size() << "|" << "value" << endl;
    }
    {
        string key(10, 'a');
        int ret = shm.del(key);
        cout << "ret=" << ret << endl;
        cout << "key=" << key.size() << "|" << key << endl;
    }
    {
        string key(10, 'a');
        string value;
        int ret = shm.get(key, value);
        cout << "ret=" << ret << endl;
        cout << "key=" << key.size() << "|" << key << endl;
        cout << "value=" << value.size() << "|" << "value" << endl;
    }
    // {
    // 	shm.clear();
    // 	cout << "clear" << endl;
    // }
    {
        string key(10, 'c');
        string value;
        int ret = shm.get(key, value);
        cout << "ret=" << ret << endl;
        cout << "key=" << key.size() << "|" << key << endl;
        cout << "value=" << value.size() << "|" << "value" << endl;
    }
    cout << shm.size() << endl;

    while (true)
    {
        TC_Common::sleep(3);
    }
}

void testtuple()
{
    std::tuple<string,string> aa;
    aa = std::make_tuple("1", "2");
    std::cout << "c contains: " << std::get<0>(aa) << endl;
    std::cout << " and " << std::get<1>(aa) << endl;
}

void test_threadpool()
{
    TC_ThreadPool _threadPool;

    _threadPool.exec([](){
        cout << "11111111112222222222222" << endl;
        TC_Common::msleep(1000);
    });

    _threadPool.exec([](){
        cout << "22222222222222222" << endl;
        TC_Common::msleep(1000);
    });

    _threadPool.exec([](){
        cout << "3333333333333333333" << endl;
        TC_Common::msleep(1000);
    });

    _threadPool.exec([](){
        cout << "44444444444444" << endl;
        TC_Common::msleep(1000);
    });

    _threadPool.exec([](){
        cout << "55555555555555555" << endl;
        TC_Common::msleep(1000);
    });

    TC_Common::msleep(1000);

    //初始化线程池
    _threadPool.init(1);
    _threadPool.start();

    TC_Common::msleep(3000);
    _threadPool.stop();
    TC_Common::msleep(3000);
    TC_Common::msleep(3000);
    cout << "---------- " << _threadPool.getJobNum() << endl;
}

void test_timer()
{
    TC_Timer _timer;
    _timer.postRepeated(10, false, [](){
        LOG_CONSOLE_DEBUG << "11111" << endl;
    });

    //启动定时器
    _timer.startTimer(1);

    while(1)
    {
        TC_Common::msleep(1000);
    }
}

void test_json()
{
    // ifstream ifs("testjson.json");
    // if(!ifs.is_open())
    // {
    // 	cout << "open failed!" << endl;
    // 	return;
    // }

    // Json::Reader reader;
    // Json::Value root;
    // if (!reader.parse(ifs, root, false))
    // {
    // 	cout << "parse failed!" << endl;
    //     return;
    // }
    // ifs.close();

    // std::string name;
    // int age;
    // int size = root.size();
    // for (int i=0; i<size; ++i)
    // {
    //     name = root[i]["a"].asString();
    //     age = root[i]["c"].asInt();
    //     name = root[i]["cxxxxxxxxx"].asInt();

    //     std::cout<<name<<" "<<age<<std::endl;
    // }
}

class A
{
public:
    A(){cout << "A:" << this << endl;}
    ~A(){cout << "~A:" << this << endl;}
};

map<int, A> func()
{
    map<int, A> m;
    m[1] = A();
    cout << &m << "|" << &m[1] << endl;
    return m;
}



void test3()
{
    const map<string,string> &m = {{"aaa","bbb"}};
    cout << "before: " << &m << "|" << m.size() << endl;
    auto func = [&m](){
        cout << "bbbbbb=" << &m << "|" << m.size() << endl;
    };
    func();
    cout << "------------" << endl;

    while(1)
    {
        TC_Common::msleep(1000);
    }
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
        // testshm();
        // test();
        // test2();
        test3();
        // test_timer();
        // test_threadpool();
        cout << "elapsed: " << t.elapse() << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "byebye" << endl;
    return 0;
}