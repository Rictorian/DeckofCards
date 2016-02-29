#pragma once
#include "stdafx.h"
#include "Card.h"
#include <string>

using namespace std;

class DeckofCards
{
private:
	const int SIZE_OF_DECK = 52;
	const static int SIZE_OF_HAND = 5;
	//Card deck[52];
	Card *deck = new Card[SIZE_OF_DECK];
	//Card deck[52];
	int currentCard = 0;
	
public:
	//Card *deck[52];
	//int changeCard(int, Card);
	const string pokerHand[9]{ "High Card", "One Pair", "Two Pair", "Three of a Kind", "Straight", "Flush", "Full House", "Four of a Kind", "Straight Flush" };

	int keyFace = 0;
	Card firstHand[SIZE_OF_HAND], secondHand[SIZE_OF_HAND];
	int changeCard(int, Card);
	Card dealCard();
	void dealHands();
	string printCard(Card);
	void printCards();
	void shuffle();
	int checkWinner();
	int handValue(Card[]);
	void printHand(Card[]);
	void rigDeck();
	int nofaKind(Card[], int &keyFace);
	bool isStraight(Card[], int &keyFace);
	bool isFlush(Card[], int &keyFace);
	DeckofCards();
};