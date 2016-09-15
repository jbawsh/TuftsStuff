//
// ShellSort h file
//
// Name: James McCants
// Date: 5/6/14

#ifndef __Sorting__ShellSort__
#define __Sorting__ShellSort__

#include <iostream>

struct arrayWithLength{
        int length;
        int *arr;
};

class ShellSort {
 public:
        ShellSort(); // constructor

        // read in a list of values from stdin
        void readList();

        // sort function
        void sort();

        // print the array
        void printArray();

 private:
        arrayWithLength sortArray;
};

#endif /* defined(__Sorting__ShellSort__) */
