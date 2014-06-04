#include "test.h"

int main(int argc, char **argv)
{
    DIR *dp;
    struct dirent *dirp;

    if(argc <2)
    {
        printf("usage:\n");
        exit(1);
    }
    while(*++argv != NULL)
    {
        if((dp = opendir(*argv)) == NULL)
            {   perror("opendir"); exit(-1);}
        while((dirp = readdir(dp)) != NULL)
            if(strcmp(dirp->d_name, ".."))
            printf("-->%s\t%d\n", dirp->d_name, dirp->d_type);
    }
    return 0;
}

/*
 *int _do_str_cmp(char *str1,)
 *{
 *
 *
 *
 *}
 */

int _strcmp(char *str1, char *str2)
{
    int n = 0;
    while((*str1++ == *str2++) != '\0')
    {
            return *str2 - *str1;
    }
    /*
     *if(_strlen(str1) == n)
     */
    /*
     *else
     *    return n;
     */
}

int _strlen(char *str)
{
    int n = 0;
    while(*str++ != '\0')
        n++;
    return n;
}
