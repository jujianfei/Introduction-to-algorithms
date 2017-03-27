// 15281804_AC_47MS_5488K.cc
#include<stdio.h>
#include<iostream>
using namespace std;
#define N 10000+7
#define PRIM 1000000
#include<string.h>
long long dp[N][N];
int n,b,e,m,tmp;
int a[N];//第i种物品有多少个
void Init(){
    for(int i=0;i<N;i++){
        a[i]=0;
    }
}

int main(){
    //freopen("D://in.txt","r",stdin);
    Init();
    scanf("%d%d%d%d",&n,&m,&b,&e);//一共用n种物品，接下来有m行
    for(int i=0;i<m;i++){
        scanf("%d",&tmp);
        a[tmp-1]++;
    }

    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }

    long long ans=0;

    for(int i=0;i<n;i++){
        for(int j=1;j<=e;j++){

            if(j-1-a[i]>=0){
                dp[i+1][j]=(dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]]+PRIM) % PRIM;

            }else{
                dp[i+1][j]=(dp[i+1][j-1]+dp[i][j])%PRIM;
            }

            if(j>=b&&j<=e&&i==n-1)
                ans+=dp[i+1][j];
        }
    }
    cout<<ans%PRIM<<endl;
}
