```C++
#include<string.h>  
#include<stdio.h>  
#include<math.h>  
const int MAX=200005;  
int min(int a,int b){return a<b?a:b;}  
int dp[MAX][20],a[MAX];  
int n,k,val[MAX];  
int  LOG[MAX];  
void Make_Rmq(int n,int b[])  
{  
    int i,j;  
    for(i=1;i<=n;i++)  
        dp[0][i]=b[i];  
    for(i=1;i<=LOG[n];i++)  
    {  
        int limit=n+1-(1<<i);  
        for(j=1;j<=limit;j++)  
            dp[i][j]=min(dp[i-1][j],dp[i-1][j+(1<<i>>1)]);  
    }  
}  
int RMQ(int l,int r)  
{  
    int  k=LOG[r-l+1];  
    return min(dp[k][l],dp[k][r-(1<<k)+1]);  
}  
  
void Make_Rmqindex(int n,int b[])  
{  
    int i,j;  
    for(i=1;i<=n;i++)  
        dp[0][i]=i;  
    for(i=1;i<=LOG[n];i++)  
    {  
        int limit=n+1-(1<<i);  
        for(j=1;j<=limit;j++)  
        {  
            int x=dp[i-1][j],y=dp[i-1][j+(1<<i>>1)];  
            dp[i][j]=b[x]<b[y]?x:y;  
        }  
    }  
}  
int Rmq_Index(int l,int r,int b[])  
{  
    int k=LOG[r-l+1];  
    int x=dp[k][l];  
    int y=dp[k][r-(1<<k)+1];  
    return b[x]<b[y]?x:y;  
}  
int main()  
{  
    int t,i,j;  
    LOG[0]=-1;  
    for(i=1;i<MAX;i++)  
        LOG[i]=LOG[i>>1]+1;  
    for(i=1;i<=10;i++)  
            val[i]=i;  
    Make_Rmqindex(10,val);  
    int l,r;  
    while(1)  
    {  
        scanf("%d%d",&l,&r);//l<r  
        int ans=Rmq_Index(l,r,val);  
        printf("%d\n",ans);  
    }  
    return 0;  
}  
```
