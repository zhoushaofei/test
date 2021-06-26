
#-----------------------------------------------------------------------

APP       := Test
TARGET    := TestServer
DFLAGS    := O2
CONFIG    :=
STRIP_FLAG:= N
J2CPP_FLAG:=

INCLUDE += -I/usr/local/upevent/include
LIB     += -L/usr/local/upevent/lib/ -lupevent

INCLUDE += -I/usr/local/taf/cpp/thirdparty/include/mysql
LIB     += -L/usr/local/taf/cpp/thirdparty/lib/ -lmysqlclient

#-----------------------------------------------------------------------
include /usr/local/taf/cpp/makefile/makefile.taf.new

LIB_64_O2     += -L/usr/local/taf/cpp/thirdparty/lib/ -lssl -lcrypto


#-----------------------------------------------------------------------
