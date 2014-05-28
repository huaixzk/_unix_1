#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;

    while((c=getchar()) != EOF)
        if((putchar(c)) == EOF)
            printf("error putchar .\n");
    return 0;


}
