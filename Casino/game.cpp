#include "game.h"

Game::Game(Table table, Wheel wheel)
	: table(table), wheel(wheel) {
}

// simulates a single round of betting,
// spinning the wheel, and resolving outcomes
void Game::play() {
	
	// gather bets
	std::vector<PlayerBet> bets = table.getAllBets();
	
	// spin wheel
	Bin bin = wheel.spin();
	
	// resolve bets
	for (auto pb : bets) {
		if (bin.outcomeInBin(pb.bet.getOutcome())) {
			pb.player.win(pb.bet);
		}
		else {
			pb.player.lose(pb.bet);
		}
	}
	
}