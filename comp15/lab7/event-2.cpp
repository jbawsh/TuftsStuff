//
//  event-2.cpp
//
//  Created by Chris Gregg on 1/30/14.
//  Edited by Student 2
//

#include "event.h"
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

Event::Event() { // default constructor, whole day event
        startTime = 0;
	endTime = 2359;
	description = "";
        
}

Event::Event(int startT, int endT, string desc) {
        // TODO: Student writes this methodd
	startTime = startT;
	endTime = endT;
	description = desc;
}

int Event::getStartTime() {
        // TODO: Student writes this method
        return startTime;
}

int Event::getEndTime() {
        // TODO: Student writes this method
	return endTime;
}

std::string Event::getDescription() {
        // TODO: Student writes this method
        return description;
}

void Event::setStartTime(int startT) {
        // TODO: Student writes this method
        startTime = startT;
}

void Event::setEndTime(int endT) {
        // TODO: Student writes this method
        endTime = endT;
}

void Event::setDescription(string str) {
        // TODO: Student writes this method
        description = str;
}

bool Event::amIBefore(Event otherEvent) {
        // TODO: Student writes this method
        if (startTime < otherEvent.getStartTime())
            return true;
        if (startTime == otherEvent.getStartTime() && endTime < otherEvent.getEndTime())
            return true;
        if (startTime == otherEvent.getStartTime() && endTime == otherEvent.getEndTime() && description < otherEvent.getDescription())
            return true;
        else
	        return false;
}

bool Event::isSameEventAs(Event otherEvent) {
        if (startTime == otherEvent.getStartTime() &&
         endTime == otherEvent.getEndTime() &&
         description == otherEvent.getDescription())
                return true;
        return false;
}

void Event::printEvent(){
        // TODO: Student writes this method
        cout << "Start Time: "<< getStartTime() << endl 
		<< "End Time: "<< getEndTime() << endl
		<< "Description: "<< getDescription() << endl << endl;	
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
