#include <unistd.h>
#include <iostream>
#include <util/tc_common.h>
#include "event/TimeUtil.h"

#include <engine_client_cpp.hpp>

using namespace std;
using namespace taf;

using com::apama::engine::EngineManagement;
using com::apama::engine::EngineStatus;
using com::apama::engine::MonitorScript;
using com::apama::event::EventConsumer;
using com::apama::event::EventSupplier;
using com::apama::event::Event;
using com::apama::EngineException;
using com::apama::event::DisconnectableEventConsumer;

class MyReceiveConsumer : public DisconnectableEventConsumer {
public:
    MyReceiveConsumer(EngineManagement* engine);
    virtual ~MyReceiveConsumer();
    virtual void sendEvents(const Event* const * events);
    virtual void disconnect(const char* reason);

private:
    EngineManagement* engine;
    EventSupplier* supplier;
};

MyReceiveConsumer::MyReceiveConsumer(EngineManagement* eng) : DisconnectableEventConsumer(), engine(eng), supplier(NULL) {
    const char *channels[2] = { "JZ_2C", NULL };
    supplier = engine->connectEventConsumer(this, channels);
}

MyReceiveConsumer::~MyReceiveConsumer() {
    com::apama::event::deleteEventSupplier(supplier);
}

void MyReceiveConsumer::sendEvents(const Event* const * events) {
    static int cnt = 0;
    for (const Event* const * event = events; *event; event++) {
        cout << **event << endl;
        cnt ++;
        if (cnt == 2)
        {
            while ((1))
            {
                cnt = cnt+1;
                // printf("x");
            }
        }
    }
}

void MyReceiveConsumer::disconnect(const char* reason) {
    cout << "Consumer disconnect|" << reason << endl;
}

void test()
{
    const char* emsg = "null";
    EngineManagement* engine = NULL;
    try
    {
        emsg = "Failed to initialise engine library";
        // cout << emsg << endl;
        com::apama::engine::engineInit("engine_client.cpp sample");

        emsg = "Failed to connect to engine";
        // cout << emsg << endl;
        engine = com::apama::engine::connectToEngine("127.0.0.1", 35903);

        emsg = "Event sink connection failed";
        // cout << emsg << endl;
        // MyReceiveConsumer* consumer = new MyReceiveConsumer(engine);

        while (1)
        {
            for(int i=0; i < 10; i++)
            {
                int64_t tm = TNOWMS;
                emsg = "Event sending failed";
                Event* events[2];
                string heartBeatStr = "gats.adapter.trade.astock.EntrustConfirm(\"291013_176463_1604458317\",\"291013_176463_1604458317\",\"0\",\"\",{\"C\":\"" + TC_Common::tostr(TC_Common::now2us()) + "\"})";
                events[0] = com::apama::event::createEvent(heartBeatStr.c_str(), "JZ_2A");
                events[1] = nullptr;
                engine->sendEvents(events);
                com::apama::event::deleteEvent(events[0]);
                cout << TNOWMS-tm << "|" << heartBeatStr << endl;
            }
            TC_Common::msleep(1000);
        }
    }
    catch (EngineException& e) {
        cout << emsg << "|exception:" << e.what() << endl;
    }
    catch (...) {
        cout << emsg << "|unknown exception." << endl;
    }
}

int main()
{
    cout << "hello" << endl;

    ProgressTimer t;
	test();
	cout << "elapsed: " << t.elapse() << endl;

    cout << "byebye" << endl;
    return 0;
}