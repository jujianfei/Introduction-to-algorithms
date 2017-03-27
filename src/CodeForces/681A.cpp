#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    string tmp;
    int ok = false;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        int a, b;
        cin >> a >> b;
        if (a >= 2400 && b > a) {
            ok = true;
        }
    }

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}