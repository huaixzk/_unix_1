#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;

    while((c = getc(stdin)) != EOF)
        if((putc(c, stdout)) == EOF)
            printf("putc error !\n");
    if(ferror(stdin))
    printf("input error\n");
    exit(0);
}
