#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

int main(int argc, char * argv[]){
    int a = getpid();
    printf("Hello World [pid:%d] \n", a);
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed \n");
        exit(1);
    }
    else if (rc == 0){
        printf("hello, I am the child (pid : %d) \n", getpid());
        char *myargs[4];
        myargs[0] = strdup("grep"); //program
        myargs[1] = argv[1]; //arg
        myargs[2] = argv[2]; //arg
        myargs[3] = NULL; // end of arr
        execvp(myargs[0], myargs); //error handling
        // goes to the olders, finds ls, and does the -l 
        //command where the file name is ommitted int he results 
        fprintf(stderr, "exec failed, this line shouldn't print out \n");
        exit(1);
    }
    else {
        int wc = waitpid(rc,NULL,0);
        // passing &status gives the condition of the child 
        printf("hello, I am the parent of %d (wc : %d) \n", rc, wc, a);
    }
    return 0;
}
