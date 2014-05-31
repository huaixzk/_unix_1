#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("pid:  %d\tppid  %d\tuid: %d\teuid: %d\tgid: %d\tegid: %d\n", getpid(), getppid(), getuid(), geteuid(), getgid(), getegid());

}
