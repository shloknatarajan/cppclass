#include <iostream>
#include <string>

using namespace std;

void displayReverse(string);

int main() {
	string s;
	cout << "String: ";
	getline(cin, s);

	displayReverse(s);

	return 0;
}

void displayReverse(string s) {
    cout << "Reversed String:";
	for(int i = s.length(); i >= 0; i--) {
		cout << s[i];
	}
	cout << endl;
}