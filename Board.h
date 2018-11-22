#pragma once
#include <iostream>
#include <string>
#include "Deck.h"

using namespace std;

typedef enum { A, B, C, D, E } Letter;
typedef enum { one, two, three, four, five } Number;

class Board {
private:
	Card *cards[5][5];
	bool faceStatus[5][5];
	int lettersIndex[5] = { 1, 5, 9, 13, 17 };
	int numbersIndex[5] = { 2, 6, 10, 14, 18 };

public:
	string display[20];

	Board();

	//Overload de l'opérateur <<
	friend ostream& operator<<(ostream& os, Board& board)
	{
		board.print();
		return os;
	}

	const bool isFaceUp(const Letter &letter, const Number &number);
	bool turnFaceUp(const Letter &letter, const Number &number);
	bool turnFaceDown(const Letter &letter, const Number &number);
	Card* getCard(const Letter &letter, const Number &number);
	void setCard(const Letter &letter, const Number &number, Card* card);
	void reset();

private:
	void getCardRange(const Letter &letter, const Number &number);
	void print();
};
