#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define DEBUG

void test_for_write(int fd, char *ss);

int main(int argc, char *argv[])
{
    int fd;
    
    if(argc != 2)
    {
        printf("error : too few arguments .\n");
        exit (0);
    }

    if((fd = open(argv[1], O_RDWR|O_APPEND|O_CREAT, S_IWUSR|S_IRUSR)) == -1)
    {
        printf("open error : %s\n",argv[1]);
        exit(1);
    }
#ifdef DEBUG
    printf("file desc: %d\n",fd);
#endif
    int t;
    if((t = dup(fd)) < 0)
    {
        perror("dup failed");
        exit(1);
    }
#ifdef DEBUG
    printf("file des :%d\n",t);
#endif
    test_for_write(fd,"test for fd!!\n");

    test_for_write(t,"test for t!!\n");

    close(t);
    close(fd);
    return(0);
}

void test_for_write(int fd, char *ss)
{
    if((write(fd, ss, strlen(ss))) != strlen(ss))
    {
        printf("write error.\n");
        exit(1);
    }   
#ifdef DEBUG
    printf("ss :%s\tpointer size : %d\tstrlen : %d\n", ss, sizeof(ss), strlen(ss));
#endif
}
