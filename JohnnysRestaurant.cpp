#include <iomanip>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct menuItemType {
    string name;
    double price;
};

menuItemType menuList[8];


void getData(menuItemType menuList[8]) {
    ifstream fin;
    fin.open("menu.txt");

    string name;
    double price;

    for (int i = 0; i < 8; i++) {
        getline(fin, name);
        fin >> price;
        fin.ignore();
        menuList[i].name = name;
        menuList[i].price = price;
    }
}

void showMenu(menuItemType menuList[8]) {
    for (int i = 0; i < 8; i++) {
        cout << i+1 <<".  " << setw(20) << menuList[i].name << setw(7) << menuList[i].price << endl;
    }
    cout << "E.  Exit\n";
}

void order(vector<menuItemType> vec) {
    bool loop = true;
    int i = 0;
    char val;
    while (loop) {
        cout << "Purchase " << i+1 << ": ";
        cin >> val;

        if(val == 'E') {
            loop = false;
        } else {
            vec[i] = menuList[val];
            i++;
        }
        
        cout << endl;

    }
}

void printCheck(vector<menuItemType> vec) {
    double total, tax;
    for(int i = 0; i < vec.size(); i++) {
        total += vec[i].price;
        cout << setw(20) << left << vec[i].name << setw(10) << "$" << vec.[i].price << endl;
    }

    tax = (total * 0.07);
    cout << setw(20) << left << "Tax" << setw(10) << fixed << showpoint << setprecision(2) << tax << endl;
    cout << setw(20) << left << "Amount Due" << setw(10) << "$" << fixed << showpoint << setprecision(2) << (total-tax); 
    
}

void main() {
    vector <menuItemType> uservec;
    getData(menuList);
    showMenu(menuList);
    order(uservec);
    printCheck(uservec);
}