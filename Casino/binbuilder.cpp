#include "binbuilder.h"

// odds
const double STRAIGHT_BET = 35;
const double SPLIT_BET = 17;
const double STREET_BET = 11;
const double CORNER_BET = 8;
const double BASKET_BET = 6;
const double LINE_BET = 5;
const double COLUMN_BET = 2;
const double DOZEN_BET = 2;
const double EVEN_BET = 1;

void BinBuilder::generateStraightBets(Wheel& wheel) {
	for (int i = 0; i < 37; ++i) {
		Outcome outcome("Number " + std::to_string(i), STRAIGHT_BET);
		wheel.addOutcome(i, outcome);
	}
	Outcome outcome("Number 00", STRAIGHT_BET);
	wheel.addOutcome(37, outcome);
}

// covers two contiguous numbers
void BinBuilder::generateSplitBets(Wheel& wheel) {
	int rows = 12;
	int x = 0;

	for (int r = 0; r < rows; ++r) {
		// add split for first column and second column (1-2, 4-5, etc)
		x = (r * 3) + 1;
		Outcome outcome("Split " + std::to_string(x) +
				"-" + std::to_string(x + 1), SPLIT_BET);
		wheel.addOutcome(x, outcome);
		wheel.addOutcome(x + 1, outcome);

		// add split for second column and third column (2-3, 5-6, etc)
		x = (r * 3) + 2;
		Outcome outcome2("Split " + std::to_string(x) +
			"-" + std::to_string(x + 1), SPLIT_BET);
		wheel.addOutcome(x, outcome2);
		wheel.addOutcome(x + 1, outcome2);
	}

	// add split for above and below (1-4, 4-7, etc)
	for (int n = 1; n < 34; ++n) {
		Outcome outcome("Split " + std::to_string(n) +
			"-" + std::to_string(n + 3), SPLIT_BET);
		wheel.addOutcome(n, outcome);
		wheel.addOutcome(n + 3, outcome);
	}

	// add zero splits
	Outcome outcome("Split 0-00", SPLIT_BET);
	wheel.addOutcome(0, outcome);
	wheel.addOutcome(37, outcome);
}

// covers 4 contiguous numbers
void BinBuilder::generateCornerBets(Wheel& wheel) {

}

// covers three numbers in a row
void BinBuilder::generateStreetBets(Wheel& wheel) {

}

// covers all 12 numbers in a column (excludes 0 and 00)
void BinBuilder::generateColumnBets(Wheel& wheel) {

}

// covers six numbers in two contiguous rows
void BinBuilder::generateLineBets(Wheel& wheel) {

}

// covers 1-12, 13-24, or 25-36
void BinBuilder::generateDozenBets(Wheel& wheel) {

}

// covers red/black, even/odd, and hi/lo
void BinBuilder::generateEvenMoneyBets(Wheel& wheel) {

}

// covers 1, 2, 3, 0, and 00
void BinBuilder::generateBasketBet(Wheel& wheel) {

}