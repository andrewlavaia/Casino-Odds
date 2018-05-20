#ifndef BET_H
#define BET_H

#include "outcome.h"
#include <string>

class Bet {
public:
	Bet(double amount, Outcome outcome);

	double winAmount() const;
	std::string toString() const;
	double getAmount() const;
	Outcome getOutcome() const;

private:
	double amount;
	Outcome outcome;
};

#endif


