//
//  SelectionSort.cpp
//
//  Sorts integers using the SelectionSort algorithm by looping through the
//  array and picking the smallest element each time and putting it at the 
//  front of the sorted subsection so the unsorted part gets smaller every time
//  until it's done.
//
//  Name: James McCants
//  Date: 5/6/14


#include "SelectionSort.h"

using namespace std;

SelectionSort::SelectionSort(){ // constructor
        sortArray.length = 0;
        sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void SelectionSort::readList(){
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

void SelectionSort::sort(){
        // selection sort on sortArray
        int minIndex; // keeps track of the smallest number's index
        int tmp;
        for (int i = 0; i < (sortArray.length - 1); i++) {
                minIndex = i;
                for (int j = (i + 1); j < sortArray.length; j++) {
                        if (sortArray.arr[j] < sortArray.arr[minIndex]) {
                                minIndex = j;
                        }
                }
                if (minIndex != i) {
                        tmp = sortArray.arr[i];
                        sortArray.arr[i] = sortArray.arr[minIndex];
                        sortArray.arr[minIndex] = tmp;
                }
        }
}

void SelectionSort::printArray(){
        // prints out the integers in sorted order
        for (int i = 0; i < sortArray.length; i++) {
                cout << sortArray.arr[i] << endl;
        }
}


