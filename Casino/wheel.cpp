#include "wheel.h"

Wheel::Wheel(unsigned seed)
	: rng(seed), bins(std::array<Bin, 38>()) {

}

void Wheel::addOutcome(int i, Outcome outcome) {
	if (i < 0 || i > 37) {
		std::cerr << "Error: out of range";
		exit(-1);
	}
	bins[i].addOutcome(outcome);
}

Bin Wheel::getBin(int i) const {
	if (i < 0 || i > 37) {
		std::cerr << "Error: out of range";
		exit(-1);
	}
	return bins[i];
}

Bin Wheel::spin() const {
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 37); // distribution in range [0, 37]
	return bins[dist(rng)];
}