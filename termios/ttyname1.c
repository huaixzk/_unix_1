#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#include "_ttyname.h"

#define TTYNAME(int) _ttyname(int)

int main(void)
{
    printf("fd 0:  %s\n", isatty(0) ? TTYNAME(0) : "not a tty");
    printf("fd 1:  %s\n", isatty(1) ? TTYNAME(1) : "not a tty");
    printf("fd 2:  %s\n", isatty(1) ? TTYNAME(2) : "not a tty");


}
