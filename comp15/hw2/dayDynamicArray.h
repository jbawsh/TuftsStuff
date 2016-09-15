//
//  day.h
//  CalendarOrderedLists
//
//  Created by Chris Gregg on 1/30/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//
//  Name: James
//  Date: 2/11/14
//

#ifndef __CalendarOrderedLists__day__
#define __CalendarOrderedLists__day__

#include <iostream>
#include "event.h"

class Day {
public:
        static const int INIT_CAPACITY = 5;
        
	Day(); // constructor
        void scheduleEvent(); // default event for full day
        void scheduleEvent(int startTime, int endTime, string description);
        void scheduleEvent(Event anEvent);
        void cancelEvent(Event anEvent);
        void printDay();
        string exportDay();
        
        ~Day(); // destructor
private:
	Event *eventList;
        int eventCount;
        int eventCapacity;
        void expandEvents(); //expands the size of the array
        void checkOrder(Event anEvent); //checks an Event to put it in order

};

#endif /* defined(__CalendarOrderedLists__day__) */
