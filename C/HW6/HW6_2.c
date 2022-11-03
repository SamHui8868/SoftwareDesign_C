#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include<stdint.h>
int main(void)
{
    while(1)
    {
    typedef union{
        float v;
        unsigned char ptr[4];}Float;//v and ptr have same initial address
    Float x;
    scanf("%f",&(x.v));
    printf("%02x%02x%02x%02x\n",
           x.ptr[3],x.ptr[2],x.ptr[1],x.ptr[0]);
    printf("%08lx\n",*((unsigned long*)&x.v));
    printf("%08lx\n",(unsigned long)x.v);//cast to unsigned long
    }
    return 0;
}
