// UART.cpp : �w�q�D���x���ε{�����i�J�I�C
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

HANDLE init_rs232(int  com) //��l��comport
{

	DCB dcb;
	HANDLE hComm; //�N����C��ϥΪ�Handle���ŧi
	wchar_t buf[100];

	swprintf_s(buf, 100, L"\\\\.\\COM%d", com);

	hComm = CreateFile(buf, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);

	//�p�GCOM���}�ҡA��������
	if (hComm == INVALID_HANDLE_VALUE)
	{
		cout << "�}�ҳq�T����~!" << endl;
		system("pause");
		return 0;
	}

	FillMemory(&dcb, sizeof(dcb), 0);

	dcb.BaudRate = CBR_115200; //�]�w�j�v��115200
	dcb.ByteSize = 8;          //�줸�լ�8bit
	dcb.Parity = NOPARITY;     //parity��NONE
	dcb.StopBits = ONESTOPBIT; //1��Stop bit
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
	//�q�T��]�w���� 
	if (!SetCommState(hComm, &dcb))
	{
		CloseHandle(hComm); //����hComm
		cout << "�q�T��]�w���~!" << endl;
		return 0;
	}

	return hComm;
}

void COMSend(HANDLE hComm, char vOutData[], unsigned long BS)//�ǰeRS232
{
	int ln;
	unsigned long lrc;

	if (hComm == 0) return; //�ˬdHandle��

	WriteFile(hComm, vOutData, BS, &lrc, NULL);//�e�X���	
}

DWORD COMRecv(HANDLE hComm, char* inbuff)//����RS232
{
	DWORD byteRead, errCode;
	COMSTAT state;

	ClearCommError(hComm, &errCode, &state);//�M����C���~��Ū����C�ثe���A

	ReadFile(hComm, inbuff, 1, &byteRead, NULL);//����COM���

	return byteRead;
}



//=========================================================================