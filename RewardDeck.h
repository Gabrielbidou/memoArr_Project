#pragma once
#include "Deck.h"

class RewardDeck : public Deck<Reward> {

private:
	RewardDeck();
	static RewardDeck* rd_ptr;

public:
	static RewardDeck& make_RewardDeck();
};