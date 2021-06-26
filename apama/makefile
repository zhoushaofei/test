
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

INCLUDE += -I/usr/local/SoftwareAG/Apama_5.3/include
LIB     += -L/usr/local/SoftwareAG/Apama_5.3/lib/ -lengine_client -Wl,--rpath=/usr/local/SoftwareAG/Apama_5.3/lib

#-----------------------------------------------------------------------
include /usr/local/taf/cpp/makefile/makefile.taf.new



#-----------------------------------------------------------------------
