#ifndef BET_H
#define BET_H

#include <string>
#include "outcome.h"

class Player;

class Bet {
public:
	Bet(double amount, Outcome outcome, 
		const Player& player);

	double winAmount() const;
	std::string toString() const;
	double getAmount() const;
	Outcome getOutcome() const;

private:
	double amount;
	Outcome outcome;
	const Player& player;
};

#endif


