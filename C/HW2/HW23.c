#include<stdio.h>

int main(void)
{
 int A[]={10,6,20,7,22,11,18};
 int i,j;
 printf("Before sorting:");
 printA(A,7);
 for (i=0;i<7;i++)
 {
     for(j=0;j<6;j++)
     {
          if(A[j]>A[j+1])
     {
         swap(&A[j],&A[j+1]);

     }
     }
}
printf("After  sorting:");
printA(A,7);
 return 0;
}
void printA(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d   ",A[i]);
    }
putchar('\n');
}
void swap(int*x,int*y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
}
