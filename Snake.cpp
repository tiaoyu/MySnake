#include "Snake.h"
using namespace std;
Snake::Snake()
{
}

Snake::~Snake()
{

}
/**
 * get input from keyboard
 */
int 
Snake::getch()
{
	cout << "===> this is getch.(get input from keyboard.)" << endl;
	struct termios oldCh;
	ioctl (STDIN_FILENO, TCGETS, &oldCh);
	struct termios newCh = oldCh;
	newCh.c_lflag &= ~(ECHO | ICANON);
	ioctl (STDIN_FILENO, TCSETS, &newCh);
	int ch = getchar ();
	ioctl (STDIN_FILENO, TCSETS, &oldCh);
	return ch;
}

/**
 * init snake
 */
void 
Snake::init()
{	
	deadth = false;
	
	///use opengl func to listen keyboard, so this don's be used
	// pthread_create ( &snake_thread, NULL, _thread_t<Snake, &Snake::move>, this);
	//////////
	cout << "===> this is snake init.(init snake.)" << endl;
	int count = 10;
	Point* p;
	for (int i = 0; i < count; ++i)
	{
		p = new Point( 1, i + 1 );
		body.push_back ( *p );
		// don't forget free this point
		free ( p );
	}

	// set oldTail
	oldTail = body.front ();
	// set direction of snake
	direction = oldDirection = RIGHT;
	
}
/**
 * snake die
 */
void 
Snake::die()
{
	cout << "===> main thread is over." << endl;
	if ( snake_thread != 0 )
	{
		pthread_join ( snake_thread, NULL );
		cout << "===> snake_thread is over. Game Over!" << endl;
	}
	
}
/**
 * keep moving
 */
void 
Snake::moveOn(Ground &ground)
{
	Point* pHead = &body.front ();
	Point* pTemp = NULL;

	int x = pHead->getX();
	int y = pHead->getY();
	if ( x <= 0 - ground.getHeight() || x >= ground.getHeight() - 1
		|| y <= 0 - ground.getWidth() || y >= ground.getWidth() - 1 )
	{
		deadth = true;
		return ;
	}

	switch ( direction )
	{
	case UP:
		pTemp = new Point( x, y + 1 );
		break;
	case DOWN:
		pTemp = new Point( x, y - 1 );
		break;
	case LEFT:
		pTemp = new Point( x - 1, y );
		break;
	case RIGHT:
		pTemp = new Point( x + 1, y );
		break;
	default:
		break;
	}
	body.push_front (*pTemp);
	body.pop_back ();
}
void 
Snake::addTail( Point p )
{
	body.push_back ( p );
}
void 
Snake::print()
{
	cout << "<Snakes' Head>" << endl;
	for (std::list<Point>::iterator i = body.begin(); i != body.end(); ++i)
	{
		cout << "| (" << i->getX() << "," << i->getY() << ") |" << endl;
	}
	cout << "<Snakes' Tail>" << endl;
}

void 
Snake::print( Ground &ground)
{
	for ( list<Point>::iterator i = body.begin(); i != body.end(); ++i )
	{
		int x = i->getX();
		int y = i->getY();
		if ( x > ground.getHeight() && x < ground.getHeight()
			&& y > 0 && y < ground.getWidth() )
		{
			ground.ground[i->getX()][i->getY()] = 'o';
		}
	}
	ground.print();
}

/**
 * listen keyboard input, and control snake moving
 */
void 
Snake::move()
{
	while ( true )
	{
		if ( deadth )
		{
			break;
		}

		int key = getch();
		
		if ( strchr ( "Qq", key ) != NULL )
		{
			deadth = true;
			break;
		}

		switch ( key )
		{
		case 'W':case 'w':
			oldDirection = direction;
			direction = UP;
			break;
		case 'S':case 's':
			oldDirection = direction;
			direction = DOWN;
			break;
		case 'A':case 'a':
			oldDirection = direction;
			direction = LEFT;
			break;
		case 'D':case 'd':
			oldDirection = direction;
			direction = RIGHT;
			break;
		default:
			break;
		}
	}
	pthread_exit ( NULL );
}