#ifndef PLAYER_H
#define	PLAYER_H
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>


const int rows = 10;
const int elements = 10;


class PLAYER {
public:
	char grid[elements][rows];
	~PLAYER() {}  // destructor
};

extern PLAYER player[3];

#endif