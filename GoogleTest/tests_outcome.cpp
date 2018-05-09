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

TEST(OutcomeTests, OddsToString) {
	Outcome a("a", 8);
	Outcome b("b", 80);
	Outcome c("c", 8.5);
	Outcome d("d", 100.55);
	Outcome e("e", 0.33);
	EXPECT_EQ(a.oddsToString(), "8:1");
	EXPECT_EQ(b.oddsToString(), "80:1");
	EXPECT_EQ(c.oddsToString(), "8.5:1");
	EXPECT_EQ(d.oddsToString(), "100.55:1");
	EXPECT_EQ(e.oddsToString(), "0.33:1");
}

TEST(OutcomeTests, HashEquality) {
	Outcome a("a", 8);
	Outcome b("b", 7);
	Outcome c("a", 8);

	EXPECT_EQ(std::hash<Outcome>{}(a), std::hash<Outcome>{}(c));
	EXPECT_EQ(std::hash<Outcome>{}(a), std::hash<Outcome>{}(a));
	EXPECT_NE(std::hash<Outcome>{}(a), std::hash<Outcome>{}(b));
}