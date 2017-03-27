#include <bits/stdc++.h>
using namespace std;

long long n, sum;

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n >> sum;
    char c;
    long long x;
    long long cnt = 0;
    for (long long i=0; i<n; i++) {
        cin >> c >> x;
        //cout << c << " " << x << endl;
        if (c=='+') {
            sum += x;
        } else {
            if (sum >= x) {
                sum -= x;
            } else {
                cnt ++;
            }
        }
        //cout << "sum " << sum << endl;
    }
    cout << sum << " " << cnt << endl;

}