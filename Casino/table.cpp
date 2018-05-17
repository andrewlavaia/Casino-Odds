#include "table.h"

void Table::placeBet(Bet bet) {
	bets.insert(bet);
}

void Table::removeBet(Bet bet) {
	bets.erase(bet);
}

