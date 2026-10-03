#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{  
    if (argc != 3)
        {
        printf("Invalid arguments");
        return 1;
        }
    int int1 = atoi(argv[1]);
    int int2 = atoi(argv[2]);
    printf("%d + %d = %d \n" , int1, int2, int1 + int2);       
    return 0;
 }
