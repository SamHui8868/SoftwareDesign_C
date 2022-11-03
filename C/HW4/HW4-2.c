
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

int main(void)
{
    char*buf,c,*head,*tbuf;
    int i,n;
    head=buf=(char*)malloc(10*sizeof(char)+sizeof(char*)+sizeof(char*));
    *((char**)&(buf[10+sizeof(char*)]))=NULL;
    i=0;
    c=0;
    while(c !=0x0D)// while not Enter get character
    {
        c=_getch();
        switch(c)
        {
        case 0x08:
            putchar(c);
            putchar(0x20);
            putchar(c);
            if(i==0)
            {
                tbuf = *((char**)&(buf[10+sizeof(char*)]));
                if(tbuf== NULL){
                    putchar(0x07);
                  }
                  else{
                    free(buf);
                    buf=tbuf;
                    i=9;
                  }
                }else{
                       i--;
                      }

            break;
            case 0x0D:
            break;
            default:
                putchar(c);
                buf[i++]=c;
                if(i==10){
                    tbuf=buf;
                    buf=*((char**)&buf[10])=(char*)malloc(10*sizeof(char)+sizeof(char*)+sizeof(char*));
                    *((char**)&(buf[10+sizeof(char*)]))=tbuf;
                    i=0;
                }
        }

    }
        printf("\n=========================================================\n");
        buf[i]=0x00;
        printbuf(head);
        return 0;
}
int printbuf(char*buf)
{
    int i=0;
    char*add;
    add=buf;
   while(add[i]!=0x00)
    {
        putchar(add[i++]);
        if(i==10)
        {
          add=*(char**)(&add[10]);
          i=0;
        }
    }
    return 0;
}

