// 6564693_AC_50ms_0kB.cpp
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

#define N  100007
#define ll long long
int n;


int main() {
    //freopen("in.txt", "r", stdin);
    while (cin >> n && n) {
        ll ans = 0, last = 0, tmp;
        for (int i=0; i<n; i++) {
            cin >> tmp;
            ans += abs(last);
            last += tmp;
        }
        cout << ans << endl;
    }
}
