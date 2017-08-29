#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
    string name;
    float gross, fed, state, ss, med, pension, health, net;
    cout << "Employee name: " << endl;
    getline(cin, name);
    cout << "\nGross Pay: " << endl;
    cin >> gross;

    fed = gross * 0.15;
    state = gross * 0.035;
    ss = gross * 0.0575;
    med = gross * 0.0275;
    pension = gross * 0.05;
    health = 75;
    net = gross - fed - state - ss - med - pension - health;
    cout << name << endl;
    cout.width(35);
    cout << setprecision(2) << fixed;
    cout << left << net << endl;
    cout << left << "Gross Amount" << right << gross;

    /*cout.width(45);
    cout << setfill('*') << setw(45);
    cout << left << "hi" << right << "Hola Amigos" << endl;*/


    
}
