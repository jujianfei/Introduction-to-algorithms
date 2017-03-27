//这才叫pat嘛，有点技术含量哈，先dfs确定出每个节点的前序遍历的
// 大小，同时对数组进行排序，然后想对应即可求出每个节点的变量然后
// BFS 就能求出
#include <bits/stdc++.h>
using namespace std;

#define N 107

int G[N][2];
int ranker[N];
int val[N];
int n;

int cnt = -1;
void dfs(int u) {

    if (G[u][0] != -1) dfs(G[u][0]);
    cnt ++;
    ranker[u] = cnt;
    if (G[u][1] != -1) dfs(G[u][1]);
}

int a[N];

int main() {
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        G[i][0] = a, G[i][1] = b;
    }

    dfs(0);

    //for (int i=0; i<n; i++) cout << ranker[i] << " "; cout << endl;


    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    for (int i=0; i<=n; i++) {
        val[i] = a[ranker[i]];
    }


    deque<int> pq;
    vector<int> ret;
    pq.push_back(0);
    while(pq.empty()==false) {
        int fro = pq.front();
        ret.push_back(val[fro]);
        pq.pop_front();
        if (G[fro][0] != -1) {
            pq.push_back(G[fro][0]);
        }
        if (G[fro][1] != -1) {
            pq.push_back(G[fro][1]);
        }
    }
    for (int i=0; i<ret.size(); i++) {
        if (i!=ret.size()-1) {
            cout << ret[i] << " ";
        } else {
            cout << ret[i] << endl;
        }
    }


}
