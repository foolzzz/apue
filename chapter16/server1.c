#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include  <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>


int main()
{
	int sockfd;

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	printf("sockfd=%d\n",sockfd);

	struct sockaddr_in sa;

	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = htonl(INADDR_ANY);
	sa.sin_port = htons(5000);

	int res;
	int s_len;
	s_len = sizeof(sa);
	res = bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
	if(res != 0)
	{
		perror("bind e");
	}

	listen(sockfd,10);

	int c_sockfd;
	struct sockaddr_in sc;
	int c_len;

	c_len = sizeof(sc);

	char *buf;
	buf =  (char *)malloc(500);
	while(1)
	{
		c_sockfd = accept(sockfd,(struct sockaddr *)&sc,&c_len);	
		
		printf("Get %s - %d\n",inet_ntoa(sc.sin_addr),ntohs(sc.sin_port));


	}
	
	return 0;
}



