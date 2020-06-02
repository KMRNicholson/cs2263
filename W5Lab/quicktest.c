#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
    int num = 0;
    int i = 0;
    while(argv[i] != (char*)NULL){
        num++;
        i++;
    }

    printf("%d %d", argc, num);
    return 0;
}