#include <stdio.h>


char ss[100] = "abcsdeffnhjk";

int main()
{
//rintf("%s\n", _strcat(ss, _strcat(ss+5, "fuck")));
printf("%s\t%s\n", ctermid(NULL), ttyname(NULL));
}
