#include "pch.h"
#include <iostream>
#include "Player.h"

void Player::addReward(const Reward & reward)
{
}

void Player::setDisplayMode(bool endOfGame)
{
}

void Player::print()
{
	if (endOfGame == true) {

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
