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