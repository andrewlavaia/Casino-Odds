#include "pch.h"
#include "../casino/wheel.h"
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
	wheel.getBin(0).addOutcome(a);
	wheel.getBin(37).addOutcome(a);

	EXPECT_EQ(wheel.getBin(0).getCount(), 1);
	EXPECT_EQ(wheel.getBin(1).getCount(), 0);
	EXPECT_EQ(wheel.getBin(37).getCount(), 1);
}