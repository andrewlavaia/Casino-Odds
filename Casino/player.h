#ifndef PLAYER_H
#define PLAYER_H

#include "bet.h"
#include "table.h"

class Bet;
class Table;

class Player {
public:
	Player(double cash = 1000);
	
	void placeBet(Bet bet, Table& table);
	void placeBets(Table& table);
	void win(Bet bet);
	void lose(Bet bet);

	bool isPlaying() const;
	double getCash() const;
	double getHighestCash() const;
	int getRoundsPlayed() const;

private:
	double cash;
	double highestCash;
	bool playing;
	int roundsPlayed;
};




#endif


