#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N (107)
using namespace std;
typedef long long ll;

const int maxn=  150  ;

int dp[maxn+5][maxn+5];
int DP(int a,int b)
{
    if(~dp[a][b])  return dp[a][b];
    if(a==0||b==0||a==1&&b==1)  return dp[a][b]=0;
    if(a==1)  return dp[a][b]=1+DP(a+1,b-2);
    else if(b==1)   return dp[a][b]=1+DP(a-2,b+1);

    dp[a][b]=max(1+DP(a+1,b-2),1+DP(a-2,b+1));
    return dp[a][b];
}
int main()
{
    int a,b;
    memset(dp,-1,sizeof dp);
    while(~scanf("%d%d",&a,&b))
    {
        printf("%d\n",DP(a,b));
    }

   return 0;
}
