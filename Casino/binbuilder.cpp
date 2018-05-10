#include "binbuilder.h"

// odds
const double STRAIGHT_BET = 35;

void BinBuilder::generateStraightBets(Wheel& wheel) {
	for (int i = 0; i < 37; ++i) {
		Outcome outcome("Number " + std::to_string(i), STRAIGHT_BET);
		wheel.addOutcome(i, outcome);
	}
	Outcome outcome("Number 00", STRAIGHT_BET);
	wheel.addOutcome(37, outcome);
}

void BinBuilder::generateSplitBets(Wheel& wheel) {

}

void BinBuilder::generateCornerBets(Wheel& wheel) {

}

void BinBuilder::generateRowBets(Wheel& wheel) {

}

void BinBuilder::generateColumnBets(Wheel& wheel) {

}

void BinBuilder::generateLowMidHiBets(Wheel& wheel) {

}

void BinBuilder::generateEvenMoneyBets(Wheel& wheel) {

}