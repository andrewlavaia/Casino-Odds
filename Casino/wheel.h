#ifndef WHEEL_H
#define WHEEL_H

#include <array>
#include <random>
#include <cassert>

#include "outcome.h"
#include "bin.h"

class Wheel {
public:
	Bin getBin(int i) const;
	Bin getRandomBin() const;


private:
	std::array<Bin, 38> bins;

};





#endif