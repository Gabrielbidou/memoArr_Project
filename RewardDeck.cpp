#include "pch.h"
#include <iostream>
#include "RewardDeck.h"
#include "Reward.h"

RewardDeck::RewardDeck() {
	c_deck.push_back(Reward(1));
	c_deck.push_back(Reward(1));
	c_deck.push_back(Reward(1));
	c_deck.push_back(Reward(2));
	c_deck.push_back(Reward(2));
	c_deck.push_back(Reward(3));
	c_deck.push_back(Reward(4));
	cptr = &c_deck.front();
}

RewardDeck& RewardDeck::make_RewardDeck() {
	RewardDeck *newRDeck = new RewardDeck();
	return *newRDeck;
}