// 基础并查集，手速题

#include <bits/stdc++.h>
using namespace std;
#define N 10005
int fa[N];
int mark[N];
int getroot(int x) {
    if (x != fa[x]) {
        fa[x] = getroot(fa[x]);     //回溯时的压缩路径
    }
    return fa[x];
}

bool q_m(int i,int j) {
    return getroot(i) == getroot(j);
}

void merger(int i,int j) {
    fa[getroot(j)]=getroot(i);
}

int n,m;

set<int> bird, tree;

int main() {
    //freopen("in.txt", "r", stdin);
    for (int i=0; i<N; i++) fa[i] = i;
    cin >> n;
    for (int i=0; i<n; i++) {
        int number;
        cin >> number;
        vector<int> tmp;
        int x;
        for (int j=0; j<number; j++) {
            cin >> x;
            mark[x] = 1;
            bird.insert(x);
            tmp.push_back(x);
        }
        for (int i=0; i<tmp.size()-1; i++) {
            if (q_m(tmp[i], tmp[i+1])==false) merger(tmp[i], tmp[i+1]);
        }
    }

    for (int i=0; i<N; i++) {
        if (mark[i]) {
            tree.insert(getroot(i));
        }
    }
    cout << tree.size() << " " << bird.size() << endl;
    cin >> m;
    int a, b;
    for (int i=0; i<m; i++) {
        cin >> a >> b;

        if (q_m(a, b)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


}
