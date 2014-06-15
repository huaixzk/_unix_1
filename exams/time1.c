#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    struct tm *tm;
    struct tm *tm0;
    char *s = malloc(50);

    time(&t);
    tm = localtime(&t);
    strftime(s, sizeof(s), "%d/%m/%y\t%E", tm);
    printf("%s\n", asctime(tm));
    printf("%s\n", ctime(&t));
    printf("%s\n", s);
 //   printf("%s\n", ctime(&(mktime(tm))));
    if(!strcmp(asctime(tm), ctime(&t)))
    printf("same!!\n");

}
