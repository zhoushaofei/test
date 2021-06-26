#include "util/tc_common.h"
#include "servant/Communicator.h"
#include "event/TimeUtil.h"

#include "/home/upchina/zhoushaofei/sdkframe/project/lib/proto/MQApi.h"

using namespace std;
using namespace taf;
using namespace ht;

int main()
{
	try
	{
	    Communicator::getInstance()->setProperty("locator", "taf.tafregistry.QueryObj@tcp -h 172.16.8.38 -p 17890");

		string topic = TC_Common::now2str();
		LOG_CONSOLE_DEBUG << "topic=" << topic << endl;

		MQApiPrx prx = Communicator::getInstance()->stringToProxy<MQApiPrx>("sf.MQBrokerServer.MQBrokerTafObj");

		//TC_Common::msleep(1000);

		ProgressTimer t;

		SendMsgReq req;
		SendMsgRsp rsp;

		req.msg.topic = topic;
		req.msg.uuid = "test-uuid";
		req.msg.msgType = "test-msgType";
		req.msg.content = {'a','b','c'};

		int count = 10000;
		for (int i = 0; i < count; i++)
		{
			req.msg.uuid = "test-uuid-" + TC_Common::tostr(i);
			std::size_t hash = std::hash<std::string>{}("111111");
			prx->taf_hash(hash)->async_sendMsg(nullptr, req);
			// prx->async_sendMsg(nullptr, req);
		}

		LOG_CONSOLE_DEBUG << "test done, elapsed=" << t.elapse() << endl;

		//while (1)
		{
			TC_Common::msleep(3000);
		}
	}
	catch(const std::exception& e)
	{
	}

	return 0;
}
