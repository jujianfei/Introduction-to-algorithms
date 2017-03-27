// 5652161_AC_31ms_1592kB.cpp
#include<stdio.h>
#include<iostream>
using namespace std;

#define N 1000+7

int n,w;
int dp[N];//可能需要longlong
int a[N];
int v[N];
void Init(){
    for(int i=0;i<=w;i++){
        dp[i]=0;
    }
}

int main(){
    //freopen("D://in.txt","r",stdin);
    int cases;
    scanf("%d",&cases);
    while(cases--){
        Init();
        scanf("%d%d",&n,&w);
        for(int i=0;i<n;i++){
            scanf("%d",&v[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        for(int i=0;i<=n;i++){
            for(int j=w;j>=a[i-1];j--){
                dp[j]=std::max( dp[j], dp[j-a[i-1]] + v[i-1] );
            }
        }
        cout<<dp[w]<<endl;
    }
}


