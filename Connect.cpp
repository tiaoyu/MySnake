#include "Connect.h"

Connect::Connect()
{
	cout << "===> this is Connect().";
}
Connect::~Connect()
{
	cout << "===> this is ~Connect().";
}

string 
Connect::sendData( const string ipaddr, const Score score, const int port )
{
	int sockfd, n;
	char recvline[4096], sendline[4096];

	struct sockaddr_in servaddr;

	sockfd = socket ( AF_INET, SOCK_STREAM, 0 );

	bzero ( &servaddr, sizeof ( servaddr ) );
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons ( port );

	inet_pton ( AF_INET, ipaddr.c_str(), &servaddr.sin_addr );

	connect ( sockfd, ( struct sockaddr * ) &servaddr, sizeof ( servaddr ) );

	// send Score
	int needSend = sizeof ( Score );
	char* buff = ( char* ) malloc ( needSend );
	memcpy ( buff, &score, needSend );

	int pos = 0;
	int len = 0;

	while ( pos < needSend )
	{
		len = send ( sockfd, buff + pos, 4096, 0 );
		if ( len <= 0 )
		{
			break;
		}
		pos += len;
	}

	free ( buff );
	
	// get Message from server
	recv ( sockfd, recvline, 10, 0 );	

	close ( sockfd );

	return string( recvline );
}
