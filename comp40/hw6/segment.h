/* Interface for a memory manager for a Universal Machine
* 
* Authors: Dan Kane, Aaron Bowen
* November 12 2014
*
* This component acts as a memory manager for a UM. The memory is split into 
* segments with unique IDs. The smallest unit of memory is a 32-bit word.
*/

#ifndef _SEGMENT_
#define _SEGMENT_

#include <stdint.h>
#include <seq.h>
#include <uarray.h>

typedef UArray_T Segment;
typedef uint32_t Word;
typedef uint32_t ID;

void init_mem(uint32_t length); 

ID new_seg(uint32_t length);

void free_seg(ID id); 

void put_word(Word word, ID id, uint32_t offset);

Word get_word(ID id, uint32_t offset);

Segment get_seg(ID id);

void put_seg(Segment seg, ID id);

void free_mem();

#endif
