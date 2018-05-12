#ifndef BINBUILDER_H
#define BINBUILDER_H

#include <array>
#include "wheel.h"
#include "bin.h"
#include "outcome.h"

// creates all of the outcomes for the 
// 38 bins of a roulette wheel

class BinBuilder {
public:
	static void generateStraightBets(Wheel& wheel);
	static void generateSplitBets(Wheel& wheel);
	static void generateCornerBets(Wheel& wheel);
	static void generateStreetBets(Wheel& wheel);
	static void generateColumnBets(Wheel& wheel);
	static void generateLineBets(Wheel& wheel);
	static void generateDozenBets(Wheel& wheel);
	static void generateEvenMoneyBets(Wheel& wheel);
	static void generateBasketBet(Wheel& wheel);

private: 

};


#endif