/*
  James McCants
  Date: 4/30/14

  header file for SongHash.cpp
 */

#ifndef __SongSearch__SongHash__
#define __SongSearch__SongHash__

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include "hashfunc.h"

using namespace std;

const float LOADFACTOR = 0.5f; //tells the table when to expand

//holds data for a specific song
struct song_info {
        string title;
        string artist;
        vector<string> lyrics;
};

//holds data for a song as it pretains to a specific word
struct word_freq {
        int freq;
        song_info* song;
};

//holds data for a word that is hashed to be searched later
struct word {
        string word;
        vector<word_freq> song_list;
};

//sets up the hashtable
class WordTable {
    
 public:
        WordTable();
        void read_lyrics(char * filename, bool show_progress );
        void find();
        bool getEnd() {return endIt;};

 private:
        void insert(string w, string a, string t);
        void checkSong(int index, uint32_t);
        void sortFreq(int index, uint32_t hash);
        void print(int index, uint32_t hash);
        void printContext(int index, uint32_t hash, int j);
        string alphaOnly(string s);
        song_info* currentSong;
        bool alreadyIn;
        std::unordered_map<uint32_t, vector<word>> wordList;
        word createWord(string w);
        bool endIt;
};

#endif /* defined(__SongSearch__SongHash__) */
