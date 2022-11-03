
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
    struct BufferNode{
    char data[10];
    struct BufferNode*next;
    struct BufferNode*front;};
int main(void)
{

    char c;
    struct BufferNode *buf;
    struct BufferNode *head;
    int i,n;
    buf=malloc(1*sizeof(struct BufferNode));
    (*buf).front=NULL;
    head=buf;
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
                if((*buf).front== NULL){
                    putchar(0x07);
                  }
                  else{
                    buf=(*buf).front;
                    free(buf);
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
                (*buf).data[i++]=c;
                if(i==10){
                    (*buf).next=(struct BufferNode*)malloc(1*sizeof(struct BufferNode));//initial address of new space save to buf.next
                    (*((*buf).next)).front=buf;//new space .front = buf
                    buf=(*buf).next;//buf equal to new space
                    i=0;
                }
        }

    }
        printf("\n=========================================================\n");
        (*buf).data[i]=0x00;
        printbuf(head);
        return 0;
}
int printbuf(struct BufferNode*buf)
{
    int i=0;
   while((*buf).data[i]!=0x00)
    {
        putchar((*buf).data[i++]);
        if(i==10)
        {
          buf=(*buf).next;
          i=0;
        }
    }
    return 0;
}

