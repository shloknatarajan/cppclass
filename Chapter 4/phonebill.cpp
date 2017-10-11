#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

double regularservice(double min) {
    if (min - 50 > 0) {
        return 10 + ((min - 50) * 0.2);
    } else {
        return 10;
    }
}

double premiumservice(double d, double n) {
    double total = 25;
    if (d - 75 > 0)
        total += ((d - 75) * 0.10);
    if (n - 100 > 0) 
        total += ((n - 100) * 0.05);
    return total;
}

int main() {
    int option;
    double minutes, day, night, charge;

    cout << "1. Regular Service\n2. Premium Service\n3. Information about this program\n4. Quit\n";
    cin >> option;

    // Reg Service (1): $10 plus first 50 min free. $0.2 per minute over
    // Premium Service (2): $25 plus first 75 min day free, 0.10 min after. first 100 min night free, 0.05 per min after

        switch(option) {

            case 1: 
                cout << "Minutes: ";
                cin >> minutes;
                charge = regularservice(minutes);
                cout << "\nCharge: $" << fixed << showpoint << setprecision(2) << charge;
                break;

            case 2:
                cout << "Day Time Minutes: ";
                cin >> day;
                cout << "\nNight Time Minutes: ";
                cin >> night;
                charge = premiumservice(day, night);
                cout << "\nCharge: $" << fixed << showpoint << setprecision(2) << charge;
                break;
                
            case 3:
                cout << "This program calculates phone bills";
                
            case 4:
                break;

            default:
                cout << "\nInvalid input" << endl;

        }   
    
    return 0;
}