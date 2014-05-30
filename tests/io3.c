#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 100

int main()
{
    //char *ch;
    char ch[BUFSIZE];
    while((fgets(ch, BUFSIZE, stdin)) != NULL)
        if((fputs(ch, stdout)) == EOF )
           printf("puts error."); 

}
