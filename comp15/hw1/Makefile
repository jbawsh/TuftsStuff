#
# Makefile for rectangle assignment
#
CXX = /usr/bin/clang++
FLAGS = -Wall -Wextra -O3 -lm

rectangleTester: rectangleTester.cpp rectangle.cpp rectangle.h
	${CXX} ${FLAGS} -o rectangleTester rectangleTester.cpp rectangle.cpp

clean:
	rm -f rectangleTester

provide:
	provide comp15 hw1 rectangle.h rectangle.cpp rectangleTester.cpp \
		Makefile Readme
