
# JCE2CPP = /usr/local/taf/cpp/tools/jce2cpp

# LIB 	+= -lpthread -ldl -lrt

# INCLUDE += -I/usr/local/upevent/include
# LIB     += -L/usr/local/upevent/lib -lupevent

# INCLUDE += -I/usr/local/taf/cpp/include
# LIB     += -L/usr/local/taf/cpp/lib -ltafservant -ltafutil -lparse
# LIB     += -L/usr/local/taf/cpp/thirdparty/lib -lssl -lcrypto

# INCLUDE += -I/usr/local/uppersist/include
# LIB     += -L/usr/local/uppersist/lib -luppersist

# INCLUDE += -I/root/software/oracle/instantclient_11_2/sdk/include
# LIB 	+= -L/root/software/oracle/instantclient_11_2 -locci -lnnz11 -lclntsh

INCLUDE += -I/root/software/oracle/instantclient_19_8/sdk/include
LIB 	+= -L/root/software/oracle/instantclient_19_8 -lclntsh -locci -lpthread

# INCLUDE += -I/usr/local/thirdparty/include/oracle
# LIB 	+= -L/usr/local/thirdparty/lib/oracle -locci -lnnz19 -lclntsh

#  -lclntsh -locci -lmql1-lipc1 -lnnz12 -lons -lclntshcore

test : main.cpp
	g++ -m64 -O2 -fPIC -Wall -std=c++11 -o test main.cpp $(INCLUDE) $(LIB)

clean :
	rm -f test main.o

