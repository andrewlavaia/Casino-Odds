#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include "game.h"

class Simulator {
public:
	Simulator(Game game, std::vector<Player> players,
			int rounds = 250);

	void run();
	void printResults();

private:
	Game game;
	std::vector<Player> players;
	int rounds;	
};


#endif

