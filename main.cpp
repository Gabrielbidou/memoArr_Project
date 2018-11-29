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
//Deck<Card> *cardDeck;

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
	rules = new Rules(numPlayers);
	board = new Board();
	game = new Game(numPlayers, board);
	 
	//Loop for players' names and creating players
	for (int i = 0; i < numPlayers; i++) {
		string name;
		cout << "Please enter the name player " << (i + 1) << ": ";
		cin >> name;
		
		Player *currentPlayer = new Player(name);
		currentPlayer->setSide(Side(i));

		game->addPlayer(*currentPlayer);
	}
	
	//Display Game
	cout << *game;

	//Game Loop
	while (!rules->gameOver(*game)) {
		board->reset();
		game->setCurrentCard(nullptr);

		//Set all players as Active
		for (int i = 0; i < numPlayers; i++) {
			Player& player = game->getPlayer(Side(i));
			player.setActive(true);
		}

		//Revealing card to each player
		for (int i = 0; i < numPlayers; i++) {
			int x = 0, y = 0;
			
			if (i == 0 || i == 1) {
				if (i == 1)
					x = 4;

				y = 1;
				board->turnFaceUp(Letter(x), Number(y++));
				board->turnFaceUp(Letter(x), Number(y++));
				board->turnFaceUp(Letter(x), Number(y++));
	
				
				board->updateScreen();
				cout << game->getPlayer(Side(i)).getName() << ", if you've seen your cards, press ENTER";
				
				if (i == 0)
					cin.ignore();
				cin.ignore();

				y = 1;
				board->turnFaceDown(Letter(x), Number(y++));
				board->turnFaceDown(Letter(x), Number(y++));
				board->turnFaceDown(Letter(x), Number(y++));
			}
			else {
				if (i == 3)
					y = 4;

				x = 1;
				board->turnFaceUp(Letter(x++), Number(y));
				board->turnFaceUp(Letter(x++), Number(y));
				board->turnFaceUp(Letter(x++), Number(y));

				board->updateScreen();
				cout << game->getPlayer(Side(i)).getName() << ", if you've seen your cards, press ENTER";

				cin.ignore();

				x = 1;
				board->turnFaceDown(Letter(x++), Number(y));
				board->turnFaceDown(Letter(x++), Number(y));
				board->turnFaceDown(Letter(x++), Number(y));
			}
		}

		system("cls");
		cout << *game;

		//Round Loop
		while (!rules->roundOver(*game)) {
			const Player& currentPlayer = rules->getNextPlayer(*game);
			if (currentPlayer.isActive()) {
				cout << currentPlayer.getName() << "'s turn !" << endl;

				bool flag = false;
				char currentLetterIndex;
				char currentNumberIndex;

				Letter currentLetter;
				Number currentNumber;

				Card* currentCard;

				while (!flag) {
					cout << "Enter the row of desired card: ";
					cin >> currentLetterIndex;
					cout << "Enter the column of desired card: ";
					cin >> currentNumberIndex;

					currentLetter = Letter((int) currentLetterIndex - 65);
					currentNumber = Number((int) currentNumberIndex - 49);

					flag = board->turnFaceUp(currentLetter, currentNumber);
				}
				
				currentCard = board->getCard(currentLetter, currentNumber);
				game->setCurrentCard(currentCard);

				if (!rules->isValid(*game)) {
					cout << currentPlayer.getName() << " got a wrong card and is out for the round" << endl;
					game->getPlayer(currentPlayer.getSide()).setActive(false);
				}
				cout << *game;
			}
		}
	}

	//Display players and winners
	system("cls");
	for (int i = 0; i < numPlayers; i++) {
		Player& player = game->getPlayer(Side(i));
		player.setDisplayMode(true);
		cout << player;
	}
}

