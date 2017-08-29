#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
void main() {
    ifstream fin;
    ofstream fout;
    float val, tax;

    // Get Property Value
    cout << "Property Value: ";
    cin >> val;

    // Get taxable amount
    tax = val * 0.92;

    fout.open("property.txt");
    if (fout.is_open()){
        fout << "-------------------Property Tax Data--------------------" << endl;
        fout << "________________________________________________________" << endl;

        fout << setw(28) << left << "Assesed Value: ";
        fout << setw(28) << setprecision(2) << fixed << right << val << endl; 

        fout << setw(28) << left << "Taxable Amount: ";
        fout << setw(28) << right << tax <<endl; 

        fout << setw(35) << left << "Tax Rate for each $100.00: ";
        fout << setw(21) << right << "1.05" << endl; 

        fout << setw(28) << left << "Property Tax: ";
        fout << setw(28) << right << (tax / 100) * 1.05 << endl; 





    }
    


}