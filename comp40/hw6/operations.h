/*
 * Authors: Dan Kane, Aaron Bowen
 *
 * Date: 11/12/14
 *
 * This file provides the interface for the operations module.
 * The operation module is responsible for the actual execution of individual
 * instructions.
 */

#ifndef _OPERATIONS_
#define _OPERATIONS_

#include <segment.h>

typedef uint32_t Register;

void cond_move(Register *dest, Register *origin, Register *cond);

void seg_load(Register *dest, Register *seg_id, Register *offset);

void seg_store(Register *seg_id, Register *offset, Register *word);

void add(Register *dest, Register *arg1, Register *arg2);

void mult(Register *dest, Register *arg1, Register *arg2);

void divide(Register *dest, Register *numer, Register *denom);

void nand(Register *dest, Register *arg1, Register *arg2);

void halt();

void map_seg(Register *store_id, Register *length);

void unmap_seg(Register *seg_id);

void output(Register *value);

void input(Register *store_val);

void load_prog(Register *seg_id);

void load_val(Register *store_in, Word val);

#endif
