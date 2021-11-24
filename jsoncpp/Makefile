CC = g++ -std=c++14

all: casher gunrock_server
setup: aggieclient.h aggieserver.h

aggieclient.h: aggie.json
	jsonrpcstub aggie.json --cpp-server=aggieServer --cpp-client=aggieClient

aggieserver.h: aggie.json
	jsonrpcstub aggie.json --cpp-server=aggieServer --cpp-client=aggieClient

casher.o: aggieclient.h casher.cpp
	$(CC) -c casher.cpp

gunrock_server.o: aggieserver.h gunrock_server.cpp
	$(CC) -c gunrock_server.cpp

gunrock_server:	gunrock_server.o
	g++ -o gunrock_server gunrock_server.o -ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server

casher:	casher.o
	g++ -o casher casher.o -ljsoncpp -lcurl -ljsonrpccpp-common -ljsonrpccpp-client

clean:
	rm -rf *.o aggieclient.h aggieserver.h casher gunrock_server
