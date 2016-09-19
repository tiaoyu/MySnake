#ifndef _SNAKE_H_
#define _SNAKE_H_
#include <iostream>
#include <malloc.h>
#include <list>
#include <pthread.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include "Point.h"
#include "Ground.h"
using namespace std;

/**
 * template of thread start func
 */
template <typename TYPE, void ( TYPE::*move)()>
void* _thread_t( void* param )
{
	TYPE* This = ( TYPE* ) param;
	This->move();
	return NULL;
}

class Snake
{
public:
	Snake();
	~Snake();
	void move();
	void init();
	void print();
	void die();
	void print( Ground &ground );
	void addTail( Point p );
	void moveOn( Ground &ground );
	int getch();

	// direction of snake
	int direction;
	int oldDirection;
	// direction of moving
	static const int UP = 1;
	static const int DOWN = -1;
	static const int LEFT = -2;
	static const int RIGHT = 2;
	bool deadth;
	Point oldTail;
	list<Point> body;
	///////////////////////
private:	
	pthread_t snake_thread;
};

#endif