#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *buf = malloc(10);
#ifdef SETZERO
    memset(buf, 0, sizeof(10));
#endif

    char *test = calloc(2,10);
    printf("%d\t%d\n", strlen(buf), strlen(test));

    free(buf);
    free(test);
}
