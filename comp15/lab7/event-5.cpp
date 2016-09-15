//
//  event-5.cpp
//
//  Created by Chris Gregg on 1/30/14.
//  Edited by Student 5
//

#include "event.h"
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

Event::Event() { // constructor   //start time to 0 endtime to 2359 description to ""
       setStartTime(0);
	   setEndTime(2359);
	   setDescription("");
        
}

Event::Event(int startT, int endT, string desc) {
        setStartTime(startT);
		setEndTime(endT);
		setDescription(desc);
}

int Event::getStartTime() {
        return startTime;
}
int Event::getEndTime() {
        return endTime;
}

std::string Event::getDescription() {
        return description;
}

void Event::setStartTime(int startT) {
       startTime = startT;
}

void Event::setEndTime(int endT) {
        endTime = endT;
}

void Event::setDescription(string str) {
        description = str;
}

bool Event::amIBefore(Event otherEvent) {
        if (startTime < otherEvent.startTime){
			return true;
		} else return false;
}

bool Event::isSameEventAs(Event otherEvent) {
        if (startTime == otherEvent.getStartTime() &&
         endTime == otherEvent.getEndTime() &&
         description == otherEvent.getDescription())
                return true;
        return false;
}

void Event::printEvent(){
        cout << "Start Time: " << getStartTime() << endl;
		cout << "End Time: " << getEndTime() << endl;
		cout << "Description: " << getDescription() << endl << endl;
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
