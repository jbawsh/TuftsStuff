//
//  event-4.cpp
//
//  Created by Chris Gregg on 1/30/14.
//  Edited by Student 4

#include "event.h"
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;
// initialize event start, end, and description
Event::Event() { // constructor
    startTime = 0; 
    endTime = 2359;
    description = "";
        
}

Event::Event(int startT, int endT, string desc) {
    startTime = startT;
    endTime = endT;
    description = desc; 
}
// getter functions for modularity
int Event::getStartTime() {
    return startTime;
	
}

int Event::getEndTime() {	
    return endTime;
}

std::string Event::getDescription() {
    return description;
}
//setter functions for modularity
void Event::setStartTime(int startT) {
    startTime = startT;
}

void Event::setEndTime(int endT) {
    endTime = endT;
}

void Event::setDescription(string str) {
    description = str;
}
// Purpose: To check if the event being inserted is before event being viewed
bool Event::amIBefore(Event otherEvent) {
    if (startTime < otherEvent.getStartTime())
	return true;
    else
	return false;
}
//Purpose: to check all parts of event to see if events are the same
bool Event::isSameEventAs(Event otherEvent) {
        if (startTime == otherEvent.getStartTime() &&
         endTime == otherEvent.getEndTime() &&
         description == otherEvent.getDescription())
                return true;
        return false;
}
// Purpose: Prints out event with start, end, and description
void Event::printEvent(){
      cout << "Start Time: " << getStartTime() << endl;
      cout << "End Time: " << getEndTime() << endl;
      cout << "Description: " << getDescription() << endl << endl;
      // 2 new lines 
}

string Event::eventCSV() {
        ostringstream startTimeStr,endTimeStr;
        startTimeStr << startTime;
        endTimeStr << endTime;
        
        string EventString = startTimeStr.str()+","+
                                endTimeStr.str()+","+
                                description;
        return EventString;
        
}
