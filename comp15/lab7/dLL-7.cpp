//
//  DayLinkedList.cpp - 7
//
//  Created by Chris Gregg on 1/30/14.
//  Edited By Student 7
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
            
    EventNode *newNode = new EventNode;
    
    //call Event constructor
    newNode->theEvent = Event(startTime, endTime, description);
    
    //check if list is empty
    if (eventList == NULL) {
      eventList = newNode;
      newNode -> next = NULL;
    }
    
    //insert if it's before the first thing in the list
    
    else if (newNode -> theEvent.amIBefore(eventList->theEvent) == true) {
      newNode -> next = eventList;
      eventList = newNode;
    }
    
    // insert correctly in to sorted list
    else {

    EventNode *iterator = eventList;
  
    iterator = eventList;
    
      while (iterator != NULL) {
        
        //insert at end if not before anything else 
        if (iterator -> next == NULL) {
          iterator -> next = newNode;
          newNode -> next = NULL;
          
          break;
        }
        
        //insert in middle at correct place
        if (newNode -> theEvent.amIBefore(iterator->next->theEvent) == true) {
          newNode -> next = iterator -> next;
          iterator -> next = newNode;
          
          break;
        }
        
          iterator = iterator -> next;
                                   
      }
     
    }
        
}

void Day::scheduleEvent(Event anEvent){
        scheduleEvent(anEvent.getStartTime(),anEvent.getEndTime(),anEvent.getDescription());
}

void Day::cancelEvent(Event anEvent){
   
   
    EventNode *iterator = eventList;
    EventNode *iterbehind = eventList;
    
    iterbehind -> next =  iterator;

    
    while (iterator != NULL) {
     if ((iterator -> theEvent).isSameEventAs(anEvent)) { 
        iterbehind -> next = iterator -> next;
        
        delete iterator;
      }
      
      iterator = iterator -> next;
      iterbehind = iterbehind -> next;
    }
  
  
}

void Day::printDay() {
        EventNode *iterator = new EventNode;
        
        iterator = eventList;
        
        while (iterator != NULL) {
          
          (iterator->theEvent).printEvent();
          
          iterator = iterator -> next;
          
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
