//
//  dLL-6.cpp
//
//  Created by Chris Gregg on 1/30/14.
//  Edited by Student 6
//

#include "dayLinkedList.h"
#include <cassert>

Day::Day(){ // constructor
  eventList = NULL;
  eventCount = 0;
}

void Day::scheduleEvent() { // add default Event for a full Day
        scheduleEvent(0,2359,"");
}
void Day::scheduleEvent(int startTime, int endTime, string description){
  //creates new event node
  EventNode *newEvent = new EventNode;
  newEvent->theEvent = Event(startTime,endTime,description);
  newEvent->next = NULL;
  //if eventList is empty, points eventList to new event node
  if (eventList == NULL) {
    eventList = newEvent;
  }
  //else, finds proper place to add new event so list is still in order
  else {
    //checks if newEvent takes place before any other event
    if (newEvent->theEvent.amIBefore(eventList->theEvent)) {
      newEvent->next = eventList;
      eventList = newEvent;
      return;
    }
    //scans for correct placement of new event and places
    EventNode *event;
    for (event = eventList; event->next != NULL; event = event->next) {
      if (newEvent->theEvent.amIBefore(event->next->theEvent)) {
	newEvent->next = event->next;
	event->next = newEvent;
	return;
      }
    }
    //the newEvent is the tail of the list
    event->next = newEvent;
  }
}

void Day::scheduleEvent(Event anEvent){
  scheduleEvent(anEvent.getStartTime(),anEvent.getEndTime(),anEvent.getDescription());
}

void Day::cancelEvent(Event anEvent){
  //checks if event is the head event
  if (anEvent.isSameEventAs(eventList->theEvent)) {
    EventNode *temp = eventList->next;
    delete eventList;
    eventList = temp;
    return;
  }
  //scans rest of list for event
  for (EventNode *event = eventList; event->next != NULL; event = event->next) {
    if (anEvent.isSameEventAs(event->next->theEvent)) {
      EventNode *temp = event->next->next;
      delete event->next;
      event->next = temp;
      return;
    }
  }
}

void Day::printDay() {
  for (EventNode *event = eventList; event != NULL; event = event->next) {
    event->theEvent.printEvent();
    cout << endl;
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
