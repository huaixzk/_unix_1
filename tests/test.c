#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <string.h>

char b[] = "ABCabc";

int main()
{
    int a;
    
    if((a = open("test.txt", O_RDWR|O_CREAT,S_IRUSR|S_IWUSR)) < 0)
    {
        printf("open error : \n");
        perror(0);
    }
    
 printf("file des : %d\n", a);   
    if((write(a, b, strlen(b))) != strlen(b))
    {
        printf("write error :\n");
        exit(0);
    }
    printf("sizeof b : %d\t strlen :%d\n", sizeof(b), strlen(b));
    close(a);
    return 0;
}
