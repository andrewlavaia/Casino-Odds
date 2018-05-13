#include "pch.h"
#include "../casino/wheel.h"
#include "../Casino/binbuilder.h"
#include "../casino/bin.h"
#include "../casino/outcome.h"

TEST(BinBuilderTests, CheckStraightBets) {
	Wheel wheel;

	for (int i = 0; i < 37; ++i) {
		Outcome outcome("Number " + std::to_string(i), 35);
		EXPECT_EQ(wheel.getBin(i).outcomeInBin(outcome), true);
	}

	Outcome a("Number 00", 35);
	EXPECT_EQ(wheel.getBin(37).outcomeInBin(a), true);
}

TEST(BinBuilderTests, CheckSplitBets) {
	Wheel wheel;

	Outcome outcome23("Split 2-3", 17);
	EXPECT_EQ(wheel.getBin(2).outcomeInBin(outcome23), true);
	EXPECT_EQ(wheel.getBin(3).outcomeInBin(outcome23), true);
	EXPECT_EQ(wheel.getBin(4).outcomeInBin(outcome23), false);

	Outcome outcome3435("Split 34-35", 17);
	EXPECT_EQ(wheel.getBin(34).outcomeInBin(outcome3435), true);
	EXPECT_EQ(wheel.getBin(35).outcomeInBin(outcome3435), true);
	EXPECT_EQ(wheel.getBin(36).outcomeInBin(outcome3435), false);

	Outcome outcome47("Split 4-7", 17);
	EXPECT_EQ(wheel.getBin(4).outcomeInBin(outcome47), true);
	EXPECT_EQ(wheel.getBin(7).outcomeInBin(outcome47), true);
	EXPECT_EQ(wheel.getBin(5).outcomeInBin(outcome47), false);

	Outcome outcome000("Split 0-00", 17);
	EXPECT_EQ(wheel.getBin(0).outcomeInBin(outcome000), true);
	EXPECT_EQ(wheel.getBin(37).outcomeInBin(outcome000), true);
	EXPECT_EQ(wheel.getBin(1).outcomeInBin(outcome000), false);
}

TEST(BinBuilderTests, CheckStreetBets) {
	Wheel wheel;

	Outcome outcome123("Street 1-2-3", 11);
	EXPECT_EQ(wheel.getBin(1).outcomeInBin(outcome123), true);
	EXPECT_EQ(wheel.getBin(2).outcomeInBin(outcome123), true);
	EXPECT_EQ(wheel.getBin(3).outcomeInBin(outcome123), true);
	EXPECT_EQ(wheel.getBin(4).outcomeInBin(outcome123), false);

	Outcome outcome343536("Street 34-35-36", 11);
	EXPECT_EQ(wheel.getBin(34).outcomeInBin(outcome343536), true);
	EXPECT_EQ(wheel.getBin(35).outcomeInBin(outcome343536), true);
	EXPECT_EQ(wheel.getBin(36).outcomeInBin(outcome343536), true);
	EXPECT_EQ(wheel.getBin(37).outcomeInBin(outcome343536), false);
}

TEST(BinBuilderTests, CheckLineBets) {
	Wheel wheel;

	Outcome outcome16("Line 1-6", 5);
	EXPECT_EQ(wheel.getBin(1).outcomeInBin(outcome16), true);
	EXPECT_EQ(wheel.getBin(2).outcomeInBin(outcome16), true);
	EXPECT_EQ(wheel.getBin(3).outcomeInBin(outcome16), true);
	EXPECT_EQ(wheel.getBin(4).outcomeInBin(outcome16), true);
	EXPECT_EQ(wheel.getBin(5).outcomeInBin(outcome16), true);
	EXPECT_EQ(wheel.getBin(6).outcomeInBin(outcome16), true);
	EXPECT_EQ(wheel.getBin(0).outcomeInBin(outcome16), false);
	EXPECT_EQ(wheel.getBin(7).outcomeInBin(outcome16), false);

	Outcome outcome3136("Line 31-36", 5);
	EXPECT_EQ(wheel.getBin(31).outcomeInBin(outcome3136), true);
	EXPECT_EQ(wheel.getBin(32).outcomeInBin(outcome3136), true);
	EXPECT_EQ(wheel.getBin(33).outcomeInBin(outcome3136), true);
	EXPECT_EQ(wheel.getBin(34).outcomeInBin(outcome3136), true);
	EXPECT_EQ(wheel.getBin(35).outcomeInBin(outcome3136), true);
	EXPECT_EQ(wheel.getBin(36).outcomeInBin(outcome3136), true);
	EXPECT_EQ(wheel.getBin(37).outcomeInBin(outcome3136), false);
}

