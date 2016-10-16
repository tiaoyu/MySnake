#ifndef _CONNECT_H_
#define _CONNECT_H_

#include <iostream>
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

#include "Score.h"
using std::cout;
using std::endl;
using std::string;
class Connect
{
public:

	string sendData(const string ipaddr, const Score score, const int port );

	Connect();
	~Connect();
};
#endif