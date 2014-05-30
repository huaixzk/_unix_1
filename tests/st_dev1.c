#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("usage : %s <device | file>\n",argv[0]);
        return 0;
    }
    int i;
    struct stat buf;
    for(i =1; i < argc; i++)
    {
        if((lstat(argv[i], &buf)) < 0)
        {
            printf("lstat error\n");
            continue;
        }
        printf("dev = %d/%d\n", major(buf.st_dev), minor(buf.st_dev));
        if(S_ISBLK(buf.st_mode) || S_ISCHR(buf.st_mode))
        printf("%s\trdev :\tmajor: %d\tminor : %d\n", (S_ISBLK(buf.st_mode))?"block":"character", major(buf.st_rdev), minor(buf.st_rdev));
    
    }
    return 0;
}
