#include<conio.h>
#include<stdio.h>

int main(void)
{
    char buf[100],c=0;
    int i=0;
    while((c = getch())!=0x0D)
    {
        buf[i]=c;i++;
        putchar(c);
    }
    buf[i]=0x00;
    printf("\n===============================================\n");
    puts(buf);
    return 0;
}
