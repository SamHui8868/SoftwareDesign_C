
#include <stdio.h>	
#include <conio.h>	
#include <string.h>	
#include <time.h>
#include <sys/stat.h>
#include <iostream>
#include <process.h>
#include <conio.h>
#include <fstream>
struct BufferNode {//declare structure
    char data[10];
    struct BufferNode* next;//structure pointer
    struct BufferNode* front;
};
struct BufferNode* getNode(void);
int printbuf(struct BufferNode* buf);
int readBufFromFile(struct BufferNode** head, const char* fln);
int saveBufToFile(struct BufferNode* head, const char* fln);
int clearFile(const char* fln);
int countbuf(struct BufferNode* buf);

int main(void)
{

    char c,start;
    struct BufferNode* buf;
    struct BufferNode* head;
    struct BufferNode* tbuf;
    struct BufferNode* newhead;
    struct BufferNode* sourcehead;
    struct BufferNode* copy,load;
    int i, n;
    head = buf = getNode();
    i = 0;
    c = 0x00;
    start = 0x31;
    while (start == 0x31)
    {
        head = buf;
        printf("\nYou can start now\n");
        while (c != 0x0D)// while not Enter get character
        {
            c = _getch();
            switch (c)
            {
            case 0x08:
                putchar(c);
                putchar(0x20);
                putchar(c);
                if (i == 0)
                {
                    tbuf = (*buf).front;//back to previous memory space
                    if ((*buf).front == NULL) {
                        putchar(0x07);
                    }
                    else {
                        free(buf);
                        buf = tbuf;
                        i = 9;
                    }
                }
                else {
                    i--;
                }

                break;
            case 0x20:
                printf("\n<Press[1] to Save text to File>\n<Press[2] to copy text from source.txt to text.txt>\n");
                printf("<Press[3] to load text from text.txt>\n<Press[4] to clear text.txt>\n<Press[Enter] to show text>\n");

                c = _getch();
                switch (c)
                {
                case 0x31://1
                    buf->data[i] = 0x00;
                    saveBufToFile(head, "text.txt");
                    printf("\n<File Saved>\n");
                    break;
                case 0x32://2
                    readBufFromFile(&copy, "source.txt");
                    printf("\n<source.txt loaded>\n");
                    saveBufToFile(copy, "text.txt");
                    printf("\n<copied text from source.txt to text.txt>\n");
                    break;
                case 0x33://3
                    readBufFromFile(&head, "text.txt");
                    printf("\n<text.txt loaded to buffer>\n");
                    printf("\n<Print buffer>\n");                   
                    printf("[%d]",i);
                    i=countbuf(head);
                    printbuf(head);
                    buf = head;
                    /*Teacher code
                    buf=head;
                    while(buf->next!=NULL)
                    {buf=buf->next;
                    if(buf->front!=NULL)free(buf->front);
                    }
                    if(buf!=NULL)free(buf);
                    readBufFromFile(&head,"text.txt");
                    */
                    break;
                case 0x34://4
                    clearFile("text.txt");
                    printf("\n<cleared text.txt>\n");
                    break;
                }

                break;/**/

            case 0x0D:
                break;
            default:
                putchar(c);
                (*buf).data[i++] = c;
                if (i == 10) {
                    tbuf = buf;
                    buf = (*buf).next = getNode();//initial address of new space save to buf.next
                    (*buf).front = tbuf;//old memory address
                    i = 0;
                }

            }
         }
    printf("\n\n=========================================================\n");
    printf("Text in buf:\n");
    (*buf).data[i] = 0x00;
    n=printbuf(head);
    printf("\n=========[%d]==================\n", n);
    printf("Text read from text.txt:\n");
    readBufFromFile(&newhead, "text.txt");
    n=printbuf(newhead);
    printf("\n=========[%d]==================\n", n);
    printf("Text read from souce.txt:\n");
    readBufFromFile(&sourcehead, "source.txt");
    n =printbuf(sourcehead);
    printf("\n=========[%d]==================\n", n);/**/
    printf("\nPress[1] to try again\n");
    start = _getch();
    if (start == 0x31)
    {
        c = 0x00;
    }

    }
    return 0;
    
}
int countbuf(struct BufferNode* buf)
{
    int i = 0;
    while ((*buf).data[i] != 0x00)
    {
      i++;
        if (i == 10)
        {
            buf = (*buf).next;
            i = 0;
        }
    }
    return i;
}

int printbuf(struct BufferNode* buf)
{
    int j = 0;
    int i = 0;
    while ((*buf).data[i] != 0x00)
    {
        putchar((*buf).data[i++]);
        j++;
        if (i == 10)
        {
            buf = (*buf).next;
            i = 0;
        }
    }
    return j;
}
struct BufferNode* getNode(void)
{
    int i;
    struct BufferNode* ptr;
    ptr = (struct BufferNode*)malloc(1 * sizeof(struct BufferNode));//craete new memory space in dynamic
    for (i = 0; i < 10; i++)
    {
        (*ptr).data[i] = 0x00;
    }
    if (ptr != NULL)ptr->front = ptr->next = NULL;
    return ptr;
};
int readBufFromFile(struct BufferNode** head, const char* fln)
{
    FILE* fp;
    struct BufferNode* buf, * tbuf;
    char c;
    int n = 0, i, rVal;

    rVal = fopen_s(&fp, fln, "rb");//if open success rVal=0;

    if (rVal != 0) return 0;

    *head = buf = getNode();

    n = i = fread(buf->data, sizeof(char),10, fp);
    while (i == 10) {
        tbuf = buf;
        buf = buf->next = getNode();
        buf->front = tbuf;
        n += i = fread(buf->data, sizeof(char),10, fp);
    }

    if (i == 0) {
        buf = buf->front;
        free(buf->next);
        buf->next = NULL;
    }  

    fclose(fp);
    return n;
}
int saveBufToFile(struct BufferNode* head, const char* fln)
{
    FILE* fp;
    struct BufferNode* buf;
    int  i;

    fopen_s(&fp, fln, "wb");
    buf = head;
    i = 0; 
    while (buf != NULL) {
        fwrite(buf->data,sizeof(char),10,fp);
        buf = buf->next;
    }
    fclose(fp);
    return i;
}
int clearFile(const char* fln)
{
    struct BufferNode* buf;
    buf = getNode();
    saveBufToFile(buf,fln);
     return 0;

}