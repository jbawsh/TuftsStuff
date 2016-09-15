readme for hw5

James McCants

Date: 4/30/14



Purpose of Program:

        To read in a large song database efficiently and allow the user to 
        search within the database for a specific lyric.

How to Compile:

        Use the makefile by typing "make songsearch".

List of Files:

        songSearch.cpp, SongHash.h, SongHash.cpp, hashfunc.h,
        hashfunc.cpp

Outline of Data Structures:

        For this homework I used an unordered map with a uint32_t key and a 
        vector of structs that contain a word and another vector holding song
        info for that word and a pointer to the actual song itself.

        I used an unordered map because of ease of implementation and that it
        uses a key for easier hashing. I attatched a vector to the unordered map
        so that when collision happens I can push different words onto the
        vector.

Outline of Algorithm:

        I hashed the words to store them into the unordered map and used structs
        to help keep each word paired with the songs that it appears in. I
        decided to wait until the search happened to deal with figuring out the
        frequency of the word in the song as to only print out the top 10 songs 
        it appears in. I did this because this way instead of regoing through
        everything to set the frequencies this way I only deal with the songs
        that contain the word being searched for.

        I used a selection sort to find the top 10 frequencies after I found a
        word because that way I only had to go through the whole list of songs
        attatched to a word 10 times to find the 10 highest frequencies.
