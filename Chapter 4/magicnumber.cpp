/* magicNumber.cpp. Introduction to if statements and switch statements
Note: conditional logic part has been commented out
*/
#include <iostream>
#include <time.h>    // Me - need for using time seed with srand
#include <windows.h> // Me - need for sleep
using namespace std;
void menu();
void playGame();
int main()
{
    menu();
    return 0;
}
void menu()
{
    int choice = 0;
    cout << "Enter the number of your choice:\n" // all this menu is one line
         << "1. Play my game.\n"
         << "2. Say hello.\n"
         << "3. Quit.\n\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        playGame();
        break;
    case 2:
        cout << "Hello there!" << endl;
        menu();
        break;
    case 3:
        cout << "Thanks for playing! Bye bye.\n\n"
             << endl;
        break;
    default:
        cout << "Not a valid choice." << endl;
        menu();
    }
}
void playGame()
{
    // char reply; // Note: Conditional Logic part commented out
    int magicNum;
    int guess;
    bool gotIt = false;
    srand((unsigned)time(NULL)); // one method for seeding srand is with time
    function
        magicNum = rand() % 100 + 1;
    // Me - ??? ensures cin, cout, cerr associated with new stdin, stdout, stderr?
    ios::sync_with_stdio();
    // cout<<"Welcome to the guessing game. Would you like to play a round (y/n)?";
    // cin>>reply;
    // if(reply=='y' || reply=='Y') //Note: Conditional Logic part commented out
    // {
    cout << "\nThe magic number is between 1 and 100.\n\n" // same line continued
         << "Watch closely as I give a quick hint.\n\n"    // same line continued
         << "***** *****";
    Sleep(3000);
    cout << "\r***** " << magicNum << " *****";
    Sleep(500);
    cout << "\r***** *****";
    cout << "\n\nWhat was the magic number? You have 2 guesses. ";
    cin >> guess;
    if (guess == magicNum)
    {
        cout << "\nThat's right!\n\n";
        gotIt = true;
    }
    else if (magicNum > guess)
    {
        cout << "\nYour guess is too low. Try again.\n\n";
    }
    else if (magicNum < guess)
    {
        cout << "\nYour guess is too high. Try again.\n\n";
    }
    if (!gotIt)
    {
        cin >> guess; // 2nd guess
        if (guess == magicNum)
        {
            cout << "\nThat's right!\n\n";
        }
        else
        {
            cout << "\nSorry. You lost this game.\n\n";
        }
    }
    menu(); // call menu() again
    // }
} // end playGame()