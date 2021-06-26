#include <iostream>

// x3py framework: https://github.com/rhcad/x3py
// 1: use multiple plugins, 2: use one plugin, 3: raw loading mode
// 4: use static library plugin, 5: find and load plugins
//
#ifndef LOADMODE
#define LOADMODE  1
#endif

int test();

//---------------------------------------------------------------
#if   LOADMODE==1   // use multiple plugins: plugins/*.pln
//---------------------------------------------------------------

#include <portability/x3port.h>
#include <nonplugin/useplugins.h>

int main()
{
    std::cout << "11111111" << std::endl;
    const char* plugins[] = {
        "x3manager.pln", "plsimple.pln", NULL
    };
    std::cout << "22222" << std::endl;
    x3::AutoLoadPlugins autoload(plugins, "plugins");
    std::cout << "333333" << std::endl;

    return test();
}

//---------------------------------------------------------------
#elif LOADMODE==2   // use only one plugin: plugins/plsimple.pln
//---------------------------------------------------------------

#include <portability/x3port.h>
#define PLUGIN_PATH  "plugins/"
#define PLUGIN_NAME  "plsimple"
#include <nonplugin/useplugin.h>

int main()
{
    return test();
}

//---------------------------------------------------------------
#elif LOADMODE==3   // raw loading mode
//---------------------------------------------------------------

#include <portability/portimpl.h>

HMODULE modules[10] = { NULL };

int main()
{
    const char* plugins[] = {
        "plugins/x3manager.pln",
        "plugins/plsimple.pln",
        "plugins/observerex.pln",
        NULL
    };
    int count = 0;

    for (int i = 0; plugins[i]; i++)
    {
        modules[count] = x3LoadLibrary(plugins[i]);
        if (modules[count])
            count++;
    }

    int ret = test();

    while (--count >= 0)
    {
        x3FreeLibrary(modules[count]);
    }

    return ret;
}

namespace x3 {
class IObject;
bool createObject(const char* clsid, long iid, IObject** p)
{
    typedef bool (*F)(const char*, long, IObject**);
    F f = (F)GetProcAddress(modules[0], "x3CreateObject");
    return f && f(clsid, iid, p);
}
} // x3

//---------------------------------------------------------------
#elif LOADMODE==4   // use static library plugin
//---------------------------------------------------------------

#include <portability/x3port.h>
#include <module/pluginimpl.h>
#define XUSE_LIB_PLUGIN
#include <module/modulemacro.h>
XDEFINE_EMPTY_MODULE()

#ifdef _MSC_VER
#pragma comment(lib, "libpln1.lib")
#endif

extern const x3::ClassEntry* const classes_libpln1;

const x3::ClassEntry* const x3::ClassEntry::classes[] = {
        s_classes, classes_libpln1, NULL
    };

int main()
{
    return test();
}

//---------------------------------------------------------------
#elif LOADMODE==5   // find and load plugins
//---------------------------------------------------------------

#include <portability/x3port.h>
#include <nonplugin/scanplugins.h>

int main()
{
    x3::loadScanPlugins();

    int ret = test();

    x3::unloadScanPlugins();

    return ret;
}

//---------------------------------------------------------------
#endif

#include <plsimple/isimple.h>
#include <stdio.h>

int test()
{
    x3::Object<ISimple> p(clsidSimple);

    if (p)
    {
        printf("The plugin is loaded (%s in %s).\n",
            p->getInterfaceName(), p->getClassName());
    }
    else
    {
        printf("The plugin is not loaded.\n");
        return 1;
    }

    int sum = p->add(1, 2);
    printf("p->add(1, 2): %d\n", sum);

    if (sum != 3)
    {
        printf("diffrent implement\n");
        return 2;
    }

    printf("Goodbye\n");
    return 0;
}
