#include <iostream>
#include <stdio.h>
#include "hector.h"

using namespace std;
//
// hector.cpp -- compare three different collision solutions
//
// your job: code the insert functions
//  our job: run the three insert functions and report results
//

// constructor
Hector::Hector()
{
	for(int i = 0; i < TSIZE; i++)
	{
		cheneyTable[i] = NULL;
		linnyTable[i] = -1;
		doublesTable[i] = -1;
	}
}


// linear probing
//
//  returns number of collisions before finding a spot
//
int Hector::linny(int value)
{
	int attempt = 0;
	int index;
	bool found = false;
	while(!found)
	{
                index = (3*value + 7 + attempt)%17;
		if (linnyTable[index] == SENTINEL) {
                        found = true;
                        linnyTable[index] = value;
                } else {
                        attempt++;
                }
	}
	return attempt;
}

// double hashing using a second function
//  
//  returns number of collisions before finding a spot
//
int Hector::doubles(int value)
{
	int attempt = 0;
        int index;
        bool found = false;
        while(!found) {
                index = (3*value + 7 + (attempt * (13 - (value%13))) )%17;
                if (doublesTable[index] == SENTINEL) {
                        found = true;
                        doublesTable[index] = value;
                } else {
                        attempt++;
                }
        }
	return attempt;
}

// chained hashing -- each spot in table is a linked list 
//
//  returns number of items in that spot before insertion
//
int Hector::cheney(int value)
{
	int attempt = 0;
        int index;
        Node* temp;
        Node* newNode = new Node;
        newNode->key = value;
        newNode->next = NULL;
        
        index = (3*value + 7)%17;

        if (cheneyTable[index] == NULL) {
                cheneyTable[index] = newNode;
        } else {
                temp = cheneyTable[index];
                while (temp->next != NULL) {
                        attempt++;
                        temp = temp->next;
                }
                temp->next = newNode;
        }
        
        return attempt;
}

// print the hash tables
void Hector::print()
{
	for(int i=0; i < TSIZE; i++)
	{
		cout << linnyTable[i] << " ";
		
	}
	
	cout << endl;
	
	for(int i=0; i < TSIZE; i++)
	{
		cout << doublesTable[i] << " ";
		
	}
	cout << endl;
	
	Node* iter = NULL;
	for(int i=0; i < TSIZE; i++)
	{
		iter = cheneyTable[i];
		cout << " [";
		while(iter != NULL)
		{
			cout << iter->key << " ";
			iter = iter->next;
		}
		cout << "]";
	}
	cout << endl;
}
