// 6751127_AC_157ms_892kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N 100007
using namespace std;

int n, m, L;
int a[N];

bool can(int x) { //最小间隔是x行不行
    int cnt = 0;
    int sum = 0;
    for (int i=1; i<=n; i++) {
        sum += (a[i]- a[i-1]);
        if (sum <= x) {
            cnt ++;
        } else {
            sum = 0;
        }
    }
    return cnt <= m;
}

int main () {
    //freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &L, &n, &m);
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
    }
    a[0] = 0;
    a[n+1] = L;
    n = n + 1;
    sort(a,a+n);
    int r = INF;
    int l = 0;
    int mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (can(mid)) l = mid;
        else          r = mid;
    }
    cout << r << endl;




}
