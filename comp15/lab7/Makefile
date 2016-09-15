#
# Makefile for Calendar Ordered Lists
#
CXX = clang++
FLAGS = -Wall -Wextra -Wconversion -g

ifeq ($(student),1)
	dayfile = dDA-$(student).cpp
endif
ifeq ($(student),2)
	dayfile = dDA-$(student).cpp
endif
ifeq ($(student),3)
	dayfile = dDA-$(student).cpp
endif
ifeq ($(student),4)
	dayfile = dDA-$(student).cpp
endif
ifeq ($(student),5)
        dayfile = dLL-$(student).cpp
endif
ifeq ($(student),6)
        dayfile = dLL-$(student).cpp
endif
ifeq ($(student),7)
        dayfile = dLL-$(student).cpp
endif

student$(student)Calendar: $(dayfile) dayDynamicArray.h \
                                 tests.h tests.cpp \
                                 event-$(student).cpp event.h main.cpp
	${CXX} ${FLAGS} -o student$(student)Calendar tests.cpp \
	                   $(dayfile) event-$(student).cpp main.cpp

clean:
	rm -f student*Calendar

make provide:
	provide comp15 lab7 debugReport.txt

