#include "bin.h"

Bin::Bin(std::unordered_set<Outcome> outcomes)
	: outcomes(outcomes), count(outcomes.size()) {

}

void Bin::addOutcome(Outcome outcome) {
	outcomes.insert(outcome);
	++count;
}

unsigned Bin::getCount() {
	return count;
}