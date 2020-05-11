#include <stdio.h>
#include "myutils.h"

int main(int argc, char** argv){
    int i = 10; //Declares a variable i and assigns value 10.
    int j = 99; //Decalres a variable j and assigns value 99.
    int* pi; //Declares a pointer variable for i.
    int* pj; //Declares a pointer variable for j.
    pi = &i; //Assigns the address of i to the pi pointer variable.
    pj = &j;

    printf("\n*** SWAP FUNCTION ***\n\n");
    
    printf("Before swap:\n");
    printf("i - address:%p \tvalue:%i\n", &i, i); //We print the address of i (by dereferencing i), and then the value
    printf("j - address:%p \tvalue:%i\n", &j, j); //We print the address of i, and then the value (by using indirection on pi)

    swap(pi, pj);

    printf("After swap:\n");
    printf("i - address:%p \tvalue:%i\n", &i, i); //We print the address of i (by dereferencing i), and then the value
    printf("j - address:%p \tvalue:%i\n", &j, j); //We print the address of i, and then the value (by using indirection on pi)

    printf("\n*** ZERO FUNCTION ***\n\n");

    printf("Before zero:\n");
    printf("i - address:%p \tvalue:%i\n", &i, i); //We print the address of i (by dereferencing i), and then the value
    printf("j - address:%p \tvalue:%i\n", &j, j); //We print the address of i, and then the value (by using indirection on pi)

    zero(pi);
    zero(pj);

    printf("After zero:\n");
    printf("i - address:%p \tvalue:%i\n", &i, i); //We print the address of i (by dereferencing i), and then the value
    printf("j - address:%p \tvalue:%i\n", &j, j); //We print the address of i, and then the value (by using indirection on pi)

    printf("\n*** PLAYING WITH POINTERS ***\n\n");

    printf("i - address:%p \tvalue:%i\n", &i, i); //We print the address of i (by dereferencing i), and then the value
    printf("pi - value:%p \tindirection:%i\n", pi, *pi); //We print the address of i, and then the value (by using indirection on pi)

    printf("Please enter a new value for i: "); //Here I added some of my own practice just to understand scanf() a bit better
    scanf("%d", pi); //Passing pi, which contains the address of i, to the scanf() function.

    printf("i - address:%p \tvalue:%i\n", &i, i); //We print the address of i (by dereferencing i), and then the value
    printf("pi - value:%p \tindirection:%i\n", pi, *pi); //We print the address of i, and then the value (by using indirection on pi)

    return 0;
}