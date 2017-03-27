// 6545679_AC_63ms_1104kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;
#define N   100007
#define INF 0xfffffff
int n,m;
int a[N];

int main() {
    //freopen("in.txt", "r", stdin);
    int cases;
    cin >> cases;
    while (cases -- ) {
        int ans = INF;
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        int p=0,q=0;
        int sum = 0;
        while (q!=n) {
            while (sum < m && p!=n) {
                sum += a[p];
                p++;
            }
            if (sum >= m) {
                //cout <<" update when " << q << " " << p << endl;
                ans = min(ans, p-q);
            }
            sum = sum - a[q];
            q++;
        }
        if (ans == INF) {
            ans = 0;
        }
        cout << ans << endl;
    }
}
