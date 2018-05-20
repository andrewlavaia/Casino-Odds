#include "pch.h"
#include "../casino/wheel.h"
#include "../Casino/binbuilder.h"
#include "../casino/bin.h"
#include "../casino/outcome.h"

TEST(BinBuilderTests, CheckStraightBets) {
	Wheel wheel;

	for (int i = 0; i < 37; ++i) {
		Outcome outcome("Number " + std::to_string(i), 35);
		EXPECT_EQ(wheel.getBin(i).containsOutcome(outcome), true);
	}

	Outcome a("Number 00", 35);
	EXPECT_EQ(wheel.getBin(37).containsOutcome(a), true);
}

TEST(BinBuilderTests, CheckSplitBets) {
	Wheel wheel;

	Outcome outcome23("Split 2-3", 17);
	EXPECT_EQ(wheel.getBin(2).containsOutcome(outcome23), true);
	EXPECT_EQ(wheel.getBin(3).containsOutcome(outcome23), true);
	EXPECT_EQ(wheel.getBin(4).containsOutcome(outcome23), false);

	Outcome outcome3435("Split 34-35", 17);
	EXPECT_EQ(wheel.getBin(34).containsOutcome(outcome3435), true);
	EXPECT_EQ(wheel.getBin(35).containsOutcome(outcome3435), true);
	EXPECT_EQ(wheel.getBin(36).containsOutcome(outcome3435), false);

	Outcome outcome47("Split 4-7", 17);
	EXPECT_EQ(wheel.getBin(4).containsOutcome(outcome47), true);
	EXPECT_EQ(wheel.getBin(7).containsOutcome(outcome47), true);
	EXPECT_EQ(wheel.getBin(5).containsOutcome(outcome47), false);

	Outcome outcome000("Split 0-00", 17);
	EXPECT_EQ(wheel.getBin(0).containsOutcome(outcome000), true);
	EXPECT_EQ(wheel.getBin(37).containsOutcome(outcome000), true);
	EXPECT_EQ(wheel.getBin(1).containsOutcome(outcome000), false);
}

TEST(BinBuilderTests, CheckStreetBets) {
	Wheel wheel;

	Outcome outcome123("Street 1-2-3", 11);
	EXPECT_EQ(wheel.getBin(1).containsOutcome(outcome123), true);
	EXPECT_EQ(wheel.getBin(2).containsOutcome(outcome123), true);
	EXPECT_EQ(wheel.getBin(3).containsOutcome(outcome123), true);
	EXPECT_EQ(wheel.getBin(4).containsOutcome(outcome123), false);

	Outcome outcome343536("Street 34-35-36", 11);
	EXPECT_EQ(wheel.getBin(34).containsOutcome(outcome343536), true);
	EXPECT_EQ(wheel.getBin(35).containsOutcome(outcome343536), true);
	EXPECT_EQ(wheel.getBin(36).containsOutcome(outcome343536), true);
	EXPECT_EQ(wheel.getBin(37).containsOutcome(outcome343536), false);
}

TEST(BinBuilderTests, CheckLineBets) {
	Wheel wheel;

	Outcome outcome16("Line 1-6", 5);
	EXPECT_EQ(wheel.getBin(1).containsOutcome(outcome16), true);
	EXPECT_EQ(wheel.getBin(2).containsOutcome(outcome16), true);
	EXPECT_EQ(wheel.getBin(3).containsOutcome(outcome16), true);
	EXPECT_EQ(wheel.getBin(4).containsOutcome(outcome16), true);
	EXPECT_EQ(wheel.getBin(5).containsOutcome(outcome16), true);
	EXPECT_EQ(wheel.getBin(6).containsOutcome(outcome16), true);
	EXPECT_EQ(wheel.getBin(0).containsOutcome(outcome16), false);
	EXPECT_EQ(wheel.getBin(7).containsOutcome(outcome16), false);

	Outcome outcome3136("Line 31-36", 5);
	EXPECT_EQ(wheel.getBin(31).containsOutcome(outcome3136), true);
	EXPECT_EQ(wheel.getBin(32).containsOutcome(outcome3136), true);
	EXPECT_EQ(wheel.getBin(33).containsOutcome(outcome3136), true);
	EXPECT_EQ(wheel.getBin(34).containsOutcome(outcome3136), true);
	EXPECT_EQ(wheel.getBin(35).containsOutcome(outcome3136), true);
	EXPECT_EQ(wheel.getBin(36).containsOutcome(outcome3136), true);
	EXPECT_EQ(wheel.getBin(37).containsOutcome(outcome3136), false);
}

