#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include <string>
#include <string.h>
#include <ctype.h>
#include "POINT.h"
#include "SHIP.h"
#include "PLAYER.h"
#include "PLACESHIPS.h"
#include "LoadShips.h"
#include "InputAttack.h"
#include "RESET.h"
#include "InputAttack.h"
#include "DIRECTION.h"
#include "SHOW.h"
#include "InputShipPosition.h"
#include "GameOverCheck.h"



using namespace std;


const char isHIT = 'H';
const char miss = 'M';

PLAYER player[3];
SHIP ship[SHIP_TYPES];

// functions
void LoadShips();
void RESET();
void SHOW(int, bool);
PLACESHIPS InputShipPosition();
bool InputAttack(int&,int&,int);
bool GameOverCheck(int);



int main()
{
	bool gameRunning = false;
	LoadShips();
	RESET();
	
	// "place ships" phase of game
	for (int aplyr=1; aplyr<3; ++aplyr)
	{
		for (int thisShip=0; thisShip<SHIP_TYPES; ++thisShip)
		{
			// display grid for player
			system ("clear");
			SHOW(aplyr,gameRunning);
			
			cout << "\n\n";
			cout << "\033[1;34mPlayer " << aplyr << ", you are about to place your ships.  Format should be:\033[0m\n";
			cout << "\033[1;34mFacing (0:Horizontal,1:Vertical), X - axis coords, Y - axis coords\033[0m\n";
			cout << "\033[1;34mShip to place: " << ship[thisShip].name << " which has a length of " << ship[thisShip].length  << "\n"<<"\033[0m\n";
			cout << "\033[1;34mWhere do you want to be placed? \033[0m";
			
			// get input from user and loop until good data is returned
			PLACESHIPS aShip;
			aShip.shipType.onGrid[0].X = -1;
			while (aShip.shipType.onGrid[0].X == -1)
			{
				aShip = InputShipPosition();
			}

			// combine user data with "this ship" data
			aShip.shipType.length = ship[thisShip].length;
			aShip.shipType.name = ship[thisShip].name;

			// determine ALL grid points based on length and direction
			for (int i=0; i<aShip.shipType.length; ++i)
			{
				if (aShip.direction == HORIZONTAL){
					aShip.shipType.onGrid[i+1].X = aShip.shipType.onGrid[i].X+1;
					aShip.shipType.onGrid[i+1].Y = aShip.shipType.onGrid[i].Y; }
				if (aShip.direction == VERTICAL){
					aShip.shipType.onGrid[i+1].Y = aShip.shipType.onGrid[i].Y+1;
					aShip.shipType.onGrid[i+1].X = aShip.shipType.onGrid[i].X; }
				
				player[aplyr].grid[aShip.shipType.onGrid[i].X][aShip.shipType.onGrid[i].Y] = isSHIP;
			}
		}
	}

	// main phase of the game
	
	gameRunning = true;
	int thisPlayer = 1;
	int enemyPlayer;
	int x,y;
	while (gameRunning){
		if (thisPlayer == 1) enemyPlayer = 2;
		if (thisPlayer == 2) enemyPlayer = 1;
		
		cout<<endl<<endl;
		system ("clear");
		SHOW(enemyPlayer,gameRunning);

		// get attacking coords
		bool goodInput = false;
		while (goodInput == false) {
			goodInput = InputAttack(x,y,thisPlayer);
		} 
		// check board if a ship is there, set as hit, otherwise miss
		if (player[enemyPlayer].grid[x][y] == isSHIP) player[enemyPlayer].grid[x][y] = isHIT;
		if (player[enemyPlayer].grid[x][y] == isWATER) player[enemyPlayer].grid[x][y] = miss;

		// check to see if the game is over
		int aWin = GameOverCheck(enemyPlayer);
		if (aWin != 0) {
			gameRunning = false;
			break;
		}
		thisPlayer = (thisPlayer == 1) ? 2 : 1;
	} 

	system ("clear"); 

	cout << "\033[1;35m\n\nCONGRATULATIONS!!!  PLAYER " << thisPlayer << " wins!\033[0m\n\n\n\n";
	
	cin.ignore().get();
	
	return 0;
}