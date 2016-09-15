//
// This program finds the number of values over the
// average of all the values in an array.
// James McCants
// 10/11/13
//

#include <iostream>
using namespace std;

const int SENTINEL = 0;
const int SPACE = 30000;

//finds the average of the values
double average(int nums[]);

//finds the number of values above the average
int over(int nums[], double avg);

//prints in and out values and calls the other functions
int main() {

  int y;
  int pos = 0;
  double avg;
  int nums[SPACE];

  do {
    cin >> y;
    nums[pos] = y;
    pos++;
  } while(pos < SPACE && y != SENTINEL);

  if(pos >= SPACE) {
    cerr << "too much input" << endl;
    return 1;
  }

  avg = average(nums);
  cout << over(nums, avg) << endl;

  return 0;

}

//finds the average of the values

double average(int nums[SPACE]) {

  int pos = 0;
  double sum = 0;
  double posfinal;

  while (nums[pos] != SENTINEL) {
    sum += nums[pos];
    pos++;
    posfinal = pos;
  }
  return sum/posfinal;
}

//finds the number of values over the average

int over(int nums[SPACE], double avg) {

  int amountover = 0;
  int pos = 0;
  
  while (nums[pos] != SENTINEL) {
    if(nums[pos] > avg) {
      amountover++;
      pos++;
    } else {
      pos++;
    }
  }
  
  return amountover;
}