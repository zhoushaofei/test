

#-----------------------------------------------------------------------

APP       := Test
TARGET    := test
DFLAGS    := O2
CONFIG    :=
STRIP_FLAG:= N
J2CPP_FLAG:=

INCLUDE += -I/usr/local/upevent/include
LIB     += -L/usr/local/upevent/lib/ -lupevent

INCLUDE += -I/usr/local/taf/cpp/thirdparty/include/mysql
LIB     += -L/usr/local/taf/cpp/thirdparty/lib/ -lmysqlclient

# INCLUDE += -I/root/software/ctp/v6.3.19_P1_20200106_api/v6.3.19_P1_20200106_api_tradeapi_se_linux64
# LIB     += /root/software/ctp/v6.3.19_P1_20200106_api/v6.3.19_P1_20200106_api_tradeapi_se_linux64/thostmduserapi_se.so
# LIB     += /root/software/ctp/v6.3.19_P1_20200106_api/v6.3.19_P1_20200106_api_tradeapi_se_linux64/thosttraderapi_se.so

# INCLUDE += -I/root/software/ctp/v6.3.19_P1_20200106_api/v6.3.19_P1_20200106_api_clientdatacollectdll_linux64
# LIB     += /root/software/ctp/v6.3.19_P1_20200106_api/v6.3.19_P1_20200106_api_clientdatacollectdll_linux64/LinuxDataCollect.so

# INCLUDE += -I/root/software/ctp/v6.3.19_T1_20200423_api/v6.3.19_T1_20200423_api_tradeapi_se_linux64
# LIB     += /root/software/ctp/v6.3.19_T1_20200423_api/v6.3.19_T1_20200423_api_tradeapi_se_linux64/thostmduserapi_se.so
# LIB     += /root/software/ctp/v6.3.19_T1_20200423_api/v6.3.19_T1_20200423_api_tradeapi_se_linux64/thosttraderapi_se.so

# INCLUDE += -I/root/software/ctp/v6.3.19_T1_20200423_api/v6.3.19_T1_20200423_api_clientdatacollectdll_linux64
# LIB     += /root/software/ctp/v6.3.19_T1_20200423_api/v6.3.19_T1_20200423_api_clientdatacollectdll_linux64/LinuxDataCollect.so

# INCLUDE += -I/usr/local/thirdparty/include/ctp
# LIB     += -L/usr/local/thirdparty/lib/ctp/sim -lthostmduserapi_se -lthosttraderapi_se -lLinuxDataCollect
# LIB     += -Wl,--rpath=/usr/local/thirdparty/lib/ctp/sim

INCLUDE += -I/usr/local/thirdparty/include/ctp
LIB     += -L/usr/local/thirdparty/lib/ctp -lthostmduserapi_se -lthosttraderapi_se -lLinuxDataCollect
LIB     += -Wl,--rpath=/usr/local/thirdparty/lib/ctp

# INCLUDE += -I/usr/local/thirdparty/include/ctp
# LIB     += -L/usr/local/thirdparty/lib/ctp -lthostmduserapi_se -lthosttraderapi_se -lLinuxDataCollect
# LIB     += -Wl,--rpath=/root/v6.3.16_T1_20190508_api

#-----------------------------------------------------------------------
include /usr/local/taf/cpp/makefile/makefile.taf.new

LIB_64_O2     += -L/usr/local/taf/cpp/thirdparty/lib/ -lssl -lcrypto



#-----------------------------------------------------------------------
