#pragma once
#include "Game.h"

using namespace std;

class Rules {
public:
	Rules() {}

	bool isValid(Game& game);
	bool gameOver(Game& game);
	bool roundOver(Game& game);
	const Player& getNextPlayer(Game& game);
};