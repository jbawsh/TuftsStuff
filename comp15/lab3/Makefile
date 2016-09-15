#
# Makefile for maze solver
#
CXX = clang++
FLAGS = -Wall -Wextra -Wconversion -Wreturn-type -g

mazeSolver: main.cpp maze.cpp maze.h stack.cpp stack.h
	${CXX} ${FLAGS} -o mazeSolver main.cpp maze.cpp stack.cpp

clean:
	rm -f mazeSolver
	
provide:
	provide comp15 lab3 main.cpp maze.cpp maze.h stack.cpp stack.h Makefile
