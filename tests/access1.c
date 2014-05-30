#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int result;
    
    if((access("test1", F_OK)) != -1)
        printf("File Exises.\n");
    while(!(access("test1", R_OK)))
      {
          printf("read ok!\n");
          break;
      }
    if((access("test1", W_OK)) != -1)
        printf("write ok!\n");
    if((access("test2", X_OK)) != -1)
        printf("Exec ok\n");
    return 0;
}
