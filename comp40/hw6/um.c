/* Program to emulate a Universal Machine
 * Authors: Dan Kane and Aaron Bowen
 * 
 * Date: 11/12/14
 * This program effectively emulates a CPU by executing inputted instructions. 
 *
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "bitpack.h"
#include "decoder.h"

#define MAX_LENGTH 250000000      /* number of words that fit into 1000 Mb */

int calc_num_instr(const char *path);
void read_file(FILE *fp);

int main(int argc, const char *argv[])
{
        FILE *fp;
        int length;
        
        fp = fopen(argv[1], "rb");
        
        fprintf(stderr, "argc: %d\n", argc);

        if (argc != 2 || fp == NULL) {
                fprintf(stderr, "improper input\n");
                exit(1);
        }

        length = calc_num_instr(argv[1]);
        assert (length < MAX_LENGTH);
        
        init_mem(length);
        init_regs();

        read_file(fp);      /* reads until EOF */
        fclose(fp);
        
        while (execution_cycle());  /* should call halt() which returns false */
       
        free_regs();
        free_mem();

        exit(0);
}

/*
 * This function reads the inputted .um fle and puts instructions into the
 * instruction segment one word at a time.
 */
void read_file(FILE *fp)  
{
        Segment zero_seg = get_seg(0);
        int byte_size = 8;
        int byte;
        Word instr = 0;
        
        int count;
        for (count = 0; (byte = getc(fp)) != EOF; count++) {
                instr = Bitpack_newu(instr, byte_size, 24, byte);
                
                for (int i = 1; i < 4; i++) {
                        byte = getc(fp);
                        instr = Bitpack_newu(instr, byte_size, 
                                             24 - i * byte_size, byte);
                }
                Word *temp = (Word *) UArray_at(zero_seg, count);
                *temp = instr;
        }
}

int calc_num_instr(const char *path)
{
        struct stat buf;          
        
        stat(path, &buf);
        int size = buf.st_size;
        
        return size / 4;     /* each instruction contains 4 bytes */
}
