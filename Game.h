#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "Card.h"
#include "Board.h"

using namespace std;

class Game {

	//Variables de classe
	Board *board;
	vector<Player> players;
	const Card* currentCard;
	const Card* previousCard;

	int numPlayers;
	static int currentRound;

public:
	Game(int numPlayers, Board *currentBoard) : numPlayers(numPlayers) {
		board = currentBoard;
		currentRound = 0;
		currentCard = previousCard = nullptr;
	}

	~Game() {
		delete board;
	}
	//Overload de l'opérateur <<
	friend ostream& operator<<(ostream& os, Game& game)
	{
		game.print();
		return os;
	}

	int getRound() const { return currentRound++; }
	void addPlayer(const Player& player) { 
		players.push_back(player);  
	}
	Player& getPlayer (Side side);
	const Card* getPreviousCard() const;
	const Card* getCurrentCard() const ;
	void setCurrentCard(const Card* card);
	Card* getCard(const Letter& letter, const Number& number);
	void setCard(const Letter& letter, const Number& number, Card* card);

private:
	void print();

};