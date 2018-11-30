#pragma once
#include <iostream>
#include <vector>
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

	//Overload de l'opérateur <<
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
	void updateScreen();
protected:
	void getCardRange(const Letter &letter, const Number &number);
	
	virtual void print();
};

class ExpertBoard : public Board {
	char lettersChar[5] = { 'A', 'B', 'C', 'D', 'E' };
	char numbersChar[5] = { '1', '2', '3', '4', '5' };
	string display[4];
	vector<string> cardsPosition;
	vector<Card *> cardsVector;
public:
	ExpertBoard() {
		for (int i = 0; i < 4; i++) {
			string s(100, ' ');
			display[i] = s;
		}
	}
	virtual bool turnFaceUp(const Letter &letter, const Number &number) {
		//Vérifie si la carte est déjà face dévoilée
		if (isFaceUp(letter, number)) {
			return false;
		}

		else {
			string s(2, ' ');
			s[0] = lettersChar[letter];
			s[1] = numbersChar[number];
			cardsPosition.push_back(s);
			cardsVector.push_back(cards[letter][number]);
			faceStatus[letter][number] = true;
			return true;
		}
	}
	virtual bool turnFaceDown(const Letter &letter, const Number &number) {
		//Vérifie si la carte est déjà cachée
		if (!isFaceUp(letter, number)) {
			return false;
		}

		else {
			cardsVector.pop_back();
			faceStatus[letter][number] = false;
			return true;
		}
	}
	virtual void reset() {
		//Configure toutes les cartes comme étant face cachée
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				faceStatus[i][j] = false;

		for (int i = 0; i < cardsVector.size(); i++)
			cardsVector.pop_back();
	}
private:
	virtual void print() {
		for (int i = 0; i < cardsVector.size(); i++) {
			int displayPosition = i * 4;

			for (int j = 0; j < 3; j++) {
				Card &currentCard = *cardsVector[i];
				display[j].replace(displayPosition, 3, currentCard(j));
			}

			display[4].replace(displayPosition, 2, cardsPosition[i]);
		}
	}
};
