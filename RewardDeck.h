#pragma once
#include "Deck.h"

class RewardDeck : public Deck<Reward> {

private:
	RewardDeck();

public:
	static RewardDeck& make_RewardDeck();
};