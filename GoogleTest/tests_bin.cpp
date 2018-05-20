#include "pch.h"
#include "../casino/bin.h"
#include "../casino/outcome.h"

TEST(BinTests, CheckCount) {
	Outcome a("a", 8);
	Outcome b("b", 7);
	Bin bin;

	EXPECT_EQ(bin.getCount(), 0);
	bin.addOutcome(a);
	EXPECT_EQ(bin.getCount(), 1);
	bin.addOutcome(b);
	EXPECT_EQ(bin.getCount(), 2);
}

TEST(BinTests, OutcomeInBin) {
	Outcome a("a", 8);
	Outcome b("b", 7);
	Outcome c("c", 9);
	Outcome d("a", 15);

	Bin bin;
	bin.addOutcome(a);
	bin.addOutcome(b);

	EXPECT_EQ(bin.containsOutcome(a), true);
	EXPECT_EQ(bin.containsOutcome(b), true);
	EXPECT_EQ(bin.containsOutcome(c), false);
	EXPECT_EXIT(bin.addOutcome(d), ::testing::ExitedWithCode(-1), 
		"Error: outcome with name=a already exists in Bin");
	EXPECT_EQ(bin.getCount(), 2);
}