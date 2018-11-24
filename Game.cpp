#include "pch.h"
#include <iostream>
#include "Game.h"

Player & Game::getPlayer(Side side)
{
	return players[side];
}

const Card * Game::getPreviousCard()
{
	return nullptr;
}

const Card * Game::getCurrentCard()
{
	return nullptr;
}

void Game::setCurrentCard(const Card * card)
{
	previousCard = currentCard;
	//currentCard = card;
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
