#ifndef PLAYER_H
#define PLAYER_H

#include "bet.h"
#include "table.h"

class Player {
public:
	Player(double cash = 1000);
	
	void placeBet(Bet bet, Table& table);
	void win(Bet bet);
	void lose(Bet bet);

	bool isPlaying() const;
	double getCash() const;

private:
	double cash;
	bool playing;
	

};




#endif


