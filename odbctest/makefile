
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

INCLUDE += -I/usr/local/thirdparty/include/unixODBC
LIB     += -L/usr/local/thirdparty/lib/unixODBC -lodbc

#-----------------------------------------------------------------------
include /usr/local/taf/cpp/makefile/makefile.taf.new



#-----------------------------------------------------------------------
