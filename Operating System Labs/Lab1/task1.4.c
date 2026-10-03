#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 6)
        {
        printf("Invalid arguments");
        return 1;
        }
    int int1 = atoi(argv[1]);
    int sum = 0;
    int min = int1;
    int max = int1;
    for (int i = 1; i < argc; i++)
    {
        int num = atoi(argv[i]);
        sum += num; 
        if (num < min) {
            min = num; 
        }
        if (num > max) {
            max = num; 
        }
    }
    printf("Sum = %d\n", sum);
    printf("Min. = %d\n", min);
    printf("Max. = %d\n", max);
    return 0;
}
 
