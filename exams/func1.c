#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int a(void)
{
    //donothing
    puts("got a !\n");
}

int b(int a(void))
{
a();
puts("got b!\n");
}

int main()
{
    b(a);


}
