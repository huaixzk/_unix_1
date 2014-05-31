#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void pr_exit(int status);

int main()
{
    pid_t pid;
    int status;

    if((pid = fork()) < 0)
        perror("fork1 error.");
    else if(pid == 0)
        exit(7);

    if(wait(&status) != pid)
        perror("wait1 error");
    pr_exit(status);

    if((pid = fork()) <  0)
        perror("fork2 error");
    else if(pid == 0)
        abort();

    if(wait(&status) != pid)
        perror("wait2 error");
    pr_exit(status);

    if((pid = fork()) < 0)
        perror("fork3 error");
    else if(pid == 0)
        status /= 0;

    if(wait(&status) != pid)
        perror("wait3 error");
    pr_exit(status);

    exit(0);
}

void pr_exit(status)
{
    if(WIFEXITED(status))
        printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    else if(WIFSIGNALED(status))
        printf("abnormal termination, signal number = %d%s\n", 
                WTERMSIG(status),
#ifdef WCOREDUMP
                WCOREDUMP(status) ? " (core file.generated)":"");
#else
    "");
#endif
    else if(WIFSTOPPED(status))
        printf("child stopped , signal number = %d\n", WSTOPSIG(status));
}