TEST(BinBuilderTests, CheckCornerBets) {
	Wheel wheel;

	Outcome outcome15("Corner 1-5", 8);
	EXPECT_EQ(wheel.getBin(1).outcomeInBin(outcome15), true);
	EXPECT_EQ(wheel.getBin(2).outcomeInBin(outcome15), true);
	EXPECT_EQ(wheel.getBin(4).outcomeInBin(outcome15), true);
	EXPECT_EQ(wheel.getBin(5).outcomeInBin(outcome15), true);
	EXPECT_EQ(wheel.getBin(0).outcomeInBin(outcome15), false);
	EXPECT_EQ(wheel.getBin(3).outcomeInBin(outcome15), false);

	Outcome outcome3236("Corner 32-36", 8);
	EXPECT_EQ(wheel.getBin(32).outcomeInBin(outcome3236), true);
	EXPECT_EQ(wheel.getBin(33).outcomeInBin(outcome3236), true);
	EXPECT_EQ(wheel.getBin(35).outcomeInBin(outcome3236), true);
	EXPECT_EQ(wheel.getBin(36).outcomeInBin(outcome3236), true);
	EXPECT_EQ(wheel.getBin(34).outcomeInBin(outcome3236), false);
}

TEST(BinBuilderTests, CheckColumnBets) {
	Wheel wheel;

	Outcome outcome1("Column 1-34", 2);
	EXPECT_EQ(wheel.getBin(1).outcomeInBin(outcome1), true);
	EXPECT_EQ(wheel.getBin(4).outcomeInBin(outcome1), true);
	EXPECT_EQ(wheel.getBin(7).outcomeInBin(outcome1), true);
	EXPECT_EQ(wheel.getBin(34).outcomeInBin(outcome1), true);
	EXPECT_EQ(wheel.getBin(0).outcomeInBin(outcome1), false);
	EXPECT_EQ(wheel.getBin(3).outcomeInBin(outcome1), false);
	EXPECT_EQ(wheel.getBin(35).outcomeInBin(outcome1), false);

	Outcome outcome2("Column 2-35", 2);
	EXPECT_EQ(wheel.getBin(2).outcomeInBin(outcome2), true);
	EXPECT_EQ(wheel.getBin(5).outcomeInBin(outcome2), true);
	EXPECT_EQ(wheel.getBin(8).outcomeInBin(outcome2), true);
	EXPECT_EQ(wheel.getBin(35).outcomeInBin(outcome2), true);
	EXPECT_EQ(wheel.getBin(34).outcomeInBin(outcome2), false);
	EXPECT_EQ(wheel.getBin(6).outcomeInBin(outcome2), false);

	Outcome outcome3("Column 3-36", 2);
	EXPECT_EQ(wheel.getBin(3).outcomeInBin(outcome3), true);
	EXPECT_EQ(wheel.getBin(6).outcomeInBin(outcome3), true);
	EXPECT_EQ(wheel.getBin(9).outcomeInBin(outcome3), true);
	EXPECT_EQ(wheel.getBin(36).outcomeInBin(outcome3), true);
	EXPECT_EQ(wheel.getBin(1).outcomeInBin(outcome3), false);
	EXPECT_EQ(wheel.getBin(8).outcomeInBin(outcome3), false);
	EXPECT_EQ(wheel.getBin(37).outcomeInBin(outcome3), false);
}

