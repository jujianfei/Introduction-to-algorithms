#include <bits/stdc++.h>
using namespace std;

#define N 107



int main() {
    //freopen("in.txt", "r", stdin);
    string s;
    cin >> s;
    string t = s;
    reverse(s.begin(), s.end());
    cout << t + s << endl;
}