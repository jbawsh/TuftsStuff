/*                            WordFreqList.h

 purpose: declares all the fucntions for use on the list and sets up the struct
 for data and the WFList nodes.                                

 name: James McCants
 date: 12/4/13
 */

#ifndef __WordFreqList_H__
#define __WordFreqList_H__

//the struct of data for a node
struct WordFreq
{
        int freq;
        std::string word;
};

//declares the type for a node struct
struct WFListNode;
typedef WFListNode *WFList;

//creates an empty list
WFList   empty       (void);

//checks if a list is empty
bool     isEmpty     (WFList list);

//adds a new node to the front of the list
WFList   prepend     (WordFreq data, WFList list);

//returns the struct of data for a given list node
WordFreq first       (WFList list);

//returns the next node in the list after the given node
WFList   rest        (WFList list);

//deletes the first node of the list and returns the rest
WFList   deleteFirst (WFList list);

//inserts a node after the given node and points to what was after the given
//node in the list
void     insertAfter (WordFreq data, WFList list);

//changes the frequency of a given node to the passed update value
void     set_freq    (WFList list, int update);

#endif
