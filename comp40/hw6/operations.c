/*
 * Authors: Dan Kane, Aaron Bowen
 *
 * Date: 11/13/14
 * 
 * This file provides the implementation for the 13 operations of the UM.
 *
 * Note: It is an unchecked runtime error to attempt to access a memory location
 *       that is not included in a mapped segment.
 *       It is also an u.r.e. to attempt to input or output a value outside the
 *       range 0 to 255.
 */

#include <stdlib.h>
#include <stdio.h>

#include "operations.h"
#include "decoder.h"

void cond_move(Register *dest, Register *origin, Register *cond)
{
        if (*cond != 0) {
                *dest = *origin;
        }
}

void seg_load(Register *dest, Register *seg_id, Register *offset)
{
        *dest = get_word(*seg_id, *offset);
}

void seg_store(Register *seg_id, Register *offset, Register *word)
{
        put_word(*word, *seg_id, *offset);
}

void add(Register *dest, Register *arg1, Register *arg2)
{
        *dest = *arg1 + *arg2;
}

void mult(Register *dest, Register *arg1, Register *arg2)
{
        *dest = (*arg1) * (*arg2);
}

void divide(Register *dest, Register *numer, Register *denom)
{
        *dest = *numer / *denom;   /* rounds to zero */
}

void nand(Register *dest, Register *arg1, Register *arg2)
{
        *dest = (*arg1) & (*arg2);
        *dest = ~(*dest);
}

void halt()
{
        /* Do nothing */
}

void map_seg(Register *stores_id, Register *length)
{
        *stores_id = new_seg(*length);
}

void unmap_seg(Register *seg_id)
{
        free_seg(*seg_id);
}

void output(Register *value)
{
        putchar((int)*value);
}

void input(Register *stores_val)
{
        *stores_val = (uint32_t) getchar();
}

void load_prog(Register *seg_id)
{
        Segment seg = get_seg(*seg_id);
        int length = UArray_length(seg);
        int put_at = 0;
        put_seg(UArray_copy(seg, length), put_at);
}

void load_val(Register *store_in, Word val)
{
        *store_in = val;
}
