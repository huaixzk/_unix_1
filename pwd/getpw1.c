#include <stdio.h>
#include <pwd.h>
#include <stdlib.h>
#include "_getpw.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        /* Test :
         *char *a = "abcdef";
         *char b[10]= "abcdef";
         *printf("######%d\n",_str_cmp(a,b));
         */
    printf("usage: %s <argv1> <argv2>\n",argv[0]);
    exit(0);
    }
   
    int i;
    struct passwd *pd;
    
    for(i = 1; i < argc; i++)
    {
        switch(_test_user(argv[i]))
        {
            case 0: 
                pd = _getpwnam(argv[i]);
        /*printf("###%s\t%d\n", pd->pw_name, pd->pw_uid);*/
                break;  // holy shit !!!!
            case 1:
                pd = _getpwuid(atoi(argv[i]));
 //       printf("###%s\t%d\n", pd->pw_name, pd->pw_uid);
                break;
            default:
                pd = NULL;
                break;
        }
        if(pd == NULL)
        {
            printf("invald username or uid\n");
            exit(1);
        }
        printf("###%s\t%d\n", pd->pw_name, pd->pw_uid);
        printf("argv[%d]:  %s\thome:  %s\tshell:  %s\n", i, argv[i], pd->pw_dir, pd->pw_shell);

    }
    
    return 0;

}
