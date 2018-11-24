#include "pch.h"
#include <iostream>
#include "Rules.h"
#include "Deck.h"
#include "CardDeck.h"

using namespace std;

//Variables globales
Game *game;
Rules *rules;
Board *board;
CardDeck *cardDeck;

int numPlayers;

int main()
{
	//Enter the number of players
	while (numPlayers < 2 || numPlayers > 4) {
		cout << "Please enter the number of players (between 2 and 4): ";
		cin >> numPlayers;

		//If input is not a number
		if (!cin) {
			cout << "Enter a valid digit" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		else {
			if (numPlayers < 2 || numPlayers > 4)
				cout << "Not a valid number of players" << endl;
		}
		
	}

	//Create Game, Rules and Board
	rules = new Rules();
	board = new Board();
	game = new Game(numPlayers, board);
	cardDeck->
	 
	//Loop for players' names and creating players
	for (int i = 0; i < numPlayers; i++) {
		string name;
		cout << "Please enter the name player " << (i + 1) << ": ";
		cin >> name;
		
		Player *currentPlayer = new Player(name);
		currentPlayer->setSide(Side(i));

		game->addPlayer(*currentPlayer);
	}
	cout << *game;

	while (!rules->gameOver(*game)) {
		board->reset();
		//Set all players as Active
		for (int i = 0; i < numPlayers; i++) {
			Player& player = game->getPlayer(Side(i));
			player.setActive(true);
		}
		//MISSING REVEAL CARD
		while (!rules->roundOver(*game)) {

		}
	}
}

