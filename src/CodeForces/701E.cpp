#include <bits/stdc++.h>
using namespace std;
#define N 501
int dp[N][N];
int a[N];
int n, K;


int main() {
        //memset(dp, -1, sizeof(dp));
        //freopen("in.txt", "r", stdin);
        cin >> n >> K;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }

        dp[0][0] = 1;
        for (int i=1; i<=n; i++) { // 当前考虑第i个物品
            for (int j=K; j>=0; j--) { // 能够凑成j的价值
                for (int k=K; k>=0; k--) { // 能否参与构成这个值
                    if (dp[j][k]) dp[j][k] = 1;
                    int value = a[i];
                    if ( j>=value && dp[j-value][k]) dp[j][k] = 1;
                    if (j>=value && k>=value && dp[j-value][k-value]) dp[j][k] = 1;

                }
            }
        }
        int ans = 0;
        for (int i=0; i<=K; i++) {
            if (dp[K][i]) ans++;
        }
        cout << ans << endl;
        for (int i=0; i<=K; i++) {
            if (dp[K][i]) cout << i << " ";
        }
        cout << endl;
}