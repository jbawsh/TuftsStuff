// rev2.cpp
// Read in words, reverse, print
//  Shows: dynamically allocated variable size array

#include <iostream>
#include "vector2.h"
using namespace std;

void readin_data(Vector *data);
void rev_list   (Vector *data);
void print_list (Vector *data);

int main()
{
        Vector data;

        readin_data(&data);
        rev_list(&data);
        print_list(&data);

        return 0;
}


// -- read in a list of integers ---
//   args: data
//   rets: nothing
//   errs: quits on too many words

void readin_data(Vector *data)
{
        bool finished = false;
        int n;

        while (!finished) {
                if (cin.eof()) {
                        finished = true;
                } else {
                        cin >> n;
                        data->add(n);
                }
        }
}


// -- reverse an array ---
//  args: Vector of int
//  rets: nothing
//  mods: reverses array

void rev_list(Vector *data)
{
        int number_i, number_j;
        for (int i = 0, j = data->getSize() - 1; i < j; i++, j--) {
                number_i = data->get(i);
                number_j = data->get(j);
                data->add(number_i, j);
                data->add(number_j, i);
        }
}

// -- print out a list of strings
//  args: Vector of int
//  rets: nothing
//  mods: modifies cout, not data

void print_list(Vector *data)
{
        for (int i = 0; i < data->getSize(); i++) {
                cout << data->get(i) << endl;
        }
}
