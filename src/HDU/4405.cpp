// 5648105_AC_31ms_2752kB.cpp
#include<stdio.h>
#include<iostream>

using namespace std;
#define N 100000+10
#define M 1000+7
int n,m;
int fl[N];
double dp[N];
void Init(){
    for(int i=0;i<N;i++){
        fl[i]=-1;
        dp[i]=-1.0;
    }
}

int get(int i){

    int tar=fl[i];
    if(tar==-1)return -1;
    do{
        int tmp=fl[tar];
        if(tmp==-1)
            return tar;
        else
            tar=tmp;
    }while(1);
}

int main(){
    //freopen("D://in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)){
        Init();
        if(m==0&&n==0)break;
        int from,end;
        for(int i=0;i<m;i++){
            scanf("%d%d",&from,&end);
            fl[from]=end;
        }

        for(int i=0;i<=7;i++){
            dp[n+i]=0.0;
        }

        for(int i=n-1;i>=0;i--){
            double sum=0.0;
            for(int k=1;k<=6;k++){
                int next=get(i+k);
                if(next==-1){
                    sum+=dp[i+k];
                }else{
                    sum+=dp[next];
                }
            }
            dp[i]=sum/6.0+1.0;
        }
        printf("%.4f\n",dp[0]);

    }
}
