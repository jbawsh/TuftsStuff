// tests.cpp

#include <iostream>
#include <sstream>
#include "tests.h"
#include "dayDynamicArray.h"

using namespace std;

// Test report
bool testReport(string testName, bool(*testResult)()) {
	cout << "---------------\n";
	cout << "Testing: '" << testName << "'\n\n";
	if (testResult()) {
		cout << "Test '" << testName << "' passed!\n";
		cout << "---------------\n\n";
		return true;
	}
	else {
		cout << "Test '" << testName << "' failed!\n";
		cout << "---------------\n\n";
		return false;
	}
}

// Test 1: Add event onto the end of a Day
bool addEndEvent(){
	Day d;
	Event e1(900,1000,"Breakfast");
	Event e2(1200,1300,"Lunch");
	Event e3(1700,1800,"Dinner");
	
	d.scheduleEvent(e1);
	d.scheduleEvent(e2);
	d.scheduleEvent(e3);
	
	string result = d.exportDay();
	
	string expectedOutput = string("900,1000,Breakfast\n")+
				"1200,1300,Lunch\n"+
				"1700,1800,Dinner\n";
	cout << "Expected-----:\n";
	cout << expectedOutput;
	cout << "-------------\n\n";
	
	cout << "Actual-----:\n";
	cout << result;
	cout << "------------\n\n";
	
	if (expectedOutput == result) return true;
	return false;
}

// Test 2: Expand the Day
bool expandDay(){
	Day d;
	ostringstream s,sExpected;
	// create 70 events to add
	Event e;
	for (int i=0;i<70;i++) {
		int startTime = (i * 20) / 60 * 100 + (i * 20) % 60;
		int endTime = ((i * 20 + 10) / 60)*100 + (i * 20 + 10) % 60;
		e.setStartTime(startTime);
		e.setEndTime(endTime);
		s << i;
		e.setDescription("Event "+s.str());
		s.str("");
		d.scheduleEvent(e);
		sExpected << startTime << "," << endTime << "," << "Event " << i << endl;
	}
	string result = d.exportDay();
	
	string expectedOutput = sExpected.str();
	
	cout << "Expected-----:\n";
	cout << expectedOutput;
	cout << "-------------\n\n";
	
	cout << "Actual-----:\n";
	cout << result;
	cout << "------------\n\n";
	
	if (expectedOutput == result) return true;
	return false;
}

// Test 3: Cancel first event
bool cancelFirst(){
	Day d;
	Event e1(900,1000,"Breakfast");
	Event e2(1200,1300,"Lunch");
	Event e3(1700,1800,"Dinner");
	
	d.scheduleEvent(e1);
	d.scheduleEvent(e2);
	d.scheduleEvent(e3);
	
	d.cancelEvent(e1);
	
	string result = d.exportDay();
	
	string expectedOutput = string("1200,1300,Lunch\n")+
				"1700,1800,Dinner\n";
	cout << "Expected-----:\n";
	cout << expectedOutput;
	cout << "-------------\n\n";
	
	cout << "Actual-----:\n";
	cout << result;
	cout << "------------\n\n";
	
	if (expectedOutput == result) return true;
	return false;
}

// Test 4: Cancel middle event
bool cancelMiddle(){
	Day d;
	Event e1(900,1000,"Breakfast");
	Event e2(1200,1300,"Lunch");
	Event e3(1700,1800,"Dinner");
	
	d.scheduleEvent(e1);
	d.scheduleEvent(e2);
	d.scheduleEvent(e3);
	
	d.cancelEvent(e2);
	
	string result = d.exportDay();
	
	string expectedOutput = string("900,1000,Breakfast\n")+
				"1700,1800,Dinner\n";
	cout << "Expected-----:\n";
	cout << expectedOutput;
	cout << "-------------\n\n";
	
	cout << "Actual-----:\n";
	cout << result;
	cout << "------------\n\n";
	
	if (expectedOutput == result) return true;
	return false;
}

// Test 5: Cancel final event 
bool cancelFinal(){
	Day d;
	Event e1(900,1000,"Breakfast");
	Event e2(1200,1300,"Lunch");
	Event e3(1700,1800,"Dinner");
	
	d.scheduleEvent(e1);
	d.scheduleEvent(e2);
	d.scheduleEvent(e3);
	
	d.cancelEvent(e3);
	
	string result = d.exportDay();
	
	string expectedOutput = string("900,1000,Breakfast\n")+
				"1200,1300,Lunch\n";
	cout << "Expected-----:\n";
	cout << expectedOutput;
	cout << "-------------\n\n";
	
	cout << "Actual-----:\n";
	cout << result;
	cout << "------------\n\n";
	
	if (expectedOutput == result) return true;
	return false;
}

// Test 6: Add events that are the same time
bool addSameTime(){
	Day d;
	Event e1(900,1000,"Breakfast 1");
	Event e2(900,1000,"Breakfast 2");
	
	d.scheduleEvent(e1);
	d.scheduleEvent(e2);
	
	string result = d.exportDay();
	
	string expectedOutput = string("900,1000,Breakfast 1\n")+
				"900,1000,Breakfast 2\n";
	cout << "Expected-----:\n";
	cout << expectedOutput;
	cout << "-------------\n\n";
	
	cout << "Actual-----:\n";
	cout << result;
	cout << "------------\n\n";
	
	if (expectedOutput == result) return true;
	return false;
}

// Test 7: Delete non-existent event
bool cancelNonexistent(){
	Day d;
	Event e1(900,1000,"Breakfast");
	Event e2(1200,1300,"Lunch");
	Event e3(1700,1800,"Dinner");
	
	d.scheduleEvent(e1);
	d.scheduleEvent(e3);
	d.cancelEvent(e2);
	
	string result = d.exportDay();
	
	string expectedOutput = string("900,1000,Breakfast\n")+
				       "1700,1800,Dinner\n";
	cout << "Expected-----:\n";
	cout << expectedOutput;
	cout << "-------------\n\n";
	
	cout << "Actual-----:\n";
	cout << result;
	cout << "------------\n\n";
	
	if (expectedOutput == result) return true;
	return false;
}

// Test 8: Add duplicate event
bool addDuplicate(){
	Day d;
	Event e1(900,1000,"Breakfast");
	
	d.scheduleEvent(e1);
	d.scheduleEvent(e1);
	
	string result = d.exportDay();
	
	string expectedOutput = string("900,1000,Breakfast\n")+
				"900,1000,Breakfast\n";
	cout << "Expected-----:\n";
	cout << expectedOutput;
	cout << "-------------\n\n";
	
	cout << "Actual-----:\n";
	cout << result;
	cout << "------------\n\n";
	
	if (expectedOutput == result) return true;

	return false;
}

// Test 9: Cancel event when no events are in list
bool cancelWhenNoEvents(){
	Day d;
	Event e1(900,1000,"Breakfast");
	
	d.cancelEvent(e1);
	
	string result = d.exportDay();
	
	string expectedOutput = string("");
	cout << "Expected-----:\n";
	cout << expectedOutput;
	cout << "-------------\n\n";
	
	cout << "Actual-----:\n";
	cout << result;
	cout << "------------\n\n";
	
	if (expectedOutput == result) return true;

	return false;
}