#include <iostream>
#include <string>
using namespace std;
void main() {
    string name;
    cout << "What is your name" << endl;
    cin >> name;

    for (int i = 0; i < name.length(); i++) {
        cout << name[i] << "\t" << int(name[i]) << endl;
    }

}