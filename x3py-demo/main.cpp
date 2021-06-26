#include <iostream>
#include <portability/x3port.h>
#include <nonplugin/useplugins.h>

#include "../x3py-plugin/myplugin.h"

using namespace std;

int main()
{
    cout << "helloworld" << endl;

    const char* plugins[] = {
        "libmyplugin.so", nullptr
    };

    // 自动加载和卸载插件，插件在程序文件的plugins子目录下
    x3::AutoLoadPlugins autoload(plugins, "../x3py-plugin/");


    x3::AnyObject obj("clsid_myplugin");

    if (obj)
    {
        cout << "ok" << endl;
        // int xx = obj->add(1, 2);
        // cout << "xxx=" << xx << endl;
    }
    else
    {
        printf("The plugin is not loaded.\n");
        return 1;
    }

    return 0;
}