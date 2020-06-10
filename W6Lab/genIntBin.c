// C program to generate random numbers and write them to binary
// Based on https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

void print_binary(int number, FILE* file, int zeros)
{
    if (zeros < (sizeof(int)*8)) {
        print_binary(number >> 1, file, zeros+1);
        putc((number & 1) ? '1' : '0', file);
    }
}

// Driver program
int main(int argc, char* argv[])
{
	// This program will create different sequence of
	// random numbers on every program run
    if(argc != 3)
    {
        printf("%s: %s\n", argv[0], "<number of numbers> <file name>");
        return EXIT_FAILURE;
    }

    FILE* file = fopen(argv[2], "wb");
    if(file == NULL){
        printf("failed to open file\n");
        return EXIT_FAILURE;
    }
    //no error checking
    int max = atoi(argv[1]);

    print_binary(max, file, 0);
    int num = 0;
	// Use current time as seed for random generator
    srand(time(0));

    for(int i = 0; i<max; i++){
        num = rand()/(float)1000;
        print_binary(num, file, 0);
    }
	return 0;
}
