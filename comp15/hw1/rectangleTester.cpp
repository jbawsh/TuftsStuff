// FILE: rectangleTester.cpp
//
// Purpose: to implement a rectangle class and tell the user about the
//          rectangles
//
// Name: James McCants
// Date: 1/20/14

#include <iostream>

using namespace std;

#include "rectangle.h"

//helper function
void checkSquare(rectangle r);

// main
//    purpose: create a rectangle and read in data for another one then tells   //             the user about the created rectangles

int main()
{
        float w, h;

        rectangle r1;

        cin >> w >> h;

        rectangle r2 = rectangle(w, h);

        cout << "r1 has area " << r1.area();
        cout << " perimeter " << r1.perimeter();
        checkSquare(r1);

        cout << "r2 has area " << r2.area();
        cout << " perimeter " << r2.perimeter();
        checkSquare(r2);

        return 0;
}

// checkSquare
//    purpose: checks if the rectangle it reads in is a square or not and
//             outputs it to the user

void checkSquare(rectangle r)
{
        if (r.isSquare()) {
                cout << " and is a square" << endl;
        } else {
                cout << " and is not a square" << endl;
        }
}
