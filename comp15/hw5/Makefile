#
# Makefile for SongSearch, Assignment 5
#
CXX = g++
FLAGS = -std=c++11 -Wall -Wextra -Wconversion -g

songsearch: songSearch.cpp SongHash.h SongHash.cpp hashfunc.h hashfunc.cpp
	${CXX} ${FLAGS} -o songsearch songSearch.cpp SongHash.cpp hashfunc.cpp

clean:
	rm -f songsearch

provide_design:
	provide comp15 hw5_design songsearch_design.txt

provide:
	provide comp15 hw5 songSearch.cpp SongHash.h SongHash.cpp hashfunc.h hashfunc.cpp readme.txt Makefile


