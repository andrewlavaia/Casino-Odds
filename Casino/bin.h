#ifndef BIN_H
#define BIN_H

#include <unordered_set>

#include "outcome.h"

// Represents each of the 38 possible marble locations 
// after a spin in Roulette.

class Bin {
public:
	Bin(std::unordered_set<Outcome> outcomes);

private:
	std::unordered_set<Outcome> outcomes;
};

#endif