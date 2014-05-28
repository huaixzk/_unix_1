#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define DEBUG
#define BUFSIZE 100
int main(int argc, char *argv[])
{
    
  /*fork ;   */
    pid_t pid;
    int n;
    char *r;
    char buf[BUFSIZE]; 
    int *status;

    if((pid = fork()) == 0)
    switch(argc)
    {
        case 1:
            if((fgets(buf, BUFSIZE, stdin)) == NULL)
            {
                printf("fgets() error.\n");
                exit (1);
            }

#ifdef DEBUG
            printf("fgets().\n");
#endif
            buf[strlen(buf)-1] = 0;
            if((execlp(buf, buf, (char *)0)) == -1)          
                {
                    printf("exec error!\t%s\n",buf);
                    exit(0);
                }
#ifdef DEBUG
            printf("here!!\n");
#endif
        case 2:
                exit(0);
    }
        
    if ((waitpid(pid, status, 0)) < 0)
    {
        printf("waitpid error .\n");
        exit(0);
    }
    exit(0);
}

