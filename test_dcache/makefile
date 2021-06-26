
JCE2CPP = /usr/local/taf/cpp/tools/jce2cpp

LIB 	+= -lpthread -ldl -lrt

INCLUDE += -I/usr/local/upevent/include
LIB     += -L/usr/local/upevent/lib -lupevent

INCLUDE += -I/home/tafjce/DCache/ProxyServer
INCLUDE += -I/home/tafjce/DCache/API/include
INCLUDE += -I/home/tafjce/DCache/JceComm
LIB     += -L/home/tafjce/DCache/API/lib -lAPI

INCLUDE += -I/usr/local/taf/cpp/include
LIB     += -L/usr/local/taf/cpp/lib -ltafservant -ltafutil -lparse
LIB     += -L/usr/local/taf/cpp/thirdparty/lib -lssl -lcrypto

test : main.cpp
	g++ -m64 -O2 -fPIC -Wall -std=c++11 -o test main.cpp $(INCLUDE) $(LIB)

clean :
	rm -f test main.o

