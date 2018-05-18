#include "game.h"

Game::Game(Table table, Wheel wheel)
	: table(table), wheel(wheel) {
}

void Game::addPlayer(Player player) {
	players.insert(player);
}

void Game::removePlayer(Player player) {
	players.erase(player);
}

void Game::gatherBets() {
	for (auto& player : players) {

	}
}

void Game::spinWheel() {

}

void Game::resolveBets() {

}