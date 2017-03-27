// 6764151_AC_16ms_736kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N (1024 * 10)
using namespace std;

struct Edge{
    int e,C,P,R;
    Edge() {}
};

vector<Edge> v[10];

struct Node {
    int i, j;
    int val;
    Node(int i,int j,int val) :i(i), j(j), val(val) { }
    Node () {}
    bool operator < (const Node & n) const { return n.val > val; }
};

int n,m;

int dp[N]; //记录当前状态的花费的最小值
int encode(int i,int j) { return i*1024 + j; }

priority_queue<Node> pq;

int main() {
    //freopen("in.txt", "r", stdin);

    while (cin >> n >> m) {


        int a,b,c,p,r;
        for (int i=0; i<m; i++) {
            cin >> a >> b >> c >> p >> r;
            Edge tmp;
            tmp.e = b-1, tmp.C = c-1, tmp.P = p, tmp.R = r;
            v[a-1].push_back(tmp);
        }
        //for (int i=0; i<n-1; i++) cout << v[i][0].C << " "; cout << endl;

        memset(dp, 0x3f, sizeof(dp));
        dp[encode(0,1)] = 0;
        pq.push(Node(0,1,0));
        while (pq.size()!=0) {
            Node fro = pq.top();
            pq.pop();
            for (int k=0; k<v[fro.i].size(); k++) {
                if (true) { //fro能够转移到k
                    int cost;
                    if (fro.j & (1<<v[fro.i][k].C)) cost = v[fro.i][k].P;
                    else                      cost = v[fro.i][k].R;
                    int nextcost = cost + fro.val;
                    int nextstate = encode(((v[fro.i][k].e)), fro.j|(1<<(v[fro.i][k].e)));
                    if (dp[nextstate]>nextcost) {
                        dp[nextstate]=nextcost;
                        pq.push(Node(((v[fro.i][k].e)), fro.j|(1<<(v[fro.i][k].e)), nextcost));
                    }
                }
            }
        }
//        for (int i=0; i<n; i++) {
//            for (int j=0; j<(1<<n); j++) {
//                if (dp[encode(i,j)]==INF) cout << "F ";
//                else                      cout << dp[encode(i,j)] << " ";
//            }cout << endl;
//        }

        int ans = INF;
        for (int j=0; j<(1<<n); j++) {
            ans = min(ans, dp[encode(n-1,j)]);
        }
        if (ans == INF) cout << "impossible" << endl;
        else            cout << ans << endl;


    }

}
