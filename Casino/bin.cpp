#include "bin.h"

Bin::Bin(std::unordered_set<Outcome> outcomes)
	: outcomes(outcomes) {
}

bool Bin::outcomeInBin(Outcome outcome) const {
	if (outcomes.find(outcome) != outcomes.end())
		return true;
	else
		return false;
}

void Bin::addOutcome(Outcome outcome) {
	if (outcomeInBin(outcome)) {
		std::cerr << "Error: outcome with name=" << outcome.getName() 
			<< " already exists in Bin";
		exit(-1);
	}
	else {
		outcomes.insert(outcome);
	}
}

unsigned Bin::getCount() const {
	return outcomes.size();
}