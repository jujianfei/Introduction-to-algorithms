// 纯水题，注意不要用cin
#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int n, m;
int main() {
        //freopen("in.txt", "r", stdin);
        scanf("%d%d", &n, &m);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int tmp;
                scanf("%d", &tmp);
                mp[tmp] ++;
            }
        }
        map<int,int>::iterator p=mp.begin();
        for (; p!=mp.end(); p++) {
            if (p->second > m*n /2) {
                cout << p->first << endl;
                return 0;
            }
        }


}
