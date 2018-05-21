#include <iostream>
#include <string>
#include <cassert>

#include "outcome.h"
#include "bin.h"
#include "wheel.h"
#include "binbuilder.h"

int main() {

	//Wheel wheel;
	//wheel.getBin(8).printOutcomes();
	
	Wheel wheel2(0);
	Bin bin = wheel2.spin();
	bin.printOutcomes();

	bin = wheel2.spin();
	bin.printOutcomes();

	bin = wheel2.spin();
	bin.printOutcomes();

	return 0;
}