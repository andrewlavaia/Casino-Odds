#ifndef TABLE_H
#define TABLE_H

#include "bet.h"
#include <unordered_set>

class Table {
public:
	void placeBet(Bet bet);
	void removeBet(Bet bet);

private: 
	double limit;
	double minimum;
	std::unordered_set<Bet> bets;
	
};


#endif
