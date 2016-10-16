#include "View.h"

Snake View::snake = Snake();
Food View::food = Food();
Score View::score = Score();
Connect View::connect = Connect();
View::View()
{
	cout << "===> this is View()" << endl;
}
View::~View()
{
	cout << "===> this is ~View()" << endl;
}
void 
View::init( int argc, char* argv[] )
{
	snake.init();
	food.create( snake );
	score.setSco( 0 );
	glutInit ( &argc, argv );
	glutInitDisplayMode ( GLUT_RGBA | GLUT_DOUBLE );
	glutInitWindowPosition ( 400, 400 );
	glutInitWindowSize ( 600, 600 );
	glutCreateWindow ( "First OpenGL" );
	glutDisplayFunc ( &display );
	glutIdleFunc ( &idle );
	glutKeyboardFunc ( &keyboard );
	glutMainLoop ();
}

void 
View::idle()
{
	snake.oldTail = snake.body.front ();
	snake.moveOn();
	if ( snake.body.front ().getX() == food.getX() 
		&& snake.body.front ().getY() == food.getY())
	{
		food.create ( snake );
		score.setSco ( score.getSco() + 1 );
		snake.addTail(snake.oldTail);
		cout << snake.body.size() << endl;

	}

	if ( snake.deadth )
	{
		connect.sendData( "127.0.0.1", score, 8080 );
		cout << "===> sanke die.Game over!" << endl;
		sleep (3);
		exit (0);
	}

	display();
}

void 
View::display()
{
	
	glEnable (GL_DEPTH_TEST);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode (GL_MODELVIEW);
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glPointSize ( 5.0f );
	glColor3f (1.0f, 0.0f, 0.0f);
	glBegin ( GL_POINTS );
	for ( list<Point>::iterator i = snake.body.begin(); i != snake.body.end(); ++i )
	{
		glVertex2f ( i->getX() * 1.0 / 50.0, i->getY() * 1.0 / 50.0 );
		// cout << i->getX()*1.0 / 100 << "," << i->getY()*1.0 / 100 << endl;
	}
	glColor3f ( 0.0f, 0.0f, 1.0f );
	glVertex2f ( food.getX() * 1.0 / 50.0, food.getY() * 1.0 / 50.0 );
	glEnd ();
	// glutSolidSphere (10, 20, 20);
	glFlush ();
	glutSwapBuffers ();
	usleep(50000);
}

void 
View::keyboard( unsigned char key, int x, int y )
{
	cout << "( " << x << " , " << y << " )" << endl;
	switch ( key )
	{
	case 'W':case 'w':
		snake.oldDirection = snake.direction;
		snake.direction = snake.UP;
		break;
	case 'S':case 's':
		snake.oldDirection = snake.direction;
		snake.direction = snake.DOWN;
		break;
	case 'A':case 'a':
		snake.oldDirection = snake.direction;
		snake.direction = snake.LEFT;
		break;
	case 'D':case 'd':
		snake.oldDirection = snake.direction;
		snake.direction = snake.RIGHT;
		break;
	default:
		break;
	}
}