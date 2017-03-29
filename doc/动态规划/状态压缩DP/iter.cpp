#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 10;
const int INF = 0x3f3f3f3f;

int main(void)
{
    int n;
    int d[N+1][N+1];

    while (cin >> n && n) {
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= n; j ++) {
                scanf("%d", &d[i][j]);
            }
        }
/*
        for (int k = 0; k <= n; k ++) {
            for (int i = 0; i <= n; i ++) {
                for (int j = 0; j <= n; j ++) {
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
                }
            }
        }
*/
        int dp[1<<(N+1)][N+1];
        for (int k = (1<<(n+1))-1; k >= 0; k --)
            fill(dp[k], dp[k]+n+1, INF);
        dp[(1<<(n+1))-1][0] = 0;
        for (int k = (1<<(n+1))-2; k >= 0; k --) {
            for (int i = 0; i <= n; i ++) {
                for (int j = 0; j <= n; j ++) {
                    dp[k][i] = min(dp[k][i], d[i][j] + dp[k | 1 << j][j]);
                }
            }
        }
        printf("%d\n", dp[0][0]);
    }

    return 0;
}