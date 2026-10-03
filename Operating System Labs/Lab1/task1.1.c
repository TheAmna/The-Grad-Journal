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


// Print a string (a note) as many times as you want. This will require some loops.
// For instance, the program titled “task1” prints the given note three times:
// task1 3 “I hate you”
// I hate you
// I hate you
// I hate you

// Please note that arguments passed onto a program are strings, not numbers. So,
// 3 above is string “3” and not number 3. To convert “3” to 3, use the function
// atoi(), of the C’s standard library <stdlib.h> to convert string numbers like
// “333” to int 333. Something like atoi(argv[1]) will work
