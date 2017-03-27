// 6609743_AC_60ms_0kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define N  (1007)
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
int n, m;

struct Node {
    int vol, pow, pri, num;
};

bool cmp(const Node & n1, const Node & n2) {
    return n1.vol < n2.vol;
}
int sum[N];

Node a[N];
int dp[N];

int main() {

    //freopen("in.txt", "r", stdin);
    while (cin >> n && n) {
        memset(sum, 0, sizeof(sum));
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=n; i++) {
            scanf("%d%d%d%d", &a[i].vol, &a[i].pow, &a[i].pri, &a[i].num);

        }
        sort(a+1, a+n+1, cmp);
        for (int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i].num;
        for (int i=1; i<=n; i++) {
            
            int miner = 0x7fffffff;
            for (int j=0; j<=i-1; j++) {
                int tmp = dp[j];
                int add = (sum[i] - sum[j]) * a[i].pri + a[i].pow;
                miner = min(miner, tmp + add);
            }
            dp[i] = miner;
            
        }
        cout << dp[n] << endl;
    }

}

