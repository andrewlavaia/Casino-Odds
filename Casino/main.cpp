#include <iostream>
#include <string>
#include <cassert>

#include "outcome.h"
#include "bin.h"
#include "wheel.h"
#include "binbuilder.h"
#include "table.h"
#include "game.h"
#include "simulator.h"

int main() {

	Wheel wheel;
	Table table;
	Game game(table, wheel);
	
	Player* playerA = new AlwaysBetOnRed();
	Player* playerB = new AlwaysBetOnBlack();
	
	Simulator sim(game, { playerA, playerB });
	sim.run();
	sim.printResults();

	return 0;
}