#ifndef _FOOD_H_
#define _FOOD_H_
#include "Food.h"
#include "Snake.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class Food:public Point
{
public:
	Food();
	Food(int x, int y);
	~Food();
	void init( Snake &snake );
	void create( Snake &snake );
};

#endif