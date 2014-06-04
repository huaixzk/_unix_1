#include "test.h"
#include "_do_dir_list.h"

int main(int argc, char **argv)
{
 //   char *buf = malloc(sizeof(argv[1]) + sizeof(argv[2]));
    printf("%d\t%d\n", sizeof(argv[1]), sizeof(argv[2]));
    char c;
    printf("%d\t%d\t%d\t%d\n", sizeof(1), sizeof('c'), sizeof("\0"), sizeof("a"));
    //printf("%d\t%d\n", strlen(argv[1]), strlen(argv[2]));
 //   printf("%s\n", _strcat(_strcat(_strcat(buf, argv[1]), "/"), argv[2]));
   // free(buf);
}

