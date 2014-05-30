#include <stdio.h>
#include <stdlib.h>
//#include <curses.h>  no need
//#define DEBUG
#ifdef DEBUG 
#undef DEBUG
#endif
#define BUFSIZE 1024
/*
 *test for strcat1.c. As libcat1.so 
 */
#include "_strcat.h"

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        /*
         *for argc ==1 func
         */
        printf("#### choice:\n1 > : Anykey to continue;\n2 > : Enter 'q' to Quit .");
        char c = getc(stdin);
        if(c == 'q')
        {
            printf("Well then ; quiting ...\n");
            exit(0);
        }
       getchar();  // for get EOF the input  
        char buf[BUFSIZE];
        char st1[BUFSIZE];
        char st2[BUFSIZE];
        char st3[BUFSIZE];
        printf("st1 :\t");
        /*gets(st1);*/
        fgets(st1, BUFSIZE, stdin);
      //  printf("$$$$$$$%s\n",st1);
        //char *t = "test"; /*strcat1(st1, NULL);*/
        printf("st2 :\t");
        /*gets(st2);*/
        fgets(st2, BUFSIZE, stdin);
        printf("st3 :\t");
        /*gets(st3);*/
        fgets(st3, BUFSIZE, stdin);

        n_0(st1);  
        n_0(st2);
        n_0(st3);

#ifdef DEBUG
        printf("st1:%sst2:%sst3:%s\n", st1, st2, st3);
        printf("$$$$$$%c#######%c$$$$$",st1[2],st1[3]); // test the strcat1 return ?= str1
#endif
        _strcat(st1, st2);
        //strcat1(buf, st2);
        printf("st1: %s\nst2: %s\n", st1, st2);
        printf("s12 :%s\ts13: %s\n", st1, _strcat(st1, st3));

#ifdef DEBUG
        char *t = st1;
        while(*t == '\n')
        {
            printf("got !!\n");
            t++;
        }
        printf("debug: st1 :$$$$$$%c###%s###",st1[2],st1);
#endif
        exit(1);
    }
    if(argc == 2)
    {
        printf("want to print %s ?\n%s\n", argv[1],argv[1]);
        exit(0);
    }

    if(argc > 2)
    {
   int i = 2;
    for(; i < argc; i++) 
    {
        _strcat(argv[1], argv[i]);
        printf("argv[%d]: %s\targv[1]: %s\n", i, argv[i], argv[1]);       
    }  
        return 0;
    }
    
}
