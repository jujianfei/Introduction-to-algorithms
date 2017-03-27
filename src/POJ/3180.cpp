// 7011475_AC_235ms_2640kB.cpp
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <map>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
#define N 20007

vector<int> G[N];
vector<int> rG[N];
int used[N];
vector<int> res; // 后续遍历顺序点列表
int n, m;
int cmp[N]; //所属的强连通分量的拓扑编号
void add_edge(int from, int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
}


void dfs(int v) {
    used[v] = 1;
    for (int i=0; i<G[v].size(); i++) {
        if (!used[G[v][i]]) dfs(G[v][i]);
    }
    res.push_back(v);
}

void rdfs(int v, int k) {
    used[v] = 1;
    cmp[v] = k;
    for (int i=0; i<rG[v].size(); i++) {
        if (!used[rG[v][i]]) rdfs(rG[v][i], k);
    }
}

int scc() {
    memset(used, 0, sizeof(used));
    res.clear();
    for (int v=0; v<n; v++) {
        if (!used[v]) dfs(v);
    }
    memset(used, 0, sizeof(used));
    int k = 0;

    for (int i=res.size()-1; i>=0; i--) { //按照原来的图的拓扑排序的逆后序的反向

        if (used[res[i]]==false) rdfs(res[i], k++);
    }
    return k;
}
map<int,int> mp;
int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    int b, e;
    for (int i=0; i<m; i++) {
        scanf("%d%d", &b, &e);
        b--, e--;
        add_edge(b, e);
    }
    scc();
    for (int i=0; i<n; i++) {
        mp[cmp[i]]++;
    }
    int ans = 0;
    for (map<int,int>::iterator p=mp.begin(); p!=mp.end(); p++) {
        if (p->second >= 2) {
            ans ++;
        }
    }
    cout << ans << endl;

}

