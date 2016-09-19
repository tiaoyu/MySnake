#ifndef _VIEW_H
#define _VIEW_H

#include <GL/glut.h>
#include "Snake.h"
#include "Ground.h"
#include "Food.h"
template <typename TYPE, void ( TYPE::*display)()>
void* _display( void )
{
	TYPE view;
	view.display();
	return NULL; 
}

class View
{
public:
	View();
	void init( int argc, char* argv[] );
	~View();
private:
	static Snake snake;
	static Ground ground;
	static Food food;
	static void idle();
	static void display();
	static void keyboard( unsigned char key, int x, int y );
};

#endif