#include "Card.hpp"


Card::Card(int newSymbol, int newColor) {
	this->symbol = newSymbol;
	this->color = newColor;
	this->next = NULL;
};

Card::Card() {
	this->symbol = -1;
	this->color = -1;
	this->next = NULL;
};

int Card::getSymbol() {
    return this->symbol;
};

int Card::getColor() {
    return this->color;
};

Card *Card::getNext() {
    return this != NULL ? this->next : NULL;
};

string Card::toString() {

    string leftPart = "";
    string rightPart = "";
    switch (this->color) {
        case 0: {
            leftPart += "Red";
            break;
        }
        case 1: {
            leftPart += "Green";
            break;
        }
        case 2: {
            leftPart += "Blue";
            break;
        }
        case 3: {
            leftPart += "Yellow";
            break;
        }
        case 4: {
            leftPart += "Wild";
            break;
        }
        default: {
            leftPart += "None";
            break;
        }
    }
    switch (this->symbol) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9: {
            rightPart += to_string(this->symbol);
            break;
        }
        case 10: {
            rightPart += "Skip";
            break;
        }
        case 11: {
            rightPart += "Reverse";
            break;
        }
        case 12: {
            rightPart += "Draw2";
            break;
        }
        case 13: {
            rightPart += "Wild Color Change";
            break;
        }
        case 14: {
            rightPart += "Wild Draw Four";
            break;
        }
        default: {
            rightPart = "None";
            break;
        }
    }
    return leftPart + " - " + rightPart;
};


