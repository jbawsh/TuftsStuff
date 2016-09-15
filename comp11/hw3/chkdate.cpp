//
// This program checks if dates are valid between 1/1/1 and 12/31/9999
// James McCants
// 9/24/13
//

#include <iostream>

using namespace std;

int main()
{
  int mm = 0;
  int dd = 0;
  int yyyy = 0;
  const int jan = 1, feb = 2, mar = 3, apr = 4, may = 5, jun = 6;
  const int jul = 7, aug = 8, sep = 9, oct = 10, nov = 11, dec = 12;

  cin >> mm >> dd >> yyyy;

  if(mm == jan && 1 <= dd && dd <= 31 && 1 <= yyyy && yyyy <= 9999) {
    cout << "Y" << endl;
  } else if(mm == mar && 1 <= dd && dd <= 31 && 1 <= yyyy && yyyy <= 9999) {
    cout << "Y" << endl;
  } else if(mm == apr && 1 <= dd && dd <= 30 && 1 <= yyyy && yyyy <= 9999) {
    cout << "Y" << endl;
  } else if(mm == may && 1 <= dd && dd <= 31 && 1 <= yyyy && yyyy <= 9999) {
    cout << "Y" << endl;
  } else if(mm == jun && 1 <= dd && dd <= 30 && 1 <= yyyy && yyyy <= 9999) {
    cout << "Y" << endl;
  } else if(mm == jul && 1 <= dd && dd <= 31 && 1 <= yyyy && yyyy <= 9999) {
    cout << "Y" << endl;
  } else if(mm == aug && 1 <= dd && dd <= 31 && 1 <= yyyy && yyyy <= 9999) {
    cout << "Y" << endl;
  } else if(mm == sep && 1 <= dd && dd <= 30 && 1 <= yyyy && yyyy <= 9999) {
    cout << "Y" << endl;
  } else if(mm == oct && 1 <= dd && dd <= 31 && 1 <= yyyy && yyyy <= 9999) {
    cout << "Y" << endl;
  } else if(mm == nov && 1 <= dd && dd <= 30 && 1 <= yyyy && yyyy <= 9999) {
    cout << "Y" << endl;
  } else if(mm == dec && 1 <= dd && dd <= 31 && 1 <= yyyy && yyyy <= 9999) {
    cout << "Y" << endl;
  } else if(mm == feb && 1 <= dd && dd <= 28 && 1 <= yyyy && yyyy <= 9999) {
    cout << "Y" << endl;
  } else if(mm == feb && dd == 29 && ((yyyy % 400) == 0)) {
    cout << "Y" << endl;
  } else if(mm == feb && dd == 29 && ((yyyy % 100) == 0)) {
    cout << "N" << endl;
  } else if(mm == feb && dd == 29 && ((yyyy % 4) == 0)) {
    cout << "Y" << endl;
  } else { cout << "N" << endl;
}
  return 0;
}
