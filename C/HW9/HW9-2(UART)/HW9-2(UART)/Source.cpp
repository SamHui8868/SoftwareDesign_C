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
#include <windows.h>
using namespace std;
#include <conio.h>
//===========================


HANDLE init_rs232(int  com);
void COMSend(HANDLE hComm, char vOutData[], unsigned long BS);
DWORD COMRecv(HANDLE hComm, char* inbuff);

int main(void)																	  //
{
	char c = 0x00;
	HANDLE hComm;
	ULONG NonBlk = 1;
	ULONG Blk = 0;

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

	COMRecv(hComm, &c);
	//SetCommTimeouts(hComm, &tTimeout0);
	while ((c = _getch()) != 0x0D) {
		COMSend(hComm, &c, 1L);
		COMRecv(hComm, &c);
		putchar(c);
	}
	getchar();
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