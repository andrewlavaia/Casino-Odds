#include <iostream>
#include <string>
#include <cassert>

#include "outcome.h"
#include "bin.h"
#include "wheel.h"
#include "binbuilder.h"

int main() {

	int n = 1;

	while (n != 0) {
		

		Wheel wheel;
		BinBuilder::generateStraightBets(wheel);
		
		
		std::cin >> n;
	}

	return 0;
}