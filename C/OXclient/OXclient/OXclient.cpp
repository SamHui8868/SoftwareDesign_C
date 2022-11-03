// OX2.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <process.h>
#include <string.h>
using namespace std;

#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

#define BUFFERSIZE 100
#define SPORT 5550
void GotoXY(SHORT x, SHORT y);
void GetXY(int* x, int* y);
void print_form(const char* frm[], char* sb);
int sb_check(char sb[][3]);
int create_OX_server(int port);
SOCKET connect_Rplayer(const char* ip, int port);
int main()
{
	const char* frm[] = {
		"%c|%c|%c\n",
		"-+-+-\n",
		"%c|%c|%c\n",
		"-+-+-\n",
		"%c|%c|%c\n" };
	char sb[3][3] = { '1', '2', '3',
					  '4', '5', '6',
					  '7', '8', '9' };
	char turn = 'O';
	int pos, n = 0, client_turn = 0;

	SOCKET rsck;
	char buf[BUFFERSIZE], IP[20];
	int rVal;
	WSADATA			WsaData;

	if (0 != WSAStartup(MAKEWORD(1, 1), &WsaData)) {
		WSACleanup();																			  //
		exit(0);
	}

	/*create_OX_server(SPORT);

	while (1) {
		Sleep(1);
	}*/

	cout << "IP:"; cin >> IP;
	rsck = connect_Rplayer(IP, SPORT);

	print_form(frm, (char*)sb);

	do {
		if (client_turn) {
			sprintf_s(buf, BUFFERSIZE, "%d", pos);
			rVal = send(rsck, buf, BUFFERSIZE, 0);
			rVal = recv(rsck, buf, BUFFERSIZE, 0);
			if (sb_check(sb)) {
				printf("Winner is [%c]!!!\n", turn);
				sprintf_s(buf, BUFFERSIZE, "%d", pos);
				rVal = send(rsck, buf, BUFFERSIZE, 0);
				break;
			}
			sscanf_s(buf, "%d", &pos);
		}
		else {
			printf("[%c]>>", turn);
			scanf_s("%d", &pos);
		}

		((char*)sb)[pos - 1] = turn;

		print_form(frm, (char*)sb);
		if (sb_check(sb)) {
			printf("Winner is [%c]!!!\n", turn);
			sprintf_s(buf, BUFFERSIZE, "%d", pos);
			rVal = send(rsck, buf, BUFFERSIZE, 0);
			break;
		}
		turn = (turn == 'O') ? 'X' : 'O';
		client_turn = (client_turn) ? 0 : 1;
		n++;

	} while (n < 9);

	if (n == 9) {
		printf("The competition is draw!!!\n");
		sprintf_s(buf, BUFFERSIZE, "%d", pos);
		rVal = send(rsck, buf, BUFFERSIZE, 0);
	}

	getchar(); getchar();
}

int sb_check(char sb[][3])
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (sb[i][0] == sb[i][1] && sb[i][1] == sb[i][2])return 1;
	}
	for (i = 0; i < 3; i++)
	{
		if (sb[0][i] == sb[1][i] && sb[1][i] == *((char*)sb + 2 * 3 + i))return 1;
	}
	if (sb[0][0] == sb[1][1] && sb[1][1] == sb[2][2])return 1;
	if (sb[2][0] == sb[1][1] && sb[1][1] == sb[0][2])return 1;
	return 0;
}
void print_form(const char* frm[], char* p)
{

	int i, k = 0;
	int x, y;
	int x0, y0;
	x0 = 65;
	y0 = 5;
	GetXY(&x, &y);
	for (i = 0; i < 5; i++) {
		GotoXY(x0, y0 + i);
		if (!(i % 2)) {
			printf(frm[i], p[k], p[k + 1], p[k + 2]);
			k += 3;
		}
		else {
			printf(frm[i]);
		}
	}
	GotoXY(x, y);
}
//=======================================================================================

void waitClient(void* pt);
int create_OX_server(int port)
{
	static SOCKET			sck1;							//自己的socket
	SOCKADDR_IN		sa;							//自己的SOCKADDR_IN結構
																							  //
//---------------------------------------------建立SCOKET---------------------------------------------//
	sck1 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);											  //
	if (INVALID_SOCKET == sck1) {
		WSACleanup();																			  //
		exit(0);
	}																								  //
