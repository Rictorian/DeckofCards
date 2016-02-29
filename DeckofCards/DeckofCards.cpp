// DeckofCards.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "DeckofCards.h"
#include "Card.h"
#include "iostream"
#include "string"

using namespace std;

DeckofCards::DeckofCards()
{
	int count = 0;
	for (int suitCount = 0; suitCount < 4; suitCount++)
	{
		for (int faceCount = 0; faceCount < 13; faceCount++)
		{
			deck[count].face = faceCount;
			deck[count].suit = suitCount;
			count++;
		}
	}
}

void DeckofCards::printCards()
{
	for (int count = 0; count < SIZE_OF_DECK; count++)
	{
		cout << deck[count].toString() << endl;
	}
}

void DeckofCards::shuffle()
{
	int r;
	Card tempCard;
	for (int count = 0; count < SIZE_OF_DECK; count++)
	{
		int oneSlot = rand() % SIZE_OF_DECK;
		tempCard.face = deck[oneSlot].face;
		tempCard.suit = deck[oneSlot].suit;
		int twoSlot = rand() % SIZE_OF_DECK;
		deck[oneSlot].face = deck[twoSlot].face;
		deck[oneSlot].suit = deck[twoSlot].suit;
		deck[twoSlot].face = tempCard.face;
		deck[twoSlot].suit = tempCard.suit;
	}
}

int DeckofCards::changeCard(int deckSlot, Card inCard)
{
	deck[deckSlot].face = inCard.face;
	deck[deckSlot].suit = inCard.suit;
	return 0;
}

Card DeckofCards::dealCard()
{
	currentCard++;
	return deck[currentCard - 1];

}

string DeckofCards::printCard(Card inCard)
{
	return deck[currentCard - 1].toString();
}

void DeckofCards::dealHands()
{
	int j, k;
	Card temp, newTemp;

	//ASSIGNING HAND ARRAYS THEIR NEW CARDS//
	for (int count = 0; count < SIZE_OF_HAND; count++)
	{
		Card tempCard = dealCard();
		firstHand[count].face = tempCard.face;
		firstHand[count].suit = tempCard.suit;
		Card newTempCard = dealCard();
		secondHand[count].face = newTempCard.face;
		secondHand[count].suit = newTempCard.suit;
	}
	//SORTING CARDS IN HAND 1//
	for (int i = 0; i < SIZE_OF_HAND; i++)
	{
		j = i;

		while (j > 0 && firstHand[j].face < firstHand[j - 1].face)
		{
			temp.face = firstHand[j].face;
			temp.suit = firstHand[j].suit;
			firstHand[j].face = firstHand[j - 1].face;
			firstHand[j].suit = firstHand[j - 1].suit;
			firstHand[j - 1].face = temp.face;
			firstHand[j - 1].suit = temp.suit;
			j--;
		}
	}
	//SORTING CARDS IN HAND 2//
	for (int i = 0; i < SIZE_OF_HAND; i++)
	{
		k = i;

		while (k > 0 && secondHand[k].face < secondHand[k - 1].face)
		{
			temp.face = secondHand[k].face;
			temp.suit = secondHand[k].suit;
			secondHand[k].face = secondHand[k - 1].face;
			secondHand[k].suit = secondHand[k - 1].suit;
			secondHand[k - 1].face = temp.face;
			secondHand[k - 1].suit = temp.suit;
			k--;
		}
	}
}
void DeckofCards::printHand(Card hand[])
{
		//PRINTING THE HANDS//
	for (int count = 0; count < SIZE_OF_HAND; count++)
	{
		cout << hand[count].toString() << endl;
	}
}

int DeckofCards::checkWinner()
{
	if (handValue(firstHand) > handValue(secondHand))
		return 1;
	else if (handValue(firstHand) < handValue(secondHand))
		return 2;
	else
		return 3;
}

int DeckofCards::handValue(Card hand[])
{
	if (isStraight(hand, keyFace) && isFlush(hand, keyFace))
	{
		return 8;
	}
	else if (nofaKind(hand, keyFace) == 4)
	{
		return 7;
	}	
	else if (nofaKind(hand, keyFace) == 3 && (hand[0].face == hand[1].face || hand[1].face == hand[2].face))
	{
		return 6;
	}	
	else if (isFlush(hand, keyFace))
	{
		return 5;
	}
	else if (isStraight(hand, keyFace))
	{
		return 4;
	}
	else if (nofaKind(hand, keyFace) == 3)
	{
		return 3;
	}
	else if (nofaKind(hand, keyFace) == 2 && (hand[0].face == hand[1].face || hand[1].face == hand[2].face))
	{
		return 2;
	}
	else if (nofaKind(hand, keyFace) == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int DeckofCards::nofaKind(Card hand[], int &face)
{
	int current = 0, counter = 1, max = 0;
	for (int count = 0; count < SIZE_OF_HAND; count++)
	{
		for (int sCount = (1 + count); sCount < SIZE_OF_HAND; sCount++)
		{
			if (hand[sCount].face == hand[current].face)
				counter++;
		}
		if (counter > max)
		{
			max = counter;
			face = hand[current].face;
		}
		counter = 1;
	}
	return max;
}

bool DeckofCards::isStraight(Card hand[], int &face)
{
	if (hand[0].face == ((hand[1].face) - 1) && hand[0].face == ((hand[2].face) - 2) && hand[0].face == ((hand[3].face) - 3) && hand[0].face == ((hand[4].face) - 4))
	{
		keyFace = hand[4].face;
		return true;
	}
	else
		return false;
}

bool DeckofCards::isFlush(Card hand[], int &face)
{
	if (hand[0].suit == hand[1].suit && hand[0].face == hand[2].suit && hand[0].face == hand[3].suit && hand[0].face == hand[4].suit)
	{
		keyFace = hand[4].face;
		return true;
	}
		
	else
		return false;
}

void DeckofCards::rigDeck()
{
	firstHand[0].face = 8;
	firstHand[0].suit = 0;
	firstHand[1].face = 8;
	firstHand[1].suit = 1;
	firstHand[2].face = 8;
	firstHand[2].suit = 2;
	firstHand[3].face = 8;
	firstHand[3].suit = 0;
	firstHand[4].face = 4;
	firstHand[4].suit = 0;
}