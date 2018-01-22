#include "InputAttack.h"
#include <iostream>
#include "PLAYER.h"
#include <cstdio>
#include <stdio.h>
#include <cstdlib>

using namespace std;


bool InputAttack(int& x, int& y, int theplayer)
{
	cout << "\nPLAYER " << theplayer << ", ENTER COORDINATES TO ATTACK: ";
	bool goodInput = false;
	cin >> x >> y;
	if (x<0 || x>=elements) return goodInput;
	if (y<0 || y>=rows) return goodInput;
	goodInput = true; 
	return goodInput;
}