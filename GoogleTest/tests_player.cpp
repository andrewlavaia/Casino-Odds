#include "pch.h"
#include "../casino/bet.h"
#include "../casino/outcome.h"
#include "../casino/player.h"
#include "../casino/table.h"


TEST(PlayerTests, PlaceBet) {
	Table table;

	Player p(1000);
	Outcome a("a", 8);
	Bet bet(100, a, p);

	EXPECT_EQ(table.getAllBets().size(), 0);
	p.placeBet(bet, table);
	EXPECT_EQ(table.getAllBets().size(), 1);
	EXPECT_EQ(p.getCash(), 900);
}

TEST(PlayerTests, WinBet) {
	Player p(1000);
	Outcome a("a", 8);
	Bet bet(100, a, p);
	bet.win();
	EXPECT_EQ(p.getCash(), 1900); // 1000 + 100 + 800
}