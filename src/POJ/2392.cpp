// 6581571_AC_47ms_1060kB.cpp
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <deque>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define N 407
int n;
#define M 40007
struct Node {
    int h,c,m;
};
bool cmp(const Node & n1, const Node & n2) { return n1.m < n2.m; }

Node a[N];
int dp[M];
int sum[M];
int main() {
    ///freopen("in.txt", "r", stdin);
    while (cin >> n) {
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<n; i++) {
            scanf("%d%d%d", &a[i].h, &a[i].m, &a[i].c);
        }
        sort(a, a+n, cmp);
        dp[0]=1;
        int ans = 0;
        for (int i=0;i<n;i++) {
            memset(sum, 0, sizeof(sum));
            for (int j=a[i].h; j<=a[i].m; j++) {
                if (!dp[j] && dp[j-a[i].h] && sum[j-a[i].h] < a[i].c) {
                    dp[j] = 1;
                    sum[j] = sum[j-a[i].h] + 1;
                    ans = max(ans, j);
                }
            }
        }
//        for (int i=0;i<=60;i++) {
//            cout << i << ": " << dp[i] << endl;
//        }
        cout << ans << endl;
    }






}
