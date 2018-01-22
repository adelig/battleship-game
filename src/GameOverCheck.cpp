#include "GameOverCheck.h"
#include <iostream>
#include "PLAYER.h"

using namespace std;

const char isSHIP = 'S';
bool GameOverCheck(int enemyPLAYER)
{
	bool winner = true;
	
	for (int w=0; w<elements; ++w){
			for (int h=0; h<rows; ++h){
				
				if (player[enemyPLAYER].grid[w][h] == isSHIP)
					{
						winner = false;
						return winner;
					}
				}
	  
	}
	
	return winner;
}
