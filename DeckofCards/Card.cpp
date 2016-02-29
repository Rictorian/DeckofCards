#include "stdafx.h"
#include <string>
#include "Card.h"

using namespace std;
Card::Card(int inFace, int inSuit)
{
	face = inFace;
	suit = inSuit;
}
Card::Card()
{
	face = 0;
	suit = 0;
}

string Card::toString()
{
	return ("The " + faces[face] + " of " + suits[suit]);
}