#include "Deck.hpp"
#pragma once
class Uno {

    Deck *pile;
    Deck *discardPile;
    public:
        explicit Uno();
        void playGame();

};