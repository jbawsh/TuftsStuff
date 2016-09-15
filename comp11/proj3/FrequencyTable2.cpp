/*                         FrequencyTable2.cpp

 purpose: provides definitions for all the funtions in a frequecny table class
 that uses an array of linked lists to store words and their frequencies when
 read in from a text file.

 name: James McCants
 date: 12/4/13
 */

#include <iostream>

using namespace std;

#include "FrequencyTable.h"

/*
FrequencyTable:
    purpose: is a constructor for the FrequencyTable class.
    effects: sets the three lists to empty for every index of the array.
 */

FrequencyTable::FrequencyTable()
{
        for (int i = 0; i < LETTERS; i++) {
                list[i] = empty();
                temp[i] = empty();
                temp_in[i] = empty();
        }

        ltr = 0;
}

/*
in:
    purpose: checks if a given word is already in the table somewhere.
    args:    a word to check.
    returns: a boolean ture if the word is in the table, else false
    effects: does not change the list, just runs through it
 */

bool FrequencyTable::in(string word)
{
        ltr = ifw(word);

        temp_in[ltr] = list[ltr];

        while (!isEmpty(temp_in[ltr]) &&
               (first(temp_in[ltr]).word <= word)) {
                if (first(temp_in[ltr]).word == word) {
                        return true;
                }
                temp_in[ltr] = rest(temp_in[ltr]);
        }
        return false;
}

/*
insert:
    purpose: inserts a given word in to the list in alphabetical order or
             updates the frequency of the word if there is already an occurence
             of it in the list.
    args:    a word to insert.
    returns: void
    effects: uses several conditionals to decide where the word should go in
             the list or if it is already there. Then calls prepend,
             insertAfter, or set_freq to update the list with the new
             information.
 */

void FrequencyTable::insert(string word)
{
        WordFreq new_data;

        new_data.freq = 1;
        new_data.word = word;

        ltr = ifw(word);

        temp[ltr] = list[ltr];

        if ((!in(word)) && 
            (isEmpty(list[ltr]) || (word < first(list[ltr]).word))) {
                list[ltr] = prepend(new_data, list[ltr]);
        } else if (!in(word)) {
                while (!isEmpty(temp[ltr]) &&
                       (first(temp[ltr]).word < word) &&
                       (!isEmpty(rest(temp[ltr]))) &&
                       (first(rest(temp[ltr])).word < word)) {
                        temp[ltr] = rest(temp[ltr]);
                }
                insertAfter(new_data, temp[ltr]);
        } else {
                while (!isEmpty(temp[ltr]) &&
                       (first(temp[ltr]).word <= word)) {
                        if (first(temp[ltr]).word == word) {
                                set_freq(temp[ltr], (frequency(word) + 1));
                        }
                        temp[ltr] = rest(temp[ltr]);
                }
        }
        return;
}

/*
frequency:
    purpose: goes through the list and returns the frequency of a given word.
    args:    takes in a word.
    returns: the value of the frequency for the given word.
    effects: does not alter the list.
 */

int FrequencyTable::frequency(string word)
{
        int frequency = 0;

        ltr = ifw(word);

        temp[ltr] = list[ltr];

        if (in(word)) {
                while (!isEmpty(temp[ltr]) && first(temp[ltr]).word <= word) {
                        if (first(temp[ltr]).word == word) {
                                frequency = first(temp[ltr]).freq;
                                break;
                        }
                        temp[ltr] = rest(temp[ltr]);
                }
        }
        return frequency;
}

/*
size:
    purpose: finds the size of the entire list.
    returns: the size of the list.
    effects: does not alter the list, goes through the list until null and
             counts all the non-null nodes.
 */

int FrequencyTable::size()
{
        int counter = 0;
        
        ltr = 0;

        for (ltr = 0; ltr < LETTERS; ltr++) {
                temp[ltr] = list[ltr];
                while (temp[ltr] != NULL) {
                        counter++;
                        temp[ltr] = rest(temp[ltr]);
                }
        }

        return counter;
}

/*
get:
    purpose: points pointers towards the data values for the nth term in the
             list allowing the data to be used in another file.
    args:    the number of the term of the list you want data from, the
             pointers you want to set their value equal to the data in the node.
    returns: void, changes the value of pointers though.
    effects: does not effect the list.
 */

void FrequencyTable::get(int n, string *p_word, int *p_frequency)
{
        int list_pos = 0;

        ltr = 0;
        
        for (ltr = 0; ltr < LETTERS; ltr++) {
                temp[ltr] = list[ltr];
                while (temp[ltr] != NULL) {
                        if (list_pos == n) {
                                *p_word = first(temp[ltr]).word;
                                *p_frequency = first(temp[ltr]).freq;
                                return;
                        } else {
                                temp[ltr] = rest(temp[ltr]);
                                list_pos++;
                        }
                }
        }
}

/*
destroy:
    purpose: goes through and deletes all the nodes in the list.
    returns: void.
    effects: destroys the list.
 */

void FrequencyTable::destroy()
{
        for (int i = 0; i < LETTERS; i++) {
                     while (list[i] != NULL) {
                             list[i] = deleteFirst(list[i]);
                             temp[i] = list[i];
                             temp_in[i] = list[i];
                     }
        }               
}                                        

/*
ifw (int_for_word):
    purpose: checks the first letter of a given word to find its position in
             the alphabet so it knows which value of the array of list the word
             needs to go in.
    args:    takes in a word.
    returns: returns the array index for words starting with that letter.
    effects: does not alter the list.
 */

int FrequencyTable::ifw(string word)
{
        int ltr_count = 0;
        char letter = 'a';

        while(ltr_count < LETTERS) {
                if (word[0] == letter) {
                        return ltr_count;
                } else {
                        ltr_count++;
                        letter++;
                }
        }

        return ltr_count;
}
                
        

        
        
