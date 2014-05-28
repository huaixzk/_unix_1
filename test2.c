#include <stdio.h>
#include <dirent.h>
#include <sys/types.h> 

void do_list(DIR * dir)
{
    struct dirent *pp;

    while((pp = readdir(dir)) != NULL)

    printf("%s\n",pp->d_name);

}
