// 6548960_AC_7250ms_33656kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <cmath>
#include <set>
#define INF 0x3f3f3f3f
using namespace std;
#define N  17
int n;

vector<int> a,b,c,d;
vector<int> a_b;

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    int tmpa,tmpb,tmpc,tmpd;
    for (int i=0;i<n;i++) {
        cin >> tmpa >> tmpb >> tmpc >> tmpd;
        a.push_back(tmpa);
        b.push_back(tmpb);
        c.push_back(tmpc);
        d.push_back(tmpd);
    }
    for (int i=0;i<a.size();i++) {
        for (int j=0;j<b.size();j++) {
            a_b.push_back(a[i] + b[j]);
        }
    }
    sort(a_b.begin(), a_b.end());

    int ans = 0;
    for (int i=0; i<c.size(); i++) {
        for (int j=0; j<d.size(); j++) {
            int target = - (c[i] + d[j]);
            ans += upper_bound(a_b.begin(),a_b.end(),target) - lower_bound(a_b.begin(),a_b.end(),target);
        }
    }
    cout << ans << endl;

}
