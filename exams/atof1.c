#include <stdio.h>
#include <stdlib.h>
#define DEBUG

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("usage: %s <str for float>\n", *argv);
        return;
    }
    
    else
#ifdef DEBUG
        printf("%s\n", *(argv + 1));
#endif
        printf("%f\n", atof(*(argv + 1)));
}
