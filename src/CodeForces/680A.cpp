
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

map<long long,long long> mp;
int main() {
    //freopen("in.txt", "r", stdin);
    vector<long long> v;
    long long tmp;
    for (long long i=0; i<5; i++) {
        cin >> tmp;
        mp[tmp]++;
        v.push_back(tmp);
    }

    long long ret = accumulate(v.begin(), v.end(), 0);
    long long ans = ret;
    for (auto &x : mp) {
        long long val = x.first, times = x.second;
        if (times >= 3) {
            ans = min(ans, ret-3*val);
        } else if (times >= 2) {
            ans = min(ans, ret-2*val);
        }
    }
    cout << ans << endl;


}
