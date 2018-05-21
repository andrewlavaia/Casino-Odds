#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include "bet.h"

class Bet;

// The table manages the bets for each player
class Table {
public:
	Table(double limit = 1000, double minimum = 1);
	void placeBet(Bet bet);
	void placeAllBets(std::vector<Bet> newBets);
	void clearAllBets();
	std::vector<Bet> getAllBets() const;
	
private: 
	double limit;
	double minimum;
	std::vector<Bet> bets;
	
};


#endif
