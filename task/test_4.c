#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void get_env(char **env);
extern char **environ;

int main()
{
    printf("HOME: %s\n", getenv("HOME"));
   get_env(environ);
   if(*environ == NULL)
        puts("wrong!!\n");
    printf("HOME: %s\n", getenv("PWD"));
    exit(0);   
}

void get_env(char **env)
{
    /*
     *char **buf = env;
     *while(*env != NULL)
     *{
     *    printf("%s\n", *env++);
     *    *env++;
     *}
     */
    /*
     *while(puts(*buf++) != 0)
     *    ;
     */

}
