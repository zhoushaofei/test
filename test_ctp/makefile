

LIB 	+= -lpthread -ldl -lrt

INCLUDE += -I./v6.3.16_T1_20190508_api_clientdatacollectdll_linux64
LIB     += ./v6.3.16_T1_20190508_api_clientdatacollectdll_linux64/LinuxDataCollect.so
LIB     += -Wl,--rpath=./v6.3.16_T1_20190508_api_clientdatacollectdll_linux64

INCLUDE += -I./v6.3.16_T1_20190508_api_tradeapi_se_linux64
LIB     += ./v6.3.16_T1_20190508_api_tradeapi_se_linux64/thosttraderapi_se.so
LIB     += -Wl,--rpath=./v6.3.16_T1_20190508_api_tradeapi_se_linux64

test : main.cpp
	g++ -m64 -O2 -fPIC -Wall -std=c++11 -o test main.cpp $(INCLUDE) $(LIB)

clean :
	rm -f test main.o

