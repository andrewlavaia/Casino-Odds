#include "bet.h"

Bet::Bet(double amount, Outcome outcome)
	: amount(amount), outcome(outcome) {

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

Outcome Bet::getOutcome() const {
	return outcome;
}
