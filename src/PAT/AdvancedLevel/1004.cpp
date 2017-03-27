// 给定一个树，统计每层上叶子节点有多少个，题目给出的n是多余条件

#include <bits/stdc++.h>
using namespace std;

#define N 507
#define INF 0x3f3f3f3f

vector<int> G[N];
int depth[N];
int n, m;
int cnt[N];
int max_depth = 0;
void BFS() {
    depth[1] = 0;
    deque<int> d;
    d.push_back(1);
    while (!d.empty()) {
        int fro = d.front();
        d.pop_front();
        for (int i=0; i<G[fro].size(); i++) {
            int x = G[fro][i];
            depth[x] = depth[fro] + 1;
            max_depth = max(max_depth, depth[x]);
            d.push_back(x);
        }
        if (G[fro].size()==0) {
            cnt[depth[fro]]++;
        }
    }

}

int main() {

    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int id, k;
        cin >> id >> k;
        int child_id;
        while (k--) {
            cin >> child_id;
            G[id].push_back(child_id);
        }
    }

    BFS();
    for (int i=0; i<max_depth; i++) {
        cout << cnt[i] << " ";
    }
    cout << cnt[max_depth] << endl;

}
