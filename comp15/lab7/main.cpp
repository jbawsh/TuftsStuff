// Day and Event Tester

#include<iostream>
#include "dayDynamicArray.h"
#include "event.h"
#include "tests.h"

int main(){
	bool allPassed = true; // be optimistic!
	
	cout << "Beginning Tests...\n\n";
	
	// Test 1: Add event onto the end of a Day
	allPassed = testReport("Add event onto the end of a Day",
			  &addEndEvent) && allPassed;
			  
	// Test 2: Expand the Day
	allPassed = testReport("Expand the Day",
			  &expandDay) && allPassed;
	
	// Test 3: Cancel first event
	allPassed = testReport("Cancel first event",
			  &cancelFirst) && allPassed;
			  
	// Test 4: Cancel middle event
	allPassed = testReport("Cancel middle event",
			  &cancelMiddle) && allPassed;
			  
	// Test 5: Cancel final event 
	allPassed = testReport("Cancel final event",
			  &cancelFinal) && allPassed;
			  
	// Test 6: Add events that are the same time
	allPassed = testReport("Add same time events",
			  &addSameTime) && allPassed;
			  
	// Test 7: Cancel non-existent event
	allPassed = testReport("Cancel non-existent event",
			  &cancelNonexistent) && allPassed;
			  
	// Test 8: Add duplicate event
	allPassed = testReport("Add duplicate event",
			  &addDuplicate) && allPassed;
	
	// Test 9: Cancel when there are no events in the list
	allPassed = testReport("Cancel with no events in the list",
			  &cancelWhenNoEvents) && allPassed;
			  
	cout << "Tests Complete.\n\n";
	if (allPassed) {
		cout << "All tests passed!\n";
	}
	else {
		cout << "Some tests failed!\n";
	}
}
