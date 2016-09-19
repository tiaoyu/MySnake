#include "Snake.h"
#include "Ground.h"
#include "View.h"
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <iostream>
using namespace std;
int 
main(int argc, char *argv[])
{
	View view;
	view.init( argc, argv);
	
/*	cout << "===> this is main." << endl;
	Snake snake;
	Ground ground;
	snake.init();
	ground.init();
	ground.print();
	// main thread
	while ( true )
	{
		system ("clear");
		ground.clear();
		snake.moveOn( ground ); 	// update ground
		// snake.print();				// print snake;
		snake.print( ground );	// print ground
		if ( snake.deadth )
		{
			cout << "===> sanke die." << endl;
			break;
		}
		usleep ( 50000 );
	}
	snake.die();*/

	return 0;
}