#include "Deck.hpp"
#include <iostream>
#include <random>

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

}

Deck::Deck(Card *newCards) {
    this->cards = newCards;
    int total = 0;
    Card *tempHead = this->cards;
    this->top = this->cards;
    while (tempHead != NULL) {
        total++;
        tempHead = tempHead->next;
        if (tempHead->next == NULL) {
            this->bottom = tempHead;
        }
    }
    this->numCards = total;
};

Card *Deck::getDeck() {
    return this->cards;
};

Card *Deck::deal() {

    if (this->cards == NULL) {
        return NULL;
    } else {
        Card *tempHead = this->cards;
        Card *prevCard = tempHead;
        while (tempHead->next != NULL) {
            prevCard = tempHead;
            tempHead = tempHead->next;
        }
        // found last card
        Card *lastCard = prevCard->next;
        prevCard->next = NULL;
        this->bottom = prevCard;
        return lastCard;
    }
};

void Deck::addCardToHand(Card *newCard) {

    if (this->cards == NULL) {
        this->cards = newCard;
        this->bottom = newCard;
        this->top = newCard;
    } else {
        this->bottom->next = newCard;
        this->bottom = newCard;
    }

};

void Deck::shuffle() {


    // split in 3 ways
    int fourWayIndex = this->numCards / 4;
    Card *firstCut = this->cards;
    Card *secondCut = NULL;
    Card *thirdCut = NULL;
    Card *fourthCut = NULL;

    int index = 0;
    Card *tempHead = this->cards;
    while (tempHead != NULL) {
        if (index != 0 && index % fourWayIndex == 0) {
            // found where to cut
            if (secondCut == NULL) {
                secondCut = tempHead->next;
                tempHead->next = NULL;
                tempHead = secondCut;
            } else if (thirdCut == NULL) {
                thirdCut = tempHead->next;
                tempHead->next = NULL;
                tempHead = thirdCut;
            } else if (fourthCut == NULL) {
                fourthCut = tempHead->next;
                tempHead->next = NULL;
                break;
            }
        }
    }

    Deck *newDeck = new Deck(NULL);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 3);
    while (firstCut != NULL || secondCut != NULL || thirdCut != NULL || fourthCut != NULL) {
        int randomIndex = distr(gen);
        switch (randomIndex) {
            case 0:
                // take from first pile
                newDeck->addCardToHand()
            case 1:
                // take from second pile
            case 2:
                // take from third pile
            case 3:
                // take from fourth pile
        }
    }


};

