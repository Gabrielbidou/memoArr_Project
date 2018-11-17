#pragma once

using namespace std;

class Board {
	typedef enum { A = (char) 'A', B = (char) 'B', C = (char) 'C', D = (char) 'D', E = (char) 'E' } Letter;
	typedef enum { one = (char) '1', two = (char) '2', three = (char) '3', four = (char) '4', five = (char) '5' } Number;

	char letters[5] = { 'A', 'B', 'C', 'D', 'E' };

public:
	string display[20];

	Board() {
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

	}
	void reset();
private: void print() {
	for (int i = 0; i < 20; i++)
		cout << display[i] << endl;
}
};
