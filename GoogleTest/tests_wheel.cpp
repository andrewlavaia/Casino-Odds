#include "pch.h"
#include "../casino/wheel.h"
#include "../Casino/binbuilder.h"
#include "../casino/bin.h"
#include "../casino/outcome.h"


TEST(WheelTests, BinInitialization) {
	Wheel wheel;

	for (int i = 0; i < 38; ++i) {
		EXPECT_EQ(typeid(wheel.getBin(i)), typeid(Bin));
		EXPECT_EQ(wheel.getBin(i).getCount(), 0);
	}

	EXPECT_EXIT(wheel.getBin(-1), ::testing::ExitedWithCode(-1), "Error: out of range");
	EXPECT_EXIT(wheel.getBin(38), ::testing::ExitedWithCode(-1), "Error: out of range");
}

TEST(WheelTests, addOutcomeToBin) {
	Outcome a("a", 8);
	Wheel wheel;
	wheel.addOutcome(0, a);
	wheel.addOutcome(37, a);

	EXPECT_EQ(wheel.getBin(0).getCount(), 1);
	EXPECT_EQ(wheel.getBin(0).outcomeInBin(a), true);
	EXPECT_EQ(wheel.getBin(1).getCount(), 0);
	EXPECT_EQ(wheel.getBin(1).outcomeInBin(a), false);
	EXPECT_EQ(wheel.getBin(37).getCount(), 1);
	EXPECT_EQ(wheel.getBin(37).outcomeInBin(a), true);
}

TEST(WheelTests, GenerateStraightBets) {
	Wheel wheel;
	BinBuilder::generateStraightBets(wheel);
	for (int i = 0; i < 37; ++i) {
		Outcome outcome("Number " + std::to_string(i), 35);
		EXPECT_EQ(wheel.getBin(i).getCount(), 1);
		EXPECT_EQ(wheel.getBin(i).outcomeInBin(outcome), true);
	}
	
	Outcome a("Number 00", 35);
	EXPECT_EQ(wheel.getBin(37).outcomeInBin(a), true);
}

TEST(WheelTests, GenerateSplitBets) {
	Wheel wheel;
	BinBuilder::generateSplitBets(wheel);
	
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

TEST(WheelTests, GenerateStreetBets) {
	Wheel wheel;
	BinBuilder::generateStreetBets(wheel);

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

TEST(WheelTests, GenerateLineBets) {
	Wheel wheel;
	BinBuilder::generateLineBets(wheel);

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