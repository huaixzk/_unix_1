#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <termios.h>
#include <string.h>
#include <limits.h>

#define DEV "/dev/"
#define DEVLEN sizeof(DEV)-1

#define DEBUG

char *_ttyname(int fd)
{
    struct stat fdstat, devstat;
    DIR *dp;
    struct dirent *dirp;
    static char pathname[_POSIX_PATH_MAX + 1];
    char *rval = NULL;

    if(isatty(fd) == 0)
        return(NULL);
    if(fstat(fd, &fdstat) < 0)
        return(NULL);
    if(S_ISCHR(fdstat.st_mode) == 0)
        return(NULL);

    strcpy(pathname, DEV);
    if((dp = opendir(DEV)) == NULL)
        return(NULL);

    while((dirp = readdir(dp)) != NULL)
    {
        if(dirp->d_ino != fdstat.st_ino)
        {
            printf("Dir: %s\n", dirp->d_name);//fdstat.st_name);
            continue;
        }
#ifdef DEBUG
        printf("found!!\n");
#endif
    strncpy(pathname + DEVLEN, dirp->d_name, _POSIX_PATH_MAX - DEVLEN);
    if(stat(pathname, &devstat) < 0)
        continue;
    if(devstat.st_ino == fdstat.st_ino && devstat.st_dev == fdstat.st_dev)
    {
        rval = pathname;
        break;
    }
    }
    closedir(dp);
    return(rval);
}

struct dirent *_do_dir_list(char *path)
{
    DIR *d;
    struct dirent *dir;
    if((d = opendir(path)) != NULL)
        while((dir = readdir(d) != NULL))
        return dir;


}
