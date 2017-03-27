// 6608625_AC_0ms_0kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define N  (100007)
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
int n, m;

struct Node {
    int x,y;
    Node(int x,int y):x(x), y(y){}
    Node() {}
};

Node dp[N];
int a[N];


int main() {
    //freopen("in.txt", "r", stdin);
    int T;
    int cnt=0;
    for (cin >> T; T; T--) {
        cnt++;
        memset(dp, 0, sizeof(dp));

        scanf("%d%d", &n, &m);
        m--;
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i=0; i<n; i++) {

            for (int j=m; j>=0; j--) {
                if (j>=a[i]) {
                    if (dp[j-a[i]].x + 1 > dp[j].x) {
                        dp[j].x = dp[j-a[i]].x + 1;
                        dp[j].y = dp[j-a[i]].y + a[i];
                    } else if (dp[j-a[i]].x + 1 == dp[j].x && dp[j-a[i]].y + a[i] > dp[j].y) {
                        dp[j].y = dp[j-a[i]].y + a[i];
                    } else {}
                }
            }
        }
        printf("Case %d: %d %d\n", cnt, dp[m].x+1, dp[m].y + 678);

    }
}

