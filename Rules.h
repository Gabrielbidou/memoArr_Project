/*************************************************************
Names: Gabriel Brunet
	   Jean Fei
*************************************************************/

#pragma once
#include "Game.h"

using namespace std;

class Rules {
	const int numPlayers;
	static int currentSide;
	static int numActivePlayers;
public:
	Rules(int numPlayers) : numPlayers(numPlayers) {
		currentSide = 0; 
		numActivePlayers = numPlayers;
	}

	bool isValid(const Game& game);
	bool gameOver(const Game& game);
	bool roundOver(const Game& game);
	const Player& getNextPlayer(Game& game);
};