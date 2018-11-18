#include "pch.h"
#include "Board.h"

//Constructeur par défaut
Board::Board()
{
	//Initialiser la Board comme étant vide
	for (int i = 0; i < 20; i++) {
		string s(20, ' ');
		display[i] = s;
	}

	//Ajouter les lettres de la première colonne
	display[1][0] = A; display[5][0] = B; display[9][0] = C; display[13][0] = D; display[17][0] = E;

	//Ajouter les chiffres de la dernière rangée
	display[19][2] = one; display[19][6] = two; display[19][10] = three; display[19][14] = four; display[19][18] = five;

	//Ajouter tous les z pour les cartes face cachée
	for (int i = 0; i < 20; i += 4) {
		for (int j = 0; j < 3; j++) {
			for (int k = 1; k < 20; k += 4) {
				display[i + j].replace(k, 2, "zzz");
			}
		}
	}

	//Initialiser toutes les faces cachées
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			faceStatus[i][j] = false;
}

const bool Board::isFaceUp(const Letter & letter, const Number & number)
{
	try
	{
		getCardRange(letter, number);
		return faceStatus[letter][number];
	}
	catch (const std::out_of_range &error)
	{
		
	}
}

bool Board::turnFaceUp(const Letter & letter, const Number & number)
{
	return false;
}

bool Board::turnFaceDown(const Letter & letter, const Number & number)
{
	return false;
}

Card * Board::getCard(const Letter & letter, const Number & number)
{
	try
	{
		getCardRange(letter, number);
		return cards[letter][number];
	}
	catch (const std::out_of_range &error)
	{
		throw(error);
	}
}

void Board::setCard(const Letter & letter, const Number & number, Card * card)
{
	try
	{
		getCardRange(letter, number);
		cards[letter][number] = card;
	}
	catch (const std::out_of_range &error)
	{
		throw(error);
	}
}

void Board::reset()
{
}

//Méthodes privées
void Board::getCardRange(const Letter & letter, const Number & number)
{
	if (letter == C && number == three) {
		out_of_range error();
		cout << "This space is unusable";
		throw(error);
	}
	if (letter < 0 || letter > 4 || number < 0 || number > 4) {
		out_of_range error();
		throw(error);
	}
}

void Board::print()
{
	for (int j = 0; j < 20; j++) {
		cout << display[j] << endl;
	}
}
