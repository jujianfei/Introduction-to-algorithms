#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N (1007)
using namespace std;
typedef long long ll;


ll exgcd(ll a,ll b,ll &x,ll &y) {
    if(b==0) {
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


ll A, B, C;

int main()
{
    //freopen("in.txt", "r", stdin);
    cin >> A >> B >> C;

    ll x, y;
    ll gd = exgcd(A, B, x, y);

    if (-C % gd != 0) cout << -1 << endl;
    else {
        ll n = -C / gd;
        cout << x*n << " " << y*n << endl;
    }




}