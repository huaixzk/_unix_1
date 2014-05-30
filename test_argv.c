#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc ==1)
    exit(1);

    int i, j;
    for(i = 1; i < argc; i++)
    {
        printf("%s\n",argv[i]);
        
        while(argv[i][j] != '\0')
            {
                printf("%d\t%c\n", argv[i][j], argv[i][j]);
                j++;
            }
    
    
    }


}
