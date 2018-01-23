#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

vector <string> names;

void displayVector(vector <string> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
}

void removeLast(vector <string> &vec) {
    vec.resize(vec.size()-1);
}

void addName(vector <string> &vec, string s) {
    vec.resize(vec.size() + 1);
    vec[vec.size()-1] = s;
}

void searchreplace(vector <string> &vec, string a, string b) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == a) {
            vec[i] = b;
        }
    }
}

void searchremove(vector<string> &vec, string toRemove) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == toRemove) {
            vec[i] = vec[vec.size()-1];
            break;
        }
    }
    vec.resize(vec.size()-1);
}

void searchremove2(vector <string> &vec, string toRemove) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == toRemove) {
            vec.erase(vec.begin() + i);
        }
    }
}

int main() {
    vector <string> names;
    cout << "Original Vector: " << endl;
    addName(names, "Amy");
    addName(names, "Bo");
    addName(names, "Carl");
    addName(names, "Doris");
    addName(names, "Eve");
    displayVector(names);

    cout << endl << "Remove Last: " << endl;
    removeLast(names);
    displayVector(names);

    cout << "\nAdd Fred: \n";
    addName(names, "Fred");
    displayVector(names);

    cout << "\nReplace Carl with Cal: \n";
    searchreplace(names, "Carl", "Cal");
    displayVector(names);

    cout << "\nRemove Amy (changing order): \n";
    searchremove(names, "Amy");
    displayVector(names);

    cout << "\nRemove Bo (without changing order): \n";
    searchremove2(names, "Bo");
    displayVector(names);

    return 0;
}