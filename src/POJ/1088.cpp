// 15183589_AC_63MS_8600K.cc
#include<stdio.h>
#include<iostream>//iostream一定要放在stdio的后面
using namespace std;
int m,n;
//DP记忆化搜索
int dp[1003][1003];
int a[1003][1003];
int dirx[4]={-1,0,1,0};
int diry[4]={0,1,0,-1};

int dfs(int i,int j){
    if(dp[i][j]!=0) return dp[i][j];
    //如果越过了边界，那么是0

    if(i==0||j==0||i==n+1||j==m+1)return dp[i][j]=0;
    int maxer=0;
    for(int k=0;k<4;k++){
        if(a[i][j]>a[i+dirx[k]][j+diry[k]]){
            maxer=std::max(dfs(i+dirx[k],j+diry[k]),maxer);
        }
    }

    return dp[i][j]=maxer+1;

}


int main(){
   //freopen("D:\\in.txt","r",stdin);

   scanf("%d%d",&n,&m);{
    for(int i=0;i<1003;i++){
        for(int j=0;j<1003;j++){
            a[i][j]=-1;
            dp[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
          dfs(i,j);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans=std::max(ans,dp[i][j]);
        }
    }

    cout<<ans<<endl;
}
}



