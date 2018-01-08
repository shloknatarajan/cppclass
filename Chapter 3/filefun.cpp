// 5 Steps for file I/O
//Step 1: Include header file <fstream>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath> // for pow function

using namespace std;
int main() {
    // Step 2: Declaring file stream variables

    ifstream fin; // input file stream - for reading data IN
    ofstream fout; // output file stream - for reading data OUT
    // fin and fout are just variable names

    const double PI = 3.14159;
    string user = "", item = "";
    double diam = 0, area = 0;

    // Step 3: Associate file stream variables with I/O sources
    
    fin.open("circledata.txt"); // open file for reading
        // file must be in folder with cpp
    
    fout.open("circleoutput.txt"); // open file for writing
        // makes file if it doesn't already exist
        // if file exists, it's erased/written over (unless append specified)
    
    getline(fin, user); // get first line of data - store in 'user'
    
    // Step 4: Use file stream variables with << >>
    fout << "Circle Data For: " << user << "\n\n\n";
    fout << left << setw(20) << "Item" << right << setw(15) << "Area" << endl;
    fout << setw(35) << setfill('_') << "_" << endl << endl;

    fout << fixed << showpoint << setprecision(3);
    fout << setfill(' ');

    while (!fin.eof()) // while not at end of fin file
    {
        getline(fin, item);
        fin >> diam;
        fin.ignore(80, '\n');
        
        area = PI *pow(diam/2.0, 2);
        fout << left << setw(20) << item << right << setw(15) << area << endl;
    }
    
    // Step 5: Close files
    fin.close();
    fout.close();
    return 0;
}