#include "pch.h"
#include <iostream>
#include "Rules.h"

bool Rules::isValid(Game & game)
{
	Card& previousCard = *game.getPreviousCard();
	Card& currentCard = *game.getCurrentCard();
	char animalPrevious = previousCard(1)[1];
	char backgroundPrevious = previousCard(1)[0];
	char animalCurrent = currentCard(1)[1];
	char backgroundCurrent = currentCard(1)[0];

	if (animalPrevious == animalCurrent || backgroundPrevious == backgroundCurrent)
		return true;
	else
		return false;
}

bool Rules::gameOver(Game & game)
{
	return false;
}

bool Rules::roundOver(Game & game)
{
	return false;
}

const Player & Rules::getNextPlayer(Game & game)
{
	return game.getPlayer(Top);
}
