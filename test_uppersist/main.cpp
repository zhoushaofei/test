#include <unistd.h>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <util/tc_thread_pool.h>
#include <util/tc_common.h>
#include <util/tc_thread_queue.h>
#include "util/tc_logger.h"
#include "util/tc_file.h"
#include "util/tc_config.h"
#include "servant/RemoteLogger.h"
#include "event/TimeUtil.h"
#include "persist/PersistHelper.h"

using namespace std;
using namespace taf;


int main()
{
    cout << "welcome" << endl;

    try
    {
        // persist::PersistHelper persisHelper;
        // persist::PersistParam persistParam1;
        // persist::PersistParam persistParam2;

        persist::PersistHelper::setLogOn(true);

        // persistParam2 = persistParam1;

        static persist::PersistHelper persisHelper;
        persist::PersistParam persistParam;

        // 开启persist调试日志
        persist::PersistHelper::setLogOn(true);

        // persistParam.dbconn = "172.16.8.31 ;ht ; up123456 ; upwhdb ;utf8 ; 1521";
        persistParam.dbconn = "172.16.8.29 ;ht ; up123456 ; orcl ;utf8 ; 1521";
        persistParam.pat = persist::PAT_ORACLE;
        persistParam.sequence_name = "NODE_ID";
        persistParam.persistName2Table["PO_ORDERRECORD_TEST"] = "T_ORDERRECORD_TEST";

        persisHelper.init(persistParam);

        TC_Common::msleep(1000);
    }
    catch (std::exception& e)
    {
        cout << "exception:" << e.what() << endl;
    }
    catch (...)
    {
        cout << "unknown exception." << endl;
    }

    cout << "byebye" << endl;
    return 0;
}