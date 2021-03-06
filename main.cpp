/*************************************************************
Names: Gabriel Brunet
	   Jean Fei
*************************************************************/	

#pragma once
#include "pch.h"
#include <iostream>
#include "Player.h"
#include "Game.h"
#include "Board.h"
#include "Deck.h"
#include "Card.h"
#include "CardDeck.h"
#include "ExpertBoard.h"
#include "Reward.h"
#include "RewardDeck.h"
#include "Rules.h"
#include <algorithm>
#include <ctime>

using namespace std;

//Variables globales
Game *game;
Rules *rules;
Board *board;

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

	//Select the display mode
	bool flag = false;
	while (!flag) {
		char displayMode;
		cout << "Please select the display mode (B = Base / E = Expert): ";
		cin >> displayMode;

		if (displayMode == 'b' || displayMode == 'B') {
			board = new Board();
			flag = true;
		}
		else if (displayMode == 'e' || displayMode == 'E') {
			board = new ExpertBoard();
			flag = true;
		}
		else
			cout << "Please enter a valid display mode" << endl;
			
	}

	//Create Game, Rules and Board
	rules = new Rules(numPlayers);
	game = new Game(numPlayers, board);
	CardDeck &cardDeck = CardDeck::make_CardDeck();
	RewardDeck &rewardDeck = RewardDeck::make_RewardDeck();
	 
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
	system("PAUSE");
	//Shuffling the decks
	cardDeck.shuffle();
	rewardDeck.shuffle();

	//Placing card on board
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == 2 && j == 2)
				;
			else
				game->setCard(Letter(i), Number(j), cardDeck.getNext());
		}
	}

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
	
				
				cout << *board;
				cout << game->getPlayer(Side(i)).getName() << ", if you've seen your cards, " << flush;
				
				system("PAUSE");

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

				cout << *board;
				cout << game->getPlayer(Side(i)).getName() << ", if you've seen your cards, " << flush;

				system("PAUSE");

				x = 1;
				board->turnFaceDown(Letter(x++), Number(y));
				board->turnFaceDown(Letter(x++), Number(y));
				board->turnFaceDown(Letter(x++), Number(y));
			}
		}

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
					cout << "Enter the desired card: ";
					cin >> currentLetterIndex;
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
		//Last active player draw card from reward deck
		static int ignoreCounter = 0;
		for (int i = 0; i < numPlayers; i++) {
			Player& player = game->getPlayer(Side(i));
			if (player.isActive()) {
				player.addReward(*rewardDeck.getNext());
				cout << "Winner of this round is: " << player.getName() << endl;

				system("PAUSE");
			}
				
		}
	}

	//Display players
	system("cls");
	Player *winner = &(game->getPlayer(Side(0)));

	for (int i = 0; i < numPlayers; i++) {
		Player& player = game->getPlayer(Side(i));

		if (player.getNRubis() > winner->getNRubis())
			winner = &player;
		player.setDisplayMode(true);
		cout << player;
	}

	//Display the Winner
	cout << "The winner of the game is:" << endl;
	cout << *winner;
}

