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
	void addOutcome(int i, Outcome outcome);
	Bin getBin(int i) const;
	Bin spin() const; 

private:
	std::array<Bin, 38> bins;
	mutable std::mt19937 rng;
};


#endif