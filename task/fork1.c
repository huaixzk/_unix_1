#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

//#define DEBUG
#define BUFSIZE 100

char *n_0(char *st);

int main(int argc, char *argv[])
{
    
  /*fork ;   */
    pid_t pid;
    int n;
    char *r;
    char buf[BUFSIZE]; 
    int *status;
    
    char *ex;

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
            /*for debug*/
            /*
             *for(int i = 0; buf[i] != 0; i++)
             *    printf("#%c$", buf[i]);
             */
            buf[strlen(buf)-1] = '\0';
            printf("exec: %s\n",buf);
            
            if((execlp(buf, buf, (char *)0)) == -1)          
                {
                    printf("exec error!\t%s\n",buf);
                    exit(0);
                }
#ifdef DEBUG
            printf("here!!\n");
#endif
            break;
        case 2:
            //ex = n_0(argv[1]);
            if((execlp(argv[1], argv[1], (char *)0))==-1)
            {
                printf("execvp error!!\n");
                exit(0);
            }
            break;
        default:
            printf("usage : %s [arg1]\n", argv[0]);
            exit(0);
    }
        
    if ((waitpid(-1, status, 0)) != pid)
    {
        printf("waitpid error .\n%s\n",status);
        exit(0);
    }
    exit(0);
}

char *n_0(char *st)
{
    char *buf;
    buf = st;
    while(*st++ != '\n')
    ;
    *st = 0;
    return buf;
}

