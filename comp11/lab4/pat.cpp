//
//  pat.cpp  -- draw a checkerboard pattern
//  version1: draws 8 rows of 8 chars alternating X and -
//  Goal: allow user to enter two strings and 
//		the number of pairs per line
//		the number lines per set
//		the number sets per image
//
//  tools: loops and functions(with arguments)
//

#include <iostream>

using namespace std;

void twolines(string s1, string s2, int reps);     //declaration

int main()
{
  string str1, str2;
  int rep;
  int row;

  cout << "Input two strings: ";
  cin >> str1 >> str2;
  cout << "Input number of pairs of strings per row: ";
  cin >> rep;
  cout << "Input number of pairs of rows: ";
  cin >> row;

  int how_many = row;
  int counter  = 0;

  while (counter < how_many) {
    twolines( str1, str2, rep);
    counter++;
  }
  return 0;
}

void twolines(string s1, string s2, int reps)
{
  int how_many = reps;
  int counter  = 0; 

  while (counter < how_many) {
    cout << s1 << s2;
    counter++;
  }    
  cout << endl;
  
  int counter1 = 0;

  while (counter1 < how_many) {
    cout << s2 << s1;
    counter1++;
  }
  cout << endl;
}
