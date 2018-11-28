#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "Deck.h"

template<typename C>
void Deck<C>::shuffle()
{
	std::srand(std::time(0));
	std::random_shuffle(c_deck.begin(), c_deck.end());
}

template<typename C>
C* Deck<C>::getNext()
{
	C* next;
	if (cptr == &c_deck.back()) {
		next = nullptr;
	}
	else {
		next = cptr++;
	}

	return next;
}

template<typename C>
bool Deck<C>::isEmpty() const
{
	return c_deck.empty();
}

template class Deck<Card>;
template class Deck<Reward>;