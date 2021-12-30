#include "Uno.cpp"
#include <time.h>

int main(void) {

    srand(time(NULL));
    Uno *unoGame = new Uno();
    unoGame->playGame();
    return -1;


}