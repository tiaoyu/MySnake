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
	void move();	// snake move
	void init();	// snake init
	void print();	// print snake
	void die();		// snake die
	void addTail( Point p );	// snake add tial
	void moveOn();
	int getch();	// get keyboard listen

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