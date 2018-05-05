#include "outcome.h"

Outcome::Outcome(std::string name, double odds) 
	: name(name), odds(odds) {
}

bool Outcome::operator==(const Outcome &rhs) const {
	return name == rhs.name;
}

bool Outcome::operator!=(const Outcome &rhs) const {
	return !(*this == rhs);
}

std::string Outcome::oddsToString() const {
	std::string str = std::to_string(odds);
	int offset = 1;
	if (str.find_last_not_of('0') == str.find('.')) { 
		offset = 0; 
	} 
	str.erase(str.find_last_not_of('0') + offset, std::string::npos);
	return str + ":1";
}

double Outcome::winAmount(double dollars) const {
	return dollars * odds;
}

std::string Outcome::getName() const {
	return name;
}

double Outcome::getOdds() const {
	return odds;
}