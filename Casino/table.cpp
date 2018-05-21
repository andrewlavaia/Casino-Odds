#include "table.h"

Table::Table(double limit, double minimum) :
	limit(limit), minimum(minimum) {
}

void Table::placeBet(Bet bet) {
	bets.push_back(bet);
}

void Table::placeAllBets(std::vector<Bet> newBets) {
	std::swap(bets, newBets);
}

void Table::clearAllBets() {
	bets.clear();
}

std::vector<Bet> Table::getAllBets() const {
	return bets;
}

