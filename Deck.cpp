#include "Deck.hpp"
#include <iostream>
#include <random>

Deck::Deck(){
	int total = 0;
	this->cards = NULL;
	this->bottom = NULL;
	this->top = NULL;
	// first create zeros
	for (int i = 0; i < 4; i++) {
		if (this->cards == NULL) {
			this->cards = new Card(0, i);
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
			this->bottom->next = new Card(j, i);
			this->bottom = this->bottom->next;
            this->bottom->next = new Card(j, i);
            this->bottom = this->bottom->next;
			total += 2;
		}
	}

	// then add two of each, reverse, skip, and draw two
	for(int i = 0; i < 4; i++) {
		for(int j = 10; j <= 12; j++) {
			this->bottom->next = new Card(j, i);
			this->bottom = this->bottom->next;
			this->bottom->next = new Card(j, i);
			this->bottom = this->bottom->next;
			total += 2;
		}
	}
	for(int i = 13; i <= 14; i++) {
		this->bottom->next = new Card(i, 4);
		this->bottom = this->bottom->next;
		this->bottom->next = new Card(i, 4);
		this->bottom = this->bottom->next;
		this->bottom->next = new Card(i, 4);
		this->bottom = this->bottom->next;
		this->bottom->next = new Card(i, 4);
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
        if (tempHead != NULL && tempHead->next == NULL) {
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
        Card *dealCard = this->top;
        this->top = this->top->next;
        this->cards = this->top;
        cout << "dealing" << dealCard->toString() << endl;
        this->numCards--;
        return dealCard;
    }
};

void Deck::addCardToHand(Card *newCard) {

    if (this->cards == NULL) {
        cout << "cards is null" << endl;
        this->cards = newCard;
        this->bottom = newCard;
        this->top = newCard;
    } else if(newCard != NULL) {
        this->bottom->next = newCard;
        this->bottom = newCard;
    }
    this->numCards++;

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
            index++;
        } else {
            index++;
            tempHead = tempHead->next;
        }
    }

    Deck *newDeck = new Deck(NULL);
    Deck *firstDeck = new Deck(firstCut);
    Deck *secondDeck = new Deck(secondCut);
    Deck *thirdDeck = new Deck(thirdCut);
    Deck *fourthDeck = new Deck(fourthCut);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 3);
    while (firstDeck->cards != NULL || secondDeck->cards != NULL || thirdDeck->cards != NULL || fourthDeck->cards != NULL) {
        int randomIndex = distr(gen);
        cout << "before switch" << endl;
        switch (randomIndex) {
            case 0:
                // take from first pile
                if (firstDeck->cards != NULL) {
                    newDeck->addCardToHand(firstDeck->deal());
                }
                break;
            case 1:
                // take from second pile
                if (secondDeck->cards != NULL) {
                    newDeck->addCardToHand(secondDeck->deal());
                }
                break;
            case 2:
                // take from third pile
                if (thirdDeck->cards != NULL) {
                    newDeck->addCardToHand(thirdDeck->deal());
                }
                break;
            case 3:
                // take from fourth pile
                if (fourthDeck->cards != NULL) {
                    newDeck->addCardToHand(fourthDeck->deal());
                }
                break;
        }
        cout << "cards left: firstDeck:" << firstDeck->numCards << "\nsecondDeck:" << secondDeck->numCards << "\nthirdDeck:" << thirdDeck->numCards << "\nfourthDeck:" << fourthDeck->numCards << endl;
    }
    cout << "number of cards in newDeck = " << newDeck->numCards << endl;
    this->cards = newDeck->cards;

};

