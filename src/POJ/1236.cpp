// 7011738_AC_0ms_756kB.cpp
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define N 207
vector<int> G[N];
vector<int> rG[N];
vector<int> DAG[N];
int in[N];
int out[N];
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




int Count() {
    int ret = 0;
    for (int i=0; i<n; i++) {
        if (in[i]==0) ret++;
    }
    return ret;
}


int Cnt() {
    int fir = 0;
    for (int i=0; i<n; i++) {
        if (in[i] == 0) fir ++;
    }
    int sec = 0;
    for (int i=0; i<n; i++) {
        if (out[i] == 0) sec ++;
    }
    return max(fir, sec);
}

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int tar;
        while(scanf("%d", &tar) && tar!=0) {
            tar--;
            add_edge(i, tar);
        }
    }
    int tmp = scc();
    //cout << scc() << endl;



    for (int i=0; i<n; i++) {
        for (int k=0; k<G[i].size(); k++) {
            int b = cmp[i], e = cmp[G[i][k]];
            if (b==e) continue;
            DAG[b].push_back(e);
        }
    }
    n = tmp;
    for (int i=0; i<n; i++) {
        sort(DAG[i].begin(), DAG[i].end());
        DAG[i].erase(unique(DAG[i].begin(), DAG[i].end()), DAG[i].end());
        for (int j=0; j<DAG[i].size(); j++) {
            int b = i, e = DAG[i][j];
            out[b] ++;
            in[e] ++;
        }
    }
    if (n == 1) {
        cout << "1" << endl;
    } else {
        cout << Count() << endl;
    }

    if (n == 1) {
        cout << "0" << endl;
    } else {
        cout << Cnt() << endl;
    }




}

