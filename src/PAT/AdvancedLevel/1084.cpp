// 破损的键盘，模拟，水题
#include <bits/stdc++.h>
using namespace std;

#define N 10007
string s, t;


int main() {
    //freopen("in.txt", "r", stdin);
    cin >> s >> t;
    int cur = 0;
    int n= s.size();
    vector<char> ret;
    set<char> already;
    for (int i=0; i<n; i++) {
        if (cur == t.size() || s[i] != t[cur]) {
            char up = s[i];
            if (islower(up)) {
                up = s[i]-32;
            }
            if (already.find(up) == already.end()) {
                    already.insert(up);
                    ret.push_back(up);
            }
        } else {
            cur ++;
        }
    }
    for (int i=0; i<ret.size(); i++) {
        cout << ret[i];
    } cout << endl;

}

