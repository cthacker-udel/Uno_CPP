#include <string>
#include "CardType.cpp"
#include "CardColor.cpp"
#pragma once
using namespace std;

class Card {

	/*
	 * Number of cards
	 * 1 0 for each color
	 * 2 of 1-9 for each color
	 * 2 skip for each color
	 * 2 reverse for each color
	 * 2 draw 2 for each color
	 * 4 wild color change
	 * 4 wild draw four
	 *
	 * Heirarchy will go like this 0-9 #s, 10-skip, 11-reverse, 12-draw2, 13-wildcolorchange, 14-drawfourcolorchange
	 *
	 */

	/*
	 *
	 * colors will go 0-red, 1-green, 2-blue, 3-yellow, 4-wild
	 *
	 */

	int symbol;
	int color;
	Card *next;
	friend class Deck;
	public:
		Card();
		Card(int, int);
		string getSymbol();
		string getColor();
		Card *getNext();

};
