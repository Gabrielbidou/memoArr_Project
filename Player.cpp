/*************************************************************
Names: Gabriel Brunet
	   Jean Fei
*************************************************************/

#include "pch.h"
#include <iostream>
#include "Player.h"

void Player::addReward(const Reward & reward)
{
	this->numRubis += reward.getNumRubies();
}

void Player::setDisplayMode(bool endOfGame)
{
	this->endOfGame = endOfGame;
}

void Player::print()
{
	if (this->endOfGame == true) {
		cout << this->getName() << ": ";
		cout << this->getNRubis() << " rubies" << endl;
	}
	else {
		cout << this->getName() << ": ";
		cout << sides[this->getSide()] << "(";
		if (this->isActive())
			cout << "active" << ")" << endl;
		else
			cout << "inactive" << ")" << endl;

	}
}
