#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%s\n", getenv("HOME"));
    printf("%s\n", getenv("HOME"));
    printf("%s\n", getenv("PWD"));
    
    extern char **environ;
    /*
     *so we can do this to fix it.
     */

 //   char *en[] = *environ;
        int i = 0;
    while(environ[i] != NULL)
    {
    printf("%s\t%d\n", environ[i],i);
    i++;
    printf("i:\t%d\n",i);
    }
    printf("%s\n", getenv("PWD")); // i think this well fail

/*
 *Reason :environ ++ will go to the end of the **environ. So if use secure_getenv() will get null
 *            else seg fault.
 */


}
