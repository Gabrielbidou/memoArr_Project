/*************************************************************
Names: Gabriel Brunet
	   Jean Fei
*************************************************************/

#pragma once
#include "Card.h"
#include "Reward.h"
#include <vector>

template <typename C>
class Deck {
protected:
	std::vector<C> c_deck;
	C* cptr;
public:
	void shuffle();
	C* getNext();
	bool isEmpty() const;
};
