// 5652109_AC_15ms_1584kB.cpp
#include<stdio.h>
#include<iostream>
using namespace std;
int n,w;
int dp[10][50];//前i门课凑出j的学分有多少种组合
int a[10],b[10];
void Init(){
    for(int i=0;i<10;i++){
        for(int j=0;j<50;j++){
            dp[i][j]=0;
        }
    }
}

int main(){
    //freopen("D://in.txt","r",stdin);
    int cases;
    scanf("%d",&cases);

    while(cases--){
       scanf("%d%d",&w,&n);//w学分，n门课

       Init();
       for(int i=0;i<n;i++){
           scanf("%d%d",&a[i],&b[i]);
       }
       dp[0][0]=1;
       for(int i=1;i<=n;i++){
           for(int j=0;j<=w;j++){
               int sum=0;
               for(int k=0;k<=b[i-1];k++){
                   if(j-k*a[i-1]>=0)
                        sum += dp[i-1][j-k*a[i-1]];
               }
               dp[i][j]=sum;
           }
       }
       cout<<dp[n][w]<<endl;

    }


}
