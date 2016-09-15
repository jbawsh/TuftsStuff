/*                         FrequencyTable2.cpp

 purpose: declares all the functions for a FrequencyTable class.

 name: James McCants
 date: 12/4/13
 */

#ifndef __wordfreq__FrequencyTable2__
#define __wordfreq__FrequencyTable2__

#include "WordFreqList.h"

//size of the alphabet
const int LETTERS = 26;

class FrequencyTable
{
 public:
        //Constructor for the class
        FrequencyTable();

        //checks if a word is in the list
        bool in(string word);

        //inserts a new word into the list
        void insert(string word);

        //checks the frequency of a given word
        int frequency(string word);

        //returns the size of the whole list
        int size();

        //passes the data value for the nth node to pointers
        void get(int n, string *p_word, int *p_frequency);

        //deletes the list
        void destroy();

 private:
        //declares these list arrays
        WFList list[LETTERS];
        WFList temp[LETTERS];
        WFList temp_in[LETTERS];
        
        //for use in incrementing the array index
        int ltr;

        //returns a number for the first letter of a word
        int ifw(string word);
};

#endif
