#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc != 3)
        {
        printf("Invalid arguments");
        return 1;
        }
    int count = atoi(argv[1]);
    {
    for (int i = 0; i < count; i++) {
        printf("%s\n", argv[2]); 
        }
    }
    return 0;
 }
