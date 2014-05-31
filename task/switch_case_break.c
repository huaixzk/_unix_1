#include <stdio.h>
#include <stdlib.h>
/*
 *test for swatch() {case 1: ... ;case 2: ...;}
 *break
 */
void do_hello(char *st);

int main(int argc, char **argv)
{
    /*
     *argc = 0;           test if argc is changable ; it can !! var
     */
    switch(argc)
    {
        case 0: 
            /*will never get here !!*/
            /*if you change the argc .*/
            printf("get here!! case 0:\n");
            break;
            exit(0);  // will never get here !!
        case 1:
            printf("get here!! case 1:\n");
            /*no break test;*/
            do_hello("case 1");
            break;
        case 2:
            printf("get here!! case 2:\n");
            do_hello("case 2");
            break;
        default: 
            do_hello("\n have fun !!");
    }
    return 0;

}

void do_hello(char *st)
{
    printf("hello, %s\n",st);
}
