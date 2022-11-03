
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
    struct BufferNode{
    char data[10];
    struct BufferNode*next;
    struct BufferNode*front;};
    struct BufferNode*getNode(void);
    int printbuf(struct BufferNode*buf);

int main(void)
{

    char c;
    struct BufferNode *buf;
    struct BufferNode *head;
    struct BufferNode *tbuf;
    int i,n;
    head=buf=getNode();
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
                tbuf=(*buf).front;//back to previous memory space
                if((*buf).front== NULL){
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
                (*buf).data[i++]=c;
      if(i==10){
                     tbuf=buf;
                    buf=(*buf).next=getNode();//initial address of new space save to buf.next
                    (*buf).front=tbuf;//old memory address
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
struct BufferNode*getNode(void)
{
    struct BufferNode*ptr;
    ptr=(struct BufferNode*)malloc(1*sizeof(struct BufferNode));
    if (ptr != NULL)ptr->front=ptr->next=NULL;
    return ptr;
};

