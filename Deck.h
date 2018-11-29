#pragma once
#include "Card.h"
#include "Reward.h"
#include <vector>

template <typename C>
class Deck {

public:
	std::vector<C> c_deck;
	C* cptr;

	virtual void shuffle();
	virtual C* getNext();
	virtual bool isEmpty() const;
};