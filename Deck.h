#pragma once
#include "Card.h"
#include "Reward.h"
#include <vector>

template <typename C>
class Deck {

private:
	vector<C> c_deck{ nullptr };
	C* c_ptr{c_deck.data};

public:
	virtual void shuffle();
	virtual C* getNext();
	virtual bool isEmpty() const;
};