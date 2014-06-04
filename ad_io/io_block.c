#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

#define BUFSIZE 10000
void set_blk(int fd, int flags);
void clr_blk(int fd, int flags);
char buf[BUFSIZE];

int main(void)
{
    int ntowrite, nwrite;
    char *ptr;
    
    ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
    fprintf(stderr, "read %d bytes\n",ntowrite);

    set_blk(STDOUT_FILENO, O_NONBLOCK);

    for(ptr = buf; ntowrite > 0; )
    {
        errno = 0;
        nwrite = write(STDOUT_FILENO, ptr, ntowrite);
        fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);
        if(nwrite > 0)
        {
            ptr += nwrite;
            ntowrite -= nwrite;
        }
    }

    clr_blk(STDOUT_FILENO, O_NONBLOCK);
    exit(0);

}

void set_blk(int fd, int flags)
{
    int val;

    if((val = fcntl(fd, F_GETFL, 0)) < 0)
    {
        printf("error fcntl get flags\n");
        exit(-1);
    }

    val |= flags;

    if(fcntl(fd, F_SETFL,val) < 0)
    {
        printf("error fcntl  set blk\n");
        exit(-1);
    }
}

void clr_blk(int fd, int flags)
{
    int val;
    
    if((val = fcntl(fd, F_GETFL, 0)) < 0)
    {
        printf("error fcntl get flags clr_blk\n");
        exit(-1);
    }

    val &= -flags;

    if(fcntl(fd, F_SETFL, val) < 0)
    {
        printf("error fcntl set flags clr_blk\n");
        exit(-1);
    }
}
