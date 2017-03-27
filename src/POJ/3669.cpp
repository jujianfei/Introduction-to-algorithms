// 15207565_AC_532MS_1648K.cpp
#include<stdio.h>
#include <iostream>
#include<queue>
using namespace std;
//思路很重要,建立地图,写入最早炸掉的时间，然后看下，00点如果是0,那么就-1了
//否则BFS，BFS过程中判断是不是已经超过了最长时间，如果超过了就说明已经逃离了，否则返回-1
#define N 407
#define MAX_M 50000+7
#define INF 0xffffff
struct P{
    int x,y,t;
    P(int x,int y,int t):x(x),y(y),t(t){}
    P(){}
};
P bomb[MAX_M];
int m[N][N];
bool visit[N][N];
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};
int last=-1;
int M;
bool Inmap(int x,int y){
    if(x<0||x>=N||y<0||y>=N){
        return false;
    }
    return true;
}

void Init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visit[i][j]=false;
            m[i][j]=INF;
        }
    }
}

int bfs()
{

    queue<P> que;
    P current;
    current.x = 0;
    current.y = 0;
    // 当前花费时间
    current.t = 0;
    que.push(current);
    while (que.size())
    {
        // 做个备份
        const P p = que.front(); que.pop();
        for (int j = 1; j < 5; ++j)
        {
            current = p;
            current.x = current.x + dx[j];
            current.y = current.y + dy[j];
            ++current.t;

            if (current.x >= 0 && current.y >= 0 && m[current.x][current.y] > current.t && !visit[current.x][current.y])
            {
                visit[current.x][current.y] = true;
                // 爆炸时间大于当前时间，是安全的
                if (m[current.x][current.y] > last)
                {
                    // 当前位置爆炸时间大于流星雨最晚落下的时间，说明跑出了流星雨区域
                    return current.t;
                }
                que.push(current);
            }
        }
    }

    return -1;
}
int main(){
    //freopen("D://in.txt","r",stdin);
    Init();
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>bomb[i].x>>bomb[i].y>>bomb[i].t;
        last=std::max(last,bomb[i].t);
        for(int k=0;k<5;k++){
            int tempx=bomb[i].x+dx[k];
            int tempy=bomb[i].y+dy[k];
            if(Inmap(tempx,tempy)&&bomb[i].t<m[tempx][tempy]){
                m[tempx][tempy]=bomb[i].t;
            }
        }

    }

    if(m[0][0]==0){
        cout<<-1<<endl;
        return 0;
    }else{
        cout<<bfs()<<endl;
        return 0;
    }

}
