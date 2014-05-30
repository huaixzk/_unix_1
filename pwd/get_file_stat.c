#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>

#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    if(argc < 2) {  printf("too few arguments:\n"); exit(0);}
    
    int i;
    int fd;
    struct stat buf;
    char *ptr;
    /*
     *switch(argc)
     *{
     *    case 2:
     *    case 3:
     *}
     */
    for(i = 1; i < argc; i++)
    {
        printf("file :%s\n",argv[i]);
        if((lstat(argv[i], &buf)) < 0)
        {
            printf("lstat error :%s\n", argv[i]);
            continue; /*continue to lstat nextgitignore*/
        } 
        
        if(S_ISREG(buf.st_mode))   ptr = "regular";
        else if(S_ISDIR(buf.st_mode))  ptr = "directory";
        else if(S_ISCHR(buf.st_mode))  ptr = "character special";
        else if(S_ISBLK(buf.st_mode))  ptr = "block special";
        else if(S_ISFIFO(buf.st_mode))  ptr = "fifo";
#ifdef S_ISLNK
        else if(S_ISLNK(buf.st_mode)) ptr = "symbolic link";
#endif
#ifdef S_ISSOCK
        else if(S_ISSOCK(buf.st_mode)) ptr = "socket";
#endif
        else    ptr = "unknown mode";
        printf("%s\n", ptr);
    }
    exit (0);



}
