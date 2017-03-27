// 6663266_AC_0ms_0kB.cpp
#include <bits/stdc++.h>  
using namespace std;  
  
#define ft(i,s,t) for (int i=s;i<=t;i++)  
#define frt(i,t,s) for (int i=t;i>=s;i--)  
#define cls(v,c) memset(v,c,sizeof(v))  
const int INF=0x3f3f3f3f;  
const int N=205;  
  
int dp[N][2],kp[N][2],len,n;  
vector<int>v[N];  
string s1,s2,s;  
map<string,int>mp;  
  
void dfs(int u)  
{  
    dp[u][0]=0;dp[u][1]=1;  
    kp[u][0]=kp[u][1]=1;  //默认都是唯一的
    for (int i=0;i<v[u].size();i++)  
    {  
        int t=v[u][i];  
        dfs(t);  
        dp[u][0]+=max(dp[t][0],dp[t][1]);   
        dp[u][1]+=dp[t][0];  
        // 判断什么时候方案不唯一
        if (dp[t][0] > dp[t][1] && kp[t][0]==0) kp[u][0]=0; //  
        else if (dp[t][1]>dp[t][0] && kp[t][1]==0) kp[u][0]=0;  
        else if (dp[t][1]==dp[t][0]) kp[u][0]=0;  

        if (kp[t][0]==0) kp[u][1]=0;  // 如果选择了根节点节点，那么只有所有的孩子是唯一的才行，
    }  
  
}  
int main()  
{  
    while (~scanf("%d",&n)&&n)  
    {  
        ft(i,0,n) v[i].clear();  
        cls(dp,0);cls(kp,0);  
        mp.clear();len=1;  
        cin>>s;  
        mp[s]=len++;  
        ft(i,1,n-1)  
        {  
            cin>>s1>>s2;  
            if (mp.count(s1)==0) mp[s1]=len++;  
            if (mp.count(s2)==0) mp[s2]=len++;  
  
            v[mp[s2]].push_back(mp[s1]);  
        }  
        dfs(1);  
        if (dp[1][0]>dp[1][1]&&kp[1][0]) printf("%d Yes\n",dp[1][0]);  
        else if (dp[1][1]>dp[1][0]&&kp[1][1]) printf("%d Yes\n",dp[1][1]);  
        else printf("%d No\n",max(dp[1][0],dp[1][1]));  
    }  
}  