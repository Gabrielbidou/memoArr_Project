#pragma once
#include <vector>
#include "Card.h"
#include "Deck.h"

class CardDeck : public Deck<Card> {

private:
	CardDeck();

public:
	static CardDeck&  make_CardDeck();
};