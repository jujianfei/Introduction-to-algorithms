// DFS爆了，换BFS AC
#include <bits/stdc++.h>
using namespace std;

bool dp[1288][130][62];

bool vis[1288][130][62];

int m, n, l, t;


int ret = 0;

const int di[6] = {-1, 1, 0, 0, 0, 0};
const int dj[6] = {0, 0, -1, 1, 0, 0};
const int dk[6] = {0, 0, 0, 0, 1, -1};

struct Node {
    int x, y, z;
    Node(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
    Node() {}

};

bool legal(int i, int j, int k) {
    if (i>=0 && i<m && j>=0 && j<n && k >=0 && k<l) return true;
    else return false;
}

int bfs(int i, int j, int k) {

    int res = 0;
    deque<Node> pq;
    vis[i][j][k] = 1;

    pq.push_back(Node(i, j, k));
    while (pq.empty()==false) {
        Node fro = pq.front();
        pq.pop_front();
        int ii = fro.x, jj = fro.y, kk = fro.z;

        res ++;
        for (int x=0; x<6; x++) {
            int ni = ii + di[x];
            int nj = jj + dj[x];
            int nk = kk + dk[x];
            if (legal(ni, nj, nk) && !vis[ni][nj][nk] &&  dp[ni][nj][nk]) {
                pq.push_back(Node(ni, nj, nk));
                vis[ni][nj][nk] = 1;
            }
        }

    }
    return res;

}


int main() {
    //freopen("in.txt", "r", stdin);
    cin >> m >> n >> l >> t;
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    for (int k=0; k<l; k++) {
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cin >> dp[i][j][k];
            }
        }
    }
   int cnt;
   for (int k=0; k<l; k++) {
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!vis[i][j][k] && dp[i][j][k]) {
                    cnt = bfs(i, j, k);

                    if (cnt >= t) {
                        ret += cnt;
                    }
                }
            }
        }
    }
    cout << ret << endl;
}

