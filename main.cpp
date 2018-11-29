#include "pch.h"
#include <iostream>
#include "Player.h"
#include "Game.h"
#include "Board.h"
#include "Deck.h"
#include "Card.h"
#include "CardDeck.h"
#include "Reward.h"
#include "RewardDeck.h"
#include <algorithm>
#include <ctime>

using namespace std;

//Variables globales
Game *game;
int numPlayers;

int main()
{
	cout << "Please enter the number of players" << endl;
	cin >> numPlayers;
	//Repeat until valid number of players entered
	while(!cin >> numPlayers || numPlayers < 2 || numPlayers > 4) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter the number of players" << endl;
		cin >> numPlayers;
	}

	 game = new Game(numPlayers);
	//Loop for players' names and creating players
	for (int i = 0; i < numPlayers; i++) {
		string name;
		cout << "Please enter the name player " << (i + 1) << endl;
		cin >> name;
		
		Player *currentPlayer = new Player(name, 0);
		currentPlayer->setSide(Side(i));

		game->addPlayer(*currentPlayer);
	}
	
	//// Testing RewardDeck and CardDeck
	//
	//RewardDeck newRD = RewardDeck::make_RewardDeck();
	//cout << "RewardDeck size: " << newRD.c_deck.size() << " capacity: " << newRD.c_deck.capacity() << endl;
	//newRD.shuffle();
	//while(!newRD.isEmpty()) {
	//	cout << (*newRD.getNext()).getNumRubies() << " ";
	//}
	//newRD.shuffle();
	//cout << endl << "Testing second shuffle: " << endl;
	//while (!newRD.isEmpty()) {
	//	cout << (*newRD.getNext()).getNumRubies() << " ";
	//}

	//CardDeck newCD = CardDeck::make_CardDeck();
	//cout << "CardDeck size: " << newCD.c_deck.size() << " capacity: " << newCD.c_deck.capacity() << endl;
	//cout << "first shuffle: " << endl;
	//newCD.shuffle();
	//while (!newCD.isEmpty()) {
	//	string rowString1 = (*newCD.getNext())(1);
	//	cout << rowString1 << "  ";
	//}

	//newCD.shuffle();
	//cout << endl << "second shuffle: " << endl;
	//while (!newCD.isEmpty()) {
	//	string rowString2 = (*newCD.getNext())(1);
	//	cout << rowString2 << "  ";
	//}
	
}

