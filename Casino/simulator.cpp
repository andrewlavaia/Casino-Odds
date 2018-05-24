#include "simulator.h"

Simulator::Simulator(Game game, std::vector<Player> players,
	int rounds) : game(game), players(players), rounds(rounds) {

}

void Simulator::run() {
	for (int i = 0; i < rounds; ++i) {

		for (auto& player : players) {
			if (player.isPlaying()) {
				player.placeBets(game.getTable());
			}
		}

		game.play();
	}
}

void Simulator::printResults() {
	for (auto player : players) {
		std::cout << "Ending Cash: " << player.getCash() << std::endl;
		std::cout << "Highest Cash: " << player.getHighestCash() << std::endl;
		std::cout << "Rounds Played: " << player.getRoundsPlayed() << std::endl;
		std::cout << std::endl;
	}
}