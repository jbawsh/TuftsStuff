//
//  day.cpp
//  CalendarOrderedLists
//
//  Created by Chris Gregg on 1/30/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//
//  Name: James McCants
//  Date: 2/11/14
//

#include "dayDynamicArray.h"
#include <cassert>
#include <string>

const int Day::INIT_CAPACITY;

Day::Day(){ // constructor
        eventList =  new Event[INIT_CAPACITY];
        eventCount = 0;
        eventCapacity = INIT_CAPACITY;
}

void Day::scheduleEvent() { // add default event for a full Day
        scheduleEvent(0,2359,"");
}

/*
  scheduleEvent
  Purpose: expands the array if need be and then enters the event into the last
           spot in the array and then calls a function to check the order
  Args:    takes in arguments for an event
 */

void Day::scheduleEvent(int startTime, int endTime, string description){
        if (eventCount >= eventCapacity) {
                //if the array is full it calls a function to expand it
                expandEvents();
        }
        
        eventList[eventCount].setStartTime(startTime);
        eventList[eventCount].setEndTime(endTime);
        eventList[eventCount].setDescription(description);

        //checks if the array is in order
        checkOrder(eventList[eventCount]);

        eventCount++;
}

void Day::scheduleEvent(Event anEvent){
        scheduleEvent(anEvent.getStartTime(),anEvent.getEndTime(),anEvent.getDescription());
}

/*
  cancelEvent
  Purpose: takes in an event and then removes it from the array and shifts all
           the other ones over
  Args:    takes in an event to remove
 */

void Day::cancelEvent(Event anEvent){

        int index = -2;

        for (int i = 0; i < eventCount; i++) {
                if (eventList[i].isSameEventAs(anEvent)) {
                        index = i; //finds the event and tracks what index
                        break;
                }
        }

        if (index == -2) return; //the event wasn't there

        for (int j = index; j < eventCount - 1; j++) {
                //removes the event by moving everything over one
                eventList[j] = eventList[j + 1];
        }
        eventCount--; //changes the eventCount because one has been deleted
}

/*
  printDay
  Purpose: cycles through the array and calls the print function for each event
 */

void Day::printDay() {
        for (int i = 0; i < eventCount; i++) {
                eventList[i].printEvent();
        }
}

string Day::exportDay(){
        string csvString = "";
        for (int index=0;index < eventCount; index++) {
                csvString+= eventList[index].eventCSV() + "\n";
        }
        return csvString;
}

/*
  expandEvents
  Purpose: doubles the ammount of space in the array and copies all the data
           into the larger array
 */

void Day::expandEvents(){
        Event *temp = new Event[eventCapacity*2]; //temp is twice as big
        
        for (int i = 0; i < eventCount; i++) {
                temp[i] = eventList[i];
        }

        eventList = temp;
        delete [] temp;
        eventCapacity = eventCapacity*2; //updates capacity
}

/*
  checkOrder
  Purpose: checks to put an event in order in the array based on start time
  Args:    takes in an event to be put in order
 */

void Day::checkOrder(Event anEvent){
        int index = -2;

        for (int i = 0; i < eventCount; i++) {
                if (anEvent.amIBefore(eventList[i])) {
                        //checks if it's before any other events in the array
                        index = i;
                        break;
                }
        }

        if (index == -2) return; //if index hasn't changed then it wasn't
                                 //before any other events so it's in the right
                                 //place already

        for (int j = eventCount; j > index; j--) {
                //frees up space at the index of the event it was before
                eventList[j] = eventList[j - 1];
        }

        eventList[index] = anEvent; //fills the newly freed index
}

Day::~Day(){
        delete [] eventList;
}
