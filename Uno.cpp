#include "Uno.hpp"

Uno::Uno(Deck *pile) {
    this->pile = pile;
    this->discardPile = NULL;
};

void Uno::playGame() {

    // craft players hands
    Deck *playerHand = new Deck(NULL);
    Deck *computerHand = new Deck(NULL);

    for (int i = 0; i < 7; i++) {
        playerHand->addCardToHand(this->pile->deal());
        computerHand->addCardToHand(this->pile->deal());
    }

}