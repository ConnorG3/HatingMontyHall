#pragma once
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <conio.h>

using namespace std;

const int DOOR_CHANCE = 3;
const int BULLET_CHANCE = 6;
const string SPACE = "   ";

bool MontyHall();
bool NormalHall(); 
void placePrizeDoor(bool& door1, bool& door2, bool& door3);
void testMonty10000(int& win, int& lose);
void testNormal10000(int& win, int& lose);
void testRussianRoulette10000(int blankResults[6], int bulletResults[6]);
void printDoorResults(int win, int lose);
void russianRoulette(int blankResults[6], int bulletResults[6]);
void spin(bool barrel[6]);
void fire(bool barrel[6], bool& lost, int blankResults[6], int bulletResults[6], int round);
void printRouletteRoundResults(int blankResults[6], int bulletResults[6]);
double chance(int number1, int number2);

