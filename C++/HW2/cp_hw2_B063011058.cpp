#include<iostream>
#include<fstream>

using namespace std;

int no_of_color;
int no_of_walls;
int stock[10000];
int no_of_forbid;
int forbid_pattern[10000][10000];
int solution=0;

int checkstock(int stock[],int color)//check whether have enough cans to paint
{
    int flag;
    if(stock[color]==0)
    {
        flag=1;
    }
    else
    {
        flag=0;
    }
    return flag;
}

int checkforbid(int previous_color,int now_color)//check whether the color is forbid
{
    int flag;
    if(previous_color >= 0)//make sure the color exist
    {
        if(forbid_pattern[previous_color][now_color]==1)
        {
            flag=1;
        }
    }
    else
    {
        flag=0;
    }
    return flag;
}



int paintwall(int current_wall,int previous_color)
{
    if(current_wall==no_of_walls)//add one solution when all the walls are painted (base case of recursion)
    {
        solution++;
        return solution;
    }
    else
    {
        for(int i=0;i < no_of_color;i++)// i is the color used to paint the wall
        {
        int cs;
        cs=checkstock(stock,i);
        if(cs==1)
        {
           continue;//if not enough paint cans change another color
        }
        int cf;
        cf=checkforbid(previous_color,i);
        if(cf==1)
        {
            continue;//if the current color is forbid change another color
        }
        stock[i]--;//one can of paint is used
        paintwall(current_wall+1,i);//do recursion to paint the rest of the wall, i will be the previous color
        stock[i]++;//refill stock for next painting solution
        }
    }

}

int main(int argv, char* arcv[]) {
	ifstream is;
    ofstream os;
    is.open(arcv[1]);
    os.open(arcv[2]);

	is>>no_of_walls>>no_of_color;
	for (int i = 0; i < no_of_color; i++)
	{
		is>>stock[i];
	}
	is>>no_of_forbid;
	for (int i = 0; i < no_of_forbid; i++)
	{
		int a, b;
		is>>a>>b;
		forbid_pattern[a][b] = 1;
	}
	paintwall(0, -3);
	os<<solution<<endl;
	cout<<solution;

	is.close();
    os.close();

	return 0;
}
