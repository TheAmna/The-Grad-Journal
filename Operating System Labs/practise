#include <unistd.h>   // fork() lives here, not std.h
#include <stdio.h>

int main(int argc, char *argv[]) {   // argv needs [] — it's an array of strings
    printf("A\n");                    // \n goes INSIDE the quotes, no backslash-space before it

    int rc1 = fork();                 // first fork

    if (rc1 == 0) {
        // this block runs in the CHILD process
        printf("B\n");

        int rc2 = fork();             // second fork, only in child

        if (rc2 == 0) {
            // this runs in the GRANDCHILD process
            printf("C\n");
        }
        else {
            // this runs in the CHILD process (parent of grandchild)
            printf("D\n");
        }
    }
    else {
        // this runs in the ORIGINAL PARENT process
        printf("E\n");
    }

    return 0;
}
