/*commom.h*/
#ifndef _COMMOM_H_
#define _COMMOM_H_
 
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
 
#define SIZE 512
 
typedef struct
{
	int val;
	char buf[SIZE];
}Buffer;
 
int create_socket()
{
	int lisfd;
	lisfd = socket(AF_INET, SOCK_STREAM, 0);//IPV4 数据流 TCP类型
	if (lisfd == -1)
	{
		perror("create_socket failed!\n");
		exit(1);
	}
	return lisfd;
}
 
int sock_bind(int lisfd, int port)
{
	struct sockaddr_in myaddr;
	memset((char *)&myaddr, 0, sizeof(struct sockaddr_in));//清零
	myaddr.sin_family = AF_INET;//IPV4
	myaddr.sin_port = htons(port);//端口
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);//允许连接到所有本地地址上
	if (bind(lisfd, (struct sockaddr *)&myaddr, sizeof(struct sockaddr))==-1)
	{
		perror("sock_bind failed!\n");
		exit(1);
	}
	return 0;
}
 
int sock_listen(int lisfd, int max_con)
{
	if (listen(lisfd, max_con)==-1)
	{
		perror("sock_listen failed!\n");
		exit(1);
	}
	return 0;
}
 
int sock_accept(int lisfd)
{
	struct sockaddr remoaddr;
	int clifd;
	socklen_t size = sizeof(struct sockaddr);
	
	memset((char *)&remoaddr, 0, sizeof(struct sockaddr));
	clifd = accept(lisfd, &remoaddr, &size);
	if (clifd == -1)
	{
		perror("sock_accept failed!\n");
		exit(1);
	}
	return clifd;
}
 
int sock_connect(int clifd, char *ipaddr, int port)
{
	struct sockaddr_in remoaddr;
	memset((char *)&remoaddr, 0, sizeof(struct sockaddr_in));
	remoaddr.sin_family = AF_INET;//IPV4地址
	remoaddr.sin_port = htons(port);//端口
	remoaddr.sin_addr.s_addr = inet_addr(ipaddr);//服务器端IP地址
	if (connect(clifd, (struct sockaddr *)&remoaddr, sizeof(struct sockaddr))==-1)
	{
		perror("sock_connect failed!\n");
		exit(1);
	}
	return 0;
}
 
int sock_send(int sockfd, void *buf, size_t len, int flags)
{
	int nbytes;
	nbytes = send(sockfd, buf, len, flags);
	if (nbytes == -1)
	{
		perror("sock_send failed!\n");
		exit(1);
	}
	return nbytes;
}
 
int sock_recv(int sockfd, void *buf, size_t len, int flags)
{
	int nbytes;
	nbytes = recv(sockfd, buf, len, flags);
	if (nbytes == -1)
	{
		perror("sock_send failed!\n");
		exit(1);
	}
	return nbytes;
}
 
 
#endif