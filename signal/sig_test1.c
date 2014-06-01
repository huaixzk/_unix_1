#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sig_test(int);

int main(void)
{
    if(signal(SIGUSR1, sig_test) == SIG_ERR)
    {
        printf("cannot catch SIGUSR1\n");
        exit(EXIT_FAILURE);
    }
    if(signal(SIGUSR2, sig_test) == SIG_ERR)
    {
        printf("cannot catch SIGUSR2\n");
        exit(EXIT_FAILURE);
    }
    for(;;)
        pause();

}

static void sig_test(int signo)
{
    if(signo == SIGUSR1)   
        printf("received SIGUSR1\n");
    else if(signo == SIGUSR2)
        printf("received SIGUSR2\n");
    else
        printf("received SIGNAL : %d\n", signo);
    
   return ;
    

}
