// 6565659_AC_260ms_0kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <cmath>
#include <set>

#define INF 0x3f3f3f3f
using namespace std;

#define N  1000007
#define ll long long
int n;

int v[N];

int main()
{
    int T,n;
    //freopen("in.txt", "r", stdin);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",&v[i]);

        set<int>s;
        int l=0,r=0,ans=0;
        while(l<n)
        {
            while (r<n&&s.find(v[r])==s.end()) s.insert(v[r++]);
            ans=max(ans,r-l);
            s.erase(v[l++]);
        }
        printf("%d\n",ans);
    }
}
