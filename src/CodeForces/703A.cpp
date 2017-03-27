#include <bits/stdc++.h>
using namespace std;
int fir=0, sec=0;
int main() {
    int n;
    cin >> n;
    int x, y;
    for (int i=0; i<n; i++) {
        cin >> x >> y;

        if (x > y ) fir ++;
        else if (x < y) sec++;
        else {}
    }
    if (fir > sec) cout << "Mishka" << endl;
    else if (fir < sec) cout << "Chris" << endl;
    else cout << "Friendship is magic!^^" << endl;
}