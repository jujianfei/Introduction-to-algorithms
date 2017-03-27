// 15282347_AC_110MS_1024K.cc
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define N 40000+7
#include<string.h>
#define INF 0xfffffff
using namespace std;

int a[N];
int dp[N];
int n,x;
int main(){
    //freopen("D://in.txt","r",stdin);
    int cases;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            dp[i]=INF;
        }
        for(int i=0;i<n;i++){
            *lower_bound(dp,dp+n,a[i])=a[i];
        }
        cout<<lower_bound(dp,dp+n,INF)-dp<<endl;
    }
}
