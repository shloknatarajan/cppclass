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
    cin >> name;
    cout << "\nAge: ";
    cin >> age;
    cout << "\nOccupation: ";
    cin >> occupation;

    // Print Everything
    cout << "\nTIcket Sales for: " << name << "\nOccupation: " << occupation << " \nAge: " << age << "\n\n";
    cout << "**********************\n" << "Ticket Price\t\t" << "Number Sold";
    cout <<"\n************************\n";
    
    for (int i=0; i < 8; i+= 2) {
        cout << setprecision(2);
        cout << fixed;
        cout << sales[i];
        cout<< setprecision(0);
        cout << "\t\t" << sales[i+1] << endl;
    }

    cout << "************************\n";    
    cout << setprecision(2);
    cout << fixed;
    cout << "GROSS REVENUE: " << rev;




}