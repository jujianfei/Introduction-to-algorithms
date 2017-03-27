// 6999273_AC_16ms_724kB.cpp
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string.h>
#define N 100007
using namespace std;
typedef long long ll;

ll A, B, C, k;

ll a, b, m;

ll gcd(ll a, ll b){ return a == 0 ? b : gcd(b % a, a); }

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll r=exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return r;
}

ll mod_inverse(ll a, ll m) {
	ll x, y;
	exgcd(a, m, x, y);
	return (m + x % m) % m;
}

int main() {


    //freopen("in.txt", "r", stdin);
    while (cin >> A >> B >> C >> k) {
        if (!A&&!B&&!C&&!k) break;
        a = C;
        m = 1LL << k;
        b = (B - A + m) % m;
        ll g = gcd(a, m);
        if (b % g!=0) {
            cout << "FOREVER" << endl;
            continue;
        }

        a = a / g;
        m = m / g;
        b = b / g;

        ll res = (mod_inverse(a, m) * b) % m;
        cout << res << endl;

    }

}
