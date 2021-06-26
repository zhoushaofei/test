#pragma once

#include <iostream>
#include "servant/Application.h"


using namespace taf;

/**
 *
 **/
class TestServer : public Application
{
public:
	/**
	 *
	 **/
	virtual ~TestServer() {};

	/**
	 *
	 **/
	virtual void initialize();

	/**
	 *
	 **/
	virtual void destroyApp();
	virtual void onServerConfig();
};

extern TestServer g_app;


////////////////////////////////////////////

