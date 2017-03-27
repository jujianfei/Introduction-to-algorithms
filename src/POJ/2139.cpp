// 15234799_AC_32MS_968K.cc
#include<stdio.h>
#include<iostream>
using namespace std;
#define N 307
#define INF 0xfffffff
int n,m;
int D[N+1][N+1];//存放最短路
int G[N+1][N+1];//从1开始
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                G[i][j]=INF;
            }
    }
    for(int i=1;i<=n;i++){
        G[i][i]=0;
    }
}

void calculate(){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            D[i][j]=G[i][j];
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(D[i][j]>D[i][k]+D[k][j]){
                    D[i][j]=D[i][k]+D[k][j];
                }
            }
        }
    }
}

int tmp[N];
int main(){
    //freopen("D://in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    init();
    for(int line=1;line<=m;line++){
        int num;

        scanf("%d",&num);
        for(int i=0;i<num;i++){
            scanf("%d",&tmp[i]);
        };
        for(int i=0;i<num;i++){
            for(int j=i+1;j<num;j++){
                G[tmp[i]][tmp[j]]=G[tmp[j]][tmp[i]]=1;
            }
        }
    }
    calculate();


    int miner=INF;
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
            sum+=D[i][j];
        }
        miner=std::min(miner,sum);
    }

    double res=miner*1.0/(n-1)*100;
    cout<<int(res)<<endl;

}
