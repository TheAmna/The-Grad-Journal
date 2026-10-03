// Write a program that accepts a number of strings, sorts them alphabetically, and
// then prints them, as shown below:
// task2 hello my name is Bilal

// Bilal
// hello
// is
// my
// name
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_strings(char *arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc - 1; i++) {
        for (int j = 0; j < argc - i - 1; j++) {
            if (strcmp(argv[j], argv[j + 1]) > 0) {
                char *temp = argv[j];
                argv[j] = argv[j + 1];
                argv[j + 1] = temp;
            }
        }
    }
    print_strings(&argv[1], argc -1);
    return 0;
}
