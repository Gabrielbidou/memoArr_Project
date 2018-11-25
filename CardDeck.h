#pragma once
#include <vector>
#include "Card.h"
#include "Deck.h"

class CardDeck : public Deck<Card> {

private:
	vector<Card> cardDeck;

public:
	static CardDeck&  make_CardDeck();
};