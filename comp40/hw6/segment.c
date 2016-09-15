/* Implementation for a module which emulates a 32-bit segmented memory
*  
*  Authors: Dan Kane, Aaron Bowen
*  November 12 2014
*
*  This file is the implementation for a component which acts as a memory
*  manager for a Universal Machine.  
*/ 

#include <stdlib.h>
#include <stdio.h>

#include "segment.h"

Seq_T seg_IDs, unmapped_IDs;

/*
*  Initiliazer function which is called at the beginning of execution.
*  Creates the sequences which will manage the memory segments and
*  initializes the instruction segment with a specified length.
*/
void init_mem(uint32_t length) 
{
	seg_IDs = Seq_new(100); 
	unmapped_IDs = Seq_new(100);
	Segment zero_seg = UArray_new(length, sizeof(Word));
	Seq_addlo(seg_IDs, zero_seg);
}

/*
* This function maps a new segment of specified length. Reuses unmapped
* segment IDs when possible.
*/
ID new_seg(uint32_t length)
{
	Segment new_seg = UArray_new(length, sizeof(Word));
	if (Seq_length(unmapped_IDs) != 0) {   /* check for unmapped IDs */
		ID id = (ID)(uintptr_t) Seq_remlo(unmapped_IDs); 
		Seq_put(seg_IDs, id, new_seg);
		return id;
	} 
	Seq_addhi(seg_IDs, new_seg);           /* add brand new ID */
	ID id = (ID) Seq_length(seg_IDs) - 1; 
	return id;
}

/*
* This function frees a segment with the specified ID and adds this
* ID to unmapped_IDs. It is an unchecked runtime error if ID does 
* not exist
*/ 
void free_seg(ID id)
{
	Segment to_free = (Segment) Seq_get(seg_IDs, (int) id);
	UArray_free(&to_free);
	Seq_put(seg_IDs, (int) id, NULL);
	Seq_addlo(unmapped_IDs, (void *)(uintptr_t) id); 
}

/*
*  Stores a given word at a specified location in memory
*/
void put_word(Word word, ID id, uint32_t offset)
{
	Segment seg = (Segment) Seq_get(seg_IDs, (int) id);
	Word *temp = (Word *) UArray_at(seg, (int) offset);
	*temp = word;
}

/*
* Returns a word from a given location in memory
*/
Word get_word(ID id, uint32_t offset)
{
	Segment seg = (Segment) Seq_get(seg_IDs, (int) id);
	return *(Word *) UArray_at(seg, (int) offset);
}

/*
* Returns a pointer to the segment associated with the provided ID
*/
Segment get_seg(ID id)
{
	Segment seg = (Segment) Seq_get(seg_IDs, (int) id);
	return seg;
}

/*
* Stores a given segment at the specified ID and frees previous contents
* at this ID
*/
void put_seg(Segment seg, ID id)
{
	Segment to_free = (Segment) Seq_get(seg_IDs, (int) id);
	UArray_free(&to_free);
	Seq_put(seg_IDs, (int) id, seg);
}

/*
* Frees all memory associated with the memory manager
*/
void free_mem()
{
	int length = Seq_length(seg_IDs);
	for (int i = 0; i < length; i++) {
		Segment to_free = (Segment) Seq_get(seg_IDs, i);
		if (to_free != NULL) {
			UArray_free(&to_free);
		}
	}
	Seq_free(&seg_IDs);
	Seq_free(&unmapped_IDs);
}
