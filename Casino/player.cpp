#include "player.h"

Player::Player(Table table, double cash)
	: table(table), cash(cash), playing(true) {

}

void Player::placeBet(Bet bet) {
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

