#include "game.h"

Game::Game(Table table, Wheel wheel)
	: table(table), wheel(wheel) {
}

// simulates a single player stepping up to the 
// game and initiating a round of play
void Game::play(Player player) {
	
	// gather bets
	std::vector<Bet> bets = table.getAllBets();
	
	// spin wheel
	Bin bin = wheel.spin();
	
	// resolve bets
	for (auto bet : bets) {
		if (bin.outcomeInBin(bet.getOutcome())) {
			player.adjustCash(bet.winAmount());
		}
	}
	
}