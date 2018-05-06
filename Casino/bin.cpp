#include "bin.h"

Bin::Bin(std::unordered_set<Outcome> outcomes)
	: outcomes(outcomes) {

}

void Bin::addOutcome(Outcome outcome) {
	outcomes.insert(outcome);
}