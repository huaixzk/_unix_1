#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 1024

int main()
{
    int rtn;
    char buf[BUFSIZE];
    
    int op;

   if((op = open("test.txt", O_RDWR|O_CREAT, S_IRWXU|S_IRWXO|S_IRWXG) == -1)) 
       printf("open error. \n");

    while((rtn = read(STDIN_FILENO, buf, BUFSIZE)) != 0)
        /*
         *if(buf == "EOF")
         *   {
         *       printf("done . quitting ....\n");
         *        exit(0);
         *   }
         */
      if((write(op, buf, rtn)) != rtn)
              printf("error write. \n");
         close(op);     

              if(rtn < 0)
              printf("read error.\n");
    exit(0);

}
