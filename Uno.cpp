#include "Uno.hpp"
#include "Deck.cpp"
#include "Card.cpp"
#include <iostream>

Uno::Uno() {
    Deck *deck = new Deck();
    this->pile = deck;
    this->discardPile = NULL;
};

void Uno::playGame() {

    // craft players hands
    Deck *playerHand = new Deck(NULL);
    Deck *computerHand = new Deck(NULL);
    std::cout << "Entering loop" << std::endl;

    for (int i = 0; i < 7; i++) {
        playerHand->addCardToHand(this->pile->deal());
        computerHand->addCardToHand(this->pile->deal());
    }

}