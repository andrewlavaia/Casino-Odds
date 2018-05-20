#ifndef PLAYER_H
#define PLAYER_H

#include "table.h"
#include "wheel.h"

class Player {
public:
	Player(Table table, double cash = 1000);
	
	void placeBet(Bet bet);
	void win(Bet bet);
	void lose(Bet bet);

	bool isPlaying() const;
	double getCash() const;

private:
	Table table;
	double cash;
	bool playing;
	

};




#endif


