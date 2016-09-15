//
//  dayDynamicArray - 2
//
//  Edited by Student 2
//

#include "dayDynamicArray.h"
#include <cassert>
#include "event.h"
#include <string>


const int Day::INIT_CAPACITY;

Day::Day(){ // constructor
        // TODO: Student writes this method
        eventList = new Event[INIT_CAPACITY];
	eventCapacity = INIT_CAPACITY;
	eventCount = 0;

}

void Day::scheduleEvent() { // add default event for a full Day
        scheduleEvent(0,2359,"");
}
void Day::scheduleEvent(int startTime, int endTime, string description){
        // TODO: Student writes this method
        Event *newEvent = new Event;
	newEvent->setStartTime(startTime);
	newEvent->setEndTime(endTime);
	newEvent->setDescription(description);
	// case 1: startTime < all Events. I will insert at the beginning and
	// then push all the rest of the events
	if (eventCount == eventCapacity) {
                    eventCapacity = eventCapacity*2;
                    Event* newArray = new Event[eventCapacity];
                    for (int i = 0; i < eventCount; i++){
                            newArray[i] = eventList[i];
                    }
                    delete [] eventList;
                    eventList = newArray;
        }
 
    if (newEvent->amIBefore(eventList[0])) {
		for (int i=eventCount; i>0; i--){
                eventList[i] = eventList[i-1];
		}
        eventList[0] = *newEvent;
        eventCount ++;
		}


	// case 2: startTime > startTime of 1st event
	for (int i=0; i < eventCount; i++) {
	// startTime is between 2 events
		if (eventList[i].amIBefore(*newEvent)) {
		       continue;}
		       // now i'm at the right position
		       // now i insert
		       for (int j=eventCount; j>i; j--){
                eventList[j] = eventList[j-1];
		       }
		       // now I already shifted all the elemnts from the right position
			eventList[i] = *newEvent;
    
			eventCount ++;
            break;
    }                    // now i push every Event after that by 1 position

			
		
	// case 3
	// startTime is later than the last event
	// i insert it at the last.
    if (startTime >= eventList[eventCount-1].getStartTime()) {
			eventList[eventCount] = *newEvent;
			eventCount ++;
		}
}

void Day::scheduleEvent(Event anEvent){
        scheduleEvent(anEvent.getStartTime(),anEvent.getEndTime(),anEvent.getDescription());
}

void Day::cancelEvent(Event anEvent){
    // delete an event from the given eventList.
    for (int i=0; i < eventCount; i++) {
        if (eventList[i].isSameEventAs(anEvent)){
                for (int j = i; j < eventCount; j++) {
                        eventList[j] = eventList[j+1];
                }
                eventCount --;
                return;
        } 
        // TODO: Student writes this method
    }
}

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

Day::~Day(){
        delete [] eventList;
}
