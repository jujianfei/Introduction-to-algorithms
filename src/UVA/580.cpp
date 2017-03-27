// 6640989_AC_0ms_0kB.cpp
#include <iostream>
#include <stdio.h>
#include <cstring>
#define N 100007
#include <cmath>
using namespace std;

long long f[N],g[N];
int n;
long long gx(int n);

long long fx(int n) {
    if (f[n]!=-1)return f[n];
    long long ret = ((long long)(1<<(n-3)));
    for (int i=2; i<=n-2; i++) {
        ret += gx(i-2) * ((long long)(1<<(n-i-2)));
    }
    return f[n] = ret;
}

long long gx(int n) {
    if (g[n]!=-1)return g[n];
    else return g[n] = ((long long)(1<<n)-fx(n));
}
int main() {
    //freopen("in.txt", "r", stdin);
    memset(f, -1, sizeof(f));
    memset(g, -1, sizeof(g));
    f[0]=f[1]=f[2]=0;
    g[0]=1;g[1]=2;g[2]=4;
    while (cin >> n && n) {
        cout << fx(n) << endl;
    }

}
