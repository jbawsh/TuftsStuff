/*
  SongHash.cpp
  SongSearch
  Name: James McCants
  Date: 4/30/14

  The purpose of this program is to read in data from a file of song lyrics and
  allow the user to search in that database to find songs with that contain the
  word they are looking for and it should print out the title and artist of the
  songs the word is in along with some context for the word within the lyrics.
*/

#include "SongHash.h"
#include "hashfunc.h"

using namespace std;

/*
  Initializes some values and sets the load factor for my unodered map.
 */

WordTable::WordTable() {
        currentSong = NULL;
        alreadyIn = false;
        endIt = false;
        wordList.max_load_factor(LOADFACTOR);
}

/*
  Purpose: to insert words into the hashtable with a pointer to the song that
  they were found in. Runs checks to see if the word/song pair has already been
  input into the table so as not to have repeats. If the word is already in it
  calls another function to check and see if the song is already attatched to it

*/

void WordTable::insert(string w, string a, string t) {
        bool didBreak = false;
        int index;
        if (currentSong == NULL ||
            a != currentSong->artist ||
            t != currentSong->title) {
                currentSong = new song_info();
                currentSong->artist = a;
                currentSong->title = t;
        }
        currentSong->lyrics.push_back(w);
        string word = alphaOnly(w);
        uint32_t hash = hash_string(word);
      
        if (alreadyIn == false) {
                for (int i = 0; i < wordList[hash].size(); i++) {
                        if (wordList[hash][i].word == word) {
                                didBreak = true;
                                index = i;
                                break;
                        }
                }
                if (didBreak) alreadyIn = true;
        }
        if (!alreadyIn) {
                wordList[hash].push_back(createWord(word));
                alreadyIn = true;
        } else {
                checkSong(index, hash);
        }
}

/*
  Purpose: checks to see if a word and song are already paired, if they aren't
  it adds the song onto the word so that when the word is searched for later
  the song is checked.
 */

void WordTable::checkSong(int index, uint32_t hash) {
        vector<word_freq>* cSong = new vector<word_freq>;
        *cSong = wordList[hash][index].song_list;
        bool didBreak = false;

        for (int i = 0; i < cSong->size(); i++) {
                if (cSong->at(i).song->title == currentSong->title &&
                    cSong->at(i).song->artist == currentSong->artist) {
                        didBreak = true;
                        break;
                }
        }
        if (!didBreak) {
                word_freq temp;
                temp.song = currentSong;
                temp.freq = 0;
                cSong->push_back(temp);
        }
}

/*
  Creates a new set of word and word_freq structs for the new word and adds on
  the song it came from to create the new pair.
 */

word WordTable::createWord(string w) {
        word tempWord;
        word_freq tempFreq;
        tempFreq.freq = 0;
        tempFreq.song = currentSong;
        tempWord.song_list.push_back(tempFreq);
        tempWord.word = w;
        return tempWord;
}

/*
  Purpose: Reads in a word from the user and finds it in the hashtable. If it 
  can't find it nothing happens, otherwise it goes to the word and then starts
  to cycle through all the songs attatched to the word and everytime it finds 
  the word in the lyrics it incriments the frequency. Then it calls a function
  to sort the frequencies.
 */

void WordTable::find() {
        bool didBreak = false;
        string w;
        int index;
        cin >> w;
        if (w == "<BREAK>") {
                endIt = true;
                return;
        }
        w = alphaOnly(w);
        uint32_t hash = hash_string(w);
        for (int i = 0; i < wordList[hash].size(); i++) {
                if (wordList[hash][i].word == w) {
                        index = i;
                        didBreak = true;
                        break;
                }
        }       
        if (!didBreak) return;

        vector<word_freq>* cSong = new vector<word_freq>;
        *cSong = wordList[hash][index].song_list;       
        for (int i = 0; i < cSong->size(); i++) {
                for (int j = 0; j < cSong->at(i).song->lyrics.size(); j++) {
                        if (alphaOnly(cSong->at(i).song->lyrics[j]) == w) {
                                cSong->at(i).freq++;
                        } } }
        delete cSong;
        sortFreq(index, hash);
}

