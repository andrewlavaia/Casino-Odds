#include "pch.h"

#include "../casino/outcome.h"

TEST(OutcomeTests, Equality) {
	Outcome a("a", 8);
	Outcome b("b", 7);
	Outcome c("a", 8);

	EXPECT_EQ(a, c);
	EXPECT_EQ(a, a);
	EXPECT_NE(a, b);
}