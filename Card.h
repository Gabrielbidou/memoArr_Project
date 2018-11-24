#pragma once
#include <string>

using namespace std;

typedef enum { Krab, Penguin, Octopus, Turtle, Walrus } FaceAnimal;
typedef enum { red, green, purple, blue, yellow } FaceBackground;

class Card {

private:
	FaceAnimal animal;
	FaceBackground background;

	string card[3];

	char animalArray[5] = { 'K', 'P', 'O', 'T', 'W' };
	char backgroundArray[5] = { 'r', 'g', 'p', 'b', 'y' };

	Card(){}
	Card(FaceAnimal animal, FaceBackground background) : animal(animal), background(background) {
		for (int i = 0; i < 3; i++) {
			string s(3, backgroundArray[background]);
			card[i] = s;
		}
		card[1][1] = animalArray[animal];
	}

public:
	string& operator()(int row) {
		return this->card[row];
	}


};