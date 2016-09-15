#
# Makefile for Hashing Lab
#
CXX = clang++
FLAGS = -Wall -Wextra -Wconversion -Wreturn-type -g

hectorHash: hector-main.cpp hector.cpp hector.h
	${CXX} ${FLAGS} -o hectorHash hector-main.cpp hector.cpp

clean:
	rm -f hectorHash
	
provide:
	provide comp15 lab10 hector-main.cpp hector.cpp hector.h Makefile
