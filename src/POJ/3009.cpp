// 15160306_AC_125MS_728K.cc
//注意题目要求的是最少的步数,
//不是最先到达的步数,因此要全部搜索完成
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int Max = 20 + 10;
int map[Max][Max];
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}}; //0上，1左，2下，3右 
int flag; //标记是否找到解
int minStep,w,h; 
void dfs(int x, int y, int step)
{
	int nx,ny;
	int tx,ty;
	if(step > 10){return;}
	if(map[x][y] == 3){
		minStep = min(minStep,step); 
		return;
	}
	for(int i=0;i<4;i++)
	{
		tx = x + dir[i][0];//下一步
		ty = y + dir[i][1];
		nx = x;//保守的
		ny = y;
        
		while(tx >= 0 && tx < h && ty >= 0 && ty < w && map[tx][ty] != 1)
            //预判下一步,如果不出现越界情况,而且下一步不是障碍,
		{
			nx += dir[i][0];
			ny += dir[i][1];
            //这里nx,ny可能是终点.
			if(map[nx][ny] == 3) {
				minStep = min(minStep, step);    
				return;
			}
            
			tx = nx + dir[i][0];//再次判断下一步
			ty = ny + dir[i][1];

		 	if(tx < 0 || tx >= h || ty < 0 || ty >= w) //忘记加这句就会错！！ 
				  break; //如果下一个位置越界，就直接break跳出，不进行后面的深搜，进行改变方向~ 
			if(map[tx][ty] == 1) //没有越界就要判断是不是遇到墙了，遇到墙就停止滑动，开始进行深搜 
			{
				map[tx][ty] = 0; //消除障碍 
				dfs(nx, ny, step+1);
				map[tx][ty] = 1; //重建障碍 
			}
		}
	}
}

int main()
{
	int sx,sy;
	while(scanf("%d %d",&w,&h) != EOF && w != 0 && h != 0)
	{
		minStep = 10000;
		for(int i=0; i<h; i++)
		{
			for(int j=0; j<w; j++)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j] == 2)  {
					sx = i;
					sy = j;
				}
			}
		}
		dfs(sx, sy, 1); 
		if(minStep == 10000)
			cout<<"-1"<<endl;
		else
			cout<<minStep<<endl;
	}
	return 0;
}