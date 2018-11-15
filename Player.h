#pragma once
#include <string>
#include "Reward.h"

using namespace std;
class Player {
private:
	bool active;

public:
	const string name;
	string side;
	int numRubis;

	Player(){}
	Player(string name, string side, int numRubis) : name(name), side(side), numRubis(numRubis) {}

	string getName() const { return name; }
	void setActive(bool flag) { active = flag; }
	bool isActive() { return active; }
	int getNRubis() { return numRubis; }
	void addReward(const Reward &reward);
	void setDisplayMode(bool endOfGame);
};