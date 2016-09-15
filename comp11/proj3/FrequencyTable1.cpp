/*                         FrequencyTable1.cpp

 purpose: provides definitions for all the funtions in a frequecny table class
 that uses a linked list to store words and their frequencies when read in from
 a text file.

 name: James McCants
 date: 12/4/13
 */

#include <iostream>

using namespace std;

#include "FrequencyTable.h"

/*
FrequencyTable:
    purpose: is a constructor for the FrequencyTable class.
    effects: sets the three lists to empty.
 */

FrequencyTable::FrequencyTable()
{
        list = empty();
        temp = empty();
        temp_in = empty();
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
        temp_in = list;

        while (!isEmpty(temp_in) && (first(temp_in).word <= word)) {
                if (first(temp_in).word == word) {
                        return true;
                }
                temp_in = rest(temp_in);
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
        
        temp = list;

        if ((!in(word)) && (isEmpty(list) || (word < first(list).word))) {
                list = prepend(new_data, list);             
        } else if (!in(word)) {
                while (!isEmpty(temp) && 
                       (first(temp).word < word) &&
                       (!isEmpty(rest(temp))) &&
                       (first(rest(temp)).word < word)) {
                        temp = rest(temp);
                }
                insertAfter(new_data, temp);
        } else {
                while (!isEmpty(temp) && (first(temp).word <= word)) {
                        if (first(temp).word == word) {
                                set_freq(temp, (frequency(word) + 1));
                        }
                        temp = rest(temp);
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

        temp = list;

        if (in(word)) {
                while (!isEmpty(temp) && first(temp).word <= word) {
                        if (first(temp).word == word) {
                                frequency = first(temp).freq;
                                break;
                        }
                        temp = rest(temp);
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

        temp = list;

        while (temp != NULL) {
                counter++;
                temp = rest(temp);
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
        temp = list;

        for (int i = 0; i <= n; i++) {
                if (i == n) {
                        *p_word = first(temp).word;
                        *p_frequency = first(temp).freq;
                        return;
                } else {
                        if (isEmpty(temp)) {
                                return;
                        } else {
                                temp = rest(temp);
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
        while (list != NULL) {
                list = deleteFirst(list);
        }

        temp = deleteFirst(temp);
        temp_in = deleteFirst(temp_in);
}

