
# LIB 	+= -lpthread -ldl -lrt
LIB 	+= -ldl

INCLUDE += -I../x3py-master/interface/core
INCLUDE += -I../x3py-master/interface/example

# LIB     += -L/usr/local/taf/cpp/lib -ltafservant -ltafutil -lparse
# LIB     += -L/usr/local/taf/cpp/thirdparty/lib -lssl -lcrypto

test : main.cpp
	g++ -m64 -O2 -fPIC -Wall -std=c++11 -o test main.cpp $(INCLUDE) $(LIB)

clean :
	rm -f test main.o

