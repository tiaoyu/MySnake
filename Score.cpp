#include "Score.h"
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;

Score::Score()
{
	cout << "===> this is Score()." << endl;
}
Score::Score( string sid, string uid, int sco )
{
	this->sid = sid;
	this->uid = uid;
	this->sco = sco;
}
Score::~Score()
{
	cout << "===> this is ~Score()." << endl;
}

void 
Score::setSid( string sid )
{
	this->sid = sid;
}
string 
Score::getSid()
{
	return this->sid;
}
void 
Score::setUid( string uid )
{
	this->uid = uid;
}
string 
Score::getUid()
{
	return this->uid;
}
void 
Score::setSco( int sco )
{
	this->sco = sco;
}
int 
Score::getSco()
{
	return this->sco;
}
string 
Score::toString()
{
	std::stringstream ss;
	string str;
	ss << this->sco;
	ss >> str;
	return "[sid:" + this->sid + ",uid:" + this->uid
		+ ",sco:" + str + "]";
}

