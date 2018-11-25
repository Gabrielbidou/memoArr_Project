#include "pch.h"
#include <iostream>
#include <vector>
#include "Deck.h"
#include "CardDeck.h"
#include "Card.h"

CardDeck & CardDeck::make_CardDeck()
{
	int i = 0;
	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 5; b++) {
			cardDeck.insert(i, Card(FaceAnimal(a), FaceBackground(b)));
			i++;
		}
	}
}
