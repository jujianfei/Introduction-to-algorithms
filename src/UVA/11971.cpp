// 6639606_AC_0ms_0kB.cpp
#include <iostream>
#include <stdio.h>
#include <cstring>
#define N 10007
using namespace std;

long long n,k;
long long under, upper;
typedef long long ll;

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
int main() {
    //freopen("in.txt", "r", stdin);
    long long cases;
    cin >> cases;
    long long cnt = 0;
    while (cases--) {
        cnt ++;
        cin >> n >> k;
        ll upper = ((ll)1<<k) - k - 1;
        ll under = ((ll)1<<k);
        if (upper == 0) {
            under = 1;
        } else {
            ll gd = gcd(under, upper);
            upper /= gd;
            under /= gd;
        }
        cout << "Case #" << cnt <<": " << upper << "/" << under <<endl;
    }
}
