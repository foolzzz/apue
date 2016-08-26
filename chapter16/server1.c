#include <stdio.h>
#include <sys/socket.h>


int main()
{
	int sockfd;

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	printf("sockfd=%d\n",sockfd);

	struct sockaddr_in sa;

	sa


