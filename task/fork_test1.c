#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int m = 4, n = 5;

int main()
{
    int a;
    int b = 2;
    
    pid_t pid;
    int status;
    printf("test11 !!\t%d\n", getpid());
    if((pid = fork()) < 0)
    {
        printf("fork error\n");
        exit(1);
    }
    if(pid == 0)
    {
        a = 1;
        printf("child :m: %d\tn: %d\tb: %d\ta: %d\n", m, n, b, a);
        
    }
    else {
    sleep(2);


    printf("test !!\t%d\n", getpid());
        }
     wait(&status);
    printf("status: %d\n",status);
}
