#ifndef PLAYER_H
#define PLAYER_H

#include "bet.h"
#include "table.h"

class Bet;
class Table;

class Player {
public:
	Player(double cash = 1000);
	
	virtual void placeBets(Table& table);
	void placeBet(Bet bet, Table& table);
	void win(Bet bet);
	void lose(Bet bet);

	bool isPlaying() const;
	double getCash() const;
	double getHighestCash() const;
	int getRoundsPlayed() const;

protected:
	double cash;
	double highestCash;
	bool playing;
	int roundsPlayed;
};

class AlwaysBetOnBlack : public Player {
public:
	void placeBets(Table& table);
};

class AlwaysBetOnRed : public Player {
public:
	void placeBets(Table& table);
};




#endif


