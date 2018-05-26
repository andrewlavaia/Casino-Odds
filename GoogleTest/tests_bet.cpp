#include "pch.h"
#include "../casino/bet.h"
#include "../casino/outcome.h"
#include "../casino/player.h"

class Player;

TEST(BetTests, WinAmount) {
	AlwaysBetOnRed p;
	Outcome a("a", 8);
	Outcome b("b", 1);
	Outcome c("c", .50);
	
	Bet bet1(100, a, p);
	Bet bet2(100, b, p);
	Bet bet3(100, c, p);

	EXPECT_EQ(bet1.winAmount(), 800);
	EXPECT_EQ(bet2.winAmount(), 100);
	EXPECT_EQ(bet3.winAmount(), 50);
}

TEST(BetTests, BetToString) {
	AlwaysBetOnRed p;
	Outcome a("a", 8);
	Outcome b("b", 1);
	Outcome c("c", .50);

	Bet bet1(100, a, p);
	Bet bet2(100.50, b, p);
	Bet bet3(100, c, p);

	EXPECT_EQ(bet1.toString(), "100 on a at 8:1");
	EXPECT_EQ(bet2.toString(), "100.5 on b at 1:1");
	EXPECT_EQ(bet3.toString(), "100 on c at 0.5:1");
}
