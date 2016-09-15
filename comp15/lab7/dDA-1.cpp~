//
//  dayDynamicArray-1.cpp
//
//  Edited by student 1
//

#include "dayDynamicArray.h"
#include <cassert>
#include <string>

const int Day::INIT_CAPACITY;

Day::Day(){ // constructor
    eventList = new Event[INIT_CAPACITY];
    eventCount = 0;
    eventCapacity = INIT_CAPACITY;
}

void Day::scheduleEvent() { // add default event for a full Day
    scheduleEvent(0,2359,"");
}

// creates new event, inserts into correct place in the array
// resizes array if necessary using resize fxn
void Day::scheduleEvent(int startTime, int endTime, string description){
    if (eventCount == eventCapacity) {
	resizeList();
    }
    Event newEvent;
    newEvent.setStartTime(startTime);
    newEvent.setEndTime(endTime);
    newEvent.setDescription(description);
    if (eventCount == 0) { 
		eventList[eventCount] = newEvent;
	        eventCount++;
		return;
    }
    //loop through and find where event should go
    for (int i = 0; i < eventCount; i++) {
	if (newEvent.getStartTime() < eventList[i].getStartTime()) {
	    //shift following events over
	    for (int j = eventCount; j > i; j--){
		eventList[j] = eventList[j-1];
	    }
	    eventList[i] = newEvent;	
	    eventCount++;
	    return;
	}
    }
}

// calls other schedule fxn
void Day::scheduleEvent(Event anEvent){
    scheduleEvent(anEvent.getStartTime(),anEvent.getEndTime(),
	anEvent.getDescription());
}

// cancels an event by looping through the array and calling
// isSameEventAs
void Day::cancelEvent(Event anEvent){
    for (int i = 0; i < eventCount; i++){
	if (eventList[i].isSameEventAs(anEvent)){
	    //delete this one
	    for (int j = i; j < eventCount; j++){
		eventList[j] = eventList[j+1];
		return;
	    }
	}
    }
}

// prints day using print day function
void Day::printDay() {
    for (int i = 0; i < eventCount; i++){
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

// resizes list by doubling it once it reaches capacity
void Day::resizeList(){
    eventCapacity = eventCapacity*2;
    Event* newArray = new Event[eventCapacity];
    for (int i = 0; i < eventCount; i++){
	newArray[i] = eventList[i];
    }
    delete eventList;
    eventList = newArray;
}
