#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void do_prt(char *st);

int main()
{
    pid_t pid;

    if((pid = fork()) < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if(pid == 0)
    {
        do_prt("child: abcdefghijklmnokq\n");
    }
    else 
    {
        do_prt("parent: rstuvwxyz123456789\n");
    }
    exit(0);
}

void do_prt(char *st)
{
    char *buf = st;
   setbuf(stdout, NULL); 
   while(*buf != '\0')
       putc(*buf++, stdout);

}
