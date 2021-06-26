#include "util/tc_common.h"
#include "servant/Communicator.h"
#include "../test_taf_server/Hello.h"

using namespace std;
using namespace taf;
using namespace Test;

int main()
{
	int ret;
	string str;

    // string obj = "Base.WupProxyServer.WupProxyObj@tcp -h 10.1.84.117 -t 60000 -p 4509";
	// string obj = "test_wup@tcp -h 10.1.84.117 -t 60000 -p 4509";
	// string obj = "Test.TestServer.TestObj@tcp -h 10.8.17.58 -t 60000 -p 10012";

	string obj = "Test.TestServer.TestObj";
    Communicator::getInstance()->setProperty("locator", "taf.tafregistry.QueryObj@tcp -h 10.8.17.27 -p 17890");
    auto prx = Communicator::getInstance()->stringToProxy<HelloPrx>(obj);
    ret = prx->test3(0, "sbuff", str);

	// prx->taf_set_protocol(ServantProxy::PROTOCOL_HTTP_JCE, 5);


    // map<string, string> context;
    // context[":path"] = "/wup";

	// cout << "test1" << endl;

    // prx->test3(0, "sbuff", str, context);

    cout << "ret=" << ret << endl;
    cout << "str=" << str << endl;

    cout << "333333333" << endl;
	// cout << req << endl;
	// cout << rsp << endl;

	cout << "done" << endl;
	return 0;
}
