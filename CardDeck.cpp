#include "pch.h"
#include <iostream>
#include <vector>
#include "Deck.h"
#include "CardDeck.h"
#include "Card.h"

CardDeck::CardDeck() {

	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 5; b++) {
			c_deck.push_back(Card(FaceAnimal(a), FaceBackground(b)));
		}
	}
}

CardDeck & CardDeck::make_CardDeck()
{
	CardDeck* newDeck = new CardDeck();
	return *newDeck;
}
