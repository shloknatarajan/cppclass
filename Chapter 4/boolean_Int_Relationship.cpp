/*
	In C++, you can use either a bool variable or an int variable to store true
	and false.

	Using ints comes from earlier versions of C++ since logical expressions
	evaluate to either 1 (true) or 0 (false).

	ALL NONZERO VALUES ARE TREATED AS TRUE.		(0 is false)

	Some implications of this int / boolean relationship is shown below.
*/

#include <iostream>	
using namespace std;

int main()
{
	int num = 5;

	int answer1 = (num < 10);
	cout << "True is the same as " << answer1 << endl;

	int answer2 = (num > 10);
	cout << "False is the same as " << answer2 << endl<<endl;

	/***********************************************************************
		Example 1 below : return of integer other than 0

		Recall that "return 0" returns a 0 to the operating systems
		and indicates there was no error during program execution.

		Return of any other integer (non-zero) can be used to halt the program.
	************************************************************************/

				//  return 273;		// comment out to run entire program

	/************************************************************************
		Example 2 below: Confusion between == (equality) and = (assignment)

		In the expression below, the value of 5 is assigned to x.  
		ALSO, 5 becomes the value of the expression in the if statement.
		Since any nonzero value is true, the cout occurs.

		Also note that the value of x has been changed to 5 which probably 
		wasn't intended!

	***********************************************************************/

	int x = 7;

	if (x = 5)		// instead of x == 5
	{
		cout << "The number equals five\n";
	}

	cout << "x is now " << x << endl << endl;

	/***********************************************************************

		Example 3 below: associativity of relational operators

		Consider the code:

			if (0 <= num && num <= 10)		(Correct!)

		What if instead you write:
		
			if (0 <= num <= 10)		(Incorrect!)

		This will still run even though the results may be incorrect.

		In the case below, because relational operators are from left to right,

		(0 <= 20) is evaluted first:

		(0 <= 20) <= 10			( 0 <= 20  evaluates to true which is 1)

		1  <= 10				( true is 1)

		1   (true)

	*************************************************************************/
	
	num = 20;

	if (0 <= num <= 10)
		cout << num <<" is between 0 and 10" << endl << endl;

	return 0;
}
