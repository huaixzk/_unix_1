#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define BUFSIZE 2

void do_test(int fd, char *ss);
void do_read_puts(int fd);
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("too few argument:\n");
 //       if(argc == 3)
 //           printf("%s\t%s\n", argv[1], argv[2]);
        exit(0);
    }
    
    int dup1;
    int dup2;
    if((dup1 = fcntl(atoi(argv[1]),F_DUPFD, 0)) < 0)
    {
        printf("fcntl dunpfd failed : \n");
        exit(1);
    }

    printf("file desc: %s\t%d\tdup1\t%d\n", argv[1],atoi(argv[1]), dup1);
    do_test(dup1,"test_for_test\n");
    if((dup2 = dup(dup1)) <0)
    {
        printf("dup failed :\n");
        exit(1);
    }
    do_read_puts(dup2);
    return 0;
}
void do_test(int fd, char *ss)
{
    if((write(fd, ss, strlen(ss))) != strlen(ss))
    {
        printf("write test errror:\n");
        exit(1);
    }
}

void do_read_puts(int fd)
{
    char buf[BUFSIZE];

    while((read(fd, buf, BUFSIZE)) != 1)   
    {
        puts(buf);
        
    }
    exit (0);
}
