#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
     *test for fgets()
     */
    char st[BUFSIZ];
    char *ts;

    if((fgets(ts, BUFSIZ, stdin)) == NULL)
        printf("error\n");

    printf("#########%s\n",st);
}
