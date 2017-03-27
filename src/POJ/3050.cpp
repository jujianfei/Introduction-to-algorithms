// 15214440_AC_625MS_900K.cc
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
//#include"D://myapi.h"
using namespace std;
#define N 100000
int a[5][5];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int tmp[6];
int res[N][6];
int cnt_size=0;

void Input(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&a[i][j]);
        }
    }
}

bool compare_aux(int index){
    for(int i=0;i<6;i++){
        if(res[index][i]!=tmp[i]){
            return false;
        }
    }
    return true;
}

bool InRes(){
    for(int i=0;i<cnt_size;i++){
        if(compare_aux(i)==true){
            return true;
        }
    }
    return false;
}
bool Inmap(int x,int y){
    if(x<0||y<0||x>=5||y>=5)return false;
    else return true;
}

void dfs(int depth,int x,int y){
    if(depth==6){
        if(!InRes()){
            for(int i=0;i<6;i++){
                res[cnt_size][i]=tmp[i];
            }
            ++cnt_size;
        }
        return;
    }
    tmp[depth]=a[x][y];
    for(int k=0;k<4;k++){
        if(Inmap(x+dx[k],y+dy[k])){
            dfs(depth+1,x+dx[k],y+dy[k]);
        }
    }
}

int main(){
    //freopen("D://in.txt","r",stdin);
    Input();

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            dfs(0,i,j);
        }
    }
    cout<<cnt_size<<endl;


}
