// 6546227_AC_500ms_2004kB.cpp
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
using namespace std;
#define N   1000007
#define INF 0x3f3f3f3f
int n,m;
int a[N];
set<int> st;
map<int,int> mp;
int main() {
    //freopen("in.txt", "r", stdin);
    while (cin >> n) {
        st.clear();
        mp.clear();
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            st.insert(a[i]);
        }
        int m = st.size();
        int p=0, q=0;
        int ans = n;
        while (q!=n) {
            while (mp.size() < m && p!=n) {
                mp[a[p]] ++;
                p++;
            }
            if (mp.size()==m) {
                ans = min(ans, p-q);
            }
            if (mp[a[q]]==1) {
                mp.erase(a[q]);
            } else {
                mp[a[q]]--;
            }
            q++;
        }
        cout << ans << endl;
    }
}
