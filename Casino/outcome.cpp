#include "outcome.h"

Outcome::Outcome(std::string name, double odds) : name(name), odds(odds) {

}

bool Outcome::operator==(const Outcome &rhs) const {
	return name == rhs.name;
}

bool Outcome::operator!=(const Outcome &rhs) const {
	return !(*this == rhs);
}

