#include <stdio.h>
#include <stdlib.h>
/*
 *just for test a[]  char *b
 */
int main()
{
    char a[BUFSIZ] = "abc";
    char *b = a;

    while(*a == *b++)
    {
    printf("a: #%c$\tb: #%c$\n",*a,*b);
    printf("a: %d\tb: %d\tbufsize: %d\n", sizeof(a), sizeof(b),BUFSIZ);
 //   a++;
    a =a +1;
    }
    exit(0);
}
