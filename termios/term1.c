#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

int main()
{
    struct termios term;
    long vdisable;

    if(isatty(STDIN_FILENO) == 0)
    {
        printf("not a terminal device!\n");
        exit(0);
    }
    
    if((vdisable = fpathconf(STDIN_FILENO, _PC_VDISABLE)) < 0)
    {
        printf("fpathconf error or _POSIX_VDISABLE not in effect\n");
        exit(1);
    }
    
    if(tcgetattr(STDIN_FILENO, &term) < 0)
    {
        printf("tcgetattr error!\n");
        exit(2);
    }
    
    term.c_cc[VINTR] = vdisable; // disable INTR character
    term.c_cc[VEOF] = 2; // EOF is CONTROL-B
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &term) < 0)
    {
        printf("tcsetattr error\n");
        exit(1);
    }
    exit(1);
}
