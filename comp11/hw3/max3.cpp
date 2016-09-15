#include <iostream>

/* 
     max3.cpp -- program to print out the largest of three input values

     usage: ./max3
     input: three doubles 
    output: the largest of the three input values
      note: Do not prompt the user, do not print explanations on output.
            In fact, do not change main() at all, and don't use cin or
            cout in max3().
    
    modified by: James McCants
    modified on: 9/22/13
 */

using namespace std;

double max3(double n1, double n2, double n3);    // tell compiler about this

int main()
{
        double  a, b, c;                // input values
        double  largest;                // result
        
        cin >> a >> b >> c;             // read in three values

        largest = max3(a, b, c);        // compute the largest

        cout << largest << endl;        // display it on the screen

        return 0;
}

//
// max3() return the largest of three values passed as arguments
//
double max3(double n1, double n2, double n3)
{

        // your code here
        // your function MUST use return to send back the
        // largest value of the three values passed in
  
  double lrg;

  if((n1 > n2 && n1 > n3) || (n1 > n3 && n1 == n2) || (n1 > n2 && n1 == n3)) {
    lrg = n1; 
} else if((n2 > n1 && n2 > n3) || (n2 > n1 && n2 == n3) || (n2 > n3 && n2 == n1)) {
    lrg = n2;
} else  if((n3 > n1 && n3 > n2) || (n3 > n1 && n3 == n2) || (n3 > n2 && n3 == n1)) {
    lrg = n3;
} return lrg;
      
}
