// 尺取法，贪心，爆了longlong，开始没有后发现wa了一次
#include <bits/stdc++.h>
using namespace std;
#define N 100005

long long n;
long long p;
long long a[N];

bool ok(long long l, long long r) {
    if (a[l] * p >= a[r]) return true;
    else return false;
}

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n >> p;
    for (long long i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+n+1);

    long long ret = 1;
    long long l = 1, r = 1;
    while (l <= n && r <= n) {
        if (ok(l, r)) {
            ret = max(ret, r-l+1);
            r ++;
        } else {
            l ++;
        }
    }
    cout << ret << endl;

}

