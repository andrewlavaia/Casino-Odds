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
	BinBuilder(Wheel& wheel);
	void buildBins();

private: 
	void generateStraightBets();
	void generateSplitBets();
	void generateCornerBets();
	void generateRowBets();
	void generateColumnBets();
	void generateEvenMoneyBets();
};


#endif