#include <iostream>
using namespace std;
void main() {
    int length;
    double inches, yards, feet;
    cout << "Enter a length (cm)" << endl;
    cin >> length; 
    inches = length / 2.54;
    yards = inches / 36;
    yards = int(yards);
    inches = inches - yards * 36; 
    feet = inches / 12;
    feet = int(feet); 
    inches = inches - feet * 12;
    inches = int(inches);
    cout << yards << " yard(s), " << feet << " feet, " << inches << " inch(es)" << endl;
}