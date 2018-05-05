#ifndef OUTCOME_H
#define OUTCOME_H

#include <string>

class Outcome {
public:
	Outcome(std::string name, double odds);
	bool operator==(const Outcome &rhs);

private:
	std::string name;
	double odds;
};

#endif