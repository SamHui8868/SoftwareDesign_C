#include<stdio.h>
#include <Windows.h>

void GotoXY(SHORT x, SHORT y);
void GetXY(int * x, int * y);

int main(void)
{
    int i;
    int k;
    char SC[3][3];
    char*form[]={ "   %c | %c | %c  \n",
                  " ----+---+---- \n",
                  "   %c | %c | %c  \n",
                  " ----+---+---- \n",
                  "   %c | %c | %c  \n"};
    ((char*)SC)[0]='1';
    ((char*)SC)[1]='2';
    ((char*)SC)[2]='3';
    ((char*)SC)[3]='4';
    ((char*)SC)[4]='5';
    ((char*)SC)[5]='6';
    ((char*)SC)[6]='7';
    ((char*)SC)[7]='8';
    ((char*)SC)[8]='9';

    char turn='O';
    i=0;
    printform(form,SC);
    while(i<9)
    {

        if(turn=='O')
        {
        printf("\nPlayers turn:",turn);
        scanf("%d",&k);
        ((char*)SC)[k-1]=turn;//turn SC
        printform(form,SC);
        if(check(SC)==1)//call check function
        {
            printf("Winner is %c",turn);
            break;
        }

        }
        if(turn=='X')
        {

         ((char*)SC)[computer(SC)-1]=turn;//turn SC
         printform(form,SC);

        if(check(SC)==1)//call check function
        {
            printf("Winner is %c",turn);
            break;
        }
        }



        turn=(turn=='O')?'X':'O';//if true switch to next player
        i++;
        if(i==9)
        {
          printf("Draw!!\n") ;
        }
    }
    return 0;
}

int printform(char*frm[],char*p)
{
	int i, k = 0;
	int x, y;

	GetXY(&x, &y);
	for (i = 0;i < 5;i++) {
		GotoXY(x0, y0 + i);
		if (!(i % 2)) {
			printf(frm[i],	p[k], p[k+1], p[k+2]);
			k += 3;
		}
		else {
			printf(frm[i]);
		}
	}
	GotoXY(x, y);
}
int check(char SC[3][3])
{
    int i;
    for(i=0;i<3;i++)
    {
        if(SC[i][0]==SC[i][1] && SC[i][2]==SC[i][0])
            {
            return 1;
            }
        else if(SC[0][i]==SC[1][i] && SC[2][i]==SC[0][i])
        {
            return 1;
        }
        else if(SC[0][0]==SC[1][1] && SC[1][1]==SC[2][2])
        {
            return 1;
        }
        else if(SC[0][2]==SC[1][1] && SC[1][1]==SC[2][0])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int computer (char sc[3][3]){
	int i;
	for(i=0; i<3;i++){
		if(sc[i][0]==sc[i][1])         //檢查橫排連線
		 	if(sc[i][2]!='X'&&sc[i][2]!='O')
			return i*3+3;
		if(sc[i][1]==sc[i][2])         //檢查橫排連線
			if(sc[i][0]!='X'&&sc[i][0]!='O')
			return i*3+1;
		if(sc[i][0]==sc[i][2])         //檢查橫排連線
			if(sc[i][1]!='X'&&sc[i][1]!='O')
			return i*3+2;
		if(sc[0][i]==sc[1][i])        //檢查直排連線
			if(sc[2][i]!='X'&&sc[2][i]!='O')
			return i+7;
		if(sc[0][i]==sc[2][i])        //檢查直排連線
			if(sc[1][i]!='X'&&sc[1][i]!='O')
			return i+4;
		if(sc[1][i]==sc[2][i])        //檢查直排連線
			if(sc[0][i]!='X'&&sc[0][i]!='O')
			return i+1;
	}
	if(sc[0][0]==sc[1][1])          //檢查右斜排連線
	    if(sc[2][2]=='9')
		return 9;
	if(sc[0][0]==sc[2][2])          //檢查右斜排連線
		if(sc[2][2]=='5')
		return 5;
	if(sc[1][1]==sc[2][2])          //檢查右斜排連線
		if(sc[2][2]=='1')
		return 1;
	if(sc[0][2]==sc[1][1])          //檢查左斜排連線
	    if(sc[2][2]=='7')
		return 7;
	if(sc[0][2]==sc[2][0])          //檢查左斜排連線
		if(sc[2][2]=='5')
		return 5;
	if(sc[1][1]==sc[2][0])          //檢查左斜排連線
		if(sc[2][2]=='3')
		return 3;
	if(sc[1][1]=='5')          //檢查5
		return 5;
	if(sc[0][0]=='1')          //檢查1
		return 1;
	if(sc[0][2]=='3')          //檢查3
		return 3;
	if(sc[2][0]=='7')          //檢查7
		return 7;
	if(sc[2][2]=='9')          //檢查9
		return 9;
	if(sc[0][1]=='2')          //檢查2
		return 2;
	if(sc[1][0]=='4')          //檢查4
		return 4;
	if(sc[1][2]=='6')          //檢查6
		return 6;
	return 8;
}
//===========================================================
// Set current cursor position.
void GotoXY(SHORT x, SHORT y)
{
	// Set the cursor position.
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cord;
	Cord.X = x;
	Cord.Y = y;
	SetConsoleCursorPosition(StdOut, Cord);
}
void GetXY(int * x, int * y)
{
	// Set the cursor position.
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo = { 0 };
	GetConsoleScreenBufferInfo(StdOut, &ScreenBufferInfo);
	GetConsoleScreenBufferInfo(StdOut, &ScreenBufferInfo);


	*x = ScreenBufferInfo.dwCursorPosition.X;
	*y = ScreenBufferInfo.dwCursorPosition.Y;

}
