#include "game.h"

Game::Game(Table table, Wheel wheel)
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
		if (bin.outcomeInBin(bet.getOutcome())) {
			//pb.first.win(pb.second);
			//std::cout << pb.second.toString();
		}
		else {
			//pb.first.lose(pb.second);
		}
	}
	
}