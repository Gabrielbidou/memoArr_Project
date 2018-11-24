#include "pch.h"
#include <iostream>
#include "Rules.h"

bool Rules::isValid(Game & game)
{
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
