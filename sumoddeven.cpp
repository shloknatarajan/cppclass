#include <iostream>
using namespace std;
bool isEven(int n) {
    if (n % 2 == 0)
        return true;
    else
        return false;
}
void main() {
    
    // Test numbers: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
    
    char c;
    int num = 0, totale = 0, totalo = 0;
    cout << "Please enter integers (end with q)" << endl;

    while (1) {
        c = cin.get();
        while (c == ' ' || c == '\n') {
            c = cin.get();
        }
        cin.putback(c);

        if (c == 'q' || c == 'Q') {
            break;
        }

        cin >> num;

        if(isEven(num)) {
            totale += num;
        } else {
            totalo += num;
        }
    }

    cout << "Even sum: " << totale;
    cout << "\nOdd sum: " << totalo;

}