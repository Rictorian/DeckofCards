#include "stdafx.h"
#include "time.h"
#include "Card.h"
#include "DeckofCards.h"
#include "iostream"
#include "string"

using namespace std;

const int SIZE_OF_DECK = 52;

int main()
{
	srand(time(0));
	int intFace, intSuit, firstKeyFace, secondKeyFace, pause;
	//cin >> intFace;
	//cout << endl;
	//cin >> intSuit;
	//cout << endl;
	//Card firstCard(intFace, intSuit);
	//cout << firstCard.toString();
	//cin >> pause;
	DeckofCards realDeck;
	//realDeck.changeCard(0, firstCard);
	//realDeck.printCards();
	//cin >> pause;
	realDeck.shuffle();
	cout << endl << endl;
	realDeck.printCards();
	cin >> pause;
	realDeck.dealHands();
	realDeck.printHand(realDeck.firstHand);
	realDeck.printHand(realDeck.secondHand);
	cin >> pause;
	realDeck.rigDeck();
	realDeck.printHand(realDeck.firstHand);
	cout << realDeck.handValue(realDeck.firstHand);
	cout << endl << "You have: " << realDeck.pokerHand[realDeck.handValue(realDeck.firstHand)];
	//cout << endl << realDeck.nofaKind(realDeck.firstHand, realDeck.keyFace);
	//cout << endl << realDeck.keyFace;
	cin >> pause;
	return 0;
}