#ifndef SHIP_H
#define	SHIP_H
#include "POINT.h"
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>


using namespace std;

const int SHIP_TYPES = 5;

class SHIP {
public:	
	string name; //Ship name	
	int length;  //Total points on the grid	
	POINT onGrid[5];  //0-4 max length of biggest ship	
	bool isHITFlag[5];  //Whether or not those points are a "isHIT"
	~SHIP() {}  // destructor
};

extern SHIP ship[SHIP_TYPES];

#endif