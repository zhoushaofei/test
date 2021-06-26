
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

INCLUDE += -I/usr/local/thirdparty/include/macli
LIB     += -L/usr/local/thirdparty/lib/macli -lmaCliApi -lxsdk -lObjects  -Wl,--rpath=/usr/local/thirdparty/lib/macli
# INCLUDE += -I../test_macli_29/include
# LIB     += -L../test_macli_29/Lnx64 -lmaCliApi -lxsdk -lObjects  -Wl,--rpath=/usr/local/thirdparty/lib/macli

#-----------------------------------------------------------------------
include /usr/local/taf/cpp/makefile/makefile.taf.new

LIB_64_O2     += -L/usr/local/taf/cpp/thirdparty/lib/ -lssl -lcrypto



#-----------------------------------------------------------------------
