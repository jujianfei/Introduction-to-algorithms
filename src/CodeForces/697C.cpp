#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

map<ll, ll> mp;

int depth(ll x) {
    for (int i=63; i>=0; i--) {
        if (x&(1LL << i)) return i;
    }
    return -1;
}

void adder(ll a, ll b, ll x) {

    while (a!=b) {

        if (depth(a) > depth(b)) {
            mp[a] += x;

            a = a / 2;
        } else if (depth(a) < depth(b)) {
            mp[b] += x;

            b = b / 2;
        } else {
            mp[a] += x;
            mp[b] += x;

            a = a / 2;
            b = b / 2;
        }

    }

}


ll query(ll a, ll b) {
     ll ans = 0;
     while (a!=b) {

        if (depth(a) > depth(b)) {
            if (mp.find(a)!=mp.end()) {
                ans += mp[a];
            }
            a = a / 2;
        } else if (depth(a) < depth(b)) {
            if (mp.find(b)!=mp.end()) {
                ans += mp[b];
            }
            b = b / 2;
        } else {
            if (mp.find(a)!=mp.end()) {
                ans += mp[a];
            }
            a = a / 2;

            if (mp.find(b)!=mp.end()) {
                ans += mp[b];
            }
            b = b / 2;
        }

    }
    return ans ;
}

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    int type;
    for (int i=0; i<n; i++) {
        cin >> type;
        if (type == 1) {
            ll x, y, val;

            cin >> x >> y >> val;
            adder(x, y, val);
        } else {
            ll x, y;

            cin >> x >> y;
            cout << query(x, y) << endl;
        }
    }


}