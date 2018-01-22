#ifndef PLACESHIPS_H
#define	PLACESHIPS_H
#include "SHIP.h"
#include "DIRECTION.h"


class PLACESHIPS {
public:
	DIRECTION direction;
	SHIP shipType;
	~PLACESHIPS() {}   // destructor
};

#endif