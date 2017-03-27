// 集合的相似度问题，使用好stl的set即可
#include <bits/stdc++.h>
using namespace std;
#define N 10007
set<int> v[N];
int n;

double q(int a, int b) {
    int total = v[a].size() + v[b].size();
    int cnt = 0;
    for (set<int>::iterator p = v[a].begin(); p!=v[a].end(); p++) {
        int val = *p;
        if (v[b].find(val) != v[b].end()) cnt ++;
    }
    return cnt*1.0/(total-cnt);
}


int main() {
      //freopen("in.txt", "r", stdin);
      cin >> n;
      int m;
      for (int i=0; i<n; i++) {
            int m;
            cin >> m;
            int tmp;
            while (m--) {
                cin >> tmp;
                v[i].insert(tmp);
            }
      }

      int K;
      cin >> K;
      int a, b;
      for (int i=0; i<K; i++) {
            cin >> a >> b;
            a--, b--;
            printf("%.1f%%\n", q(a, b) * 100);
      }

}
