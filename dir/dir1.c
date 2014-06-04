#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    struct dirent **namelist;
    int n;

    if(argc < 2)
    {
        printf("usage : XX <arg1> <arg2>\n");
        exit(1);
    }
    while(*++argv != NULL)
    {
    n = scandir(*argv, &namelist, NULL, alphasort);
    printf("dir numbers :%d\n",n);
    if(n < 0)
        perror("scandir");
    else {
        while(n--)
        {
            printf("%s\n", namelist[n]->d_name);
            free(namelist[n]);
        }
        free(namelist);
    }
    }
}
