#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define  DO_PRT(_ts) do_part1_x(_ts)

void do_prt(char *st);
void do_part1_x(char *st);

int main(int argc, char *argv[])
{
    char **buf = argv;
    while(*buf != NULL)
    {
        DO_PRT(*buf++);
        DO_PRT("\n");
    
    }
    while(*argv  == NULL)
        DO_PRT("wrong!!\n");
    //printf("Main###%s@@@\n", argv[0]);

}

void do_prt(char *st)
{
    char *buf = st;
   setbuf(stdout, NULL); 
   while(*buf != '\0')
       putc(*buf++, stdout);

}

void do_part1_x(char *st)
{
/*
 *This function may be wrong!!!
 */
    while(*st != '\0')
        write(STDOUT_FILENO, st++, 1);
 //   write(STDOUT_FILENO, st, 1);
 //       printf("##%s@@\n", st);
        
}
