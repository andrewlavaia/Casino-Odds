#ifndef BET_H
#define BET_H

#include "outcome.h"
#include <string>


// should tie these to individual players
// player's wallets will be debited upon 
// placing bets

class Bet {
public:
	Bet(double amount, Outcome outcome);

	double winAmount() const;
	std::string toString() const;

private:
	double amount;
	Outcome outcome;
};


#endif


