// UART.cpp : 定義主控台應用程式的進入點。
//

//#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <process.h>
#include <windows.h>
using namespace std;
#include <conio.h>
#include"CQ.h"
//===========================


HANDLE init_rs232(int  com);
void COMSend(HANDLE hComm, char vOutData[], unsigned long BS);
DWORD COMRecv(HANDLE hComm, char* inbuff);
void getLocalTimeLog(char* cctime);
void GotoXY(int x, int y);
void GetXY(int* x, int* y);
void putsXY(char* s, int x, int y);
void RecvData(void* p);
int TestAndSet(void);
void ReleaseTAS(void);
CQueue CQ;

int main(void)																	  //
{
	char c = 0x00;
	char d = 0x00;
	HANDLE hComm;
	ULONG NonBlk = 1;
	ULONG Blk = 0;
	char buf[100], cctime[40];

	hComm = init_rs232(5);
	printf("[%d]", hComm);

	COMMTIMEOUTS tTimeout0, tTimeout;
	// get the timeout 
	GetCommTimeouts(hComm, &tTimeout0);
	tTimeout = tTimeout0;
	tTimeout.ReadIntervalTimeout = 10;
	tTimeout.ReadTotalTimeoutMultiplier = 10;
	tTimeout.ReadTotalTimeoutConstant = 10;
	//	tTimeout.WriteTotalTimeoutMultiplier = 10;
	//	tTimeout.WriteTotalTimeoutConstant = 100;
	SetCommTimeouts(hComm, &tTimeout);

	GetCommTimeouts(hComm, &tTimeout);
	printf("<%d>", tTimeout.ReadIntervalTimeout);
	printf("<%d>", tTimeout.ReadTotalTimeoutConstant);
	printf("<%d>", tTimeout.ReadTotalTimeoutMultiplier);

	//COMRecv(hComm, &c);
	//SetCommTimeouts(hComm, &tTimeout0);

	_beginthread(RecvData, 0, (void*)&hComm);
	while (c != 0x1B) {
		if (_kbhit()) {
			c = _getch();
			COMSend(hComm, &c, 1L);
			printf("[%c]", c);
		}

		if (!isCQempty(&CQ)) {
			d = deleteCQ(&CQ);
			printf("<%c>", d);
		}

		getLocalTimeLog(cctime);
		sprintf_s(buf, 100, "%s  ", cctime);
		putsXY(buf, 60, 1);

		Sleep(1);
	}
	getchar();
}

void getLocalTimeLog(char* cctime)
{
	time_t timer;
	struct tm tblock;

	timer = time(NULL);
	localtime_s(&tblock, &timer);
	sprintf_s(cctime, 100, "%d/%02d/%02d %02d:%02d:%02d", (tblock.tm_year + 1900) - 1911, tblock.tm_mon + 1, tblock.tm_mday, tblock.tm_hour, tblock.tm_min, tblock.tm_sec);
}
void RecvData(void* p)
{
	char c;
	int n;
	HANDLE hComm;

	hComm = *((HANDLE*)p);
	while (1) {

		n = COMRecv(hComm, &c);
		if (n == 1)
			insertCQ(&CQ, c);
	}
}


HANDLE init_rs232(int  com) //初始化comport
{

	DCB dcb;
	HANDLE hComm; //將給串列埠使用的Handle的宣告
	wchar_t buf[100];

	swprintf_s(buf, 100, L"\\\\.\\COM%d", com);

	hComm = CreateFile(buf, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);

	//如果COM未開啟，偵測失敗
	if (hComm == INVALID_HANDLE_VALUE)
	{
		cout << "開啟通訊埠錯誤!" << endl;
		system("pause");
		return 0;
	}

	FillMemory(&dcb, sizeof(dcb), 0);

	dcb.BaudRate = CBR_115200; //設定鮑率為115200
	dcb.ByteSize = 8;          //位元組為8bit
	dcb.Parity = NOPARITY;     //parity為NONE
	dcb.StopBits = ONESTOPBIT; //1個Stop bit
	dcb.fBinary = TRUE;

	dcb.fRtsControl = RTS_CONTROL_TOGGLE; // the RTS line is high if chars are available for transmission
 //   dcb.fRtsControl = RTS_CONTROL_DISABLE;   	
	dcb.fOutxCtsFlow = FALSE;         // No CTS output flow control   
	dcb.fOutxDsrFlow = FALSE;         // No DSR output flow control   
	dcb.fDtrControl = DTR_CONTROL_DISABLE;                                         // DTR flow control type   
	dcb.fDsrSensitivity = FALSE;      // DSR sensitivity   
	dcb.fTXContinueOnXoff = FALSE;     // XOFF continues Tx   
	dcb.fOutX = TRUE;                // XON/XOFF out flow control   
	dcb.fInX = TRUE;                 // XON/XOFF in flow control   
	dcb.fErrorChar = FALSE;           // Disable error replacement.   
	dcb.fNull = FALSE;                // Disable null stripping.   
	dcb.fAbortOnError = FALSE;        // Do not abort reads/writes on                                         
							// error.    	
	//通訊埠設定失敗 
	if (!SetCommState(hComm, &dcb))
	{
		CloseHandle(hComm); //釋放hComm
		cout << "通訊埠設定錯誤!" << endl;
		return 0;
	}

	return hComm;
}

void COMSend(HANDLE hComm, char vOutData[], unsigned long BS)//傳送RS232
{
	int ln;
	unsigned long lrc;

	if (hComm == 0) return; //檢查Handle值

	WriteFile(hComm, vOutData, BS, &lrc, NULL);//送出資料	
}

DWORD COMRecv(HANDLE hComm, char* inbuff)//接收RS232
{
	DWORD byteRead, errCode;
	COMSTAT state;

	ClearCommError(hComm, &errCode, &state);//清除串列錯誤或讀取串列目前狀態

	ReadFile(hComm, inbuff, 1, &byteRead, NULL);//接收COM資料

	return byteRead;
}
//=========================================================================
static long TstFlag = 0;
int TestAndSet(void)
{
	long tmp;
	tmp = 1;
	_asm {//assemble language
		MOV EAX, tmp//copy tmp value to EAX
		xchg TstFlag, EAX//swap value
		MOV tmp, EAX
	}
	return tmp;
}
void ReleaseTAS(void)
{
	TstFlag = 0;
}


//=========================================================================
void GotoXY(int x, int y)
{
	// Set the cursor position.
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cord;
	Cord.X = x;
	Cord.Y = y;
	SetConsoleCursorPosition(StdOut, Cord);
}
void GetXY(int* x, int* y)
{
	// Set the cursor position.
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo = { 0 };
	GetConsoleScreenBufferInfo(StdOut, &ScreenBufferInfo);


	*x = ScreenBufferInfo.dwCursorPosition.X;
	*y = ScreenBufferInfo.dwCursorPosition.Y;

}
void putsXY(char* s, int x, int y)
{
	int xt, yt;
	while (TestAndSet()) {
		Sleep(1);
	}//wait 1ms if there is some functions using

	GetXY(&xt, &yt);
	GotoXY(x, y);
	printf("%s  ", s);
	GotoXY(xt, yt);
	ReleaseTAS();
}

