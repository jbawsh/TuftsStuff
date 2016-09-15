// tests.h

#ifndef __CalendarTests__event__
#define __CalendarTests__event__

#include <iostream>
using namespace std;

// Test report
bool testReport(string testName, bool(*testResult)());

// Test 1: Add event onto the end of a Day
bool addEndEvent();

// Test 2: Expand the Day
bool expandDay();

// Test 3: Cancel first event
bool cancelFirst();

// Test 4: Cancel middle event
bool cancelMiddle();

// Test 5: Cancel final event 
bool cancelFinal();

// Test 6: Add events that are the same time
bool addSameTime();

// Test 7: Delete non-existent event
bool cancelNonexistent();

// Test 8: Add duplicate event
bool addDuplicate();

// Test 9: Cancel when there are no events in the list
bool cancelWhenNoEvents();

#endif
