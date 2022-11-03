
#include <stdio.h>
#include <malloc.h>

int main(void)
{
    char*buf,c,*ptr;
    int i=0;
    ptr=(char*)malloc(10*sizeof(char)+sizeof(char*));
    buf=ptr;
    while((c = getch())!=0x0D)// while not Enter get character
    {
    	ptr[i]=c; // *(buf+(i++))=c
        putchar(c);
        i++;
        if(i==10)
        {
            ptr=*((char**)(&(ptr[10])))=(char*)malloc(10+sizeof(char*));//ptr points to new 100 memory
            i=0;
        }

    }

        ptr[i]=0x00;
        printf("\n=========================================================\n");
        printbuf(buf);

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
          //printbuf(add);
        }


    }
    return i;
}

