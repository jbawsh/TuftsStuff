#
# Makefile for maze solver
#
CXX = clang++
FLAGS = -Wall -Wextra -Wconversion -Wreturn-type -g

sandwichList: main.cpp sandwichList.cpp sandwichList.h
	${CXX} ${FLAGS} -o sandwichList main.cpp sandwichList.cpp

clean:
	rm -f sandwichList
	
provide:
	provide comp15 lab4 main.cpp sandwichList.cpp sandwichList.h Makefile
