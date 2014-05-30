#include <stdio.h>

/*
 *test for ctermid .
 */

int main()
{
    /*test1   */
    char *ss ;
 //   printf("ctermid_r : %s\n",ctermid_r());
    printf("ctermid : %s\t%s\n", ctermid(ss), ss);
    return 0;
}
