#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

void menu();
void handleinput();
void numtest();
void stringtest();

void menu() {
    cout << "\n" << setw(10) << setfill('-') << right << "-" << "Palindromes" << setw(10) << setfill('-') << right << "-" << endl;    
    cout << "1) Numeric Palindrome Test\n2) String Palindrome Test\n3) Quit\n";
}

void handleinput(char c) {
    
}

void numtest() {
    int a,num,b,temp=0;
	cout<<"Number: ";
	cin>>num;
	b=num;
	while(num>0) {
		a=num%10;
		num=num/10;
		temp=temp*10+a;
	}

	if(temp==b)
        cout << b << " is a palindrome" << endl;
    else 
        cout << b << " is not a palindrome" << endl;
        
}

void stringtest() {
    string original, back, forward;
    cout << "String: ";
    cin.ignore(80,'\n');
    getline(cin, original);
    for (int i = 0; i < original.length(); i++) {
        if (isalpha(original[i]))
            forward += tolower(original[i]);
    }
    for (int i = (forward.length()-1); i >= 0 ; i--) {
        back += forward[i];
    }

    if (forward == back) {
        cout << forward << " is a palindrome\n";
    } else {
        cout << forward << " is not a palindrome\n";
    }
}

void main() {
    int choice;
    while (1) {
        menu();
        cin >> choice;
        switch(choice) {
            case 1:
                numtest();
                break;
            
            case 2:
                stringtest();
                break;

            case 3:
                exit(EXIT_SUCCESS);
                break;
            
            default:
                cout << "Invalid Choice\n";
        }
    }
}