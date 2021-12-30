#include "Deck.hpp"
#include <iostream>

Deck::Deck(){
	int total = 0;
	// first create zeros
	for (int i = 0; i < 4; i++) {
		if (this->cards == NULL) {
			cards = new Card(0, i);
			this->top = cards;
			this->bottom = cards;
			total++;
		} else {
			this->bottom->next = new Card(0, i);
			this->bottom = this->bottom->next;
			total++;
		}
	}

	// then create 1-9
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 9; j++) {
			this->bottom->next = new Card(i, j);
			this->bottom = this->bottom->next;
            this->bottom->next = new Card(i, j);
            this->bottom = this->bottom->next;
			total += 2;
		}
	}

	// then add two of each, reverse, skip, and draw two
	for(int i = 0; i < 4; i++) {
		for(int j = 10; j <= 12; j++) {
			this->bottom->next = new Card(i, j);
			this->bottom = this->bottom->next;
			this->bottom->next = new Card(i, j);
			this->bottom = this->bottom->next;
			total += 2;
		}
	}
	for(int i = 13; i <= 14; i++) {
		this->bottom->next = new Card(4, i);
		this->bottom = this->bottom->next;
		this->bottom->next = new Card(4, i);
		this->bottom = this->bottom->next;
		this->bottom->next = new Card(4, i);
		this->bottom = this->bottom->next;
		this->bottom->next = new Card(4, i);
		this->bottom = this->bottom->next;
		total += 4;
	}
	// we now have a deck of 108 cards
	this->numCards = total;
    std::cout << "number of cards = " << this->numCards << std::endl;

}
