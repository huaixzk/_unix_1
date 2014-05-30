#include <stdio.h>
#include <stdlib.h>
 /*
  *for character input/output
  */
int main()
{
    char c;

    while((c = fgetc(stdin)) != EOF)
        if((fputc(c, stdout)) == EOF)
            printf("fputc error\n");

    exit (0);
}
