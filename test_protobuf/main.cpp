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

#include "test.pb.h"

using namespace std;
using namespace taf;

// using namespace Protocol;
// using namespace Protocol::Protobuf;
// using namespace google::protobuf::io;

void test()
{
	Example1 example1;
    example1.set_stringval("hello,world");
    example1.set_bytesval("are you ok?");

    // Example1_EmbeddedMessage *embeddedExample2 = new Example1_EmbeddedMessage();

    // embeddedExample2->set_int32val(1);
    // embeddedExample2->set_stringval("embeddedInfo");
    // example1.set_allocated_embeddedexample1(embeddedExample2);

    example1.add_repeatedint32val(2);
    example1.add_repeatedint32val(3);
    example1.add_repeatedstringval("repeated1");
    example1.add_repeatedstringval("repeated2");

	// example1.to
	char buf[1024] = {0};
	int pblen = example1.ByteSize();
	if (!example1.SerializeToArray(buf, 1024))
	{
        std::cerr << "Failed to write example1." << std::endl;
    }

	cout << "done|" << pblen << endl;
}


int main(int argc, char **argv)
{
	try
	{
		ProgressTimer t;
		test();
		cout << "elapsed: " << t.elapse() << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    cout << "byebye" << endl;
    return 0;
}