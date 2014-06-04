#include "test.h"

int _do_dir_list(char *file) 
/*
 *_do_dir_list()  need a argv that path
 */
{
    DIR *dp;
    struct dirent *dirp;
    
    if((dp = opendir(file)) == NULL)
    {
        printf("opendir: %s\n", file);
        exit(-1);
    }  
    while((dirp = readdir(dp)) != NULL)
    {
       if(drip->) 
    
    }

}
