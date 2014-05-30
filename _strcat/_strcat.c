#include <stdio.h>
#include <string.h>

#define DEBUG
#undef DEBUG
#define BUFSIZE 1024
/*
 *realization strcat for string
 */
char *_strcat(char *str1, char *str2)
{
    /*
     *use do_len_str(str) to get len of str 
     */
    /*
     *int i;
     *int k = 0;
     *char buf[BUFSIZE];
     */

/*
 *    for(i = 0; i < strlen(str1); i++)
 *    {
 *        buf[i] = str1[i];
 *    }
 *
 *    [>i = 0;<]
 *    if(str2[k] != '\0')
 *    {
 *        buf[i+k] = str2[k];
 *        k++;
 *    }
 *    [>str1[strlen(str1) + strlen(str2)+1] = '\0';<]
 *    buf[i+k+1] = '\0';
 *#ifdef DEBUG
 *    puts(buf);
 *#endif
 *    str1 = buf;
 *    return  str1;
 */
    char *buf = str1;
    while(*str1 != '\0')
        str1++;
    while((*str1++ = *str2++) != '\0')
        ;
            //printf("fuck: %s", str1);
#ifdef DEBUG
            printf("fuck: %s", str1);
    printf("debug: #%s#\n", str1);
#endif
    return buf;
}

char *n_0(char *st)
{
    char *buf = st;
    while(*st != '\n')
    {
#ifdef DEBUG
    printf("debug : n_0 :#####%c#######\n", *st);
#endif
        st++;
    }
    *st = '\0';
    return buf;
}
