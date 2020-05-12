/* 
    program.c

    Description:
    Program for printing values and addreses of variables in different scopes.
    
    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-05-12
*/

#include <stdio.h>
#include <stdlib.h>

void display(int* a, int* b, int* c){
    printf("\nAddress\t\tName\t\tValue");
    printf("\n-------\t\t----\t\t-----");
    printf("\n%p\ta\t\t%d", a, *a);
    printf("\n%p\tb\t\t%d", b, *b);
    printf("\n%p\tc\t\t%d\n\n", c, *c);
}

int g1(int a, int b){
    int c = (a + b) * b;
    printf("\n*** g1() Function Variable Scope ***\n");
    display(&a, &b, &c);
    return c;
}

int g2(int a, int b){
    int c = g1(a+3, b-11);
    printf("\n*** g2() Function Variable Scope ***\n");
    display(&a, &b, &c);
    return c - b;
}

int main(int argc, char** argv){
    int a = 5;
    int b = 17;
    int c = g2(a-1, b*2);
    printf("\n*** main() Function Variable Scope ***\n");
    display(&a, &b, &c);
    return EXIT_SUCCESS;
}