#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1024

int _strcmp(char *);

int main(void)
{
    char buf[BUFSIZE];
    
    if(fgets(buf, BUFSIZE, stdin) == NULL)
    {
        puts("fgets error\n");
        exit(1);
    }
    if(getenv("PAGER") == NULL)
        printf("get it\n");

    //printf("%s\n", getenv("PAGER"));   
    printf("%s\t%d\n", buf, strlen(buf));
    printf("%s\t%d\n", buf, _strlen(buf));

    return 0;
}

int _strlen(char *buf)
{
    int k = 0;
    while(*buf != '\0')
    {
        buf++;
        k++;
    }
    return k;
}
