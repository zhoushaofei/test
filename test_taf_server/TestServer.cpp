#include "TestServer.h"
#include "HelloImp.h"

using namespace std;
using namespace Test;

TestServer g_app;


void TestServer::onServerConfig()
{
    //启用协程
    // ServerConfig::OpenCoroutine = true;
}

void TestServer::initialize()
{
    //taf servant
    addServant<HelloImp>(ServerConfig::Application + "." + ServerConfig::ServerName + ".TestObj");
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

