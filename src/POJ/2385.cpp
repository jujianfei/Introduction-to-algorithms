// 15281064_AC_0MS_1004K.cc
#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
#define N 1000+7
#define M 35
int n;
int m;
int dp[N][M][2];//一直到第i分钟，一共转移j次，在当前k树下能得到的最大值。
void Init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<2;k++){
                dp[i][j][k]=0;
            }
        }
    }
}

int a[N];
int y[2][N];

int main(){
    //freopen("D://in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);//掉苹果的树0或者1
        a[i]--;
        if(a[i]==0){
            y[0][i]=1;y[1][i]=0;
        }else{
            y[1][i]=1;y[0][i]=0;
        }
    }

    Init();

    dp[1][0][0]=y[0][1];
    dp[1][0][1]=0;
    dp[1][1][0]=0;
    dp[1][1][1]=y[1][1];

    for(int i=2;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                for(int k=0;k<=1;k++){
                    dp[i][j][k]=dp[i-1][j][k]+y[k][i];
                }
            }else{
                for(int k=0;k<=1;k++){
                    dp[i][j][k]=std::max(dp[i-1][j][k]+y[k][i],dp[i-1][j-1][1-k]+y[k][i]);
                }
            }

        }
    }


    int maxer=-1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=1;k++){
                if(dp[i][j][k]>maxer){
                    maxer=dp[i][j][k];
                }
            }
        }
    }
    cout<<maxer<<endl;
}
