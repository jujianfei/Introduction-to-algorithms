/*
Write a program that takes a command line parameter N,
and generates a random N-by-N perfect maze. A maze is perfect if
it has exactly one path between every pair of points in the maze,
i.e., no inaccessible locations, no cycles, and no open spaces.
Here's a nice algorithm to generate such mazes. Consider an N-by-N grid of cells,
each of which initially has a wall between it and its four neighboring cells.
For each cell (x, y), maintain a variable north[x][y] that is true if there is wall
separating (x, y) and (x, y + 1). We have analogous variables east[x][y],
south[x][y], and west[x][y] for the corresponding walls. Note that if
there is a wall to the north of (x, y) then north[x][y] = south[x][y+1] = true.
Construct the maze by knocking down some of the walls as follows:
Start at the lower level cell (1, 1).
Find a neighbor at random that you haven't yet been to.
If you find one, move there, knocking down the wall. If you don't find one, go back to the previous cell.
Repeat steps ii. and iii. until you've been to every cell in the grid.
*/
#include <bits/stdc++.h>
using namespace std;
#include<random>
///*********
#define N 52
///*********
#define WEST 0
#define SOUTH 1
#define EAST 2
#define NORTH 3
int n=N-2;
default_random_engine e;
int north[N][N];
int east[N][N];
int south[N][N];
int west[N][N];
int visited[N][N];
int visitedcounter=0;

int di[4]={0,-1,0,1};
int dj[4]={-1,0,1,0,};
//请构建这个迷宫，并且给出一个解
//TODO:unimplemented
void dfs(int i,int j,int dir);

int init(){
    //假设采用笛卡尔坐标系，迷宫范围(1,1)到(n,n)，
    //而且是从1,1开始，50,50结束
    visitedcounter=0;
    memset(north,0,sizeof(north));
    memset(south,0,sizeof(north));
    memset(east,0,sizeof(north));
    memset(west,0,sizeof(north));
    memset(visited,0,sizeof(north));
    dfs(1,1,EAST);//开始的时候是从0,1进入的1,1

}
int main(){
    init();
}
