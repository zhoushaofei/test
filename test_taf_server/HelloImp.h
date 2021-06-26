#pragma once


#include "servant/Application.h"
#include "Hello.h"

/**
 *
 *
 */
class HelloImp : public Test::Hello
{
public:
	/**
	 *
	 */
	virtual ~HelloImp() {}

	/**
	 *
	 */
	virtual void initialize() {};

	/**
	 *
	 */
    virtual void destroy() {};

	/**
	 *
	 */
    virtual taf::Int32 test1(taf::CurrentPtr current);
    virtual taf::Int32 test2(taf::CurrentPtr current);
    virtual taf::Int32 test3(taf::Int32 index,const std::string & s,std::string &r,taf::CurrentPtr current);
    virtual taf::Int32 test4(const Test::TestReq & req,Test::TestRsp &rsp,taf::CurrentPtr current);
};

