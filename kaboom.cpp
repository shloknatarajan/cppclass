#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

void menu();
void kaboom();
void averages();
void drawRectangle();
void cleanconsole();

void menu() {
    cout << "\n" << setw(10) << setfill('-') << right << "-" << "Loop Practice (choose a number)" << setw(10) << setfill('-') << right << "-" << endl;    
    cout << "1) Kaboom\n2) Averages\n3) Draw Rectangle\n4) Clear Screen/Restart\n5) Quit\n";
}

void kaboom() {
    string s;
    for (int i = 10; i > 0; i--) {
        s += to_string(i);
        s += "...";
    }
    cout << s;   
}

void averages() {
    cout << "Enter Numbers:\n";
    char c;
    int num = 0, count = 0;
    double avg = 0, sum = 0;
    
    while (1) {
        //cin.ignore(1000, '\n');
        c = cin.get();

        while (c == ' ' || c == '\n') {
            c = cin.get();
        }

        cin.putback(c);

        if (c == 'q' || c == 'Q') {
            break;
        } 

        cin >> num;
        //cout << "num: " << num << endl;
        //cout << "New Sum = " << sum << "+=" << num << " = " << (sum+num) << endl;
        sum+=num;
        //cout << "count++" << endl;
        count++;     
    }
    
    /*cout << "sum: " << sum << endl;
    cout << "count " << count << endl;
    cout << "avg = " << sum/count << endl;*/
    avg = sum/count;    
    cout << "Average: " << avg;
}

void drawRectangle() {
    int height = 0, width = 0;
    cout << "Enter Height: ";
    cin >> height;
    cout << "Enter Width: ";
    cin >> width;

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}

void cleanconsole() {
    system("cls");
}


void main() {
    int choice = 0;

    while(1) {
        menu();
        cin >> choice;
        cout << "Choice = " << choice << endl;
        switch (choice) {
            case 1: 
                kaboom();
                break;

            case 2:
                averages();
                break;
                // Why tf does the program break when running this one. It autoselects choice 2 when the program is supposed to repeat and get stuck
            case 3: 
                drawRectangle();
                break;
            
            case 4:
                cleanconsole();
                break;

            case 5:
                exit(EXIT_SUCCESS);
                break;
            
            default:
                cout << "Invalid input" << endl;
        }
    }
}