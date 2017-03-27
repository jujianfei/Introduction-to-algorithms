// 6737833_AC_3782ms_4808kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>
#define INF 0x3f3f3f3f
using namespace std;
typedef int LL;
int n,m;
#define N 21
vector<int> G[N];
int dp[1<<20];



int main () {
    //freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &n, &m)) {
        memset(dp, 0 ,sizeof(dp));
        for (int i=0; i<N; i++) G[i].clear();
        for (int i=1; i<=n; i++) {
            int p,tmp;
            scanf("%d", &p);
            for (int j=0; j<p; j++) {
                scanf("%d", &tmp);
                G[i].push_back(tmp);
            }
        }

        for (int i=0; i<(1<<m); i++) dp[i] = 1;
        for (int i=1; i<=n; i++) { //使用滚动数组
            for (int j=(1<<m)-1; j>=0; j--) {
                int ans = 0;
                for (int k=0; k<G[i].size(); k++) {
                     if (j&(1<<(G[i][k]-1))) {
                        ans += dp[j&~(1<<(G[i][k]-1))];
                     }
                }
                dp[j] = ans;
            }
        }
        printf("%d\n",dp[(1<<m)-1]);
    }




}
