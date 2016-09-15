//
//  DayLinkedList.cpp
//  CalendarOrderedLists
//
//  Created by Chris Gregg on 1/30/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//
//  Name: James McCants
//  Date: 2/11/14
//

#include "dayLinkedList.h"
#include <cassert>

Day::Day(){ // constructor
        eventList = NULL;  //intiates the head
}

void Day::scheduleEvent() { // add default Event for a full Day
        scheduleEvent(0,2359,"");
}

/*
  scheduleEvent
  Purpose: adds an event to the list in order by comparing start times
  Args:    takes in arguments for a new event
 */

void Day::scheduleEvent(int startTime, int endTime, string description){
        bool didBreak = false;
        eventCount = 0;

        EventNode *newEvent = new EventNode();
        newEvent->theEvent = Event(startTime, endTime, description);

        EventNode *tempEvent = eventList;
        EventNode *tempEventBefore = eventList; //tracks the event before temp

        if (tempEvent == NULL) {
                //if there are no events yet
                eventList = newEvent;
        }
        else {
                while (tempEvent != NULL) {
                        //cycles through events to put in order
                        if (newEvent->theEvent.amIBefore(tempEvent->theEvent)) {
                                didBreak = true;
                                break;
                        } else {
                                if (eventCount > 0) {
                                        tempEventBefore = tempEventBefore->next;
                                }                             
                                tempEvent = tempEvent->next;
                                eventCount++;
                        }
                }
                if (newEvent->theEvent.amIBefore(eventList->theEvent)) {
                        //if it's before the first event
                        newEvent->next = eventList;
                        eventList = newEvent;
                } else if (didBreak) {
                        //if it's in the middle of the list somewhere
                        tempEventBefore->next = newEvent;
                        newEvent->next = tempEvent;
                } else {
                        //if it's after all events in the list
                        tempEventBefore->next = newEvent;
                }
        }
}

void Day::scheduleEvent(Event anEvent){
        scheduleEvent(anEvent.getStartTime(),anEvent.getEndTime(),anEvent.getDescription());
}

/*
  cancelEvent
  Purpose: takes in an event and then finds that event in the list and then
           removes it from the list
  Args:    takes in an event to be removed
 */

void Day::cancelEvent(Event anEvent){
        eventCount = 0;

        EventNode *tempEvent;
        EventNode *tempEventBefore;

        tempEvent = eventList;
        tempEventBefore = eventList; //keeps track of the node before the one
                                     //the one being checked

        if (eventList->theEvent.isSameEventAs(anEvent)) {
                //if it's canceling the first event
                eventList = eventList->next;
        }
        while (tempEvent != NULL) {
                if (tempEvent->theEvent.isSameEventAs(anEvent)) {
                        tempEventBefore->next = tempEvent->next;
                        tempEvent = NULL;
                        break;
                }
                if (eventCount > 0) { //makes sure it stays before temp
                        tempEventBefore = tempEventBefore->next;
                }
                eventCount++;
                tempEvent = tempEvent->next;
        }
}
/*
  printDay
  Purpose: cycles through the list and calls print for each node in the list
 */

void Day::printDay() {
        EventNode *tempEvent;

        tempEvent = eventList;

        while (tempEvent != NULL) {
                tempEvent->theEvent.printEvent();
                tempEvent = tempEvent->next;
        }
}

string Day::exportDay(){
        string csvString = "";
        EventNode *tempEventNode = eventList;
        while (tempEventNode != NULL) {
                csvString+= tempEventNode->theEvent.eventCSV() + "\n";
                tempEventNode = tempEventNode->next;
        }
        return csvString;
}
Day::~Day() {
        while (eventList != NULL) {
                EventNode *tempNextNode = eventList->next;
                delete eventList;
                eventList = tempNextNode;
        }
}
