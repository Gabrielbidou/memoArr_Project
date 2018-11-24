#pragma once
#include <string>
#include "Reward.h"

using namespace std;

//Définitions
typedef enum { Top, Bottom, Left, Right } Side;

class Player {
private:
	bool active;
	Side side;

public:
	const string name;
	int numRubis;

	Player(){}
	Player(string name, int numRubis) : name(name), numRubis(numRubis) {}

	string getName() const { return name; }
	bool isActive() { return active; }
	int getNRubis() { return numRubis; }
	Side getSide() { return side; }
	void setSide(Side side) { this->side = side; }
	void setActive(bool flag) { active = flag; }
	void addReward(const Reward &reward);
	void setDisplayMode(bool endOfGame);
};