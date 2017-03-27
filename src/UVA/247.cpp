// 6658354_AC_190ms_0kB.cpp
#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
using namespace std;
#include <algorithm>
#include <cmath>
#include <map>
typedef long long ll;
#define INF 0x3f3f3f3f
#define N 1007
#define M 1000007
#define RST(x) memset(x, 0, sizeof(x))

int d[N][N];
int m,n;
map<string, int> mp;
map<int, string> re;
string tmp1,tmp2;
int cnt;
int G[N][N];
vector<int> res[N];
int counter;
int vis[N];

int get(string & s) {
    if (mp.find(s) != mp.end()) {
        return mp[s];
    } else {
        mp[s] = cnt;
        re[cnt] = s;
        cnt++;
        return mp[s];
    }
}

void init() {
    mp.clear(), cnt = 0;
    re.clear();
    memset(d, 0, sizeof(d));
    for (int i=0; i<N; i++) res[i].clear();
    counter = 0;
    memset(G, 0, sizeof(G));
    memset(vis, 0, sizeof(vis));
}

void dfs(int u, int counter) {
    vis[u] = true;
    res[counter].push_back(u);
    for (int i=0; i<n; i++) {
        if (G[u][i] && vis[i]==false) {
            dfs(i, counter);
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    int dataset = 0;
    cin >> n >> m;
    while (1) {
        dataset ++;
        if (n==0 && m==0) break;
        init();
        for (int i=0; i<m; i++) {
            cin >> tmp1 >> tmp2;
            int a = get(tmp1), b = get(tmp2);
            d[a][b] = 1;
        }

        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    d[i][j] = d[i][j] || (d[i][k] && d[k][j]);
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (d[i][j] == 1 &&  d[j][i] == 1) G[i][j] = G[j][i] = 1;
            }
        }
        for (int i=0; i<n; i++) {
            if (vis[i]==0) {
                dfs(i, counter++);
            }
        }
        printf("Calling circles for data set %d:\n", dataset);
        for (int i=0; i<counter; i++) {
            for (int j=0; j<res[i].size()-1; j++) {
                cout << re[res[i][j]] << ", ";
            }cout << re[res[i][res[i].size()-1]] << endl;
        }
        cin >> n >> m;
        if (n==0 && m==0) break;
        else cout << endl;

    }
}
