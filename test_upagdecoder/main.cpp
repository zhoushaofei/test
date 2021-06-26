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
#include "agdecoder/AgDecoder.h"
#include "agdecoder/DecoderIf.h"


using namespace std;
using namespace taf;


class MyDataNotify : public AgDataNotifyIf
{
    /*
     * 股票静态信息
     * iTradeDate: 交易日
     * vStockInfo: 静态信息
     * bSnapshot：true
     */
    virtual int update(E_EXCHANGE market, int iTradeDate, const vector<UPStockInfo> & vStockInfo, bool bSnapshot)
    {
        cout << "update: market=" << market << "|iTradeDate=" << iTradeDate << "|vStockInfo.size=" << vStockInfo.size() << "|bSnapshot=" << bSnapshot << endl;
        return 0;
    }

    /*
     * 上海静态文件行情更新
     * iTradeDate: 交易日
     * vQuoteData: 行情信息
     * bSnapshot：是否全量，如果为true表示vQuoteData是今天所有股票的信息
     */
    virtual int update(E_EXCHANGE market, int iTradeDate, const vector<UPQuoteData> &vQuoteData, bool bSnapshot)
    {
        cout << "update: market=" << market << "|iTradeDate=" << iTradeDate << "|vQuoteData.size=" << vQuoteData.size() << "|bSnapshot=" << bSnapshot << endl;
        return 0;
    }

    //上海快照
    virtual int update(const SH_L1_STOCKSNAP& snap)
    {
        string symbol(snap.SecurityID.Value());
        if (symbol == "600000")
        {
            LOG_CONSOLE_DEBUG << "update: SH_L1_STOCKSNAP=" << snap.SecurityID.Value() << endl;
        }
        return 0;
    }

    //上海指数行情
    virtual int update(const SH_L1_INDEX& index)
    {
        string symbol(index.SecurityID.Value());
        if (symbol == "600000")
        {
            LOG_CONSOLE_DEBUG << "update: SH_L1_INDEX=" << index.SecurityID.Value() << endl;
        }
        return 0;
    }

    //深圳快照
    virtual int update(const SZ_L1_SNAPSHOT & snap)
    {
        string symbol(snap.Basic.SecurityID.Value());
        if (symbol == "000001")
        {
            LOG_CONSOLE_DEBUG << "update: SZ_L1_SNAPSHOT=" << snap.Basic.SecurityID.Value() << endl;
        }
        return 0;
    }

    //深圳指数行情
    virtual int update(const SZ_L1_INDEX & index)
    {
        string symbol(index.SecurityID.Value());
        if (symbol == "000001")
        {
            LOG_CONSOLE_DEBUG << "update: SZ_L1_INDEX=" << index.SecurityID.Value() << endl;
        }
        return 0;
    }

    // ---------------------批量回调接口-----------------------

    //上海批量 快照
    virtual int update(const vector<SH_L1_STOCKSNAP>& vSnap)
    {
        cout << "update: SH_L1_STOCKSNAP.size=" << vSnap.size() << endl;
        return 0;
    }

    //上海批量 指数
    virtual int update(const vector<SH_L1_INDEX>& vIndex)
    {
        cout << "update: SH_L1_INDEX.size=" << vIndex.size() << endl;
        return 0;
    }

    //深圳批量 快照
    virtual int update(const vector<SZ_L1_SNAPSHOT>& vSnap)
    {
        cout << "update: SZ_L1_SNAPSHOT.size=" << vSnap.size() << endl;
        return 0;
    }

    //深圳批量 行情
    virtual int update(const vector<SZ_L1_INDEX>& vIndex)
    {
        cout << "update: SZ_L1_INDEX.size=" << vIndex.size() << endl;
        return 0;
    }

};

void dotest()
{
    MyDataNotify mynotify;

    AgDecoder ag_sh;
    ag_sh.addObserver(&mynotify);

    map<string,string> config_sh;
    config_sh["ip"] = "10.1.82.103";
    config_sh["port"] = "50011";
    config_sh["mktdt00"] = "/data/marketdata/syncdata_new/mktdt00.txt";
    config_sh["cpxx"] = "/data/marketdata/syncdata_new/cpxx0202%m%d.txt";
    config_sh["batchnum"] = "1000";
    config_sh["sender"] = "aqs";
    config_sh["target"] = "MDGW";
    config_sh["mode"] = "binary";
    config_sh["cpxxReadTime"] = "085500";
    // config_sh["mktdtReadTime"] = "090000";
    config_sh["depthChannelNum"] = "1";
    config_sh["tickChannelNum"] = "1";
    config_sh["etfPath"] = "/data/marketdata/syncdata_new";

    bool ret_sh = ag_sh.init(E_EXCHANGE_SH, config_sh);
    if (ret_sh)
    {
        cout << "ag_sh.init done|" << ret_sh << endl;
    }
    else
    {
        cout << "ag_sh.init failed|" << ret_sh << endl;
    }


    AgDecoder ag_sz;
    ag_sz.addObserver(&mynotify);

    map<string,string> config_sz;
    config_sz["ip"] = "10.1.82.103";
    config_sz["port"] = "8015";
    config_sz["sender"] = "aqs191";
    config_sz["target"] = "F000621Q0055";
    config_sz["securities"] = "/data/marketdata/syncdata_new/securities_%Y%m%d.xml";
    config_sz["securityReadTime"] = "085000";
    // config_sz["indexinfo"] = "/data/marketdata/syncdata_new/indexinfo_%Y%m%d.xml";
    config_sz["depthChannelNum"] = "1";
    config_sz["tickChannelNum"] = "1";
    config_sz["etfPath"] = "/data/marketdata/syncdata_new";

    bool ret_sz = ag_sz.init(E_EXCHANGE_SZ, config_sz);
    if (ret_sz)
    {
        cout << "ag_sz.init done|" << ret_sz << endl;
    }
    else
    {
        cout << "ag_sz.init failed|" << ret_sz << endl;
    }


    while (1)
    {
        TC_Common::msleep(1000);
    }
}

int main()
{
    cout << "welcome" << endl;

    try
    {
        dotest();
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