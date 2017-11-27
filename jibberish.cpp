#include <iostream>
#include <string>
#include <regex>

using namespace std;

string jib(string s);
void jibWords(string s);

int main() {
    int repeat = 1;
    string s, out;
    while(repeat == 1) {
        cout << "Enter phrase:\n";
        getline(cin, s);

        cout << "Jibberish: ";
        jibWords(jib(s));

        cout << "Type 1 to do another one: ";
        cin >> repeat;
        cin.ignore(256, '\n');
    }

    return 0;
}

string jib(string s) {
	regex re("([a|o|i|u|y|e]+)");
	return regex_replace(s, re, "iddig$&");
}

void jibWords(string s) {
	for (int i = 0; i < s.length(); i++)
		cout << (char)tolower(s[i]);
	cout << endl;
}