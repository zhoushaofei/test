
/*client.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#include <netinet/in.h>
#include <netinet/tcp.h> // for TCP_NODELAY

#include <iostream>

#include "util/tc_common.h"
#include "servant/Communicator.h"


using namespace std;


int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Usage: %s <server_ipaddr> <port>\n", argv[0]);
		exit(1);
	}
	int clifd;
	Buffer *mybuf;
	mybuf = (Buffer *)malloc(sizeof(Buffer));

	clifd = create_socket();

	int flag = 1;
	setsockopt(clifd, IPPROTO_TCP, TCP_NODELAY, (void*)&flag, sizeof(int));

	// int quickack = 0;
	// setsockopt(clifd, IPPROTO_TCP, TCP_QUICKACK, &quickack, sizeof(int));

	int nSendBuf=0;
	setsockopt(clifd, SOL_SOCKET, SO_SNDBUF, (char *)&nSendBuf, sizeof(int));

	int nRecvBuf=0;
	setsockopt(clifd, SOL_SOCKET, SO_RCVBUF, (char *)&nRecvBuf, sizeof(int));

	int flagxx = 122;
	socklen_t opt_len = sizeof(flagxx);
	getsockopt(clifd, IPPROTO_TCP, TCP_NODELAY, (void*)&flagxx, &opt_len);
	cout << "TCP_NODELAY=" << flagxx << endl;

	getsockopt(clifd, IPPROTO_TCP, TCP_QUICKACK, (void*)&flagxx, &opt_len);
	cout << "TCP_QUICKACK=" << flagxx << endl;

	sock_connect(clifd, argv[1], atoi(argv[2]));

	// getchar();

	mybuf->val = 123;
	// printf("input a num:");
	// scanf("%d", &mybuf->val);
	// printf("input some text:");
	// scanf("%s", mybuf->buf);

	int64_t tm = TC_Common::now2us();
	for (int i=0; i< 1; i++)
	{
		sock_send(clifd, mybuf, sizeof(Buffer), 0);
		int ret = sock_recv(clifd, mybuf, sizeof(Buffer), 0);
		if (ret > 0)
		{
			printf("recv:val = %d, buf = %s, ret= %d\n", mybuf->val, mybuf->buf, ret);
		}
		// TC_Common::msleep(100);
		int64_t tm2 = TC_Common::now2us() - tm;
		cout << "i=" << i << "|tm=" << tm2 << endl;
	}

	getchar();

	close(clifd);

	return 0;
}
