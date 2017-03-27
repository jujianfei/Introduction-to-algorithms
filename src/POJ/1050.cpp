// 6575369_AC_16ms_768kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <cmath>
#include <set>
#define INF 0x3f3f3f3f
using namespace std;
#define N  107
#define ll long long

int n;
int a[N][N];

int c[N];
int d[N];
int find_max() {
    d[1]=c[1];
    for (int i=2;i<=n;i++) {
        if (d[i-1] < 0) {
            d[i] = c[i];
        } else {
            d[i] = d[i-1] + c[i];
        }
    }
    int maxer = -INF;
    for (int i=1; i<=n; i++) {
        maxer = max(maxer, d[i]);
    }
    return maxer;
}



int main()
{
    //freopen("in.txt", "r", stdin);
    while(~scanf("%d", &n)) {
        memset(a, 0, sizeof(a));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        int ans = -INF;
        for (int i=1; i<=n; i++) {
            memset(c, 0, sizeof(c));
            for (int j=i; j<=n; j++) {
                for (int k=1; k<=n; k++) {
                    c[k] += a[j][k];
                }

                ans = max(ans, find_max());
            }
        }
        cout << ans << endl;




    }
    //


}
