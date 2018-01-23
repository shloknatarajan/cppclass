#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
vector <double> grades;

void displayVector(vector <double> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "\t";
    }
}

double droplowest(vector <double> &vec) {
    int lowestindex = 0;
    int lowestnum = vec[0];
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] < lowestnum) {
            lowestnum = vec[i];
            lowestindex = i;
        }
    }
    vec.erase(vec.begin() + lowestindex);
    return lowestnum;
}

double average(vector <double> &vec) {
    double sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    return (sum / vec.size());
}

void addGrade(vector <double> &vec, double num) {
    vec.resize(vec.size() + 1);
    vec[vec.size()-1] = num;
}

int main() {
    string name;
    double n;
    ifstream fin;
    fin.open("GradesText.txt");

    if(!fin) {
        cout << "Can't open input file" << endl;
        cout << "Program terminates" << endl;
        return 1;
    }

    getline(fin, name);
    while(!fin.eof()) {
        fin >> n;
        addGrade(grades, n);
        //cout << "Added grade " << n << endl;
    }

    // Printing Data
    cout << "Student name is: " << name << endl;
    cout << "Filling grades vector from text file." << endl;
    displayVector(grades);
    cout << "\nThe dropped score is " << droplowest(grades) << endl;
    cout << name << " has a test average of: " << average(grades) << endl;





    return 0;
}