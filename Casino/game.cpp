#include "game.h"

Game::Game(Table& table, const Wheel& wheel)
	: table(table), wheel(wheel) {
}

// simulates a single round of betting,
// spinning the wheel, and resolving outcomes
void Game::play() {
	
	// gather bets
	std::vector<Bet> bets = table.getAllBets();
	
	// spin wheel
	Bin bin = wheel.spin();
	
	// resolve bets
	for (auto bet : bets) {
		if (bin.containsOutcome(bet.getOutcome())) {
			bet.win();
		}
		else {
			bet.lose();
		}
	}

	// clear bets from table
	table.clearAllBets();
}