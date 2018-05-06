#include "wheel.h"

Bin Wheel::getBin(int i) const {
	assert(i >= 0 && i < 38);
	return bins[i];
}

Bin Wheel::getRandomBin() const {
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 37); // distribution in range [0, 37]
	return bins[dist(rng)];
}