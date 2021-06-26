#include <iostream>
#include <module/plugininc.h>
#include <module/pluginimpl.h>
#include <module/modulemacro.h>
#include "myplugin.h"

using namespace std;


XBEGIN_DEFINE_MODULE()
    // XDEFINE_CLASSMAP_ENTRY(MyPlugin)
XEND_DEFINE_MODULE_DLL()

OUTAPI bool x3InitializePlugin()
{
    cout << "x3InitializePlugin" << endl;
    return true;
}

OUTAPI void x3UninitializePlugin()
{
    cout << "~~~ x3UninitializePlugin" << endl;
}

// MyPlugin::MyPlugin()
// {

// }

// MyPlugin::~MyPlugin()
// {

// }

// int MyPlugin::add(int a, int b) const
// {
//     cout << a << "+" << b << "=" << a+b << endl;

//     return 123;
// }