#include <iostream>
#include <fstream>
using namespace std;
int total_wall, total_color, color_amount[1000];
int total_forbid, forbid_color[1000][1000] ;

int sum = 0;
void DFS(int past_color, int pos)
{
	if (pos == total_wall)
	{	
		sum++;
		return;
	}
	for (int i = 0; i < total_color; i++)
	{
		if (color_amount[i] == 0)
			continue;
		if (past_color >= 0)
		{
			if (forbid_color[past_color][i] == 1)
				continue;
		}
		color_amount[i]--;
	
		DFS(i, pos + 1);
		color_amount[i]++;
	}
}
int main(int argv, char* arcv[]) {
	ifstream inputStream;
    ofstream outputStream;
    inputStream.open(arcv[1]);
    outputStream.open(arcv[2]);
    
	inputStream>>total_wall>>total_color;
	for (int i = 0; i < total_color; i++)
	{
		inputStream>>color_amount[i];
	}
	inputStream>>total_forbid;
	for (int i = 0; i < total_forbid; i++)
	{
		int a, b;
		inputStream>>a>>b;
		forbid_color[a][b] = 1;
	}
	DFS(-1, 0);
	outputStream<<sum<<endl;
	
	inputStream.close();
    outputStream.close();
    
	return 0;
}