TEST(BinBuilderTests, CheckCornerBets) {
	Wheel wheel;

	Outcome outcome15("Corner 1-5", 8);
	EXPECT_EQ(wheel.getBin(1).containsOutcome(outcome15), true);
	EXPECT_EQ(wheel.getBin(2).containsOutcome(outcome15), true);
	EXPECT_EQ(wheel.getBin(4).containsOutcome(outcome15), true);
	EXPECT_EQ(wheel.getBin(5).containsOutcome(outcome15), true);
	EXPECT_EQ(wheel.getBin(0).containsOutcome(outcome15), false);
	EXPECT_EQ(wheel.getBin(3).containsOutcome(outcome15), false);

	Outcome outcome3236("Corner 32-36", 8);
	EXPECT_EQ(wheel.getBin(32).containsOutcome(outcome3236), true);
	EXPECT_EQ(wheel.getBin(33).containsOutcome(outcome3236), true);
	EXPECT_EQ(wheel.getBin(35).containsOutcome(outcome3236), true);
	EXPECT_EQ(wheel.getBin(36).containsOutcome(outcome3236), true);
	EXPECT_EQ(wheel.getBin(34).containsOutcome(outcome3236), false);
}

TEST(BinBuilderTests, CheckColumnBets) {
	Wheel wheel;

	Outcome outcome1("Column 1-34", 2);
	EXPECT_EQ(wheel.getBin(1).containsOutcome(outcome1), true);
	EXPECT_EQ(wheel.getBin(4).containsOutcome(outcome1), true);
	EXPECT_EQ(wheel.getBin(7).containsOutcome(outcome1), true);
	EXPECT_EQ(wheel.getBin(34).containsOutcome(outcome1), true);
	EXPECT_EQ(wheel.getBin(0).containsOutcome(outcome1), false);
	EXPECT_EQ(wheel.getBin(3).containsOutcome(outcome1), false);
	EXPECT_EQ(wheel.getBin(35).containsOutcome(outcome1), false);

	Outcome outcome2("Column 2-35", 2);
	EXPECT_EQ(wheel.getBin(2).containsOutcome(outcome2), true);
	EXPECT_EQ(wheel.getBin(5).containsOutcome(outcome2), true);
	EXPECT_EQ(wheel.getBin(8).containsOutcome(outcome2), true);
	EXPECT_EQ(wheel.getBin(35).containsOutcome(outcome2), true);
	EXPECT_EQ(wheel.getBin(34).containsOutcome(outcome2), false);
	EXPECT_EQ(wheel.getBin(6).containsOutcome(outcome2), false);

	Outcome outcome3("Column 3-36", 2);
	EXPECT_EQ(wheel.getBin(3).containsOutcome(outcome3), true);
	EXPECT_EQ(wheel.getBin(6).containsOutcome(outcome3), true);
	EXPECT_EQ(wheel.getBin(9).containsOutcome(outcome3), true);
	EXPECT_EQ(wheel.getBin(36).containsOutcome(outcome3), true);
	EXPECT_EQ(wheel.getBin(1).containsOutcome(outcome3), false);
	EXPECT_EQ(wheel.getBin(8).containsOutcome(outcome3), false);
	EXPECT_EQ(wheel.getBin(37).containsOutcome(outcome3), false);
}

