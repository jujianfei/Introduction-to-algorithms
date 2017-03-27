#include <bits/stdc++.h>
using namespace std;

long long m, n;

long long fir[5];
long long sec[5];

int main() {
    cin >> n >> m;
    long long xm = m / 5;
    long long lm = m % 5;
    long long xn = n / 5;
    long long ln = n % 5;

    for (long long i=0; i<5; i++) {
        if (i<=ln) fir[i] = xn + 1;
        else  fir[i] = xn;
    }
    fir[0] --;
    for (long long i=0; i<5; i++) {
        if (i<=lm) sec[i] = xm + 1;
        else sec[i] = xm;
    }
    sec[0] --;
    long long ans = 0;
    for (long long i=0; i<=4; i++) {
        if (i == 0) ans += fir[i] * sec[i];
        else ans += fir[i] * sec[5-i];
    }
    cout << ans << endl;
}