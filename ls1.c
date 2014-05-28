#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

//#define DEBUG

void donothing(void);
void do_dir_list(DIR *d);

int main(int argc, char *argv[])
{
    DIR *dir;
    //DIR **dr;
    int i;
    if(argc == 1)
        {
            if((dir = opendir(".")) == NULL)
        {
            printf("error opendir .\n");
            exit(1);
        }
 //       printf("got here!!\n");
        do_dir_list(dir);
   //     printf("test");
        }
    /*
     *{
     *    struct dirent *pp;
     *    pp = readdir(dir);
     *    printf("%s\n",pp->d_name);
     *
     *}
     */
 //       do_dir_list(dir);
     else 
         if(argc == 2)
    {
       if ((dir = opendir(argv[1])) == NULL)
           printf("error opendir %s\n",argv[1]);
       else 
           do_dir_list(dir);
    }
    else  
        printf("$$$$$$$$$$$$$$$$$$$$$$\n");
        for(i = 1; i < argc; i++)
        {
            if((dir = opendir(argv[i])) == NULL)
            {
                printf("error open dir : %s\n",argv[i]);
                exit(1);
            }
            else 

                do_dir_list(dir);
            printf("######################\n");
        }
    
}

void dothing(void)
{
    // do nothing
}

void do_dir_list(DIR *d)
{
    struct dirent *dd;
   // int i;
    
    while((dd = readdir(d)) != NULL)
    if(dd->d_name[0] != '.' && dd->d_name[1] !='\0') //|| dd->d_name != "..\0")
    {
 //       printf("got here!!\n");
    printf("%s\t",dd->d_name);
    }
    printf("\n");
    closedir(d);
}
