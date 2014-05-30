#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

int main()
{
    char name[L_tmpnam];
    char line[BUFSIZE];
    FILE *fp;    

    printf("%s\n",tmpnam(NULL)); // first temp name

    tmpnam(name);
    printf("%s\n",name);

    if((fp = tmpfile()) == NULL)
        printf("tmpfile error.\n");
    
    fputs("test , just for test\n", fp);
    rewind(fp);
    if((fgets(line, BUFSIZE, fp)) == NULL)
        printf("fgets error\n");
    fputs(line, stdout);
    getchar();
    exit(0);
}
