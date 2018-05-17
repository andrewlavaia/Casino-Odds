#ifndef PLAYER_H
#define PLAYER_H

#include "table.h"
#include "wheel.h"

class Player {
public:
	Player(Table table, Wheel wheel);
	void placeBet();

private:
	double cash;

	// temporarily hold table and wheel in player 
	// should probably switch these to pointers if 
	// keeping this interface
	Table table; 
	Wheel wheel;

};




#endif


