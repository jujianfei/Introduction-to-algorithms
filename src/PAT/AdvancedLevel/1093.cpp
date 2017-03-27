// 简单的dp，先统计某个数字之前出现p的个数，pa的个数，pat的个数
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005
string s;
ll a[N], b[N], c[N];
int n;
int MOD = 1000000007;
int main() {
   // freopen("in.txt", "r", stdin);
    cin >> s;
    n = s.size();
    ll cnt = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'P') {
            cnt++;
        }
        a[i] = cnt;
    }

    cnt = 0;
    for (int i=1; i<n; i++) {
        if (s[i] == 'A') {
            cnt += a[i-1];
            cnt = cnt % MOD;
        }
        b[i] = cnt;
    }

    cnt = 0;
    for (int i=1; i<n; i++) {
        if (s[i] == 'T') {
            cnt += b[i-1];
            cnt = cnt % MOD;
        }
        c[i] = cnt;
    }
    cout << cnt << endl;
}
