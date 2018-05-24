#ifndef GAME_H
#define GAME_H

#include "table.h"
#include "wheel.h"
#include "bet.h"

class Game {
public:
	Game(Table& table, const Wheel& wheel);
	void play();
	Table& getTable();

private:
	Table& table;
	const Wheel& wheel;
};



#endif
