#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

const int MAXLINE = 4096;
const int SERVPORT = 8080;
int 
main(int argc, char const *argv[])
{
	int sockfd, n;
	char recvline[MAXLINE], sendline[MAXLINE];
	struct sockaddr_in servaddr;

	sockfd = socket ( AF_INET, SOCK_STREAM, 0 );

	bzero ( &servaddr, sizeof ( servaddr ) );
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons ( SERVPORT );

	inet_pton ( AF_INET, argv[1], &servaddr.sin_addr );

	connect ( sockfd, ( struct sockaddr * ) &servaddr, sizeof ( servaddr ) );

	printf ( "send something: " );

	fgets ( sendline, MAXLINE, stdin );

	send ( sockfd, sendline, strlen ( sendline ), 0 );

	char receive[10];

	recv ( sockfd, receive, 10, 0 );
	printf ( "get: %s\n", receive );

	close ( sockfd );
	exit ( 0 );

	return 0;
}