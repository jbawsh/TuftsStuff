/*                         FrequencyTable1.cpp

 purpose: declares all the functions for a FrequencyTable class.

 name: James McCants
 date: 12/4/13
 */

#ifndef __wordfreq__FrequencyTable1__
#define __wordfreq__FrequencyTable1__

#include "WordFreqList.h"

class FrequencyTable
{
 public:
        //constructor for the class
        FrequencyTable();

        //checks if a word is in the list
        bool in(string word);

        //inserts a new word into the list
        void insert(string word);

        //checks the frequency of a given word
        int frequency(string word);

        //returns the size of the whole list
        int size();

        //passes in the data value for the nth node to pointers
        void get(int n, string *p_word, int *p_frequency);

        //deletes the list
        void destroy();

 private:
        //declares these lists
        WFList list;
        WFList temp;
        WFList temp_in;
};

#endif 
