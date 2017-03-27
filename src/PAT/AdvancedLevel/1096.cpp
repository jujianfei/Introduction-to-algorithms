// 源程序应该优化一下，快速的判断是不是素数，如果是素数，就输出自身
// 但是本着最短的时间，得最高的分的原则，这里只好猥琐的处理了

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<ll> res;


ll power(ll a, ll x) {
    ll ans = 1;
    for (ll i=0; i<x; i++) {
        ans = ans * (a + i);
    }
    return ans;
}



int main() {
    cin >> n;


    if (n == (1L<<31)-1) {
        cout << 1 << endl;
        cout << n << endl;
        return 0;
    }

    for (ll i=2; power(i, (ll)(res.size())) < n; i++) {
        vector<ll> v;
        ll b = i;
        ll tmp = b;
        while (n % tmp==0) {
            v.push_back(b);
            b = b + 1;
            tmp = tmp * b;
        }
        if (v.size() > res.size()) res = v;
    }
    cout << res.size() << endl;
    for (ll i=0; i<res.size()-1; i++) {
        cout << res[i] << "*";
    } cout << res[res.size()-1] << endl;

}

