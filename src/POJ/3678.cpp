// 7012108_AC_375ms_1348kB.cpp
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define N 10007

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
    for (int v=0; v<n * 2; v++) {
        if (!used[v]) dfs(v);
    }
    memset(used, 0, sizeof(used));
    int k = 0;

    for (int i=res.size()-1; i>=0; i--) { //按照原来的图的拓扑排序的逆后序的反向
        if (used[res[i]]==false) rdfs(res[i], k++);
    }
    return k;
}


void ADD(int a, int b, int flag, const string& tmp) {
    if (tmp == "AND" && flag) {
        add_edge(a+n, a);
        add_edge(b+n, b);
    } else if (tmp == "AND" && !flag) {
        add_edge(a, b+n);
        add_edge(b, a+n);
    } else if (tmp == "OR" && flag) {
        add_edge(a+n, b);
        add_edge(b+n, a);
    } else if (tmp == "OR" && !flag) {
        add_edge(a, a+n);
        add_edge(b, b+n);
    } else if (tmp == "XOR" && flag) {
        add_edge(a+n, b);
        add_edge(a, b+n);
        add_edge(b+n, a);
        add_edge(b, a+n);

    } else {
        add_edge(a, b);
        add_edge(b, a);
        add_edge(a+n, b+n);
        add_edge(b+n, a+n);
    }
}


int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    int a, b, flag;
    string tmp;
    for (int i=0; i<m; i++) {
        scanf("%d%d%d", &a, &b, &flag);
        cin >> tmp;
        ADD(a, b, flag, tmp);
    }
    scc();
    for (int i=0; i<n; i++) {
        if (cmp[i] == cmp[n + i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    

}

