#ifndef BET_H
#define BET_H

#include <string>
#include "outcome.h"
#include "player.h"

class Player;

class Bet {
public:
	Bet(double amount, Outcome outcome, Player& player);

	// alert player of result 
	void win(); 
	void lose();

	double winAmount() const;
	std::string toString() const;

	double getAmount() const;
	Outcome getOutcome() const;

private:
	double amount;
	Outcome outcome;
	Player& player;
};

#endif


