#include "outcome.h"

Outcome::Outcome(std::string name, double odds) : name(name), odds(odds) {

}

bool Outcome::operator==(const Outcome &rhs) {
	return name == rhs.name && odds == rhs.odds;
}

