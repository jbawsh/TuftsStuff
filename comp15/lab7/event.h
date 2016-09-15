//
//  event.h
//  CalendarOrderedLists
//
//  Created by Chris Gregg on 1/30/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#ifndef __CalendarOrderedLists__event__
#define __CalendarOrderedLists__event__

#include <iostream>
using namespace std;

class Event{
public:
	Event(); // constructor
	Event(int startT, int endT, string desc);
	int getStartTime();
	int getEndTime();
	std::string getDescription();
	
	void setStartTime(int startT);
	void setEndTime(int endT);
	void setDescription(string str);
        
	bool amIBefore(Event otherEvent); // returns true if the event is before another event
        bool isSameEventAs(Event otherEvent); // returns true if the event is equal to another event
        
        void printEvent(); // prints the event as follows:
                           // Start Time: 1200
                           // End Time: 1300
                           // Description: Lunch (with two newlines)
                           //
	string eventCSV(); // returns a comma-separated-value string in the form:
                           //     startTime,endTime,description
        

        
private:
	int startTime;
        int endTime;
        string description;
};

#endif /* defined(__CalendarOrderedLists__event__) */
