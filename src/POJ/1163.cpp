// 15185229_AC_16MS_812K.cc
#include<stdio.h>
#include<iostream>//iostream一定要放在stdio的后面
#define INF 0xfffffff
#include <cstdio>
#include <queue>
#include<vector>
#include<set>
#define clrbit(x,y) x&=~(1<<(y-1))//将第i位数清零，i从1开始-->这里最大是20
using namespace std;
#define INF 200000000
//记忆化搜索
int dp[107][107];
int a[107][107];
int n;
void Init(){
    for(int i=0;i<107;i++){
        for(int j=0;j<107;j++){
            dp[i][j]=-1;
            a[i][j]=-1;
        }
    }
}
int dfs(int  i,int j){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==n) return dp[i][j]=a[i][j];
    return dp[i][j]=std::max(dfs(i+1,j),dfs(i+1,j+1))+a[i][j];
}

int main(){
    //freopen("D://in.txt","r",stdin);
    scanf("%d",&n);
    Init();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&a[i][j]);
        }
    }
    cout<<dfs(1,1)<<endl;

}
