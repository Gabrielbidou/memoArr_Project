#include "pch.h"
#include <iostream>
#include <vector>
#include "Deck.h"

template<typename C>
void Deck<C>::shuffle()
{
	std::srand(time(0));
	std::random_shuffle(c_deck.begin, c_deck.end);
}

template<typename C>
C* Deck<C>::getNext()
{
	c_ptr++;
	return c_deck.c_ptr;
}

template<typename C>
bool Deck<C>::isEmpty() const
{
	return c_deck.empty;
}