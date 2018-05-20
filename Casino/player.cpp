#include "player.h"

Player::Player(double cash)
	: cash(cash), playing(true) {
}

void Player::placeBet(Bet bet, Table& table) {
	table.placeBet(bet);
}

void Player::win(Bet bet) {
	cash += bet.winAmount();
}

void Player::lose(Bet bet) {

}

bool Player::isPlaying() const {
	return playing;
}

double Player::getCash() const {
	return cash;
}

