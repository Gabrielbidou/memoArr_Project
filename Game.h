#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Card.h"
#include "Board.h"

using namespace std;

class Game {

	//Variables de classe
	Board board;
	vector<Player> players;
	//Card currentCard;
	//Card previousCard;
	int numPlayers;
	int currentRound;

public:
	Game(int numPlayers) : numPlayers(numPlayers), currentRound(0) {
		
	}

	int getRound() { return currentRound; }
	void addPlayer(const Player& player) { 
		players.push_back(player);  
	}
	Player& getPLayer();
	const Card* getPreviousCard();
	const Card* getCurrentCard();
	void setCurrentCard(const Card*);

};