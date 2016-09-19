#include "Food.h"

Food::Food()
{
	
}

Food::Food( int x, int y ):Point( x, y )
{
	x = x;
	y = y;
}

void Food::init( Snake &snake )
{

}

void Food::create( Snake &snake )
{
	setX( rand() % 98 - 49);
	setY( rand() % 98 - 49);
}

Food::~Food()
{
	
}
