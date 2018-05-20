#include "table.h"

Table::Table(double limit, double minimum) :
	limit(limit), minimum(minimum) {
}

void Table::placeBet(PlayerBet pb) {
	bets.push_back(pb);
}

std::vector<PlayerBet> Table::getAllBets() const {
	return bets;
}

