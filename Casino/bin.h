#ifndef BIN_H
#define BIN_H

#include <unordered_set>
#include <algorithm>
#include <iostream>

#include "outcome.h"

// Represents each of the 38 possible marble locations 
// after a spin in Roulette.

class Bin {
public:
	Bin(std::unordered_set<Outcome> outcomes = {});
	bool containsOutcome(Outcome outcome) const;
	void addOutcome(Outcome outcome);
	unsigned getCount() const;
	void printOutcomes() const;

private:
	std::unordered_set<Outcome> outcomes;
};

#endif