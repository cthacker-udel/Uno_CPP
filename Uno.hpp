#include "Deck.hpp";
class Uno {

    Deck *pile;
    Deck *discardPile;
    public:
        explicit Uno(Deck *);
        void playGame();

};