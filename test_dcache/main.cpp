#include "util/tc_option.h"
#include "util/tc_timer.h"
#include <iostream>
#include "event/TimeUtil.h"
#include "Proxy.h"
#include "servant/Communicator.h"

using namespace taf;
using namespace DCache;

std::atomic_int cnt_ok{0};
std::atomic_int cnt_fail{0};

TC_Option option;

class TestCallback : public ProxyPrxCallback
{
public:
    TestCallback(string key, int valueSize)
    {
        _key = key;
        _valueSize = valueSize;
        _startMs = TNOWMS;
    }

    virtual void callback_setStringEx(taf::Int32 ret)
    {
        if (ret != DCache::ET_SUCC)
        {
            // int64_t elapsed = TNOWMS - _startMs;
            // cout << "setStringEx failed|" << ret << "|" << _key << "|" << _valueSize << "|" << elapsed << endl;
            cnt_fail++;
        }
        else
        {
            // int64_t elapsed = TNOWMS - _startMs;
            // cout << "setStringEx succ|" << ret << "|" << _key << "|" << _valueSize << "|" << elapsed << endl;
            cnt_ok++;
        }
    }

    virtual void callback_setStringEx_exception(taf::Int32 ret)
    {
        // int64_t elapsed = TNOWMS - _startMs;
        // cout << "callback_setStringEx_exception|" << ret << "|" << _key << "|" << _valueSize << "|" << elapsed << endl;
    }

private:
    string _key;
    int _valueSize;
    int64_t _startMs;
};

void test_set_batch_sync()
{
    string key = "TEST-001";
    // string value("hello");
    string value(1000, 'a');

    string obj = "DCache.htProxyServer.ProxyObj@tcp -h 172.16.8.24 -t 60000 -p 34195";
    string moudle = "htTestNoDB";
    ProxyPrx prx = Communicator::getInstance()->stringToProxy<ProxyPrx>(obj);
    int count = 2000;

    ProgressTimer t;
    for (int i = 0; i < count; i++)
    {
        // key = "TEST-" + TC_Common::now2str() + "-" + TC_Common::tostr(i);
        // key = "TEST-" + TC_Common::tostr(i);
        key = "TEST-001";
        int ret = prx->setStringEx(moudle, key, value, 0, false, TNOW + 24*3600);
        if (ret != DCache::ET_SUCC)
        {
            cout << "setStringEx111 failed|" << ret << "|" << key << "|" << value.length() << "|" << t.elapse() << endl;
            cnt_fail++;
        }
        else
        {
            cnt_ok++;
        }
    }

    cout << "test_set_batch_sync done|count=" << count << "|ok=" << cnt_ok << "|fail=" << cnt_fail << "|" << t.elapse() << endl;

    while (1)
    {
        TC_Common::msleep(1000);
    }
}

void test_set_batch_async()
{
    string obj = "DCache.htProxyServer.ProxyObj@tcp -h 172.16.8.24 -t 60000 -p 34195";
    string moudle = "htTestNoDB";

    ProxyPrx prx = Communicator::getInstance()->stringToProxy<ProxyPrx>(obj);
    int count = 100;

    ProgressTimer t;
    for (int i = 0; i < count; i++)
    {
        {
            // string key = "TEST-" + TC_Common::now2str() + "-" + TC_Common::tostr(i);
            // string key = "TEST-" + TC_Common::tostr(i);
            string key = "TEST-111";
            string value = TC_Common::tostr(i);
            ProxyPrxCallbackPtr cb = new TestCallback(key, value.length());
            prx->async_setStringEx(cb, moudle, key, value, 0, false, TNOW + 24*3600);
        }
        // {
        //     // string key = "D1-" + TC_Common::now2str() + "-" + TC_Common::tostr(i);
        //     string key = "D1-" + TC_Common::tostr(i);
        //     string value(150, 'a');
        //     ProxyPrxCallbackPtr cb = new TestCallback(key, value.length());
        //     prx->async_setStringEx(cb, moudle, key, value, 0, false, TNOW + 24*3600);
        // }
        // {
        //     // string key = "D2-" + TC_Common::now2str() + "-" + TC_Common::tostr(i);
        //     string key = "D2-" + TC_Common::tostr(i);
        //     string value(150, 'a');
        //     ProxyPrxCallbackPtr cb = new TestCallback(key, value.length());
        //     prx->async_setStringEx(cb, moudle, key, value, 0, false, TNOW + 24*3600);
        // }
        // {
        //     // string key = "D3-" + TC_Common::now2str() + "-" + TC_Common::tostr(i);
        //     string key = "D3-" + TC_Common::tostr(i);
        //     string value(150, 'a');
        //     ProxyPrxCallbackPtr cb = new TestCallback(key, value.length());
        //     prx->async_setStringEx(cb, moudle, key, value, 0, false, TNOW + 24*3600);
        // }
        // {
        //     // string key = "D4-" + TC_Common::now2str() + "-" + TC_Common::tostr(i);
        //     string key = "D4-" + TC_Common::tostr(i);
        //     string value(150, 'a');
        //     ProxyPrxCallbackPtr cb = new TestCallback(key, value.length());
        //     prx->async_setStringEx(cb, moudle, key, value, 0, false, TNOW + 24*3600);
        // }

        // if (i%50000==0 && i > 0)
        // {
        //     TC_Common::msleep(1000);
        //     cout << i << "|ok=" << cnt_ok << "|fail=" << cnt_fail << "|" << t.elapse() << endl;
        // }
    }

    // cout << "test_set_batch_async done|count=" << count << "|ok=" << cnt_ok << "|fail=" << cnt_fail << "|" << t.elapse() << endl;

    while (1)
    {
        TC_Common::msleep(1000);
        cout << "test_set_batch_async done|count=" << count << "|ok=" << cnt_ok << "|fail=" << cnt_fail << "|" << t.elapse() << endl;
    }
}

int main(int argc, char *argv[])
{
    try
    {
        option.decode(argc, argv);

        // if (option.hasParam("async"))
        {
            test_set_batch_async();
        }
        // else
        // {
            // test_set_batch_sync();
        // }
    }
    catch (std::exception& e)
    {
        cout << "exception:" << e.what() << endl;
    }
    catch (...)
    {
        cout << "unknown exception." << endl;
    }

    return 0;
}
