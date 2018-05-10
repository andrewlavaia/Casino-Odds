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