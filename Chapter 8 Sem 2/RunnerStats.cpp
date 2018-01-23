#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void readstore(ifstream & inf, double nums[][8], string name[]);
void totalaverage(double nums[][8]);
void printdata(double nums[][8], string name[]);

int main() {
    ifstream fin;
    fin.open("RunnerProgramData.txt");
    
    if(!fin) {
        cout << "Can't open input file" << endl;
        cout << "Program terminates" << endl;
        return 1;
    }

    double miles[5][8];
    string names[5];
    readstore(fin, miles, names);
    totalaverage(miles);
    printdata(miles, names);
    return 0;
}

void readstore(ifstream & inf, double nums[][8], string name[]) {
    for(int i = 0; i < 5; i++) {
        inf >> name[i];
        for (int j = 0; j < 7; j++) {
            inf >> nums[i][j];
        }
    }
}

void totalaverage(double nums[][8]) {
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 7; j++) {
            sum += nums[i][j];
        }
        nums[i][7] = (((double)sum)/7);
        sum = 0;
    }
}

void printdata(double nums[][8], string name[]) {
    cout << setw(10) << left << "Name";
    cout << setw(8) << left << "Day 1";
    cout << setw(8) << left << "Day 2";
    cout << setw(8) << left << "Day 3";
    cout << setw(8) << left << "Day 4";
    cout << setw(8) << left << "Day 5";
    cout << setw(8) << left << "Day 6";
    cout << setw(8) << left << "Day 7";
    cout << setw(8) << left << "Average" << endl;
    for(int i = 0; i < 5; i ++) {
        cout << setw(10) << left << name[i];
        for(int j = 0; j < 8; j++) {
            cout << setw(7) << fixed << showpoint << setprecision(2) << nums[i][j] << " ";
        }
        cout << endl;
    }
}
