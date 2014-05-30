#include <stdio.h>
#include <stdlib.h>

int a =2;
int b;
char *str1;
char *str2 = "abcsss";

int main()
{
    //int b;
    b =a;
    
    str1 = str2;
    str1++;
   // *str2 = 'a';
    //str2[0] = '\0';
    a = 3;
    printf("a: %d\tb: %d\n", a, b);
    printf("str1: %s\tstr2: %s\n", str1, str2);

}
