/* 
    digitOnes.c

    Description:
    Program for finding the amount of 1's in the binary representation of a base10 number.
    
    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-05-05

    Links:
    https://tutorialspoint.dev/language/cpp/char_bit-in-c
    https://www.tutorialspoint.com/sizeof-operator-in-c
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char** argv){
    int value;
    int iErr;
    int bits, bits_per_byte, bytes;
    int one_count;

    printf("Integer to examine (integer 'n' must be '0 < n < 2147483648'): ");
    iErr = scanf("%i",&value);

    // Check for NaN inputs
    if(iErr != 1){
        printf("Unable to read the value.\n");
        return EXIT_FAILURE;
    }

    // Check for inputs outside limits.
    if(value < 1 || value > INT_MAX){
        printf("Invalid integer value. Please enter an integer 'n' which follows '0 < n < 2147483648'.\n");
        return EXIT_FAILURE;
    }
    
    bits_per_byte = CHAR_BIT; //CHAR_BIT is how many bits are in a char (1 byte) for the system (typically will be 8 bits)
    bytes = sizeof(value); //sizeof(value) gets the amount bytes allocated in memory for the value variable type

    bits = bits_per_byte * bytes; //We multiple bits_per_byte * bytes to get the amount of bits for the value variable

    // Loop through the bits in value while using bitwise operators for anding and shifting to determine the amount of 1's  
    one_count = 0;
    for(int i = 0; i < bits; i++){
        int bitwise_result = value & 1;
        if(bitwise_result == 1){
            one_count++;
        }

        value = value >> 1;
        i++;
    }

    printf("Number of ones: %i", one_count);

    return EXIT_SUCCESS;
}