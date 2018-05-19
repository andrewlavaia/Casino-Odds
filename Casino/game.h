#ifndef GAME_H
#define GAME_H

#include "table.h"
#include "wheel.h"
#include "player.h"

class Game {
	Game(Table table, Wheel wheel);
	void play(Player player);

private:
	Table table;
	Wheel wheel;
};



#endif
