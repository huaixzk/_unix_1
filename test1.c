#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

void do_list(DIR *dir);

int main(int argc, char *argv[])
{
    DIR *d;
    char *p = "/";
    //struct dirent *dd;

    d = opendir(p);
    do_list(d);
    return 0;

}
