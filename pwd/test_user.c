#include <stdio.h>
#include <stdlib.h>
#include "_getpw.h"

/*
 *test for the function _test_user(char *ss);
 */

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        printf("usage:  %s <arg1> <arg2>\n",argv[0]);
        exit(1);
        /*
         *donothingV;
         */
    }


    /*int i;*/
    for(int i = 1; i < argc; i++)
    {
        printf("_test_user:  %d\n", _test_user(argv[i]));
        
    }

    return 0;

}
