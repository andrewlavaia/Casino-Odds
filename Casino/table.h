#ifndef TABLE_H
#define TABLE_H

#include "bet.h"
#include <unordered_set>

// Each table holds the bets for a single player
class Table {
public:
	Table(double limit = 10000, double minimum = 1);
	void placeBet(Bet bet);
	void removeBet(Bet bet);
	std::vector<Bet> getAllBets();

private: 
	double limit;
	double minimum;
	std::vector<Bet> bets;
	
};


#endif
