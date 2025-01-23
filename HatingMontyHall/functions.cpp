#include "Header.h"


//assumes you pick door 1
//assumes you switch every time
bool MontyHall() {
	bool door1 = false;
	bool door2 = false;
	bool door3 = false;
	bool win = false;
	int random;

	placePrizeDoor(door1, door2, door3); //places prize behind random door

	if (door1 == true){
		random = rand() % 2;
		if (random == 0) {
			return door2; //you switch, returns door 2 (false)
		}
		else if (random == 1) {
			return door3; //you switch, returns door 3 (false)
		}
	}
	else if (door2 == true) {
		random = rand() % 2;
		if (random == 0) {
			return door2; //you switch, returns door 2 (true)
		}
		else if (random == 1) {
			return door2; //you switch, returns door 2 (true)
		}
	}
	else if (door3 == true) {
		random = rand() % 2;
		if (random == 0) {
			return door3; //you switch, returns door 3 (true)
		}
		else if (random == 1) {
			return door3; //you switch, returns door 3 (true)
		}
	}
}

bool NormalHall() {
	bool door1 = false;
	bool door2 = false;
	bool door3 = false;
	bool win = false;
	int random;

	placePrizeDoor(door1, door2, door3); //places prize behind random door

	if (door1 == true) {
		random = rand() % 2;
		if (random == 0) {
			return door2; //you switch, returns door 2 (false)
		}
		else if (random == 1) {
			return door3; //you switch, returns door 3 (false)
		}
	}
	else if (door2 == true) {
		random = rand() % 2;
		if (random == 0) {
			return door2; //you switch, returns door 2 (true)
		}
		else if (random == 1) {
			return door3; //you switch, returns door 3 (false)
		}
	}
	else if (door3 == true) {
		random = rand() % 2;
		if (random == 0) {
			return door2; //you switch, returns door 2 (false)
		}
		else if (random == 1) {
			return door3; //you switch, returns door 3 (true)
		}
	}
}

void placePrizeDoor(bool &door1, bool &door2, bool &door3) {
	int random = rand() % DOOR_CHANCE; //roll 0-2

	if (random == 0) {
		door1 = true;
	}
	else if (random == 1) {
		door2 = true;
	}
	else if (random == 2) {
		door3 = true;
	}
}

void testMonty10000(int& win, int& lose) {
	for (int i = 0; i < 10000; i++) {
		if (MontyHall() == true) {
			win++;
		}
		else {
			lose++;
		}
	}
}

void testNormal10000(int& win, int& lose) {
	for (int i = 0; i < 10000; i++) {
		if (NormalHall() == true) {
			win++;
		}
		else {
			lose++;
		}
	}
}

void printDoorResults(int win, int lose) {
	cout << "Wins: " << win  << "  " << SPACE << fixed << setprecision(2) << chance(win, 10000) << "%" << endl;
	cout << "Losses: " << lose << SPACE << fixed << setprecision(2) << chance(lose, 10000) << "%" << endl;
	cout << endl << endl;
}

void russianRoulette(int blankResults[6], int bulletResults[6]) {
	bool barrel[6] = {false, false, false, false, false, false};
	bool lost = false;
	int round = 0;

	spin(barrel);

	while (!lost && round < 6) {
		fire(barrel, lost, blankResults, bulletResults, round);
		round++;
	}
}

void spin(bool barrel[6]) {
	bool done = false;
	int random = rand() % BULLET_CHANCE;
	barrel[random] = true;
}

void fire(bool barrel[6], bool& lost, int blankResults[6], int bulletResults[6], int round) {
	if (barrel[round] == true) {
		lost = true;
		bulletResults[round]++;
	}
	else if (barrel[round] == false) {
		blankResults[round]++;
	}
}

void printRouletteRoundResults(int blankResults[6], int bulletResults[6]){
	for (int i = 0; i < 6; i++) {
		cout << "Round " << (i + 1) << ":" << endl << endl;
		cout << "Blanks: " << fixed << setw(4) << blankResults[i] << SPACE << fixed << setprecision(2) << chance(blankResults[i], (blankResults[i] + bulletResults[i])) << "%" << endl;
		cout << "Bullets:" << fixed << setw(4) << bulletResults[i] << SPACE << fixed << setprecision(2) << chance(bulletResults[i], (blankResults[i] + bulletResults[i])) << "%" << endl;
		cout << endl;
	}
}

void testRussianRoulette10000(int blankResults[6], int bulletResults[6]) {
	for (int i = 0; i < 10000; i++) {
		russianRoulette(blankResults, bulletResults);
	}
}

double chance(int number1, int number2) {
	double number1d = number1 / 1.0;
	double number2d = number2 / 1.0;
	double result = number1d / number2d;
	result = result * 100;

	return result;
}