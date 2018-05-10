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
	void generateSplitBets(Wheel& wheel);
	void generateCornerBets(Wheel& wheel);
	void generateRowBets(Wheel& wheel);
	void generateColumnBets(Wheel& wheel);
	void generateLowMidHiBets(Wheel& wheel);
	void generateEvenMoneyBets(Wheel& wheel);

private: 

};


#endif