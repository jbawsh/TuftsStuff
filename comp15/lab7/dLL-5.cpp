//
//  DayLinkedList.cpp - 5
//
//  Edited by student 5
//

#include "dayLinkedList.h"
#include <cassert>

Day::Day(){ // constructor
        eventList = NULL; //just creates an empty node
        eventCount = 0;
}

void Day::scheduleEvent() { // add default Event for a full Day
        scheduleEvent(0,2359,"");
}
void Day::scheduleEvent(int startTime, int endTime, string description){
        Event new_event(startTime, endTime, description);
		EventNode *tempNode = NULL;
		EventNode *prevNode = NULL;
		EventNode *newNode = NULL;
		newNode = new EventNode;
		newNode->theEvent = new_event;
		bool nodeinserted = false;
		if (eventList == NULL){	//creates first node
			eventList = newNode;
			eventList->next = NULL;
			eventCount++;
			nodeinserted = true;
		} else if (new_event.amIBefore(eventList->theEvent)){	//puts in new head
			newNode->next = eventList;
			eventList = newNode;
			nodeinserted = true;
			eventCount++;
		} else for(tempNode=eventList->next, prevNode=eventList; //general case
			tempNode!=NULL; prevNode=tempNode, tempNode=tempNode->next){
			if (new_event.amIBefore(tempNode->theEvent)){
				newNode->next = tempNode;
				prevNode->next = newNode;
				nodeinserted = true;
				eventCount++;
				break; // need to get out of loop if it's created
				
			}
		} if (!nodeinserted){ //put at end, occurs if it is the largest
			tempNode = eventList;
			for (int i = 0; i < eventCount-1; i++){
				tempNode = tempNode->next;
			}
			tempNode->next = newNode;
			newNode -> next = NULL;
			nodeinserted = true;
			eventCount++;
		}	
}



void Day::scheduleEvent(Event anEvent){
        scheduleEvent(anEvent.getStartTime(),anEvent.getEndTime(),anEvent.getDescription());
}

void Day::cancelEvent(Event anEvent){
	EventNode *tempNode = eventList;
	// delete first one
  	if (eventList->theEvent.isSameEventAs(anEvent)){ //delete first node
 		eventList = eventList->next;
  	} else {	//delete any node other than first
		EventNode *prevNode = tempNode;
		tempNode = tempNode->next;
		while (tempNode!=NULL){
			if (tempNode->theEvent.isSameEventAs(anEvent)){
				prevNode->next = tempNode->next;
				break;
			}
			prevNode = tempNode;
			tempNode = tempNode->next;
		}
	}
}

void Day::printDay() {
		EventNode *tempNode = eventList;
	
		for ( ; tempNode != NULL; tempNode = tempNode->next){
			tempNode->theEvent.printEvent();
		}
}

string Day::exportDay(){
        string csvString = "";
        EventNode *tempEventNode = eventList;
        while (tempEventNode != NULL) {
                csvString+= tempEventNode->theEvent.eventCSV() + "\n";
                tempEventNode = tempEventNode->next;
        }
        return csvString;
}
Day::~Day() {
        while (eventList != NULL) {
                EventNode *tempNextNode = eventList->next;
                delete eventList;
                eventList = tempNextNode;
        }
}
