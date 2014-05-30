#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST

int main()
{
    time_t tt;
    struct tm *tm;
#ifdef TEST   
    tt = time(NULL);
#else 
   time(&tt);
#endif
    if((tm = localtime(&tt)) == NULL)
    {
        printf("localtime() error\n");
        exit(1);
    }
    
    printf("year: %d\tmonth: %d\tday: %d\thour: %d\tmin: %d\tsec: %d\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
    printf("Day of Year : %d\n",tm->tm_yday);

    printf("DATE: %s",ctime(&tt));
    return 0;
}
