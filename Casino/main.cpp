#include <iostream>
#include <string>
#include <cassert>

#include "outcome.h"
#include "bin.h"
#include "wheel.h"
#include "binbuilder.h"

int main() {

	Wheel wheel;
	wheel.getBin(8).printOutcomes();
		

	return 0;
}