// 5991179_AC_15ms_236kB.cpp
#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
  
using namespace std;  
  
int a[1001];//炸药威力  
int dp[1001];  
  
int main()  
{  
    int n,i,j,mn,mx;  
    while(~scanf("%d",&n))  
    {  
        memset(dp,0,sizeof(dp));  
        for(i = 1; i <= n; ++i)  
        {  
            scanf("%d",&a[i]);  
            mn = mx = a[i];  
            for(j = i; j > 0; --j)  
            {  
                mn = min(mn,a[j]);//(j~i)最小威力  
                mx = max(mx,a[j]);//(j~i)最大威力  
                dp[i] = max(dp[j-1]+(mx-mn)*(mx-mn),dp[i]);  
            }  
        }  
        printf("%d\n",dp[n]);  
    }  
    return 0;  
} 