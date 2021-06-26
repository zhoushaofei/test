
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

INCLUDE += -I/usr/local/thirdparty/include
LIB     += -L/usr/local/thirdparty/lib/ -ljsoncpp

INCLUDE += -I./kcxpapi_linux64_20.20201104/kcxpapi_linux64
# LIB     += -L./kcxpapi_linux64_20.20201104/kcxpapi_linux64 -ldes -lkcbpcli -lkcbpcrypt -lkcxpmq -lKDEncodelib_x64 -Wl,--rpath=./kcxpapi_linux64_20.20201104/kcxpapi_linux64
LIB     += -L./kcxpapi_linux64_20.20201104/kcxpapi_linux64 -lkcbpcli -lKDEncodelib_x64 -Wl,--rpath=./kcxpapi_linux64_20.20201104/kcxpapi_linux64

#-----------------------------------------------------------------------
include /usr/local/taf/cpp/makefile/makefile.taf.new

LIB_64_O2     += -L/usr/local/taf/cpp/thirdparty/lib/ -lssl -lcrypto



#-----------------------------------------------------------------------
