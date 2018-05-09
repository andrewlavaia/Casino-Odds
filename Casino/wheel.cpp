#include "wheel.h"

Wheel::Wheel(std::array<Bin, 38> bins, unsigned seed)
	: bins(bins), rng(seed) {

}

Bin Wheel::getBin(int i) const {
	assert(i >= 0 && i < 38);
	return bins[i];
}

Bin Wheel::getRandomBin() {
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 37); // distribution in range [0, 37]
	return bins[dist(rng)];
}