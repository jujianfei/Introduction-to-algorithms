//统计次数呗，水~
#include <bits/stdc++.h>
using namespace std;

string s, t;
map<char, int> mps;
map<char, int> mpt;


int main() {
    //freopen("in.txt", "r", stdin);
    cin >> s;
    cin >> t;
    for (int i=0; i<s.size(); i++) mps[s[i]]++;
    for (int i=0; i<t.size(); i++) mpt[t[i]]++;
    bool ok = true;
    int ret = 0;
    for (map<char, int>::iterator p = mpt.begin(); p!=mpt.end(); p++) {
        char c = p->first;
        int times = p->second;

        if (mps.find(c) == mps.end()) {
            ok = false;
            ret += times;
        } else {
            if (mps[c] < times) {
                ok = false;
                ret += (times-mps[c]);
            }
        }
    }

    if (ok) {
        cout << "Yes" << " " << s.size()-t.size() << endl;
    } else {
        cout << "No" << " " << ret << endl;
    }
}

