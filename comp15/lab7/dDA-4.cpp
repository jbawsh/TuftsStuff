//
//  dayDynamicArray - 4.cpp
//
//  Created by Chris Gregg on 1/30/14.
//  Edited by Student 4

#include "dayDynamicArray.h"
#include <cassert>
#include <string>

const int Day::INIT_CAPACITY;
//creates dynamic arry
Day::Day(){ // constructor
        eventList = new Event[INIT_CAPACITY];
        eventCount = 0;
        eventCapacity = INIT_CAPACITY;
}

void Day::scheduleEvent() { // add default event for a full Day
        scheduleEvent(0,2359,"");
}
// Purpose: schdedules event in day and places event in order 
//    based on start time. Places events with same start time after 
//    events already in list
void Day::scheduleEvent(int startTime, int endTime, string description){
        Event temp; 
        temp.setStartTime(startTime);
	temp.setEndTime(endTime); 
	temp.setDescription(description);
	//checks to see if there is enough capacity, and if there isn't 
	//it expands the array
	if(eventCount >= eventCapacity){
	    Event *tempList = new Event[eventCapacity*2];
	    for(int i = 0; i < eventCapacity; i++){
		tempList[i] = eventList[i];
	    }
	    delete[] eventList;
	    eventList = tempList; 
	    eventCapacity = eventCapacity*2;
	}
	//if there is no event in array, place one in the first position
	if(eventCount == 0){
	    eventList[0] = temp;
	}else{
	    for (int i = 0; i < eventCapacity; i++){
	    //Checks if amIBefore is true
		if(temp.amIBefore(eventList[i])){
		// Moves later events over to put earlier event in list
		    for(int begin = eventCapacity-2; begin >= i; begin--){
			eventList[begin+1] = eventList[begin];
		    }
		    eventList[i] = temp;
		    break;
		} //checks to see if events are at the same time, puts sencond 
		  // entered event after first entered list
		if(temp.getStartTime() == eventList[i].getStartTime()){
		    for(int begin = eventCapacity-2; begin > i; begin--){
			eventList[begin+1] = eventList[begin];
		    }
		    eventList[i] = temp;
		    break;
		}
		// checks to see if description is empty and
		//places event in index
		if (eventList[i].getDescription() == ""){
		    eventList[i] = temp;
		    break;
		}
	    }
	}
	eventCount++;
}

void Day::scheduleEvent(Event anEvent){
        scheduleEvent(anEvent.getStartTime(),anEvent.getEndTime(),anEvent.getDescription());
}
//Purpose: To delete events in array, and reset events
void Day::cancelEvent(Event anEvent){
        for (int i = 0; i < eventCount; i++){
	    if(eventList[i].isSameEventAs(anEvent)){
		for(int j = i; j < eventCapacity; j++){
		eventList[j] = eventList[j+1];
		}
		//reset event
		eventList[eventCount-1].setStartTime(0);
		eventList[eventCount-1].setEndTime(2359);
		eventList[eventCount-1].setDescription("");
	    }
	}
}
// Purpose: Prints out day with events sorted, appearing in array order
void Day::printDay() {
       for(int i = 0; i < eventCount; i++){
	   if(eventList[i].getDescription() != ""){
	       eventList[i].printEvent();
	   }
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
