#include "player.h"

Player::Player(double cash)
	: cash(cash), playing(true) {
}

void Player::placeBet(Bet bet, Table& table) {
	table.placeBet(bet);
	double val = bet.getAmount();
	cash -= val;
}

void Player::win(Bet bet) {
	cash += bet.getAmount(); // original stake 
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

