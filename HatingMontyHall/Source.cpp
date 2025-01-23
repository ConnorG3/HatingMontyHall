#include "Header.h"

void main() {
	srand(time(NULL)); //seed rand
	int win = 0;
	int lose = 0;
	int blankResults[6] = { 0, 0, 0, 0, 0, 0 };
	int bulletResults[6] = { 0, 0, 0, 0, 0, 0 };

	cout << "Monty Hall:" << endl;
	testMonty10000(win, lose);
	printDoorResults(win, lose);

	//reset results
	win = 0;
	lose = 0; 

	cout << "Normal (true random):" << endl;
	testNormal10000(win, lose);
	printDoorResults(win, lose);

	cout << "Russian Roulette:" << endl << endl;
	testRussianRoulette10000(blankResults, bulletResults);
	printRouletteRoundResults(blankResults, bulletResults);
}