#include <iostream>
#include <cmath>
using namespace std;

// Global & Function Prototypes
enum triangleType{scalene, isosceles, equilateral, noTriangle};
triangleType triangleShape(double a, double b, double c);
void printShape(triangleType type);
bool isTriangle(double a, double b, double c);

// Main
void main() {
    double a, b, c;
    cout <<"Side 1: ";
    cin >> a;
    cout <<"Side 2: ";
    cin >> b;
    cout <<"Side 3: ";
    cin >> c;

    printShape(triangleShape(a, b, c));

}

triangleType triangleShape(double a, double b, double c) {
    if (!(isTriangle(a, b, c))) {
        return noTriangle;
    }

    if (a == b && b == c) {
		return equilateral;
    } else if (a == b || b == c || a == c) {
		return isosceles;
    } else {
		return scalene;
    }
}

bool isTriangle(double a, double b, double c) {
    if (a + b < c) {
        return false;
    }

    if (a + c < b) {
        return false;
    }

    if (b + c < a) {
        return false;
    }
    
    return true;
}

void printShape(triangleType type) {
    switch(type) {
		case scalene:
			cout << "Scalene" << endl;
			break;
		case isosceles:
			cout << "Isosceles" << endl;
			break;
		case equilateral:
			cout << "Equilateral" << endl;
			break;
		case noTriangle:
			cout << "Not a triangle" << endl;
			break;
	}
}