TEST(BinBuilderTests, CheckDozenBets) {
	Wheel wheel;

	Outcome outcome1("Dozen 1-12", 2);
	EXPECT_EQ(wheel.getBin(1).containsOutcome(outcome1), true);
	EXPECT_EQ(wheel.getBin(2).containsOutcome(outcome1), true);
	EXPECT_EQ(wheel.getBin(5).containsOutcome(outcome1), true);
	EXPECT_EQ(wheel.getBin(12).containsOutcome(outcome1), true);
	EXPECT_EQ(wheel.getBin(0).containsOutcome(outcome1), false);
	EXPECT_EQ(wheel.getBin(14).containsOutcome(outcome1), false);
	EXPECT_EQ(wheel.getBin(35).containsOutcome(outcome1), false);

	Outcome outcome2("Dozen 13-24", 2);
	EXPECT_EQ(wheel.getBin(13).containsOutcome(outcome2), true);
	EXPECT_EQ(wheel.getBin(14).containsOutcome(outcome2), true);
	EXPECT_EQ(wheel.getBin(15).containsOutcome(outcome2), true);
	EXPECT_EQ(wheel.getBin(24).containsOutcome(outcome2), true);
	EXPECT_EQ(wheel.getBin(25).containsOutcome(outcome2), false);
	EXPECT_EQ(wheel.getBin(3).containsOutcome(outcome2), false);

	Outcome outcome3("Dozen 25-36", 2);
	EXPECT_EQ(wheel.getBin(25).containsOutcome(outcome3), true);
	EXPECT_EQ(wheel.getBin(26).containsOutcome(outcome3), true);
	EXPECT_EQ(wheel.getBin(27).containsOutcome(outcome3), true);
	EXPECT_EQ(wheel.getBin(36).containsOutcome(outcome3), true);
	EXPECT_EQ(wheel.getBin(24).containsOutcome(outcome3), false);
	EXPECT_EQ(wheel.getBin(5).containsOutcome(outcome3), false);
	EXPECT_EQ(wheel.getBin(37).containsOutcome(outcome3), false);
}

TEST(BinBuilderTests, CheckBasketBet) {
	Wheel wheel;
	Outcome outcome("Basket", 6);
	EXPECT_EQ(wheel.getBin(0).containsOutcome(outcome), true);
	EXPECT_EQ(wheel.getBin(3).containsOutcome(outcome), true);
	EXPECT_EQ(wheel.getBin(37).containsOutcome(outcome), true);
	EXPECT_EQ(wheel.getBin(4).containsOutcome(outcome), false);
}

TEST(BinBuilderTests, CheckEvenMoneyBets) {
	Wheel wheel;

	Outcome red("Red", 1);
	Outcome black("Black", 1);
	Outcome even("Even", 1);
	Outcome odd("Odd", 1);
	Outcome hi("Hi", 1);
	Outcome lo("Lo", 1);

	EXPECT_EQ(wheel.getBin(0).containsOutcome(red), false);
	EXPECT_EQ(wheel.getBin(0).containsOutcome(black), false);
	EXPECT_EQ(wheel.getBin(0).containsOutcome(even), false);
	EXPECT_EQ(wheel.getBin(0).containsOutcome(odd), false);
	EXPECT_EQ(wheel.getBin(0).containsOutcome(hi), false);
	EXPECT_EQ(wheel.getBin(0).containsOutcome(lo), false);

	EXPECT_EQ(wheel.getBin(37).containsOutcome(red), false);
	EXPECT_EQ(wheel.getBin(37).containsOutcome(black), false);
	EXPECT_EQ(wheel.getBin(37).containsOutcome(even), false);
	EXPECT_EQ(wheel.getBin(37).containsOutcome(odd), false);
	EXPECT_EQ(wheel.getBin(37).containsOutcome(hi), false);
	EXPECT_EQ(wheel.getBin(37).containsOutcome(lo), false);

	EXPECT_EQ(wheel.getBin(1).containsOutcome(red), true);
	EXPECT_EQ(wheel.getBin(1).containsOutcome(odd), true);
	EXPECT_EQ(wheel.getBin(1).containsOutcome(lo), true);

	EXPECT_EQ(wheel.getBin(18).containsOutcome(red), true);
	EXPECT_EQ(wheel.getBin(18).containsOutcome(even), true);
	EXPECT_EQ(wheel.getBin(18).containsOutcome(lo), true);

	EXPECT_EQ(wheel.getBin(19).containsOutcome(red), true);
	EXPECT_EQ(wheel.getBin(19).containsOutcome(odd), true);
	EXPECT_EQ(wheel.getBin(19).containsOutcome(hi), true);

	EXPECT_EQ(wheel.getBin(35).containsOutcome(black), true);
	EXPECT_EQ(wheel.getBin(35).containsOutcome(odd), true);
	EXPECT_EQ(wheel.getBin(35).containsOutcome(hi), true);
}