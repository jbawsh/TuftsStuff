//
//  dayDynamicArray-3
//
//  Created by Chris Gregg on 1/30/14.
//  Edited by Student 3
//

#include "dayDynamicArray.h"
#include <cassert>
#include <string>

const int Day::INIT_CAPACITY;

//constructor for the class, sets private variables to initial
//values and creates the dynamic array for the Day's Events
Day::Day(){
    eventCount = 0;
    eventCapacity = INIT_CAPACITY;
    eventList = new Event[INIT_CAPACITY];
}

// add default event for a full Day
void Day::scheduleEvent() { 
        scheduleEvent(0,2359,"");
}

//schedules Event with given start time, end time and description
//in order of start time
void Day::scheduleEvent(int startTime, int endTime, string description){
    if (eventCount == eventCapacity)
	expandArray();
    
    Event newEvent(startTime,endTime,description);
    
    for (int i = 0; i < eventCount; i++) {
	if (newEvent.amIBefore(eventList[i])) {
	    for (int j = eventCount; j > i; j--) {
		eventList[j] = eventList[j-1];
	    } // moves all Events over to make room for new event
	    eventList[i] = newEvent;
	    eventCount++;
	    return;
	}
    }
    
    eventList[eventCount] = newEvent; //will only occur if startTime is after 
    eventCount++;		      //all other Events in the Day
}

//schedules Event with given parameter Event
void Day::scheduleEvent(Event anEvent){
        scheduleEvent(anEvent.getStartTime(),
		      anEvent.getEndTime(),anEvent.getDescription());
}

//searches for and cancels the Event parameter within the ordered list
void Day::cancelEvent(Event anEvent){
    for (int i = 0; i < eventCount; i++) {
	if (eventList[i].isSameEventAs(anEvent)) {
	    for (int j = i; j < (eventCount-1); j++) {
		eventList[j] = eventList[j+1];
	    }
	    eventCount--;
	    break;
	}    
    }
}

//prints the ordered list of events for the Day 
void Day::printDay(){
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

Day::~Day(){
        delete [] eventList;
}

//expands the dynamic array if capacity is filled
void Day::expandArray() {
    Event *temp = new Event[eventCapacity * 2];
    for (int i = 0; i < eventCount; i++)
	temp[i] = eventList[i]; 
    
    delete [] eventList;
    eventList = temp;
    eventCapacity = eventCapacity * 2;
}
