#include "Card.hpp"
class Deck {
	
	Card *cards;
	Card *top;
	Card *bottom;
	int numCards; // for sanity
	public:
		Card *getDeck();
		void shuffle();
		void addCard(Card *);
		Deck();
		Deck(Card *);
			
};
