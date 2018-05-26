#ifndef PLAYER_H
#define PLAYER_H

#include "bet.h"
#include "table.h"
#include "bin.h"

class Bin;
class Bet;
class Table;

class Player {
public:
	Player(double cash = 1000, double betPercent = .01);
	virtual void placeBets(Table& table) = 0;
	virtual void checkWinningBin(Bin& bin);
	void placeBet(Bet bet, Table& table);
	void win(Bet bet);
	void lose(Bet bet);

	bool isPlaying() const;
	double getCash() const;
	double getHighestCash() const;
	int getRoundsPlayed() const;

protected:
	double cash;
	const double originalCash;
	double highestCash;
	double betPercent;
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

class SevenReds : public Player {
public:
	SevenReds();
	void checkWinningBin(Bin& bin);
	void placeBets(Table& table);

private:
	int redCnt;
};



#endif


