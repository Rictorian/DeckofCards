#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class Card
{
private:
	const string faces[13] = {"Two", "Three", "Four", "Five" , "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
	const string suits[4] = { "Clubs", "Diamonds", "Spades", "Hearts" };
public:
	int face, suit;
	Card();
	Card(int, int);
	string toString();
};