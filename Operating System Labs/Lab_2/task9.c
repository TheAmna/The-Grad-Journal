#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

int main(int argc, char * argv[]){
    int a = getpid();
    printf("Hello World [pid:%d] \n", a);

    int rc1 = fork(); 
    if (rc1 < 0){
        fprintf(stderr, "fork failed \n");
        exit(1);
    }
    else if (rc1 == 0){
        printf("hello, I am the child (pid : %d) \n", getpid());
        char *myargs1[4];
        myargs1[0] = strdup("grep"); //program
        myargs1[1] = argv[1]; //arg
        myargs1[2] = argv[2]; //arg
        myargs1[3] = NULL; // end of arr
        execvp(myargs1[0], myargs1); //error handling
        // goes to the olders, finds ls, and does the -l 
        //command where the file name is ommitted int he results 
        fprintf(stderr, "exec failed, this line shouldn't print out \n");
        exit(1);
    }

    int rc2 = fork(); 
    if (rc2 < 0){
        fprintf(stderr, "fork failed \n");
        exit(1);
    }
    else if (rc2 == 0){
        printf("hello, I am the child (pid : %d) \n", getpid());
        char *myargs2[4];
        myargs2[0] = strdup("wc"); //program
        myargs2[1] = argv[2]; //arg //arg //arg
        myargs2[3] = NULL; // end of arr
        execvp(myargs2[0], myargs2); //error handling
        // goes to the olders, finds ls, and does the -l 
        //command where the file name is ommitted int he results 
        fprintf(stderr, "exec failed, this line shouldn't print out \n");
        exit(1);
    }

    int rc3 = fork(); 
    if (rc3 < 0){
        fprintf(stderr, "fork failed \n");
        exit(1);
    }
    else if (rc3  == 0){
        printf("hello, I am the child (pid : %d) \n", getpid());
        char *myargs3[4];
        myargs3[0] = strdup("cat"); //program
        myargs3[1] = argv[2]; //arg
        myargs3[3] = NULL; // end of arr
        execvp(myargs3[0], myargs3); //error handling 
        fprintf(stderr, "exec failed, this line shouldn't print out \n");
        exit(1);
    }

    int rc4 = fork(); 
    if (rc4 < 0){
        fprintf(stderr, "fork failed \n");
        exit(1);
    }
    else if (rc4 == 0){
        printf("hello, I am the child (pid : %d) \n", getpid());
        char *myargs4[4];
        myargs4[0] = strdup("echo"); //program
        myargs4[1] = argv[1];  //arg
        myargs4[3] = NULL; // end of arr
        execvp(myargs4[0], myargs4); //error handling
        // goes to the olders, finds ls, and does the -l 
        //command where the file name is ommitted int he results 
        fprintf(stderr, "exec failed, this line shouldn't print out \n");
        exit(1);
    }


    else {
        int wc1 = waitpid(rc1,NULL,0);
        // passing &status gives the condition of the child 
        printf("hello, I am the parent of %d (wc : %d) \n", rc1 , wc1, a);
        int wc2 = waitpid(rc2,NULL,0);
        printf("hello, I am the parent of %d (wc : %d) \n", rc2 , wc2, a);
        int wc3 = waitpid(rc3,NULL,0);
        printf("hello, I am the parent of %d (wc : %d) \n", rc3 , wc3, a);
        int wc4 = waitpid(rc4,NULL,0);
        printf("hello, I am the parent of %d (wc : %d) \n", rc4 , wc4, a);
    }
    return 0;
}
