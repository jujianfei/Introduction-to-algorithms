// 这种题目，一句话也不想多说


#include <bits/stdc++.h>
using namespace std;
#define N 100005

int n, m;
vector<int> G[N];
int depth[N];


int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    int root, number;
    for (int i=0; i<m; i++) {
        cin >> root >> number;
        int id;
        while (number--) {
            cin >> id;
            G[root].push_back(id);
        }
    }
    depth[1] = 1;
    deque<int> pq;
    pq.push_back(1);
    while (pq.empty()==false) {
        int fro = pq.front();
        pq.pop_front();
        for (int i=0; i<G[fro].size(); i++) {
            int id = G[fro][i];
            depth[id] = depth[fro] + 1;
            pq.push_back(id);
        }
    }

    map<int,int> mp;
    for (int i=1; i<=n; i++) {
        mp[depth[i]]++;
    }

    int maxer = -1;
    int rec = -1;
    map<int,int>::iterator p=mp.begin();
    for (; p!=mp.end(); p++) {
        if (p->second > maxer) {
            maxer = p->second;
            rec = p->first;
        }
    }

    cout << maxer << " " << rec << endl;
}
