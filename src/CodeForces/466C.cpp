#include <bits/stdc++.h>
using namespace std;
#define N 1000007
#define INF 0x3f3f3f3f
long long n;
long long a[N];
long long sum = 0;
long long s[N];
int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for (long long i=1; i<=n; i++) {
       cin >> a[i];
       sum += a[i];
    }
    if (sum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }


    long long cnt = 0;
    long long ans = 0;
    for (long long i=1; i<n; i++) {
        s[i] = s[i-1] + a[i];

        if (s[i] * 3 == sum * 2) {
            ans += cnt;
        }
        if (s[i] * 3 == sum) {
            cnt++;
        }


    }

    cout << ans << endl;


}