#ifndef _VIEW_H
#define _VIEW_H

#include <GL/glut.h>
#include "Snake.h"
#include "Food.h"

class View
{
public:
	View();
	void init( int argc, char* argv[] );
	~View();
private:
	static Snake snake;
	static Food food;
	static void idle();
	static void display();
	static void keyboard( unsigned char key, int x, int y );
};

#endif