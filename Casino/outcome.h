#ifndef OUTCOME_H
#define OUTCOME_H

#include <string>

// Represents the potential outcomes after a bet
class Outcome {
public:
	Outcome(std::string name, double odds);
	bool operator==(const Outcome &rhs) const;
	bool operator!=(const Outcome &rhs) const;

	std::string oddsToString() const;
	double winAmount(double dollars) const;

	std::string getName() const;
	double getOdds() const;

private:
	std::string name;
	double odds;
};

// Allow Outcomes to be hashed on their name
namespace std {
	template<>
	struct hash<Outcome> {
		size_t operator()(const Outcome &obj) const {
			return hash<string>()(obj.getName());
		}
	};
}

#endif