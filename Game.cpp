/*************************************************************
Names: Gabriel Brunet
	   Jean Fei
*************************************************************/

#include "pch.h"
#include <iostream>
#include "Game.h"

int Game::currentRound;

Player & Game::getPlayer(Side side)
{
	return players[side];
}

const Card * Game::getPreviousCard() const
{
	return previousCard;
}

const Card * Game::getCurrentCard() const
{
	return currentCard;
}

void Game::setCurrentCard(const Card * card)
{
	if (card == nullptr)
		currentCard = nullptr;
	previousCard = currentCard;
	currentCard = card;
}

Card * Game::getCard(const Letter & letter, const Number & number)
{
	return board->getCard(letter, number);
}

void Game::setCard(const Letter & letter, const Number & number, Card * card)
{
	board->setCard(letter, number, card);
}

void Game::print()
{
	cout << *board;

	for (int i = 0; i < numPlayers; i++) {
		cout << players[i];
	}
}
