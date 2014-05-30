#include <stdio.h>
#include <stdlib.h>
/*
 *test for mkstemp() function
 */

int main()
{
    if((mkstemp("test.st")) < 0)
    {
        printf("mkstemp error\n");
        exit(1);
    }
    return 0;

}
