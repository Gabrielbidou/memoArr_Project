#include "pch.h"
#include <iostream>
#include "Player.h"
#include "Game.h"
using namespace std;

//Variables globales
Game *game;
int numPlayers;
string sides[] = { "Top", "Bottom", "Left", "Right" };

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
		cout << "Please enter the name player " << i << endl;
		getline(cin, name);
		
		Player *currentPlayer = new Player(name, sides[i], 0);

		game->addPlayer(*currentPlayer);
	}
}

