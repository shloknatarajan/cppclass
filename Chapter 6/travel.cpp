#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int ppl, instruct, rent, icost, ecost, base, sub, tax, deposit, total;
void menu();
double climbing(int &ppl, int &instruct, int &rent);
double climbing(int all);
double scuba(int &ppl, &instruct);
double spelunking(int &ppl, int &rent);
void getTotal();

int main () {
    int choice;
    menu();
    cin >> choice;
    cout <<"Numer of People in Party: ";
    cin >> ppl;
    cout << "\nNumer of People Needing Instruction";
    cin >> instruct;
    cout << "\nNumber of People Needing Equipment";
    cin >> rent;

    switch (choice) 
        case 1:      
            break;
    return 0;
}

void menu() {
    cout << "Vacation Packages: " << endl;
    cout << "1) Devil's Courthouse Adventure Weekend\n2) Suba Bahama\n3) Barron Cliff Spelunk\n4) Exit Program\n";
    cout << "Enter 1, 2, 3, or 4: ";
}

double climbing(int &ppl, int &instruct, int &rent) {
    int total = 0;
    base = 
    // Applies discount for parties of 5 or more
    if (ppl > 4) {
        total += ((double)ppl * 350 * 0.9);
    } else {
        total += (ppl *350);
    }

    total += instruct * 100;
    total += rent*120;
    return total;
    sub = total;
}

double climbing(int all) {
    int total = 0;
    
        // Applies discount for parties of 5 or more
        if (ppl > 4) {
            total += ((double)all * 350 * 0.9);
        } else {
            total += (all *350);
        }
    
        total += all * 100;
        total += all * 120;
        return total;
}



