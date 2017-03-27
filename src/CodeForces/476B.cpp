#include <bits/stdc++.h>
using namespace std;
#define N 107
#define INF 0x3f3f3f3f

string a, b;
int ori;



double dp[N][N];

double dfs(int i, int j) {

    if (dp[i][j] != INF) return dp[i][j];

    if (i==0) {
        if (j == 0) return dp[0][0] = 1;
        else return dp[0][j] = 0;
    }

    char c = b[i-1];
    if (c=='+') return dp[i][j] = dfs(i-1, j-1);
    else if (c=='-') return dp[i][j] = dfs(i-1, j+1);
    else return dp[i][j] = 0.5 * (dfs(i-1, j-1) + dfs(i-1, j+1));
}


int main() {

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            dp[i][j] = INF;

    //freopen("in.txt", "r", stdin);



    cin >> a >> b;
    for (int i=0; i<a.size(); i++) {
        if (a[i] == '+') ori++;
        else ori --;
    }
    printf("%.12f\n", dfs(b.size(), ori));
}