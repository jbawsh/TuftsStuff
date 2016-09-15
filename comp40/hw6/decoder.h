/*
 * Authors: Dan Kane, Aaron Bowen
 *
 * Date: 11/12/14
 *
 * This file provides the interface for the decoder module.
 * 
 * The decoder module extract one instructions at a time, extracts its opcode, 
 * register number(s), an optional value (load_val only), and then
 * executes the instruction.
 * This module is also responsible for managing the registers and distributing
 * access to them during instruction execution.
 */

#ifndef _DECODER_
#define _DECODER_

#include <stdbool.h>
#include "operations.h"

bool execution_cycle();
void init_regs();
void free_regs();

#endif
