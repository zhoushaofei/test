/*server.c*/
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

#define MAXNUM 10

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}
	int lisfd, clifd;
	Buffer *mybuf;
	mybuf = (Buffer *)malloc(sizeof(Buffer));

	lisfd = create_socket();

	// int flag = 1;
	// setsockopt(lisfd, IPPROTO_TCP, TCP_NODELAY, (void*)&flag, sizeof(int));

	// int quickack = 0;
	// setsockopt(clifd, IPPROTO_TCP, TCP_QUICKACK, &quickack, sizeof(int));

	int flagxx = 122;
	socklen_t opt_len = sizeof(flagxx);
	getsockopt(lisfd, IPPROTO_TCP, TCP_NODELAY, (void*)&flagxx, &opt_len);
	cout << "TCP_NODELAY=" << flagxx << endl;

	getsockopt(lisfd, IPPROTO_TCP, TCP_QUICKACK, (void*)&flagxx, &opt_len);
	cout << "TCP_QUICKACK=" << flagxx << endl;



	sock_bind(lisfd, atoi(argv[1]));
	sock_listen(lisfd, MAXNUM);

	while(1)
	{
		clifd = sock_accept(lisfd);
		printf("sock_accept\n");

		int ret = sock_recv(clifd, mybuf, sizeof(Buffer), 0);
		if (ret > 0)
		{
			sock_send(clifd, mybuf, sizeof(Buffer), 0);
			printf("recv:val = %d, buf = %s, ret= %d\n", mybuf->val, mybuf->buf, ret);
		}
	}
	close(clifd);
	close(lisfd);
	return 0;
}
