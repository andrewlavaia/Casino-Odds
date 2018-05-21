#include "pch.h"
#include "../casino/wheel.h"
#include "../Casino/binbuilder.h"
#include "../casino/bin.h"
#include "../casino/outcome.h"


TEST(WheelTests, BinInitialization) {
	Wheel wheel;

	for (int i = 0; i < 38; ++i) {
		EXPECT_EQ(typeid(wheel.getBin(i)), typeid(Bin));
	}

	EXPECT_EXIT(wheel.getBin(-1), ::testing::ExitedWithCode(-1), "Error: out of range");
	EXPECT_EXIT(wheel.getBin(38), ::testing::ExitedWithCode(-1), "Error: out of range");
}

TEST(WheelTests, AddOutcomeToBin) {
	Outcome a("a", 8);
	Wheel wheel;
	wheel.addOutcome(0, a);
	wheel.addOutcome(37, a);

	EXPECT_EQ(wheel.getBin(0).containsOutcome(a), true);
	EXPECT_EQ(wheel.getBin(1).containsOutcome(a), false);
	EXPECT_EQ(wheel.getBin(37).containsOutcome(a), true);
}

TEST(WheelTests, OutcomeCount) {
	Wheel wheel;

	EXPECT_EQ(wheel.getBin(1).getCount(), 12);
	EXPECT_EQ(wheel.getBin(2).getCount(), 14);
	EXPECT_EQ(wheel.getBin(3).getCount(), 12);

	EXPECT_EQ(wheel.getBin(4).getCount(), 14);
	EXPECT_EQ(wheel.getBin(5).getCount(), 17);
	EXPECT_EQ(wheel.getBin(6).getCount(), 14);

	EXPECT_EQ(wheel.getBin(34).getCount(), 11);
	EXPECT_EQ(wheel.getBin(35).getCount(), 13);
	EXPECT_EQ(wheel.getBin(36).getCount(), 11);

	EXPECT_EQ(wheel.getBin(0).getCount(), 3);
	EXPECT_EQ(wheel.getBin(37).getCount(), 3);
}

TEST(WheelTests, RNG) {
	Wheel wheel(0); // custom seed
	
	Bin bin = wheel.spin();
	Outcome outcome1("Number 34", 35);
	EXPECT_EQ(bin.containsOutcome(outcome1), true);
	
	bin = wheel.spin();
	Outcome outcome2("Number 23", 35);
	EXPECT_EQ(bin.containsOutcome(outcome2), true);

	bin = wheel.spin();
	Outcome outcome3("Number 19", 35);
	EXPECT_EQ(bin.containsOutcome(outcome3), true);

}