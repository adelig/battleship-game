#include "RESET.h"
#include <iostream>
#include "PLAYER.h"

using namespace std;

void RESET()
{
	for (int plyr=1; plyr<3; ++plyr)
	{
		for (int w=0; w<elements; ++w){
			for (int h=0; h<rows; ++h){
				player[plyr].grid[w][h] = isWATER;
		}}
	}
}