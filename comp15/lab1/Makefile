#
# Makefile for hookbook
#
CXX = clang++
FLAGS = -Wall -Wextra -g

hookbook: main.cpp hookbook.cpp hookbook.h
	${CXX} ${FLAGS} -o hookbook main.cpp hookbook.cpp

clean:
	rm -f hookbook
	
provide:
	provide comp15 lab1 main.cpp hookbook.cpp hookbook.h

