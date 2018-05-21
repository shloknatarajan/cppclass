#ifndef CARD_H
#define CARD_H
using namespace std;

class Card {
    private:
        char suit;
        char type;
        int pointValue;

    public:
        Card();

        char getSuit();
        char getType();
        int getPointValue();

        /*char setSuit(char c);
        char setType(char c);
        int setPointValue(int n);*/

        void deal();
        void show();
};

#endif