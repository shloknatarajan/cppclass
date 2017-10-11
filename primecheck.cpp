#include <iostream>
using namespace std;

bool isprime();
bool isEven();

bool isEven(int n) {
    if (n % 2 == 0)
        return true;
    else
        return false;
}

bool isPrime(int n) {
    /*if (n % 2 == 0) {
        if (n == 2) {
            return true;
        } else {
            return false;
        }
    } else {

        for (int i = 0; i < sqrt(n); i++) {
            if (n % i == 0) {
                return true;
            }
        }
        
        return false;
    }*/

    if (n == 2)
        return true;
    if (n == 3)
        return true;
    if (n % 2 == 0)
        return false;
    if (n % 3 == 0)
        return false;

    int i = 5;
    int w = 2;

    while (i * i <= n) {
        if (n % i == 0)
            return false;

        i += w;
        w = 6 - w;
    }

    return true;
}



void main() {
    int num = 0;
    char c;
    while (1) {
        cout << "Enter a postive number: ";
        cin >> num;
        
        if (isPrime(num)) {
            cout << num << " is a prime number.\n";
        } else {
            cout << num << " is not a prime number.\n";
            
        }

        cout << "\nDo you want to test another number?\nEnter 1 to continue or any other key to quit\n";
        cin >> c;

        if(c == '1') {
            continue;
        } else {
            break;
        }
        

    }
}