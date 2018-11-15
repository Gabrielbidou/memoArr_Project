#pragma once

class Card {
	typedef enum {Krab, Penguin, Octopus, Turtle, Walrus} FaceAnimal;
	typedef enum {red, green, purple, blue, yellow} FaceBackground;


private:
	FaceAnimal animal;
	FaceBackground background;

	char card[3][3];

	char animalArray[5] = { 'K', 'P', 'O', 'T', 'W' };
	char backgroundArray[5] = { 'r', 'g', 'p', 'b', 'y' };

	Card(){}
	Card(FaceAnimal animal, FaceBackground background) : animal(animal), background(background) {
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				card[i][j] = backgroundArray[background];
		card[1][1] = animalArray[animal];
	}


};