#include "test.h"
char *doo(char *str1, char *str2);
int main(int argc, char **argv)
{
    if(argc != 3)
    {
        printf("usage XX\n");
        exit(0);
    }
 char *buf = malloc(sizeof(argv[1] + sizeof(argv[2] +1)));
printf("%s\n", strcat(strcat(strcat(buf, argv[1]), "/"), argv[2]));
free(buf);
return 0;


}

char *doo(char *str1, char *str2)
{
    char buf[strlen(str1) + strlen(str2) + 2];
 //   while(str)
    printf("argv1 : %s\tbuf: %s\n", str1, buf);
    while(*str1++ == '\0')
        ;
        *str1 = '/';
    while((*++str1 = *str2++) != '\0')
        ;
    printf("%s\n",buf);


}
