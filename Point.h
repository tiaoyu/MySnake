#ifndef _POINT_H_
#define _POINT_H_

class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();
	void setX( int x );
	int getX();
	void setY( int y );
	int getY();
private:
	int x;
	int y;	
};

#endif