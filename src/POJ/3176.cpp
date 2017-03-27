// 15230132_AC_47MS_1704K.cc
#include<stdio.h>
#include<iostream>
using namespace std;
#define N 357
int dp[N][N];
int a[N][N];
int n;
int main(){
    //freopen("D://in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&a[i][j]);
        }
    }
    dp[1][1]=a[1][1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1) dp[i][j]=dp[i-1][j]+a[i][j];
            else dp[i][j]=std::max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
        }
    }
    int maxer=-1;
    for(int i=1;i<=n;i++){
        maxer=std::max(maxer,dp[n][i]);
    }
    cout<<maxer<<endl;
}
