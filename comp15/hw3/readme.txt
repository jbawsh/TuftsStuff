Read Me

Name: James McCants
Date: 3/5/14

Purpose of program--------------------------------------------------------------

     I used dynamic arrays to store data of days and events. The events were
 input into days in order by time and the days were input into a calendar in
 order by date. The program then prints out the whole thing in multiple formats.

List of files-------------------------------------------------------------------
     
    main.cpp, dayDynamicArray.cpp, dayDynamicArray.h, event.cpp, event.h,
Calendar.cpp, Calendar.h, Makefile, readme.txt

How to compile------------------------------------------------------------------

    Use the inculded Makefile and type the command make and then you can run the
program using ./calendar.

Outline of data structure-------------------------------------------------------

    This program uses a dynamic array of dynamic arrays to store data. Whenever
an array is filled it doubles it's capacity and it moves things to the left or
right when things are inserted or deleted.

Outline of algorithms-----------------------------------------------------------

    In calendar for getDay I cycled through the array of days with a for loop
and checked to find a day with the same date as the given one and returned a
reference to that index in the array.

    In calendar for insertDay I used a for loop to go through the array and 
check and see if there is a day that the date im trying to insert is before
using amIBefore(). Once I found the index of the day it is before I move 
everything else up one index and then insert the day at that spot and return
a reference to that index. If a day is inserted I incriment the day count and
check to see if it is the last index and if the array is empty to catch corner
cases.

    To print the calendar I loop through the day list and call print on each
day which then prints all the events in that day.

    In day nextFreeBlock I first check to see if the event I want to schedule
has any conflicts and if it doesn't I return it's start time. Then I check to
see where it has a conflict and first check to see if it is the last event of
the day that it conflicts with, if so I check to see if moving it back to the
end of the event it's conflicting with still leaves enough time before the day
ends. If so I return the end of that last event to be the start of the one I'm
trying to insert. Else return -1. If it's not the last event that it conflicts 
with I check to see if there is enough room between the end of the event it
conflicts with and the start of the next event and if so I insert it there. If
there isn't enough room I change the start time for the event I'm trying to 
schedule to be after the one it just conflicted with and then I run the loop
again until it either fits or exhausts all of the events in the list and there
is still no space I return -1.

   In day scheduleEarliest I taked the returned start time from next free block
and add on the duration of the event using the duration and addTimes functions
to find the new end time based on the given start time and then I update the
end time then I schedule the event. If next available time is -1 then it returns
false and doen't schedule the event.
