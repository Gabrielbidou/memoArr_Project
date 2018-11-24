#pragma once
#include <string>
#include "Reward.h"

using namespace std;

//Définitions
typedef enum { Top, Bottom, Left, Right } Side;

class Player {
private:
	bool endOfGame;
	bool active;
	Side side;
	const string name;
	int numRubis;

	string sides[4] = { "Top", "Bottom", "Left", "Right" };
public:
	Player(){}
	Player(string name) : name(name), numRubis(0) {}

	//Overload de l'opérateur <<
	friend ostream& operator<<(ostream& os, Player& player)
	{
		player.print();
		return os;
	}

	string getName() const { return name; }
	bool isActive() { return active; }
	int getNRubis() { return numRubis; }
	Side getSide() { return side; }
	void setSide(Side side) { this->side = side; }
	void setActive(bool flag) { this->active = flag; }
	void addReward(const Reward &reward);
	void setDisplayMode(bool endOfGame);

private:
	void print();
};