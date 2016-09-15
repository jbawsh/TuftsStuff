/***********************************************************************/
/*                          IntList Interface                          */
/***********************************************************************/
/* A minimal implementation of linked lists.                           */
/* Author:  Mark A. Sheldon, Tufts University, Fall 2012               */
/*                                                                     */
/* An IntList is either:                                               */
/*      - An empty list (the empty list)  OR                           */
/*      - A non-empty list node containing:                            */
/*           o an integer-valued head  AND                             */
/*           o an IntList tail                                         */
/*                                                                     */
/* Operations:                                                         */
/* (see prototypes below for parameter/type information)               */
/*      empty()      : returns an empty list                           */
/*      isEmpty()    : returns true if the given list is empty,        */
/*                     and false otherwise                             */
/*      prepend()    : returns a newly allocated list node with the    */
/*                     given data value in the head and the given list */
/*                     in the tail                                     */
/*      head()       : returns the data value in the head of the       */
/*                     given non-empty list node.                      */
/*                     It is an error to call head() on an empty list. */
/*      tail()       : returns the IntList in the tail of the given    */
/*                     non-empty list node.                            */
/*                     It is an error to call tail() on an empty list. */
/*      deleteHead() : returns the IntList in the tail of the given    */
/*                     list.                                           */
/*                     Frees storage associated with a non-empty node. */
/*                     It is an error to call deleteHead() on an       */
/*                     empty list.                                     */
/***********************************************************************/

#ifndef __INTLIST_H__
#define __INTLIST_H__

struct  IntListNode;
typedef IntListNode *IntList;

IntList empty      (void);
bool    isEmpty    (IntList list);
IntList prepend    (int new_data, IntList list);
int     head       (IntList list);
IntList tail       (IntList list);
IntList deleteHead (IntList list);

#endif
