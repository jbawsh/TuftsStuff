/*                            WordFreqList.cpp
 
 purpose: defines all the functions declared in WordFreqList.h for use with a
          list.
 
 name: James McCants
 date: 12/4/13
 */

#include <iostream>

using namespace std;

#include "WordFreqList.h"

//defines a WFList
struct WFListNode {
        WordFreq    data;
        WFListNode *next;
};

/*
empty:
    purpose: creates an empty list.
    returns: a list.
    effects: creates a node that points to nothing.
 */

WFList empty()
{
        return NULL;
}

/*
isEmpty:
    purpose: checks if a given node is empty.
    args:    takes in a node.
    returns: a boolean, true if it's empty, esle false
    effects: does not change the node.
 */

bool isEmpty(WFList list)
{
        return list == NULL;
}

/*
prepend:
    purpose: puts a new node in front of a given one (even if the given is
             empty).
    args:    struct of data for the new node, the given node.
    returns: a new list with the added node.
    effects: adds a new node to the beginning of the given list.
 */

WFList prepend(WordFreq new_data, WFList list)
{
        WFListNode *p_node = new WFListNode;

        p_node->data.freq = new_data.freq;
        p_node->data.word = new_data.word;

        if (list == NULL) {
                p_node->next = NULL;
        } else {
                p_node->next = list;
        }

        return p_node;
}

/*
first:
    purpose: to return the data of a node.
    args:    takes in a list node.
    returns: a data struct.
    effects: does not change the list.
 */

WordFreq first(WFList list)
{
        return list->data;
}

/*
rest:
    purpose: returns the next node in the list.
    args:    takes in a node.
    returns: the next node in the list.
    effects: does not change the list.
 */

WFList rest(WFList list)
{
        return list->next;
}

/*
deleteFirst:
    purpose: to delet the first node in a given list.
    args:    takes in a node.
    returns: the rest of the list.
    effects: deletes the first element of the list.
 */

WFList deleteFirst(WFList list)
{
        WFList remainder = rest(list);
        list->next       = NULL;
        delete list;
        return remainder;
}

/*
insertAfter:
    purpose: inserts a new node behind a given node and placing the rest of the              given node after the new one.
    args:    takes in a node and a struct of data to put in the new one.
    returns: void.
    effects: calls prepend.
 */

void insertAfter (WordFreq new_data, WFList list)
{
        list->next = prepend(new_data, rest(list));
}

/*
set_freq:
    purpose: updates the frequency data value for a given list node.
    args:    a list and a value to update.
    returns: void.
    effects: changes the frequency value for a given node.
 */

void set_freq (WFList list, int update)
{       
        list->data.freq = update;
        return;
}
