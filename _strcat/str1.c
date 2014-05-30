#include <stdio.h>
#include <stdlib.h>
char *strcat1(char *str1, char *str2);

int main()
{
    char *a = "abc" ;
    char *b = "ABC" ; 
    char p[100] = "test";
    printf("%s\t%s\n", strcat1(p,a), strcat1(p,b));
    return 0;
}
