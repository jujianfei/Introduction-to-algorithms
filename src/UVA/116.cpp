// 6606525_AC_350ms_0kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define N 507
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
int n, m;

int a[N][N];
int dp[N][N];
int rec[N][N]; // 1 stand for up 2 stand for v_ 3 stand for down

struct Node {
    int i,j;
    Node (int i,int j):i(i),j(j){}
    Node(){}
};
bool cmp(const Node &n1, const Node &n2) {
    if (n1.i < n2.i) return true;
    else if (n1.i > n2.i) return false;
    else return n1.j < n2.j;
}

int main() {
    //freopen("in.txt", "r", stdin);
    while (cin >> n >> m) {
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        memset(rec, 0, sizeof(rec));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i=0; i<n; i++) {
            dp[i][m-1] = a[i][m-1];
        }
        for (int j=m-2; j>=0; j--) {
            for (int i=0; i<n; i++) {
                int fir = dp[(i-1+n)%n][j+1];
                int sec = dp[i][j+1];
                int thi = dp[(i+1)%n][j+1];
                int fi = (i-1+n)%n;
                int si = i;
                int ti = (i+1)%n;
                vector<Node> tmp;
                tmp.push_back(Node(fir, fi));
                tmp.push_back(Node(sec, si));
                tmp.push_back(Node(thi, ti));
                sort(tmp.begin(), tmp.end(), cmp);
                rec[i][j] = tmp[0].j;
                dp[i][j] = tmp[0].i + a[i][j];
            }
        }
        int begin = -1;
        int miner = INF;
        for (int i=0; i<n; i++) {
            if (dp[i][0] < miner) {
                miner = dp[i][0];
                begin = i;
            }
        }
        int i= begin;
        int j=0;
        while (1) {
            cout << i+1;
            if (j+1!=m)cout << " ";
            i = rec[i][j];
            j = j + 1;
            if (j==m) break;
        }cout << endl;
        cout << dp[begin][0] << endl;



    }
}

