/*                               wordfreq

 purpose: to read in a text file and keep track of every word in the file and
 then print out the frequency of how often a word appears and then the word
 itself creating a list that is in alphabetical order.

 name: James McCants
 date: 12/4/13
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

#include "FrequencyTable.h"

//Untility functions for main

FrequencyTable input(FrequencyTable list);
void output(FrequencyTable list);

/*
main:
    purpose: creates a new list and then calls input to fill it and then output
             to print it out and then destroy to empty the list.
    returns: 0 if it works.
    effects: does not actually act on the list at all.
 */

int main()
{
        FrequencyTable list;

        list = input(list);

        output(list);

        list.destroy();

        return 0;
}

/*
input:
    purpose: fills in a list with words that it reads in from a file.
    args:    takes in a FrequencyTable class to fill up.
    returns: a FrequencyTable class that is now full of new words.
    effects: reads in words and passes them to the list.
 */

FrequencyTable input(FrequencyTable list)
{
        int len;
        string word;
        
        while (cin >> word) {
                if (((word[0] >= 'a') &&
                     (word[0] <= 'z')) ||
                    ((word[0] >= 'A') &&
                     (word[0] <= 'Z'))) {
                        len = word.length();
                        for (int i = 0; i < len; i++) {
                                word[i] = tolower(word[i]);
                        }
                        list.insert(word);
                }
        }
        return list;
}

/*
output:
    purpose: retrieves and prints out all the data stored in a list.
    args:    a FrequencyTable class.
    returns: void.
    effects: goes through the list it is passed and prints out all of the
             word/frequency pairs stored inside.
 */

void output(FrequencyTable list)
{
        string *p_word;
        int *p_freq;
        p_word = new string;
        p_freq = new int;
        *p_freq = 10;
        *p_word = "mom";
        int size = 0;

        size = list.size();

        for (int i = 0; i < size; i++) {
                list.get(i, p_word, p_freq);
                cout << *p_freq << " " << *p_word << endl;
        }
        
        p_freq = NULL;
        delete p_freq;
        p_word = NULL;
        delete p_word;
}
       
