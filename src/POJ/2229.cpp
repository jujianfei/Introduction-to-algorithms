// 15260403_AC_125MS_8552K.cc
#include<stdio.h>
#include<iostream>
#define N 1000000+7
long long dp[N];
using namespace std;
int n;
const int M = 1000000000;
int main(){
    //freopen("D://in.txt","r",stdin);
    for(int i=0;i<N;i++){
        dp[i]=-1;
    }
    dp[1]=1;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        if(i%2){
            dp[i]=dp[i-1];
        }else{
            dp[i]=(dp[i>>1]+dp[i-1]) % M;
        }
    }
    cout<<dp[n]<<endl;
}
