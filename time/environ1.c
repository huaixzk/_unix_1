#include <stdio.h>
#include <stdlib.h>

    extern char **environ;
int main(int argc, char *argv[])
{
   // printf("NULL??###%c$$$\n",argv[argc]);
    
    while(*environ != NULL)
    printf("%s\n", *environ++);
    for(int i = 0; i <18; i++)
        environ--;
    printf("%s\n", secure_getenv("HOME"));
    printf("%s\n", secure_getenv("PWD"));

}
