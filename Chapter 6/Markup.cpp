#include <iostream>
#include <iomanip>
using namespace std;

double retailPrice(double wsale, double per) {
    if (wsale < 0 || per < 0) {
        return 0;
    }

    return (wsale + ((per/100)*wsale));
}

int main() {
    double price, markup;
    cout << "Price: ";
    cin >> price;
    cout << "\nMarkup percentage (1-100):";
    cin >> markup;
    cout << "\nRetail Price: " << fixed << showpoint << setprecision(2) << "$" << retailPrice(price, markup);
    return 0;
}

