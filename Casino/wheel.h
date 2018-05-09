#ifndef WHEEL_H
#define WHEEL_H

#include <array>
#include <random>
#include <cassert>

#include "outcome.h"
#include "bin.h"

class Wheel {
public:

	Wheel(std::array<Bin, 38> bins, unsigned seed = std::random_device()());
	Bin getBin(int i) const;
	Bin getRandomBin();

private:
	std::array<Bin, 38> bins;
	std::mt19937 rng;
};


#endif