#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Drink {
    string name;
    double price;
    int available;
};

Drink allDrinks[5] = {{"Cola", 0.75, 20},
                      {"Root Beer", 0.75, 20},
                      {"Lemon-Lime", 0.75, 20},
                      {"Grape Soda", 0.80, 20},
                      {"Cream Soda", 0.80, 20}, 
};

void displayDrinks();
void chooseDrink();
void calcChange(Drink d, double paid);

void displayDrinks() {
    for (int i = 0; i < 5; i++) {
        cout << (i+1) << ")  ";
        cout << setw(20) << left << allDrinks[i].name;
        cout << fixed << showpoint << setprecision(2) << allDrinks[i].price << endl;
    }
    cout << "6)  Leave the drink machine\n";
}

void chooseDrink() {
    int choice;
    double money;
    cout << "Choose one: ";
    cin >> choice;

    if (choice > 6 || choice < 1) {
        cout << "\nInvalid choice\n";
        chooseDrink();
    }

    if (choice == 6) {
        exit(EXIT_SUCCESS);
    }

    if (allDrinks[choice].available < 1) {
        cout << "\nSold Out!\n";
        chooseDrink();
    }

    cout << "\nEnter an amount of money: ";
    cin >> money;

    if (money - allDrinks[choice].price < 0) {
        cout << "\nInsufficient Funds\n";
        displayDrinks();
        chooseDrink();
    } else {
        cout <<"Thump, thump, thump. Enjoy your beverage!\n";
        cout << "\nChange calculated: " << (money - allDrinks[choice].price) << endl;
        cout << "Your change, " << (money - allDrinks[choice].price) << " has dropped into the dispenser" << endl;
        allDrinks[choice].available--;
        cout << "There are " << allDrinks[choice].available << " drinks of that type left.\n";
    }
}

void main() {
    while (true) {
        displayDrinks();
        chooseDrink();
    }
}



