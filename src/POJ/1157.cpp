// 15184887_AC_16MS_804K.cc
#include<stdio.h>
#include<iostream>//iostream一定要放在stdio的后面
#define INF 0xfffffff
#include <cstdio>
#include <queue>
#include<vector>
#include<set>
#define clrbit(x,y) x&=~(1<<(y-1))//将第i位数清零，i从1开始-->这里最大是20
using namespace std;
#define INF -200000000
int dp[107][107];
int a[107][107];
//二进制操作
int n,m;

void Init(){
    for(int i=0;i<107;i++){
        for(int j=0;j<107;j++){
            dp[i][j]=INF;
        }
    }
}


int main(){
    //freopen("D://in.txt","r",stdin);
    Init();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    dp[1][1]=a[1][1];
    //先处理第一行
    for(int i=2;i<=m;i++){
        dp[1][i]=std::max(a[1][i],dp[1][i-1]);
    }

    for(int i=2;i<=n;i++){
        for(int j=i;j<=m;j++){
            dp[i][j]=std::max(dp[i][j-1],dp[i-1][j-1]+a[i][j]);
        }
    }
    cout<<dp[n][m]<<endl;

}
