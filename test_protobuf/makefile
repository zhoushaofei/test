
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

INCLUDE += -I/root/software/protobuf-2.6.1/build/include
LIB     += -L/root/software/protobuf-2.6.1/build/lib -lprotobuf -Wl,--rpath=/root/software/protobuf-2.6.1/build/lib

# INCLUDE += -I/usr/local/thirdparty/include
# LIB     += -L./mnch -lMNCH   -Wl,--rpath=./mnch


LOCAL_SRC += $(wildcard *.cc)

#-----------------------------------------------------------------------
include /usr/local/taf/cpp/makefile/makefile.taf.new

LIB_64_O2     += -L/usr/local/taf/cpp/thirdparty/lib/ -lssl -lcrypto



#-----------------------------------------------------------------------
