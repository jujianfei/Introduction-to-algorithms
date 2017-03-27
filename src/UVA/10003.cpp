// 6616994_AC_790ms_0kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <sstream>
#include <deque>
#include <vector>
using namespace std;
#define N  1007
#define INF 0x3f3f3f3f

int dp[N][N];
int n ,L;

int a[N];


int dfs(int i, int j) {

    if (dp[i][j] != -1) return dp[i][j];
    if (i == j) return dp[i][j] = 0;

    if (i+1 == j) return dp[i][j] = 0;

    int maxer = INF;
    for (int k=i+1; k<=j-1; k++) {
        maxer = min(maxer, dfs(i, k) + dfs(k, j));
    }

    return dp[i][j] = maxer  + a[j] - a[i];

}




int main() {
    //freopen("in.txt", "r", stdin);
    while (cin >> n && n) {
        memset(dp, -1, sizeof(dp));
        memset(a, 0, sizeof(a));
        cin >> L;
        for (int i=1; i<=L; i++) {
            scanf("%d", &a[i]);
        }
        a[L+1] = n;
        cout << "The minimum cutting is "  << dfs(0, L+1) << "." << endl;
    }
}
