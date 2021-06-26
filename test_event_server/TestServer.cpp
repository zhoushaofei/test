#include "TestServer.h"
#include "Hello.h"

using namespace std;
using namespace Test;

TestServer g_app;


DECLARE_EVENT(TestDummy, Event, EN_TEST_DUMMY, EventTestDummy)
DECLARE_EVENT(TestReq, EventReq, EN_TEST_REQ, EventTestReq)
DECLARE_EVENT(TestRsp, EventRsp, EN_TEST_RSP, EventTestRsp)



// 事件处理
class MyEventListener : public IEventListener
{
public:
    MyEventListener(TestServer* manager)
        : IEventListener("MyEventListener"), _manager(manager)
    {
		cout << "MyEventListener" << endl;
    }
    virtual ~MyEventListener()
    {
		cout << "~MyEventListener" << endl;
    }
    virtual void onEvent(const EventPtr& event)
    {
		cout << "11111111" << endl;
        if (_manager)
        {
            _manager->onEvent(event);
        }
    }
private:
    TestServer* _manager = nullptr;
};


void TestServer::onEvent(const EventPtr& event)
{
	cout << event->baseInfo() << endl;
	cout << "------------------------" << endl;

	// cout << event->getClientId() << endl;
	// DEFAULT_EVENT_SERVER->forceClose(event->getClientId());

	if (event->getEventName() == EN_TEST_DUMMY)
	{
	}
}


void TestServer::onServerConfig()
{
    //启用协程
    ServerConfig::OpenCoroutine = true;
}

void TestServer::initialize()
{
    //事件端口
    addServant<ev::EventImp>(ServerConfig::Application + "." + ServerConfig::ServerName + ".TestEventObj");
    addServantProtocol(ServerConfig::Application + "." + ServerConfig::ServerName + ".TestEventObj", &ev::RemoteAsyncEventBuilder::parseAsyncEvent);

    EventManager::getInstance()->init();

    EventManager::getInstance()->setLogLevel("DEBUG");

	_listener = new MyEventListener(this);

	// for (int i = 0; i < 99; i++)
	// {
	// 	DEFAULT_EVENT_SERVER->subscribeAsync("threadName", _listener, i);
	// }


    // DEFAULT_EVENT_SERVER->subscribeAsync("threadName", _listener, EN_CLIENT_CLOSE);

	// DEFAULT_EVENT_SERVER->subscribeAsync("threadName", _listener, EN_TEST_DUMMY);
	// DEFAULT_EVENT_SERVER->subscribeAsync("threadName", _listener, EN_TEST_REQ);
	// DEFAULT_EVENT_SERVER->subscribeAsync("threadName", _listener, EN_TEST_RSP);

	//订阅事件回调
	DEFAULT_EVENT_SERVER->setSubscribeCallback([](const EVSubscribe& eventData){
		LOG_CONSOLE_DEBUG << eventData << endl;
	});

	_timer.startTimer(1);
	_timer.postDelayed(5000, [this](){
        // EventPtr event = CREATE_EVENT(EN_TEST_DUMMY, "", "");
        // event->getObject<TestDummy>().msg = "bbbbbb";
		// DEFAULT_EVENT_SERVER->sendRemoteEvent(event);
		// cout << event->baseInfo() << endl;
        // cout << "send, ev=" << event->getEventName() << "|msg=" << event->getObject<TestDummy>().msg << endl;
	});
}
/////////////////////////////////////////////////////////////////
void
TestServer::destroyApp()
{
}


/////////////////////////////////////////////////////////////////
int
main(int argc, char* argv[])
{
	try
	{
		g_app.main(argc, argv);
        g_app.waitForShutdown();
	}
	catch (std::exception& e)
	{
		cerr << "std::exception:" << e.what() << std::endl;
	}
	catch (...)
	{
		cerr << "unknown exception." << std::endl;
	}
	return -1;
}

