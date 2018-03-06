#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct menuItemType {
    string item;
    double price;
};

menuItemType menuList[8];
vector <menuItemType> selections;

void getData();
void showMenu();
void userSelect();
void printCheck();

void getData() {
    ifstream fin;
    fin.open("menu.txt");
    string name;
    double cost;
    for (int i = 0; i < 8; i++) {
        getline(fin, name);
        fin >> cost;
        fin.ignore();
        menuList[i].item = name;
        menuList[i].price = cost;
    }
}

void showMenu() {
     for (int i = 0; i < 8; i++) {
        cout << i+1 << ")   " << setw(20) << left << menuList[i].item;
        cout << "$" << fixed << showpoint << setprecision(2) << menuList[i].price << endl;
    }
}

void userSelect() {
    char choice;
    cout << "\nSelection: ";
    cin >> choice;
    if (choice == 'E' || choice == 'e') {
        cout << "\nEnding Selection Process\n";
        printCheck();
    }
    int c = (int)choice - 48;
    if (c > 8 || c < 1) {
        cout << "\nInvalid Selection";
        cout << "\n You Selected: " << c;
        userSelect();
    } else {
        selections.push_back(menuList[(c-1)]);
        userSelect();
    }
}

void printCheck() {
    double total = 0;
    for (int i = 0; i < selections.size(); i++) {
        cout << setw(20) << left << selections[i].item;
        cout << fixed << showpoint << setprecision(2) << "$" << selections[i].price << endl;
        total += selections[i].price;
    }

    cout << setw(20) << left << "Tax:" << "$" << total * 0.07 << endl;
    cout << setw(20) << left << "Amount Due:" << "$" << total + total * 0.07;
    exit(EXIT_SUCCESS);
}

void main() {
    getData();
    showMenu();
    userSelect();
}



