#include "Card.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std; 
char types[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K'};
char suits[] = {'S', 'C', 'H', 'D'};
int points[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};


Card::Card() {
    srand(time(0)); // Avoids getting the same roll repeatadly
    deal();
}

char Card::getSuit() {
    return suit;
}   

char Card::getType() {
    return type;
}

int Card::getPointValue() {
    return pointValue;
}


void Card::deal() {
    int r = (rand() % 4);
    suit = suits[r];
    r = (rand() % 13);
    type = types[r];
    pointValue = points[r];
}

void Card::show() {
    cout << type << suit;
}
