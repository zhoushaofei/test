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
#include "event/EventManager.h"
#include "event/TimeUtil.h"
#include "jmem/jmem_hashmap.h"

// #include "../test_event_server/Hello.h"

using namespace std;
using namespace taf;
using namespace ht;
// using namespace Test;



// DECLARE_EVENT(TestDummy, Event, EN_TEST_DUMMY, EventTestDummy)
// DECLARE_EVENT(TestReq, EventReq, EN_TEST_REQ, EventTestReq)
// DECLARE_EVENT(TestRsp, EventRsp, EN_TEST_RSP, EventTestRsp)




class AsyncListener : public IEventListener
{
public:
    AsyncListener(string name) : IEventListener("AsyncListener") {};

    virtual void onEvent(const EventPtr& event)
    {
        if (event->getEventName() == EN_SUBSCRIBE_RSP)
        {
            EVSubscribe& object = event->getObject<EVSubscribe>();
            LOG_CONSOLE_DEBUG << "subscribe succ object:" << object << endl;
        }
        cout << event->baseInfo() << endl;
        cout << "------------------------" << endl;
    }
};


int main(int argc, char **argv)
{
	try
	{
        EventManager::getInstance()->setLogLevel("DEBUG");

        auto func = [](bool isConnected, const TC_Endpoint& ep){
            LOG_CONSOLE_DEBUG << "isConnected=" << isConnected << "|ep=" << ep.toString() << endl;
        };

        // auto client = RemoteEventClient::createClient("Test.TestServer.TestEventObj@tcp -h 127.0.0.1 -p 23502", func);
        // auto client = RemoteEventClient::createClient("ht.JZApamaMatchServer.JZApamaMatchObj@tcp -h 172.16.8.24 -t 60000 -p 10030", func);
        // auto client = RemoteEventClient::createClient("ht.JZApamaMatchServer.JZApamaMatchObj@tcp -h 10.1.82.188 -t 60000 -p 10016", func);
        auto client = RemoteEventClient::createClient("sf.MQAccessServer.MQAccessObj@tcp -h 172.16.8.24 -t 60000 -p 10064", func);

        IEventListenerPtr listener = new AsyncListener("AsyncListener");

        client->subscribeAsync("threadName", listener, EN_SUBSCRIBE_RSP);
        client->subscribeAsync("threadName", listener, 10260, "JZ1");

        getchar();

        client->subscribeAsync("threadName", listener, 10260, "JZ1");
        client->subscribeAsync("threadName", listener, 10260, "JZ2");

        // getchar();

        auto infos = client->getSubscribeInfAll();

        for (auto item : infos)
        {
            cout << item.eventName << "|" << item.tag << "|" << item.resName << endl;
        }

        getchar();

        cout << "unsubscribe 1" << endl;
        client->unsubscribe(listener, 10260, "JZ1");
        client->unsubscribe(listener, 10260, "JZ3");
        cout << "unsubscribe 2" << endl;

        getchar();

        // getchar();

        infos = client->getSubscribeInfAll();

        for (auto item : infos)
        {
            cout << item.eventName << "|" << item.tag << "|" << item.resName << endl;
        }

        getchar();


        cout << "forceClose" << endl;
        client->forceClose();
        getchar();



        TC_Common::msleep(1000);
        cout << "1111111111111" << endl;
        client->clear();


        TC_Common::msleep(1000);
        cout << "2222222222222" << endl;
        // client->subscribeAsync("threadName", listener, 10260, "JZ_104000-080909002010");

        // for (int i = 0; i < 99; i++)
        // {
        //     client->subscribeAsync("threadName", listener, i);
        // }

        // client->subscribeAsync("threadName", listener, EN_CLIENT_CLOSE);
        // client->subscribeAsync("threadName", listener, EN_SUBSCRIBE_RSP);
        // client->subscribeAsync("threadName", listener, EN_ATTACH);
        // client->subscribeAsync("threadName", listener, EN_ATTACH_RSP);

        // client->subscribeAsync("threadName", listener, EN_TEST_DUMMY);
        // client->subscribeAsync("threadName", listener, EN_TEST_REQ);
        // client->subscribeAsync("threadName", listener, EN_TEST_RSP);

        // client->attach("abc");
        // // client->attach("def");

        // getchar();

        // client->clear();
        // client->forceClose();

        // getchar();
        // client->unsubscribe(listener, EN_TEST_DUMMY);
        // client->unsubscribe(listener, EN_TEST_REQ);
        // client->unsubscribe(listener, EN_TEST_RSP);
        // getchar();

        // EventPtr event = CREATE_EVENT(EN_TEST_DUMMY, "", "ass");
        // event->getObject<TestDummy>().msg = "aaaaaaa";
        // client->sendRemoteEvent(event);
		// cout << event->baseInfo() << endl;
        // cout << "send, ev=" << event->getEventName() << "|msg=" << event->getObject<TestDummy>().msg << endl;

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