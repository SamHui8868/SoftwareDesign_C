// HW12-HanoiTower.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include"STACK.h"
#include<stdio.h>

STACK s[3];
void MOV(int src, int num, int dest,int _num);
void printStacks(int k);
int step;
int main()
{
    int n, i;
	int c;

	s[0].sp = 16;
	s[1].sp = 16;
	s[2].sp = 16;
	while (1) {
		printf("Enter number of disks(1~16):");
		scanf_s("%d", &n);
		for (i = 0; i < n; i++)
		{
			c = push(&(s[0]), n - i);
		}
		printStacks(n);
		MOV(0, n, 2, n);
		printf("====================Complete================TOTAL STEP[%d]===============", step);
		step = 0;
		getchar();
	}
}


void MOV(int src, int num, int dest,int _num)
{
	int dest_temp;
	if (num == 1)
	{

		push(&(s[dest]),pop( &(s[src])));
		step++;
		printf("STEP[%d]:\n", step);
		printStacks(_num);

	}
	else {
		dest_temp = 3 - (src + dest);
		MOV(src, num - 1, dest_temp,_num);
		MOV(src,1, dest,_num);
		MOV(dest_temp, num - 1, dest, _num);
	}
}
void printStacks(int k)
{
	int j ;
	int i ;
	i = 15;
	for (j = 0; j < 3; j++)
	{
		printf("s[%d]=<", j);
		for (i = 15; i > 15-k; i--)
		{
			printf("  %d  ", s[j].buf[i]);
		}
		printf(">\n");
		}
	printf(">\n");
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
