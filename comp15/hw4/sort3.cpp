//
//  ShellSort.cpp
//
//  Sorts integers using the ShellSort algorithm by using the idea of gaps to
//  compare integers between ever decreasing gaps to make the array less
//  jumbled so that as the gaps get smaller and it becomes more and more like a
//  straight up insertion sort there is less rearranging that needs to be done.
//
//  Name: James McCants
//  Date: 5/6/14


#include "sort3.h"

using namespace std;

ShellSort::ShellSort(){ // constructor
        sortArray.length = 0;
        sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void ShellSort::readList(){
        int currentCapacity = 10;
        sortArray.arr = new int[currentCapacity];
        
        while (cin >> sortArray.arr[sortArray.length]) {
                ++sortArray.length;
                if (sortArray.length==currentCapacity) {
                        int *temp = new int[currentCapacity*2];
                        for (int i=0;i<currentCapacity;i++) {
                                temp[i] = sortArray.arr[i];
                        }
                        delete [] sortArray.arr;
                        sortArray.arr = temp;
                        currentCapacity *= 2;
                }
        }
}

void ShellSort::sort(){
        // shell sort on sortArray
        int tmp, icrmt, i, j;

        for (icrmt = sortArray.length/2; icrmt > 0; icrmt /= 2) {
                for (i = icrmt; i < sortArray.length; i++) {
                        tmp = sortArray.arr[i];
                        for (j = i; j >= icrmt; j -= icrmt) {
                                if (tmp < sortArray.arr[j - icrmt]) {
                                        sortArray.arr[j] =
                                                sortArray.arr[j-icrmt];
                                } else {
                                        break;
                                }
                        }
                        sortArray.arr[j] = tmp;
                }
        }
}

void ShellSort::printArray(){
        // prints out the integers in sorted order
        for (int i = 0; i < sortArray.length; i++) {
                cout << sortArray.arr[i] << endl;
        }
}
