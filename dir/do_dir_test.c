#include "_do_dir_list.h"
#include "test.h"

int main(int argc, char **argv)
{
    if(argc <2 )
    {
        printf("usage : %s [argv1 ....]\n", *argv);
        exit(0);
    }
    
    while(*++argv != NULL)
    {
        if(_do_dir_list(*argv) == 0)
        {
            printf("_do_dir_list [ERROR]: %s\n", *argv);
                    perror("_do_dir_list");
                    exit(-1);
        }
    
    }
    return 0;
}
