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
