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

const int SERVPORT = 8080;
const int MAXLINE = 4096;
const int LISTENQ = 1024;

int 
main(int argc, char const *argv[])
{
	int 		listenfd, connfd;
	struct 		sockaddr_in servaddr;
	char		buff[MAXLINE];

	listenfd = socket ( AF_INET, SOCK_STREAM, 0 );

	bzero ( &servaddr, sizeof (servaddr) );
	servaddr.sin_family		 = AF_INET;
	servaddr.sin_addr.s_addr = htonl ( INADDR_ANY );
	servaddr.sin_port		 = htons ( SERVPORT );

	bind ( listenfd, ( struct sockaddr * ) &servaddr, sizeof ( servaddr ) );

	listen ( listenfd, 10 );

	for ( ; ; )
	{
		// struct socketaddr_in client_addr;
		// socket_t length = sizeof ( client_addr );
		connfd = accept ( listenfd, ( struct sockaddr * ) NULL, NULL );

		int n = recv ( connfd, buff, MAXLINE, 0 );
		buff[n] = '\0';

		printf ( "%s", buff );


		char response[100] = "got it~";
		write ( connfd, response, sizeof ( response ) );
		close ( connfd );
	}

	return 0;
}

