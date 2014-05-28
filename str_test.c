#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 10

void do_print(char *ss);
int main()
{
    char *test1 = "tes";
    char test2[10] = "test_er";
    char test3[] = "test3";

    do_print(test1);
    printf("#############\n%s\t: %d\t %d\n############\n", test3, sizeof(test3), strlen(test3));
    do_print(test2);
    do_print(test3);

    return 0;
}

void do_print(char *ss)
{
    /*
     *in fact , donot sure how it will work !
     */
    printf("%s:\tsizeof : %d\tstrlen : %d\n", ss, sizeof(ss), strlen(ss));
}
