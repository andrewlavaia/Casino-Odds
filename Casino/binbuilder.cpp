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

void BinBuilder::populateRouletteBins(Wheel& wheel) {
	generateStraightBets(wheel);
	generateSplitBets(wheel);
	generateCornerBets(wheel);
	generateStreetBets(wheel);
	generateColumnBets(wheel);
	generateLineBets(wheel);
	generateDozenBets(wheel);
	generateEvenMoneyBets(wheel);
	generateBasketBet(wheel);
}

// Covers any single number
// Outcome name = "Number 1", "Number 2", ...
void BinBuilder::generateStraightBets(Wheel& wheel) {
	for (int i = 0; i < 37; ++i) {
		Outcome outcome("Number " + std::to_string(i), STRAIGHT_BET);
		wheel.addOutcome(i, outcome);
	}
	Outcome outcome("Number 00", STRAIGHT_BET);
	wheel.addOutcome(37, outcome);
}

// Covers two contiguous numbers
// Outcome name = "Split 1-2", "Split 2-3", ...
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

// Covers 4 contiguous numbers (1-2-4-5)
// Outcome name = "Corner 1-5", "Corner 2-6", ...
void BinBuilder::generateCornerBets(Wheel& wheel) {
	int x = 0;
	for (int r = 0; r < 11; ++r) {
		 x = (r * 3) + 1;
		 // repeate process for corners between first and second
		 // column and then between second and third column
		 for (int i = x; i <= x + 1; ++i) {
			 Outcome outcome("Corner " + std::to_string(i) +
				 "-" + std::to_string(i + 4), CORNER_BET);
			 wheel.addOutcome(i, outcome);
			 wheel.addOutcome(i + 1, outcome);
			 wheel.addOutcome(i + 3, outcome);
			 wheel.addOutcome(i + 4, outcome);
		 }
	}
}

// Covers three numbers in a row
// Outcome name = "Street 1-2-3", "Street 4-5-6", ...
void BinBuilder::generateStreetBets(Wheel& wheel) {
	for (int r = 0; r < 12; ++r) {
		int x = (r * 3) + 1;
		Outcome outcome("Street " + std::to_string(x) +
			"-" + std::to_string(x + 1) + "-" +
			std::to_string(x + 2), STREET_BET);
		wheel.addOutcome(x, outcome);
		wheel.addOutcome(x + 1, outcome);
		wheel.addOutcome(x + 2, outcome);
	}
}

// Covers all 12 numbers in a column (excludes 0 and 00)
// Outcome name = "Column 1-34", "Column 2-35", ...
void BinBuilder::generateColumnBets(Wheel& wheel) {
	Outcome outcome1("Column 1-34", COLUMN_BET);
	Outcome outcome2("Column 2-35", COLUMN_BET);
	Outcome outcome3("Column 3-36", COLUMN_BET);

	for (int n = 1; n < 37; ++n) {
		if (n % 3 == 1)
			wheel.addOutcome(n, outcome1);
		else if (n % 3 == 2)
			wheel.addOutcome(n, outcome2);
		else
			wheel.addOutcome(n, outcome3);
	}
}

// Covers six numbers in two contiguous rows
// Outcome name = "Line 1-6", "Line 4-9", ...
void BinBuilder::generateLineBets(Wheel& wheel) {
	for (int r = 0; r < 11; ++r) {
		int x = (r * 3) + 1;
		Outcome outcome("Line " + std::to_string(x) +
			"-" + std::to_string(x + 5), LINE_BET);
		for (int i = 0; i < 6; ++i) {
			wheel.addOutcome(x + i, outcome);
		}
	}
}

// Covers 1-12, 13-24, or 25-36
// Outcome name = "Dozen 1-12", "Dozen 13-24", ...
void BinBuilder::generateDozenBets(Wheel& wheel) {
	Outcome outcome1("Dozen 1-12", DOZEN_BET);
	Outcome outcome2("Dozen 13-24", DOZEN_BET);
	Outcome outcome3("Dozen 25-36", DOZEN_BET);

	for (int n = 1; n < 37; ++n) {
		if (n <= 12)
			wheel.addOutcome(n, outcome1);
		else if (n > 12 && n <= 24)
			wheel.addOutcome(n, outcome2);
		else
			wheel.addOutcome(n, outcome3);
	}
}

// Covers red/black, even/odd, and hi/lo
// Output name = "Red", "Even", "Hi", ...
void BinBuilder::generateEvenMoneyBets(Wheel& wheel) {
	Outcome red("Red", EVEN_BET);
	Outcome black("Black", EVEN_BET);
	Outcome even("Even", EVEN_BET);
	Outcome odd("Odd", EVEN_BET);
	Outcome hi("Hi", EVEN_BET);
	Outcome lo("Lo", EVEN_BET);
	std::unordered_set<int> reds = {1, 3, 5, 7, 9, 
				12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 
				32, 34, 36};

	for (int n = 1; n < 37; ++n) {
		if (n % 2 == 0)
			wheel.addOutcome(n, even);
		else
			wheel.addOutcome(n, odd);

		if (n <= 18)
			wheel.addOutcome(n, lo);
		else
			wheel.addOutcome(n, hi);

		if (reds.find(n) != reds.end())
			wheel.addOutcome(n, red);
		else
			wheel.addOutcome(n, black);
	}
}

// Covers 1, 2, 3, 0, and 00
// Output name = "Basket"
void BinBuilder::generateBasketBet(Wheel& wheel) {
	Outcome outcome("Basket", BASKET_BET);
	wheel.addOutcome(0, outcome);
	wheel.addOutcome(1, outcome);
	wheel.addOutcome(2, outcome);
	wheel.addOutcome(3, outcome);
	wheel.addOutcome(37, outcome);
}