#include "pch.h"
#include <iostream>
#include "Player.h"
#include "Game.h"
#include "Board.h"

using namespace std;

//Variables globales
Game *game;
int numPlayers;

int main()
{
	while (numPlayers < 2 || numPlayers > 4) {
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
}

