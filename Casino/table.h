#ifndef TABLE_H
#define TABLE_H

#include "playerbet.h"
#include <vector>

// The table manages the bets for each player
class Table {
public:
	Table(double limit = 1000, double minimum = 1);
	void placeBet(PlayerBet pb);
	std::vector<PlayerBet> getAllBets() const;
	
private: 
	double limit;
	double minimum;
	std::vector<PlayerBet> bets;
	
};


#endif
