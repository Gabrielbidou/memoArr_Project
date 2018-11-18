#pragma once
#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

typedef enum { A = (char) 'A', B = (char) 'B', C = (char) 'C', D = (char) 'D', E = (char) 'E' } Letter;
typedef enum { one = (char) '1', two = (char) '2', three = (char) '3', four = (char) '4', five = (char) '5' } Number;

class Board {
private:
	Card *cards[5][5];
	bool faceStatus[5][5];
	char letters[5] = { 'A', 'B', 'C', 'D', 'E' };

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
