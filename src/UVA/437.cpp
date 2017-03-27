// 6605034_AC_0ms_0kB.cpp
#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
struct node  
{  
    int l;  
    int w;  
    int h;  
    bool operator < (const node &a)const{  
        return l<a.l;  
    }  
}a[1001]; 
 
int n,dp[1001];  

int main()  
{  
    int cas=1;  
    while(scanf("%d",&n)&&n) {  
    int cur=0;  
    memset(dp,0,sizeof(dp));  
    for(int i=0;i<n;i++)  {  
        int ita,itb,itc;  
        scanf("%d%d%d",&ita,&itb,&itc);  
        a[cur++]=(node){max(ita,itb),min(ita,itb),itc};  
        a[cur++]=(node){max(ita,itc),min(ita,itc),itb};  
        a[cur++]=(node){max(itb,itc),min(itb,itc),ita};  
    }  
    sort(a,a+cur);  
    int ans=0;  
    for(int i=0;i<cur;i++)  
    {  
        int maxi=0;  
        for(int j=i-1;j>=0;j--)  
        if(a[i].l>a[j].l&&a[i].w>a[j].w)  
            maxi=max(maxi,dp[j]);  
        dp[i]=maxi+a[i].h;  
        ans=max(ans,dp[i]);  
    }  
    printf("Case %d: maximum height = %d\n",cas++,ans);  
    }  
    return 0;  
}  