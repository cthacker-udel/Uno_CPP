#include "Card.hpp"
class Deck {
	
	Card *cards;
	Card *top;
	Card *bottom;
	int numCards; // for sanity
    friend class Uno;
	public:
		Card *getDeck();
		void shuffle();
		Deck();
		explicit Deck(Card *);
        void addCardToHand(Card *);
        Card *deal();
			
};
