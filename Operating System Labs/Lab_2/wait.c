#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){
    int parent_pid = getpid();
    printf("Hello World [pid:%d] \n", parent_pid);

    int rc1 = fork();
    if (rc1 < 0){
        fprintf(stderr, "fork1 failed \n");
        exit(1);
    }
    else if (rc1  == 0){
        printf("hello, I am the child1 (pid : %d) \n", getpid());
        exit(0);
    }

    int rc2 = fork();
    if (rc2 < 0){
        fprintf(stderr, "fork2 failed /n");
        exit(1);
    }
    else if (rc2 == 0){
        printf("hello, I am the child2 (pid : %d) \n", getpid());
        exit(0);
    }
    
    int rc3 = fork();
    if (rc3 <0 ){
        fprintf (stderr, "fork3 failed \n");
        exit(1);
    }
    else if (rc3  == 0){
        printf("hello, I am the child3 (pid : %d) \n", getpid());
        exit(0);
    }

    else {
        int wc1 = waitpid(rc1,NULL,0);
        // wait for rc1 to finish then parent can do whatever
        // also child removed from zombie state 
        // passing &status gives the condition of the child 
        printf("hello, I am the parent %d with child1 (wc1 : %d) \n", parent_pid, wc1);

        int wc2 = waitpid(rc2,NULL,0);
        printf("hello, I am the parent %d with child2 (wc2 : %d) \n", parent_pid, wc2);      
        
        int wc3 = waitpid(rc3,NULL,0);
        printf("hello, I am the parent %d with child3 (wc3 : %d) \n", parent_pid, wc3);  
    }
    return 0;
}
