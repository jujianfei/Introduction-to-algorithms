#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

bool get(ll tar) {
    if (tar % 1234LL == 0) {
        //cout << tar / 1234LL << " k " << endl;
        return true;
    }
    else return false;
}

bool can(ll tar) {
    int ok = false;
    for (ll i=0; i*123456LL<=tar; i++) {
        if (get(tar-i*123456LL)) {
            ok = true;
            //cout << i << " j " << endl;
            break;
        }
    }
    return ok;
}


int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    ll ok = false;
    for (ll i=0; i*1234567LL<=n; i++) {
        if (can(n - i*1234567LL)) {
            ok = true;
            //cout << i << " i " << endl;
            break;
        }
    }
    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


}