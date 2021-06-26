#pragma once

#include <iostream>
#include "servant/Application.h"
#include "event/EventManager.h"
#include "event/EventInterface.h"
#include "util/tc_timer.h"


using namespace taf;
using namespace ev;

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

public:
    virtual void onEvent(const EventPtr& event);

public:
    IEventListenerPtr _listener;
	TC_Timer _timer;
};

extern TestServer g_app;


////////////////////////////////////////////

