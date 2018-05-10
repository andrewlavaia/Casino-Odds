#ifndef WHEEL_H
#define WHEEL_H

#include <iostream>
#include <array>
#include <random>
#include <cassert>

#include "outcome.h"
#include "bin.h"

class Wheel {
public:
	Wheel(unsigned seed = std::random_device()());
	Bin& getBin(int i);
	Bin spin();										// returns winning bin

private:
	std::array<Bin, 38> bins;
	std::mt19937 rng;
};


#endif