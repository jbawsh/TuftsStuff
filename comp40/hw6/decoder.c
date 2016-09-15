/*
 * Authors: Dan Kane, Aaron Bowen
 *
 * Date: 11/12/14
 *
 * This file provides the implementation for the decoder module.
 */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "decoder.h"
#include "bitpack.h"

Register *regs;
Segment instr_seg;
int ip, seg_length;

typedef enum Operations {
        cond_move_op, seg_load_op, seg_store_op, add_op, mult_op, divide_op, 
        nand_op, halt_op, map_seg_op, unmap_seg_op, output_op, input_op, 
        load_prog_op, load_val_op
} Operation;

void execute(Operation op, Register *reg_a, Register *reg_b, Register *reg_c);

/* Allocates memory for the registers and creates a new segment zero */
void init_regs()
{
        regs = calloc(8, sizeof(*regs));
        assert(regs != NULL);
        ip = 0;
        instr_seg = get_seg(0);
        seg_length = UArray_length(instr_seg);
}

/* This is the inner loop - called with every instruction */
bool execution_cycle()
{
        Word instr;
        Operation opcode;
        int reg_a, reg_b, reg_c;

        /* check if all operations have been executed */
        if (ip >= seg_length) {
                return false;
        }
        instr  = *(Word *) UArray_at(instr_seg, ip++);

        if ((int32_t) instr == EOF) {
                return false;
        }

        opcode = Bitpack_getu(instr, 4, 28);

        if (opcode == load_val_op) {           /* treat load_val separately */
                int reg_num = Bitpack_getu(instr, 3, 25);
                Word val = Bitpack_getu(instr, 25, 0);
                load_val(&regs[reg_num], val);
                return true;
        } else if (opcode == halt_op) {       /* treal halt separately */
                return false;
        }
        
        reg_a = Bitpack_getu(instr, 3, 6);   /* some instr ignore some regs */
        reg_b = Bitpack_getu(instr, 3, 3);
        reg_c = Bitpack_getu(instr, 3, 0);

        execute(opcode, &regs[reg_a], &regs[reg_b], &regs[reg_c]);
        return true;
}

/* To execute an instruction, the appropriate operation is called from the 
 * operations interface */
void execute(Operation op, Register *reg_a, Register *reg_b, Register *reg_c)
{
        switch(op) {
        case cond_move_op:
                fprintf(stderr, "cond_move\n");
                cond_move(reg_a, reg_b, reg_c);
                break;   
        case seg_load_op:
                fprintf(stderr, "seg_load\n");
                seg_load(reg_a, reg_b, reg_c);
                break;
        case seg_store_op:
                fprintf(stderr, "seg_store\n");
                seg_store(reg_a, reg_b, reg_c);
                break;
        case add_op:
                fprintf(stderr, "add\n");
                add(reg_a, reg_b, reg_c);
                break;
        case mult_op:
                fprintf(stderr, "mult\n");
                mult(reg_a, reg_b, reg_c);
                break;
        case divide_op:
                fprintf(stderr, "divide\n");
                divide(reg_a, reg_b, reg_c);
                break;
        case nand_op:
                fprintf(stderr, "nand\n");
                nand(reg_a, reg_b, reg_c);
                break;
        case halt_op:
                fprintf(stderr, "halt\n");
                halt();
                break;
        case map_seg_op:
                fprintf(stderr, "map_seg\n");
                map_seg(reg_b, reg_c);
                break;
        case unmap_seg_op:
                fprintf(stderr, "unmap_seg\n");
                unmap_seg(reg_c);
                break; 
        case output_op:
                fprintf(stderr, "output\n");
                output(reg_c);
                break;
        case input_op:
                fprintf(stderr, "input\n");
                input(reg_c);
                break;
        case load_prog_op:
                fprintf(stderr, "load_prog\n");
                if (*reg_b != 0) {
                        load_prog(reg_b);
                        instr_seg = get_seg(0);
                        seg_length = UArray_length(instr_seg);
                }
                ip = *reg_c;
                break;
        default:     /* load_val already accounted for */
                break;
        }
}

void free_regs()
{
        free(regs);
}
