#include <stdio.h>
#include <stdlib.h>

int i =0;
char *str1 = "hello!";
void do_i(int j);
void do_do(char *st1, char *st2);

int main()
{
    i = 1;

    int j = 2;
    char *str3 ="test!";   
    char *str2 = "linux!!";
    str1 = str3;
 //   str1 = "\0";
    printf("test:%s\n",str1);
    //*str1 =  '\0';
    do_i(j);
 //   str1 = str2;
    do_do(str1, str2);
    printf("i: %d\tstr1: %s\tj: %d\tstr2: %s\n", i, str1, j, str2);
   return 0;
}


void do_do(char *st1, char *st2)
{
    i =4;
    printf("before :st1: %s \tst2: %s\n", st1, st2);
    char *t;
    t = st1;
    st1 = st2;
    st2 = t;
    st1 = "never";
    printf("after :st1: %s\tst2: %s\n", st1, st2);
    str1 = "gotch!";
}
void do_i(int j)
{
    j = 100;

}
