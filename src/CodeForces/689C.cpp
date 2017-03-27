#include <bits/stdc++.h>
using namespace std;

#define N 200007
using ll = long long;


ll f(ll x) {
    ll ans = 0;
    for (ll k=2; ; k++) {
       ll b = x / (k*k*k);
       if (b == 0) break;
       ans += b;
    }
    return ans;
}

int main() {

    //freopen("in.txt", "r", stdin);
    ll n;
    cin >> n;
    ll left = 1;
    ll right = 1LL<<60;
    ll mid;

    while (right-left > 1 ) {

        mid = (left + right) / 2;
        //cout << "mid " << mid << endl;
        if (f(mid) < n) {
            left = mid;
        } else if (f(mid) >= n) {
            right = mid;
        }


    }

    if (f(left) == n) cout << left << endl;
    else if (f(right) ==n) cout << right << endl;
    else cout << -1 << endl;



}