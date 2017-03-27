//给定一颗树，求从根结点到叶子节点的路径上等于目标的序列有哪些，手速题目
#include <bits/stdc++.h>
using namespace std;

#define N 107

int fa[N];
int val[N];
vector<int> G[N];
vector<vector<int> > ret;

int m, n, tar;

void done(int i) {
    vector<int> tmp;
    while (i) {
        tmp.push_back(val[i]);
        i = fa[i];
    }
    tmp.push_back(val[0]);
    reverse(tmp.begin(), tmp.end());
    ret.push_back(tmp);
}


void dfs(int root, int now) {

    if (G[root].size()==0) {
        if (now == tar) {
            done(root);
        }
        return;
    }

    for (int i=0; i<G[root].size(); i++) {
        int id = G[root][i];
        dfs(id, val[id] + now);
    }
}


int main() {
        //freopen("in.txt", "r", stdin);
        cin >> n >> m >> tar;
        for (int i=0; i<n; i++) cin >> val[i];
        for (int i=0; i<m; i++) {
            int id, num, x;
            cin >> id;
            cin >> num;


            for (int j=0; j<num; j++) {
                cin >> x;
                G[id].push_back(x);
                fa[x] = id;
            }
        }

        dfs(0, val[0]);
        sort(ret.begin(), ret.end());
        reverse(ret.begin(), ret.end());
        for (int i=0; i<ret.size(); i++) {
            for(int j=0; j<ret[i].size()-1; j++) {
                cout << ret[i][j] << " ";
            } cout << ret[i][ret[i].size()-1] << endl;
        }

}
