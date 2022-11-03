#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include<stdint.h>
#include<math.h>
int main(void)
{
    while(1)
    {
    typedef union{
        float v;
        unsigned char ptr[4];
        struct{unsigned F:23;
               unsigned E:8;
               unsigned S:1;};
        }Float;//v and ptr have same initial address
    Float x;
    float y;
    scanf("%f",&(x.v));
    printf("%02x%02x%02x%02x\n",x.ptr[3],x.ptr[2],x.ptr[1],x.ptr[0]);
    printf("%08lx\n",*((unsigned long*)&x.v));
    printf("<%f>=[%d,%02x,%06x]\n",x.v,x.S,x.E,x.F);//cast to unsigned long
    }
    return 0;
}
