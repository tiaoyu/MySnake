#include "Ground.h"
#include <string.h>
Ground::Ground()
{

}

int 
Ground::getWidth()
{
	return width;
}

int 
Ground::getHeight()
{
	return height;
}

void 
Ground::init()
{
	cout << "===> this is ground init.(init ground)." << endl;
	for (int i = 0; i < height; ++i)
	{
		ground.push_back ( vector<char> (width, '#') );
	}
}
void 
Ground::clear()
{
	cout << "===> ground clear.(clear ground.)" << endl;
	for ( int i = 1; i < height-1; ++i )
	{
		for ( int j = 1; j < width-1; ++ j )
		{
			ground[i][j] = ' ';
		} 
	}
}
void 
Ground::print()
{
	for ( int i = 0; i < height; ++i )
	{
		for ( int j = 0; j < width; ++j )
		{
			cout << ground[i][j];
		}
		cout << endl;
	}
}
Ground::~Ground()
{

}