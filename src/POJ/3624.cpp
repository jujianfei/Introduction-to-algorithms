// 15693560_AC_329MS_808K.cc
#include <iostream>
#include <stdio.h>
using namespace std;
#define N 3500
#define M 12887
int v[N];
int w[N];

int n,m;
int dp[M];


int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d%d",&n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d%d",&v[i], &w[i]);
    }

    for (int i=1; i<=n; i++) {
        for (int j=m; j>=0; j--) {
            if (j < v[i-1]) {
                ;
            } else {
                dp[j] = max(dp[j], dp[j-v[i-1]]+w[i-1]);
            }
        }
    }
    cout << dp[m] << endl;
}
