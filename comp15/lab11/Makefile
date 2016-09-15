#
# Makefile for Graph Traversal Lab
#
CXX = clang++
FLAGS = -Wall -Wextra -Wconversion -Wreturn-type -g

graphTraversal: main.cpp graph.cpp graph.h
	${CXX} ${FLAGS} -o graphTraversal graph.cpp main.cpp

clean:
	rm -f graphTraversal
	
provide:
	provide comp15 lab11 main.cpp graph.cpp graph.h Makefile
