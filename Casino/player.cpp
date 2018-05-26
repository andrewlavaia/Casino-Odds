#include "player.h"

Player::Player(double cash, double betPercent)
	: cash(cash), originalCash(cash), highestCash(cash), 
	betPercent(betPercent), playing(true), roundsPlayed(0) {
}

void Player::placeBet(Bet bet, Table& table) {
	table.placeBet(bet);
	cash -= bet.getAmount(); 
}

void Player::checkWinningBin(Bin& bin) {
	// do nothing by default
}

void Player::win(Bet bet) {
	cash += bet.getAmount(); // original stake 
	cash += bet.winAmount(); 
	if (cash > highestCash)
		highestCash = cash;
}

void Player::lose(Bet bet) {

}

bool Player::isPlaying() const {
	return playing;
}

double Player::getCash() const {
	return cash;
}

double Player::getHighestCash() const {
	return highestCash;
}

int Player::getRoundsPlayed() const {
	return roundsPlayed;
}



// -------------------------

void AlwaysBetOnBlack::placeBets(Table& table) {
	if (isPlaying()) {
		Outcome o1("Black", 1);
		Bet bet(betPercent * originalCash, o1, *this);
		placeBet(bet, table);

		++roundsPlayed;
	}
}

void AlwaysBetOnRed::placeBets(Table& table) {
	if (isPlaying()) {
		Outcome o1("Red", 1);
		Bet bet(betPercent * originalCash, o1, *this);
		placeBet(bet, table);

		++roundsPlayed;
	}
}

SevenReds::SevenReds() : redCnt(0) {
	playing = false;
}

void SevenReds::checkWinningBin(Bin& bin) {
	if (bin.containsOutcome({ "Red", 1 })) 
		++redCnt;
	else 
		redCnt = 0;	

	if (redCnt >= 7)
		playing = true;
	else
		playing = false;

}

void SevenReds::placeBets(Table& table) {
	if (isPlaying()) {
		Outcome o1("Red", 1);
		Bet bet(betPercent * originalCash, o1, *this);
		placeBet(bet, table);

		++roundsPlayed;
	}
}