TEST(BinBuilderTests, CheckDozenBets) {
	Wheel wheel;

	Outcome outcome1("Dozen 1-12", 2);
	EXPECT_EQ(wheel.getBin(1).outcomeInBin(outcome1), true);
	EXPECT_EQ(wheel.getBin(2).outcomeInBin(outcome1), true);
	EXPECT_EQ(wheel.getBin(5).outcomeInBin(outcome1), true);
	EXPECT_EQ(wheel.getBin(12).outcomeInBin(outcome1), true);
	EXPECT_EQ(wheel.getBin(0).outcomeInBin(outcome1), false);
	EXPECT_EQ(wheel.getBin(14).outcomeInBin(outcome1), false);
	EXPECT_EQ(wheel.getBin(35).outcomeInBin(outcome1), false);

	Outcome outcome2("Dozen 13-24", 2);
	EXPECT_EQ(wheel.getBin(13).outcomeInBin(outcome2), true);
	EXPECT_EQ(wheel.getBin(14).outcomeInBin(outcome2), true);
	EXPECT_EQ(wheel.getBin(15).outcomeInBin(outcome2), true);
	EXPECT_EQ(wheel.getBin(24).outcomeInBin(outcome2), true);
	EXPECT_EQ(wheel.getBin(25).outcomeInBin(outcome2), false);
	EXPECT_EQ(wheel.getBin(3).outcomeInBin(outcome2), false);

	Outcome outcome3("Dozen 25-36", 2);
	EXPECT_EQ(wheel.getBin(25).outcomeInBin(outcome3), true);
	EXPECT_EQ(wheel.getBin(26).outcomeInBin(outcome3), true);
	EXPECT_EQ(wheel.getBin(27).outcomeInBin(outcome3), true);
	EXPECT_EQ(wheel.getBin(36).outcomeInBin(outcome3), true);
	EXPECT_EQ(wheel.getBin(24).outcomeInBin(outcome3), false);
	EXPECT_EQ(wheel.getBin(5).outcomeInBin(outcome3), false);
	EXPECT_EQ(wheel.getBin(37).outcomeInBin(outcome3), false);
}

TEST(BinBuilderTests, CheckBasketBet) {
	Wheel wheel;
	Outcome outcome("Basket", 6);
	EXPECT_EQ(wheel.getBin(0).outcomeInBin(outcome), true);
	EXPECT_EQ(wheel.getBin(3).outcomeInBin(outcome), true);
	EXPECT_EQ(wheel.getBin(37).outcomeInBin(outcome), true);
	EXPECT_EQ(wheel.getBin(4).outcomeInBin(outcome), false);
}

TEST(BinBuilderTests, CheckEvenMoneyBets) {
	Wheel wheel;

	Outcome red("Red", 1);
	Outcome black("Black", 1);
	Outcome even("Even", 1);
	Outcome odd("Odd", 1);
	Outcome hi("Hi", 1);
	Outcome lo("Lo", 1);

	EXPECT_EQ(wheel.getBin(0).outcomeInBin(red), false);
	EXPECT_EQ(wheel.getBin(0).outcomeInBin(black), false);
	EXPECT_EQ(wheel.getBin(0).outcomeInBin(even), false);
	EXPECT_EQ(wheel.getBin(0).outcomeInBin(odd), false);
	EXPECT_EQ(wheel.getBin(0).outcomeInBin(hi), false);
	EXPECT_EQ(wheel.getBin(0).outcomeInBin(lo), false);

	EXPECT_EQ(wheel.getBin(37).outcomeInBin(red), false);
	EXPECT_EQ(wheel.getBin(37).outcomeInBin(black), false);
	EXPECT_EQ(wheel.getBin(37).outcomeInBin(even), false);
	EXPECT_EQ(wheel.getBin(37).outcomeInBin(odd), false);
	EXPECT_EQ(wheel.getBin(37).outcomeInBin(hi), false);
	EXPECT_EQ(wheel.getBin(37).outcomeInBin(lo), false);

	EXPECT_EQ(wheel.getBin(1).outcomeInBin(red), true);
	EXPECT_EQ(wheel.getBin(1).outcomeInBin(odd), true);
	EXPECT_EQ(wheel.getBin(1).outcomeInBin(lo), true);

	EXPECT_EQ(wheel.getBin(18).outcomeInBin(red), true);
	EXPECT_EQ(wheel.getBin(18).outcomeInBin(even), true);
	EXPECT_EQ(wheel.getBin(18).outcomeInBin(lo), true);

	EXPECT_EQ(wheel.getBin(19).outcomeInBin(red), true);
	EXPECT_EQ(wheel.getBin(19).outcomeInBin(odd), true);
	EXPECT_EQ(wheel.getBin(19).outcomeInBin(hi), true);

	EXPECT_EQ(wheel.getBin(35).outcomeInBin(black), true);
	EXPECT_EQ(wheel.getBin(35).outcomeInBin(odd), true);
	EXPECT_EQ(wheel.getBin(35).outcomeInBin(hi), true);
}