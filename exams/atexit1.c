#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void a()
{
puts("got a \n");
}

void b()
{
    puts("got b\n");
}

int main()
{
    atexit(a);
    atexit(b);
 //   abort();
 //   return 0;
 //   exit(EXIT_SUCCESS);
    _exit(0);
}
