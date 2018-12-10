/*************************************************************
Names: Gabriel Brunet
	   Jean Fei
*************************************************************/

#pragma once
#include <vector>
#include "Card.h"
#include "Deck.h"

class CardDeck : public Deck<Card> {

private:
	CardDeck();
	static CardDeck* cd_ptr;

public:
	static CardDeck&  make_CardDeck();
};