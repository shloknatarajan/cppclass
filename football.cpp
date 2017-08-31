#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
void main() {
    string name, occupation;
    ifstream fin;
    ofstream fout;
    int b, age;
    float a, sales[8], rev;
    age = 0;
    b = 0;
    rev = 0;

    // Open file and get sales into array sales[]
    fin.open("sales.txt");
    if (fin.is_open()) {
        while(fin >> a) {
            sales[b] = a;
            // cout << "a is " << a << " and b is " << b << ": " << sales[b] << " ";
            b++;            
        }
    } else { 
        cout << "Failed to open file" << endl;
    }

    // Calculate the total revenue
    for(int i = 0; i < 8; i+=2) {
        rev += (sales[i] * sales[i+1]);
    }

    // Questions
    cout << "Name: ";
    getline(cin, name);
    cout << "\nAge: ";
    cin >> age;
    cout << "\nOccupation: ";
    getline(cin, occupation);    
    getline(cin, occupation);
    
    // Print Everything
    cout << "\nTIcket Sales for: " << name << "\nOccupation: " << occupation << " \nAge: " << age << "\n\n";
    cout << setfill('=') << setw(36) << right << "=" << endl;
    cout << setfill(' ') << left << setw(18) << "Ticket Price" << right << setw(18) << "Number Sold" << endl;
    cout << setfill('=') << setw(36) << right << "=" << endl;
    cout << setfill(' ');
    
    for (int i=0; i < 8; i+= 2) {
        cout << setprecision(2) << fixed << left << setw(18) << sales[i];
        cout << setprecision(0) << right << setw(18) << sales[i+1] << endl;
    }

    cout << setfill('=') << setw(36) << right << "=" << endl;
    cout << setprecision(2);
    cout << fixed;
    cout << "GROSS REVENUE: " << rev;


    fin.close();
    fout.close();
}