#!/bin/sh
source /usr/local/SoftwareAG/Apama_5.3/bin/apama_env
nohup correlator -p 15903 --license /root/SoftwareAG/ApamaWork_5.3/license/license.txt > output.txt 2>&1 &
# nohup correlator -p 15903 > output.txt 2>&1 &

# 等待1s, 等待correlator启动完成
echo "correlator start..."
sleep 1

# 注入APAMA脚本
echo "inject scripts..."
engine_inject -p 15903 ConnHeartBeat.mon
engine_inject -p 15903 NewOrderDef.mon
engine_inject -p 15903 TradeAdapterDef.mon
engine_inject -p 15903 test.mon
# engine_inject -p 15903 test1.mon
# engine_inject -p 15903 test2.mon
# engine_inject -p 15903 test3.mon
# engine_inject -p 15903 test4.mon

