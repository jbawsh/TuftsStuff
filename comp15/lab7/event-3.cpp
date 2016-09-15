//
//  event-3.cpp
//
//  Created by Chris Gregg on 1/30/14.
//  Edited by Student 3
//

#include "event.h"
#include <stdlib.h>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

//constants
const int BEG_DAY = 0;
const int END_DAY = 2359;

//default constructor for the class, creates an Event with a start time
//at the beginning of the day and an end time at the end with the empty
//string as the description
Event::Event() {
    startTime = BEG_DAY;
    endTime = END_DAY;
    description = "";
}

//overloaded constructor with parameters for start time, end time and
//description
Event::Event(int startT, int endT, string desc) {
    startTime = startT;
    endTime = endT;
    description = desc;
}

//getter function for the start time
int Event::getStartTime() {
    return startTime;
}

//getter function for the end time
int Event::getEndTime() {
    return endTime;
}

//getter function for the description
std::string Event::getDescription() {
    return description;
}

//setter function for the start time
void Event::setStartTime(int startT) {
    startTime = startT;
}

//setter function for the end time
void Event::setEndTime(int endT) {
    endTime = endT;
}

//setter function for the description
void Event::setDescription(string str) {
    description = str;
}

//bool function returning whether Event is before another event
bool Event::amIBefore(Event otherEvent) {
    return (startTime < otherEvent.getStartTime());
}

//bool function returning whether Event is the same event as another
//event
bool Event::isSameEventAs(Event otherEvent) {
        if (startTime == otherEvent.getStartTime() &&
         endTime == otherEvent.getEndTime() &&
         description == otherEvent.getDescription())
                return true;
        return false;
}

//prints the event in the format:
// Start Time: (startTime)
// End Time: (endTime)
// Description: (description)
void Event::printEvent(){
    cout << "Start Time: " << startTime << endl;
    cout << "End Time: " << endTime << endl;
    cout << "Description: " << description << endl;
    cout << endl;
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
