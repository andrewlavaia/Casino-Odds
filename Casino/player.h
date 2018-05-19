#ifndef PLAYER_H
#define PLAYER_H

#include "table.h"
#include "wheel.h"

class Player {
public:
	Player();
	void adjustCash(double amount);

private:
	double cash;

};




#endif


