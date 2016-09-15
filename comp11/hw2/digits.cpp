// iftest.cpp
//      purpose: report number of digits in an integer
//        shows: use of output, input, conditional statements
//         note: has bugs, needs work
//
//  modified by:James McCants
//         date:9/13/13
//

#include <iostream>
using namespace std;

int main()
{
	int input;

	cout << "Enter a number: ";
	cin  >> input;

	if (input >= 100) {
		cout << "input has three or more digits" << endl;
	} else if ( input >= 10) {
		cout << "input has two digits" << endl;
	} else if ( input >= 0) {
		cout << "input has one digit" << endl;
	} else if ( input <= -100) {
	        cout << "input has three or more digits and input is negative" << endl;
	} else if ( input <= -10) {
	        cout << "input has two digits and is negative" << endl;
	} else if ( input < 0) { 
		cout << "input has one digit and is negative" << endl;
	}

        return 0;
}
