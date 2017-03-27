// 6643018_AC_0ms_0kB.cpp
#include <iostream>
#include <stdio.h>
#include <cstring>
#define N 1007
using namespace std;
#define M 10056

int C[N][N];
int f[N];
int n;
void pre() {
    memset(C, 0, sizeof(C));
    for (int i=0; i<N; i++) {
        C[i][0]=1;
        for (int j=1; j<=i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % M;
        }
    }
}

int fx(int n) {
    if (f[n]!=-1) return f[n];
    if (n==0) return f[0] = 1;
    if (n==1) return f[1] = 1;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        ans = ans + (C[n][i]*fx(n-i)) % M;
        ans = ans % M;
    }
    return f[n] = ans;
}

int main() {
    //freopen("in.txt", "r", stdin);
    pre();
    memset(f, -1, sizeof(f));
    int cases;
    cin >> cases;
    for (int T=1; T<=cases; T++) {
        cin >> n;
        printf("Case %d: %d\n", T, fx(n));
    }
}
