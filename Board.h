#pragma once
#include <iostream>
#include <string>
#include "Deck.h"

using namespace std;

typedef enum { A, B, C, D, E } Letter;
typedef enum { one, two, three, four, five } Number;

class Board {
protected:
	Card *cards[5][5];
	bool faceStatus[5][5];
	int lettersIndex[5] = { 1, 5, 9, 13, 17 };
	int numbersIndex[5] = { 2, 6, 10, 14, 18 };
private:
	string display[20];
public:
	Board();

	//Overload de l'op�rateur <<
	friend ostream& operator<<(ostream& os, Board& board)
	{
		board.print();
		return os;
	}

	const bool isFaceUp(const Letter &letter, const Number &number);
	virtual bool turnFaceUp(const Letter &letter, const Number &number);
	virtual bool turnFaceDown(const Letter &letter, const Number &number);
	Card* getCard(const Letter &letter, const Number &number);
	void setCard(const Letter &letter, const Number &number, Card* card);
	virtual void reset();
	virtual void updateScreen();
protected:
	void getCardRange(const Letter &letter, const Number &number);
	virtual void print();
};