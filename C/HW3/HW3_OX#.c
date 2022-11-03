#include<stdio.h>

int main(void)
{
    int i;
    int k;
    int num;
    char SC[3][3];
    char*form[]={ "   %c | %c | %c  \n",
                  " ----+---+---- \n",
                  "   %c | %c | %c  \n",
                  " ----+---+---- \n",
                  "   %c | %c | %c  \n"};
    for(i=0;i<9;i++)//initialize SC
    {
        ((char*)SC)[i]=' ';

    }
    char turn='O';
    i=0;
    while(i<9)
    {
        printform(form,SC);
        printf(">>turn[%c]:",turn);
        scanf("%d",&k);
        ((char*)SC)[k-1]=turn;//turn SC
        if(check(SC)==1)//call check function
        {
            printf("Winner is [%c] !!",turn);
            break;
        }
        i++;
        turn=(turn=='O')?'X':'O';//if true switch to next symbol
        if(i==9)
        {
          printf("Draw!!\n") ;
        }
    }
    return 0;
}

void printform(char*form[],char*SC)
{
    int i,j;
    for(i=0,j=0;i<5;i++)
    {
        if(i==1 | i==3 )
        {
           printf(form[i]) ;
        }
        else
            {
                printf(form[i],SC[j],SC[j+1],SC[j+2]);
                j=j+3;
            }
    }
}
int check(char SC[3][3])
{
    int i;
    for(i=0;i<3;i++)
    {
        if(SC[i][0]==SC[i][1] && SC[i][2]==SC[i][0] && SC[i][0]!=' ')
            {
            return 1;
            }
        else if(SC[0][i]==SC[1][i] && SC[2][i]==SC[0][i] && SC[0][i]!=' ')
        {
            return 1;
        }
        else if(SC[0][0]==SC[1][1] && SC[1][1]==SC[2][2] && SC[1][1]!=' ')
        {
            return 1;
        }
        else if(SC[0][2]==SC[1][1] && SC[1][1]==SC[2][0] && SC[1][1]!=' ')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

}
