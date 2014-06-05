#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PAGER "${PAGER:-more}"

int main(int argc, char **argv)
{
    char line[BUFSIZ];
    FILE *fpin, *fpout;

    if(argc != 2)
    {
        printf("usage: %s <s1>\n", *argv);
        exit(0);
    }
    
    if((fpin = fopen(*(argv + 1), "r")) == NULL)
    {
        printf("fopen %s error\n", *(argv + 1));
        exit(0);
    }
    
    if((fpout = popen(PAGER, "w")) == NULL)
    {
        puts("fpout error\n");
        exit(0);
    }
    
    while(fgets(line, BUFSIZ, fpin) != NULL)
    {
        if(fputs(line, fpout) == EOF)
        {
            printf("fputs() error\n");
            exit(-1);
        }  
    }

    if(ferror(fpin))
    {
        printf("fgets error\n");
        exit(0);
    }
    if(pclose(fpout) == -1)
    {
        printf("pclose error\n");
        exit(-1);
    }
    exit(0);
}
