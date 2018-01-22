#ifndef LoadShips_H
#define	LoadShips_H
#include "SHIP.h"
#include <string>

using namespace std;
void LoadShips()
{
	ship[0].name = "Patrol"; ship[0].length = 2;
	ship[1].name = "Destroyer"; ship[1].length = 3;
	ship[2].name = "Submarine"; ship[2].length = 3;
	ship[3].name = "Battleship"; ship[3].length = 4;
	ship[4].name = "Aircraft Carrier"; ship[4].length = 5;
}

#endif