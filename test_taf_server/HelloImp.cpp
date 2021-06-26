#include "HelloImp.h"
#include "util/tc_common.h"

using namespace std;

taf::Int32 HelloImp::test1(taf::CurrentPtr current)
{
	// LOG_CONSOLE_DEBUG << "HelloImp::test1" << endl;
	return 0;
}

taf::Int32 HelloImp::test2(taf::CurrentPtr current)
{
	LOG_CONSOLE_DEBUG << "HelloImp::test2" << endl;
	TC_Common::msleep(800);
	return 0;
}

taf::Int32 HelloImp::test3(taf::Int32 index,const std::string & s,std::string &r,taf::CurrentPtr current)
{
	LOG_CONSOLE_DEBUG << "HelloImp::test3" << endl;
	r = "test3" + s;
	return 0;
}

taf::Int32 HelloImp::test4(const Test::TestReq & req,Test::TestRsp &rsp,taf::CurrentPtr current)
{
	LOG_CONSOLE_DEBUG << "HelloImp::test4" << endl;
	rsp.msg = "test4" + req.msg;
	return 0;
}
