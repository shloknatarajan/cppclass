#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
    ifstream fin;
    ofstream fout;
    
    int num;
    double min, current, interest, charge;
    char type;
    string fulltype, ending;
    bool fine = true;
    
    fin.open("inData.txt");
    //fout.open("accounts.txt");
    fout.open("accounts.txt", ios::app);
    while(!fin.eof()) {
        fin >> num >> type >> min >> current;

        if (type == 'S' || type == 's') {
            fulltype = "Savings";
            interest = 0.04;
            charge = 10;
        } else {
            fulltype = "Checking";
            if (current - min < 5000) {
                interest = 0.03;
            } else {
                interest = 0.05;
            }
            charge = 25;
        }

        if (current >= min) {
            fine = false;
            charge = 0;
        } else {
            fine = true;
            interest = 0;

        }

        fout << "Account: " << num << "\tType: " << fulltype << fixed << showpoint << setprecision(2) << "\tCurrent balance: $" << (current*(1+interest))-charge << endl;
        
        if(fine) {
            fout << "Account was chargd a $" << charge << " fee for being below minimum balance.\n\n";
        } else {
            fout << "Account earned " << noshowpoint << (int)(interest*100) << "% interest.\n\n";
        }
    }

    return 0;
}