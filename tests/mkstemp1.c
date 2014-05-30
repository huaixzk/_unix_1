#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ss[BUFSIZ];
    int fd;
   fd =  mkstemp(ss);
    getchar();
   
    printf("%S\n",ss);

}
