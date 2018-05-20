#ifndef GAME_H
#define GAME_H

#include "table.h"
#include "wheel.h"

class Player;
class Bet;

class Game {
	Game(Table table, Wheel wheel);
	void play();

private:
	Table table;
	Wheel wheel;
};



#endif
