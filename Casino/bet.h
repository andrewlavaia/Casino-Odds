#ifndef BET_H
#define BET_H

#include "outcome.h"
#include <string>

class Bet {
public:
	Bet(double amount, Outcome outcome);

	double winAmount() const;
	double loseAmount() const;
	std::string toString() const;

private:
	double amount;
	Outcome outcome;
};


#endif


