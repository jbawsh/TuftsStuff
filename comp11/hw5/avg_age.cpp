//
// Tells the average age of people with the same name in a class list
// James McCants
// 10/11/13
//

#include <iostream>
using namespace std;

const int    SPACE = 50000;
const int    SENTINELy = -1;
const string SENTINELn = "DONE";

//tells the average age for people with a given name
void average_age(int years[], string names[], string input);

//prints in and out, calls functions
int main() {

  int posy = 0;
  int posn = 0;
  int years[SPACE];
  string names[SPACE];
  int yr;
  string nm;
  string input;

  do {
    cin >> yr;
    years[posy++] = yr;
    cin >> nm;
    names[posn++] = nm;
  } while(posy < SPACE && yr != SENTINELy);

  if(posy >= SPACE) {
    cerr << "too much data" << endl;
    return 1;
  }

  cout << "Enter a name:" << endl;
  cin >> input;

  average_age(years, names, input);

  return 0;
}

//averages the ages of people with the cool name

void average_age(int years[SPACE], string names[SPACE], string input) {

  int pos = 0;
  double counter = 0;
  double avg;
  double sumy = 0;

  while(years[pos] != SENTINELy) {
    if(names[pos] == input) {
      sumy += (2013 - years[pos]);
      counter++;
    }
    pos++;
  }

  if(counter == 0) {
    cout << "name not found" << endl;
  } else {
    avg = sumy/counter;
    cout << "average age = " << avg <<  endl;
  }
}

  
  
