#include "Card.h"
#include "Card.cpp"
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

Card* userHand;
Card* houseHand;
int USER_HAND_SIZE = 2;
int HOUSE_HAND_SIZE = 2;
bool stand = false; 

// Prototypes
void printHand();
void printHouseHand();
void houseHit();
void userHit();
void gamePlay();
void playAgain();
void createHands();

// Functions
void createHands() {

    // reset cards
    userHand = new Card[15];
    houseHand = new Card[15];

    for (int i = 0; i < 15; i++) {
        userHand[i].deal();
        houseHand[i].deal();
        
    }

    // reset all checks 
    USER_HAND_SIZE = 2;
    HOUSE_HAND_SIZE = 2;
    stand = false; 
    gamePlay();

}

void printHand() {
    cout << "Your Hand: ";
    for(int i = 0; i < USER_HAND_SIZE; i++) {
        userHand[i].show();
        cout << "\t";
    }
    cout << endl;
}

void printHouseHand() {
    cout << "House Hand: ";
    for(int i = 0; i < HOUSE_HAND_SIZE; i++) {
        houseHand[i].show();
        cout << "\t";
    }
    cout << endl;
}


void houseHit() {
    int housesum = 0;
     for (int i = 0; i < HOUSE_HAND_SIZE; i++) {
        housesum += houseHand[i].getPointValue();
    }
    if (housesum < 18) {
        HOUSE_HAND_SIZE++;
    }
}

void userHit() {
    int choice;
    cout << "Do you want to hit? (1 = yes, 2 = no)" << endl;
    cin >> choice;
    Sleep(1000);
    if (choice == 1) {
        houseHit();
        USER_HAND_SIZE++;
        gamePlay();
    } else if (choice == 2) {
        stand = true;
        gamePlay();
    } else {
        cout << "Invalid Choice" << endl;
        userHit();
    }
}



void gamePlay() {
    // Prints User hand at the beginning of each round
    printHand();

    // Determines point totals for player and house
    int usersum = 0;
    int housesum = 0;
    for (int i = 0; i < USER_HAND_SIZE; i++) {
        usersum += userHand[i].getPointValue();
    }
    for (int i = 0; i < HOUSE_HAND_SIZE; i++) {
        housesum += houseHand[i].getPointValue();
    }
    
    //cout << "User Hand Value: " << usersum << endl;
    //cout << "House Hand Value: " << housesum << endl;
    
    // Logic for winning vs losing
    if (usersum == 21) {
        cout << "You win! Blackjack!" << endl;
        playAgain();
    } else if (usersum > 21) {
        cout << "Bust! You Lose!" << endl;
        playAgain();
    } else if (usersum < 21 && stand) {
        if (housesum > usersum) {
            printHouseHand();
            cout << "The House Wins." << endl;
            playAgain();
        } else if (housesum == usersum) {
            printHouseHand();
            cout << "Tie - The House Wins" << endl;
            playAgain();
        } else if (housesum < usersum) {
            printHouseHand();
            cout << "You Win!" << endl;
            playAgain();
        }
    } else if (usersum < 21 && !stand) {
        userHit();
    }
}   

void playAgain() {
    int choice;
    cout << "Play Again? (1 = yes, 2 = no)" << endl;
    cin >> choice;
    if (choice == 1) {
        system("CLS");
        createHands();
        gamePlay();
    } else if (choice == 2) {
        cout << "Game Over" << endl;
        exit(0);
    } else {
        cout << "Invalid Choice" << endl;
        playAgain();
    }
}

int main() {
    createHands();
    
    return 0;
}



