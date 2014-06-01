#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <pwd.h>

static void do_sig(int);

int main(void)
{
    struct passwd *ptr;
    signal(SIGALRM, do_sig);
    alarm(1);
    while(1)
    {
       if((ptr = getpwnam("root")) == NULL) 
       {
            printf("getpwnam error\n");
            exit(1);
       }
       if(strcmp(ptr->pw_name, "root") != 0)
            printf("return value corrupted ! pw_name = %s\n", ptr->pw_name);
    }
}

static void do_sig(int signo)
{
    struct passwd *test_pw;

    printf("in signal handler !!\n");
    if(( test_pw = getpwnam("git")) != NULL)
    {
        printf("getpwnam signal error!\n");
        exit(1);
    }
    alarm(1);
    return ;
}
