#ifndef GAME_H
#define GAME_H

#include "table.h"
#include "wheel.h"
#include "player.h"
#include <vector>

class Game {
	Game(Table table, Wheel wheel);

	void addPlayer(Player player);
	void removePlayer(Player player);

	void gatherBets();
	void spinWheel();
	void resolveBets();

private:
	Table table;
	Wheel wheel;
	std::unordered_set<Player> players;

};



#endif
