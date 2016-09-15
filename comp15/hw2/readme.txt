Name: James McCants
Date: 2/11/14

Comp15 - Hw2

       The purpose of the program is to create a planner that stores events that
have a start time and a finish time within a day (0 - 2359). The planner stores
the events in order using and can delete events. The program can use either a
linked list or a dynamic array to accomplish this task.

 - main.cpp
        
        Stores events in the day and deltes them, runs the program

 - event.h        
 - event.cpp

        Contains helper functions for events: a print function and comparison
functions to check the order and similarity of events.

 - dayLinkedList.h
 - dayLinkedList.cpp

        Contains functions to add events to the list and delete events, also to
put the events in order.

 - dayDynamicArray.h
 - dayDynamicArray.cpp

        Contains functions to add events to the array and delete events, also
to put the events in order and expand the array if necessary.

        The Data Structures used were a dynamic array and a linked list, the
dynamic array stored events in the array with a lower index as an earlier event.
The linked list stored each event as a node in the list with the head of the 
list being the earliest event.

        The algorithm used to store the events in order was to compare their
start times using the event class helper functions while cycling through the 
respective data structures to find where a given event fit in.
