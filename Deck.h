#pragma once
#include "Card.h"
#include "Reward.h"

template <typename C>
class Deck {
	virtual void shuffle();
	virtual C* getNext();
	virtual bool isEmpty() const;
};