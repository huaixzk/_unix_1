#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 1024

int main()
{
    int rtn;
    char buf[BUFSIZE];
    

    while((rtn = read(STDIN_FILENO, buf, BUFSIZE)) != 0)
        /*
         *if(buf == "EOF")
         *   {
         *       printf("done . quitting ....\n");
         *        exit(0);
         *   }
         */
      if((write(STDOUT_FILENO, buf, rtn)) != rtn)
              printf("error write. \n");
              

              if(rtn < 0)
              printf("read error.\n");
    exit(0);

}
