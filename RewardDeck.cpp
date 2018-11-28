#include "pch.h"
#include <iostream>
#include "RewardDeck.h"
#include "Reward.h"

RewardDeck::RewardDeck() {
	c_deck.insert(c_deck.end(), 3, Reward(1));
	c_deck.insert(c_deck.end(), 2, Reward(2));
	c_deck.push_back(Reward(3));
	c_deck.push_back(Reward(4));
}

RewardDeck& RewardDeck::make_RewardDeck() {
	RewardDeck *newRDeck = new RewardDeck();
	return *newRDeck;
}