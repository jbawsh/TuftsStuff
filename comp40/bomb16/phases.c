#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* dummy functions so it can compile */

bool strings_not_equal(FILE *input, char *check)
{
        (void)input;
        (void)check;
        return false;
}

int string_length(FILE *str) 
{
        (void)str;
        int len = 0;
        return len;
}

int *read_six_numbers(FILE *str) 
{
        (void)str;
        int *six = NULL;
        return six;
}
void explode_bomb() 
{
        return;
}

/* our functions for phases 1 - 6 */

void phase_1(FILE *input)
{
        char *check = "There is more stupidity than hydrogen.";
        
        if (strings_not_equal(input, check)) {
                explode_bomb();
        }
}

void phase_2(FILE *input)
{
        int *six_num;

        six_num = read_six_numbers(input);

        for (int i = 0; i < 5; i++) {
                if ((six_num[i] + 5) != six_num[i + 1]) {
                        explode_bomb();
                }
        }
}

void phase_3(FILE *input)
{
        int *c = NULL;
        int *valPtr = NULL;

        fscanf(input, "%d, %d", c, valPtr);

        int value = *valPtr;

        switch(*c)
        {
        case 0:
                if (value != 471) {
                        explode_bomb();
                }
                return;
        case 1:
                if (value != 938) {
                        explode_bomb();
                }
                return;
        case 2:
                if (value != 467) {
                        explode_bomb();
                }
                return;
        case 3:
                if (value != 658) {
                        explode_bomb();
                }
                return;
        case 4:
                if (value != 558) {
                        explode_bomb();
                }
                return;
        case 5:
                if (value != 475) {
                        explode_bomb();
                }
                return;
        case 6:
                if (value != 461) {
                        explode_bomb();
                }
                return;
        case 7:
                if (value != 159) {
                        explode_bomb();
                }
                return;
        default:
                explode_bomb();
        }
}

/* this function does x^x recursively */

int func4(int val, int count)
{
        if (count == 0) {
                return val;
        }

        return func4(val, count - 1) * val;
}

void phase_4(FILE *input)
{
        int *valPtr = NULL;

        fscanf(input, "%d", valPtr);

        int val = *valPtr;

        val = func4(val, val);

        if (val != 823543) {
                explode_bomb();
        }
}

void phase_5(FILE *input)
{
        int total = 0;
        int arr[] = {2, 10, 6, 1, 12, 16, 9, 3, 4, 7, 14, 5, 11, 8, 15, 13};

        if (string_length(input) != 6) {
                explode_bomb();
        }
        
        for (int i = 0; i < 6; i++) {
                char c = getc(input);
                
                c &= 15;

                total += arr[((int) c)];
        }

        if (total != 32) {
                explode_bomb();
        }

}

/* this is an insertion sort for an array of long pointers of any length */
long **fun6(long **a, int len)
{
        for (int i = 1; i < len; i++) {
                long *tmp = a[i];
                int j;
                for (j = i - 1; j >= 0 && *tmp > *(a[j]); j--) {
                        a[j + 1] = a[j];
                }
                a[j + 1] = tmp;
        }
        return a;
}

void phase_6(FILE *input)
{
        char *ptr;
        int base = 10;
        long val = strtol((char *) input, &ptr, base);

        long **arr = NULL;

        *(arr[0]) = 178;
        *(arr[1]) = 181;
        *(arr[2]) = 695;
        *(arr[3]) = 349;
        *(arr[4]) = 432;
        *(arr[5]) = 957;
        *(arr[6]) = 664;
        *(arr[7]) = 142;
        *(arr[8]) = 363;

        arr = fun6(arr, 9);

        if (*(arr[8]) != val) {
                explode_bomb();
        }
}

/* dummy main so it can compile */

int main() {
        FILE *input = NULL;

        phase_1(input);
        phase_2(input);
        phase_3(input);
        phase_4(input);
        phase_5(input);
        phase_6(input);

        return 0;
}
