
# LIB 	+= -lpthread -ldl -lrt
LIB 	+= -ldl

INCLUDE += -I../x3py-master/interface/core

# LIB     += -L/usr/local/taf/cpp/lib -ltafservant -ltafutil -lparse
# LIB     += -L/usr/local/taf/cpp/thirdparty/lib -lssl -lcrypto

test : myplugin.cpp
	g++ -m64 -O2 -fPIC -Wall -std=c++11 -shared -o libmyplugin.so myplugin.cpp $(INCLUDE) $(LIB)

clean :
	rm -f test libmyplugin.so

