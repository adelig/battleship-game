#include "InputShipPosition.h"
#include <iostream>
#include "DIRECTION.h"
#include "SHIP.h"
#include "PLACESHIPS.h"

using namespace std;

const int rows = 10;
const int elements = 10;
PLACESHIPS InputShipPosition()
{
	int d, x, y;
	
	PLACESHIPS tmp;
	
	tmp.shipType.onGrid[0].X = -1;
	
	cin >> d >> x >> y; 
	if (d!=0 && d!=1) return tmp;
	if (x<0 || x>=elements) return tmp;
	if (y<0 || y>=rows) return tmp;
	
	tmp.direction = (DIRECTION)d;
	tmp.shipType.onGrid[0].X = x;
	tmp.shipType.onGrid[0].Y = y;
	return tmp;
}
