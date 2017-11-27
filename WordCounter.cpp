#include <iostream>
#include <string>

using namespace std;
int numwords(string s);
void main() {
    string s;
    cout << "String: ";
    getline(cin, s);
    cout << "Words: " << numwords(s);
}

int numwords(string s) {
    int words = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            words++;
        }
    }
    return words;
}

