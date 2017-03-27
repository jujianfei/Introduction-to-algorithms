// 6751236_AC_110ms_1092kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N 1050007
using namespace std;

struct Node {
    int w,s;
    bool operator < (const Node &n) const {
        return n.w + n.s < w + s;
    }
};

int sum;
int n;
Node a[N];

int main () {
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d%d", &a[i].w, &a[i].s);
        sum += a[i].w;
    }
    sort(a, a+n);

    int maxer = -INF;
    for (int i=0; i<n; i++) {
        sum -= a[i].w;
        maxer = max(maxer, sum-a[i].s);
    }
    cout << maxer << endl;



}
