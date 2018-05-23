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
	
	Player playerA(1000);
	Player playerB(5000);
	
	Simulator sim(game, { playerA, playerB });

	return 0;
}