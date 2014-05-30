#include <stdio.h>
#include <stdlib.h>
#include "_strcat.h"
/*
 *test for p to p _strcat
 */
#define BUFSIZE 100
int main()
{
    char *a ="abc";
    char *b = "ABC";
    char buf[99]="\0";
    char *test;
    char c[10];
    //buf = a;
    printf("$$%c$$\n",buf[0]);
    _strcat(buf,a);
    _strcat(c,a);
    printf("a: %s\tb: %s\t strcat : %s\n",a, b, _strcat(buf,b));
    return 0;
}
