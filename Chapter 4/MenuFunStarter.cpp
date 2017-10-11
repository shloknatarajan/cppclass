#include <iostream>
#include <iomanip>

using namespace std;

int num1, num2;			// global variables - generally not best practice

int main()
{
	cout << "Enter an integer:" << endl;
	cin >> num1;

	cout << "Enter another integer:" << endl;
	cin >> num2;


	return 0;

	multiplyNums();
}

void menu()
{
}

void multiplyNums()
{
	cout << num1 << " * " << num2 << " = " << num1*num2 << "\n\n";
}

void divideNums()
{
	cout << num1 << " / " << num2 << " = " << (double)num1 / num2 << "\n\n";
}