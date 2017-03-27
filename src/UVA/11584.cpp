// 6610341_AC_220ms_0kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define N  (1007)
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f

int Pre[N][N];
int dp[N];

char a[N];
int n;

bool dfs(int i,int j) {
    if (Pre[i+1][j+1] !=- 1) return Pre[i+1][j+1];
    if (i >= j) return Pre[i+1][j+1] = 1;
    if (a[i] == a[j]) return Pre[i+1][j+1] = dfs(i+1, j-1);
    else return Pre[i+1][j+1] = 0;

}

int main() {

    //freopen("in.txt", "r", stdin);
    int cases;
    scanf("%d", &cases);
    getchar();
    while (cases--) {

        memset(Pre, -1, sizeof(Pre));
        memset(dp, -1, sizeof(dp));
        gets(a);
        n = strlen(a);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                dfs(i,j);
            }
        }

        dp[1] = 1;
        for (int i=2; i<=n; i++) {
            int miner = INF;
            if (Pre[1][i]) { dp[i]=1; continue; }
            for (int j=1; j<=i-1; j++) {
                if (Pre[j+1][i] == 1) {
                    miner = min(miner, dp[j] + 1);
                }
            }
            dp[i] = miner;
        }
        cout << dp[n] << endl;


    }

}

