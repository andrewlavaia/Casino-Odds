#include "table.h"

Table::Table(double limit, double minimum) :
	limit(limit), minimum(minimum) {

}

void Table::placeBet(Bet bet) {
	bets.push_back(bet);
}

void Table::removeBet(Bet bet) {
	//bets.erase(bet);
}

std::vector<Bet> Table::getAllBets() {
	return bets;
}

