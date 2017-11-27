#include <iostream>
#include <string>

using namespace std;

// Global Variables
string name, live, a, b, c;

// Function Prototypes
void foundh(string &name);
void letterCount(string &name);
void alphabetize(string &a, string &b, string &c);

// Main
void main() {

    cout << "Name: ";
	getline(cin, name);

	cout << "Location: ";
	getline(cin, live);

    foundh(name);
    letterCount(name);

    cin.ignore(256, '\n');
    cout << "String 1: ";
    getline(cin, a);
    cout << "String 2: ";
    getline(cin, b);
    cout << "String 3: ";
    getline(cin, c);

    alphabetize(a, b, c);
    cout << a << endl << b << endl << c << endl;

    name = name + " the great";
    cout << "Goodbye " << name;
    
}

// Functions
void foundh(string &name) {
    int hcount = 0;
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == 'h') {
            hcount++;
        }
    }

    if (hcount == 0) {
        cout << "h not found" << endl;
    } else {
        cout << "h found " << hcount << " times" << endl;
    }
    
}

void letterCount(string &name) {
    char letter;
    int lcount = 0;
    cout << "Enter a letter to count occurences of: ";
    letter = cin.get();

    for (int i = 0; i < name.length(); i++) {
        if (tolower(name[i]) == tolower(letter)) {
            lcount++;
        }
    }

    if (lcount == 0) {
        cout << letter << " not found" << endl;
    } else {
        cout << letter << " found " << lcount << " times" << endl;
    }
}

void alphabetize(string &a, string &b, string &c) {
    for (int i = 0; i < a.length(); i++) {
        if (tolower(a[i]) < tolower(b[i])) {
            break;
        } else if (tolower(a[i]) > tolower(b[i])) {
            swap(a, b);
            break;
        }
    }

    for (int i = 0; i < b.length(); i++) {
        if (tolower(b[i]) < tolower(c[i])) {
            break;
        } else if (tolower(b[i]) > tolower(c[i])) {
            swap(b, c);
            break;
        }
    }

    for (int i = 0; i < a.length(); i++) {
        if (tolower(a[i]) < tolower(b[i])) {
            break;
        } else if (tolower(a[i]) > tolower(b[i])) {
            swap(a, b);
            break;
        }
    }
}


