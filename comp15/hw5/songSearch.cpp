/*
  James McCants

  Date: 4/30/14

  Main for hw5, calls functions to read in data and allow for searching.
 */

#include <iostream>
#include <string> 

#include "SongHash.h"

using namespace std;

/*
  Purpose: Takes in arguments for the file to be searched and calls functions
  from the WordTable class to set up the hashtable and then calls find() to let
  the user search for a word.
 */

int main(int argc, char *argv[])
{
        WordTable wordlist;
	if (argc == 2) {
		wordlist.read_lyrics(argv[1],false);
                while (!wordlist.getEnd()) {
                        wordlist.find();
                }
	}
	else {
		cout << "Usage: songsearch database.txt\n";
	}

        cout << "<END-OF-REPORT>" << endl;
        return 0;
}
