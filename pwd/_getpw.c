#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>

struct passwd *_getpwuid(uid_t uid)
{
    struct passwd *pwd;
    setpwent();
    while((pwd = getpwent()) != NULL)
    {
        if(pwd->pw_uid == uid)
            break;
    }
    
    endpwent();
    return pwd;
}

struct passwd *_getpwnam(char *name)
{
    struct passwd *pwd;
    setpwent();
        while((pwd = getpwent()) != NULL)
        {
            if((_str_cmp(name, pwd->pw_name)) == 0)
                break;
        }
    endpwent();
    return pwd;
}

int _str_cmp(char *str1, char *str2)
{
    int k = 0, j = 0;
    while(*str1 != '\0')
    {
        if(*str1++ == *str2++)
        j++;
    k++;
    }
    if(k == j)
    { 
 //   printf("will return 0\n");
        return 0;
    }
    /*printf("will return %d\n",k);*/
    return k;
}

int _test_user(char *ss)
{
    if(*ss >= 'a' && *ss <= 'z')
        /*
         *for linux users ; the username must be started with a lower letter. so we can tell if argv[i] a username or not 
         */
        return 0;
    else if(*ss >= '0' && *ss <= '9')
        return 1;
    else
        return *ss;
        /*
         *printf("invaild username!\t check if it's right??\n ");   
         *exit(1);
         */
    
    /*
     *else  the ss contonted by argv[i] is uid (uid_t ;int)
     */
}
