// 6744680_AC_47ms_1148kB.cpp
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
typedef long long LL;
LL n,m;
const int M = 100000000;
bool valid(LL i) {
    //检查最低的两个位是不是都是1，如果都是1，那么无效，如果不都是1，继续检查
    if ((i&(1<<0)) && (i&(1<<1))) return false;
    for (LL k=1; k<13; k++) {
        if ((i&(1<<k))==false) continue;
        if ((i&(1<<(k-1)))||(i&(1<<(k+1)))) return false;
    }
    return true;
}

LL dp[13][1<<12]; //考虑前i行状态是j的方法数目


LL G[13];

int main() {
    //freopen("in.txt","r", stdin);
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    for (LL i=1; i<=n; i++) {
        LL ans = 0;
        LL tmp;
        for (LL j=0; j<m; j++) {
            cin >> tmp;
            if (tmp)
            ans = ans | (1<<j);
        }
        G[i] = ans;
    }
    dp[0][0] = 1;
    for (LL i=1; i<=n; i++) {
        LL sub = G[i];
        do {
            if (valid(sub)) {
                LL ans = 0;
                for (LL j=0; j<(1<<m); j++) {
                    if (!(sub&j))
                        ans += dp[i-1][j];
                        ans = ans % M;
                }
                dp[i][sub] = ans;
            }

            //do something
            sub = (sub - 1) & G[i];
        }while (sub != G[i]);
    }
//    for (LL i=0; i<=2; i++) {
//        for (LL j=0; j<8; j++) {
//            cout << dp[i][j] << " ";
//        }cout << endl;
//    }
    LL ret = 0;
    for (int j=0; j<(1<<m); j++) {
        ret = ret + dp[n][j];
        ret = ret % M;
    }
    cout << ret << endl;


}
