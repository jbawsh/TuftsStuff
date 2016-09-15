//
// This program draws a pattern of increasing integers up to a maximum and then
// the same set decreasing on the other side of a line or "mirror", 4 rows.
// Name: James McCants
// Date: 10/4/13
//

# include <iostream>

using namespace std;

void draw_picture(int max);

int main() {

  int max;

  cout << "Maximum Value? ";
  cin >> max;

  draw_picture(max);

  return 0;
}

void draw_picture(int max) {

  const int rows = 4;
  int countr = 0;
  int countu = 0;
  int countd = max;

  while(countr < rows) {

  while(countu < (max + 1)) {
    cout << countu;
    countu++;
  }
  cout << "|";
  while(countd > (-1)) {
    cout << countd;
    countd--;
  }
  cout << endl;
  countu = 0;
  countd = max;
  countr++;
  }
}