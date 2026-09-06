#include<stdio.h> //used for printf(), frpintf()
#include<stdlib.h> //used ofr exit()
#include<unistd.h> //used for fork(), wait(), getpid()

int main (int argc, char* argv[]){
    int a = getpid();
    printf("[pid:%d] - Hello Students \n", a);

    int rc =fork();
    if (rc <0){
        fprintf(stderr, "fork failed \n");
        exit(1);
    }
    else if (rc == 0){
        printf("-------------------------------\n");
        printf("[pid:%d] I am the child. My rc = [%d] \n", getpid(), rc);
        printf("-------------------------------\n");
        sleep(1);
    }
    else{
        printf(" [pid:%d] I am the parent. My rc = [%d] \n", getpid(), rc);
        sleep(100);
    }
    return 0;
}
