#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int A[5][5]={ 1, 2, 3, 4, 5,
                 11,12,13,14,15,
                 21,22,23,24,25,
                 31,32,33,34,35,
                 41,42,43,44,45};
    int B[5][5]={ 1, 0, 0, 0, 0,
                  0, 1, 0, 0, 0,
                  0, 0, 1, 0, 0,
                  0, 0, 0, 1, 0,
                  0, 0, 0, 0, 1};
    int C[5][5];

  MATRIXMUL((int*)A,(int*)B,(int*)C);//2D matrix to 1D matrix
return 0;
}

void MATRIXMUL(int*a,int*b,int*c)
{
    int i,j,k;
    int sum;
    sum=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            for(k=0;k<5;k++)
            {
              sum=sum+(*(a+i*5+k))*(*(b+k*5+j));
            }
            *(c+i*5+j)=sum;
            sum=0;
        }

    }
    for(i=0;i<5;i++)
 {
 for(j=0;j<5;j++)
 {
 printf("%d\t",*(c+i*5+j));
 }
 printf("\n");
 }
}
