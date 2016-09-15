#include <iostream>

/* 
     3wordsort.cpp -- program to print out three words in alpha order

     usage: ./3wordsort
     input: three words
    output: the three words in alphabetical order, separated by spaces
      note: Do not prompt the user; Do not print explanations on output.
            In fact, don't modify main().
    
    modified by: James McCants
    modified on: 9/23/13
 */

using namespace std;

void printInOrder(string s1, string s2, string s3);

int main()
{
	string	w1, w2, w3;		// input values
	
	cin >> w1 >> w2 >> w3;		// read in three values
	printInOrder(w1, w2, w3);	// function does not return anything

	return 0;
}

//
// printInOrder() prints out the three words in alpha order
//		  with spaces between them, no return value
//
void printInOrder(string x, string y, string z)	
{
  // your code here
  // your function does NOT use return
  // Instead, it sends values to cout
  // Just print the 3 strings as described in the assignment
  // with no extra stuff.

  if(x <= y && x <= z && y <= z) {
    cout << x << " " << y << " " << z << endl;
  } else if(x <= y && x <= z && z <= y) {
    cout << x << " " << z << " " << y << endl;
  } else if(y <= x && y <= z && x <= z) {
    cout << y << " " << x << " " << z << endl;
  } else if(y <= x && y <= z && z <= x) {
    cout << y << " " << z << " " << x << endl;
  } else if(z <= x && z <= y && x <= y) {
    cout << z << " " << x << " " << y << endl;
  } else if(z <= x && z <= y && y <= x) {
    cout << z << " " << y << " " << x << endl;
  }
 
}
