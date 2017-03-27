// 15272786_AC_2000MS_628K.cpp
#include<stdio.h>
#include<iostream>
using namespace std;
#define M 100000+7
#define N 107
#include<string.h>
int dp[M];
int n,w;
int a[N];
int m[N];
void Init(){
    memset(dp,-1,sizeof(dp));
}

int solve(){
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=w;j++){
            if(dp[j]>=0){
                dp[j]=m[i];
            }else if(j<a[i] || dp[j-a[i]]<=0){
                dp[j]=-1;
            }else{
                dp[j]=dp[j-a[i]]-1;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=w;i++){
        if(dp[i]>=0)cnt++;
    }
    return cnt;
}

int main(){
    //freopen("D://in.txt","r",stdin);
    while(~scanf("%d%d",&n,&w)){
        Init();
        if(n==0&&w==0)break;
        for(int i=0;i<n;i++){scanf("%d",&a[i]);}
        for(int i=0;i<n;i++){scanf("%d",&m[i]);}
        cout<<solve()<<endl;
    }
}
