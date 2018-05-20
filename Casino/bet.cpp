#include "bet.h"

Bet::Bet(double amount, Outcome outcome, Player& player)
	: amount(amount), outcome(outcome), player(player) {

}

void Bet::win() {
	player.win(*this);
}

void Bet::lose() {
	player.lose(*this);
}

double Bet::winAmount() const {
	return outcome.winAmount(amount);
}

std::string Bet::toString() const {
	std::string str = "";
	
	std::string amountStr = std::to_string(amount);
	int offset = 1;
	if (amountStr.find_last_not_of('0') == amountStr.find('.')) {
		offset = 0;
	}
	amountStr.erase(amountStr.find_last_not_of('0') + offset, std::string::npos);
	
	str = amountStr + " on " 
		+ outcome.getName() + " at " + outcome.oddsToString();
	return str;
}

double Bet::getAmount() const {
	return amount;
}

Outcome Bet::getOutcome() const {
	return outcome;
}
