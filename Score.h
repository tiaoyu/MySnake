#ifndef _SCORE_H_
#define _SCORE_H_

#include <string>
using std::string;

class Score
{
private:
	string sid;
	string uid;
	int sco;
public:
	Score( string sid, string uid, int sco );
	Score();
	~Score();
	
	void setSid( string sid );
	string getSid();
	void setUid( string uid );
	string getUid();
	void setSco( int sco );
	int getSco();
	string toString();
};
#endif