//------------------------------------------------BIND------------------------------------------------//
	sa.sin_family = AF_INET;																	  //
	sa.sin_port = htons(port);															  //
	sa.sin_addr.s_addr = INADDR_ANY;															  //
	if (SOCKET_ERROR == bind(sck1, (LPSOCKADDR)&sa, sizeof(sa))) {
		closesocket(sck1);
		WSACleanup();																			  //
		exit(0);
	}																								  //
//-----------------------------------------------LISTEN-----------------------------------------------// 
	if (SOCKET_ERROR == listen(sck1, 1)) {
		closesocket(sck1);
		WSACleanup();																				  //
		exit(0);
	}																								  //
	cout << "Server succeeded!" << endl;															  //
	cout << "Waiting for new clients..." << endl;													  //
//-----------------------------------------------送訊息-----------------------------------------------//	
	_beginthread(waitClient, 0, (void*)&sck1);
	return 1;
}

void waitClient(void* pt)
{
	sockaddr_in addrClient;
	int addrClientlen = sizeof(addrClient);
	SOCKET sck1;
	SOCKET	ClientSocket;

	sck1 = *((SOCKET*)pt);

	ClientSocket = accept(sck1, (sockaddr FAR*) & addrClient, &addrClientlen);			  //

	_beginthread(waitClient, 0, (void*)&sck1);
	//-----------------------------------------------------------------------
	int pos, n = 0;
	int  rVal;
	char buf[BUFFERSIZE], turn;
	const char* frm[] = {
		"%c|%c|%c\n",
		"-+-+-\n",
		"%c|%c|%c\n",
		"-+-+-\n",
		"%c|%c|%c\n" };
	char sb[3][3] = { '1', '2', '3',
					  '4', '5', '6',
					  '7', '8', '9' };

	print_form(frm, (char*)sb);
	do {
		rVal = recv(ClientSocket, buf, BUFFERSIZE, 0);
		printf("%s\n", buf);
		sscanf_s(buf, "%d", &pos);
		turn = 'O';
		((char*)sb)[pos - 1] = turn;

		print_form(frm, (char*)sb);

		if (sb_check(sb)) {
			printf("Winner is [%c]!!!\n", turn);
			break;
		}
		turn = (turn == 'O') ? 'X' : 'O';
		printf("[N]>>  ");
		scanf_s("%d", &pos);

		((char*)sb)[pos - 1] = turn;

		print_form(frm, (char*)sb);

		if (sb_check(sb)) {
			rVal = recv(ClientSocket, buf, BUFFERSIZE, 0);
			sscanf_s(buf, "%d", &pos);
			printf("Winner is [%c]!!!\n", turn);

			break;
		}

		sprintf_s(buf, "%d", pos);
		rVal = send(ClientSocket, buf, BUFFERSIZE, 0);

		n++;
	} while (n < 9);
	getchar();
	printf("Client Exit!!\n ");
	closesocket(ClientSocket);
	return;//
	//
}

SOCKET connect_Rplayer(const char* ip, int port)
{

	SOCKET			sc;							//自己的socket
	SOCKADDR_IN		sa;							//自己的SOCKADDR_IN結構
																							  //
//---------------------------------------------建立SCOKET---------------------------------------------//
	sc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);											  //
	if (INVALID_SOCKET == sc) {
		WSACleanup();																			  //
		exit(0);
	}																								  //

	sa.sin_family = AF_INET;																	  //
	sa.sin_port = htons(port);															  //
	inet_pton(AF_INET, ip, &(sa.sin_addr.s_addr));

	//-----------------------------------------------送訊息-----------------------------------------------//	

	if (SOCKET_ERROR == connect(sc, (LPSOCKADDR)&sa, sizeof(sa))) {
		printf("connect server error!");//
		getchar(); getchar();
		WSACleanup();
		exit(0);
	}

	return sc;
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
void GetXY(int* x, int* y)
{
	// Set the cursor position.
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo = { 0 };
	GetConsoleScreenBufferInfo(StdOut, &ScreenBufferInfo);
	GetConsoleScreenBufferInfo(StdOut, &ScreenBufferInfo);


	*x = ScreenBufferInfo.dwCursorPosition.X;
	*y = ScreenBufferInfo.dwCursorPosition.Y;

}