#include "pch.h"
#include <iostream>
#include <vector>
#include "Deck.h"
#include "CardDeck.h"
#include "Card.h"

CardDeck* CardDeck::cd_ptr;

CardDeck::CardDeck() {

	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 5; b++) {
			c_deck.push_back(Card(FaceAnimal(a), FaceBackground(b)));
		}
	}
	cptr = &c_deck.front();
}

CardDeck & CardDeck::make_CardDeck()
{
	if (CardDeck::cd_ptr == nullptr) {
		CardDeck::cd_ptr = new CardDeck();
	}
	return *CardDeck::cd_ptr;
}
