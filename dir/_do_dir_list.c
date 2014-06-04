#include "test.h"
#include "_do_dir_list.h"
#undef DEBUG
#define _DO_STR_LEN(char ) strlen(char )

/*
 *int _do_dir_list(char *file)
 *{
 *    int n = 0;
 *    DIR *dp;
 *    struct dirent *dirp;
 *    char *test = file;   
 *    if((dp = opendir(file)) == NULL)
 *    {
 *        printf("opendir  %s error\n", file);
 *        exit(-1);
 *    }
 *    while((dirp = readdir(dp)) != NULL)
 *    {
 *
 *            if(_do_str_cmp(dirp->d_name, ".") && _do_str_cmp(dirp->d_name, ".."))
 *        printf("-->%s:  %s\n",file, dirp->d_name);
 *
 *        //printf("###%d$$$type: %d\n", , dirp->d_type);
 *        if(dirp->d_type == DT_DIR && strcmp(dirp->d_name, ".") && strcmp(dirp->d_name, ".."))
 *        {
 *
 *        //char *test = file;
 *        [>while(*test != '\0')<]
 *                [>test++;<]
 *        [>if(*--test == '/')<]
 *        [>{<]
 * //           printf("get /\n");
 *            [>char *buf = malloc(strlen(file) + strlen(dirp->d_name) + 1);<]
 *                [>_do_dir_list(_strcat(_strcat(buf, file), dirp->d_name));<]
 *            [>free(buf);<]
 *            [>}<]
 *            [>//puts("got!!!\n");<]
 *            [>else<]
 *            [>{<]
 *            //_do_dir_list(_file_to_path(file, dirp->d_name));   no use
 *              //  buf = malloc(strlen(file) + strlen(dirp->d_name) + 2);
 *                _do_dir_list(_strcat(_strcat(_strcat(buf, file), "/"), dirp->d_name));
 *        //    }
 *        }
 *        n++;
 *#ifdef DEUBG
 *        printf("dirent numbers : %d\n", n);
 *#endif
 *    }
 *    return n;
 *}
 *
 */
char *_file_to_path(char *file, char *name)
{

     char buf[1024];
 
    /*
     * if(sizeof(file) < _DO_STR_LEN(file) + sizeof(name) + 1)
     * {
     *     //   puts("here!!=\n");
     *}
     */
    /*int i = 0;*/
    //char *r = buf;
    //printf("%s------>%s------>%s\n", file, name, buf);
    /*
     *while(*r++ = *file++) 
     *    //if(*r == '\0')  break;
     *printf("r: %s\n", r);
     *    if(*(r - 1) != '/')
     *        *r = '/';
     *printf("r: %s\n", r);
     *    while((*++r = *name++) != '\0')
     *        ;
     *printf("%sNAME : %s------>%s______%s\n", file, name, buf, r);
     */
    /*
     *for(;*name != '\0';*buf++ = *name++)
     *   ; 
     */
    /*
     *printf("Return :!!!!!!!!!!%s\n", buf);       
     *return buf;
     /free(buf);
     */
}

int _do_count(char *str)
    /*
     *count for strings characters as the strlen function.
     */
{
    int n =0;
    while(*str++ != '\0')
        n++;
    return n;
}

int _do_str_cmp(char *str1, char *str2)

{
    while((*str1++ == *str2++) != '\0')
        return *str1 - *str2;
}

char *_strcat(char *str1, char *str2)
{
    char *buf = str1;
    printf("str1: %s", str1);
    while(*str1 != '\0')
        str1++;
    printf("\tstr2 :%s", str2);
        while((*str1++ = *str2++) != '\0')
        ;
    printf("\tbuf: %s\n", buf);
    return buf;
}
