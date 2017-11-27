#include <iostream>
using namespace std;
void findLowest(int temp, double &low);
double calcAverage(int sum, int n, double &low);
double low = 100;
int main() {
    int tests = 0, temp = 0, sum = 0;
    cout << "Number of Tests: ";
    cin >> tests;

    for (int i = 0; i < tests; i++) {
        cout << "\nTest " << i+1 << " Score: ";
        cin >> temp;
        sum += temp;
        findLowest(temp, low);
    }

    cout << "\nAverage: " << calcAverage(sum, tests, low);
    return 0;
}

void findLowest(int temp, double &low) {
    if (temp < low)
        low = temp;
}

double calcAverage(int sum, int n, double &low) {
    return ((sum - low)/(n-1));
}
