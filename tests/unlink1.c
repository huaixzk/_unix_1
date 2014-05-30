#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        printf("usage: %s <file>\n",argv[0]);
        exit (0);
    }
    
    int i;
    struct stat buf;
    for(i = 1; i <argc ; i++)
    {
        if((stat(argv[i], &buf)) < 0)
        {
            printf("stat error\n");
            exit(1);
        }
        
        printf("file : %s\tnlink: %d\n", argv[i], buf.st_nlink);
        if((unlink(argv[i])) < 0)
        {
            printf("unlink error \n");
            exit(0);
        }
        
    }
    return 0;
}
