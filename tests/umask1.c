#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    umask(000);
    if((creat("test",S_IRWXU|S_IRWXG|S_IRWXO)) < 0)
        printf("fail to creat\n");
    umask(666);
    if((creat("test0",S_IRWXU|S_IRWXG|S_IRWXO)) < 0)
        printf("fail to creat\n");
    return 0;
}

