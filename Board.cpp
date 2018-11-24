#include "pch.h"
#include "Board.h"

//Constructeur par d�faut
Board::Board()
{
	//Initialiser la Board comme �tant vide
	for (int i = 0; i < 20; i++) {
		string s(20, ' ');
		display[i] = s;
	}

	//Ajouter les lettres de la premi�re colonne
	display[1][0] = 'A'; display[5][0] = 'B'; display[9][0] = 'C'; display[13][0] = 'D'; display[17][0] = 'E';

	//Ajouter les chiffres de la derni�re rang�e
	display[19][2] = '1'; display[19][6] = '2'; display[19][10] = '3'; display[19][14] = '4'; display[19][18] = '5';

	//Initialiser la board avec tous des Z
	reset();

	//Initialiser toutes les faces cach�es
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			faceStatus[i][j] = false;
}

const bool Board::isFaceUp(const Letter & letter, const Number & number)
{
	//V�rifie si la combinaison Lettre et Nombre est valide
	try
	{
		getCardRange(letter, number);
		return faceStatus[letter][number];
	}
	catch (const std::out_of_range &error)
	{
		throw(error);
	}
}

bool Board::turnFaceUp(const Letter & letter, const Number & number)
{
	//V�rifie si la combinaison Lettre et Nombre est valide
	try
	{
		getCardRange(letter, number);
	}
	catch (const std::out_of_range &error)
	{
		throw(error);
	}
	
	//V�rifie si la carte est d�j� face d�voil�e
	if (faceStatus[letter][number] == true) {
		return false;
	}

	//Modifie le tableau de string selon la carte
	else {
		int indexLetter = lettersIndex[letter] - 1;
		int indexNumber = numbersIndex[number] - 1;
		for (int i = 0; i < 3; i++) {
			display[indexLetter].replace(indexNumber, 3, cards[letter][number]->operator()(i));

			indexLetter++;
		}
		faceStatus[letter][number] = true;
		updateScreen();
		return true;
	}
}

bool Board::turnFaceDown(const Letter & letter, const Number & number)
{
	//V�rifie si la combinaison Lettre et Nombre est valide
	try
	{
		getCardRange(letter, number);
	}
	catch (const std::out_of_range &error)
	{
		throw(error);
	}

	//V�rifie si la carte est d�j� face cach�e
	if (faceStatus[letter][number] == false) {
		return false;
	}

	//Modifie le tableau de string selon la carte
	else {
		int indexLetter = lettersIndex[letter] - 1;
		int indexNumber = numbersIndex[number] - 1;
		for (int i = 0; i < 3; i++) {
			display[indexLetter].replace(indexNumber, 3, "zzz");

			indexLetter++;
		}
		faceStatus[letter][number] = false;
		return true;
	}
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
	//Ajouter tous les z pour les cartes face cach�e
	for (int i = 0; i < 20; i += 4) {
		for (int j = 0; j < 3; j++) {
			for (int k = 1; k < 20; k += 4) {
				const string s("zzz");
				display[i + j].replace(k, 3, s);
			}
		}
	}
}

//M�thodes priv�es
void Board::getCardRange(const Letter & letter, const Number & number)
{
	if (letter == C && number == three) {
		out_of_range error(" ");
		cout << "This space is unusable";
		throw(error);
	}
	if (letter < 0 || letter > 4 || number < 0 || number > 4) {
		out_of_range error(" ");
		throw(error);
	}
}

void Board::updateScreen()
{

}

void Board::print()
{
	for (int j = 0; j < 20; j++) {
		cout << display[j] << endl;
	}
}
