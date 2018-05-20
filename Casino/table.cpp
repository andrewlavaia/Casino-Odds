#include "table.h"

Table::Table(double limit, double minimum) :
	limit(limit), minimum(minimum) {
}

void Table::placeBet(Bet bet) {
	//bets.push_back();
}

std::vector<Bet> Table::getAllBets() const {
	return bets;
}