/*
  Purpose: Takes in the location of a word in the hashtable and goes through all
  the songs attatched to it and uses a selection sort to find the top 10 songs
  with the largest frequencies because you only print the top 10. Then calls
  print to print the results.
 */

void WordTable::sortFreq(int index, uint32_t hash) {

        vector<word_freq>* cSong = new vector<word_freq>;
        *cSong = wordList[hash][index].song_list;

        int pos_max,count;
        word_freq temp;

	for (int i=0; (i < cSong->size()-1) && (count < 10); i++) {
                pos_max = i;		
                for (int j=i+1; j < cSong->size(); j++) {
                        if (cSong->at(j).freq > cSong->at(pos_max).freq) {
                                pos_max=j;
                        }
                }		
                if (pos_max != i) {
                        temp = cSong->at(i);
                        cSong->at(i) = cSong->at(pos_max);
                        cSong->at(pos_max) = temp;
                }
                count++;
	}
        delete cSong;
        print(index, hash);
}

/*
  Purpose: Takes in the location of the word and then prints out the Artist and
  title and context for the first 10 songs in the song_list vector. It calls a 
  function to print out the context around the words.
 */

void WordTable::print(int index, uint32_t hash) {

        int count = 0;
        vector<word_freq>* cSong = new vector<word_freq>;
        *cSong = wordList[hash][index].song_list;
        
        for (int i=0; i < cSong->size() && count < 10; i++) {
                cout << "Title: ";
                cout << cSong->at(i).song->title << endl;
                cout << "Artist: ";
                cout << cSong->at(i).song->artist << endl;
                cout << "Context: ";
                printContext(index, hash, i);
                count++;
        }
        delete cSong;
}

/*
  Purpose: Saves the indexes of where a word appears in a song and then loops
  through the song lyrics printing out the 5 words before and after the target
  word at every index that was saved. Checks to make sure for words at the start
  and end of songs.
 */

void WordTable::printContext(int index, uint32_t hash, int j) {
        vector<int> indexes;
        vector<word_freq>* cSong = new vector<word_freq>;
        *cSong = wordList[hash][index].song_list;
        string word = wordList[hash][index].word;

        for (int i = 0; i < cSong->at(j).song->lyrics.size(); i++) {
                if (word == cSong->at(j).song->lyrics[i]) {
                        indexes.push_back(j);
                }
        }
        for (int i = 0; i < indexes.size(); i++) {
                for (int z = indexes[i]-5; z < indexes[i]+6; z++) {
                        if (z >= 0 && z < cSong->at(j).song->lyrics.size()) {
                                cout << cSong->at(j).song->lyrics[z];
                        }
                }
        }
}

//
// read_lyics 
//   purp: read in song data from a disk file
//   args: the name of the file, bool to ask for progress status
//   rets: nothing
//   does: calls a function each time a word is found
//
void WordTable::read_lyrics(char * filename, bool show_progress)
{
        ifstream in(filename);			// creates an input stream
        int song_count = 0;			// for progress indicator
	string artist, title, word;		// data from the file

	// -- While more data to read...
	while ( ! in.eof() ) 
	{
		// -- First line is the artist
		getline(in, artist);
		if (in.fail()) break;
		// -- Second line is the title
		getline(in, title);
		if (in.fail()) break;
		if ( show_progress )
		{
			song_count++;
			if (song_count % 10000 == 0) {
				cout << "At "       << song_count << 
					" Artist: " << artist     << 
					" Title:"   << title << endl;
			}
		}
		while ( in >> word && word != "<BREAK>" ){
                        insert(word,artist,title);
		}
		// -- Important: skip the newline left behind
		in.ignore();
                alreadyIn = false;
	}
}


// alphaOnly() strips off non-alphabetic and non-digit characters
// and returns a string with just the alphas and digits.

string WordTable::alphaOnly(string s){

        ostringstream ss;

        for (size_t i=0;i<s.length();i++) {
                if (isalnum(s[i])){
                        ss << (char)(tolower(s[i]));
                }
        }
        return ss.str();
}
