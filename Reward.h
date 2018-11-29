#pragma once

class Reward {
	friend class RewardDeck;

private:
	int numR;
	Reward() {};
	Reward(int numR1) :numR(numR1) {};

public:
	int getNumRubies()const { return numR; }
};
	