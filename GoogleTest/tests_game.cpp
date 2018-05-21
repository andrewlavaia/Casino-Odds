#include "pch.h"
#include "../Casino/player.h"
#include "../Casino/outcome.h"
#include "../Casino/bet.h"
#include "../Casino/table.h"
#include "../Casino/wheel.h"
#include "../casino/game.h"

TEST(GameTests, IntegrationTest) {
	Wheel wheel(0); // custom seed
	Table table;
	Game game(table, wheel);

	Player p(1000);
	Outcome outcome1("Number 34", 35);
	Outcome outcome2("Red", 1); // expecting 23
	Outcome outcome3("Street 19-20-21", 11); // expecting 19
	Bet bet1(100, outcome1, p);
	Bet bet2(1000, outcome2, p);
	Bet bet3(100, outcome3, p);

	EXPECT_EQ(p.getCash(), 1000); // 1000 starting cash

	p.placeBet(bet1, table); // cash = 900
	game.play();
	EXPECT_EQ(p.getCash(), 4500); // 900 + 100 + 35*100

	p.placeBet(bet2, table); // cash = 3500
	game.play(); 
	EXPECT_EQ(p.getCash(), 5500); // 3500 + 1000 + 1000

	p.placeBet(bet3, table); // cash = 5400
	game.play();
	EXPECT_EQ(p.getCash(), 6600); // 5400 + 100 + 1100
}