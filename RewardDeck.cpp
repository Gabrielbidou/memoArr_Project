#include "pch.h"
#include <iostream>
#include "RewardDeck.h"
#include "Reward.h"

RewardDeck* RewardDeck::rd_ptr;

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
	if (RewardDeck::rd_ptr == nullptr) {
		RewardDeck::rd_ptr = new RewardDeck();
	}
	return *RewardDeck::rd_ptr;
	
}