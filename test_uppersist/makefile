
JCE2CPP = /usr/local/taf/cpp/tools/jce2cpp

LIB 	+= -lpthread -ldl -lrt

INCLUDE += -I/usr/local/upevent/include
LIB     += -L/usr/local/upevent/lib -lupevent

INCLUDE += -I/usr/local/uppersist/include
LIB     += -L/usr/local/uppersist/lib -luppersist

INCLUDE += -I/usr/local/taf/cpp/thirdparty/include/mysql
LIB     += -L/usr/local/taf/cpp/thirdparty/lib/ -lmysqlclient

INCLUDE += -I/usr/local/thirdparty/include/oracle
LIB 	+= -L/usr/local/thirdparty/lib/oracle -locci -lnnz19 -lclntsh

INCLUDE += -I/usr/local/taf/cpp/include
LIB     += -L/usr/local/taf/cpp/lib -ltafservant -ltafutil -lparse
LIB     += -L/usr/local/taf/cpp/thirdparty/lib -lssl -lcrypto

test : main.cpp
	g++ -m64 -O2 -fPIC -Wall -std=c++11 -o test main.cpp $(INCLUDE) $(LIB) -Wl,--rpath=/usr/local/thirdparty/lib/oracle

clean :
	rm -f test main.o

