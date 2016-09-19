#ifndef _GROUND_H_
#define _GROUND_H_
#include <iostream>
#include <vector>
using namespace std;
/**
 * ground 
 */
class Ground
{
public:
	Ground();
	void init();
	void print();
	void clear();
	int getWidth();
	int getHeight();
	~Ground();
	vector<vector<char> > ground;
private:
	static const int width = 50;
	static const int height = 50;
};

#endif